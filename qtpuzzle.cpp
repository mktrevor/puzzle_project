#include <QtGui/QApplication>
#include <QMotifStyle>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    QFont font("Palatino", 12, QFont::Bold);
    a.setFont(font);
    
    a.setStyle(new QMotifStyle());
    
    MainWindow w;
    
    w.show();
    
    return a.exec();
}
