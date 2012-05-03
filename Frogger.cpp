#include "Frogger.h"
#include <iostream>

Frogger::Frogger()//Constructor
{
  image.load(":/icons/images/Frogger.png");//sets the image of the frogger

  rect = image.rect();
    rect.setWidth(20);//sets the dimensions of the frogger
   rect.setHeight(20);
}

Frogger::~Frogger()//Destructor.
{
}

int Frogger::getHeight()//returns the height of the object.
{
  return rect.height();
}

int Frogger::getWidth()//returns the width of the object.
{
  return rect.width();
}


void Frogger::moveLeft(int left)//moves one space to the left.
{
  if (rect.left() >= 2)
    rect.moveTo(left, rect.top());
}

void Frogger::moveRight(int right)//moves one space to the right.
{
  if (rect.right() <= 398)
    rect.moveTo(right, rect.top());
}

void Frogger::moveTop(int top)//moves one space to the top.
{
  if (rect.top() >=32)
	rect.moveTo(rect.left(), top);
}

void Frogger::moveBottom(int bottom)//moves one space to the bottom.
{
  if(rect.bottom() <= 398)
	rect.moveTo(rect.left(), bottom);
}

void Frogger::resetState()//resets the position of the frogger.
{
  rect.moveTo(200, 360);
}

QRect Frogger::getRect() //returns the rect.
{
  return rect;
}

QImage & Frogger::getImage() //returns the image.
{
  return image;
}

void Frogger::movePositioning(int xcoordinate, int ycoordinate){
   rect.moveTo(xcoordinate,ycoordinate);
}
