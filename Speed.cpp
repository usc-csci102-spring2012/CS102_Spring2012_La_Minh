#include "Speed.h"
#include <iostream>
Speed::Speed()
{
  image.load(":/icons/images/Speed.jpg");//loads image from file.

  rect = image.rect();
   rect.setWidth(30);//sets the dimensions of the Speed
   rect.setHeight(30);

}


Speed::~Speed() {//destructor.
}

