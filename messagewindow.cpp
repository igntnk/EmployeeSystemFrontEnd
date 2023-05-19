
#include "messagewindow.h"

MessageWindow::MessageWindow(QString textTitle,QString textMain,
                             bool ok, bool cancel,QMainWindow* parent):
    QDialog(parent)
{
    SFProDisplay = QFont("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);
    QFontMetrics SFProDisplayMetrics(SFProDisplay);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->resize(300,170);
    this->setAttribute(Qt::WA_TranslucentBackground );
    this->setMouseTracking(true);
    this->setModal(true);


    titleText = new QLabel(this);
    mainText = new QLabel(this);
    titleText->setFont(SFProDisplay);
    mainText->setFont(SFProDisplay);
    titleText->setText(textTitle);
    mainText->setText(textMain);
    titleText->setGeometry(0,0,SFProDisplayMetrics.horizontalAdvance(textTitle),SFProDisplayMetrics.height());
    mainText->setGeometry(0,0,SFProDisplayMetrics.horizontalAdvance(textMain),SFProDisplayMetrics.height());
    titleText->move(this->geometry().center().x()-titleText->width()/2,this->geometry().topLeft().y()+11);
    mainText->move(this->geometry().center().x()-mainText->width()/2,this->height()-this->height()/1.8);
    titleText->setStyleSheet("color: rgb(100,100,100);");
    mainText->setStyleSheet("color: rgb(170,170,170);");

    okBtn = new QPushButton(this);
    okBtn->setStyleSheet("QPushButton {"
                         "background-color: rgb(28, 28, 28);"
                         "color: rgb(100,100,100);"
                         "border: 2px solid rgb(120,120,120);"
                         "border-radius: 7px"
                         "}"
                         "QPushButton:hover {"
                         "background-color: rgb(20, 20, 20);"
                         "color: rgb(80,80,80);"
                         "}"
                         "QPushButton:pressed {"
                         "background-color: rgb(10,10,10);"
                         "color: rgb(60,60,60);"
                         "border: 1px solid rgb(40, 40, 40);"
                         "}");
    okBtn->setFont(SFProDisplay);
    okBtn->setText("Ok");
    okBtn->hide();
    okBtn->setGeometry(this->geometry().center().x()-50,this->height()-this->height()/4,
                       100,30);

    cnslBtn = new QPushButton(this);
    cnslBtn->setStyleSheet("QPushButton {"
                         "background-color: rgb(28, 28, 28);"
                         "color: rgb(100,100,100);"
                         "border: 2px solid rgb(120,120,120);"
                         "border-radius: 7px"
                         "}"
                         "QPushButton:hover {"
                         "background-color: rgb(20, 20, 20);"
                         "color: rgb(80,80,80);"
                         "}"
                         "QPushButton:pressed {"
                         "background-color: rgb(10,10,10);"
                         "color: rgb(60,60,60);"
                         "border: 1px solid rgb(40, 40, 40);"
                         "}");
    cnslBtn->setFont(SFProDisplay);
    cnslBtn->setText("Cancel");
    cnslBtn->hide();

    if(ok)
    {
        okBtn->show();
        connect(okBtn,&QPushButton::clicked,this,&MessageWindow::signalOk);
    }

    if(cancel)
    {
        okBtn->setGeometry(this->geometry().center().x()+5,this->height()-this->height()/4,
                           100,30);
        cnslBtn->setGeometry(this->geometry().center().x()-105,this->height()-this->height()/4,
                             100,30);
        cnslBtn->show();
        connect(cnslBtn, &QPushButton::clicked,this,&MessageWindow::signalCancel);
    }

}

void MessageWindow::setMainText(QString text)
{
    QFontMetrics SFProDisplayMetrics(SFProDisplay);

    mainText->resize(SFProDisplayMetrics.horizontalAdvance(text),SFProDisplayMetrics.height());
    mainText->move(this->geometry().center().x()-mainText->width()/2,this->height()-this->height()/1.8);
    mainText->setText(text);
}

void MessageWindow::setTitleText(QString text)
{
    QFontMetrics SFProDisplayMetrics(SFProDisplay);

    titleText->resize(SFProDisplayMetrics.horizontalAdvance(text),SFProDisplayMetrics.height());
    titleText->move(this->geometry().center().x()-titleText->width()/2,this->geometry().topLeft().y()+11);

    titleText->setText(text);
}

void MessageWindow::setOkButton(bool checker)
{
    if(checker)
    {
        okBtn->show();
        connect(okBtn,&QPushButton::clicked,this,&MessageWindow::signalOk);
        if(cnslBtn->isHidden())
        {
            okBtn->setGeometry(this->geometry().center().x()-50,this->height()-this->height()/4,
                               100,30);
        }
        else
        {
            okBtn->setGeometry(this->geometry().center().x()+5,this->height()-this->height()/4,
                               100,30);
            cnslBtn->setGeometry(this->geometry().center().x()-105,this->height()-this->height()/4,
                                 100,30);
        }
    }
    else
    {
        okBtn->hide();
    }
}

void MessageWindow::setCancelButton(bool checker)
{
    if(checker)
    {
        cnslBtn->show();
        connect(cnslBtn, &QPushButton::clicked,this,&MessageWindow::signalCancel);
        if(okBtn->isHidden())
        {
            cnslBtn->setGeometry(this->geometry().center().x()-50,this->height()-this->height()/4,
                               100,30);
        }
        else
        {
            okBtn->setGeometry(this->geometry().center().x()+5,this->height()-this->height()/4,
                               100,30);
            cnslBtn->setGeometry(this->geometry().center().x()-105,this->height()-this->height()/4,
                                 100,30);
        }
    }
    else
    {
        okBtn->hide();
    }
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
    myBrush.setColor(QColor(50,50,50,240));
    myBrush.setStyle(Qt::SolidPattern);
    myPath.moveTo(0,0);
    myPath.addRoundedRect(QRect(QPoint(1,1),QPoint(this->width()-2,this->height()-2)),10,10);

    drawer->setPen(myPen);
    drawer->setBrush(myBrush);
    drawer->drawPath(myPath);

    myPath.clear();

    myPath.moveTo(0,0);
    myPath.addRoundedRect(QRect(QPoint(1,1),QPoint(this->width()-2,40)),10,10);
    myPen.setColor(QColor(80,80,80));
    myPen.setWidth(1);
    myBrush.setColor(QColor(28,28,28));

    drawer->setPen(myPen);
    drawer->setBrush(myBrush);
    drawer->drawPath(myPath);
    myPen.setColor(QColor(15,15,15));
    drawer->setPen(myPen);
    drawer->drawRect(QRect(QPoint(1,35),QPoint(this->width()-2,40)));

    myPen.setColor(QColor(28,28,28));

    drawer->setPen(myPen);
    drawer->drawRect(QRect(QPoint(2,30),QPoint(this->width()-3,38)));

    myPath.clear();
}

void MessageWindow::signalOk()
{
    emit okPressed(0);
}

void MessageWindow::signalCancel()
{
    emit cnslPressed(0);
}

void MessageWindow::mousePressEvent(QMouseEvent* event)
{
    pressPoint = event->pos();
    isClicked = true;
}

void MessageWindow::mouseMoveEvent(QMouseEvent* event)
{
    if(isClicked &&
        event->modifiers() == Qt::NoModifier &&
        isOnField(event->pos(),QRect(QPoint(10,10),QPoint(this->width()-10,40))))
    {
        this->move(event->globalPosition().x()-pressPoint.x(),event->globalPosition().y()-pressPoint.y());
    }
}

void MessageWindow::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    isClicked = false;
}

bool MessageWindow::isOnField(const QPointF& point, const QRectF& rect)
{
    return (rect.topLeft().x()<point.x() && rect.topLeft().y()<point.y() &&
            rect.bottomRight().x()>point.x() && rect.bottomRight().y()>point.y());
}
