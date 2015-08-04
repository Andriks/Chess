#include "game.h"
#include "desk.h"

#include <QFile>
#include <QTextStream>
#include <QVariant>

Game::Game(QObject *parent) :
    root_(parent),
    desk_(NULL),
    state_(NULL)
{
    desk_ = new Desk(this);
    state_ = StateOnStart::Instance();
}

//////////////////////////////////////////////////////////////////////////////////

void Game::cellAction(QString str)
{
    state_->cellAction(this, str);
}

void Game::startAction()
{
    state_->startAction(this);
}

void Game::stopAction()
{
    state_->stopAction(this);
}

void Game::saveAction(QString str)
{
    state_->saveAction(this, str);
}

bool Game::loadAction(QString str)
{
    return state_->loadAction(this, str);
}

void Game::rollback_from_list()
{
    state_->rollback_from_list(this);
}

void Game::make_move_from_list()
{
    state_->make_move_from_list(this);
}

//////////////////////////////////////////////////////////////////////////////////

void Game::cellAction_impl(QString cell_name)
{
    Cell cell;
    try {
        cell = parseQMLCellName(cell_name);
    } catch (const ChessEx &ex) {
        return;
    }

    QPointer<QObject> t_cell = root_->findChild<QObject*>("t_"+cell_name);
    if (t_cell.isNull()) {
        return;
    }

    if (!desk_->haveActiveFigure()) {
        if (!desk_->grabFigure(cell))
            return;

        t_cell->setProperty("color", "red");

    } else {
        if (desk_->putDownFigure(cell))
            drawCurState();
        else
            interruptAction();
    }
}

void Game::startAction_impl()
{
    delete desk_;
    desk_ = new Desk(this);

    drawCurState();
}

void Game::stopAction_impl()
{
    interruptAction();

    delete desk_;
    desk_ = new Desk(this);

    //clearing all figures on gui to have pure desk
    for (size_t row=0; row<Desk::getMaxCnt(); row++) {
        for (size_t col=0; col<Desk::getMaxCnt(); col++) {
            QObject *t_cell = root_->findChild<QObject*>("t_cell"+QString::number(row+1)+QString::number(col+1));
            t_cell->setProperty("text", "");
        }
    }
}

void Game::saveAction_impl(QString file_url)
{
    interruptAction();

    const QVector<Command> &executed_commands_ = desk_->getState();

    file_url.remove("file:///");
    QFile file(file_url);

    if (!file.open(QFile::WriteOnly|QFile::Truncate))
        return;

    QTextStream outstream(&file);

    for (QVector<Command>::const_iterator it=executed_commands_.begin();
                                      it!=executed_commands_.end();
                                      it++)
    {
        outstream << it->getAsString() << "\n";
    }

    file.close();
}

bool Game::loadAction_impl(QString file_url)
{
    file_url.remove("file:///");
    QFile file(file_url);

    if (!file.open(QFile::ReadOnly))
        return false;

    QVector<Command> comm_list;

    while (!file.atEnd()) {
        QString line =  file.readLine();
        Command comm;
        if (!comm.setFromString(line)) {
            // bad input file, releasing of resources and breaking operation
            file.close();

            return false;
        }

        comm_list.push_back(comm);
    }

    QPointer<Desk> new_desk = new Desk(this);
    try {
        new_desk->restoreState(comm_list);
    } catch(const ChessEx &ex) {
        file.close();
        return false;
    }

    file.close();

    //if everething was nice
    delete desk_;
    desk_ = new_desk;

    drawCurState();

    return true;
}

void Game::rollback_from_list_impl()
{
    desk_->rollback_from_list();
    drawCurState();
}

void Game::make_move_from_list_impl()
{
    desk_->make_move_from_list();
    drawCurState();
}

void Game::ChangeState(State *state)
{
    state_ = state;
}

//////////////////////////////////////////////////////////////////////////////////

Cell Game::parseQMLCellName(QString name)
{
    if (!name.contains(QRegExp("cell[1-8][1-8]")))
        throw ChessEx();


    QString tmp = name.remove("cell");
    int row = QString(tmp[0]).toInt()-1;
    int col = QString(tmp[1]).toInt()-1;

    return Cell(row,col);
}

QString Game::colorForGUI(const FigColor &color)
{
    if (color == WHITE)
        return "blue";
    else if (color == BLACK)
        return "black";
    else
        return "";
}

void Game::drawCurState()
{
    for (size_t row=0; row<Desk::getMaxCnt(); row++) {
        for (size_t col=0; col<Desk::getMaxCnt(); col++) {
            drawCell(Cell(row, col));
        }
    }
}

void Game::drawCell(const Cell &cell)
{
    QPointer<QObject> t_cell = root_->findChild<QObject*>("t_cell"+QString::number(cell.row_+1)+QString::number(cell.col_+1));

    if (t_cell.isNull())
        return;

    QPointer<Figure> item = desk_->getFigure(cell);
    if (item.isNull()) {
        t_cell->setProperty("text", "");
        return;
    }

    t_cell->setProperty("text", item->getFigName());
    t_cell->setProperty("color", colorForGUI(item->getColor()));
}

void Game::interruptAction()
{
    desk_->interruptCommand();
    drawCurState();
}
