#include "mainwindow.h"
#include "qdebug.h"
#include "qthread.h"

#include <QApplication>
#include <QLabel>
#include "ihm6843.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

     MainWindow w;
     w.show();

    return a.exec();
}
