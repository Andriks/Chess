#include "command.h"
#include "desk.h"
#include "figure.h"

#include <QStringList>
#include <QMap>


Command::Command(Desk *desk) :
    QObject(desk),
    desk_(desk)
{
}

Command::Command(const Command &rv):
    desk_(NULL)
{
    desk_ = rv.desk_;
    b_cell_info_ = rv.b_cell_info_;
    e_cell_info_ = rv.e_cell_info_;
}

Command &Command::operator=(const Command &rv)
{
    desk_ = rv.desk_;
    b_cell_info_ = rv.b_cell_info_;
    e_cell_info_ = rv.e_cell_info_;
}

bool Command::valid()
{
    Cell cur_cell = b_cell_info_.cell_;
    Figure *fig = desk_->getFigure(cur_cell);

    //needs err handle here
    if (fig == NULL)
    {
        return false;
    }

    std::vector<Cell> acc_cells = fig->cellsToMove(cur_cell);

    for (std::vector<Cell>::iterator it = acc_cells.begin(); it != acc_cells.end(); it++)
        if (*it == e_cell_info_.cell_)
            return true;

    return false;
}

void Command::set_b_info(Cell cell)
{
    Figure *fig = desk_->getFigure(cell);
    b_cell_info_ = CellInfo(cell, fig->getFigName(), fig->getColor());
}

void Command::set_e_info(Cell cell)
{
    Figure *fig = desk_->getFigure(cell);
    if (fig != NULL)
        e_cell_info_ = CellInfo(cell, fig->getFigName(), fig->getColor());
    else
        e_cell_info_ = CellInfo(cell, " ", NONE);
}

void Command::set_b_info(CellInfo inp)
{
    b_cell_info_ = inp;
}

void Command::set_e_info(CellInfo inp)
{
    e_cell_info_ = inp;
}

void Command::set_desk(Desk *new_desk)
{
    desk_ = new_desk;
}

void Command::exec()
{
    int b_row = b_cell_info_.cell_.row_;
    int b_col = b_cell_info_.cell_.col_;

    int e_row = e_cell_info_.cell_.row_;
    int e_col = e_cell_info_.cell_.col_;

    std::swap(desk_->buffer_[b_row][b_col],
              desk_->buffer_[e_row][e_col]);

    //we have swaped figures and figure, which was on target cell, on start cell now
    //if it exists (not NULL) we should to relese it from buffer (and memory)
    Figure *rem_ptr = desk_->buffer_[b_row][b_col];
    if (rem_ptr != NULL) {
        delete rem_ptr;
        desk_->buffer_[b_row][b_col] = NULL;
    }
}

void Command::rollback()
{
    int b_row = b_cell_info_.cell_.row_;
    int b_col = b_cell_info_.cell_.col_;

    int e_row = e_cell_info_.cell_.row_;
    int e_col = e_cell_info_.cell_.col_;

    std::swap(desk_->buffer_[b_row][b_col],
              desk_->buffer_[e_row][e_col]);

    QString type = e_cell_info_.ftype_;

    if (type == "K")
        desk_->buffer_[e_row][e_col] = new King(desk_, e_cell_info_.fcolor_);
    else if (type == "Q")
        desk_->buffer_[e_row][e_col] = new Queen(desk_, e_cell_info_.fcolor_);
    else if (type == "R")
        desk_->buffer_[e_row][e_col] = new Rook(desk_, e_cell_info_.fcolor_);
    else if (type == "B")
        desk_->buffer_[e_row][e_col] = new Bishop(desk_, e_cell_info_.fcolor_);
    else if (type == "Kn")
        desk_->buffer_[e_row][e_col] = new Knight(desk_, e_cell_info_.fcolor_);
    else if (type == "P")
        desk_->buffer_[e_row][e_col] = new Pawn(desk_, e_cell_info_.fcolor_);
}

CellInfo Command::get_b_info() const
{
    return b_cell_info_;
}

CellInfo Command::get_e_info() const
{
    return e_cell_info_;
}

QString Command::getAsString() const
{
    Cell b_cell = b_cell_info_.cell_;
    Cell e_cell = e_cell_info_.cell_;

    QString b_info;
    QString e_info;

    b_info = QString::number(b_cell.row_) + "," + QString::number(b_cell.col_)
     + "|" + b_cell_info_.ftype_
     + "|" + ((b_cell_info_.fcolor_ == WHITE) ? "w" : "b");

    e_info = QString::number(e_cell.row_) + "," + QString::number(e_cell.col_)
     + "|" + e_cell_info_.ftype_
     + "|" + ((e_cell_info_.fcolor_ == WHITE) ? "w" : "b");

    return b_info + "||" + e_info;
}

void Command::setFromString(const QString &inp_str)
{
    QString tmp(inp_str);
    tmp.remove("\n");

    QStringList line = tmp.split("||");

    QStringList b_info_list = line[0].split("|");
    QStringList b_cell_list = b_info_list[0].split(",");
    b_cell_info_.cell_ = Cell(b_cell_list[0].toInt(), b_cell_list[1].toInt());
    b_cell_info_.ftype_ = b_info_list[1];

    QString b_color = b_info_list[2];
    if (b_color == "w")
        b_cell_info_.fcolor_ = WHITE;
    else if(b_color == "b")
        b_cell_info_.fcolor_ = BLACK;
    else
        b_cell_info_.fcolor_ = NONE;

    QStringList e_info_list = line[1].split("|");
    QStringList e_cell_list = e_info_list[0].split(",");
    e_cell_info_.cell_ = Cell(e_cell_list[0].toInt(), e_cell_list[1].toInt());
    e_cell_info_.ftype_ = e_info_list[1];

    QString e_color = e_info_list[2];
    if (e_color == "w")
        e_cell_info_.fcolor_ = WHITE;
    else if(e_color == "b")
        e_cell_info_.fcolor_ = BLACK;
    else
        e_cell_info_.fcolor_ = NONE;
}
