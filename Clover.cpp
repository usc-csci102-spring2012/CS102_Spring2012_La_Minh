#include "Clover.h"
Clover::Clover()
{
  image.load(":/icons/images/Clover.jpg");//loads image

  rect = image.rect();
   rect.setWidth(40);//sets the dimensions of clover
   rect.setHeight(40);

}

Clover::~Clover() {//destructor.
}

void Clover::movePositioning(int xcoordinate, int ycoordinate)//moves the var to this X and Y coordinate in the window.
{
   rect.moveTo(xcoordinate,ycoordinate);
}

QRect Clover::getRect()//returns the rectangle type.
{
  return rect;
}

QImage & Clover::getImage()//sets the image as the rectangle.
{
  return image;
}


