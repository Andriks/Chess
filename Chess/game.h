#ifndef GAME_H
#define GAME_H

#include "common_types.h"


class Game : public QObject
{
    Q_OBJECT
public:
    // !!IMPORTANT!! Game instance should to be deleted explicit!
    // it have no QObject owner to be deleted automatically
    explicit Game(QObject *parent = 0);

    static Cell parseQMLCellName(QString);

signals:

public slots:
    //desk action handler
    void cellAction(QString);

    //btn action handlers
    void startAction();
    void stopAction();
    void saveAction();
    void loadAction();
    void tmpDraw();

private:
    void drawCurState();
    void drawCommand();
    void interruptCommand();

private:
    QObject *root_;     //for access to gui elements
    Desk *desk_;        //ptr to desk instance (game have 1 instance of desk during all life period)
    Command *command_;  //current command
    //std::vector<Command> executed_commands_;
};

#endif // GAME_H
