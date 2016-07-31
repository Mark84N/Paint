/*
 *  Program entities (Brush, Line, Circle, Rectangle) inherit features of this class,
 *  as they use same fields for correct drawing. Feel free to inherit Shape and implement
 *  own custom drawable class. Don't forget to implement method draw() from IDrawable!
 *
 */

#pragma once

#include <QPen>
#include <QPoint>

#include "idrawable.h"

class Shape : public IDrawable
{
public:

    Shape();
    virtual ~Shape() = default;

    virtual void setStartPosition(const QPoint &start);
    virtual void setEndPosition(const QPoint &end);

    virtual void startDerivation(const QPoint &start)override;
    virtual void endDerivation(const QPoint &start)override;

protected:

    QPoint _start;
    QPoint _end;
};
