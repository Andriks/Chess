#ifndef STATE_H
#define STATE_H

#include "common_types.h"
#include "game.h"

class Game;

class State
{
public:
    State();
    virtual ~State();

    virtual void cellAction(Game*, QString);

    virtual void startAction(Game*);
    virtual void stopAction(Game*);

    virtual void saveAction(Game*, QString);
    virtual bool loadAction(Game*, QString);

    virtual void rollback_from_list(Game*);
    virtual void make_move_from_list(Game*);

protected:
    void ChangeState (Game*, State*);

};


/////////////////////////////////////////////////////////////////////////
class StateOnStart : public State
{
public:
    StateOnStart() {}

    static State* Instance();

    virtual void cellAction(Game*, QString);
    virtual void startAction(Game*);
    virtual bool loadAction(Game*, QString);

private:
    static State *self_;

};

/////////////////////////////////////////////////////////////////////////
class StatePlayingGame : public State
{
public:
    StatePlayingGame() {}

    static State* Instance();

    virtual void cellAction(Game*, QString);
    virtual void stopAction(Game*);
    virtual void saveAction(Game*, QString);

private:
    static State *self_;

};

/////////////////////////////////////////////////////////////////////////
class StateLoadedGame : public State
{
public:
    StateLoadedGame() {}

    static State* Instance();

    virtual void cellAction(Game*, QString);
    virtual void startAction(Game*);
    virtual bool loadAction(Game*, QString);

    virtual void rollback_from_list(Game*);
    virtual void make_move_from_list(Game*);


private:
    static State *self_;

};

#endif // STATE_H
