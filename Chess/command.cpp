#include "command.h"
#include "desk.h"
#include "figure.h"

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
    {}

    //cur_fig_->cellsToMove();

    if (rem_fig_ != NULL)
        if (cur_fig_->color() == rem_fig_->color())
            return false;

    return true;
}

void Command::set_b_info(Cell cell, Figure *fig)
{
    b_cell_info_ = CellInfo(cell, fig->type(), fig->color());
    cur_fig_ = fig;
}

void Command::set_e_info(Cell cell, Figure *fig)
{
    if (fig != NULL) {
        e_cell_info_ = CellInfo(cell, fig->type(), fig->color());
        rem_fig_ = fig;
    } else {
        e_cell_info_ = CellInfo(cell);
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
