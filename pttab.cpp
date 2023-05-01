#include "pttab.h"

PTtab::PTtab(QString text,int choice,QMainWindow* parent):
    infoString(text),QLabel(parent)
{
    SFProDisplay = QFont("SF Pro Display", 12);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    this->setGeometry(0,80,parent->width()/6,60);

    infoText = new QLabel(this);
    infoText->setText(infoString);
    infoText->setStyleSheet("color: rgb(200,200,200);");
    infoText->setFont(SFProDisplay);
    picture = new QLabel(this);
    picture->setGeometry(15,0,60,60);
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


