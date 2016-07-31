#include "dialogbrushwidth.h"
#include "ui_dialogbrushwidth.h"

DialogBrushWidth::DialogBrushWidth(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogBrushWidth)
{
    ui->setupUi(this);
}

DialogBrushWidth::~DialogBrushWidth()
{
    delete ui;
}

int DialogBrushWidth::getValue() const
{
    return ui->spinBox->value();
}

void DialogBrushWidth::setValue(int val)
{
    ui->horizontalSlider->setValue(val);
}

void DialogBrushWidth::on_horizontalSlider_valueChanged(int value)
{
    ui->spinBox->setValue(value);
}

void DialogBrushWidth::on_spinBox_valueChanged(int arg1)
{
    ui->horizontalSlider->setValue(arg1);
}
