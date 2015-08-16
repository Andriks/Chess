#ifndef GAME_H
#define GAME_H

#include "common_types.h"
#include "state.h"
#include "gameimplementation.h"

class State;

class Game : public QObject
{
    Q_OBJECT
public:
    // !!IMPORTANT!! Game instance should to be deleted explicit!
    // it have no QObject owner to be deleted automatically
    explicit Game(QObject *parent = 0);

signals:

public slots:
    //desk action handler
    void cellAction(QString);

    //btn action handlers
    void startAction();
    void stopAction();

    //FileDialog in qml have no feature for creating file and saving in it
    //we can save only in existing *.txt file
    void saveAction(QString);
    bool loadAction(QString);

    void rollback_from_list();
    void make_move_from_list();

public:
    void changeState(State*);

private:
    QPointer<QObject> root_;    //for access to gui elements
    State *state_;              //curr state of game (curr screen)
    GameImplementation *game_impl;
};

#endif // GAME_H
