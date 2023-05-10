
#ifndef ADDEMPLOYEEMENU_H
#define ADDEMPLOYEEMENU_H

#include <QMainWindow>
#include <QLabel>
#include <QPainter>
#include <QPainterPath>
#include <QComboBox>
#include <QCheckBox>
#include <QDateTimeEdit>
#include <QGraphicsDropShadowEffect>
#include <QPushButton>
#include "writepanel.h"
#include "database.h"

class AddEmployeeMenu : public QLabel
{
    Q_OBJECT

public:
    AddEmployeeMenu(DataBase& refer,QMainWindow* parent = nullptr);

    void setDefault();

private:
    QFont SFProDisplay;

    DataBase& localBase;
    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    QGraphicsDropShadowEffect* shadow;

    WritePanel* m_name;
    WritePanel* m_surname;
    WritePanel* m_lastname;
    QComboBox* m_rank;
    WritePanel* m_username;
    WritePanel* m_password;
    QDateTimeEdit* m_hiringDate;
    QCheckBox* currentHiringDate;

    QPushButton* m_enter;

    QLabel* picture;

    int panelsShift =10;

    void on_checkBox_stateChanged(int arg1);
    void addToBase();

    void changeNameOp(const QString &text);
    void changeSurnamedOp(const QString &text);
    void changeLastNameOp(const QString &text);
    void changeUsernameOp(const QString &text);
    void changePasswordOp(const QString &text);

signals:
    void baseChanged();
};

#endif // ADDEMPLOYEEMENU_H
