#include "game.h"
#include <qfiledialog.h>

Game::Game(QObject *parent) :
    //QObject(parent),
    viewer_(parent)
{
    desk_ = new Desk(this);
}

void Game::cellAction(QString cell_name)
{

}

void Game::startAction()
{
    desk_->fillDefault();
}

void Game::stopAction()
{

}

void Game::saveAction()
{

}

void Game::loadAction()
{
//    QString filename = QFileDialog::getOpenFileName(
//                this,
//                tr("dsdasda"),
//                "D://"
//                );


}
