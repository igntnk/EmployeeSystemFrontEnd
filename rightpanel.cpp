#include "rightpanel.h"

RightPanel::RightPanel(DataBase* refer,int number, QMainWindow *parent):
    QLabel(parent)
{
    SFProDisplay = QFont("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);

    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    parentSize = parent->geometry();
    this->setGeometry(parent->width()-parent->width()/6,60,parent->width()/6,parent->height()-130);
    this->setMouseTracking(true);
    selectedEm = refer->employee(number);
    referBase = refer;

    employeeTasks = new QLabel(this);
    employeeTasks->setText("Employee Tasks");
    employeeTasks->setFont(SFProDisplay);
    employeeTasks->setGeometry(12,0,
                               SFProDislplayMetrics.horizontalAdvance("Employee Tasks"),SFProDislplayMetrics.height());
    employeeTasks->setStyleSheet("color: rgb(200,200,200);");

    for(int c=0;c<15;c++)
    {
        taskPanels.push_back(new PTtab("",0,this));
        taskPanels[c]->hide();
    }

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


    if(addTaskMode)
    {
        myPath.addRoundedRect(QRect(QPoint(1,taskPanels[taskPanels.size()-1]->geometry().bottomLeft().y()+5)
                              ,QPoint(this->width()-3,this->height()-2)),10,10);
        myPen.setColor(QColor(10,10,10));
        myBrush.setColor(QColor(70,70,70));

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
}

void RightPanel::setAddTaskMode()
{
    addTaskMode = true;
    this->update();
}

void RightPanel::updateTaskPanel(int number)
{
    for(int c=0;c<15;c++)
    {
        taskPanels[c]->hide();
    }

    for(int c=0;c<selectedEm->tasksAmount();c++)
    {
        taskPanels[c]->setPicture(0);
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

