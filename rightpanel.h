
#ifndef RIGHTPANEL_H
#define RIGHTPANEL_H

#include <QLabel>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <vector>
#include "database_files/employee.h"
#include "pttab.h"
#include "database_files/database.h"
#include "messagewindow.h"

class RightPanel : public QLabel
{
    Q_OBJECT

public:

    RightPanel(DataBase* refer,int number, QMainWindow* parent = nullptr);
    void resize();
    void updateTaskPanel();

private:
    std::vector<PTtab*> taskPanels;
    std::vector<PTtab*> addTaskPanels;
    std::vector<int> taskId;

    QGraphicsDropShadowEffect* shadowSave;
    QGraphicsDropShadowEffect* shadowCancel;

    DataBase* referBase;
    Employee* selectedEm;

    QRect parentSize;
    bool addTaskMode = false;

    QLabel* employeeTasks;
    QLabel* taskToAdd;
    QFont SFProDisplay;

    QRect addTaskRect;
    QPushButton* addTaskBtn;
    QPushButton* cancelAddBtn;

    int addTaskId = -1;
    double generalHeight = 0;
    QRect scrollerRect;
    QRect currentAddRect;
    bool scroller =false;
    bool scrollDrag = false;
    QPoint pressPoint;
    int currentScrollerY;
    int scrollShift = 0;

    void setAddingPanels();

    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);

    bool isOnField(const QPointF& point, const QRectF& rect);

    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

public slots:
    void updateSelectedEmployee(int number);

    void setAddTaskMode();
    void hideAddTaskMode();
    void hideTaskPanels();
    void showTaskPanels();

    void addEmployeeTask();

signals:
    void changedSelected(int number);
};

#endif // RIGHTPANEL_H
