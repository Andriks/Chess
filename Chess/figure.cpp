#include "figure.h"
#include "desk.h"

Figure::Figure(Desk *parent, FigType ftype, FigColor fcolor) :
    QObject(parent),
    owner_(parent),
    type_(ftype),
    color_(fcolor)
{
}

std::vector<Cell> Figure::cellsToMove(const Cell &cur_cell) const
{
    std::vector<Cell> res;

    return res;
}

QString Figure::getFigName() const
{
    switch (type_) {
    case KING:
        return "K";
    case QUEEN:
        return "Q";
    case ROOK:
        return "R";
    case BISHOP:
        return "B";
    case KNIGHT:
        return "Kn";
    case PAWN:
        return "p";
    default:
        return "";
    }
}

QString Figure::getFigColor() const
{
    switch (color_) {
    case BLACK:
        return "black";
    case WHITE:
        return "blue";
    default:
        return "";
    }
}

FigType Figure::type()
{
    return type_;
}

FigColor Figure::color()
{
    return color_;
}


///////////////////////////////////////////////////////////////////////////////////////
King::King(Desk *parent, FigColor inp_color) :
    Figure(parent, KING, inp_color)
{
}

std::vector<Cell> King::cellsToMove(const Cell &cur_cell) const
{
    int row = cur_cell.row_;
    int col = cur_cell.col_;

    std::vector<Cell> to_check;
    to_check.push_back( Cell(row-1, col-1) );
    to_check.push_back( Cell(row-1, col  ) );
    to_check.push_back( Cell(row-1, col+1) );

    to_check.push_back( Cell(row, col-1) );
    to_check.push_back( Cell(row, col+1) );

    to_check.push_back( Cell(row+1, col-1) );
    to_check.push_back( Cell(row+1, col  ) );
    to_check.push_back( Cell(row+1, col+1) );

    std::vector<Cell> res;

    for (int i=0; i!=to_check.size(); i++)
    {
        Cell it = to_check[i];
        if (owner_->inRange(it))
            if (owner_->getFigure(it) == NULL)
                res.push_back(it);
            else
                if (owner_->getFigure(cur_cell)->color() != owner_->getFigure(it)->color())
                    //meens that figure on target cell is enemy, we can go there
                    res.push_back(it);
    }
//have problems with *it here ... err
//    for (std::vector<Cell>::iterator it=to_check.begin(); it != to_check.end(); it++)
//    {
//        if (owner_->inRange(*it))
//            if (owner_->getFigure(*it) == NULL)
//                res.push_back(*it);
//            else
//                if (owner_->getFigure(cur_cell)->color() != owner_->getFigure(*it)->color())
//                    //meens that figure on target cell is enemy, we can go there
//                    res.push_back(*it);
//    }

    return res;
}


///////////////////////////////////////////////////////////////////////////////////////
Queen::Queen(Desk *parent, FigColor inp_color) :
    Figure(parent, QUEEN, inp_color)
{
}

std::vector<Cell> Queen::cellsToMove(const Cell &cur_cell) const
{

    /*******************************/
    /******TMP FROM KING************/
    /*******************************/

    int row = cur_cell.row_;
    int col = cur_cell.col_;

    std::vector<Cell> to_check;
    to_check.push_back( Cell(row-1, col-1) );
    to_check.push_back( Cell(row-1, col  ) );
    to_check.push_back( Cell(row-1, col+1) );

    to_check.push_back( Cell(row, col-1) );
    to_check.push_back( Cell(row, col+1) );

    to_check.push_back( Cell(row+1, col-1) );
    to_check.push_back( Cell(row+1, col  ) );
    to_check.push_back( Cell(row+1, col+1) );

    std::vector<Cell> res;

    for (int i=0; i!=to_check.size(); i++)
    {
        Cell it = to_check[i];
        if (owner_->inRange(it))
            if (owner_->getFigure(it) == NULL)
                res.push_back(it);
            else
                if (owner_->getFigure(cur_cell)->color() != owner_->getFigure(it)->color())
                    //meens that figure on target cell is enemy, we can go there
                    res.push_back(it);
    }

    return res;
}

