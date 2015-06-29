#ifndef FIGURE_H
#define FIGURE_H

#include "common_types.h"


///////////////////////////////////////////////////////////////////////////////////////
class Figure : public QObject
{
    Q_OBJECT
public:
    friend class Command;

    explicit Figure(Desk *parent = 0, FigColor fcolor=NONE);

    //returns name of color for gui
    QString getFigColor() const;

    //returns enum for Command
    FigColor color() const;

    virtual QString getFigName() const;

protected:
    virtual std::vector<Cell> cellsToMove(const Cell &) const;

protected:
    Desk *desk_;    //ptr to figure owner (Desk instance)
    FigColor color_;

};


///////////////////////////////////////////////////////////////////////////////////////
class King : public Figure
{
    Q_OBJECT
public:
    explicit King(Desk *parent, FigColor);

    virtual QString getFigName() const;

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

    virtual QString getFigName() const;

private:
   virtual std::vector<Cell> cellsToMove(const Cell &) const;

private:

};

#endif // FIGURE_H
