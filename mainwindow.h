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
#include <QKeyEvent>
#include <vector>
#include "pttab.h"
#include "database.h"
#include "descriptionfield.h"
#include "lockscreen.h"
#include "leftpanel.h"
#include "rightpanel.h"
#include "addemployeemenu.h"

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

    void showAddEmMenu();

private:
    LockScreen* lockScreen;

    QFont SFProDisplay;
    QGraphicsDropShadowEffect* shadow;

    DescriptionField* descriptionField;

    QLabel* windowTitle;
    QPushButton* exitButton;
    QPushButton* resizeButton;
    QPushButton* hideButton;
    QPushButton* refreshButton;

    std::vector<QPushButton*> employeeTools;

    QLabel* employeeTasks;

    DataBase dataBase;
    LeftPanel* leftPanel;
    std::vector<PTtab*> taskPanels();

    RightPanel* rightPanel;

    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    void initShifts();

    QPointF pressPoint;
    QPointF globalPressPoint;
    QPointF currentTopLeft;
    QPointF currentBottomRigth;
    int whichSide;
    bool isClicked =false;

    bool maxTrigger = false;
    bool waiting = false;
    bool mouseResize = false;

    int descPanelShift;

    AddEmployeeMenu* addMenu;

public slots:

    void resizeWindow();
    void hideWindow();
    void keyPressEvent(QKeyEvent *event);


};

#endif // MAINWINDOW_H
