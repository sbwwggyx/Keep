#include "hall.h"

Hall::Hall(QWidget *parent,int x,int y,int width,int height,QGraphicsScene *scene) : QWidget(parent)
{
    hallscene=scene;
    pixmap=new QGraphicsPixmapItem(QPixmap(":/res/2.png"));
    hallscene->addItem(pixmap);
    pixmap->moveBy(200,200);
}
Hall::~Hall(){

}
