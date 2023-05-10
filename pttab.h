#ifndef PTTAB_H
#define PTTAB_H

#include <QLabel>
#include <QPainter>
#include <QMainWindow>
#include <QFontMetrics>
#include <QFont>
#include <QMouseEvent>
#include <iostream>

class PTtab:public QLabel
{
    Q_OBJECT

public:
    PTtab(QString text = "Unknown Name\nUnknown Surname\nUnknown Rank" ,
          int choice= 1, QLabel* parent = nullptr);
    ~PTtab();

    void setPicture(int choice);
    void setPicture(QString file);
    void setPText(const QString& text,int rowsNum);

    void setSelected(bool);

    void resizeByScroller(bool, QRect);

private:
    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    bool isOnField(const QPointF& point, const QRectF& rect);

    bool isSelected =false;

    QFont SFProDisplay;
    QFontMetrics SFProDislplayMetrics = QFontMetrics(QFont("SF Pro Display", 12));

    QLabel* infoText;
    QString infoString;

    QString photoFile;
    QPixmap pixmap;
    QLabel* picture;
};

#endif // PTTAB_H
