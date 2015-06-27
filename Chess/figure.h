#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>


///////////////////////////////////////////////////////////////////////////////////////
class Figure : public QObject
{
    Q_OBJECT

public:
    enum FigType{EMPTY/*base class*/, KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};
    enum FigColor{NONE/*base class*/, WHITE, BLACK};

public:
    explicit Figure(QObject *parent, FigType, FigColor);

    QString getFigName() const;
    QString getFigColor() const;


private:
    virtual std::vector<QObject*> cellsToMove();

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
    virtual std::vector<QObject*> cellsToMove();

private:


};

///////////////////////////////////////////////////////////////////////////////////////
class Queen : public Figure
{
    Q_OBJECT
public:
    explicit Queen(QObject *parent, FigColor);

private:
    virtual std::vector<QObject*> cellsToMove();

private:

};

#endif // FIGURE_H
