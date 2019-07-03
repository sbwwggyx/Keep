#ifndef HALL_H
#define HALL_H

#include "head.h"
#include <QObject>

class Hall : public QWidget
{
    Q_OBJECT
public:
    explicit Hall(QWidget *parent = nullptr,int x=1024,int y=768,int width=0,int height=0,QGraphicsScene *scene=nullptr);
    ~Hall();
    int hallWidth;
    int hallHeight;
    QGraphicsScene *hallscene;
    QGraphicsPixmapItem *pixmap;
signals:

public slots:
};

#endif // HALL_H
