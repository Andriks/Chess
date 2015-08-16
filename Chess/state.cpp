#include "state.h"


State::State()
{
}

State::~State()
{
}


void State::cellAction(GameImplementation *state, QString str){ throw NotImplementedEx(); }

void State::startAction(GameImplementation *state){ throw NotImplementedEx(); }

void State::stopAction(GameImplementation *state){ throw NotImplementedEx(); }

void State::saveAction(GameImplementation *state, QString str){ throw NotImplementedEx(); }

bool State::loadAction(GameImplementation *state, QString str){ throw NotImplementedEx(); }

void State::rollback_from_list(GameImplementation *state){ throw NotImplementedEx(); }

void State::make_move_from_list(GameImplementation *state){ throw NotImplementedEx(); }

void State::changeState(Game *proxy_obj, State *state)
{
    proxy_obj->changeState(state);
}


/////////////////////////////////////////////////////////////////////////

State* StateOnStart::self_(0);

State *StateOnStart::Instance()
{
    if(!self_) {
        self_ = new StateOnStart();
    }

    return self_;
}

void StateOnStart::cellAction(GameImplementation *user, QString str) {}

void StateOnStart::startAction(GameImplementation *user)
{
    user->startAction();

    Game *proxy_obj = dynamic_cast <Game*> (user->parent());
    changeState(proxy_obj, StatePlayingGame::Instance());
}

bool StateOnStart::loadAction(GameImplementation *user, QString str)
{
    if (user->loadAction(str)) {
        Game *proxy_obj = dynamic_cast <Game*> (user->parent());
        changeState(proxy_obj, StateLoadedGame::Instance());
        return true;
    } else {
        return false;
    }
}


/////////////////////////////////////////////////////////////////////////

State* StatePlayingGame::self_(0);

State *StatePlayingGame::Instance()
{
    if(!self_) {
        self_ = new StatePlayingGame();
    }

    return self_;
}

void StatePlayingGame::cellAction(GameImplementation *user, QString str)
{
    user->cellAction(str);
}

void StatePlayingGame::stopAction(GameImplementation *user)
{
    user->stopAction();

    Game *proxy_obj = dynamic_cast <Game*> (user->parent());
    changeState(proxy_obj, StateOnStart::Instance());
}

void StatePlayingGame::saveAction(GameImplementation *user, QString str)
{
    user->saveAction(str);
}


/////////////////////////////////////////////////////////////////////////

State* StateLoadedGame::self_(0);

State *StateLoadedGame::Instance()
{
    if(!self_) {
        self_ = new StateLoadedGame();
    }

    return self_;
}

void StateLoadedGame::cellAction(GameImplementation *user, QString str) {}

void StateLoadedGame::startAction(GameImplementation *user)
{
    user->startAction();

    Game *proxy_obj = dynamic_cast <Game*> (user->parent());
    changeState(proxy_obj, StatePlayingGame::Instance());
}

bool StateLoadedGame::loadAction(GameImplementation *user, QString str)
{
    return user->loadAction(str);
}

void StateLoadedGame::rollback_from_list(GameImplementation *user)
{
    user->rollback_from_list();
}

void StateLoadedGame::make_move_from_list(GameImplementation *user)
{
    user->make_move_from_list();
}

