#ifndef GAMEIMPLEMENTATION_H
#define GAMEIMPLEMENTATION_H

#include "common_types.h"
#include "game.h"
#include "desk.h"

class GameImplementation : public QObject
{
    Q_OBJECT
public:
    explicit GameImplementation(QObject *parent = 0, QObject *root = 0);

public:
    void cellAction(QString);

    void startAction();
    void stopAction();

    void saveAction(QString);
    bool loadAction(QString);

    void rollback_from_list();
    void make_move_from_list();

private:
    static Cell parseQMLCellName(QString);
    static QString colorForGUI(const FigColor &);

    void drawCurState();
    void drawCell(const Cell &);
    void interruptAction();


private:
    QPointer<QObject> root_;    //for access to gui elements
    QPointer<Desk> desk_;       //ptr to desk instance (game have 1 instance of desk during all life period)

};

#endif // GAMEIMPLEMENTATION_H
