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
    static QString colorForGUI(const FigColor &);

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

private:
    void drawCurState();
    void drawCell(const Cell &);
    void interruptAction();

private:
    QObject *root_;             //for access to gui elements
    Desk *desk_;                //ptr to desk instance (game have 1 instance of desk during all life period)
    bool desk_is_active_;       //desk must be active only on screen 2
};

#endif // GAME_H
