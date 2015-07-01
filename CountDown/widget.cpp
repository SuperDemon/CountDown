#include "widget.h"
#include <QDir>
#include <QUrl>
#include <QAxObject>
#include <QCoreApplication>
#include <QElapsedTimer>



Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    player = new QMediaPlayer;
    layout = new QVBoxLayout(this);
    label= new QLabel;

    lcd = new QLCDNumber;
    lcd->setDigitCount(10);
    lcd->setMode(QLCDNumber::Dec);
    lcd->setSegmentStyle(QLCDNumber::Flat);


    timer = new QTimer;
    timer->setInterval(1000);
    timer->start();

    layout->addWidget(lcd,Qt::AlignCenter);

    connect(timer, SIGNAL(timeout()), this, SLOT(onTimeOut()));

    //重新设置窗口的布局管理器
    this->setLayout(layout);
    //重新设置窗口的大小
    this->resize(400, 400);
    //重新设置窗口的标题
    this->setWindowTitle("定时器");
}

Widget::~Widget()
{

}
void Widget::play()
{
    QAxObject *speech= new QAxObject();
    speech->setControl("SAPI.SpVoice");
    speech->dynamicCall("Speak(QString,uint)","时间还有5分钟",1);

}
void Widget::onTimeOut()
{

    for(int count = 304000;count > 0;)//12000000
    {
        QElapsedTimer t;
        t.start();
        while(t.elapsed()<1000)
        QCoreApplication::processEvents();

        lcd->display(TimeMSConvert(count));

        qDebug("%d---",count);

        count-=1000;

        if(count == 300000)
        {
            play();
        }
    }

}
QString Widget::TimeMSConvert(int i)
{
        QString strTime;

        int nMinute = i/60000%60;

        int nSec = i/1000%60;

        strTime = QString("%1:%2").arg(nMinute, 2, 10, QChar('0')).arg(nSec, 2, 10, QChar('0'));

        return strTime;
}


