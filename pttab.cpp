#include "pttab.h"

PTtab::PTtab(QMainWindow* parent):
    QLabel(parent)
{
    QFont SFProDisplay("SF Pro Display", 12);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);

    QFontMetrics SFProDislplayMetrics(SFProDisplay);
    infoString = "Unknown Name\nUnknown Surname\nUnknown Rank";

    this->setGeometry(0,80,parent->width()/6,60);

    pixmap.load(":icons/profile_icon.png");
    picture = new QLabel(this);
    picture->setGeometry(15,0,60,60);
    picture->setPixmap(pixmap);
    picture->setScaledContents(true);

    infoText = new QLabel(this);
    infoText->setFont(SFProDisplay);
    infoText->setText(infoString);
    infoText->setStyleSheet("color: rgb(255,255,255);");
    infoText->setGeometry(picture->geometry().topRight().x()+10,(this->height()-SFProDislplayMetrics.height()*3)/2,
                          SFProDislplayMetrics.horizontalAdvance(infoString),SFProDislplayMetrics.height()*3);
}

