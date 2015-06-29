#include "desk.h"


const int Desk::max_row_cnt_(8);
const int Desk::max_col_cnt_(8);

Desk::Desk(QObject *parent) :
    QObject(parent)
{
    //filling desk by empty ptr on base items
    for (int row=0; row<max_row_cnt_; row++) {
        std::vector<Figure*> row_vec;
        for (int col=0; col<max_row_cnt_; col++)
            row_vec.push_back(NULL);

        buffer_.push_back(row_vec);     //it will copy row to buffer_ (now mamory leek [?])
    }


    FigColor fcolor = BLACK;
    buffer_[0][0] = new Rook(   this, fcolor);
    buffer_[0][1] = new Knight( this, fcolor);
    buffer_[0][2] = new Bishop( this, fcolor);
    buffer_[0][3] = new Queen(  this, fcolor);
    buffer_[0][4] = new King(   this, fcolor);
    buffer_[0][5] = new Bishop( this, fcolor);
    buffer_[0][6] = new Knight( this, fcolor);
    buffer_[0][7] = new Rook(   this, fcolor);
    for (int i=0; i<8; i++) {
        buffer_[1][i] = new Pawn(this, fcolor);
    }

    fcolor = WHITE;
    buffer_[7][0] = new Rook(   this, fcolor);
    buffer_[7][1] = new Knight( this, fcolor);
    buffer_[7][2] = new Bishop( this, fcolor);
    buffer_[7][3] = new Queen(  this, fcolor);
    buffer_[7][4] = new King(   this, fcolor);
    buffer_[7][5] = new Bishop( this, fcolor);
    buffer_[7][6] = new Knight( this, fcolor);
    buffer_[7][7] = new Rook(   this, fcolor);
    for (int i=0; i<8; i++) {
        buffer_[6][i] = new Pawn(this, fcolor);
    }


}

Figure *Desk::getFigure(const Cell &inp_cell) const
{
    if (!inRange(inp_cell))
        return NULL;

    return buffer_[inp_cell.row_][inp_cell.col_];
}

bool Desk::inRange(const Cell &cell) const
{
    if (cell.row_ < 0 || cell.col_ < 0)
        return false;

    if (cell.row_ > (max_row_cnt_-1) || cell.col_ > (max_col_cnt_-1))
        return false;

    return true;
}
