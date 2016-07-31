/* Class provides ability of arbitrary mouse drawing */

#pragma once

#include <QVector>

#include "interfaces/shape.h"

class Brush : public IDrawable
{
public:

    Brush();
    ~Brush() = default;

    void draw(QPainter *painter)override;

    virtual void startDerivation(const QPoint &start)override;
    virtual void endDerivation(const QPoint &start)override;

private:

    QVector<QPoint> _points;
};
