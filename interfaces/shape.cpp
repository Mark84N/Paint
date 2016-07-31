#include "shape.h"

Shape::Shape()
    :_start(QPoint()),
     _end(QPoint())
{ /* empty */ }

void Shape::setStartPosition(const QPoint &start)
{
    _start = start;
}
void Shape::setEndPosition(const QPoint &end)
{
    _end = end;
}

/*  Start and end points for shapes should match unless
 *  the mouse is moved (moving mouse with pressed left key gives form to the figure)
 */
void Shape::startDerivation(const QPoint &start)
{
    setStartPosition(start);
    setEndPosition(start);
}

void Shape::endDerivation(const QPoint &start)
{
    setEndPosition(start);
}
