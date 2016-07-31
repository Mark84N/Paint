#include "rectangle.h"

void Rectangle::draw(QPainter *painter)
{
    QPen pen;
    pen.setColor(this->getFrameColor());
    pen.setWidth(this->getFrameWidth());

    painter->setPen(pen);

    QRect rect(_start, _end);
    painter->drawRect(rect);
}
