#pragma once

#include "interfaces/shape.h"

class Line : public Shape
{
public:

    Line() = default;
    ~Line() = default;

    void draw(QPainter *painter)override;
};
