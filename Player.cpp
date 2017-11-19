#include "using_libs.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"


Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/sounds/laser.wav"));

    //set image of Player
    setPixmap(QPixmap(":/images/images/car1.png"));

}

void Player::keyPressEvent(QKeyEvent *event){

    //move the player left and right
    if(event->key()==Qt::Key_Left){
        if(pos().x()>0)//что бы не вышел за линию
          setPos(x()-70, y());
       }

    else if(event->key()==Qt::Key_Right){
        if(pos().x()<700) //что бы не вышел за линию
           setPos(x()+70, y());
    }

    //shoot with the spacebar(пробел)
    else if(event->key() ==Qt::Key_Space){

        //create a bullet
        Bullet *bullet1 =new Bullet();
        Bullet *bullet2 =new Bullet();
        bullet1->setPos(x()-15, y()-50);
        bullet2->setPos(x()+55, y()-50);
        scene()->addItem(bullet1);
        scene()->addItem(bullet2);

        //play bulletsound
        if(bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state() == QMediaPlayer::StoppedState){
               bulletsound->setVolume(30);
               bulletsound->play();
        }
    }
}

void Player::spawn(){
    //create an enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);

}
