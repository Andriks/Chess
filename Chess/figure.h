#ifndef FIGURE_H
#define FIGURE_H

#include "common_types.h"


///////////////////////////////////////////////////////////////////////////////////////
class Figure : public QObject
{
    Q_OBJECT
public:
    friend class Command;

    explicit Figure(Desk *desk_ = 0, FigColor fcolor=NONE);


    FigColor getColor() const;

    virtual QString getFigName() const = 0;

protected:
    bool freeCellsCheck4loop(const Cell &cur_cell, const Cell &cell, std::vector<Cell> &res) const;

    virtual std::vector<Cell> cellsToMove(const Cell &) const = 0;

protected:
    Desk *desk_;
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

///////////////////////////////////////////////////////////////////////////////////////
class Bishop : public Figure
{
    Q_OBJECT
public:
    explicit Bishop(Desk *parent, FigColor);

    virtual QString getFigName() const;

private:
   virtual std::vector<Cell> cellsToMove(const Cell &) const;

private:

};

///////////////////////////////////////////////////////////////////////////////////////
class Rook : public Figure
{
    Q_OBJECT
public:
    explicit Rook(Desk *parent, FigColor);

    virtual QString getFigName() const;

private:
   virtual std::vector<Cell> cellsToMove(const Cell &) const;

private:

};

///////////////////////////////////////////////////////////////////////////////////////
class Knight : public Figure
{
    Q_OBJECT
public:
    explicit Knight(Desk *parent, FigColor);

    virtual QString getFigName() const;

private:
   virtual std::vector<Cell> cellsToMove(const Cell &) const;

private:

};

///////////////////////////////////////////////////////////////////////////////////////
class Pawn : public Figure
{
    Q_OBJECT
public:
    explicit Pawn(Desk *parent, FigColor);

    virtual QString getFigName() const;

private:
    virtual std::vector<Cell> cellsToMove(const Cell &) const;

    bool check4move(const Cell &, std::vector<Cell> &) const;

private:

};

#endif // FIGURE_H
