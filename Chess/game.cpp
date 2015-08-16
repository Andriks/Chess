#include "game.h"

#include <QVariant>
#include <QQuickItem>


Game::Game(QObject *parent) :
    root_(parent),
    state_(NULL)
{
    state_ = StateOnStart::Instance();
    game_impl = new GameImplementation(this, root_);
}

//////////////////////////////////////////////////////////////////////////////////

void Game::cellAction(QString str)
{
    QPointer<QObject> msg = root_->findChild<QObject*>("chess_msg");

    try {
        state_->cellAction(game_impl, str);
    } catch (const NotImplementedEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("using of not implemented method")));
    } catch (const ChessEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("chess error occured")));
    } catch (const std::exception &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("system error occured")));
    }
}

void Game::startAction()
{
    QPointer<QObject> msg = root_->findChild<QObject*>("chess_msg");

    try {
        state_->startAction(game_impl);
    } catch (const NotImplementedEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("using of not implemented method")));
    } catch (const ChessEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("chess error occured")));
    } catch (const std::exception &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("system error occured")));
    }
}

void Game::stopAction()
{
    QPointer<QObject> msg = root_->findChild<QObject*>("chess_msg");

    try {
        state_->stopAction(game_impl);
    } catch (const NotImplementedEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("using of not implemented method")));
    } catch (const ChessEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("chess error occured")));
    } catch (const std::exception &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("system error occured")));
    }
}

void Game::saveAction(QString str)
{
    QPointer<QObject> msg = root_->findChild<QObject*>("chess_msg");

    try {
        state_->saveAction(game_impl, str);
    } catch (const NotImplementedEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("using of not implemented method")));
    } catch (const ChessEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("chess error occured")));
    } catch (const std::exception &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("system error occured")));
    }
}

bool Game::loadAction(QString str)
{
    QPointer<QObject> msg = root_->findChild<QObject*>("chess_msg");

    try {
        return state_->loadAction(game_impl, str);
    } catch (const NotImplementedEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("using of not implemented method")));
        return false;
    } catch (const ChessEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("chess error occured")));
        return false;
    } catch (const std::exception &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("system error occured")));
        return false;
    }
}

void Game::rollback_from_list()
{
    QPointer<QObject> msg = root_->findChild<QObject*>("chess_msg");

    try {
        state_->rollback_from_list(game_impl);
    } catch (const NotImplementedEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("using of not implemented method")));
    } catch (const ChessEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("chess error occured")));
    } catch (const std::exception &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("system error occured")));
    }
}

void Game::make_move_from_list()
{
    QPointer<QObject> msg = root_->findChild<QObject*>("chess_msg");

    try {
        state_->make_move_from_list(game_impl);
    } catch (const NotImplementedEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("using of not implemented method")));
    } catch (const ChessEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("chess error occured")));
    } catch (const std::exception &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant("system error occured")));
    }
}

//////////////////////////////////////////////////////////////////////////////////

void Game::changeState(State *state)
{
    state_ = state;
}

