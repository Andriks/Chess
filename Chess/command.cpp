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

//    if (std::find(acc_cells.begin(), acc_cells.end(), b_cell_info_.cell_))
//        return true;
    // tmp
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

bool Command::access_check()
{
    return false;
}
