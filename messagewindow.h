
#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H

#include <QLabel>
#include <QPainter>
#include <QPainterPath>
#include <QPushButton>
#include <QMainWindow>
#include <QMessageBox>

class MessageWindow : public QMessageBox
{
public:
    MessageWindow(QString textTitle="unknown message",QString textMain = "There is no nothing",QMainWindow* parent = nullptr);

private:

    QFont SFProDisplay;

    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    QLabel* titleText;
    QLabel* mainText;

    QPushButton* okBtn;

};

#endif // MESSAGEWINDOW_H
