#ifndef PTTAB_H
#define PTTAB_H

#include <QLabel>
#include <QPainter>
#include <QMainWindow>
#include <QFontMetrics>
#include <QFont>
#include <iostream>

class PTtab:public QLabel
{
    Q_OBJECT

public:
    PTtab(QString text = "Unknown Name\nUnknown Surname\nUnknown Rank" ,
          int choice= 1, QMainWindow* parent = nullptr);
    ~PTtab();

    void setPicture(int choice);
    void setPicture(QString file);
    void setText(const QString& text,int rowsNum);

private:

    QFont SFProDisplay;

    QLabel* infoText;
    QString infoString;

    QString photoFile;
    QPixmap pixmap;
    QLabel* picture;
};

#endif // PTTAB_H
