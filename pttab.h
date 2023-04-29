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

    void setPicture(int choice);
    void setPicture(QString file);
    void setText(const QString& text,int rowsNum);

private:

    //void paintEvent(QPaintEvent *event);
    //void doPainting(QPainter* drawer);
    QFont SFProDisplay;

    QLabel* infoText;
    QString infoString;

    QPixmap pixmap;
    QLabel* picture;
};

#endif // PTTAB_H
