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

    QString getFigColor() const;

    //returns enums for Command
    FigType type() const;
    FigColor color() const;

    virtual QString getFigName() const;

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
