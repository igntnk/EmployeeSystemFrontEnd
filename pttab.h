#ifndef PTTAB_H
#define PTTAB_H

#include <QLabel>
#include <QPainter>
#include <QMainWindow>
#include <QFontMetrics>
#include <QFont>
#include <QDate>
#include <QMouseEvent>
#include <QGraphicsDropShadowEffect>
#include <iostream>
#include <cmath>

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
    void setDateLine(float percentage);
    void setUndone(bool);

    void setDeadLine(QDate newDeadLine);
    QDate deadLine() const;

private:
    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    QGraphicsDropShadowEffect* shadow;

    bool isOnField(const QPointF& point, const QRectF& rect);

    bool isSelected =false;
    float percentLine = 1;
    bool ifTaskPanel = false;
    bool lostTask = false;

    QFont SFProDisplay;
    QFontMetrics SFProDislplayMetrics = QFontMetrics(QFont("SF Pro Display", 12));

    QLabel* infoText;
    QString infoString;

    QString photoFile;
    QPixmap pixmap;
    QLabel* picture;

    QDate m_deadLine;
};

#endif // PTTAB_H
