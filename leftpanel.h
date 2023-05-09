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
    Q_OBJECT
public:
    LeftPanel(DataBase* dataBase, QMainWindow* parent = nullptr);
    void resizePanel();

    int getSelectedPanelNum();

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
    std::vector<int> inWorkNum;
    std::vector<PTtab*> profilePanelsInVacation;
    std::vector<int> inVacNum;

    int scrollShift=0;
    double generalHeight = 0;
    bool scroller=false;
    bool drag = false;
    QRect refer;
    QPoint pressPoint;
    int currentScrollerY;

    int selectedNum = -1;

public slots:
    void inWorkPressed();
    void inVacationPressed();

signals:
    void changedSelected(int number);
};

#endif // LEFTPANEL_H
