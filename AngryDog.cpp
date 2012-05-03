#include "AngryDog.h"
#include <iostream>
AngryDog::AngryDog()
{
  xdir = 20;//how far it moves for each time out
  ydir = 20;

  rect = image.rect();
   rect.setWidth(60);//sets the dimensions of the Dog
   rect.setHeight(4);

}

AngryDog::AngryDog(int xSpeed)
{
  xdir = xSpeed;//how far it moves for each time out
  ydir = xSpeed;
  rect = image.rect();
   rect.setWidth(60);//sets the dimensions of the Dog
   rect.setHeight(40);

}

AngryDog::~AngryDog() {//destructor.
}


void AngryDog::autoMove()//moves to the left
{
    if (xdir > 0){
        image.load(":/icons/images/Dog_Right.png");
    }
    else if(xdir < 0){
        image.load(":/icons/images/Dog_Left.png");
    }
    rect.translate(xdir, ydir);
}
