#include "command.h"
#include "desk.h"
#include "figure.h"

#include <algorithm>

Command::Command(QObject *parent, Desk *desk) :
    QObject(parent),
    desk_(desk),
    cur_fig_(NULL),
    rem_fig_(NULL)
{
}

bool Command::valid()
{
    //needs err handle here
    if (cur_fig_ == NULL)
    {
        return false;
    }

    std::vector<Cell> acc_cells = cur_fig_->cellsToMove(b_cell_info_.cell_);

    for (std::vector<Cell>::iterator it = acc_cells.begin(); it != acc_cells.end(); it++)
        if (*it == e_cell_info_.cell_)
            return true;

    return false;

}

void Command::set_b_info(Cell cell)
{
    Figure *fig = desk_->getFigure(cell);
    b_cell_info_ = CellInfo(cell, fig->type(), fig->color());
    cur_fig_ = fig;
}

void Command::set_e_info(Cell cell)
{
    Figure *fig = desk_->getFigure(cell);
    if (fig != NULL) {
        e_cell_info_ = CellInfo(cell, fig->type(), fig->color());
        rem_fig_ = fig;
    } else {
        e_cell_info_ = CellInfo(cell, EMPTY, NONE);
        rem_fig_ = NULL;
    }
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
        rem_ptr = NULL;
    }
}

void Command::rollback()
{

}

Figure *Command::getCurFig()
{
    return cur_fig_;
}

CellInfo Command::get_b_info()
{
    return b_cell_info_;
}

CellInfo Command::get_e_info()
{
    return e_cell_info_;
}
