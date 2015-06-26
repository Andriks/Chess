#include "figure.h"

Figure::Figure(QObject *parent) :
    QObject(parent),
    owner_(parent)
{
}

std::vector<QObject *> Figure::cellsToMove()
{
    std::vector<QObject *> res;

    return res;
}

QString Figure::figName()
{
    return "";
}


///////////////////////////////////////////////////////////////////////////////////////
King::King(QObject *parent) :
    Figure(parent)
{
}

std::vector<QObject *> King::cellsToMove()
{
    std::vector<QObject *> res;

    return res;
}

QString King::figName()
{
    return "K";
}