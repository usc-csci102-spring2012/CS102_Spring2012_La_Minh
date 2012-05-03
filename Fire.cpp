#include "Fire.h"
#include <iostream>
Fire::Fire()
{
  image.load(":/icons/images/Fire.png");//loads image from file.

  rect = image.rect();
   rect.setWidth(60);//sets the dimensions of the Fire
   rect.setHeight(40);

}


Fire::~Fire() {//destructor.
}

