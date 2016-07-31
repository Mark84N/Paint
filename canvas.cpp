#include "canvas.h"
#include "ui_canvas.h"

Canvas::Canvas(QWidget *parent, DrawAssistant *assistant)
   :QWidget(parent),
    ui(new Ui::Canvas),
    _drawAssistant(assistant)
{
    ui->setupUi(this);

    setBackgroundColor(Qt::white);
}

Canvas::~Canvas()
{
    delete ui;
}

void Canvas::paintEvent(QPaintEvent * ev)
{
    QPainter painter(this);

    for(auto &shape : _shapes){

        shape->draw(&painter);
    }
}

void Canvas::mousePressEvent(QMouseEvent * ev)
{
    if (ev->buttons() & Qt::LeftButton){

        try
        {
            _drawAssistant->startShapeDerivation(ev->pos());

            _shapes.push_back(_drawAssistant->getCurrentShape());
        }
        catch(const std::bad_alloc & err)
        {
            QMessageBox::critical(this, "Memory allocation error.", err.what());

            exit(1);
        }
        catch(const std::runtime_error &err)
        {
            QMessageBox::critical(this, "!", err.what());

            exit(1);
        }
        catch(...)
        {
            terminate();
        }

        update();
    }
}

void Canvas::mouseMoveEvent(QMouseEvent * ev)
{
    if (ev->buttons() & Qt::LeftButton){

        _drawAssistant->finishShapeDerivation(ev->pos());

        update();
    }
}

void Canvas::setBackgroundColor(const QColor &col)
{
    QPalette pal;
    pal.setColor(QPalette::Background, col);
    this->setAutoFillBackground(true);
    this->setPalette(pal);
}

void Canvas::undo()
{
    if (!_shapes.empty()){

        std::shared_ptr<IDrawable> undoValue = _shapes.back();
        _undoRedoStack.push(undoValue);
        _shapes.pop_back();

        update();
    }
}

void Canvas::redo()
{
    if (!_undoRedoStack.empty()){

        std::shared_ptr<IDrawable> redoValue = _undoRedoStack.pop();
        _shapes.append(redoValue);

        update();
    }
}

void Canvas::setDrawAssistant(DrawAssistant &assistant){

    _drawAssistant = &assistant;
}

void Canvas::clearCanvas()
{
    _shapes.clear();
    _undoRedoStack.clear();

    update();
}
