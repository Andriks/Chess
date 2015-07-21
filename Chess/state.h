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
class State1 : public State
{
public:
    State1() {}

    static State* Instance();

    void cellAction(Game*, QString);
    void startAction(Game*);
    bool loadAction(Game*, QString);

private:
    static State *self_;

};

/////////////////////////////////////////////////////////////////////////
class State2 : public State
{
public:
    State2() {}

    static State* Instance();

    void cellAction(Game*, QString);
    void stopAction(Game*);
    void saveAction(Game*, QString);

private:
    static State *self_;

};

/////////////////////////////////////////////////////////////////////////
class State3 : public State
{
public:
    State3() {}

    static State* Instance();

    void cellAction(Game*, QString);
    void startAction(Game*);
    bool loadAction(Game*, QString);

    void rollback_from_list(Game*);
    void make_move_from_list(Game*);


private:
    static State *self_;

};

#endif // STATE_H
