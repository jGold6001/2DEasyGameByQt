#include "using_libs.h"
#include "Enemy.h"
#include "Game.h"

extern Game * game;

Enemy::Enemy(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    //set random position
    int random_number = rand() % 700;
    setPos(random_number,0);

    //draw the enemyCar
    setPixmap(QPixmap(":/images/images/car2.png"));
    setTransformOriginPoint(60,50);//устанавливает отступы обьекта от края окна программы
    setRotation(180);//разворот изображения

    //connect
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));

    timer->start(50);
}


void Enemy::move(){
    //move enemy down
    setPos(x(),y()+5);


    if(pos().y() > 600){

        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }
}
