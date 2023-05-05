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

protected:
    void mousePressEvent(QMouseEvent* event);
    bool isOnField(const QPointF& point, const QRectF& rect);

private:
    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    QFont SFProDisplay;

    QPushButton* inWork;
    QPushButton* inVacation;
    bool inWorkClicked = true;
    bool inVacationClicked=false;

    std::vector<PTtab*> profilePanelsInWork;
    std::vector<PTtab*> profilePanelsInVacation;

public slots:
    void inWorkPressed();
    void inVacationPressed();
};

#endif // LEFTPANEL_H
