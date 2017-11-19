#include "using_libs.h"
#include "Game.h"
#include "Enemy.h"


Game::Game(QWidget * parent){

    //create the scene
    scene= new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);//make the scene 800x600 instead of infinity  by infinity (default)
    setBackgroundBrush(QBrush(QImage(":/images/images/bg.jpg")));


    //make the newly created scene the scene
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//убираем прокрутку горизонтал
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//убираем прокрутку по вертикале
    setFixedSize(800,600);//устанавливаем размер

    //create the player
    player = new Player();
    player->setPos(350,480);//TODO generalize to always be in the middle bottom of screen

    //make the player focusable and set it to be current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable);//местоположение игрока
    player->setFocus();

    //add the player to the screen
    scene->addItem(player);

    //create the score/health
    score = new Score();
    scene->addItem(score);

    health= new Health();
    health->setPos(health->x(), health->y()+25);//розмещаем его в окне
    scene->addItem(health);

    //spawn enemies
    QTimer *timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()),player, SLOT(spawn()));
    timer->start(2000);//1 second -  1000 millisecond

    //play bg music
    QMediaPlayer * music = new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/sounds/bg.mp3"));
    music->setVolume(30);
    music->play();


    show();//NotUnd
}


