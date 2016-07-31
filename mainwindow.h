/*
 * Main window implements GUI and interaction with other parts of the program.
 *
 * ATTENTION: due to the problems (i suppose inside Qt's library "QFileDialog") I was unable to
 * properly execute and test image saving feature. I googled the exception
 * that is throwing, and folks have the same problem - the issue is in installed git and dropbox
 * software, which made context menu in windows explorer. Release/debug build - doesn't matter.
 *
 */

#pragma once

#include <QMainWindow>
#include <QColorDialog>
#include <QFileDialog>
#include <QPixmap>
#include <QLabel>
#include <QFont>
#include <QIcon>

#include "canvas.h"
#include "dialogbrushwidth.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:

    Ui::MainWindow *ui;
    Canvas* canvas;
    QString currentMessage;
    QLabel* shapeNameLabel;
    QLabel* shapeWidthLabel;

    void passShapeIdToAssistant(ShapesId shapeId);

private slots:

    void on_actionClear_triggered();
    void on_actionExit_triggered();
    void on_actionBrush_triggered();
    void on_actionLine_triggered();
    void on_actionRectangle_triggered();
    void on_actionEllipse_triggered();
    void on_actionWidth_triggered();
    void on_actionColor_triggered();
    void on_actionInfo_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionSave_triggered();
};
