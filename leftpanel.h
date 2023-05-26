#ifndef LEFTPANEL_H
#define LEFTPANEL_H

#include <QLabel>
#include <QMouseEvent>
#include <QPushButton>
#include <QPainter>
#include <QPainterPath>
#include "database_files/database.h"
#include "pttab.h"

class LeftPanel : public QLabel
{
    Q_OBJECT
public:
    LeftPanel(DataBase* dataBase, QMainWindow* parent = nullptr);
    void resizePanel();

    int getSelectedPanelNum();
    void setSelected(int number);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void scrollEvent();
    bool isOnField(const QPointF& point, const QRectF& rect);

private:
    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    void checkScroller();
    void setDrag(QMouseEvent* event);

    DataBase* localBase;
    PTtab* referPT;

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
    int sortType = 0;

public slots:
    void inWorkPressed();
    void inVacationPressed();

    void updateProfilesList();

    void changePTInfo();

    void updateBySearch(const QString &text);
    void getSortType(int type);

signals:
    void changedSelected(int number);
};

#endif // LEFTPANEL_H
