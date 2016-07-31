#include "idrawable.h"

IDrawable::IDrawable()
    :_frameColor(QColor()),
     _frameWidth()
{
}

void IDrawable::setFrameColor(const QColor &val)
{
    _frameColor = val;
}

QColor IDrawable::getFrameColor() const
{
    return _frameColor;
}

void IDrawable::setFrameWidth(const int &val)
{
    _frameWidth = val;
}

int IDrawable::getFrameWidth() const
{
    return _frameWidth;
}
