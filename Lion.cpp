#include "Lion.h"
#include <iostream>
Lion::Lion()
{
  xdir = -2;//how far it moves for each time out
  ydir = 2;
  image.load(":/icons/images/Lion.jpg");//loads image from file.

  rect = image.rect();
   rect.setWidth(40);//sets the dimensions of the Lion
   rect.setHeight(60);

}

Lion::~Lion() {//destructor.
}


void Lion::autoMove()//moves to the left
{
     rect.translate(xdir, ydir);


}
