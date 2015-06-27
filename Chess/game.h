#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <qstring.h>

#include "desk.h"

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
    void saveAction();
    void loadAction();

private:
    void drawCurState();

private:
    QObject *root_;       //for access to gui elements
    //QObject *desk_;         //ptr to desk instance (game have 1 instance of desk during all life period)
    Desk *desk_;         //ptr to desk instance (game have 1 instance of desk during all life period)
};

#endif // GAME_H
