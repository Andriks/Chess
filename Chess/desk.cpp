#include "desk.h"

bool Desk::defaultStateFilled_(false);
std::vector<Desk::CellInfo> Desk::defaultState_;

size_t Desk::max_row_cnt_(8);
size_t Desk::max_col_cnt_(8);

Desk::Desk(QObject *parent) :
    QObject(parent),
    owner_(parent)
{
    //filling desk by empty ptr on base items
    for (size_t x=0; x<max_row_cnt_; x++) {
        std::vector<Figure*> row;
        for (size_t y=0; y<max_row_cnt_; y++)
            row.push_back(NULL);

        buffer_.push_back(row);     //it will copy row to buffer_ (now mamory leek [?])
    }


    if (!defaultStateFilled_) {
        defaultState_.push_back(CellInfo( Cell(0,0), Figure::ROOK,   Figure::BLACK ));
        defaultState_.push_back(CellInfo( Cell(0,1), Figure::KNIGHT, Figure::BLACK ));
        defaultState_.push_back(CellInfo( Cell(0,2), Figure::BISHOP, Figure::BLACK ));
        defaultState_.push_back(CellInfo( Cell(0,3), Figure::QUEEN,  Figure::BLACK ));
        defaultState_.push_back(CellInfo( Cell(0,4), Figure::KING,   Figure::BLACK ));
        defaultState_.push_back(CellInfo( Cell(0,5), Figure::BISHOP, Figure::BLACK ));
        defaultState_.push_back(CellInfo( Cell(0,6), Figure::KNIGHT, Figure::BLACK ));
        defaultState_.push_back(CellInfo( Cell(0,7), Figure::ROOK,   Figure::BLACK ));
        for (int i=0; i<8; i++) {
            defaultState_.push_back(CellInfo( Cell(1,i), Figure::PAWN, Figure::BLACK ));
        }

        defaultState_.push_back(CellInfo( Cell(7,0), Figure::ROOK,   Figure::WHITE ));
        defaultState_.push_back(CellInfo( Cell(7,1), Figure::KNIGHT, Figure::WHITE ));
        defaultState_.push_back(CellInfo( Cell(7,2), Figure::BISHOP, Figure::WHITE ));
        defaultState_.push_back(CellInfo( Cell(7,3), Figure::QUEEN,  Figure::WHITE ));
        defaultState_.push_back(CellInfo( Cell(7,4), Figure::KING,   Figure::WHITE ));
        defaultState_.push_back(CellInfo( Cell(7,5), Figure::BISHOP, Figure::WHITE ));
        defaultState_.push_back(CellInfo( Cell(7,6), Figure::KNIGHT, Figure::WHITE ));
        defaultState_.push_back(CellInfo( Cell(7,7), Figure::ROOK,   Figure::WHITE ));
        for (int i=0; i<8; i++) {
            defaultState_.push_back(CellInfo( Cell(6,i), Figure::PAWN, Figure::WHITE ));
        }

        defaultStateFilled_ = true;
    }
}

void Desk::fillDefault()
{
    for (size_t i=0; i<defaultState_.size(); i++) {
        const CellInfo item = defaultState_[i];

        const size_t row = item.cell_.row_;
        const size_t col = item.cell_.col_;

        switch (item.ftype_) {
        case Figure::KING:
            buffer_[row][col] = new King(this, item.fcolor_);
            break;
        default:
            buffer_[row][col] = new Queen(this, item.fcolor_);
            break;
        }
    }


//    for (std::vector<CellInfo>::const_iterator it=defaultState_.begin(); it != defaultState_.end(); it++) {
//        const size_t x = it->cell_.x_;
//        const size_t y = it->cell_.y_;
//        switch (it->ftype_) {
//        case Figure::KING:
//            buffer_[x][y] = new King(this, it->fcolor_);
//            break;
//        default:
//            buffer_[x][y] = new Queen(this, it->fcolor_);
//            break;
//        }
//    }

}

void Desk::clear()
{
    for (size_t row=0; row<max_row_cnt_; row++) {
        for (size_t col=0; col<max_col_cnt_; col++) {
            if (buffer_[row][col] != NULL) {
                delete buffer_[row][col];
                buffer_[row][col] = NULL;
            }
        }
    }
}

Figure *Desk::getFigure(Desk::Cell inp_cell)
{
    if (inp_cell.row_ > (max_row_cnt_-1))
        return NULL;
    if (inp_cell.col_ > (max_col_cnt_-1))
        return NULL;

    return buffer_[inp_cell.row_][inp_cell.col_];
}
