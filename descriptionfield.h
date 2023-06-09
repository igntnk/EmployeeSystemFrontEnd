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
#include "messagewindow.h"
#include "writepanel.h"

class DescriptionField : public QLabel
{
    Q_OBJECT

public:
    DescriptionField(DataBase* base, QMainWindow* parent = nullptr);
    void resize(QMainWindow* changed);

    void setVisibility(bool);
    void setInfo();
    void setDescription();

private:
    DataBase* localBase;

    bool isProfileSelected = false;
    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    void setEmploymentDate();

    QString searchLongestWord(Employee* refer);

    void initShifts();

    void changeToInWorkTask();
    void changeToDoneTask();

    std::vector<QGraphicsDropShadowEffect*> shadows;

    QPixmap profilePix;
    QLabel* profilePict;
    QLabel* chapters;
    QLabel* profileInfo;
    QLabel* chapter1;
    QLabel* taskDescription;
    QLabel* startLineDate;
    QLabel* deadLineDate;
    QLabel* responceEmployee;
    QPushButton* completeStageBtn = new QPushButton();
    QLabel* chapter2;
    QLabel* employmentDate;

    QSize buttonSize;
    int pictureShift;
    int pictureSideSize;
    int mainProfileInfoShift;
    int chapter1Shift;
    int lineShift;
    int descPanelShift;
    int topPanelHeight;

    int selectedNum = -1;
    int selectedTask = -1;

    bool isInVac = false;

    QLabel* vacStart;
    QLabel* vacEnd;
    QRect vacRect;

    WritePanel* m_name;
    WritePanel* m_surname;
    QDateEdit* m_hiringDate;

    QPushButton* cancel;
    QPushButton* save;

    QPushButton* addVacationBtn;

public slots:

    void setSelectedNum(int number);
    void changeDesc(int number);

    void setEditMode();
    void exitEditMode();

    void saveChanges();

signals:
    void baseChanged();
    void vacBtnPressed();
};

#endif // DESCRIPTIONFIELD_H
