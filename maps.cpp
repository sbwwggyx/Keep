#include "maps.h"
#include "begindialog.h"
Maps::Maps(QWidget *parent) :
    QWidget(parent)
{
    selected=false;
    easy=false;
    difficult=false;
    scene=new QGraphicsScene(this);
    scene->setSceneRect(0,0,1024,768);

    view=new QGraphicsView(this);

//**********************************************************************************************
    st=new BeginDialog(this);
    st->resize(1024,768);
    st->move(0,0);
    st->show();
    connect(st,SIGNAL(exit()),this,SLOT(exit()));
    connect(st,SIGNAL(ok()),this,SLOT(setNoDifficulty()));
    connect(st,SIGNAL(veryEasy()),this,SLOT(setNoDifficulty()));
    connect(st,SIGNAL(normal()),this,SLOT(setNormal()));
    connect(st,SIGNAL(veryHard()),this,SLOT(setHard()));
//************************************************************************Choose The Difficulty

//*********************************************************************************************
    scene->addPixmap(QPixmap(":/res/bgc.png"));
    lifebox=new QGraphicsRectItem (20,20,200,20);
    lifebox->setBrush(QBrush(Qt::blue));

    scene->addItem(lifebox);
    checkLifeTimer=new QTimer(this);

//    QGraphicsTextItem::setDefaultTextColor()

//*****************************************************************************Create the Scene


//*********************************************************************************************
    hall=new Hall(this,200,200,100,100,scene);

//******************************************************************************Create the Hall


//*********************************************************************************************
    monster=new Monster(this,100,100,1024,768,2,true,false,scene);

//**************************************************************************Create the Monsters

//*********************************************************************************************
    view->resize(1024,768);
    view->setFixedSize(1024,768);
    view->setMinimumSize(1024,768);
    view->setMaximumSize(1024,768);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setScene(scene);
    view->setCursor(Qt::CrossCursor);
    view->show();
//*****************************************************************Game Page Set Scene and View
}
void Maps::createHall(){


}
void Maps::createMonster(){

}
void Maps::mousePressEvent(QMouseEvent *event){
    if(selected){
        player->pixmap->setFocus();
        if(event->button()==Qt::LeftButton){
            att=new Weapon(this,player->xP+25,player->yP+25,event->x(),event->y(),10,scene);
            player->life-=100;
            qDebug()<<"Life"<<player->life;
            event->accept();
        }
        else if(event->button()==Qt::RightButton){
            event->accept();
            player->life+=100;
            //防御函数
        }
        else{
            event->ignore();
        }

    }
    else {
        event->ignore();
    }

    qDebug()<<"Mouse Press "<<scene->focusItem();
}
void Maps::mouseReleaseEvent(QMouseEvent *event){
    if(selected){
       player->pixmap->setFocus();
    }
    else{
        event->ignore();
    }
    qDebug()<<"Mouse Release "<<scene->focusItem();
}
void Maps::keyPressEvent(QKeyEvent *event){
    if(selected){
        qDebug()<<"key Press "<<scene->focusItem();
        qDebug()<<"Key Pressed";
        switch(event->key()){
            case 65:
                player->a=true;
                event->accept();
                qDebug()<<"Key:"<<event->key();
                break;
            case 87:
                player->w=true;
                event->accept();
                qDebug()<<"Key:"<<event->key();
                break;
            case 68:
                player->d=true;
                event->accept();
                qDebug()<<"Key:"<<event->key();
                break;
            case 83:
                player->s=true;
                event->accept();
                qDebug()<<"Key:"<<event->key();
                break;
            case Qt::Key_Space:
                player->rush();
            break;
            default:
                event->ignore();
                break;
            }
    }
    else{
        event->ignore();
    }

}
void Maps::keyReleaseEvent(QKeyEvent *event){
    if(selected){
        qDebug()<<"Mouse Release "<<scene->focusItem();
        switch(event->key()){
            case 65:
                player->a=false;
                event->accept();
                break;
            case 87:
                player->w=false;
                event->accept();
                break;
            case 68:
                player->d=false;
                event->accept();
                break;
            case 83:
                player->s=false;
                event->accept();
                break;
            default:
                event->ignore();
                break;
            }
    }
    else{
        event->ignore();
    }
}
//*********************************************************************************************
Maps::~Maps()
{

}

void Maps::exit(){
    this->close();
}
//*********************************************************************************************

void Maps::setNoDifficulty(){
    selected=true;
    easy=true;
    difficult=false;
    qDebug()<<"Easy";
    startCreatePlayer();
    qDebug()<<"START";
}
void Maps::setNormal(){
    selected=true;
    easy=true;
    difficult=true;
    qDebug()<<"Normal";
    startCreatePlayer();
    qDebug()<<"START";
}
void Maps::setHard(){
    selected=true;
    easy=false;
    difficult=true;
    qDebug()<<"Hard";
    startCreatePlayer();
    qDebug()<<"START";
}

//***************************************************************************Set the Difficulty


//*********************************************************************************************

void Maps::startCreatePlayer(){
    qDebug()<<"ConstructedFunction";
    player=new Player(this,scene);
    qDebug()<<"The Player Constructed";
    life=new QGraphicsRectItem(20,20,player->life/5,20);
    if(player->life>=700){
        QBrush lifeGreen(Qt::green);
       this->life->setBrush(lifeGreen);
    }
    if(player->life>400&&player->life<700){
        QBrush lifeYellow(Qt::yellow);
        this->life->setBrush(lifeYellow);
    }
    if(player->life<=400&&player->life>200){
        QBrush lifeOrange(QColor(225,158,53));
        this->life->setBrush(lifeOrange);
    }
    if(player->life<=200){
        QBrush lifeRed(Qt::red);
        this->life->setBrush(lifeRed);
    }
    textLife=new QGraphicsTextItem("Life");
    scene->addItem(life);
    checkLifeTimer->start(100);
    connect(checkLifeTimer,SIGNAL(timeout()),this,SLOT(checkLife()));
}
void Maps::checkLife(){
    delete life;
    delete textLife;
    life=new QGraphicsRectItem(20,20,player->life/5,20);

    if(player->life>=700){
        QBrush lifeGreen(Qt::green);
       this->life->setBrush(lifeGreen);
    }
    if(player->life>400&&player->life<700){
        QBrush lifeYellow(Qt::yellow);
        this->life->setBrush(lifeYellow);
    }
    if(player->life<=400&&player->life>200){
        QBrush lifeOrange(QColor(225,158,53));
        this->life->setBrush(lifeOrange);
    }
    if(player->life<=200){
        QBrush lifeRed(Qt::red);
        this->life->setBrush(lifeRed);
    }
    textLife=new QGraphicsTextItem("Life");
    textLife->moveBy(100,20);
    textLife->setHtml("<h2><font color=red size=2>Life</font></h2>");
    scene->addItem(life);
    scene->addItem(textLife);
}
//****************************************************************************Create the Player
//2019.07.03 05:36
