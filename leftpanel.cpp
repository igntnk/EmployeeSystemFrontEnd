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

    for(int c=0;c<dataBase->employeesAmount();c++)
    {
        bool contVac =false;
        static int d=-1;
        for(int a=0;a<dataBase->vacationsAmount();a++)
        {
            if(dataBase->employee(c)->id() == dataBase->vacation(a)->employee()->id() and
                dataBase->vacation(a)->endDate() > QDate::currentDate())
            {
                contVac=true;
            }
        }
        if(contVac){continue;}
        d++;
        PTtab* refer = new PTtab(QString(dataBase->employee(c)->name()+"\n"+
                                         dataBase->employee(c)->surname()+"\n"+
                                         dataBase->employee(c)->rank()->name()),1,this);
        profilePanelsInWork.push_back(refer);
        profilePanelsInWork[d]->move(0,40+80*d);
        inWorkNum.push_back(dataBase->employee(c)->id());
        generalHeight += profilePanelsInWork[d]->height();
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

    for(int c=0;c<dataBase->employeesAmount();c++)
    {
        bool contVac =true;
        static int d=-1;
        for(int a=0;a<dataBase->vacationsAmount();a++)
        {
            if(dataBase->employee(c)->id() == dataBase->vacation(a)->employee()->id() and
                dataBase->vacation(a)->endDate() > QDate::currentDate())
            {
                contVac=false;
                d++;
            }
        }
        if(contVac){continue;}
        PTtab* refer = new PTtab(QString(dataBase->employee(c)->name()+"\n"+
                                         dataBase->employee(c)->surname()+"\n"+
                                         dataBase->employee(c)->rank()->name()),1,this);
        profilePanelsInVacation.push_back(refer);
        profilePanelsInVacation[d]->move(0,10+inVacation->geometry().bottomRight().y()+80*d+scrollShift);
        profilePanelsInVacation[d]->hide();
        inVacNum.push_back(dataBase->employee(c)->id());
        generalHeight += profilePanelsInVacation[d]->height();
    }

    generalHeight += inWork->height()+inVacation->height();

    if(generalHeight > this->height())
    {
        checkScroller();
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
    setDrag(event);

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
            }
            profilePanelsInVacation[c]->update();
        }
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
        scrollShift = -(refer.topLeft().y()*(generalHeight/this->height())-5);
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

    Employee* refEm = localBase->employee(localBase->employeesAmount()-1);
    referPT = new PTtab(QString(refEm->name()+"\n"+
                                     refEm->surname()+"\n"+
                                     refEm->rank()->name()),1,this);

    if(localBase->employeesAmount() > profilePanelsInVacation.size()+profilePanelsInWork.size())
    {
        profilePanelsInWork.push_back(referPT);
        for(int c=0;c<profilePanelsInWork.size();c++)
        {
            profilePanelsInWork[c]->move(0,40+80*c);
        }
        profilePanelsInWork[profilePanelsInWork.size()-1]->show();
        inWorkNum.push_back(refEm->id());
        generalHeight += profilePanelsInWork[0]->height();
    }
    else
    {
        for(int c=0;c<inWorkNum.size();c++)
        {
            if(inWorkNum[c] == selectedNum)
            {
                inWorkNum.erase(inWorkNum.begin()+c);
                delete profilePanelsInWork[c];
                generalHeight -= profilePanelsInWork[0]->height();
                profilePanelsInWork.erase(profilePanelsInWork.begin()+c);
            }
        }
        for(int c=0;c<inVacNum.size();c++)
        {
            if(inVacNum[c] == selectedNum)
            {
                inVacNum.erase(inVacNum.begin()+c);
                delete profilePanelsInVacation[c];
                generalHeight -= profilePanelsInVacation[0]->height();
                profilePanelsInVacation.erase(profilePanelsInVacation.begin()+c);
            }
        }
        for(int a =0;a<inVacNum.size();a++){if(inVacNum[a]>selectedNum){--inVacNum[a];}}
        for(int a =0;a<inWorkNum.size();a++){if(inWorkNum[a]>selectedNum){--inWorkNum[a];}}

        for(int c=0;c<profilePanelsInWork.size();c++)
        {
            profilePanelsInWork[c]->move(0,40+80*c);
        }

        for(int c=0;c<profilePanelsInVacation.size();c++)
        {
            profilePanelsInVacation[c]->move(0,40+80*c);
        }
    }

    inVacation->move(12,10 + profilePanelsInWork[profilePanelsInWork.size()-1]->geometry().bottomLeft().y());

    for(int c=0;c<profilePanelsInVacation.size();c++)
    {
        profilePanelsInVacation[c]->move(0,10+inVacation->geometry().bottomRight().y()+80*c+scrollShift);
    }
    this->update();

    checkScroller();
}

void LeftPanel::inWorkPressed()
{
    if(inWorkClicked){
        inWorkClicked = false;
        for(int c=0;c<profilePanelsInWork.size();c++)
        {
            profilePanelsInWork[c]->hide();
            generalHeight -=profilePanelsInWork[c]->height();
        }

        inVacation->move(inWork->geometry().topLeft().x(),inWork->geometry().bottomLeft().y()+10+scrollShift);
    }
    else{
        inWorkClicked = true;
        for(int c=0;c<profilePanelsInWork.size();c++)
        {
            profilePanelsInWork[c]->show();
            generalHeight +=profilePanelsInWork[c]->height();
        }
        inVacation->move(inWork->geometry().topLeft().x(),10 + profilePanelsInWork[profilePanelsInWork.size()-1]->geometry().bottomLeft().y()+scrollShift);
    }

    for(int c=0;c<profilePanelsInVacation.size();c++)
    {
        profilePanelsInVacation[c]->move(0,10+inVacation->geometry().bottomRight().y()+80*c+scrollShift);
    }

    checkScroller();
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

    checkScroller();

    this->update();
}

void LeftPanel::checkScroller()
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
        inWork->move(12,10);

        for(int c=0;c<profilePanelsInWork.size();c++)
        {
            profilePanelsInWork[c]->move(0,40+80*c+scrollShift);
        }

        if(inWorkClicked)
        {
            inVacation->move(inWork->geometry().topLeft().x(),10 + profilePanelsInWork[profilePanelsInWork.size()-1]->geometry().bottomLeft().y()+scrollShift);
        }
        else
        {
            inVacation->move(inWork->geometry().topLeft().x(),10+inWork->geometry().bottomLeft().y());
        }

        for(int c=0;c<profilePanelsInVacation.size();c++)
        {
            profilePanelsInVacation[c]->move(0,10+inVacation->geometry().bottomRight().y()+80*c);

        }
    }

    refer = QRect(this->width()-20,5,10,this->height()/(generalHeight/this->height())-10);
}

void LeftPanel::setDrag(QMouseEvent* event)
{
    if(isOnField(event->pos(),refer) and scroller)
    {
        drag = true;
        pressPoint = event->pos();
        currentScrollerY = refer.topLeft().y();
    }
}

void LeftPanel::scrollEvent()
{
    for(int c=0;c<profilePanelsInWork.size();c++)
    {
        if(!profilePanelsInWork[c]->isHidden())
        {
            profilePanelsInWork[c]->move(0,40+80*c+scrollShift);
        }
    }

    inWork->move(12,10+scrollShift);

    if(!profilePanelsInWork[0]->isHidden())
    {
        inVacation->move(14,10 + profilePanelsInWork[profilePanelsInWork.size()-1]->geometry().bottomLeft().y());
    }
    else
    {
        inVacation->move(14,10 + inWork->geometry().bottomLeft().y());
    }

    for(int c=0;c<profilePanelsInVacation.size();c++)
    {
        if(!profilePanelsInVacation[c]->isHidden())
        {
            profilePanelsInVacation[c]->move(0,10+inVacation->geometry().bottomRight().y()+80*c);
        }
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
    checkScroller();
}

int LeftPanel::getSelectedPanelNum()
{
    return selectedNum;
}


