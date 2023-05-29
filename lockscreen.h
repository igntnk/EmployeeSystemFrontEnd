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
#include "database_files/database.h"

class LockScreen: public QLabel
{
public:
    LockScreen(DataBase* passwordRefer, QMainWindow* parent =nullptr);
    void checkPasswords();

    int getLogginedId();
private:
    QFont SFProDisplay;

    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    void resizeEvent(QResizeEvent *event);

    QGraphicsDropShadowEffect* shadow;

    QPixmap pixmap;
    QLabel* picture;

    WritePanel* username;
    WritePanel* password;

    QPushButton* enter;
    QPushButton* exit;

    QLabel* wrongPass;

    DataBase* refer;

    int logginedId;
};

#endif // LOCKSCREEN_H
