#include "command.h"

Command::Command(QObject *parent) :
    QObject(parent),
    cur_fig_(NULL),
    rem_fig_(NULL)
{
}

bool Command::valid()
{
    if (rem_fig_ != NULL)
        if (cur_fig_->color() == rem_fig_->color())
            return false;

    return true;
}

void Command::set_b_info(Desk::Cell cell, Figure *fig)
{
    b_cell_info_ = Desk::CellInfo(cell, fig->type(), fig->color());
    cur_fig_ = fig;
}

void Command::set_e_info(Desk::Cell cell, Figure *fig)
{
    if (fig != NULL) {
        e_cell_info_ = Desk::CellInfo(cell, fig->type(), fig->color());
        rem_fig_ = fig;
    } else {
        e_cell_info_ = Desk::CellInfo(cell);
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

Desk::CellInfo Command::get_b_info()
{
    return b_cell_info_;
}

bool Command::access_check()
{
    return false;
}
