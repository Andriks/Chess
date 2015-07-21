#ifndef GAME_H
#define GAME_H

#include "common_types.h"
#include "state.h"

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
    void cellAction_impl(QString);

    void startAction_impl();
    void stopAction_impl();

    void saveAction_impl(QString);
    bool loadAction_impl(QString);

    void rollback_from_list_impl();
    void make_move_from_list_impl();

    void ChangeState(State*);
private:
    static Cell parseQMLCellName(QString);
    static QString colorForGUI(const FigColor &);

    void drawCurState();
    void drawCell(const Cell &);
    void interruptAction();

private:
    QPointer<QObject> root_;    //for access to gui elements
    QPointer<Desk> desk_;       //ptr to desk instance (game have 1 instance of desk during all life period)
    State *state_;              //curr state of game (curr screen)
};

#endif // GAME_H
