#include "figure.h"

Figure::Figure(QObject *parent, FigType ftype, FigColor fcolor) :
    QObject(parent),
    owner_(parent),
    type_(ftype),
    color_(fcolor)
{
}

std::vector<QObject *> Figure::cellsToMove()
{
    //std::vector<Desk::Cell> res;
    std::vector<QObject *> res;

    return res;
}

QString Figure::getFigName() const
{
    switch (type_) {
    case Figure::KING:
        return "K";
    case Figure::QUEEN:
        return "Q";
    case Figure::ROOK:
        return "R";
    case Figure::BISHOP:
        return "B";
    case Figure::KNIGHT:
        return "Kn";
    case Figure::PAWN:
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

Figure::FigType Figure::type()
{
    return type_;
}

Figure::FigColor Figure::color()
{
    return color_;
}


///////////////////////////////////////////////////////////////////////////////////////
King::King(QObject *parent, FigColor inp_color) :
    Figure(parent, KING, inp_color)
{
}

std::vector<QObject *> King::cellsToMove()
{
    //std::vector<Desk::Cell> res;
    std::vector<QObject *> res;

    return res;
}


///////////////////////////////////////////////////////////////////////////////////////
Queen::Queen(QObject *parent, FigColor inp_color) :
    Figure(parent, QUEEN, inp_color)
{
}

std::vector<QObject *> Queen::cellsToMove()
{
    //std::vector<Desk::Cell> res;
    std::vector<QObject *> res;

    return res;
}

