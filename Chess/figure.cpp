#include "figure.h"

Figure::Figure(QObject *parent, FigType inp_type, FigColor inp_color) :
    QObject(parent),
    owner_(parent),
    type_(inp_type),
    color_(inp_color)
{
}

std::vector<QObject *> Figure::cellsToMove()
{
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


///////////////////////////////////////////////////////////////////////////////////////
King::King(QObject *parent, FigColor inp_color) :
    Figure(parent, KING, inp_color)
{
}

std::vector<QObject *> King::cellsToMove()
{
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
    std::vector<QObject *> res;

    return res;
}

