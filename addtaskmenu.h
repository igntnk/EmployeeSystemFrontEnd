
#ifndef ADDTASKMENU_H
#define ADDTASKMENU_H

#include <QLabel>
#include <QDateTimeEdit>
#include <QCheckBox>
#include <QPushButton>
#include "writepanel.h"
#include "database_files/database.h"
#include "messagewindow.h"


class AddTaskMenu : public QLabel
{
public:
    AddTaskMenu(DataBase* dataBase,QMainWindow* parent=nullptr);

    void setDefault();
    void resize(QRect parent);

private:
    QFont SFProDisplay;

    DataBase* localBase;

    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    QLabel* chapter;

    WritePanel* m_name;
    WritePanel* m_description;
    QDateTimeEdit* m_startline;
    QDateTimeEdit* m_deadline;
    QCheckBox* currentDate;

    QPushButton* m_enter;
    QPushButton* m_cancel;

    int panelsShift =10;

    void on_checkBox_stateChanged(int arg1);
    void addToBase();
    void hideMenu();
    bool findSimilar();

    Task* referEm;

signals:
    void baseChanged();
};

#endif // ADDTASKMENU_H
