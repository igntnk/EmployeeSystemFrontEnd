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
#include "database_files/database.h"
#include "descriptionfield.h"
#include "lockscreen.h"
#include "leftpanel.h"
#include "rightpanel.h"
#include "addemployeemenu.h"
#include "addtaskmenu.h"
#include "messagewindow.h"
#include "addvacationmenu.h"
#include "searchbyname.h"

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

    MessageWindow* test;
    DataBase* dataBase;

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
    QRect neadedRect;
    int whichSide;
    bool isClicked =false;

    bool maxTrigger = false;
    bool waiting = false;
    bool mouseResize = false;

    int descPanelShift;
    int selected = -1;

    AddEmployeeMenu* addEmMenu;
    AddTaskMenu* addTaskMenu;
    AddVacationMenu* addVacationMenu;

    SearchByPar* searchPanel;

    void deleteEmployee();
    void showAddEmMenu();
    void editMenu();
    void showAddTaskMenu();
    void promoteEmployee();


public slots:

    void resizeWindow();
    void hideWindow();
    void keyPressEvent(QKeyEvent *event);

    void setSelected(int number);
    void deleteSlot();
    void promoteSlot();

    void resizeByFilter(bool opened);
};

#endif // MAINWINDOW_H
