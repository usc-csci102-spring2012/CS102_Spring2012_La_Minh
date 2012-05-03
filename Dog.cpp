#include "Dog.h"
#include <iostream>
Dog::Dog()
{
  xdir = -25;//how far it moves for each time out
  ydir = 0;
  image.load(":/icons/images/Dog_Left.png");//loads image from file.

  rect = image.rect();
   rect.setWidth(80);//sets the dimensions of the Dog
   rect.setHeight(38);

}

Dog::Dog(int xSpeed)
{
  xdir = xSpeed;//how far it moves for each time out
  ydir = 0;
  image.load(":/icons/images/Dog_Left.png");//loads image from file.

  rect = image.rect();
   rect.setWidth(80);//sets the dimensions of the Dog
   rect.setHeight(38);

}

Dog::~Dog() {//destructor.
}


void Dog::autoMove()//moves to the left
{
    if (rect.left() <= 0){
        xdir = -xdir;
        image.load(":/icons/images/Dog_Right.png");
        //rect = image.mirrored(true,false).rect();
        //rect.setWidth(40);rect.setHeight(20);
    }
    else if(rect.right() > 400){
        xdir = -xdir;
        image.load(":/icons/images/Dog_Left.png");
        //rect = image.mirrored(true,false).rect();
        //rect.setWidth(40);rect.setHeight(20);
    }
     rect.translate(xdir, ydir);


}
