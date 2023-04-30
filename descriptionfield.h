
#ifndef DESCRIPTIONFIELD_H
#define DESCRIPTIONFIELD_H

#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
#include <QPen>
#include <QPainter>
#include <QGraphicsDropShadowEffect>

class DescriptionField : public QLabel
{
public:
    DescriptionField(QMainWindow* parent = nullptr);
    void resize(QMainWindow* changed);

private:
    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    void initShifts();

    QFont SFProDisplay;
    QGraphicsDropShadowEffect* shadow;

    QPixmap profilePix;
    QLabel* profilePict;
    QLabel* mainProfileInfo;
    QLabel* chapter1;
    QLabel* taskDescription;
    QLabel* chapter2;

    int pictureShift;
    int pictureSideSize;
    int mainProfileInfoShift;
    int chapter1Shift;
    int lineShift;
    int topBarHeight;
    int descPanelShift;

};

#endif // DESCRIPTIONFIELD_H
