#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#include <QObject>
#include <QPointer>
#include <QString>
#include <exception>


class Figure;
class Desk;
class Command;

enum FigColor{NONE/*base class*/,
              WHITE,
              BLACK};


struct Cell {
    int row_;
    int col_;

    Cell(int row=-1, int col=-1):
        row_(row),
        col_(col)
    {
    }

    bool operator ==(const Cell &rv) {
        return (row_==rv.row_ && col_==rv.col_);
    }

};


struct CellInfo {
    Cell cell_;
    QString ftype_;
    FigColor fcolor_;
    CellInfo(Cell cell=Cell(), QString ftype="", FigColor fcolor=NONE):
        cell_(cell),
        ftype_(ftype),
        fcolor_(fcolor)
    {
    }

    bool operator ==(const CellInfo &rv) {
        return (cell_==rv.cell_ && ftype_==rv.ftype_ && fcolor_==rv.fcolor_);
    }

};


class ChessEx: public std::exception
{
   const char* what() {
       return "Chess exception occurred";
   }
};


#endif // COMMON_TYPES_H
