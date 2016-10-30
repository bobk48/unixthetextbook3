// signalSlot2/main.cpp
#include <QApplication>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QSlider>
int main(int argc, char *argv[])
{
     QApplication a(argc, argv);
     QWidget window;
     QVBoxLayout* mainLayout = new QVBoxLayout(&window);
     QLabel* label = new QLabel("0");
     QSpinBox* spinBox = new QSpinBox;
     QSlider* slider = new QSlider(Qt::Horizontal);
     mainLayout->addWidget(label);
     mainLayout->addWidget(spinBox);
     mainLayout->addWidget(slider);
     QObject::connect(spinBox, SIGNAL(valueChanged(int)),
     label, SLOT(setNum(int)));
     QObject::connect(spinBox, SIGNAL(valueChanged(int)),
     slider, SLOT(setValue(int)));
     QObject::connect(slider, SIGNAL(valueChanged(int)),
     label, SLOT(setNum(int)));
     QObject::connect(slider, SIGNAL(valueChanged(int)),
     spinBox, SLOT(setValue(int)));
     window.show();
     return a.exec();
}
