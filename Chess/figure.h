#ifndef FIGURE_H
#define FIGURE_H

#include "common_types.h"


///////////////////////////////////////////////////////////////////////////////////////
class Figure : public QObject
{
    Q_OBJECT
public:
    friend class Command;

    explicit Figure(Desk *parent = 0, FigType ftype=EMPTY, FigColor fcolor=NONE);

    QString getFigName() const;
    QString getFigColor() const;

    //tmp func for Command
    FigType type();
    FigColor color();

protected:
    virtual std::vector<Cell> cellsToMove(const Cell &) const;

protected:
    Desk *owner_;    //ptr to figure owner (Desk instance)
    FigType type_;
    FigColor color_;

};


///////////////////////////////////////////////////////////////////////////////////////
class King : public Figure
{
    Q_OBJECT
public:
    explicit King(Desk *parent, FigColor);

private:
    virtual std::vector<Cell> cellsToMove(const Cell &) const;

private:


};

///////////////////////////////////////////////////////////////////////////////////////
class Queen : public Figure
{
    Q_OBJECT
public:
    explicit Queen(Desk *parent, FigColor);

private:
   virtual std::vector<Cell> cellsToMove(const Cell &) const;

private:

};

#endif // FIGURE_H
