
#include "addtaskmenu.h"

AddTaskMenu::AddTaskMenu(DataBase* dataBase,QMainWindow* parent):
    QLabel(parent),localBase(dataBase)
{
    SFProDisplay = QFont("SF Pro Display", 22);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);

    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    this->setGeometry(1,50,parent->width()-3,parent->height()-52);
    this->setMouseTracking(true);
    this->hide();

    chapter = new QLabel(this);
    chapter->setFont(SFProDisplay);
    chapter->setText("Creating Task");
    chapter->resize(SFProDislplayMetrics.horizontalAdvance("Creating Task"),SFProDislplayMetrics.height());
    chapter->setStyleSheet("color: rgb(200,200,200);");

    SFProDisplay.setPixelSize(13);

    m_name = new WritePanel(this);
    m_description = new WritePanel(this);
    m_startline = new QDateTimeEdit(this);
    m_deadline = new QDateTimeEdit(this);
    currentDate = new QCheckBox(this);
    m_enter = new QPushButton(this);
    m_cancel = new QPushButton(this);

    m_name->setText("Task Name");
    m_name->setFont(SFProDisplay);
    m_name->resize(300,40);
    m_description->setText("Description");
    m_description->setFont(SFProDisplay);
    m_description->resize(800,40);

    m_name->move(parent->width()/2-m_name->width()/2,parent->height()/4);
    m_description->move(parent->width()/2-m_description->width()/2,m_name->geometry().bottomRight().y()+panelsShift);

    chapter->move(this->width()/2-chapter->width()/2,m_name->geometry().topLeft().y()-50);

    m_startline->setGeometry(parent->width()/2-100,m_description->geometry().bottomRight().y()+panelsShift,
                              200,40);
    m_startline->setFont(SFProDisplay);
    m_startline->setStyleSheet("QDateTimeEdit {"
                                "padding-left: 5 px;"
                                "background-color: rgb(20,20,20);"
                                "color: rgb(120,120,120);"
                                "border: 2px solid rgb(120,120,120);"
                                "border-radius: 7px"
                                "}"
                                "QDateTimeEdit:up-button {"
                                "width: 0px"
                                "}"
                                "QDateTimeEdit:down-button {"
                                "width:0px"
                                "}");
    m_deadline->setGeometry(parent->width()/2-100,m_startline->geometry().bottomRight().y()+panelsShift,
                             200,40);
    m_deadline->setFont(SFProDisplay);
    m_deadline->setStyleSheet(m_startline->styleSheet());

    currentDate->move(m_startline->geometry().bottomRight().x()+3,m_startline->geometry().topRight().y());
    currentDate->setText("Set Current Date");
    SFProDisplay.setPixelSize(15);
    currentDate->setFont(SFProDisplay);
    currentDate->setStyleSheet("QCheckBox {"
                                     "background-color: rgb(20,20,20);"
                                     "color: rgb(80,80,80);"
                                     "border: 2px solid rgb(80,80,80);"
                                     "border-radius: 7px;"
                                     "width: 160px;"
                                     "height: 30px;}"
                                     "QCheckBox::indicator {"
                                     "left: 5px;"
                                     "width: 20px;"
                                     "height: 20px;}");

    connect(currentDate,&QCheckBox::stateChanged,this,&AddTaskMenu::on_checkBox_stateChanged);

    m_enter->setStyleSheet("QPushButton {"
                           "background-color: rgb(28, 28, 28);"
                           "color: rgb(100,100,100);"
                           "border: 2px solid rgb(120,120,120);"
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
    m_enter->setFont(SFProDisplay);
    m_enter->setText("Enter");
    m_enter->setGeometry(m_deadline->geometry().center().x()-50,m_deadline->geometry().bottomLeft().y()+20,
                         100,30);
    m_cancel->setStyleSheet(m_enter->styleSheet());

    m_cancel->setFont(SFProDisplay);
    m_cancel->setText("Cancel");
    m_cancel->setGeometry(m_enter->geometry().topLeft().x(),m_enter->geometry().bottomLeft().y()+10,
                          100,30);

    connect(m_enter,&QPushButton::clicked,this,&AddTaskMenu::addToBase);
    connect(m_cancel,&QPushButton::clicked,this,&AddTaskMenu::hideMenu);
}

void AddTaskMenu::setDefault()
{
    m_name->setText("Name");
    m_description->setText("Description");

    currentDate->setCheckState(Qt::Unchecked);
}

void AddTaskMenu::resize(QRect parent)
{
    this->setGeometry(1,50,parent.width()-3,parent.height()-52);
    m_name->move(parent.width()/2-m_name->width()/2,parent.height()/4);
    m_description->move(parent.width()/2-m_description->width()/2,m_name->geometry().bottomRight().y()+panelsShift);
    m_startline->move(parent.width()/2-100,m_description->geometry().bottomRight().y()+panelsShift);
    m_deadline->move(parent.width()/2-100,m_startline->geometry().bottomRight().y()+panelsShift);
    currentDate->move(m_startline->geometry().bottomRight().x()+3,m_startline->geometry().topRight().y());
    m_enter->move(m_name->geometry().center().x()-50,m_deadline->geometry().bottomLeft().y()+20);
    m_cancel->move(m_enter->geometry().topLeft().x(),m_enter->geometry().bottomLeft().y()+10);
    chapter->move(this->width()/2-chapter->width()/2,m_name->geometry().topLeft().y()-50);
}


void AddTaskMenu::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter drawer(this);
    doPainting(&drawer);
}

void AddTaskMenu::doPainting(QPainter* drawer)
{
    drawer->setRenderHint(QPainter::Antialiasing);

    QPen myPen;
    QBrush myBrush;
    QPainterPath myPath;

    myPen.setColor(QColor(30,30,30));
    myBrush.setColor(QColor(30,30,30));
    myBrush.setStyle(Qt::SolidPattern);

    myPath.addRoundedRect(0,0,this->width(),this->height(),10,10);

    drawer->setPen(myPen);
    drawer->setBrush(myBrush);
    drawer->drawPath(myPath);

    myPath.clear();

    drawer->drawRect(0,0,this->width(),50);

    myPen.setColor(QColor(10,10,10));
    drawer->setPen(myPen);
    drawer->drawLine(1,1,this->width(),1);
}

void AddTaskMenu::on_checkBox_stateChanged(int arg1)
{
    if(currentDate->isChecked())
    {
        m_startline->setDate(QDate::currentDate());
        m_startline->setTime(QTime(12,30));
    }
    else
    {
        m_startline->setDate(QDate(12,12,2023));
    }
}

void AddTaskMenu::hideMenu()
{
    setDefault();
    this->hide();
}

bool AddTaskMenu::findSimilar()
{
    bool isSame;
    isSame = false;
    for(int c=0;c<localBase->tasksAmount();c++)
    {
        if(localBase->task(c)->name() == m_name->getText())
        {
            isSame = true;
        }
    }
    return isSame;
}

void AddTaskMenu::addToBase()
{
    MessageWindow* wrongInfo = new MessageWindow("Wrong Information","You've entered too short name",true,false,this);
    connect(wrongInfo,&MessageWindow::okPressed,wrongInfo,&MessageWindow::close);
    referEm = new Task();
    referEm->setId(localBase->task(localBase->tasksAmount()-1)->id()+1);

    if(m_name->getText().length() < 2)
    {
        wrongInfo->show();
        return;
    }
    if(m_description->getText().length() < 3)
    {
        wrongInfo->setMainText("You've entered too short description");
        wrongInfo->show();
        return;
    }
    if(findSimilar())
    {
        wrongInfo->setMainText("This task name is busy");
        wrongInfo->show();
        return;
    }

    referEm->setName(m_name->getText());
    referEm->setDescription(m_description->getText());
    referEm->setStartline(m_startline->date());
    referEm->setDeadline(m_deadline->date());

    localBase->addTask(referEm);
    emit baseChanged();
    setDefault();
    delete wrongInfo;
    this->hide();
}

