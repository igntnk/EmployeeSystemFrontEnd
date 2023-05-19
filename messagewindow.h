
#ifndef MESSAGEWINDOW_H
#define MESSAGEWINDOW_H

#include <QLabel>
#include <QPainter>
#include <QPainterPath>
#include <QPushButton>
#include <QMainWindow>
#include <QMouseEvent>
#include <QMessageBox>

class MessageWindow : public QDialog
{
    Q_OBJECT

public:
    MessageWindow(QString textTitle="unknown message",QString textMain = "There is no nothing",
                  bool ok=false, bool cancel=false,QMainWindow* parent = nullptr);

    void setMainText(QString text);
    void setTitleText(QString text);

    void setOkButton(bool);
    void setCancelButton(bool);

protected:

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

    bool isOnField(const QPointF& point, const QRectF& rect);

private:

    QFont SFProDisplay;

    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    QLabel* titleText;
    QLabel* mainText;

    QPushButton* okBtn;
    QPushButton* cnslBtn;

    void signalOk();
    void signalCancel();

    bool isClicked = false;
    QPoint pressPoint;

signals:
    void okPressed(int);
    void cnslPressed(int);
};

#endif // MESSAGEWINDOW_H
