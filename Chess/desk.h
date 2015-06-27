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
        int row_;
        int col_;
        Cell(int row=-1, int col=-1): row_(row), col_(col) {}
        bool operator ==(Cell rv) {
            return (row_==rv.row_ && col_==rv.col_);
        }
    };

    struct CellInfo {
        Cell cell_;
        Figure::FigType ftype_;
        Figure::FigColor fcolor_;
        CellInfo(Cell cell=Cell(-1,-1), Figure::FigType ftype=Figure::EMPTY, Figure::FigColor fcolor=Figure::NONE):
            cell_(cell),
            ftype_(ftype),
            fcolor_(fcolor)
        {}
        bool operator ==(CellInfo rv) {
            return (cell_==rv.cell_ && ftype_==rv.ftype_ && fcolor_==rv.fcolor_);
        }
    };

public:
    //friend Command;
    explicit Desk(QObject *parent = 0);

    void fillDefault();
    void clear();

    Figure *getFigure(Cell);

private:
    QObject *owner_;    //ptr to desk owner (Game instance)
    std::vector< std::vector<Figure*> > buffer_;

    static bool defaultStateFilled_;
    static std::vector<CellInfo> defaultState_;

    static int max_row_cnt_;
    static int max_col_cnt_;
};


#endif // DESK_H
