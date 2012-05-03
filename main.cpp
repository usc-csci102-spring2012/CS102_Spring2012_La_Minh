#include "Game.h"
#include <QDesktopWidget>
#include <QIcon>
#include <QApplication>
void center(QWidget &widget)//The window is created.
{

  int x, y;
  int screenWidth;
  int screenHeight;

  int WIDTH = 400;//Dimensions of the window.
  int HEIGHT = 400;
  

  QDesktopWidget *desktop = QApplication::desktop();

  screenWidth = desktop->width();
  screenHeight = desktop->height();
 
  x = (screenWidth - WIDTH) / 2;
  y = (screenHeight - HEIGHT) / 2;

  widget.setGeometry(x, y, WIDTH, HEIGHT);//screen being set.
  widget.setFixedSize(WIDTH, HEIGHT);
}


int main(int argc, char *argv[])
{
  QApplication app(argc, argv);  
    
  Game window;//create an instance of the game
  
  window.setWindowTitle("Frogger");//display gamename
  window.show();//show the game
  center(window);

  return app.exec();
}
