#include "game.h"
#include <qfiledialog.h>
#include <QVariant>

Game::Game(QObject *parent) :
    root_(parent)
{
    desk_ = new Desk(this);
}

void Game::cellAction(QString cell_name)
{
    QObject *t_cell = root_->findChild<QObject*>(QString("t_")+cell_name);
    //needs err handle here
    if (t_cell == NULL)
        return;

    t_cell->setProperty("color", "red");

}

void Game::startAction()
{
    desk_->clear();
    desk_->fillDefault();

    drawCurState();
}

void Game::stopAction()
{
    desk_->clear();
    drawCurState();
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

void Game::drawCurState()
{
    for (size_t row=0; row<8; row++) {
        for (size_t col=0; col<8; col++) {
            QObject *t_cell = root_->findChild<QObject*>(QString("t_cell")+QString::number(row+1)+QString::number(col+1));
            //needs err handle here
            if (t_cell == NULL)
                continue;

            Figure *item = desk_->getFigure(Desk::Cell(row,col));
            if (item == NULL) {
                t_cell->setProperty("text", "");
                continue;
            }

            t_cell->setProperty("text", item->getFigName());
            t_cell->setProperty("color", item->getFigColor());
        }
    }
}
