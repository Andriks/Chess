#include "game.h"
#include "desk.h"
#include "command.h"

#include <QFile>
#include <QTextStream>
#include <QVariant>

Game::Game(QObject *parent) :
    root_(parent),
    desk_(NULL),
    color_to_move_(WHITE),
    desk_is_active_(false),
    command_(NULL)
{
    desk_ = new Desk(this);
}

Cell Game::parseQMLCellName(QString name)
{
    //needs err handle here
    if (!name.contains(QRegExp("cell[1-8][1-8]")))
        return Cell(-1,-1);


    QString tmp = name.remove("cell");
    int row = QString(tmp[0]).toInt()-1;
    int col = QString(tmp[1]).toInt()-1;

    return Cell(row,col);
}

QString Game::colorForGUI(FigColor color)
{
    if (color == WHITE)
        return "blue";
    else if (color == BLACK)
        return "black";
    else
        return "";
}

void Game::cellAction(QString cell_name)
{
    if (!desk_is_active_)
        return;

    Cell cell = parseQMLCellName(cell_name);
    //bad input
    if (cell == Cell(-1,-1)) {
        interruptCommand();
        return;
    }

    QObject *t_cell = root_->findChild<QObject*>("t_"+cell_name);
    //needs err handle here
    if (t_cell == NULL) {
        interruptCommand();
        return;
    }

    if (command_ == NULL) {
        if (desk_->getFigure(cell) == NULL)
            return;

        if (desk_->getFigure(cell)->getColor() != color_to_move_)
            return;

        t_cell->setProperty("color", "red");

        command_ = new Command(desk_);
        command_->set_b_info(cell);
    } else {
        command_->set_e_info(cell);

        if (command_->valid()) {
            command_->exec();
            executed_commands_.push_back(*command_);

            // switching active player for next move
             color_to_move_ = (color_to_move_== WHITE) ? BLACK : WHITE;

            drawCommand(*command_);

            delete command_;
            command_ = NULL;

        } else {

            interruptCommand();
        }
    }
}

void Game::startAction()
{
    desk_is_active_ = true;
    color_to_move_ = WHITE;
    command_ = NULL;

    delete desk_;
    desk_ = new Desk(this);

    drawCurState();
}

void Game::stopAction()
{
    interruptCommand();
    desk_is_active_ = false;

    delete desk_;
    desk_ = new Desk(this);

    for (size_t row=0; row<Desk::max_row_cnt_; row++) {
        for (size_t col=0; col<Desk::max_col_cnt_; col++) {
            QObject *t_cell = root_->findChild<QObject*>("t_cell"+QString::number(row+1)+QString::number(col+1));
            t_cell->setProperty("text", "");
        }
    }
}

void Game::saveAction(QString file_url)
{
    interruptCommand();

    file_url.remove("file:///");
    QFile file(file_url);
    //needs err handle here
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

bool Game::loadAction(QString file_url)
{
    file_url.remove("file:///");

    QFile file(file_url);
    //needs err handle here
    if (!file.open(QFile::ReadOnly))
        return false;

    Desk *new_desk = new Desk(this);
    std::vector<Command> comm_list;

    while (!file.atEnd()) {
        QString line =  file.readLine();
        Command comm;
        if (!comm.setFromString(line)) {
            // bad input file, releasing of resources and breaking operation
            file.close();
            delete new_desk;

            return false;
        }

        comm.set_desk(new_desk);
        comm.exec();

        comm_list.push_back(comm);
    }

    file.close();

    //if everething was nice
    delete desk_;
    desk_ = new_desk;
    executed_commands_.clear();
    executed_commands_ = comm_list;
    command_ = NULL;


    drawCurState();

    return true;
}

void Game::rollback_from_list()
{
    if (command_ == &executed_commands_.front())
        return;

    if (command_ == NULL)
        command_ = &executed_commands_.back();
    else
        command_--;


    command_->rollback();
    drawCommand(*command_);
}

void Game::make_move_from_list()
{
    if (command_ == NULL)
        return;

    command_->exec();
    drawCommand(*command_);

    if (command_ == &executed_commands_.back())
        command_ = NULL;
    else
        command_++;
}

void Game::drawCurState()
{
    for (size_t row=0; row<Desk::max_row_cnt_; row++) {
        for (size_t col=0; col<Desk::max_col_cnt_; col++) {
            drawCell(Cell(row, col));
        }
    }
}

void Game::drawCommand(const Command &comm)
{
    drawCell(comm.get_b_info().cell_);
    drawCell(comm.get_e_info().cell_);
}

void Game::drawCell(const Cell &cell)
{
    QObject *t_cell = root_->findChild<QObject*>("t_cell"+QString::number(cell.row_+1)+QString::number(cell.col_+1));
    //needs err handle here
    if (t_cell == NULL)
        return;

    Figure *item = desk_->getFigure(cell);
    if (item == NULL) {
        t_cell->setProperty("text", "");
        return;
    }

    t_cell->setProperty("text", item->getFigName());
    t_cell->setProperty("color", colorForGUI(item->getColor()));
}

void Game::interruptCommand()
{
    if (command_ != NULL) {
        CellInfo info = command_->get_b_info();
        QString row = QString::number(info.cell_.row_+1);
        QString col = QString::number(info.cell_.col_+1);
        QObject *prev_t_cell = root_->findChild<QObject*>(QString("t_cell")+row+col);
        prev_t_cell->setProperty("color", colorForGUI(desk_->getFigure(info.cell_)->getColor()));

        delete command_;
        command_ = NULL;
    }
}
