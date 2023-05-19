#ifndef DESCRIPTIONFIELD_H
#define DESCRIPTIONFIELD_H

#include <QLabel>
#include <QMainWindow>
#include <QPixmap>
#include <QPen>
#include <QPainter>
#include <QPainterPath>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QDateTimeEdit>
#include <vector>
#include "database_files/employee.h"
#include "database_files/database.h"
#include "writepanel.h"

class DescriptionField : public QLabel
{
    Q_OBJECT

public:
    DescriptionField(DataBase* base, QMainWindow* parent = nullptr);
    void resize(QMainWindow* changed);

    void setVisibility(bool);
    void setInfo();

private:
    bool isProfileSelected = false;
    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    void setDescription();
    void setEmploymentDate();

    QString searchLongestWord(Employee* refer);

    void initShifts();

    QFont SFProDisplay;
    QGraphicsDropShadowEffect* shadow;

    QPixmap profilePix;
    QLabel* profilePict;
    QLabel* chapters;
    QLabel* profileInfo;
    QLabel* department;
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

    WritePanel* m_name;
    WritePanel* m_surname;
    QDateEdit* m_hiringDate;

    QPushButton* cancel;
    QPushButton* save;

public slots:

    void setSelectedNum(int number);
    void changeDesc(int number);

    void setEditMode();
    void exitEditMode();

    void saveChanges();

signals:
    void baseChanged();
};

#endif // DESCRIPTIONFIELD_H
