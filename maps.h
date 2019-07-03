#ifndef WIDGET_H
#define WIDGET_H
#include "head.h"
#include "begindialog.h"
#include <QWidget>
#include "player.h"
#include "weapon.h"
#include "monster.h"
#include "hall.h"

//namespace Ui {
//class Maps;
//}

class Maps : public QWidget
{
    Q_OBJECT

public:
    explicit Maps(QWidget *parent = nullptr);
    ~Maps();
    bool selected;
    bool easy;
    bool difficult;
    bool w,a,s,d,q,e,space;
    QTimer *createPlayer;
    QTimer *checkLifeTimer;
    Player *player;
    Weapon *att;
    Monster *monster;
    Hall *hall;

    QGraphicsScene *scene;
    QGraphicsView *view;
    QGraphicsRectItem *lifebox;
    QGraphicsRectItem *life;
    QGraphicsTextItem *textLife;
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
private slots:
    void createHall();
    void createMonster();
    void exit();
    void setNoDifficulty();
    void setNormal();
    void setHard();
    void startCreatePlayer();
    void checkLife();
private:
    BeginDialog *st;
//    Player *player;
//    Monster *monster;
//    QPushButton *btn;
//    Character *character;
//    Monster *monsters;
private:
};

#endif // WIDGET_H
