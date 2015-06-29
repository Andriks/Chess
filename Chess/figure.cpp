#include "figure.h"
#include "desk.h"

Figure::Figure(Desk *owner, FigType ftype, FigColor fcolor) :
    QObject(owner),
    owner_(owner),
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
    return "";
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

FigType Figure::type() const
{
    return type_;
}

FigColor Figure::color() const
{
    return color_;
}


///////////////////////////////////////////////////////////////////////////////////////
King::King(Desk *parent, FigColor inp_color) :
    Figure(parent, KING, inp_color)
{
}

QString King::getFigName() const
{
    return "K";
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

    return res;
}


///////////////////////////////////////////////////////////////////////////////////////
Queen::Queen(Desk *parent, FigColor inp_color) :
    Figure(parent, QUEEN, inp_color)
{
}

QString Queen::getFigName() const
{
    return "Q";
}

std::vector<Cell> Queen::cellsToMove(const Cell &cur_cell) const
{
    std::vector<Cell> res;

    int row = cur_cell.row_;
    int col = cur_cell.col_;

    /****************/
    /****ROOK********/
    /****************/
    int i = row;
    while (true) {
        Cell cell(++i, col);
        if (!owner_->inRange(cell))
            break;

        if (owner_->getFigure(cell) != NULL)
            if (owner_->getFigure(cur_cell)->color() != owner_->getFigure(cell)->color()) {
                res.push_back(cell);
                break;
            } else
                break;

        res.push_back(cell);
    }

    i = row;
    while (true) {
        Cell cell(--i, col);
        if (!owner_->inRange(cell))
            break;

        if (owner_->getFigure(cell) != NULL)
            if (owner_->getFigure(cur_cell)->color() != owner_->getFigure(cell)->color()) {
                res.push_back(cell);
                break;
            } else
                break;

        res.push_back(cell);
    }

    i = col;
    while (true) {
        Cell cell(row, ++i);
        if (!owner_->inRange(cell))
            break;

        if (owner_->getFigure(cell) != NULL)
            if (owner_->getFigure(cur_cell)->color() != owner_->getFigure(cell)->color()) {
                res.push_back(cell);
                break;
            } else
                break;

        res.push_back(cell);
    }

    i = col;
    while (true) {
        Cell cell(row, --i);
        if (!owner_->inRange(cell))
            break;

        if (owner_->getFigure(cell) != NULL)
            if (owner_->getFigure(cur_cell)->color() != owner_->getFigure(cell)->color()) {
                res.push_back(cell);
                break;
            } else
                break;

        res.push_back(cell);
    }

    /****************/
    /****BISHOP******/
    /****************/

    return res;
}

