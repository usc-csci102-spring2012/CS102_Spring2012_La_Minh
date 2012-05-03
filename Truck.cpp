#include "Truck.h"
#include <iostream>
Truck::Truck():Vehicle()
{
  xdir = 4; // how far it moves for each time out
  ydir = 0;
  image.load(":/icons/images/Truck.png");//loads image

  rect = image.rect();
   rect.setWidth(200);//sets the dimensions
   rect.setHeight(100);

}

Truck::Truck(int xSpeed, int ySpeed):Vehicle(xSpeed,ySpeed){
    image.load(":/icons/images/Truck.png");//loads image

    rect = image.rect();
    rect.setWidth(200);//sets the dimensions
    rect.setHeight(100);
}

Truck::~Truck() {//destructor.
}


void Truck::autoMove()//move to the right
{
  //for (int i=1; i<=xdir; i++)
 	 rect.translate(xdir, ydir);

  if (rect.left() >= 400) {
    rect.translate(-560,ydir);
  }

}
