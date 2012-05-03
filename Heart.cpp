#include "Heart.h"
#include <iostream>
Heart::Heart()
{
  image.load(":/icons/images/Heart.gif");//loads image from file.

  rect = image.rect();
   rect.setWidth(20);//sets the dimensions of the Heart
   rect.setHeight(20);

}


Heart::~Heart() {//destructor.
}

