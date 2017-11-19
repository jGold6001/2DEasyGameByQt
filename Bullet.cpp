#include "using_libs.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Game.h"


extern Game * game; //there is an external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw the bullet(оратить пулю)
    setPixmap(QPixmap(":/images/images/laser.png"));

    // make/connect a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    //start the timer
    timer->start(50);
}

void Bullet::move(){

    //get a list of all the items currently colliding with this bullet
    QList <QGraphicsItem *> colliding_items =collidingItems();

    //if one of the colliding items is a Enemy, destroy both the bullet and the enemy
    for(int i=0; i<colliding_items.size(); ++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){//если столкновение ровно Пуле то оно удаляется

            //increase the score
            game->score->increase();

            //images explosion



            //remove them from the scene (still on the heap)
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);



            //sound effect boom
            QMediaPlayer * boom = new QMediaPlayer();
            boom->setMedia(QUrl("qrc:/sounds/sounds/boom.mp3"));
            boom->setVolume(40);
            boom->play();

            //delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    //if there was no collision with an Enemy, move the bullet forward
    setPos(x(), y()-40);


    //if the bullet is off the screen, destroy it
    if(pos().y() <0){
        scene()->removeItem(this);
        delete this;
    }
}
