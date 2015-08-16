#ifndef STATE_H
#define STATE_H

#include "common_types.h"
#include "game.h"
#include "gameimplementation.h"

class Game;
class GameImplementation;

class State
{
public:
    State();
    virtual ~State();

    virtual void cellAction(GameImplementation*, QString);

    virtual void startAction(GameImplementation*);
    virtual void stopAction(GameImplementation*);

    virtual void saveAction(GameImplementation*, QString);
    virtual bool loadAction(GameImplementation*, QString);

    virtual void rollback_from_list(GameImplementation*);
    virtual void make_move_from_list(GameImplementation*);

protected:
    void changeState (Game*, State*);

};


/////////////////////////////////////////////////////////////////////////
class StateOnStart : public State
{
public:
    StateOnStart() {}

    static State* Instance();

    virtual void cellAction(GameImplementation*, QString);
    virtual void startAction(GameImplementation*);
    virtual bool loadAction(GameImplementation*, QString);

private:
    static State *self_;

};

/////////////////////////////////////////////////////////////////////////
class StatePlayingGame : public State
{
public:
    StatePlayingGame() {}

    static State* Instance();

    virtual void cellAction(GameImplementation*, QString);
    virtual void stopAction(GameImplementation*);
    virtual void saveAction(GameImplementation *, QString);

private:
    static State *self_;

};

/////////////////////////////////////////////////////////////////////////
class StateLoadedGame : public State
{
public:
    StateLoadedGame() {}

    static State* Instance();

    virtual void cellAction(GameImplementation*, QString);
    virtual void startAction(GameImplementation *);
    virtual bool loadAction(GameImplementation*, QString);

    virtual void rollback_from_list(GameImplementation *);
    virtual void make_move_from_list(GameImplementation*);


private:
    static State *self_;

};

#endif // STATE_H
