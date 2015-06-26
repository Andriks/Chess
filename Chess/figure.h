#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>


///////////////////////////////////////////////////////////////////////////////////////
class Figure : public QObject
{
    Q_OBJECT

private:
    enum FigType{EMPTY/*base class*/, KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};
    enum FigColor{NONE/*base class*/, WHITE, BLACK};

public:
    explicit Figure(QObject *parent = 0);

signals:

public slots:

private:
    virtual std::vector<QObject*> cellsToMove();
    virtual QString figName();

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
    explicit King(QObject *parent = 0);

private:
    virtual std::vector<QObject*> cellsToMove();
    virtual QString figName();

};

#endif // FIGURE_H
