#include "Slow.h"
#include <iostream>
Slow::Slow()
{
  image.load(":/icons/images/Slow.png");//loads image from file.

  rect = image.rect();
   rect.setWidth(30);//sets the dimensions of the Slow
   rect.setHeight(30);

}


Slow::~Slow() {//destructor.
}

