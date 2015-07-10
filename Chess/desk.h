#ifndef DESK_H
#define DESK_H

#include "common_types.h"
#include "figure.h"
#include "command.h"

#include <QVector>


class Desk : public QObject
{
    Q_OBJECT
public:
    explicit Desk(QObject *parent = 0);

    bool grabFigure(const Cell&);
    bool putDownFigure(const Cell&);
    void switchActivePlayer();

    void rollback_from_list();
    void make_move_from_list();

    bool interruptCommand();

    const QVector<Command> &getState();
    void restoreState(const QVector<Command> &);

    QPointer<Figure> getFigure(const Cell &);
    QPointer<Figure> *getPtrFromBuffer(const Cell &);
    bool inRange(const Cell &) const;
    bool haveActiveFigure() const;
    static int getMaxCnt();

private:
    FigColor color_to_move_;    //color of figures to move
    bool have_active_figure_;   //we have grab some figure and start to write command_
    QVector< QVector<QPointer<Figure> > > buffer_;
    QPointer<Command> command_;          //current command
    QVector<Command> executed_commands_;

    static const int max_cnt_;

};


#endif // DESK_H
