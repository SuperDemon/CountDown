#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaContent>
#include <QPushButton>
#include <QVBoxLayout>
#include <QLabel>
#include <QDate>
#include <QTime>
#include <QTimer>
#include <QLCDNumber>
#include <QString>


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();
private slots:
    void play();
    void onTimeOut();
    QString TimeMSConvert(int i);
public:
    QMediaPlayer *player;
    QMediaPlaylist *playList;
    QPushButton *btn;
    QVBoxLayout *layout;
    QLabel *label;

    //倒计时
    QLCDNumber *lcd;
    QTimer *timer;

};

#endif // WIDGET_H
