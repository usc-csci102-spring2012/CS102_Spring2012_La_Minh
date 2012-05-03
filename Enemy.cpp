#include "Enemy.h"
#include <iostream>
Enemy::Enemy()
{
    xdir = 1; // how far it moves for each time out
    ydir = 0;
}


Enemy::~Enemy() {//destructor.
}

void Enemy::movePositioning(int xcoordinate, int ycoordinate)//moves the var to this X and Y coordinate in the window.
{
   rect.moveTo(xcoordinate,ycoordinate);
}

void Enemy::moveBottom(int bottom)//move one step down.
{
  rect.moveBottom(bottom);
}

void Enemy::moveTop(int top)//move one step up.
{
  rect.moveTop(top);
}

void Enemy::moveLeft(int left)//move one step to left.
{
  rect.moveLeft(left);
}

void Enemy::moveRight(int right)//move to right.
{
  rect.moveRight(right);
}

QRect Enemy::getRect()//returns the rectangle type.
{
  return rect;
}

QImage & Enemy::getImage()//sets the image as the rectangle.
{
  return image;
}
