#include "Car.h"
#include <iostream>
Car::Car()
{
  xdir = -2;//how far it moves for each time out
  ydir = 0;
  image.load(":/icons/images/Car.jpg");//loads image from file.

  rect = image.rect();
   rect.setWidth(60);//sets the dimensions of the car
   rect.setHeight(40);

}

Car::Car(int xSpeed, int ySpeed):Vehicle(xSpeed,ySpeed){
    image.load(":/icons/images/Car.jpg");//loads image from file.

    rect = image.rect();
    rect.setWidth(60);//sets the dimensions of the car
    rect.setHeight(40);
}

Car::~Car() {//destructor.
}


void Car::autoMove()//moves to the left
{
//for (int i=1; i<=xdir; i++)
 	 rect.translate(xdir, ydir);

  if (rect.right() <= 0) {
    rect.translate(460,ydir);
  }

}
