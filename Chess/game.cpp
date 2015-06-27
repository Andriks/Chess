#include "game.h"
#include <qfiledialog.h>
#include <QVariant>

Game::Game(QObject *parent) :
    root_(parent),
    desk_(NULL),
    command_(NULL)
{
    desk_ = new Desk(this);
}

Desk::Cell Game::parseQMLCellName(QString name)
{
    //needs err handle here
    if (!name.contains(QRegExp("cell[1-8][1-8]")))
        return Desk::Cell(-1,-1);


    QString tmp = name.remove("cell");
    int row = QString(tmp[0]).toInt()-1;
    int col = QString(tmp[1]).toInt()-1;

    return Desk::Cell(row,col);
}

void Game::cellAction(QString cell_name)
{
    Desk::Cell cell = parseQMLCellName(cell_name);
    //bad input
    if (cell == Desk::Cell(-1,-1)) {
        interruptCommand();
        return;
    }

    QObject *t_cell = root_->findChild<QObject*>(QString("t_")+cell_name);
    //needs err handle here
    if (t_cell == NULL) {
        interruptCommand();
        return;
    }

    if (command_ == NULL) {
        Figure *fig = desk_->getFigure(cell);
        if (fig == NULL)
            return;

        t_cell->setProperty("color", "red");

        command_ = new Command(this);
        command_->set_b_info(cell, fig);
    } else {
        Figure *fig = desk_->getFigure(cell);
        command_->set_e_info(cell, fig);

        if (command_->valid()) {
            command_->exec();


        } else {

            interruptCommand();
        }
    }
}

void Game::startAction()
{
    interruptCommand();
    desk_->clear();
    desk_->fillDefault();

    drawCurState();
}

void Game::stopAction()
{
    interruptCommand();
    desk_->clear();
    drawCurState();
}

void Game::saveAction()
{
    interruptCommand();
}

void Game::loadAction()
{
    interruptCommand();
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

void Game::interruptCommand()
{
    if (command_ != NULL) {
        Desk::CellInfo info = command_->get_b_info();
        QString row = QString::number(info.cell_.row_+1);
        QString col = QString::number(info.cell_.col_+1);
        QObject *prev_t_cell = root_->findChild<QObject*>(QString("t_cell")+row+col);
        prev_t_cell->setProperty("color", command_->getCurFig()->getFigColor());

        delete command_;
        command_ = NULL;
    }
}
