#ifndef FIGURE_H
#define FIGURE_H

#include <QObject>

class Figure : public QObject
{
    Q_OBJECT
public:
    explicit Figure(QObject *parent = 0);

signals:

public slots:

private:
    QObject *owner_;    //ptr to figure owner (Desk instance)

};

#endif // FIGURE_H
