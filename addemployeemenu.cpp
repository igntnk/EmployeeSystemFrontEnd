#include "addemployeemenu.h"

AddEmployeeMenu::AddEmployeeMenu(DataBase* refer, QMainWindow* parent):
    QLabel(parent),localBase(refer)
{
    localBase->setFontPixelSize(30);
    QFontMetrics SFProDislplayMetrics(localBase->font());

    this->setGeometry(1,30,parent->width()-3,parent->height()-32);
    this->setMouseTracking(true);
    this->hide();

    chapter = new QLabel(this);
    chapter->setFont(localBase->font());
    chapter->setText("Creating Employee");
    chapter->resize(SFProDislplayMetrics.horizontalAdvance("Creating Employee"),SFProDislplayMetrics.height());
    chapter->setStyleSheet("color: rgb(200,200,200);");

    localBase->setFontPixelSize(13);

    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(30);
    shadow->setOffset(0,0);
    shadow->setColor(QColor(0,0,0,200));

    QPixmap pixmap;
    pixmap.load(":icons/profile_icon.png");
    picture = new QLabel(this);
    picture->setPixmap(pixmap);
    picture->setScaledContents(true);
    picture->setGeometry(parent->width()/2-350,parent->height()/2-130,200,200);
    picture->setGraphicsEffect(shadow);

    m_name = new WritePanel(this);
    m_surname = new WritePanel(this);
    m_document = new QComboBox(this);
    m_username = new WritePanel(this);
    m_password = new WritePanel(this);
    m_hiringDate = new QDateTimeEdit(this);
    currentHiringDate = new QCheckBox(this);
    m_enter = new QPushButton(this);
    m_cancel = new QPushButton(this);

    m_name->setText("Name");
    m_name->setFont(localBase->font());
    m_surname->setText("Surname");
    m_surname->setFont(localBase->font());
    m_username->setText("Username");
    m_username->setFont(localBase->font());
    m_password->setText("Password");
    m_password->setFont(localBase->font());

    m_name->move(parent->width()/2-m_name->width()/2,parent->height()/2-200);
    chapter->move(this->width()/2-chapter->width()/2,m_name->geometry().topLeft().y()-70);
    m_surname->move(m_name->geometry().bottomLeft().x(),m_name->geometry().bottomRight().y()+panelsShift);
    m_username->move(m_name->geometry().bottomLeft().x(),m_surname->geometry().bottomRight().y()+panelsShift);
    m_password->move(m_name->geometry().bottomLeft().x(),m_username->geometry().bottomRight().y()+panelsShift);

    m_hiringDate->setGeometry(m_name->geometry().bottomLeft().x(),m_password->geometry().bottomRight().y()+panelsShift,
                              200,40);
    m_hiringDate->setFont(localBase->font());
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
    localBase->setFontPixelSize(15);
    currentHiringDate->setFont(localBase->font());
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

    m_document->setGeometry(m_name->geometry().bottomLeft().x(),m_hiringDate->geometry().bottomRight().y()+panelsShift,
                            200,40);
    m_document->setFont(localBase->font());
    m_document->setStyleSheet("QComboBox {"
                          "padding-left: 5 px;"
                          "background-color: rgb(20,20,20);"
                          "color: rgb(120,120,120);"
                          "border: 2px solid rgb(120,120,120);"
                          "border-radius: 7px;"
                          "}");

    for(int c=0;c<localBase->documentsAmount();c++)
    {
        m_document->addItem(QString(localBase->document(c)->name() + " (" + localBase->document(c)->code()) + ")");
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
    m_enter->setFont(localBase->font());
    m_enter->setText("Enter");
    m_enter->setGeometry(m_hiringDate->geometry().center().x()-50,m_document->geometry().bottomLeft().y()+20,
                       100,30);
    m_cancel->setStyleSheet(m_enter->styleSheet());
    m_cancel->setFont(localBase->font());
    m_cancel->setText("Cancel");
    m_cancel->setGeometry(m_enter->geometry().topLeft().x(),m_enter->geometry().bottomLeft().y()+10,
                         100,30);

    connect(m_enter,&QPushButton::clicked,this,&AddEmployeeMenu::addToBase);
    connect(m_cancel,&QPushButton::clicked,this,&AddEmployeeMenu::hideMenu);
}

void AddEmployeeMenu::setDefault()
{
    m_name->setText("Name");
    m_surname->setText("Surname");
    m_username->setText("Username");
    m_password->setText("Password");

    currentHiringDate->setCheckState(Qt::Unchecked);
}

void AddEmployeeMenu::resize(QRect parent)
{
    this->setGeometry(1,30,parent.width()-3,parent.height()-32);
    m_name->move(parent.width()/2-m_name->width()/2,parent.height()/2-200);
    chapter->move(this->width()/2-chapter->width()/2,m_name->geometry().topLeft().y()-70);
    m_surname->move(m_name->geometry().bottomLeft().x(),m_name->geometry().bottomRight().y()+panelsShift);
    m_username->move(m_name->geometry().bottomLeft().x(),m_surname->geometry().bottomRight().y()+panelsShift);
    m_password->move(m_name->geometry().bottomLeft().x(),m_username->geometry().bottomRight().y()+panelsShift);
    m_hiringDate->move(m_name->geometry().bottomLeft().x(),m_password->geometry().bottomRight().y()+panelsShift);
    currentHiringDate->move(m_hiringDate->geometry().bottomRight().x()+panelsShift,m_password->geometry().bottomRight().y()+panelsShift+3);
    m_document->move(m_name->geometry().bottomLeft().x(),m_hiringDate->geometry().bottomRight().y()+panelsShift);
    m_enter->move(m_hiringDate->geometry().center().x()-50,m_document->geometry().bottomLeft().y()+20);
    m_cancel->move(m_enter->geometry().topLeft().x(),m_enter->geometry().bottomLeft().y()+10);

    picture->move(parent.width()/2-350,parent.height()/2-130);
}

void AddEmployeeMenu::showMenu()
{
    this->show();
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
    MessageWindow* wrongInfo = new MessageWindow("Wrong Information","You've entered too short name",true,false,this);
    connect(wrongInfo,&MessageWindow::okPressed,wrongInfo,&MessageWindow::close);
    referEm = new Employee();
    referEm->setId((localBase->employees().back()-1)->id()+1);

    if(m_name->getText().length() < 2)
    {
        wrongInfo->show();
        return;
    }
    if(m_surname->getText().length() < 3)
    {
        wrongInfo->setMainText("You've entered too short surname");
        wrongInfo->show();
        return;
    }
    if(findSimilar())
    {
        wrongInfo->setMainText("This username is busy");
        wrongInfo->show();
        return;
    }

    referEm->setName(m_name->getText());
    referEm->setSurname(m_surname->getText());
    referEm->setUsername(m_username->getText());
    referEm->setPassword(m_password->getText());
    referEm->setRank(localBase->rank(localBase->ranksAmount()-1));
    referEm->addDocument(localBase->document(m_document->currentText()));

    localBase->addEmployee(referEm);
    setDefault();
    delete wrongInfo;
    this->hide();
    emit baseChanged();
}

void AddEmployeeMenu::hideMenu()
{
    setDefault();
    this->hide();
}

bool AddEmployeeMenu::findSimilar()
{
    bool isSame;
    isSame = false;
    for(auto c:localBase->employees())
    {
        if(c->username() == m_username->getText())
        {
            isSame = true;
        }
    }
    return isSame;
}
