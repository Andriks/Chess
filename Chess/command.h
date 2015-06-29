#ifndef COMMAND_H
#define COMMAND_H

#include "common_types.h"


class Command : public QObject
{
    Q_OBJECT
public:
    explicit Command(Desk *desk = 0);

    Command(const Command&);
    Command& operator=(const Command&);
    //~Command(void);

    bool valid();

    void set_b_info(Cell);
    void set_e_info(Cell);

    void set_b_info(CellInfo);
    void set_e_info(CellInfo);

    void set_desk(Desk *);


    void exec();
    void rollback();

    CellInfo get_b_info() const;
    CellInfo get_e_info() const;

private:
    CellInfo b_cell_info_;  // info about cell from which we are moving (begin)
    CellInfo e_cell_info_;  // info about cell which we are moving for (end)
    Desk *desk_;
};

#endif // COMMAND_H
