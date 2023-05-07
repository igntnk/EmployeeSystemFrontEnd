#ifndef LEFTPANEL_H
#define LEFTPANEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
#include <QPainter>
#include <QPainterPath>
#include "database.h"
#include "pttab.h"

class LeftPanel : public QLabel
{
public:
    LeftPanel(DataBase* dataBase, QMainWindow* parent = nullptr);
    void resizePanel();

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void scrollEvent();
    bool isOnField(const QPointF& point, const QRectF& rect);

private:
    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    void checkeScroller();

    QFont SFProDisplay;

    QPushButton* inWork;
    QPushButton* inVacation;
    bool inWorkClicked = true;
    bool inVacationClicked=false;

    std::vector<PTtab*> profilePanelsInWork;
    std::vector<PTtab*> profilePanelsInVacation;

    int scrollShift=0;
    double generalHeight = 0;
    bool scroller=false;
    bool drag = false;
    QRect refer;
    QPoint pressPoint;
    int currentScrollerY;


public slots:
    void inWorkPressed();
    void inVacationPressed();
};

#endif // LEFTPANEL_H
