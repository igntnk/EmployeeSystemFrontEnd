#include "addemployeemenu.h"

AddEmployeeMenu::AddEmployeeMenu(DataBase& refer, QMainWindow* parent):
    QLabel(parent),localBase(refer)
{
    SFProDisplay = QFont("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);

    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(30);
    shadow->setOffset(0,0);
    shadow->setColor(QColor(0,0,0,200));

    this->setGeometry(1,50,parent->width()-3,parent->height()-52);
    this->setMouseTracking(true);
    this->hide();

    QPixmap pixmap;
    pixmap.load(":icons/profile_icon.png");
    picture = new QLabel(this);
    picture->setPixmap(pixmap);
    picture->setScaledContents(true);
    picture->setGeometry(parent->width()/2-350,parent->height()/2-130,200,200);
    picture->setGraphicsEffect(shadow);

    m_name = new WritePanel(this);
    m_surname = new WritePanel(this);
    m_lastname = new WritePanel(this);
    m_rank = new QComboBox(this);
    m_username = new WritePanel(this);
    m_password = new WritePanel(this);
    m_hiringDate = new QDateTimeEdit(this);
    currentHiringDate = new QCheckBox(this);
    m_enter = new QPushButton(this);

    m_name->setText("Name");
    m_name->setFont(SFProDisplay);
    connect(m_name->getEditPanel(),&QLineEdit::textChanged,this,&AddEmployeeMenu::changeNameOp);
    m_surname->setText("Surname");
    m_surname->setFont(SFProDisplay);
    connect(m_surname->getEditPanel(),&QLineEdit::textChanged,this,&AddEmployeeMenu::changeSurnamedOp);
    m_lastname->setText("Last Name");
    m_lastname->setFont(SFProDisplay);
    connect(m_lastname->getEditPanel(),&QLineEdit::textChanged,this,&AddEmployeeMenu::changeLastNameOp);
    m_username->setText("Username");
    m_username->setFont(SFProDisplay);
    connect(m_username->getEditPanel(),&QLineEdit::textChanged,this,&AddEmployeeMenu::changeUsernameOp);
    m_password->setText("Password");
    m_password->setFont(SFProDisplay);
    connect(m_password->getEditPanel(),&QLineEdit::textChanged,this,&AddEmployeeMenu::changePasswordOp);

    m_name->move(parent->width()/2-m_name->width()/2,parent->height()/4);
    m_surname->move(m_name->geometry().bottomLeft().x(),m_name->geometry().bottomRight().y()+panelsShift);
    m_lastname->move(m_name->geometry().bottomLeft().x(),m_surname->geometry().bottomRight().y()+panelsShift);
    m_username->move(m_name->geometry().bottomLeft().x(),m_lastname->geometry().bottomRight().y()+panelsShift);
    m_password->move(m_name->geometry().bottomLeft().x(),m_username->geometry().bottomRight().y()+panelsShift);

    m_hiringDate->setGeometry(m_name->geometry().bottomLeft().x(),m_password->geometry().bottomRight().y()+panelsShift,
                              200,40);
    m_hiringDate->setFont(SFProDisplay);
    m_hiringDate->setStyleSheet("QDateTimeEdit {"
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
    currentHiringDate->move(m_hiringDate->geometry().bottomRight().x()+panelsShift,m_password->geometry().bottomRight().y()+panelsShift+3);
    currentHiringDate->setText("Set Current Date");
    SFProDisplay.setPixelSize(15);
    currentHiringDate->setFont(SFProDisplay);
    currentHiringDate->setStyleSheet("QCheckBox {"
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

    connect(currentHiringDate,&QCheckBox::stateChanged,this,&AddEmployeeMenu::on_checkBox_stateChanged);

    m_rank->setGeometry(m_name->geometry().bottomLeft().x(),m_hiringDate->geometry().bottomRight().y()+panelsShift,
                        200,40);
    m_rank->setFont(SFProDisplay);
    m_rank->setStyleSheet("QComboBox {"
                                "padding-left: 5 px;"
                                "background-color: rgb(20,20,20);"
                                "color: rgb(120,120,120);"
                                "border: 2px solid rgb(120,120,120);"
                                "border-radius: 7px;"
                                "}");
    for(int c=0;c<localBase.taskNumbers();c++)
    {
        m_rank->addItem(localBase.getTask(c)->taskName());
    }

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
    m_enter->setGeometry(m_rank->geometry().center().x()-50,m_rank->geometry().bottomLeft().y()+20,
                       100,30);

    connect(m_enter,&QPushButton::clicked,this,&AddEmployeeMenu::addToBase);
}

void AddEmployeeMenu::setDefault()
{
    m_name->setText("Name");
    m_name->setFont(SFProDisplay);
    m_surname->setText("Surname");
    m_surname->setFont(SFProDisplay);
    m_lastname->setText("Last Name");
    m_lastname->setFont(SFProDisplay);
    m_username->setText("Username");
    m_username->setFont(SFProDisplay);
    m_password->setText("Password");
    m_password->setFont(SFProDisplay);

    currentHiringDate->setCheckState(Qt::Unchecked);
}

void AddEmployeeMenu::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter drawer(this);
    doPainting(&drawer);
}

void AddEmployeeMenu::doPainting(QPainter* drawer)
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

void AddEmployeeMenu::on_checkBox_stateChanged(int arg1)
{
    if(currentHiringDate->isChecked())
    {
        m_hiringDate->setDate(QDate::currentDate());
        m_hiringDate->setTime(QTime(12,30));
    }
    else
    {
        m_hiringDate->setDate(QDate(12,12,2023));
    }
}

void AddEmployeeMenu::addToBase()
{
    Employee refer(localBase.employeeNumbers()+1,m_name->getText(),m_surname->getText(),
                   m_lastname->getText(),localBase.getTask(m_rank->currentText()), localBase.getRank(3),m_username->getText(),
                   m_password->getText(),m_hiringDate->date(),false);

    localBase.addEmployee(refer);
    setDefault();
    this->hide();
    emit baseChanged();
}




void AddEmployeeMenu::changeNameOp(const QString &text)
{
    if(m_name->getText() == "")
    {
        m_name->showText();
    }
    else
    {
        m_name->hideText();
    }
}

void AddEmployeeMenu::changeSurnamedOp(const QString &text)
{
    if(m_surname->getText() == "")
    {
        m_surname->showText();
    }
    else
    {
        m_surname->hideText();
    }
}

void AddEmployeeMenu::changeLastNameOp(const QString &text)
{
    if(m_lastname->getText() == "")
    {
        m_lastname->showText();
    }
    else
    {
        m_lastname->hideText();
    }
}

void AddEmployeeMenu::changeUsernameOp(const QString &text)
{
    if(m_username->getText() == "")
    {
        m_username->showText();
    }
    else
    {
        m_username->hideText();
    }
}

void AddEmployeeMenu::changePasswordOp(const QString &text)
{
    if(m_password->getText() == "")
    {
        m_password->showText();
    }
    else
    {
        m_password->hideText();
    }
}

