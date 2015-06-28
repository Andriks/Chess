#include "game.h"
#include "desk.h"
#include "command.h"

#include <QFileDialog>
#include <QVariant>

Game::Game(QObject *parent) :
    root_(parent),
    desk_(NULL),
    command_(NULL)
{
    desk_ = new Desk(this);
}

Cell Game::parseQMLCellName(QString name)
{
    //needs err handle here
    if (!name.contains(QRegExp("cell[1-8][1-8]")))
        return Cell(-1,-1);


    QString tmp = name.remove("cell");
    int row = QString(tmp[0]).toInt()-1;
    int col = QString(tmp[1]).toInt()-1;

    return Cell(row,col);
}

void Game::cellAction(QString cell_name)
{
    Cell cell = parseQMLCellName(cell_name);
    //bad input
    if (cell == Cell(-1,-1)) {
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
        if (desk_->getFigure(cell) == NULL)
            return;


        t_cell->setProperty("color", "red");

        command_ = new Command(this, desk_);
        command_->set_b_info(cell);
    } else {
        command_->set_e_info(cell);

        if (command_->valid()) {
            command_->exec();
            drawCommand();
            // add to command list (for saving)

            delete command_;
            command_ = NULL;

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

void Game::tmpDraw()
{
    interruptCommand();
    drawCurState();
}

void Game::drawCurState()
{
    for (size_t row=0; row<8; row++) {
        for (size_t col=0; col<8; col++) {
            QObject *t_cell = root_->findChild<QObject*>(QString("t_cell")+QString::number(row+1)+QString::number(col+1));
            //needs err handle here
            if (t_cell == NULL)
                continue;

            Figure *item = desk_->getFigure(Cell(row,col));
            if (item == NULL) {
                t_cell->setProperty("text", "");
                continue;
            }

            t_cell->setProperty("text", item->getFigName());
            t_cell->setProperty("color", item->getFigColor());
        }
    }
}

void Game::drawCommand()
{
    //removing item from privious cell
    CellInfo b_info = command_->get_b_info();
    QString b_row = QString::number(b_info.cell_.row_+1);
    QString b_col = QString::number(b_info.cell_.col_+1);
    QObject *b_t_cell = root_->findChild<QObject*>(QString("t_cell")+b_row+b_col);
    b_t_cell->setProperty("text", "");

    //drawing this item on new cell
    CellInfo e_info = command_->get_e_info();
    QString e_row = QString::number(e_info.cell_.row_+1);
    QString e_col = QString::number(e_info.cell_.col_+1);
    QObject *e_t_cell = root_->findChild<QObject*>(QString("t_cell")+e_row+e_col);
    e_t_cell->setProperty("text", command_->getCurFig()->getFigName());
    e_t_cell->setProperty("color", command_->getCurFig()->getFigColor());
}

void Game::interruptCommand()
{
    if (command_ != NULL) {
        CellInfo info = command_->get_b_info();
        QString row = QString::number(info.cell_.row_+1);
        QString col = QString::number(info.cell_.col_+1);
        QObject *prev_t_cell = root_->findChild<QObject*>(QString("t_cell")+row+col);
        prev_t_cell->setProperty("color", command_->getCurFig()->getFigColor());

        delete command_;
        command_ = NULL;
    }
}
