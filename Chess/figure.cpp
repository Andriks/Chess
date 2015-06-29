#include "figure.h"
#include "desk.h"

Figure::Figure(Desk *desk_, FigColor fcolor) :
    QObject(desk_),
    desk_(desk_),
    color_(fcolor)
{
}

FigColor Figure::getColor() const
{
    return color_;
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
        if (desk_->inRange(it))
            if (desk_->getFigure(it) == NULL)
                res.push_back(it);
            else
                if (desk_->getFigure(cur_cell)->getColor() != desk_->getFigure(it)->getColor())
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
        if (!desk_->inRange(cell))
            break;

        if (desk_->getFigure(cell) != NULL)
            if (desk_->getFigure(cur_cell)->getColor() != desk_->getFigure(cell)->getColor()) {
                res.push_back(cell);
                break;
            } else
                break;

        res.push_back(cell);
    }

    i = row;
    while (true) {
        Cell cell(--i, col);
        if (!desk_->inRange(cell))
            break;

        if (desk_->getFigure(cell) != NULL)
            if (desk_->getFigure(cur_cell)->getColor() != desk_->getFigure(cell)->getColor()) {
                res.push_back(cell);
                break;
            } else
                break;

        res.push_back(cell);
    }

    i = col;
    while (true) {
        Cell cell(row, ++i);
        if (!desk_->inRange(cell))
            break;

        if (desk_->getFigure(cell) != NULL)
            if (desk_->getFigure(cur_cell)->getColor() != desk_->getFigure(cell)->getColor()) {
                res.push_back(cell);
                break;
            } else
                break;

        res.push_back(cell);
    }

    i = col;
    while (true) {
        Cell cell(row, --i);
        if (!desk_->inRange(cell))
            break;

        if (desk_->getFigure(cell) != NULL)
            if (desk_->getFigure(cur_cell)->getColor() != desk_->getFigure(cell)->getColor()) {
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


///////////////////////////////////////////////////////////////////////////////////////
Bishop::Bishop(Desk *parent, FigColor inp_color) :
    Figure(parent, inp_color)
{
}

QString Bishop::getFigName() const
{
    return "B";
}

std::vector<Cell> Bishop::cellsToMove(const Cell &cur_cell) const
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
        if (desk_->inRange(it))
            if (desk_->getFigure(it) == NULL)
                res.push_back(it);
            else
                if (desk_->getFigure(cur_cell)->getColor() != desk_->getFigure(it)->getColor())
                    //meens that figure on target cell is enemy, we can go there
                    res.push_back(it);
    }

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

std::vector<Cell> Rook::cellsToMove(const Cell &cur_cell) const
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
        if (desk_->inRange(it))
            if (desk_->getFigure(it) == NULL)
                res.push_back(it);
            else
                if (desk_->getFigure(cur_cell)->getColor() != desk_->getFigure(it)->getColor())
                    //meens that figure on target cell is enemy, we can go there
                    res.push_back(it);
    }

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

std::vector<Cell> Knight::cellsToMove(const Cell &cur_cell) const
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
        if (desk_->inRange(it))
            if (desk_->getFigure(it) == NULL)
                res.push_back(it);
            else
                if (desk_->getFigure(cur_cell)->getColor() != desk_->getFigure(it)->getColor())
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

std::vector<Cell> Pawn::cellsToMove(const Cell &cur_cell) const
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
        if (desk_->inRange(it))
            if (desk_->getFigure(it) == NULL)
                res.push_back(it);
            else
                if (desk_->getFigure(cur_cell)->getColor() != desk_->getFigure(it)->getColor())
                    //meens that figure on target cell is enemy, we can go there
                    res.push_back(it);
    }

    return res;
}

