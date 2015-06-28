#ifndef DESK_H
#define DESK_H

#include "common_types.h"
#include "figure.h"

#include <vector>


class Desk : public QObject
{
    Q_OBJECT
public:
    friend class Command;

    explicit Desk(QObject *parent = 0);

    void fillDefault();
    void clear();

    Figure *getFigure(const Cell &) const;
    bool inRange(const Cell &) const;

private:
    QObject *owner_;    //ptr to desk owner (Game instance)
    std::vector< std::vector<Figure*> > buffer_;

    static bool defaultStateFilled_;
    static std::vector<CellInfo> defaultState_;

    static int max_row_cnt_;
    static int max_col_cnt_;
};


#endif // DESK_H
