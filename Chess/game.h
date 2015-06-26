#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <qstring.h>

class Game : public QObject
{
    Q_OBJECT
public:
    explicit Game(QObject *parent = 0);

signals:

public slots:
    void cellAction(QString);
    void startAction();
    void stopAction();
    void saveAction();
    void loadAction();


protected:
    QObject *viewer_;

};

#endif // GAME_H
