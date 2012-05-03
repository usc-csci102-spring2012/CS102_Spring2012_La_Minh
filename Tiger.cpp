#include "Tiger.h"
#include <iostream>
Tiger::Tiger()
{
  xdir = 25;//how far it moves for each time out
  ydir = 25;
  image.load(":/icons/images/Tiger.jpg");//loads image from file.

  rect = image.rect();
   rect.setWidth(40);//sets the dimensions of the Tiger
   rect.setHeight(60);

}

Tiger::~Tiger() {//destructor.
}


void Tiger::autoMove()//moves to the left
{
     rect.translate(xdir, ydir);


}
