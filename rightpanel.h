
#ifndef RIGHTPANEL_H
#define RIGHTPANEL_H

#include <QLabel>
#include <QMainWindow>
#include <QMouseEvent>
#include <vector>
#include "database_files/employee.h"
#include "pttab.h"
#include "database_files/database.h"

class RightPanel : public QLabel
{
    Q_OBJECT

public:

    RightPanel(DataBase* refer,int number, QMainWindow* parent = nullptr);

private:
    Employee* selectedEm;
    std::vector<PTtab*> taskPanels;

    DataBase* referBase;

    QRect parentSize;

    void updateTaskPanel(int number);
    void mousePressEvent(QMouseEvent* event);

    bool isOnField(const QPointF& point, const QRectF& rect);

public slots:
    void updateSelectedEmployee(int number);

signals:
    void changedSelected(int number);
};

#endif // RIGHTPANEL_H
