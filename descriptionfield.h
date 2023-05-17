#ifndef DESCRIPTIONFIELD_H
#define DESCRIPTIONFIELD_H

#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
#include <QPen>
#include <QPainter>
#include <QGraphicsDropShadowEffect>
#include <vector>
#include "database_files/employee.h"
#include "database_files/database.h"

class DescriptionField : public QLabel
{
    Q_OBJECT

public:
    DescriptionField(DataBase* base, QMainWindow* parent = nullptr);
    void resize(QMainWindow* changed);

    void setVisibility(bool);

private:
    bool isProfileSelected = false;
    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    void setDescription();

    void setInfo();
    void setEmploymentDate();

    QString searchLongestWord(Employee* refer);

    void initShifts();

    QFont SFProDisplay;
    QGraphicsDropShadowEffect* shadow;

    QPixmap profilePix;
    QLabel* profilePict;
    QLabel* chapters;
    QLabel* profileInfo;
    QLabel* chapter1;
    QLabel* taskDescription;
    QLabel* chapter2;
    QLabel* employmentDate;

    int pictureShift;
    int pictureSideSize;
    int mainProfileInfoShift;
    int chapter1Shift;
    int lineShift;
    int topBarHeight;
    int descPanelShift;

    int selectedNum = -1;
    DataBase* referBase;

public slots:

    void setSelectedNum(int number);
    void changeDesc(int number);
};

#endif // DESCRIPTIONFIELD_H
