#include "figure.h"

Figure::Figure(QObject *parent) :
    QObject(parent),
    owner_(parent)
{
}
