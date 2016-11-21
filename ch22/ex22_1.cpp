// helloWorld/main.cpp
#include <QApplication>
#include <QLabel>
int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
     QLabel label("Hello World");
     label.show();
     return a.exec();
}
