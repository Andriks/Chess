#include "command.h"
#include "desk.h"
#include "figure.h"


Command::Command(Desk *desk) :
    QObject(desk),
    desk_(desk)
{
}

Command::Command(const Command &rv):
    desk_(NULL)

{
    b_cell_info_ = rv.b_cell_info_;
    e_cell_info_ = rv.e_cell_info_;
}

Command &Command::operator=(const Command &rv)
{
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
    b_cell_info_ = CellInfo(cell, fig->type(), fig->color());
}

void Command::set_e_info(Cell cell)
{
    Figure *fig = desk_->getFigure(cell);
    if (fig != NULL)
        e_cell_info_ = CellInfo(cell, fig->type(), fig->color());
    else
        e_cell_info_ = CellInfo(cell, EMPTY, NONE);
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
    std::swap(desk_->buffer_[b_cell_info_.cell_.row_][b_cell_info_.cell_.col_],
              desk_->buffer_[e_cell_info_.cell_.row_][e_cell_info_.cell_.col_]);

    //we have swaped figures and figure, which was on target cell, on start cell now
    //if it exists (not NULL) we should to relese it from buffer (and memory)
    Figure *rem_ptr = desk_->buffer_[b_cell_info_.cell_.row_][b_cell_info_.cell_.col_];
    if (rem_ptr != NULL) {
        delete rem_ptr;
        desk_->buffer_[b_cell_info_.cell_.row_][b_cell_info_.cell_.col_] = NULL;
    }
}

void Command::rollback()
{
//    std::swap(desk_->buffer_[b_cell_info_.cell_.row_][b_cell_info_.cell_.col_],
//              desk_->buffer_[e_cell_info_.cell_.row_][e_cell_info_.cell_.col_]);

//    Figure *rem_ptr = desk_->buffer_[b_cell_info_.cell_.row_][b_cell_info_.cell_.col_];
//    if (rem_ptr != NULL) {
//        delete rem_ptr;
//        desk_->buffer_[b_cell_info_.cell_.row_][b_cell_info_.cell_.col_] = NULL;
//    }

}

CellInfo Command::get_b_info()
{
    return b_cell_info_;
}

CellInfo Command::get_e_info()
{
    return e_cell_info_;
}
