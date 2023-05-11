#include "leftpanel.h"

LeftPanel::LeftPanel(DataBase* dataBase,QMainWindow* parent):
    QLabel(parent),localBase(dataBase)
{
    SFProDisplay = QFont("SF Pro Display");
    SFProDisplay.setPixelSize(20);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::DemiBold);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    this->setGeometry(5,50,parent->width()/6,parent->height()-101);
    this->setMouseTracking(true);

    for(int c=0;c<dataBase->employeeNumbers();c++)
    {
        static int inwCH = 0;
        if(!dataBase->getEmployee(c)->vacation())
        {
            PTtab* refer = new PTtab(QString(dataBase->getEmployee(c)->name()+"\n"+
                                             dataBase->getEmployee(c)->surname()+"\n"+
                                             dataBase->getEmployee(c)->rank().rankName()),1,this);
            profilePanelsInWork.push_back(refer);
            profilePanelsInWork[inwCH]->move(0,40+80*inwCH);
            inWorkNum.push_back(c);
            generalHeight += profilePanelsInWork[inwCH]->height();
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
    inWork->setGeometry(12,10+scrollShift,SFProDislplayMetrics.horizontalAdvance("In Work"),SFProDislplayMetrics.height());
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
    inVacation->setGeometry(14,10 + profilePanelsInWork[profilePanelsInWork.size()-1]->geometry().bottomLeft().y()+scrollShift,
                            SFProDislplayMetrics.horizontalAdvance("In Vacation"),SFProDislplayMetrics.height());
    connect(inVacation,&QPushButton::clicked,this,&LeftPanel::inVacationPressed);

    for(int c=0;c<dataBase->employeeNumbers();c++)
    {
        static int invCH = 0;
        if(dataBase->getEmployee(c)->vacation())
        {
            PTtab* refer = new PTtab(QString(dataBase->getEmployee(c)->name()+"\n"+
                                             dataBase->getEmployee(c)->surname()+"\n"+
                                             dataBase->getEmployee(c)->rank().rankName()),1,this);
            profilePanelsInVacation.push_back(refer);
            profilePanelsInVacation[invCH]->move(0,10+inVacation->geometry().bottomRight().y()+80*invCH+scrollShift);
            profilePanelsInVacation[invCH]->hide();
            inVacNum.push_back(c);
            generalHeight += profilePanelsInVacation[invCH]->height();
            invCH++;
        }
    }

    generalHeight += inWork->height()+inVacation->height()-100;

    if(generalHeight > this->height())
    {
        checkeScroller();
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
                     this->width()-30,inWork->geometry().topRight().y()+inWork->height()/2);

    drawer->drawLine(inVacation->geometry().topRight().x()+40,inVacation->geometry().topRight().y()+inVacation->height()/2,             //In Vacation
                     this->width()-30,inVacation->geometry().topRight().y()+inWork->height()/2);

    myPen.setColor(QColor(30,30,30));
    myBrush.setColor(QColor(30,30,30));
    drawer->setPen(myPen);
    drawer->setBrush(myBrush);

    if(scroller)
    {
        myPath.addRoundedRect(refer,5,5);

        drawer->drawPath(myPath);
    }
}

void LeftPanel::mousePressEvent(QMouseEvent* event)
{
    if(isOnField(event->pos(),QRect(0,50,width(),this->height())))
    {
        for(int c=0;c<profilePanelsInWork.size();c++)
        {
            if(isOnField(event->pos(),profilePanelsInWork[c]->geometry()))
            {
                if(profilePanelsInWork[c]->isHidden())
                {
                    return;
                }
                profilePanelsInWork[c]->setSelected(true);
                selectedNum = inWorkNum[c];
                emit changedSelected(selectedNum);
            }
            else{
                if(profilePanelsInWork[c]->isHidden())
                {
                    return;
                }
                profilePanelsInWork[c]->setSelected(false);
                selectedNum = -1;
            }
            profilePanelsInWork[c]->update();
        }

        for(int c=0;c<profilePanelsInVacation.size();c++)
        {
            if(isOnField(event->pos(),profilePanelsInVacation[c]->geometry()))
            {
                if(profilePanelsInVacation[c]->isHidden())
                {
                    return;
                }
                profilePanelsInVacation[c]->setSelected(true);
                selectedNum = inVacNum[c];
                emit changedSelected(selectedNum);
            }
            else{
                if(profilePanelsInVacation[c]->isHidden())
                {
                    return;
                }
                profilePanelsInVacation[c]->setSelected(false);
                selectedNum = -1;
            }
            profilePanelsInVacation[c]->update();
        }
    }

    if(isOnField(event->pos(),refer) and scroller)
    {
        drag = true;
        pressPoint = event->pos();
        currentScrollerY = refer.topLeft().y();
    }
}

void LeftPanel::mouseMoveEvent(QMouseEvent* event)
{
    if(drag)
    {
        QRect deader =refer;
        refer = QRect(this->width()-20,event->pos().y()-pressPoint.y()+currentScrollerY
                      ,10,this->height()/(generalHeight/this->height())-10);
        if(refer.topLeft().y()<5 or refer.bottomLeft().y()>this->height()-5)
        {
            refer = deader;
        }
        scrollShift = -(refer.topLeft().y()-5);
        scrollEvent();
        this->update();
    }
}

void LeftPanel::mouseReleaseEvent(QMouseEvent* event)
{
    drag = false;
}

bool LeftPanel::isOnField(const QPointF& point, const QRectF& rect)
{
    return (rect.topLeft().x()<point.x() && rect.topLeft().y()<point.y() &&
            rect.bottomRight().x()>point.x() && rect.bottomRight().y()>point.y());
}

void LeftPanel::updateProfilesList()
{
    scrollShift = 0;
    inWork->move(12,10+scrollShift);

    for(int c=0;c<profilePanelsInWork.size();c++)
    {
        generalHeight -= profilePanelsInWork[c]->height();
        delete profilePanelsInWork[c];

    }
    for(int c=0;c<profilePanelsInVacation.size();c++)
    {
        generalHeight -= profilePanelsInVacation[c]->height();
        delete profilePanelsInVacation[c];

    }

    profilePanelsInWork.clear();
    profilePanelsInVacation.clear();
    inWorkNum.clear();
    inVacNum.clear();

    for(int c=0;c<localBase->employeeNumbers();c++)
    {
        static int inwCH = 0;
        if(!localBase->getEmployee(c)->vacation())
        {
            PTtab* refer = new PTtab(QString(localBase->getEmployee(c)->name()+"\n"+
                                             localBase->getEmployee(c)->surname()+"\n"+
                                             localBase->getEmployee(c)->rank().rankName()),1,this);
            profilePanelsInWork.push_back(refer);
            profilePanelsInWork[inwCH]->move(0,40+80*inwCH);
            profilePanelsInWork[inwCH]->show();
            inWorkNum.push_back(c);
            generalHeight += profilePanelsInWork[inwCH]->height();
            inwCH++;
        }
    }

    inVacation->move(12,10 + profilePanelsInWork[profilePanelsInWork.size()-1]->geometry().bottomLeft().y()+scrollShift);

    for(int c=0;c<localBase->employeeNumbers();c++)
    {
        static int invCH = 0;
        if(localBase->getEmployee(c)->vacation())
        {
            PTtab* refer = new PTtab(QString(localBase->getEmployee(c)->name()+"\n"+
                                             localBase->getEmployee(c)->surname()+"\n"+
                                             localBase->getEmployee(c)->rank().rankName()),1,this);
            profilePanelsInVacation.push_back(refer);
            profilePanelsInVacation[invCH]->move(0,10+inVacation->geometry().bottomRight().y()+80*invCH+scrollShift);
            profilePanelsInVacation[invCH]->show();
            inVacNum.push_back(c);
            generalHeight += profilePanelsInVacation[invCH]->height();
            invCH++;
        }
    }
    checkeScroller();
}

void LeftPanel::inWorkPressed()
{
    if(inWorkClicked){
        inWorkClicked = false;
        for(int c=0;c<profilePanelsInWork.size();c++)
        {
            profilePanelsInWork[c]->hide();
            generalHeight -=profilePanelsInWork[c]->height();
            inVacation->move(12,inWork->geometry().bottomLeft().y()+10+scrollShift);
        }
    }
    else{
        inWorkClicked = true;
        for(int c=0;c<profilePanelsInWork.size();c++)
        {
            profilePanelsInWork[c]->show();
            generalHeight +=profilePanelsInWork[c]->height();
            inVacation->move(12,10 + profilePanelsInWork[profilePanelsInWork.size()-1]->geometry().bottomLeft().y()+scrollShift);
        }
    }

    checkeScroller();

    for(int c=0;c<profilePanelsInVacation.size();c++)
    {
        profilePanelsInVacation[c]->move(0,10+inVacation->geometry().bottomRight().y()+80*c+scrollShift);
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
            generalHeight -=profilePanelsInVacation[c]->height();
        }
    }
    else {
        inVacationClicked = true;
        for(int c=0;c<profilePanelsInVacation.size();c++)
        {
            profilePanelsInVacation[c]->show();
            generalHeight +=profilePanelsInVacation[c]->height();
        }
    }

    checkeScroller();
    this->update();
}

void LeftPanel::checkeScroller()
{
    if(generalHeight > this->height())
    {
        scroller = true;
        for(int c=0;c<profilePanelsInVacation.size();c++)
        {
            profilePanelsInVacation[c]->resizeByScroller(scroller, this->geometry());
        }
        for(int c=0;c<profilePanelsInWork.size();c++)
        {
            profilePanelsInWork[c]->resizeByScroller(scroller, this->geometry());
        }
    }
    else
    {
        scroller = false;

        for(int c=0;c<profilePanelsInVacation.size();c++)
        {
            profilePanelsInVacation[c]->resizeByScroller(scroller, this->geometry());
        }
        for(int c=0;c<profilePanelsInWork.size();c++)
        {
            profilePanelsInWork[c]->resizeByScroller(scroller, this->geometry());
        }
    }

    if(!scroller)
    {
        scrollShift = 0;
        inWork->move(12,10+scrollShift);
        if(inWorkClicked)
        {
            inVacation->move(14,10 + profilePanelsInWork[profilePanelsInWork.size()-1]->geometry().bottomLeft().y()+scrollShift);
        }

        for(int c=0;c<profilePanelsInWork.size();c++)
        {
            profilePanelsInWork[c]->move(0,40+80*c+scrollShift);
        }
        for(int c=0;c<profilePanelsInVacation.size();c++)
        {
            profilePanelsInVacation[c]->move(0,10+inVacation->geometry().bottomRight().y()+80*c);

        }
    }

    refer = QRect(this->width()-20,5,10,this->height()/(generalHeight/this->height())-10);
}

void LeftPanel::scrollEvent()
{
    for(int c=0;c<profilePanelsInWork.size();c++)
    {
        profilePanelsInWork[c]->move(0,40+80*c+scrollShift);
    }

    inWork->move(12,10+scrollShift);

    inVacation->move(14,10 + profilePanelsInWork[profilePanelsInWork.size()-1]->geometry().bottomLeft().y());

    for(int c=0;c<profilePanelsInVacation.size();c++)
    {
        profilePanelsInVacation[c]->move(0,10+inVacation->geometry().bottomRight().y()+80*c);

    }
}

void LeftPanel::resizePanel()
{
    for(int c=0;c<profilePanelsInVacation.size();c++)
    {
        profilePanelsInVacation[c]->resizeByScroller(scroller, this->geometry());
    }
    for(int c=0;c<profilePanelsInWork.size();c++)
    {
        profilePanelsInWork[c]->resizeByScroller(scroller, this->geometry());
    }
    checkeScroller();
}

int LeftPanel::getSelectedPanelNum()
{
    return selectedNum;
}


