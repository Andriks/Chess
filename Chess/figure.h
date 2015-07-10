#ifndef FIGURE_H
#define FIGURE_H

#include "common_types.h"


///////////////////////////////////////////////////////////////////////////////////////
class Figure : public QObject
{
    Q_OBJECT
public:
    explicit Figure(Desk *desk_ = 0, FigColor fcolor=NONE);

    FigColor getColor() const;
    QPointer<Desk> getDesk() const;

    virtual QString getFigName() const = 0;
    virtual QVector<Cell> cellsToMove(const Cell &) const = 0;

protected:
    bool freeCellsCheck4loop(const Cell &cur_cell, const Cell &cell, QVector<Cell> &res) const;

private:
    QPointer<Desk> desk_;
    FigColor color_;

};


///////////////////////////////////////////////////////////////////////////////////////
class King : public Figure
{
    Q_OBJECT
public:
    explicit King(Desk *parent, FigColor);

    virtual QString getFigName() const;
    virtual QVector<Cell> cellsToMove(const Cell &) const;

};

///////////////////////////////////////////////////////////////////////////////////////
class Queen : public Figure
{
    Q_OBJECT
public:
    explicit Queen(Desk *parent, FigColor);

    virtual QString getFigName() const;
    virtual QVector<Cell> cellsToMove(const Cell &) const;

};

///////////////////////////////////////////////////////////////////////////////////////
class Bishop : public Figure
{
    Q_OBJECT
public:
    explicit Bishop(Desk *parent, FigColor);

    virtual QString getFigName() const;
    virtual QVector<Cell> cellsToMove(const Cell &) const;

};

///////////////////////////////////////////////////////////////////////////////////////
class Rook : public Figure
{
    Q_OBJECT
public:
    explicit Rook(Desk *parent, FigColor);

    virtual QString getFigName() const;
    virtual QVector<Cell> cellsToMove(const Cell &) const;

};

///////////////////////////////////////////////////////////////////////////////////////
class Knight : public Figure
{
    Q_OBJECT
public:
    explicit Knight(Desk *parent, FigColor);

    virtual QString getFigName() const;
    virtual QVector<Cell> cellsToMove(const Cell &) const;

};

///////////////////////////////////////////////////////////////////////////////////////
class Pawn : public Figure
{
    Q_OBJECT
public:
    explicit Pawn(Desk *parent, FigColor);

    virtual QString getFigName() const;
    virtual QVector<Cell> cellsToMove(const Cell &) const;

private:
    bool check4move(const Cell &, QVector<Cell> &) const;

};

#endif // FIGURE_H
