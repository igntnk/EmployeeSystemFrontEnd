
#include "messagewindow.h"

MessageWindow::MessageWindow(QString textTitle,QString textMain,QMainWindow* parent):
    QMessageBox(parent)
{
    SFProDisplay = QFont("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);
    QFontMetrics SFProDisplayMetrics(SFProDisplay);

    titleText = new QLabel(this);
    mainText = new QLabel(this);
    titleText->setFont(SFProDisplay);
    mainText->setFont(SFProDisplay);
    titleText->setText(textTitle);
    mainText->setText(textMain);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->resize(QSize(400,SFProDisplayMetrics.horizontalAdvance(textMain)+100));
    this->setAttribute(Qt::WA_TranslucentBackground );
    this->setMouseTracking(true);
}

void MessageWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter drawer(this);
    doPainting(&drawer);
}

void MessageWindow::doPainting(QPainter *drawer)
{
    drawer->setRenderHint(QPainter::Antialiasing);

    QBrush myBrush;
    QPen myPen;
    QPainterPath myPath;

    myPen.setColor(QColor(10,10,10));
    myBrush.setColor(QColor(50,50,50,230));
    myBrush.setStyle(Qt::SolidPattern);
    myPath.moveTo(0,0);
    myPath.addRoundedRect(QRect(QPoint(1,1),QPoint(this->width()-2,this->height()-2)),10,10);

    drawer->setPen(myPen);
    drawer->setBrush(myBrush);
    drawer->drawPath(myPath);

    myPath.clear();
}

