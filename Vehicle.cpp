#include "Vehicle.h"
#include <iostream>
Vehicle::Vehicle()
{
    xdir = 0; // how far it moves for each time out
    ydir = 0;
}

Vehicle::Vehicle(int xSpeed,int ySpeed){
    xdir = xSpeed;
    ydir = ySpeed;
}

Vehicle::~Vehicle() {//destructor.
}

void Vehicle::movePositioning(int xcoordinate, int ycoordinate)//moves the var to this X and Y coordinate in the window.
{
   rect.moveTo(xcoordinate,ycoordinate);
}

void Vehicle::moveBottom(int bottom)//move one step down.
{
  rect.moveBottom(bottom);
}

void Vehicle::moveTop(int top)//move one step up.
{
  rect.moveTop(top);
}

void Vehicle::moveLeft(int left)//move one step to left.
{
  rect.moveLeft(left);
}

void Vehicle::moveRight(int right)//move to right.
{
  rect.moveRight(right);
}




QRect Vehicle::getRect()//returns the rectangle type.
{
  return rect;
}

QImage & Vehicle::getImage()//sets the image as the rectangle.
{
  return image;
}
/*
void Vehicle::autoMove(){
      rect.translate(xdir, ydir);
}
*/
