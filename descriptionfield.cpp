
#include "descriptionfield.h"

DescriptionField::DescriptionField(QMainWindow* parent):
    QLabel(parent)
{
    initShifts();

    this->setGeometry(parent->width()/6,topBarHeight,parent->width()/3*2,parent->height()-topBarHeight*2);

    SFProDisplay = QFont("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(30);
    shadow->setOffset(0,0);
    shadow->setColor(QColor(0,0,0,200));

    profilePix.load(":icons/profile_icon.png");
    profilePict = new QLabel(this);
    profilePict->setScaledContents(true);
    profilePict->setGeometry(pictureShift,pictureShift,pictureSideSize,pictureSideSize);
    profilePict->setPixmap(profilePix);
    profilePict->setGraphicsEffect(shadow);

    SFProDisplay.setPixelSize(30);
    SFProDislplayMetrics = QFontMetrics(SFProDisplay);

    mainProfileInfo = new QLabel(this);
    mainProfileInfo->setFont(SFProDisplay);
    mainProfileInfo->setText("Name:\nSurname:\nLast Name:\nRank:");
    mainProfileInfo->setAlignment(Qt::AlignRight);
    mainProfileInfo->setGeometry(profilePict->geometry().topRight().x()+mainProfileInfoShift,
                                 profilePict->geometry().topRight().y()+(profilePict->height()-SFProDislplayMetrics.height()*4)/2,
                                 SFProDislplayMetrics.horizontalAdvance("Last Name: "),SFProDislplayMetrics.height()*4);
    mainProfileInfo->setStyleSheet("color: rgb(130,130,130);");

    chapter1 = new QLabel(this);
    chapter1->setFont(SFProDisplay);
    chapter1->setText("Task Decription");
    chapter1->setGeometry(pictureShift,chapter1Shift,
                          SFProDislplayMetrics.horizontalAdvance("Task Description"),SFProDislplayMetrics.height());
    chapter1->setStyleSheet("color: rgb(130,130,130);");

    chapter2 = new QLabel(this);
    chapter2->setFont(SFProDisplay);
    chapter2->setText("Employment Date");
    chapter2->setGeometry(pictureShift,this->height()-this->height()/5,
                          SFProDislplayMetrics.horizontalAdvance("Employment Date"),SFProDislplayMetrics.height());
    chapter2->setStyleSheet("color: rgb(130,130,130);");

}

void DescriptionField::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter drawer(this);
    doPainting(&drawer);
}

void DescriptionField::doPainting(QPainter* drawer)
{
    QPen myPen;
    QBrush myBrush;

    myPen.setColor(QColor(10,10,10));
    myPen.setWidth(1);
    myBrush.setColor(QColor(28,28,28));
    myBrush.setStyle(Qt::SolidPattern);

    drawer->setPen(myPen);
    drawer->setBrush(myBrush);
    drawer->drawRect(0,0,this->width()-1,this->height()-1);

    myPen.setColor(QColor(50,50,50));
    myPen.setWidth(2);
    drawer->setPen(myPen);

    drawer->drawLine(chapter1->geometry().topRight().x()+lineShift,chapter1->geometry().topRight().y()+chapter1->height()/2+2,                 //Task description
                     this->width()-lineShift,chapter1->geometry().topRight().y()+chapter1->height()/2+2);

    drawer->drawLine(chapter2->geometry().topRight().x()+lineShift,chapter2->geometry().topRight().y()+chapter2->height()/2+2,                 //Employment Date
                     this->width()-lineShift,chapter2->geometry().topRight().y()+chapter2->height()/2+2);
}

void DescriptionField::initShifts()
{
    pictureShift = 40;
    pictureSideSize = 200;
    mainProfileInfoShift = 30;
    chapter1Shift = 300;
    lineShift = 50;
    topBarHeight = 50;
}

void DescriptionField::resize(QMainWindow* changed)
{
    this->setGeometry(changed->width()/6,topBarHeight,changed->width()/3*2,changed->height()-topBarHeight*2);

    chapter1->move(pictureShift,chapter1Shift);
    chapter2->move(pictureShift,this->height()-this->height()/5);
}

