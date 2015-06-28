#ifndef FIGURE_H
#define FIGURE_H

#include "common_types.h"


///////////////////////////////////////////////////////////////////////////////////////
class Figure : public QObject
{
    Q_OBJECT
public:
    explicit Figure(QObject *parent = 0, FigType ftype=EMPTY, FigColor fcolor=NONE);

    QString getFigName() const;
    QString getFigColor() const;

    //tmp func for Command
    FigType type();
    FigColor color();

private:
    //virtual std::vector<Desk::Cell> cellsToMove();
    virtual std::vector<QObject *> cellsToMove();

private:
    QObject *owner_;    //ptr to figure owner (Desk instance)
    FigType type_;
    FigColor color_;

};


///////////////////////////////////////////////////////////////////////////////////////
class King : public Figure
{
    Q_OBJECT
public:
    explicit King(QObject *parent, FigColor);

private:
    //virtual std::vector<Desk::Cell> cellsToMove();
    virtual std::vector<QObject *> cellsToMove();

private:


};

///////////////////////////////////////////////////////////////////////////////////////
class Queen : public Figure
{
    Q_OBJECT
public:
    explicit Queen(QObject *parent, FigColor);

private:
   //virtual std::vector<Desk::Cell> cellsToMove();
    virtual std::vector<QObject *> cellsToMove();

private:

};

#endif // FIGURE_H
