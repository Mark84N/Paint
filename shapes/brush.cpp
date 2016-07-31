#include "brush.h"

Brush::Brush()
    :_points()
{ /* empty */ }


/* Drawing raw points entails a kind of broken lines,
 * it is better to connect them with micro-lines for smooth look */
void Brush::draw(QPainter *painter)
{
    painter->setPen(QPen(getFrameColor(), getFrameWidth(),
                         Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));

    /* Case: user wants to draw single point */
    if (_points.size() == 1)
    {
        painter->drawPoint(_points[0]);
    }
    /* Case: arbitrary line, that was drawn with mouse */
    else
    {
        for(int i = 0; i < _points.size() - 1; i++)
        {
            painter->drawLine(_points[i], _points[i+1]);
        }
    }
}
void Brush::startDerivation(const QPoint &start)
{
   _points.push_back(start);
}

void Brush::endDerivation(const QPoint &start)
{
    _points.push_back(start);
}
