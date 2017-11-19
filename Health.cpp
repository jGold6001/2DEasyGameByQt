#include "using_libs.h"
#include "Health.h"

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // initialize the score to 0
    health = 3;

    // draw the text
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Health::decrease(){
    health--;
    setPlainText(QString("Health: ") + QString::number(health)); // Health: 2

    //sound damage
    QMediaPlayer * decHealth = new QMediaPlayer();
    decHealth->setMedia(QUrl("qrc:/sounds/sounds/damage.wav"));
    decHealth->setVolume(20);
    decHealth->play();
}

int Health::getHealth(){
    return health;
}

