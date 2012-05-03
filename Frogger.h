#ifndef FROGGER_H
#define FROGGER_H

#include <QImage>
#include <QRect>

class Frogger
{

  public:
    Frogger();
    ~Frogger();

  public:
    void resetState();
    void moveLeft(int);
    void moveRight(int);
    void moveTop(int);
    void moveBottom(int);
    int getWidth();
    int getHeight();
    QRect getRect();
    QImage & getImage();
    void movePositioning(int, int);

  private:
    QImage image;
    QRect rect;

};

#endif
