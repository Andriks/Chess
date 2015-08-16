#include "state.h"


State::State()
{
}

State::~State()
{
}


void State::cellAction(Game *state, QString str){ throw NotImplementedEx(); }

void State::startAction(Game *state){ throw NotImplementedEx(); }

void State::stopAction(Game *state){ throw NotImplementedEx(); }

void State::saveAction(Game *state, QString str){ throw NotImplementedEx(); }

bool State::loadAction(Game *state, QString str){ throw NotImplementedEx(); }

void State::rollback_from_list(Game *state){ throw NotImplementedEx(); }

void State::make_move_from_list(Game *state){ throw NotImplementedEx(); }

void State::ChangeState(Game *user, State *state)
{
    user->changeState(state);
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

void StateOnStart::cellAction(Game *user, QString str) {}

void StateOnStart::startAction(Game *user)
{
    user->startAction_impl();
    ChangeState(user, StatePlayingGame::Instance());
}

bool StateOnStart::loadAction(Game *user, QString str)
{
    if (user->loadAction_impl(str)) {
        ChangeState(user, StateLoadedGame::Instance());
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

void StatePlayingGame::cellAction(Game *user, QString str)
{
    user->cellAction_impl(str);
}

void StatePlayingGame::stopAction(Game *user)
{
    user->stopAction_impl();
    ChangeState(user, StateOnStart::Instance());
}

void StatePlayingGame::saveAction(Game *user, QString str)
{
    user->saveAction_impl(str);
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

void StateLoadedGame::cellAction(Game *user, QString str) {}

void StateLoadedGame::startAction(Game *user)
{
    user->startAction_impl();
    ChangeState(user, StatePlayingGame::Instance());
}

bool StateLoadedGame::loadAction(Game *user, QString str)
{
    return user->loadAction_impl(str);
}

void StateLoadedGame::rollback_from_list(Game *user)
{
    user->rollback_from_list_impl();
}

void StateLoadedGame::make_move_from_list(Game *user)
{
    user->make_move_from_list_impl();
}

