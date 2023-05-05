#include "leftpanel.h"

LeftPanel::LeftPanel(DataBase* dataBase,QMainWindow* parent):
    QLabel(parent)
{
    SFProDisplay = QFont("SF Pro Display");
    SFProDisplay.setPixelSize(20);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::DemiBold);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    this->setGeometry(0,50,parent->width()/6,parent->height()-101);

    for(int c=0;c<dataBase->employeeNumbers();c++)
    {
        static int inwCH = 0;
        if(!dataBase->getEmployee(c).vacation())
        {
            PTtab* refer = new PTtab(QString(dataBase->getEmployee(c).name()+"\n"+
                                             dataBase->getEmployee(c).surname()+"\n"+
                                             dataBase->getEmployee(c).rank().rankName()),1,this);
            profilePanelsInWork.push_back(refer);
            profilePanelsInWork[inwCH]->move(0,40+80*inwCH);
            inwCH++;
        }
    }

    inWork = new QPushButton(this);
    inVacation = new QPushButton(this);

    inWork->setFont(SFProDisplay);
    inWork->setStyleSheet("QPushButton {"
                          "background-color: rgba(0,0,0,0);"
                          "color: rgb(200,200,200);"
                          "}"
                          "QPushButton:hover {"
                          "color: rgb(180,180,180);"
                          "}"
                          "QPushButton:pressed {"
                          "color: rgb(150,150,150);"
                          "}");
    inWork->setText("In Work");
    inWork->setGeometry(12,10,SFProDislplayMetrics.horizontalAdvance("In Work"),SFProDislplayMetrics.height());
    connect(inWork,&QPushButton::clicked,this,&LeftPanel::inWorkPressed);

    inVacation->setFont(SFProDisplay);
    inVacation->setStyleSheet("QPushButton {"
                              "background-color: rgba(0,0,0,0);"
                              "color: rgb(200,200,200);"
                              "}"
                              "QPushButton:hover {"
                              "color: rgb(180,180,180);"
                              "}"
                              "QPushButton:pressed {"
                              "color: rgb(150,150,150);"
                              "}");
    inVacation->setText("In Vacation");
    inVacation->setGeometry(14,10 + profilePanelsInWork[profilePanelsInWork.size()-1]->geometry().bottomLeft().y(),
                            SFProDislplayMetrics.horizontalAdvance("In Vacation"),SFProDislplayMetrics.height());
    connect(inVacation,&QPushButton::clicked,this,&LeftPanel::inVacationPressed);

    for(int c=0;c<dataBase->employeeNumbers();c++)
    {
        static int invCH = 0;
        if(dataBase->getEmployee(c).vacation())
        {
            PTtab* refer = new PTtab(QString(dataBase->getEmployee(c).name()+"\n"+
                                             dataBase->getEmployee(c).surname()+"\n"+
                                             dataBase->getEmployee(c).rank().rankName()),1,this);
            profilePanelsInVacation.push_back(refer);
            profilePanelsInVacation[invCH]->move(0,10+inVacation->geometry().bottomRight().y()+80*invCH);
            profilePanelsInVacation[invCH]->hide();
            invCH++;
        }
    }
}

void LeftPanel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter drawer(this);
    doPainting(&drawer);
}

void LeftPanel::doPainting(QPainter* drawer)
{
    drawer->setRenderHint(QPainter::Antialiasing);

    QBrush myBrush;
    QPen myPen;
    QPainterPath myPath;

    //////////Creating left panel triangles//////////

    myPen.setColor(QColor(240,240,240));
    myBrush.setColor(QColor(240,240,240));
    myBrush.setStyle(Qt::SolidPattern);
    drawer->setPen(myPen);
    drawer->setBrush(myBrush);

    if(inWorkClicked)
    {
        myPath.moveTo(inWork->geometry().topRight().x()+11,inWork->geometry().topRight().y()+10);
        myPath.lineTo(inWork->geometry().topRight().x()+20,inWork->geometry().topRight().y()+10);
        myPath.lineTo(inWork->geometry().topRight().x()+15,inWork->geometry().topRight().y()+17);
        myPath.lineTo(inWork->geometry().topRight().x()+10,inWork->geometry().topRight().y()+10);
    }
    else
    {
        myPath.moveTo(inWork->geometry().topRight().x()+12,inWork->geometry().topRight().y()+8);
        myPath.lineTo(inWork->geometry().topRight().x()+19,inWork->geometry().topRight().y()+12);
        myPath.lineTo(inWork->geometry().topRight().x()+12,inWork->geometry().topRight().y()+17);
        myPath.lineTo(inWork->geometry().topRight().x()+12,inWork->geometry().topRight().y()+9);
    }
    drawer->drawPath(myPath);

    myPath.clear();

    if(inVacationClicked)
    {
        myPath.moveTo(inVacation->geometry().topRight().x()+11,inVacation->geometry().topRight().y()+10);
        myPath.lineTo(inVacation->geometry().topRight().x()+20,inVacation->geometry().topRight().y()+10);
        myPath.lineTo(inVacation->geometry().topRight().x()+15,inVacation->geometry().topRight().y()+17);
        myPath.lineTo(inVacation->geometry().topRight().x()+10,inVacation->geometry().topRight().y()+10);
    }
    else
    {
        myPath.moveTo(inVacation->geometry().topRight().x()+12,inVacation->geometry().topRight().y()+8);
        myPath.lineTo(inVacation->geometry().topRight().x()+19,inVacation->geometry().topRight().y()+12);
        myPath.lineTo(inVacation->geometry().topRight().x()+12,inVacation->geometry().topRight().y()+17);
        myPath.lineTo(inVacation->geometry().topRight().x()+12,inVacation->geometry().topRight().y()+9);
    }
    drawer->drawPath(myPath);

    myPath.clear();

    //////////Creating lines near text//////////

    myPen.setColor(QColor(150,150,150,150));
    myPen.setWidth(1);
    myBrush.setColor(QColor(0,0,0,0));
    drawer->setPen(myPen);
    drawer->setBrush(myBrush);
    drawer->drawLine(inWork->geometry().topRight().x()+40,inWork->geometry().topRight().y()+inWork->height()/2,                         //In Work
                     this->width()-20,inWork->geometry().topRight().y()+inWork->height()/2);

    drawer->drawLine(inVacation->geometry().topRight().x()+40,inVacation->geometry().topRight().y()+inVacation->height()/2,             //In Vacation
                     this->width()-20,inVacation->geometry().topRight().y()+inWork->height()/2);

    myPen.setColor(QColor(50,50,50));
    drawer->setPen(myPen);
}

void LeftPanel::mousePressEvent(QMouseEvent* event)
{
    if(isOnField(event->pos(),QRect(0,50,width(),this->height())))
    {
        for(int c=0;c<profilePanelsInWork.size();c++)
        {
            if(isOnField(event->pos(),profilePanelsInWork[c]->geometry()))
            {
                profilePanelsInWork[c]->setSelected(true);
            }
            else{
                profilePanelsInWork[c]->setSelected(false);
            }
            profilePanelsInWork[c]->update();
        }

        for(int c=0;c<profilePanelsInVacation.size();c++)
        {
            if(isOnField(event->pos(),profilePanelsInVacation[c]->geometry()))
            {
                profilePanelsInVacation[c]->setSelected(true);
            }
            else{
                profilePanelsInVacation[c]->setSelected(false);
            }
            profilePanelsInVacation[c]->update();
        }
    }
}

bool LeftPanel::isOnField(const QPointF& point, const QRectF& rect)
{
    return (rect.topLeft().x()<point.x() && rect.topLeft().y()<point.y() &&
            rect.bottomRight().x()>point.x() && rect.bottomRight().y()>point.y());
}

void LeftPanel::inWorkPressed()
{
    if(inWorkClicked){
        inWorkClicked = false;
        for(int c=0;c<profilePanelsInWork.size();c++)
        {
            profilePanelsInWork[c]->hide();
            inVacation->move(12,inWork->geometry().bottomLeft().y()+10);

        }
    }
    else{
        inWorkClicked = true;
        for(int c=0;c<profilePanelsInWork.size();c++)
        {
            profilePanelsInWork[c]->show();
            inVacation->move(12,10 + profilePanelsInWork[profilePanelsInWork.size()-1]->geometry().bottomLeft().y());
        }
    }

    for(int c=0;c<profilePanelsInVacation.size();c++)
    {
        profilePanelsInVacation[c]->move(0,10+inVacation->geometry().bottomRight().y()+80*c);
    }
    this->update();

}

void LeftPanel::inVacationPressed()
{
    if(inVacationClicked){
        inVacationClicked = false;
        for(int c=0;c<profilePanelsInVacation.size();c++)
        {
            profilePanelsInVacation[c]->hide();

        }
    }
    else {
        inVacationClicked = true;
        for(int c=0;c<profilePanelsInVacation.size();c++)
        {
            profilePanelsInVacation[c]->show();

        }
    }
    this->update();
}

