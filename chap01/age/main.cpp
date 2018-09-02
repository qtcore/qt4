#include <QApplication>
#include "widget.h"
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget * windows = new QWidget;  //创建窗口对象
    windows->setWindowTitle("enter your age");

    QSlider *lider = new QSlider(Qt::Horizontal);  //创建滑块对象
    QSpinBox *pinBox = new QSpinBox;   // 创建微调框 对象

    lider->setRange(0, 130); //设置取值范围
    pinBox->setRange(0,130);

    QObject::connect(pinBox, SIGNAL(valueChanged(int)), lider, SLOT(setValue(int)));  // 连接对象与槽
    QObject::connect(lider, SIGNAL(valueChanged(int)), pinBox, SLOT(setValue(int)));

    pinBox->setValue(45);  //设置默认值

    QHBoxLayout *layout = new QHBoxLayout;   //设置布局--水平
    layout->addWidget(pinBox);  // 布局里添加对象
    layout->addWidget(lider);
    windows->setLayout(layout);

    windows->show();



    //Widget w;
   // w.show();
    
    return a.exec();
}
