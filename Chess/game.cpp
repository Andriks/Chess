#include "game.h"

#include <QVariant>
#include <QQuickItem>


Game::Game(QObject *root) :
    root_(root),
    state_(NULL),
    game_impl_(NULL)
{
    state_ = StateOnStart::Instance();
    game_impl_ = new GameImplementation(this, root_);
}

//////////////////////////////////////////////////////////////////////////////////

void Game::cellAction(QString str)
{
    QPointer<QObject> msg = root_->findChild<QObject*>("chess_msg");

    try {
        state_->cellAction(game_impl_, str);
    } catch ( NotImplementedEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    } catch ( ChessEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    } catch ( std::exception &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    }
}

void Game::startAction()
{
    QPointer<QObject> msg = root_->findChild<QObject*>("chess_msg");

    try {
        state_->startAction(game_impl_);
    } catch ( NotImplementedEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    } catch ( ChessEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    } catch ( std::exception &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    }
}

void Game::stopAction()
{
    QPointer<QObject> msg = root_->findChild<QObject*>("chess_msg");

    try {
        state_->stopAction(game_impl_);
    } catch ( NotImplementedEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    } catch ( ChessEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    } catch ( std::exception &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    }
}

void Game::saveAction(QString str)
{
    QPointer<QObject> msg = root_->findChild<QObject*>("chess_msg");

    try {
        state_->saveAction(game_impl_, str);
    } catch ( NotImplementedEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    } catch ( ChessEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    } catch ( std::exception &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    }
}

bool Game::loadAction(QString str)
{
    QPointer<QObject> msg = root_->findChild<QObject*>("chess_msg");

    try {
        return state_->loadAction(game_impl_, str);
    } catch ( NotImplementedEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
        return false;
    } catch ( ChessEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
        return false;
    } catch ( std::exception &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
        return false;
    }
}

void Game::rollback_from_list()
{
    QPointer<QObject> msg = root_->findChild<QObject*>("chess_msg");

    try {
        state_->rollback_from_list(game_impl_);
    } catch ( NotImplementedEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    } catch ( ChessEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    } catch ( std::exception &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    }
}

void Game::make_move_from_list()
{
    QPointer<QObject> msg = root_->findChild<QObject*>("chess_msg");

    try {
        state_->make_move_from_list(game_impl_);
    } catch ( NotImplementedEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    } catch ( ChessEx &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    } catch ( std::exception &ex) {
        QMetaObject::invokeMethod(msg, "show", Q_ARG(QVariant, QVariant(ex.what())));
    }
}

//////////////////////////////////////////////////////////////////////////////////

void Game::changeState(State *state)
{
    state_ = state;
}

