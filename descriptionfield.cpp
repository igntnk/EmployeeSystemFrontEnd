
#include "descriptionfield.h"

DescriptionField::DescriptionField(DataBase* base, QMainWindow* parent):
    QLabel(parent), referBase(base)
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
    profilePict->hide();

    SFProDisplay.setPixelSize(30);
    SFProDislplayMetrics = QFontMetrics(SFProDisplay);

    chapters = new QLabel(this);
    chapters->setFont(SFProDisplay);
    chapters->setText("Name:\nSurname:\nLast Name:\nRank:");
    chapters->setAlignment(Qt::AlignRight);
    chapters->setGeometry(profilePict->geometry().topRight().x()+mainProfileInfoShift,
                                 profilePict->geometry().topRight().y()+(profilePict->height()-SFProDislplayMetrics.height()*4)/2,
                                 SFProDislplayMetrics.horizontalAdvance("Last Name: "),SFProDislplayMetrics.height()*4);
    chapters->setStyleSheet("color: rgb(130,130,130);");
    chapters->hide();

    profileInfo = new QLabel(this);
    profileInfo->hide();

    chapter1 = new QLabel(this);
    chapter1->setFont(SFProDisplay);
    chapter1->setText("Task Decription");
    chapter1->setGeometry(pictureShift,chapter1Shift,
                          SFProDislplayMetrics.horizontalAdvance("Task Description"),SFProDislplayMetrics.height());
    chapter1->setStyleSheet("color: rgb(130,130,130);");
    chapter1->hide();

    chapter2 = new QLabel(this);
    chapter2->setFont(SFProDisplay);
    chapter2->setText("Employment Date");
    chapter2->setGeometry(pictureShift,this->height()-this->height()/5,
                          SFProDislplayMetrics.horizontalAdvance("Employment Date"),SFProDislplayMetrics.height());
    chapter2->setStyleSheet("color: rgb(130,130,130);");
    chapter2->hide();

    SFProDislplayMetrics = QFontMetrics(SFProDisplay);

    taskDescription = new QLabel(this);
    taskDescription->setStyleSheet("color: rgb(80,80,80);");
    taskDescription->hide();

    employmentDate = new QLabel(this);
    employmentDate->setStyleSheet("color: rgb(80,80,80);");
    employmentDate->hide();

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

    if(isProfileSelected)
    {
        drawer->drawLine(chapter1->geometry().topRight().x()+lineShift,chapter1->geometry().topRight().y()+chapter1->height()/2+2,                 //Task description
                         this->width()-lineShift,chapter1->geometry().topRight().y()+chapter1->height()/2+2);

        drawer->drawLine(chapter2->geometry().topRight().x()+lineShift,chapter2->geometry().topRight().y()+chapter2->height()/2+2,                 //Employment Date
                         this->width()-lineShift,chapter2->geometry().topRight().y()+chapter2->height()/2+2);
    }
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

void DescriptionField::setSelectedNum(int number)
{
    selectedNum = number;
    setVisibility(true);
    setInfo();
    setDescription();
    setEmploymentDate();
}

void DescriptionField::changeDesc(int number)
{

    taskDescription->setText(referBase->employee(selectedNum)->task(number)->description());
}

void DescriptionField::resize(QMainWindow* changed)
{
    this->setGeometry(changed->width()/6,topBarHeight,changed->width()/3*2,changed->height()-topBarHeight*2);

    chapter1->move(pictureShift,chapter1Shift);
    chapter2->move(pictureShift,this->height()-this->height()/5);
    employmentDate->move(chapter2->geometry().bottomLeft().x(), chapter2->geometry().bottomLeft().y()+20);
}

void DescriptionField::setInfo()
{
    if(selectedNum == -1)
    {
        return;
    }

    SFProDisplay.setPixelSize(30);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    QString info = referBase->employee(selectedNum)->name() + '\n' + referBase->employee(selectedNum)->surname()
                   + '\n' + referBase->employee(selectedNum)->rank()->name();
    profileInfo->setText(info);
    profileInfo->setFont(SFProDisplay);
    profileInfo->setGeometry(chapters->geometry().topRight().x()+20,
                             chapters->geometry().topRight().y(),
                             SFProDislplayMetrics.horizontalAdvance(searchLongestWord(referBase->employee(selectedNum))),SFProDislplayMetrics.height()*4);
    profileInfo->setStyleSheet("color: rgb(130,130,130);");
}

void DescriptionField::setDescription()
{
    if(selectedNum == -1)
    {
        return;
    }

    SFProDisplay.setPixelSize(18);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    taskDescription->setText(referBase->employee(selectedNum)->task(0)->description());
    taskDescription->setFont(SFProDisplay);
    taskDescription->setGeometry(chapter1->geometry().bottomLeft().x(), chapter1->geometry().bottomLeft().y()+20,
                                 SFProDislplayMetrics.horizontalAdvance(referBase->employee(selectedNum)->task(0)->description()),SFProDislplayMetrics.height());
}

void DescriptionField::setEmploymentDate()
{
    if(selectedNum == -1)
    {
        return;
    }

    SFProDisplay.setPixelSize(25);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    employmentDate->setText(referBase->employee(selectedNum)->hireDate().toString());
    employmentDate->setFont(SFProDisplay);
    employmentDate->setGeometry(chapter2->geometry().bottomLeft().x(), chapter2->geometry().bottomLeft().y()+20,
                                SFProDislplayMetrics.horizontalAdvance(referBase->employee(selectedNum)->hireDate().toString()),SFProDislplayMetrics.height());
}

QString DescriptionField::searchLongestWord(Employee* refer)
{
    QString longest = refer->name();

    if(longest.length() < refer->surname().length()){longest = refer->surname();}
    if(longest.length() < refer->rank()->name().length()){longest = refer->rank()->name();}

    return longest;
}

void DescriptionField::setVisibility(bool choice)
{
    isProfileSelected = choice;

    if(isProfileSelected)
    {
        profilePict->show();
        chapters->show();
        profileInfo->show();
        chapter1->show();
        chapter2->show();
        taskDescription->show();
        employmentDate->show();
    }
    else
    {
        profilePict->hide();
        chapters->hide();
        profileInfo->hide();
        chapter1->hide();
        chapter2->hide();
        taskDescription->hide();
        employmentDate->hide();
    }
    this->update();
}
