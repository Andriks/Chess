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
    user->ChangeState(state);
}


/////////////////////////////////////////////////////////////////////////

State* State1::self_(0);

State *State1::Instance()
{
    if(!self_) {
        self_ = new State1();
    }

    return self_;
}

void State1::cellAction(Game *user, QString str) {}

void State1::startAction(Game *user)
{
    user->startAction_impl();
    ChangeState(user, State2::Instance());
}

bool State1::loadAction(Game *user, QString str)
{
    if (user->loadAction_impl(str)) {
        ChangeState(user, State3::Instance());
        return true;
    } else {
        return false;
    }
}


/////////////////////////////////////////////////////////////////////////

State* State2::self_(0);

State *State2::Instance()
{
    if(!self_) {
        self_ = new State2();
    }

    return self_;
}

void State2::cellAction(Game *user, QString str)
{
    user->cellAction_impl(str);
}

void State2::stopAction(Game *user)
{
    user->stopAction_impl();
    ChangeState(user, State1::Instance());
}

void State2::saveAction(Game *user, QString str)
{
    user->saveAction_impl(str);
}


/////////////////////////////////////////////////////////////////////////

State* State3::self_(0);

State *State3::Instance()
{
    if(!self_) {
        self_ = new State3();
    }

    return self_;
}

void State3::cellAction(Game *user, QString str) {}

void State3::startAction(Game *user)
{
    user->startAction_impl();
    ChangeState(user, State2::Instance());
}

bool State3::loadAction(Game *user, QString str)
{
    return user->loadAction_impl(str);
}

void State3::rollback_from_list(Game *user)
{
    user->rollback_from_list_impl();
}

void State3::make_move_from_list(Game *user)
{
    user->make_move_from_list_impl();
}

