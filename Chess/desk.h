#ifndef DESK_H
#define DESK_H

#include <QObject>
#include <vector>

class Desk : public QObject
{
    Q_OBJECT
public:
    explicit Desk(QObject *parent = 0);

    void fillDefault();

signals:

public slots:

private:
    QObject *owner_;    //ptr to desk owner (Game instance)
    std::vector< std::vector<QObject*> > buffer_;

};

#endif // DESK_H
