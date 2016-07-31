#include "line.h"

void Line::draw(QPainter *painter)
{
    painter->setPen(QPen(getFrameColor(), getFrameWidth(),
                         Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    painter->drawLine(_start, _end);
}
