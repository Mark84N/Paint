#include <QApplication>
#include "mainwindow.h"
#include "dialogbrushwidth.h"

void unexpected(){

    QMessageBox::critical(nullptr, "Error", "Something went wrong, please relaunch the program:("
                                            ""
                                            "");
    exit(1);
}

int main(int argc, char *argv[])
{
    std::set_terminate(unexpected);

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return a.exec();
}
