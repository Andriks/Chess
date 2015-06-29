#ifndef COMMAND_H
#define COMMAND_H

#include "common_types.h"


class Command : public QObject
{
    Q_OBJECT
public:
    explicit Command(Desk *desk = 0);

//    Command(const Command&);
//    Command& operator=(const Command&);
    //~Command(void);

    bool valid();

    void set_b_info(Cell);
    void set_e_info(Cell);

    void exec();
    void rollback();

    Figure *getCurFig();
    CellInfo get_b_info();
    CellInfo get_e_info();

private:
    Figure *cur_fig_;
    Figure *rem_fig_;

    CellInfo b_cell_info_;
    CellInfo e_cell_info_;
    Desk *desk_;
};

#endif // COMMAND_H
