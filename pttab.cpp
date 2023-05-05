#include "pttab.h"

PTtab::PTtab(QString text,int choice,QLabel* parent):
    infoString(text),QLabel(parent)
{
    SFProDisplay = QFont("SF Pro Display", 12);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    this->setGeometry(0,80,parent->width(),80);

    infoText = new QLabel(this);
    infoText->setText(infoString);
    infoText->setStyleSheet("color: rgb(200,200,200);");
    infoText->setFont(SFProDisplay);
    picture = new QLabel(this);
    picture->setGeometry(10,10,60,60);
    picture->setScaledContents(true);

    if(choice)
    {
        pixmap.load(":icons/profile_icon.png");
        picture->setPixmap(pixmap);
        infoText->setGeometry(picture->geometry().topRight().x()+10,(this->height()-SFProDislplayMetrics.height()*3)/2,
                              SFProDislplayMetrics.horizontalAdvance(infoString),SFProDislplayMetrics.height()*3);
    }
    else
    {
        pixmap.load(":icons/devices_icon.png");
        picture->setPixmap(pixmap);
        infoText->setGeometry(picture->geometry().topRight().x()+10,(this->height()-SFProDislplayMetrics.height()*2)/2,
                              SFProDislplayMetrics.horizontalAdvance(infoString),SFProDislplayMetrics.height()*2);
    }

}

PTtab::~PTtab()
{

}

void PTtab::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter drawer(this);
    doPainting(&drawer);
}

void PTtab::doPainting(QPainter* drawer)
{
    drawer->setRenderHint(QPainter::Antialiasing);

    QPen myPen;
    QBrush myBrush;

    myPen.setColor(QColor(255,255,255,0));
    myBrush.setColor(QColor(255,255,255,30));
    myBrush.setStyle(Qt::SolidPattern);

    if(isSelected)
    {
        drawer->setPen(myPen);
        drawer->setBrush(myBrush);

        drawer->drawRect(1,1,this->width()-2,this->height()-2);
    }
}


void PTtab::setPicture(int choice)
{
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    if(choice){
        pixmap.load(":icons/profile_icon.png");
        picture->setPixmap(pixmap);
        infoString = "Unknown Name\nUnknown Surname\nUnknown Rank";
        infoText->setText(infoString);
        infoText->setGeometry(picture->geometry().topRight().x()+10,(this->height()-SFProDislplayMetrics.height()*3)/2,
                              SFProDislplayMetrics.horizontalAdvance(infoString),SFProDislplayMetrics.height()*3);
    }
    else{
        pixmap.load(":icons/devices_icon.png");
        picture->setPixmap(pixmap);
        infoString = "Unknown Task\nUnknown Task Responsible;";
        infoText->setText(infoString);
        infoText->setGeometry(picture->geometry().topRight().x()+10,(this->height()-SFProDislplayMetrics.height()*2)/2,
                              SFProDislplayMetrics.horizontalAdvance(infoString),SFProDislplayMetrics.height()*2);
    }
}

void PTtab::setPicture(QString file)
{
    pixmap.load(":icons/devices_icon.png");
    picture->setPixmap(pixmap);
}

void PTtab::setText(const QString& text, int rowsNum)
{
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    infoString = text;
    infoText->setGeometry(picture->geometry().topRight().x()+10,(this->height()-SFProDislplayMetrics.height()*rowsNum)/2,
                          SFProDislplayMetrics.horizontalAdvance(infoString),SFProDislplayMetrics.height()*rowsNum);
}

void PTtab::setSelected(bool choice)
{
    isSelected = choice;
}

