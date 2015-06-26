#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>


///////////////////////////////////////////////////////////////////////////////////////
class Figure : public QObject
{
    Q_OBJECT

private:
    enum{EMPTY/*base class*/, KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN};

public:
    explicit Figure(QObject *parent = 0);

signals:

public slots:

private:
    virtual std::vector<QObject*> cellsToMove();

private:
    QObject *owner_;    //ptr to figure owner (Desk instance)

};


///////////////////////////////////////////////////////////////////////////////////////
class King : public Figure
{
    Q_OBJECT
public:
    explicit King(QObject *parent = 0);

private:
    virtual std::vector<QObject*> cellsToMove();

};

#endif // FIGURE_H
