#include "PowerUp.h"
#include <iostream>
PowerUp::PowerUp()
{
}


PowerUp::~PowerUp() {//destructor.
}

QRect PowerUp::getRect()//returns the rectangle type.
{
  return rect;
}

QImage & PowerUp::getImage()//sets the image as the rectangle.
{
  return image;
}


void PowerUp::movePositioning(int xcoordinate, int ycoordinate)//moves the var to this X and Y coordinate in the window.
{
   rect.moveTo(xcoordinate,ycoordinate);
}
