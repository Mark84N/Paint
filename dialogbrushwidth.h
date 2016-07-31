#pragma once

#include <QDialog>

namespace Ui {
class DialogBrushWidth;
}

class DialogBrushWidth : public QDialog
{
    Q_OBJECT

public:

    explicit DialogBrushWidth(QWidget *parent = 0);
    ~DialogBrushWidth();

    int getValue()const;
    void setValue(int val);

private slots:

    void on_horizontalSlider_valueChanged(int value);
    void on_spinBox_valueChanged(int arg1);

private:

    Ui::DialogBrushWidth *ui;
};

