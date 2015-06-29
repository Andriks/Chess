#include "game.h"
#include "desk.h"
#include "command.h"

#include <QFile>
#include <QVariant>

Game::Game(QObject *parent) :
    root_(parent),
    desk_(NULL),
    color_to_move_(WHITE),
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

    QObject *t_cell = root_->findChild<QObject*>("t_"+cell_name);
    //needs err handle here
    if (t_cell == NULL) {
        interruptCommand();
        return;
    }

    if (command_ == NULL) {
        if (desk_->getFigure(cell) == NULL)
            return;

        if (desk_->getFigure(cell)->color() != color_to_move_)
            return;

        t_cell->setProperty("color", "red");

        command_ = new Command(desk_);
        command_->set_b_info(cell);
    } else {
        command_->set_e_info(cell);

        if (command_->valid()) {
            command_->exec();
            //executed_commands_.push_back(*command_);

            // switching active player for next move
             color_to_move_ = (color_to_move_== WHITE) ? BLACK : WHITE;

            drawCommand();

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

    delete desk_;
    desk_ = new Desk(this);

    desk_->fillDefault();
    drawCurState();
}

void Game::stopAction()
{
    interruptCommand();

    delete desk_;
    desk_ = new Desk(this);

    drawCurState();
}

void Game::saveAction(QString file_url)
{
    interruptCommand();
}

void Game::loadAction(QString file_url)
{
    interruptCommand();

    file_url.remove("file:///");

    QFile file(file_url);
    //needs err handle here
    if (!file.open(QFile::ReadOnly))
        return;

    Desk *desk = new Desk(this);
    desk->fillDefault();
    std::vector<Command> v_comm;

    while (!file.atEnd()) {
        QString line =  file.readLine();

    }


    file.close();
}

void Game::tmpDraw()
{
    interruptCommand();
    drawCurState();
}

void Game::rollback_from_list()
{
    interruptCommand();
    if (executed_commands_.size() > 0) {
        Command com = executed_commands_.back();
        executed_commands_.pop_back();

        com.set_desk(desk_);
        com.rollback();
    }
}

void Game::drawCurState()
{
    for (size_t row=0; row<8; row++) {
        for (size_t col=0; col<8; col++) {
            drawCell(Cell(row, col));
        }
    }
}

void Game::drawCommand()
{
    drawCell(command_->get_b_info().cell_);
    drawCell(command_->get_e_info().cell_);
}

void Game::drawCell(const Cell &cell)
{
    QObject *t_cell = root_->findChild<QObject*>("t_cell"+QString::number(cell.row_+1)+QString::number(cell.col_+1));
    //needs err handle here
    if (t_cell == NULL)
        return;

    Figure *item = desk_->getFigure(cell);
    if (item == NULL) {
        t_cell->setProperty("text", "");
        return;
    }

    t_cell->setProperty("text", item->getFigName());
    t_cell->setProperty("color", item->getFigColor());
}

void Game::interruptCommand()
{
    if (command_ != NULL) {
        CellInfo info = command_->get_b_info();
        QString row = QString::number(info.cell_.row_+1);
        QString col = QString::number(info.cell_.col_+1);
        QObject *prev_t_cell = root_->findChild<QObject*>(QString("t_cell")+row+col);
        prev_t_cell->setProperty("color", desk_->getFigure(info.cell_)->getFigColor());

        delete command_;
        command_ = NULL;
    }
}
