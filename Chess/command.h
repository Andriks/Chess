#ifndef COMMAND_H
#define COMMAND_H

#include <QObject>

#include "desk.h"
#include "figure.h"

class Command : public QObject
{
    Q_OBJECT
public:
    explicit Command(QObject *parent = 0, Desk *desk = NULL);

    bool valid();

    void set_b_info(Desk::Cell, Figure*);
    void set_e_info(Desk::Cell, Figure*);

    void exec();
    void rollback();

    Figure *getCurFig();
    Desk::CellInfo get_b_info();
    Desk::CellInfo get_e_info();

private:
    bool access_check();

private:
//   Desk::Cell b_cell_;
//   Desk::Cell e_cell_;

    Figure *cur_fig_;
    Figure *rem_fig_;

    Desk::CellInfo b_cell_info_;
    Desk::CellInfo e_cell_info_;
    Desk *desk_;
};

#endif // COMMAND_H
