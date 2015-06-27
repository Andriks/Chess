#ifndef DESK_H
#define DESK_H

#include <QObject>
#include <vector>

#include "figure.h"

class Desk : public QObject
{
    Q_OBJECT

public:
    struct Cell {
        size_t row_;
        size_t col_;
        Cell(size_t row, size_t col): row_(row), col_(col) {}
    };

    struct CellInfo {
        Cell cell_;
        Figure::FigType ftype_;
        Figure::FigColor fcolor_;
        CellInfo(Cell cell, Figure::FigType ftype,Figure::FigColor fcolor):
            cell_(cell),
            ftype_(ftype),
            fcolor_(fcolor)
        {}
    };

public:
    explicit Desk(QObject *parent = 0);

    void fillDefault();
    void clear();

    Figure *getFigure(Cell);

private:
    QObject *owner_;    //ptr to desk owner (Game instance)
    std::vector< std::vector<Figure*> > buffer_;

    static bool defaultStateFilled_;
    static std::vector<CellInfo> defaultState_;

    static size_t max_row_cnt_;
    static size_t max_col_cnt_;
};


#endif // DESK_H
