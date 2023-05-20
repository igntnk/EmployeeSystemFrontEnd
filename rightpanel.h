
#ifndef RIGHTPANEL_H
#define RIGHTPANEL_H

#include <QLabel>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>
#include <vector>
#include "database_files/employee.h"
#include "pttab.h"
#include "database_files/database.h"

class RightPanel : public QLabel
{
    Q_OBJECT

public:

    RightPanel(DataBase* refer,int number, QMainWindow* parent = nullptr);
    void resize();

private:
    Employee* selectedEm;
    std::vector<PTtab*> taskPanels;
    std::vector<PTtab*> addTaskPanels;

    DataBase* referBase;

    QRect parentSize;
    bool addTaskMode = false;

    QLabel* employeeTasks;
    QLabel* taskToAdd;
    QFont SFProDisplay;

    void setAddingPanels();

    void updateTaskPanel(int number);
    void mousePressEvent(QMouseEvent* event);

    bool isOnField(const QPointF& point, const QRectF& rect);

    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

public slots:
    void updateSelectedEmployee(int number);

    void setAddTaskMode();

signals:
    void changedSelected(int number);
};

#endif // RIGHTPANEL_H
