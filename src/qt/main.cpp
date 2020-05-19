
#include <QApplication>
#include "MainWindow.h"



int main (int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/img/icons/MatriXMiX.png"));
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}