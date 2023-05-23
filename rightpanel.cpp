#include "rightpanel.h"

RightPanel::RightPanel(DataBase* refer,int number, QMainWindow *parent):
    QLabel(parent)
{
    SFProDisplay = QFont("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);

    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    parentSize = parent->geometry();
    this->setGeometry(parent->width()-parent->width()/6-2,50,parent->width()/6,parent->height()-101);
    this->setMouseTracking(true);
    selectedEm->setId(-1);
    referBase = refer;

    employeeTasks = new QLabel(this);
    employeeTasks->setText("Employee Tasks");
    employeeTasks->setFont(SFProDisplay);
    employeeTasks->setGeometry(12,10,
                               SFProDislplayMetrics.horizontalAdvance("Employee Tasks"),SFProDislplayMetrics.height());
    employeeTasks->setStyleSheet("color: rgb(200,200,200);");

    taskToAdd = new QLabel(this);
    taskToAdd->setText("Task(s) to Add");
    taskToAdd->setFont(SFProDisplay);
    taskToAdd->hide();
    taskToAdd->setStyleSheet("color: rgb(200,200,200);");

    addTaskToEmployee = new QPushButton(this);
    addTaskToEmployee->setStyleSheet("QPushButton {"
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
    addTaskToEmployee->setText("Add Task to Employee");
    addTaskToEmployee->setFont(SFProDisplay);
    addTaskToEmployee->resize(200,30);
    addTaskToEmployee->move((this->width()-addTaskToEmployee->width())/2,this->height()-50);

    addTaskBtn = new QPushButton(this);
    cancelAddBtn = new QPushButton(this);
    addTaskBtn->hide();
    cancelAddBtn->hide();

    connect(addTaskToEmployee,&QPushButton::clicked,this,&RightPanel::setAddTaskMode);

    generalHeight += taskToAdd->height()+80;

}

void RightPanel::resize()
{
    double panelHeight;
    double differenceKoef;

    for(int c=0;c<taskPanels.size();c++)
    {
        taskPanels[c]->resizeByScroller(false, this->geometry());
        panelHeight = this->height()-employeeTasks->geometry().bottomLeft().y()-selectedEm->tasksAmount()*taskPanels[0]->height()-4;
        differenceKoef = panelHeight/generalHeight;

        scrollerRect = QRect(this->width()-20,employeeTasks->geometry().bottomLeft().y()+selectedEm->tasksAmount()*taskPanels[0]->height()+20,
                             10,(panelHeight-30)*differenceKoef);
    }
    for(int c=0;c<addTaskPanels.size();c++)
    {
        addTaskPanels[c]->resizeByScroller(scroller, this->geometry());
        addTaskBtn->move(this->width()/2-105,this->height()-50);
        cancelAddBtn->move(this->width()/2+5,this->height()-50);
    }

    if(panelHeight > generalHeight)
    {
        scroller = false;
    }
    else
    {
        scroller = true;
    }

    addTaskRect = QRect(QPoint(1,taskToAdd->geometry().topLeft().y()-10)
                        ,QPoint(this->width(),this->height()));

    addTaskToEmployee->move((this->width()-addTaskToEmployee->width())/2,this->height()-50);

}

void RightPanel::setAddingPanels()
{
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    MessageWindow* test = new MessageWindow("Warning","You haven't selected any user",true,false,this);

    if(selectedEm->id() == -1)
    {
        connect(test,&MessageWindow::okPressed,test,&MessageWindow::close);
        test->show();
        return;
    }

    delete test;

    if(selectedEm->id() == -1)
    {
        delete selectedEm;
    }

    addTaskToEmployee->hide();

    taskToAdd->setGeometry(12,employeeTasks->height()+selectedEm->tasksAmount()*taskPanels[0]->height()+25,
                           SFProDislplayMetrics.horizontalAdvance("Task(s) to Add"),SFProDislplayMetrics.height());
    taskToAdd->show();

    bool checker = false;
    bool skeeper=false;
    int panNum=0;
    for(int c=0;c<addTaskPanels.size();)
    {
        generalHeight -= addTaskPanels[c]->height();
        delete addTaskPanels[c];
        addTaskPanels.erase(addTaskPanels.begin()+c);
        taskId.erase(taskId.begin()+c);
        if(!skeeper)
        {
            skeeper = true;
        }
    }

    delete addTaskBtn;
    delete cancelAddBtn;

    for(int c =0;c<referBase->tasksAmount();c++)
    {
        for(int a = 0; a< selectedEm->tasksAmount();a++)
        {
            if(referBase->task(c)->id() == selectedEm->task(a)->id())
            {
                checker = true;
                break;
            }
        }
        if(checker)
        {
            checker = false;
            continue;
        }
        addTaskPanels.push_back(new PTtab("",0,this));
        generalHeight += addTaskPanels[0]->height();
        taskId.push_back(c);
        QString taskName = referBase->task(c)->name();
        if(taskName.length()>20)
        {
            taskName.truncate(20);
            taskName += " ...";
        }
        addTaskPanels[panNum]->setPText(QString(taskName),1);
        addTaskPanels[panNum]->move(0,taskToAdd->geometry().bottomLeft().y() + panNum*80);
        addTaskPanels[panNum]->show();
        panNum++;
    }

    shadowSave = new QGraphicsDropShadowEffect(this);
    shadowSave->setBlurRadius(30);
    shadowSave->setOffset(0,0);
    shadowSave->setColor(QColor(0,0,0,200));

    shadowCancel = new QGraphicsDropShadowEffect(this);
    shadowCancel->setBlurRadius(30);
    shadowCancel->setOffset(0,0);
    shadowCancel->setColor(QColor(0,0,0,200));

    addTaskBtn = new QPushButton(this);
    addTaskBtn->setStyleSheet("QPushButton {"
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
    addTaskBtn->setFont(SFProDisplay);
    addTaskBtn->setText("Add");
    addTaskBtn->setGeometry(this->width()/2-105,this->height()-50,
                            100,30);
    addTaskBtn->setGraphicsEffect(shadowSave);
    addTaskBtn->hide();
    connect(addTaskBtn,&QPushButton::clicked,this,&RightPanel::addEmployeeTask);

    cancelAddBtn = new QPushButton(this);
    cancelAddBtn->setStyleSheet(addTaskBtn->styleSheet());
    cancelAddBtn->setFont(SFProDisplay);
    cancelAddBtn->setText("Cancel");
    cancelAddBtn->setGeometry(this->width()/2+5,this->height()-50,
                              100,30);
    cancelAddBtn->setGraphicsEffect(shadowCancel);
    cancelAddBtn->hide();
    connect(cancelAddBtn,&QPushButton::clicked,this,&RightPanel::hideAddTaskMode);

    addTaskBtn->show();
    cancelAddBtn->show();

    double panelHeight = this->height()-employeeTasks->geometry().bottomLeft().y()-selectedEm->tasksAmount()*taskPanels[0]->height()-4;
    double differenceKoef = panelHeight/generalHeight;

    if(generalHeight > panelHeight)
    {
        scroller = true;
        scrollerRect = QRect(this->width()-20,employeeTasks->height()+selectedEm->tasksAmount()*taskPanels[0]->height()+taskToAdd->height(),
                             10,(panelHeight-30)*differenceKoef);
        for(int c =0;c<addTaskPanels.size();c++)
        {
            addTaskPanels[c]->resizeByScroller(scroller,this->geometry());
        }
    }

    addTaskRect = QRect(QPoint(1,employeeTasks->height()+10+selectedEm->tasksAmount()*taskPanels[0]->height()+4)
                        ,QPoint(this->width(),this->height()));

}

void RightPanel::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter drawer(this);
    doPainting(&drawer);
}

void RightPanel::doPainting(QPainter* drawer)
{
    drawer->setRenderHint(QPainter::Antialiasing);

    QBrush myBrush;
    QPen myPen;
    QPainterPath myPath;

    drawer->drawLine(employeeTasks->width()+30,employeeTasks->geometry().topRight().y()+employeeTasks->height()/2,    //Employee Task
                     this->width()-20,employeeTasks->geometry().topRight().y()+employeeTasks->height()/2);


    if(addTaskMode)
    {
        clear();
        myPath.addRoundedRect(addTaskRect,10,10);
        myPen.setColor(QColor(28,28,28));
        myPen.setWidth(2);
        myBrush.setColor(QColor(30,30,30));
        myBrush.setStyle(Qt::SolidPattern);

        drawer->setPen(myPen);
        drawer->setBrush(myBrush);
        drawer->drawPath(myPath);

        myPath.clear();
    }

    if(scroller)
    {
        myPen.setColor(QColor(10,10,10));
        myBrush.setColor(QColor(10,10,10));
        drawer->setPen(myPen);
        drawer->setBrush(myBrush);

        myPath.addRoundedRect(scrollerRect,5,5);

        drawer->drawPath(myPath);
    }
}

void RightPanel::updateSelectedEmployee(int refer)
{
    if(refer == -1)
    {
        return;
    }

    showTaskPanels();
    selectedEm = referBase->employee(refer);
    updateTaskPanel();
    taskPanels[0]->setSelected(true);
    if(addTaskMode){setAddingPanels();}
}

void RightPanel::setAddTaskMode()
{
    addTaskMode = true;
    setAddingPanels();
    this->update();
}

void RightPanel::hideAddTaskMode()
{
    addTaskMode = false;
    scroller = false;
    scrollShift = 0;


    for(int c=0;c<addTaskPanels.size();)
    {
        generalHeight -= addTaskPanels[c]->height();
        delete addTaskPanels[c];
        addTaskPanels.erase(addTaskPanels.begin()+c);
        taskId.erase(taskId.begin()+c);
    }

    addTaskBtn->hide();
    taskToAdd->hide();
    cancelAddBtn->hide();

    employeeTasks->move(12,10);

    for(int c=0;c<taskPanels.size();c++)
    {

        taskPanels[c]->move(0,employeeTasks->geometry().bottomLeft().y()+80*c);
    }

    taskToAdd->move(12,employeeTasks->height()+selectedEm->tasksAmount()*taskPanels[0]->height()+15);

    addTaskId = -1;

    addTaskToEmployee->show();

    this->update();
}

void RightPanel::hideTaskPanels()
{
    for(int c=0;c<taskPanels.size();c++)
    {
        taskPanels[c]->hide();
    }
}

void RightPanel::showTaskPanels()
{
    for(int c=0;c<taskPanels.size();c++)
    {
        taskPanels[c]->show();
    }
}

void RightPanel::addEmployeeTask()
{
    MessageWindow* warning = new MessageWindow("Warning","You haven't selected task",true,false,this);

    if(addTaskId == -1)
    {
        warning->show();
        connect(warning,&MessageWindow::okPressed,warning,&MessageWindow::close);
        return;
    }
    selectedEm->addTask(referBase->task(addTaskId));
    hideAddTaskMode();
    updateTaskPanel();
    addTaskId = -1;
}

void RightPanel::updateTaskPanel()
{
    for(int c=0;c<taskPanels.size();)
    {
        delete taskPanels[c];
        taskPanels.erase(taskPanels.begin()+c);
    }

    for(int c =0;c<selectedEm->tasksAmount();c++)
    {
        taskPanels.push_back(new PTtab("",0,this));
    }

    for(int c=0;c<selectedEm->tasksAmount();c++)
    {
        QString taskName = selectedEm->task(c)->name();
        if(taskName.length()>20)
        {
            taskName.truncate(20);
            taskName += " ...";
        }
        taskPanels[c]->setPText(QString(taskName),1);
        taskPanels[c]->move(0,employeeTasks->geometry().bottomLeft().y()+80*c);
        taskPanels[c]->show();
    }
}

void RightPanel::mousePressEvent(QMouseEvent* event)
{
    pressPoint = event->pos();
    currentScrollerY = scrollerRect.topLeft().y();

    currentAddRect = addTaskRect;

    if(isOnField(event->pos(),scrollerRect))
    {
        scrollDrag = true;
    }

    this->update();

    if(isOnField(event->pos(),QRect(0,0,width(),this->height())))
    {
        if(addTaskMode)
        {
            for(int c=0;c<addTaskPanels.size();c++)
            {
                if(isOnField(event->pos(),addTaskPanels[c]->geometry()))
                {
                    addTaskPanels[c]->setSelected(true);
                    addTaskId = taskId[c];
                }
                else
                {
                    addTaskPanels[c]->setSelected(false);
                }
            }
            return;
        }

        for(int c=0;c<selectedEm->tasksAmount();c++)
        {
            if(isOnField(event->pos(),taskPanels[c]->geometry()))
            {
                taskPanels[c]->setSelected(true);
                emit changedSelected(c);

            }
            else
            {
                taskPanels[c]->setSelected(false);
            }
            taskPanels[c]->update();
        }
    }
}

void RightPanel::mouseMoveEvent(QMouseEvent *event)
{
    if(isOnField(event->pos(),scrollerRect))
    {
        this->setCursor(Qt::PointingHandCursor);
    }
    else
    {
        this->setCursor(Qt::ArrowCursor);
    }

    if(scrollDrag)
    {
        double panelHeight = this->height()-employeeTasks->height()-selectedEm->tasksAmount()*taskPanels[0]->height();
        double differenceKoef = panelHeight/generalHeight;

        QRect deader =scrollerRect;

        scrollerRect = QRect(this->width()-20,event->pos().y()-pressPoint.y()+currentScrollerY
                             ,10,(panelHeight-30)*differenceKoef);

        if(scrollerRect.topLeft().y()<employeeTasks->height()+selectedEm->tasksAmount()*taskPanels[0]->height()+taskToAdd->height()
            or scrollerRect.bottomLeft().y()>this->height()-15)
        {
            scrollerRect = deader;
        }

        scrollShift = (employeeTasks->height()+selectedEm->tasksAmount()*taskPanels[0]->height()+taskToAdd->height() - scrollerRect.topLeft().y())/differenceKoef;

        employeeTasks->move(12,scrollShift+10);

        for(int c=0;c<taskPanels.size();c++)
        {
            taskPanels[c]->move(0,employeeTasks->geometry().bottomLeft().y()+80*c);
        }

        taskToAdd->move(12,taskPanels[taskPanels.size()-1]->geometry().bottomLeft().y()+15);

        for(int c =0;c<addTaskPanels.size();c++)
        {
           addTaskPanels[c]->move(0,taskToAdd->geometry().bottomLeft().y()+5+80*c);
        }


        addTaskRect = QRect(QPoint(1,taskToAdd->geometry().topLeft().y()-10),QPoint(currentAddRect.width(),currentAddRect.bottomRight().y()));

        this->update();
    }
}

void RightPanel::mouseReleaseEvent(QMouseEvent *event)
{
    scrollDrag = false;
}

bool RightPanel::isOnField(const QPointF &point, const QRectF &rect)
{
    return (rect.topLeft().x()<point.x() && rect.topLeft().y()<point.y() &&
            rect.bottomRight().x()>point.x() && rect.bottomRight().y()>point.y());
}

