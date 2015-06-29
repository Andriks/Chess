#ifndef DESK_H
#define DESK_H

#include "common_types.h"
#include "figure.h"
#include "command.h"

#include <vector>


class Desk : public QObject
{
    Q_OBJECT
public:
    friend class Command;

    explicit Desk(QObject *parent = 0);

    Figure *getFigure(const Cell &) const;
    bool inRange(const Cell &) const;

private:
    std::vector< std::vector<Figure*> > buffer_;

public:
    static const int max_row_cnt_;
    static const int max_col_cnt_;

};


#endif // DESK_H
