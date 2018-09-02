#include <QApplication>
#include "widget.h"
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget * windows = new QWidget;  //�������ڶ���
    windows->setWindowTitle("enter your age");

    QSlider *lider = new QSlider(Qt::Horizontal);  //�����������
    QSpinBox *pinBox = new QSpinBox;   // ����΢���� ����

    lider->setRange(0, 130); //����ȡֵ��Χ
    pinBox->setRange(0,130);

    QObject::connect(pinBox, SIGNAL(valueChanged(int)), lider, SLOT(setValue(int)));  // ���Ӷ������
    QObject::connect(lider, SIGNAL(valueChanged(int)), pinBox, SLOT(setValue(int)));

    pinBox->setValue(45);  //����Ĭ��ֵ

    QHBoxLayout *layout = new QHBoxLayout;   //���ò���--ˮƽ
    layout->addWidget(pinBox);  // ��������Ӷ���
    layout->addWidget(lider);
    windows->setLayout(layout);

    windows->show();



    //Widget w;
   // w.show();
    
    return a.exec();
}
