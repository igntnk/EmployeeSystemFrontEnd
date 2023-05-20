#include "rightpanel.h"

RightPanel::RightPanel(DataBase* refer,int number, QMainWindow *parent):
    QLabel(parent)
{
    SFProDisplay = QFont("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);

    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    parentSize = parent->geometry();
    this->setGeometry(parent->width()-parent->width()/6-2,60,parent->width()/6,parent->height()-100);
    this->setMouseTracking(true);
    selectedEm = refer->employee(number);
    referBase = refer;

    employeeTasks = new QLabel(this);
    employeeTasks->setText("Employee Tasks");
    employeeTasks->setFont(SFProDisplay);
    employeeTasks->setGeometry(12,0,
                               SFProDislplayMetrics.horizontalAdvance("Employee Tasks"),SFProDislplayMetrics.height());
    employeeTasks->setStyleSheet("color: rgb(200,200,200);");

    taskToAdd = new QLabel(this);
    taskToAdd->setText("Task(s) to Add");
    taskToAdd->setFont(SFProDisplay);
    taskToAdd->hide();
    taskToAdd->setStyleSheet("color: rgb(200,200,200);");
}

void RightPanel::resize()
{
    for(int c=0;c<taskPanels.size();c++)
    {
        taskPanels[c]->resizeByScroller(false, this->geometry());
    }
}

void RightPanel::setAddingPanels()
{
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    bool checker = false;
    int panNum=0;
    for(int c=0;c<addTaskPanels.size();c++)
    {
        delete addTaskPanels[c];
        addTaskPanels.erase(addTaskPanels.begin()+c);
    }

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
        QString taskName = referBase->task(c)->name();
        if(taskName.length()>20)
        {
            taskName.truncate(20);
            taskName += " ...";
        }
        addTaskPanels[panNum]->setPText(QString(taskName),1);
        addTaskPanels[panNum]->move(0,employeeTasks->geometry().bottomLeft().y()+selectedEm->tasksAmount()*taskPanels[0]->height()+40+80*panNum);
        addTaskPanels[panNum]->show();
        panNum++;
    }

    taskToAdd->setGeometry(12,employeeTasks->geometry().bottomLeft().y()+selectedEm->tasksAmount()*taskPanels[0]->height()+15,
                           SFProDislplayMetrics.horizontalAdvance("Task(s) to Add"),SFProDislplayMetrics.height());
    taskToAdd->show();
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
        myPath.addRoundedRect(QRect(QPoint(1,employeeTasks->geometry().bottomLeft().y()+selectedEm->tasksAmount()*taskPanels[0]->height()+4)
                              ,QPoint(this->width(),this->height()-11)),10,10);
        myPen.setColor(QColor(28,28,28));
        myPen.setWidth(2);
        myBrush.setColor(QColor(30,30,30,230));
        myBrush.setStyle(Qt::SolidPattern);

        drawer->setPen(myPen);
        drawer->setBrush(myBrush);
        drawer->drawPath(myPath);

        myPath.clear();
    }
}

void RightPanel::updateSelectedEmployee(int refer)
{
    if(refer == -1)
    {
        return;
    }

    selectedEm = referBase->employee(refer);
    updateTaskPanel(refer);
    if(addTaskMode){setAddingPanels();}
}

void RightPanel::setAddTaskMode()
{
    addTaskMode = true;
    setAddingPanels();
    this->update();
}

void RightPanel::updateTaskPanel(int number)
{
    for(int c=0;c<taskPanels.size();c++)
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
    if(isOnField(event->pos(),QRect(0,0,width(),this->height())))
    {
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
    this->update();
}

bool RightPanel::isOnField(const QPointF &point, const QRectF &rect)
{
    return (rect.topLeft().x()<point.x() && rect.topLeft().y()<point.y() &&
            rect.bottomRight().x()>point.x() && rect.bottomRight().y()>point.y());
}

