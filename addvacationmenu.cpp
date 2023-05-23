#include "addvacationmenu.h"

AddVacationMenu::AddVacationMenu(DataBase* refer,QMainWindow* parent):
    QLabel(parent),localBase(refer)
{
    SFProDisplay = QFont("SF Pro Display", 22);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);

    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    this->setGeometry(1,50,parent->width()-3,parent->height()-52);
    this->setMouseTracking(true);
    this->hide();

    addVacationChapter = new QLabel(this);
    addVacationChapter->setFont(SFProDisplay);
    addVacationChapter->setText("Creating Vacation");
    addVacationChapter->resize(SFProDislplayMetrics.horizontalAdvance("Creating Vacation"),SFProDislplayMetrics.height());

    SFProDisplay.setPixelSize(13);

    m_employee = new QComboBox(this);
    m_beginDate = new QDateTimeEdit(this);
    m_endDate = new QDateTimeEdit(this);
    currentDate = new QCheckBox(this);
    m_enter = new QPushButton(this);
    m_cancel = new QPushButton(this);

    m_beginDate->resize(200,40);
    m_endDate->resize(200,40);
    m_employee->resize(200,40);

    m_employee->move(parent->width()/2-m_employee->width()/2,parent->height()/3);
    addVacationChapter->move(this->width()/2-addVacationChapter->width()/2,m_employee->geometry().topLeft().y()-70);
    m_beginDate->move(m_employee->geometry().bottomLeft().x(),m_employee->geometry().bottomRight().y()+panelsShift);
    m_endDate->move(m_beginDate->geometry().bottomLeft().x(),m_beginDate->geometry().bottomRight().y()+panelsShift);

    m_beginDate->setFont(SFProDisplay);
    m_beginDate->setStyleSheet("QDateTimeEdit {"
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

    m_endDate->setFont(SFProDisplay);
    m_endDate->setStyleSheet(m_beginDate->styleSheet());

    currentDate->move(m_beginDate->geometry().bottomRight().x()+panelsShift,m_beginDate->geometry().topLeft().y()+3);
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

    connect(currentDate,&QCheckBox::stateChanged,this,&AddVacationMenu::on_checkBox_stateChanged);

    m_employee->resize(200,40);
    m_employee->setFont(SFProDisplay);
    m_employee->setStyleSheet("QComboBox {"
                                "padding-left: 5 px;"
                                "background-color: rgb(20,20,20);"
                                "color: rgb(120,120,120);"
                                "border: 2px solid rgb(120,120,120);"
                                "border-radius: 7px;"
                                "}");

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
    m_enter->setGeometry(m_endDate->geometry().center().x()-50,m_endDate->geometry().bottomLeft().y()+20,
                       100,30);
    m_cancel->setStyleSheet("QPushButton {"
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
    m_cancel->setFont(SFProDisplay);
    m_cancel->setText("Cancel");
    m_cancel->setGeometry(m_enter->geometry().topLeft().x(),m_enter->geometry().bottomLeft().y()+10,
                         100,30);

    connect(m_enter,&QPushButton::clicked,this,&AddVacationMenu::addToBase);
    connect(m_cancel,&QPushButton::clicked,this,&AddVacationMenu::hideMenu);
}

void AddVacationMenu::setDefault()
{
    currentDate->setCheckState(Qt::Unchecked);
}

void AddVacationMenu::resize(QRect parent)
{
    this->setGeometry(1,50,parent.width()-3,parent.height()-52);
    m_employee->move(this->width()/2-m_employee->width()/2,this->height()/3);
    addVacationChapter->move(this->width()/2-addVacationChapter->width()/2,m_employee->geometry().topLeft().y()-70);
    m_beginDate->move(m_employee->geometry().bottomLeft().x(),m_employee->geometry().bottomRight().y()+panelsShift);
    m_endDate->move(m_beginDate->geometry().bottomLeft().x(),m_beginDate->geometry().bottomRight().y()+panelsShift);
    currentDate->move(m_beginDate->geometry().bottomRight().x()+panelsShift,m_beginDate->geometry().topLeft().y()+3);

    m_enter->move(m_endDate->geometry().center().x()-50,m_endDate->geometry().bottomLeft().y()+20);
    m_cancel->move(m_enter->geometry().topLeft().x(),m_enter->geometry().bottomLeft().y()+10);
}

void AddVacationMenu::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter drawer(this);
    doPainting(&drawer);
}

void AddVacationMenu::doPainting(QPainter* drawer)
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

void AddVacationMenu::on_checkBox_stateChanged(int arg1)
{
    if(currentDate->isChecked())
    {
        m_beginDate->setDate(QDate::currentDate());
        m_beginDate->setTime(QTime(12,30));
    }
    else
    {
        m_beginDate->setDate(QDate(12,12,2023));
    }
}

void AddVacationMenu::hideMenu()
{
    m_employee->clear();

    setDefault();
    this->hide();
}

void AddVacationMenu::showMenu()
{
    for(auto c:localBase->employees())
    {
        m_employee->addItem(c->name() + " " + c->surname());
    }

    this->show();
}

void AddVacationMenu::addToBase()
{
    referVac->setId(localBase->vacation(localBase->vacationsAmount()-1)->id()+1);
    referVac->setEmployee(localBase->employee(m_employee->currentIndex()));
    referVac->setBeginDate(m_beginDate->date());
    referVac->setEndDate(m_endDate->date());

    localBase->addVacation(referVac);
    emit baseChanged();
    setDefault();
    this->hide();
}
