#include "drawassistant.h"

DrawAssistant::DrawAssistant()
    :_currentShapeId(ShapesId::BRUSH),
     _currentWidth(5),
     _currentColor(Qt::black),
     _currentShape(new Brush)
{
    _shapesList = {{ShapesId::BRUSH, [](){ return std::shared_ptr<IDrawable>(new Brush());}},
                  {ShapesId::CIRCLE, [](){ return std::shared_ptr<IDrawable>(new Circle());}},
                  {ShapesId::RECTANGLE, [](){ return std::shared_ptr<IDrawable>(new Rectangle());}},
                  {ShapesId::LINE, [](){ return std::shared_ptr<IDrawable>(new Line());}}};
}

DrawAssistant &DrawAssistant::getInstance()
{
    static DrawAssistant instance;

    return instance;
}

void DrawAssistant::setCurrentWidth(int val)
{
    _currentWidth = val;
}

int DrawAssistant::getCurrentWidth() const
{
    return _currentWidth;
}

void DrawAssistant::setCurrentColor(const QColor &color)
{
    _currentColor = color;
}

QColor DrawAssistant::getCurrentColor() const
{
    return _currentColor;
}

std::shared_ptr<IDrawable> DrawAssistant::getShapeById(ShapesId shapeId)
{
    auto iter = _shapesList.find(shapeId);

    if(iter == _shapesList.end())
    {
        throw std::runtime_error("No shape with such ID program is available to draw!");
    }

    std::shared_ptr<IDrawable> newShape((*iter)());

    newShape->setFrameColor(this->_currentColor);
    newShape->setFrameWidth(this->_currentWidth);

    return newShape;
}

std::shared_ptr<IDrawable> DrawAssistant::getCurrentShape() const
{
    return _currentShape;
}
    /* User started to draw figure, we examine what is being drawn now and it's coordinates */
void DrawAssistant::startShapeDerivation(const QPoint &startPoint)
{
    _currentShape = getShapeById(_currentShapeId);
    _currentShape->startDerivation(startPoint);
}

    /* Here, shape is either still being drawn (moving mouse with clicked key), or is finishing now */
void DrawAssistant::finishShapeDerivation(const QPoint &endPoint)
{
    _currentShape->endDerivation(endPoint);
}

void DrawAssistant::setNewShapeId(ShapesId id)
{
    this->_currentShapeId = id;
    this->_currentShape = getShapeById(id);
}
