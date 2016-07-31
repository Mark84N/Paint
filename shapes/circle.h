#pragma once

#include "interfaces/shape.h"

class Circle : public Shape
{
public:

    Circle() = default;
    ~Circle() = default;

    void draw(QPainter *painter)override;
};
