#ifndef DESK_H
#define DESK_H

#include "common_types.h"
#include "figure.h"
#include "command.h"

#include <vector>


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

    void saveStateIntoFile(QString &);
    void restoreState(const std::vector<Command> &);

    Figure *getFigure(const Cell &) const;
    Figure **getPtrFromBuffer(const Cell &);
    Command *getCommand();
    bool inRange(const Cell &) const;
    bool haveActiveFigure() const;
    static int getMaxCnt();

private:
    FigColor color_to_move_;    //color of figures to move
    bool have_active_figure_;   //we have grab some figure and start to write command_
    std::vector< std::vector<Figure*> > buffer_;
    Command *command_;          //current command
    std::vector<Command> executed_commands_;

    static const int max_cnt_;

};


#endif // DESK_H
