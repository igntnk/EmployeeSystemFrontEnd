#include "pttab.h"

PTtab::PTtab(QString text,int choice,QLabel* parent):
    infoString(text),QLabel(parent)
{
    SFProDisplay = QFont("SF Pro Display", 12);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    this->setGeometry(0,80,parent->width(),80);
    this->setMouseTracking(true);

    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(30);
    shadow->setOffset(0,0);
    shadow->setColor(QColor(0,0,0,60));

    infoText = new QLabel(this);
    infoText->setText(infoString);
    infoText->setStyleSheet("color: rgb(200,200,200);");
    infoText->setFont(SFProDisplay);
    picture = new QLabel(this);
    picture->setGeometry(10,10,60,60);
    picture->setScaledContents(true);
    picture->setMouseTracking(true);
    picture->setGraphicsEffect(shadow);

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
        infoText->setGeometry(picture->geometry().topRight().x()+10,(this->height()-SFProDislplayMetrics.height()*3)/2,
                              SFProDislplayMetrics.horizontalAdvance(infoString),SFProDislplayMetrics.height()*3);
        ifTaskPanel = true;
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
    QPainterPath myPath;

    myPen.setColor(QColor(255,255,255,0));
    myBrush.setColor(QColor(255,255,255,30));
    myBrush.setStyle(Qt::SolidPattern);

    if(isSelected)
    {
        drawer->setPen(myPen);
        drawer->setBrush(myBrush);

        drawer->drawRect(1,1,this->width()-2,this->height()-2);
    }

    if(ifTaskPanel and !lostTask and m_completeStage != 3)
    {
        myPen.setColor(QColor(152+(220-152)*pow(percentLine,2), 251-(251-20)*pow(percentLine,2), 152-(152-60)*pow(percentLine,2)));
        myPen.setWidth(3);
        drawer->setPen(myPen);
        drawer->drawLine(20,77,(this->width()-20)*percentLine,77);
    }
    else if(ifTaskPanel and lostTask and m_completeStage != 3)
    {
        myBrush.setColor(QColor(220, 20, 60,40));
        myPen.setColor(QColor(255,255,255,0));
        myPen.setWidth(3);
        drawer->setPen(myPen);
        drawer->setBrush(myBrush);
        drawer->drawRect(0,0,this->width(),this->height());
    }
    if(m_completeStage == 0)
    {
        myPen.setColor(QColor(120,120,120));
        myPen.setWidth(2);
        myBrush.setColor(QColor(0, 0, 0,0));
        drawer->setPen(myPen);
        drawer->setBrush(myBrush);
        myPath.moveTo(picture->geometry().bottomRight().x()-7,picture->geometry().bottomRight().y()-5);
        myPath.lineTo(picture->geometry().bottomRight().x()-4,picture->geometry().bottomRight().y()-2);
        myPath.lineTo(picture->geometry().bottomRight().x()+4,picture->geometry().bottomRight().y()-10);
        drawer->drawPath(myPath);
    }
    if(m_completeStage == 1)
    {
        myPen.setColor(QColor(150,150,150));
        myPen.setWidth(2);
        myBrush.setColor(QColor(0, 0, 0,0));
        drawer->setPen(myPen);
        drawer->setBrush(myBrush);
        myPath.moveTo(picture->geometry().bottomRight().x()-7,picture->geometry().bottomRight().y()-5);
        myPath.lineTo(picture->geometry().bottomRight().x()-4,picture->geometry().bottomRight().y()-2);
        myPath.lineTo(picture->geometry().bottomRight().x()+4,picture->geometry().bottomRight().y()-10);
        myPath.moveTo(picture->geometry().bottomRight().x()+1,picture->geometry().bottomRight().y()-2);
        myPath.lineTo(picture->geometry().bottomRight().x()+9,picture->geometry().bottomRight().y()-10);
        drawer->drawPath(myPath);
    }
    if(m_completeStage == 2)
    {
        myPen.setColor(QColor(150,150,150));
        myPen.setWidth(2);
        myBrush.setColor(QColor(0, 0, 0,0));
        drawer->setPen(myPen);
        drawer->setBrush(myBrush);
        drawer->drawEllipse(picture->geometry().bottomRight().x()-8,picture->geometry().bottomRight().y()-10,
                          14,14);
        myPen.setWidth(1);
        drawer->setPen(myPen);
        myPath.moveTo(picture->geometry().bottomRight().x()-1,picture->geometry().bottomRight().y()-7);
        myPath.lineTo(picture->geometry().bottomRight().x()-1,picture->geometry().bottomRight().y()-2);
        myPath.lineTo(picture->geometry().bottomRight().x()+2,picture->geometry().bottomRight().y()-2);
        drawer->drawPath(myPath);
    }
    if(m_completeStage == 3)
    {
        myPen.setColor(QColor(123, 166, 101));
        myPen.setWidth(3);
        myBrush.setColor(QColor(0, 0, 0,0));
        drawer->setPen(myPen);
        drawer->setBrush(myBrush);

        myPath.moveTo(picture->geometry().bottomRight().x()-7,picture->geometry().bottomRight().y()-5);
        myPath.lineTo(picture->geometry().bottomRight().x()-4,picture->geometry().bottomRight().y()-2);
        myPath.lineTo(picture->geometry().bottomRight().x()+4,picture->geometry().bottomRight().y()-10);
        drawer->drawPath(myPath);

    }
}

QDate PTtab::deadLine() const
{
    return m_deadLine;
}

void PTtab::setCompleteStage(int stage)
{
    m_completeStage  = stage;
}

int PTtab::completeStage()
{
    return m_completeStage;
}

void PTtab::setDeadLine(QDate newDeadLine)
{
    m_deadLine = newDeadLine;
}


void PTtab::setPicture(int choice)
{
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
        infoString = "Unknown Task\nUnknown Task Responsible;";
        infoText->setText(infoString);
        infoText->setGeometry(picture->geometry().topRight().x()+10,(this->height()-SFProDislplayMetrics.height()*3)/2,
                              SFProDislplayMetrics.horizontalAdvance(infoString),SFProDislplayMetrics.height()*3);
        ifTaskPanel = true;
    }
}

void PTtab::setPicture(QString file)
{
    pixmap.load(file);
    picture->setPixmap(pixmap);
}

void PTtab::setPText(const QString& text, int rowsNum)
{
    infoString = text;
    infoText->setText(infoString);
    infoText->setGeometry(picture->geometry().topRight().x()+10,(this->height()-SFProDislplayMetrics.height()*rowsNum)/2,
                          SFProDislplayMetrics.horizontalAdvance(infoString)+20,SFProDislplayMetrics.height()*rowsNum);
}

void PTtab::setSelected(bool choice)
{
    isSelected = choice;
}

void PTtab::resizeByScroller(bool choice , QRect globalRect)
{
    if(choice)
    {

        this->setGeometry(this->geometry().x(),this->geometry().y(),globalRect.width()-25,80);

    }
    else
    {
        this->setGeometry(this->geometry().x(),this->geometry().y(),globalRect.width(),80);

    }

}

void PTtab::setDateLine(float percentage)
{
    percentLine = percentage;
}

void PTtab::setUndone(bool choice)
{
    lostTask = choice;
}
