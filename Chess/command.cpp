#include "command.h"
#include "desk.h"
#include "figure.h"

#include <QStringList>


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
    QPointer<Figure> fig = desk_->getFigure(cur_cell);

    if (fig.isNull())
        return false;

    QVector<Cell> acc_cells = fig->cellsToMove(cur_cell);

    for (QVector<Cell>::iterator it = acc_cells.begin(); it != acc_cells.end(); it++)
        if (*it == e_cell_info_.cell_)
            return true;

    return false;
}

void Command::set_b_info(Cell cell)
{
    QPointer<Figure> fig = desk_->getFigure(cell);
    b_cell_info_ = CellInfo(cell, fig->getFigName(), fig->getColor());
}

void Command::set_e_info(Cell cell)
{
    QPointer<Figure> fig = desk_->getFigure(cell);
    if (!fig.isNull())
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

void Command::set_desk(QPointer<Desk> new_desk)
{
    desk_ = new_desk;
}

void Command::exec()
{
    int b_row = b_cell_info_.cell_.row_;
    int b_col = b_cell_info_.cell_.col_;

    int e_row = e_cell_info_.cell_.row_;
    int e_col = e_cell_info_.cell_.col_;

    std::swap(*desk_->getPtrFromBuffer(Cell(b_row, b_col)),
              *desk_->getPtrFromBuffer(Cell(e_row, e_col)));

    //we have swaped figures and figure, which was on target cell, on start cell now
    //if it exists (not NULL) we should to relese it from buffer (and memory)
    QPointer<Figure> rem_ptr = desk_->getFigure(Cell(b_row, b_col));
    if (!rem_ptr.isNull()) {
        delete rem_ptr;
    }
}

void Command::rollback()
{
    int b_row = b_cell_info_.cell_.row_;
    int b_col = b_cell_info_.cell_.col_;

    int e_row = e_cell_info_.cell_.row_;
    int e_col = e_cell_info_.cell_.col_;

    std::swap(*desk_->getPtrFromBuffer(Cell(b_row, b_col)),
              *desk_->getPtrFromBuffer(Cell(e_row, e_col)));

    QString type = e_cell_info_.ftype_;

    if (type == "K")
        *desk_->getPtrFromBuffer(Cell(e_row, e_col)) = new King(desk_, e_cell_info_.fcolor_);
    else if (type == "Q")
        *desk_->getPtrFromBuffer(Cell(e_row, e_col)) = new Queen(desk_, e_cell_info_.fcolor_);
    else if (type == "R")
        *desk_->getPtrFromBuffer(Cell(e_row, e_col)) = new Rook(desk_, e_cell_info_.fcolor_);
    else if (type == "B")
        *desk_->getPtrFromBuffer(Cell(e_row, e_col)) = new Bishop(desk_, e_cell_info_.fcolor_);
    else if (type == "Kn")
        *desk_->getPtrFromBuffer(Cell(e_row, e_col)) = new Knight(desk_, e_cell_info_.fcolor_);
    else if (type == "P")
        *desk_->getPtrFromBuffer(Cell(e_row, e_col)) = new Pawn(desk_, e_cell_info_.fcolor_);

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
    QString delim = ";";

    Cell b_cell = b_cell_info_.cell_;
    Cell e_cell = e_cell_info_.cell_;

    QString b_info;
    QString e_info;

    b_info = QString::number(b_cell.row_) + "," + QString::number(b_cell.col_)
     + delim + b_cell_info_.ftype_
     + delim + ((b_cell_info_.fcolor_ == WHITE) ? "w" : "b");

    e_info = QString::number(e_cell.row_) + "," + QString::number(e_cell.col_)
     + delim + e_cell_info_.ftype_
     + delim + ((e_cell_info_.fcolor_ == WHITE) ? "w" : "b");

    return b_info + delim+delim + e_info;
}

bool Command::setFromString(const QString &inp_str)
{
    QString delim = ";";

    QString tmp(inp_str);
    if ( !tmp.contains(QRegExp("[0-7],[0-7]"+delim+"( |F|K|Q|R|B|P|Kn)"+delim+"[wb]"+delim+delim+"[0-7],[0-7]"+delim+"( |F|K|Q|R|B|P|Kn)"+delim+"[wb]\n")) )
        return false;

    tmp.remove("\n");

    QStringList line = tmp.split(delim+delim);

    QStringList b_info_list = line[0].split(delim);
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

    QStringList e_info_list = line[1].split(delim);
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

    return true;
}
