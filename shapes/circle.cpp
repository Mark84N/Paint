#include "circle.h"

void Circle::draw(QPainter *painter)
{

    painter->setPen(QPen(getFrameColor(), getFrameWidth(),
                         Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    QRect rect(_start, _end);

    painter->drawEllipse(rect);
}
