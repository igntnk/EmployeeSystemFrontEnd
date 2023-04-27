#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsBlurEffect>
#include <QLabel>
#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <QPushButton>
#include <vector>

class MainWindow : public QMainWindow

{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

    bool isOnField(const QPointF& point, const QRectF& rect);

private:

    QLabel* windowTitle;
    QPushButton* exitButton;
    QPushButton* resizeButton;
    QPushButton* hideButton;

    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    QPointF pressPoint;
    bool isClicked =false;

};

#endif // MAINWINDOW_H
