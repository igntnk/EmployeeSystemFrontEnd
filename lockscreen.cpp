#include "lockscreen.h"

LockScreen::LockScreen(DataBase* passwordRefer, QMainWindow* parent):
    QLabel(parent)
{
    QFont SFProDisplay = QFont("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    this->setGeometry(1,50,parent->width()-3,parent->height()-52);

    refer = passwordRefer;

    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(30);
    shadow->setOffset(0,0);
    shadow->setColor(QColor(0,0,0,200));

    pixmap.load(":icons/profile_icon.png");

    picture = new QLabel(this);
    picture->setGeometry(this->width()/2-100,this->height()/7,200,200);
    picture->setScaledContents(true);
    picture->setPixmap(pixmap);
    picture->setGraphicsEffect(shadow);

    username = new WritePanel(this);
    password = new WritePanel(this);

    username->move(picture->geometry().center().x()-username->width()/2,picture->geometry().bottomLeft().y()+30);
    username->setText("Username");
    password->move(username->geometry().topLeft().x(),username->geometry().bottomLeft().y()+20);
    password->setPasswordType(true);
    password->setText("Password");

    enter = new QPushButton(this);
    enter->setStyleSheet("QPushButton {"
                         "background-color: rgb(28, 28, 28);"
                         "color: rgb(100,100,100);"
                         "border: 2px solid rgb(100,100,100);"
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
    enter->setFont(SFProDisplay);
    enter->setText("Enter");
    enter->setGeometry(password->geometry().center().x()-50,password->geometry().bottomLeft().y()+20,
                       100,30);
    connect(enter,&QPushButton::clicked,this,&LockScreen::checkPasswords);

    exit = new QPushButton(this);
    exit->setStyleSheet("QPushButton {"
                        "background-color: rgb(28, 28, 28);"
                        "color: rgb(100,100,100);"
                        "border: 2px solid rgb(60,60,60);"
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
    exit->setFont(SFProDisplay);
    exit->setText("Exit");
    exit->setGeometry(password->geometry().center().x()-50,enter->geometry().bottomLeft().y()+10,
                       100,30);
    connect(exit,&QPushButton::clicked,parent,&QLabel::close);

    wrongPass = new QLabel(this);
    wrongPass->setText("Wrong password or username");
    wrongPass->setFont(SFProDisplay);
    wrongPass->setGeometry(enter->geometry().center().x()-SFProDislplayMetrics.horizontalAdvance("Wrong password or username")/2,
                           exit->geometry().bottomLeft().y()+20,
                           SFProDislplayMetrics.horizontalAdvance("Wrong password or username"),SFProDislplayMetrics.height());
    wrongPass->setStyleSheet("color: rgb(150,150,150)");
    wrongPass->hide();
}

void LockScreen::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter drawer(this);
    doPainting(&drawer);
}

void LockScreen::doPainting(QPainter* drawer)
{
    drawer->setRenderHint(QPainter::Antialiasing);

    QPen myPen;
    QBrush myBrush;
    QPainterPath myPath;

    myPen.setColor(QColor(30,30,30));
    myBrush.setColor(QColor(30,30,30));
    myBrush.setStyle(Qt::SolidPattern);

    myPath.addRoundedRect(0,0,this->width(),this->height(),10,10);

    drawer->setPen(myPen);
    drawer->setBrush(myBrush);
    drawer->drawPath(myPath);

    myPath.clear();

    drawer->drawRect(0,0,this->width(),50);

    myPen.setColor(QColor(10,10,10));
    drawer->setPen(myPen);
    drawer->drawLine(1,1,this->width(),1);
}

void LockScreen::resizeEvent(QResizeEvent *event)
{
    picture->move(this->width()/2-100,this->height()/7);

    username->move(picture->geometry().center().x()-username->width()/2,picture->geometry().bottomLeft().y()+30);
    password->move(username->geometry().topLeft().x(),username->geometry().bottomLeft().y()+20);

    enter->move(password->geometry().center().x()-50,password->geometry().bottomLeft().y()+20);
    exit->move(password->geometry().center().x()-50,enter->geometry().bottomLeft().y()+10);
}

void LockScreen::checkPasswords()
{
    bool pass = false;
    for(int c=0;c<refer->employeesAmount();c++)
    {
        if(username->getText() == refer->employee(c)->username() and password->getText() == refer->employee(c)->password())
        {
            pass = true;
            logginedId = refer->employee(c)->id();
        }
    }

    if(pass)
    {
        this->hide();
    }
    else
    {
        wrongPass->show();
    }
}

int LockScreen::getLogginedId()
{
    return logginedId;
}


