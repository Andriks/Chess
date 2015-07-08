#include "desk.h"

#include <QFile>
#include <QTextStream>


const int Desk::max_cnt_(8);


Desk::Desk(QObject *parent) :
    QObject(parent),
    color_to_move_(WHITE),
    have_active_figure_(false),
    command_(NULL)
{
    //filling desk by empty ptr on base items
    for (int row=0; row<max_cnt_; row++) {
        std::vector<Figure*> row_vec;
        for (int col=0; col<max_cnt_; col++)
            row_vec.push_back(NULL);

        buffer_.push_back(row_vec);     //it will copy row to buffer_ (now mamory leek [?])
    }


    FigColor fcolor = BLACK;
    buffer_[0][0] = new Rook(   this, fcolor);
    buffer_[0][1] = new Knight( this, fcolor);
    buffer_[0][2] = new Bishop( this, fcolor);
    buffer_[0][3] = new Queen(  this, fcolor);
    buffer_[0][4] = new King(   this, fcolor);
    buffer_[0][5] = new Bishop( this, fcolor);
    buffer_[0][6] = new Knight( this, fcolor);
    buffer_[0][7] = new Rook(   this, fcolor);
    for (int i=0; i<8; i++) {
        buffer_[1][i] = new Pawn(this, fcolor);
    }

    fcolor = WHITE;
    buffer_[7][0] = new Rook(   this, fcolor);
    buffer_[7][1] = new Knight( this, fcolor);
    buffer_[7][2] = new Bishop( this, fcolor);
    buffer_[7][3] = new Queen(  this, fcolor);
    buffer_[7][4] = new King(   this, fcolor);
    buffer_[7][5] = new Bishop( this, fcolor);
    buffer_[7][6] = new Knight( this, fcolor);
    buffer_[7][7] = new Rook(   this, fcolor);
    for (int i=0; i<8; i++) {
        buffer_[6][i] = new Pawn(this, fcolor);
    }
}


bool Desk::grabFigure(const Cell &cell)
{
    Figure *curr_fig = getFigure(cell);

    if (curr_fig == NULL)
        return false;

    if (curr_fig->getColor() != color_to_move_)
        return false;

    have_active_figure_ = true;

    command_ = new Command(this);
    command_->set_b_info(cell);

    return true;
}

bool Desk::putDownFigure(const Cell &cell)
{
    if (!have_active_figure_)
        return false;

    command_->set_e_info(cell);

    if (command_->valid()) {
        command_->exec();
        executed_commands_.push_back(*command_);

        delete command_;
        command_ = NULL;

        switchActivePlayer();
        have_active_figure_ = false;

        return true;

    } else {
        interruptCommand();
        return false;
    }
}

void Desk::switchActivePlayer()
{
    color_to_move_ = (color_to_move_== WHITE) ? BLACK : WHITE;
}

void Desk::rollback_from_list()
{
    if (command_ == &executed_commands_.front())
        return;

    if (command_ == NULL)
        command_ = &executed_commands_.back();
    else
        command_--;


    command_->rollback();
}

void Desk::make_move_from_list()
{
    if (command_ == NULL)
        return;

    command_->exec();

    if (command_ == &executed_commands_.back())
        command_ = NULL;
    else
        command_++;
}

bool Desk::interruptCommand()
{
    if (command_ != NULL) {
        delete command_;
        command_ = NULL;

        have_active_figure_ = false;
        return true;
    } else {
        return false;
    }
}

void Desk::saveStateIntoFile(QString &file_url)
{
    file_url.remove("file:///");
    QFile file(file_url);

    if (!file.open(QFile::WriteOnly|QFile::Truncate))
        return;

    QTextStream outstream(&file);

    for (std::vector<Command>::iterator it=executed_commands_.begin();
                                      it!=executed_commands_.end();
                                      it++)
    {
        outstream << it->getAsString() << "\n";
    }

    file.close();
}

void Desk::restoreState(const std::vector<Command> &commands)
{
    executed_commands_.clear();

    for (std::vector<Command>::const_iterator it=commands.begin();
                                      it!=commands.end();
                                      it++)
    {
        command_ = new Command(this);
        command_->set_b_info(it->get_b_info());
        command_->set_e_info(it->get_e_info());

        if (!command_->valid())
            throw std::exception();

        command_->exec();
        executed_commands_.push_back(*command_);
        delete command_;
    }

    command_ = NULL;
}

Figure *Desk::getFigure(const Cell &inp_cell) const
{
    if (!inRange(inp_cell))
        return NULL;

    return buffer_[inp_cell.row_][inp_cell.col_];
}

Figure **Desk::getPtrFromBuffer(const Cell &inp_cell)
{
    return &(buffer_[inp_cell.row_][inp_cell.col_]);
}

Command *Desk::getCommand()
{
    return command_;
}

bool Desk::inRange(const Cell &cell) const
{
    if (cell.row_ < 0 || cell.col_ < 0)
        return false;

    if (cell.row_ > (max_cnt_-1) || cell.col_ > (max_cnt_-1))
        return false;

    return true;
}

bool Desk::haveActiveFigure() const
{
    return have_active_figure_;
}

int Desk::getMaxCnt()
{
    return max_cnt_;
}
