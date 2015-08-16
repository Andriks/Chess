#include "figure.h"
#include "desk.h"

Figure::Figure(Desk *desk, FigColor fcolor) :
    QObject(desk),
    desk_(desk),
    color_(fcolor)
{
}

FigColor Figure::getColor() const
{
    return color_;
}

QPointer<Desk> Figure::getDesk() const
{
    return desk_;
}

bool Figure::freeCellsCheck4loop(const Cell &cur_cell, const Cell &cell, QVector<Cell> &res) const
{
    if (!desk_->inRange(cell))
        return false;

    if (!desk_->getFigure(cell).isNull())
        if (desk_->getFigure(cur_cell)->getColor() != desk_->getFigure(cell)->getColor()) {
            res.push_back(cell);
            return false;
        } else
            return false;

    res.push_back(cell);
    return true;
}


///////////////////////////////////////////////////////////////////////////////////////
King::King(Desk *parent, FigColor inp_color) :
    Figure(parent, inp_color)
{
}

QString King::getFigName() const
{
    return "K";
}

QVector<Cell> King::cellsToMove(const Cell &cur_cell) const
{
    int row = cur_cell.row_;
    int col = cur_cell.col_;

    QVector<Cell> to_check;
    to_check.push_back( Cell(row-1, col-1) );
    to_check.push_back( Cell(row-1, col  ) );
    to_check.push_back( Cell(row-1, col+1) );

    to_check.push_back( Cell(row, col-1) );
    to_check.push_back( Cell(row, col+1) );

    to_check.push_back( Cell(row+1, col-1) );
    to_check.push_back( Cell(row+1, col  ) );
    to_check.push_back( Cell(row+1, col+1) );

    QVector<Cell> res;

    for (int i=0; i!=to_check.size(); i++)
    {
        Cell it = to_check[i];
        if (getDesk()->inRange(it))
            if (getDesk()->getFigure(it).isNull())
                res.push_back(it);
            else
                if (getDesk()->getFigure(cur_cell)->getColor() != getDesk()->getFigure(it)->getColor())
                    //meens that figure on target cell is enemy, we can go there
                    res.push_back(it);
    }

    return res;
}


///////////////////////////////////////////////////////////////////////////////////////
Queen::Queen(Desk *parent, FigColor inp_color) :
    Figure(parent, inp_color)
{
}

QString Queen::getFigName() const
{
    return "Q";
}


QVector<Cell> Queen::cellsToMove(const Cell &cur_cell) const
{
    QVector<Cell> res;

    int row = cur_cell.row_;
    int col = cur_cell.col_;

    int i, j;

    /****************/
    /****ROOK********/
    /****************/
    i = row;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(++i, col), res));

    i = row;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(--i, col), res));

    i = col;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(row, ++i), res));

    i = col;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(row, --i), res));


    /****************/
    /****BISHOP******/
    /****************/

    i = row; j = col;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(++i, ++j), res));

    i = row; j = col;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(++i, --j), res));

    i = row; j = col;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(--i, --j), res));

    i = row; j = col;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(--i, ++j), res));



    return res;
}


///////////////////////////////////////////////////////////////////////////////////////
Bishop::Bishop(Desk *parent, FigColor inp_color) :
    Figure(parent, inp_color)
{
}

QString Bishop::getFigName() const
{
    return "B";
}

QVector<Cell> Bishop::cellsToMove(const Cell &cur_cell) const
{
    QVector<Cell> res;

    int row = cur_cell.row_;
    int col = cur_cell.col_;

    int i, j;

    i = row; j = col;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(++i, ++j), res));

    i = row; j = col;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(++i, --j), res));

    i = row; j = col;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(--i, --j), res));

    i = row; j = col;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(--i, ++j), res));


    return res;
}


///////////////////////////////////////////////////////////////////////////////////////
Rook::Rook(Desk *parent, FigColor inp_color) :
    Figure(parent, inp_color)
{
}

QString Rook::getFigName() const
{
    return "R";
}

QVector<Cell> Rook::cellsToMove(const Cell &cur_cell) const
{
    QVector<Cell> res;

    int row = cur_cell.row_;
    int col = cur_cell.col_;

    int i = row;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(++i, col), res));

    i = row;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(--i, col), res));

    i = col;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(row, ++i), res));

    i = col;
    do {    } while(freeCellsCheck4loop(cur_cell, Cell(row, --i), res));


    return res;
}


///////////////////////////////////////////////////////////////////////////////////////
Knight::Knight(Desk *parent, FigColor inp_color) :
    Figure(parent, inp_color)
{
}

QString Knight::getFigName() const
{
    return "Kn";
}

QVector<Cell> Knight::cellsToMove(const Cell &cur_cell) const
{
    int row = cur_cell.row_;
    int col = cur_cell.col_;

    QVector<Cell> to_check;
    to_check.push_back( Cell(row+2, col+1) );
    to_check.push_back( Cell(row+1, col+2) );

    to_check.push_back( Cell(row-2, col+1) );
    to_check.push_back( Cell(row-1, col+2) );

    to_check.push_back( Cell(row+2, col-1) );
    to_check.push_back( Cell(row+1, col-2) );

    to_check.push_back( Cell(row-2, col-1) );
    to_check.push_back( Cell(row-1, col-2) );

    QVector<Cell> res;

    for (int i=0; i!=to_check.size(); i++)
    {
        Cell it = to_check[i];
        if (getDesk()->inRange(it))
            if (getDesk()->getFigure(it).isNull())
                res.push_back(it);
            else
                if (getDesk()->getFigure(cur_cell)->getColor() != getDesk()->getFigure(it)->getColor())
                    //meens that figure on target cell is enemy, we can go there
                    res.push_back(it);
    }

    return res;
}


///////////////////////////////////////////////////////////////////////////////////////
Pawn::Pawn(Desk *parent, FigColor inp_color) :
    Figure(parent, inp_color)
{
}

QString Pawn::getFigName() const
{
    return "P";
}

QVector<Cell> Pawn::cellsToMove(const Cell &cur_cell) const
{
    int row = cur_cell.row_;
    int col = cur_cell.col_;

    QVector<Cell> to_check4move;
    QVector<Cell> to_check4attack;

    QVector<Cell> res;

    if (getColor() == WHITE) {
        //it is IMPORTENT to add this first, we cant check next Cell if it is not valid
        to_check4move.push_back(Cell(row-1, col));

        if (row == Desk::getMaxCnt()-2)
            // it is first move if it steel there
            to_check4move.push_back(Cell(row-2, col));

        to_check4attack.push_back(Cell(row-1, col-1));
        to_check4attack.push_back(Cell(row-1, col+1));

    } else {
        //it is IMPORTENT to add this first, we cant check next Cell if it is not valid
        to_check4move.push_back(Cell(row+1, col));

        if (row == 1)
            // it is first move if it steel there
            to_check4move.push_back(Cell(row+2, col));

        to_check4attack.push_back(Cell(row+1, col-1));
        to_check4attack.push_back(Cell(row+1, col+1));
    }

    for (int i=0; i!=to_check4attack.size(); i++) {
        Cell cell = to_check4attack[i];
        if (getDesk()->inRange(cell))
            if (!getDesk()->getFigure(cell).isNull())
                if (getDesk()->getFigure(cur_cell)->getColor() != getDesk()->getFigure(cell)->getColor())
                    //meens that figure on target cell is enemy, we can go there
                    res.push_back(cell);
    }



    for (int i=0; i!=to_check4move.size(); i++) {
        Cell cell = to_check4move[i];
        if (getDesk()->inRange(cell))
            if (getDesk()->getFigure(cell).isNull()) {
                res.push_back(cell);
                continue;
            }

        break;
    }


    return res;
}

bool Pawn::check4move(const Cell &cell, QVector<Cell> &res) const
{
    if (getDesk()->inRange(cell))
        if (getDesk()->getFigure(cell).isNull()) {
            res.push_back(cell);
            return true;
        }

    return false;
}


