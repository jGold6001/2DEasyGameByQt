#include "using_libs.h"
#include "Game.h"


Game * game;//global variable

int main(int argc, char *argv[]){
   QApplication a(argc, argv);

   game = new Game();
   game->show();


    return a.exec();
}
