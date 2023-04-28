#ifndef PTTAB_H
#define PTTAB_H

#include <QLabel>
#include <QPainter>
#include <QMainWindow>
#include <QFontMetrics>
#include <iostream>

class PTtab:public QLabel
{
    Q_OBJECT

public:
    PTtab(QMainWindow* parent = nullptr);

private:

    //void paintEvent(QPaintEvent *event);
    //void doPainting(QPainter* drawer);

    QLabel* infoText;
    QString infoString;

    QPixmap pixmap;
    QLabel* picture;
};

#endif // PTTAB_H
