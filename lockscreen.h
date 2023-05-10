#ifndef LOCKSCREEN_H
#define LOCKSCREEN_H

#include <QLabel>
#include <QPainter>
#include <QMainWindow>
#include <QPainterPath>
#include <QPushButton>
#include <QGraphicsDropShadowEffect>
#include <QKeyEvent>
#include <vector>
#include "writepanel.h"
#include "employee.h"

class LockScreen: public QLabel
{
public:
    LockScreen(std::vector<Employee> passwordRefer, QMainWindow* parent =nullptr);
    void checkPasswords();


private:
    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    void resizeEvent(QResizeEvent *event);
    void changeUsernameOp(const QString &text);
    void changePasswordOp(const QString &text);

    QGraphicsDropShadowEffect* shadow;

    QPixmap pixmap;
    QLabel* picture;

    WritePanel* username;
    WritePanel* password;

    QPushButton* enter;

    QLabel* wrongPass;

    std::vector<Employee> refer;

};

#endif // LOCKSCREEN_H
