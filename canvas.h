/*
 *  Canvas class and their interaction with DrawAssistant are the key point of the program logic.
 *  DrawAssistant provides common data (current brush width, color, provides with constructed Shape objects).
 *  In it's turn, Canvas encapsulates all drawable entities, provides interface for drawing, and the RTTI ensures
 *  that each entity will be drawn in a correct way.
 *
 */

#pragma once

#include <QWidget>
#include <QStack>
#include <QPainter>
#include <QPair>
#include <QMouseEvent>
#include <QAction>

#include "drawassistant.h"
#include "interfaces/shape.h"

namespace Ui {
class Canvas;
}

class Canvas : public QWidget
{
    Q_OBJECT

public:

    explicit Canvas(QWidget *parent = nullptr, DrawAssistant *assistant = nullptr);
    ~Canvas();

    void setDrawAssistant(DrawAssistant &assistant);
    void clearCanvas();
    void setBackgroundColor(const QColor &);

    void undo();
    void redo();

private:

    Ui::Canvas *ui;
    QVector<std::shared_ptr<IDrawable>>_shapes;
    QStack<std::shared_ptr<IDrawable>> _undoRedoStack;
    DrawAssistant* _drawAssistant;

protected:

    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);

};
