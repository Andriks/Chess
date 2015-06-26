#include "desk.h"
#include "figure.h"

Desk::Desk(QObject *parent) :
    QObject(parent),
    owner_(parent)
{
    //filling desk by empty ptr on base items
    for (int i=0; i<8; i++) {
        std::vector<QObject*> row;
        buffer_.push_back(row);     //it will copy row to buffer_ (now mamory leek [?])

        for (int j=0; j<8; j++) {
            //row.push_back(new Figure(this));
            row.push_back(NULL);
        }
    }
}

void Desk::fillDefault()
{

}
