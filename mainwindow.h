#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsBlurEffect>
#include <QLabel>
#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <QPushButton>
#include <QApplication>
#include <QGraphicsDropShadowEffect>
#include <vector>
#include "pttab.h"
#include "descriptionfield.h"

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
    QFont SFProDisplay;
    QGraphicsDropShadowEffect* shadow;

    DescriptionField* descriptionField;

//    QPixmap profilePix;
//    QLabel* profilePict;
//    QLabel* mainProfileInfo;
//    QLabel* chapter1;
//    QLabel* taskDescription;
//    QLabel* chapter2;

    QLabel* windowTitle;
    QPushButton* exitButton;
    QPushButton* resizeButton;
    QPushButton* hideButton;
    QPushButton* refreshButton;

    std::vector<QPushButton*> employeeTools;

    QPushButton* inWork;
    QPushButton* inVacation;
    QLabel* employeeTasks;
    bool inWorkClicked;
    bool inVacationClicked;

    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    void initShifts();

    QPointF pressPoint;
    bool isClicked =false;

    bool maxTrigger = false;
    bool waiting = false;

    int descPanelShift;

public slots:
    void resizeWindow();
    void hideWindow();
    void changeEvent(QEvent* e);

    void inWorkPressed();
    void inVacationPressed();
};

#endif // MAINWINDOW_H
