#pragma once

#include "interfaces/shape.h"

class Rectangle : public Shape
{
public:

    Rectangle() = default;
    ~Rectangle() = default;

    void draw(QPainter *painter)override;
};
