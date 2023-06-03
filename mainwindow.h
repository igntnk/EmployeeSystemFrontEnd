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
    DataBase* dataBase;

    MessageWindow* message;

    LockScreen* lockScreen;

    std::vector<QGraphicsDropShadowEffect*> shadows;

    DescriptionField* descriptionField;

    QLabel* windowTitle;
    QPushButton* exitButton;
    QPushButton* resizeButton;
    QPushButton* hideButton;

    std::vector<QPushButton*> employeeTools;

    QLabel* employeeTasks;

    LeftPanel* leftPanel;
    QPushButton* myProfile;
    QLabel* myProfileText;
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

    QSize mainWindowMinimumSize;
    QSize controlButtonSize;
    QSize employeeControllButtonSize;
    QSize myProfileIconSize;
    QSize myProfileBtnSize;
    int employeeControllButtonShift;
    int descPanelShift;
    int leftSideShift;
    int buttonShift;
    int topPanelHeight;
    int strokeWidth;
    int toCenterShift;
    int defaultSearchPanelHeight;
    int extendedSearchPanelHeight;
    int bootomLeftSideShift;
    int shiftForScrolling;

public slots:

    void resizeWindow();
    void hideWindow();
    void keyPressEvent(QKeyEvent *event);

    void setSelected(int number);
    void deleteSlot();
    void promoteSlot();
    void myProfileSelected();

    void resizeByFilter(bool opened);
};

#endif // MAINWINDOW_H
