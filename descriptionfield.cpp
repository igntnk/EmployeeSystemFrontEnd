
#include "descriptionfield.h"

DescriptionField::DescriptionField(DataBase* base, QMainWindow* parent):
    QLabel(parent), referBase(base)
{
    initShifts();

    this->setGeometry(parent->width()/6,topBarHeight,parent->width()/3*2,parent->height()-topBarHeight*2);

    SFProDisplay = QFont("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    for(int c=0;c<4;c++)
    {
        shadows.push_back(new QGraphicsDropShadowEffect(this));
        shadows[c] = new QGraphicsDropShadowEffect(this);
        shadows[c]->setBlurRadius(30);
        shadows[c]->setOffset(0,0);
        shadows[c]->setColor(QColor(0,0,0,200));
    }
    profilePix.load(":icons/profile_icon.png");
    profilePict = new QLabel(this);
    profilePict->setScaledContents(true);
    profilePict->setGeometry(pictureShift,pictureShift,pictureSideSize,pictureSideSize);
    profilePict->setPixmap(profilePix);
    profilePict->setGraphicsEffect(shadows[0]);
    profilePict->hide();

    SFProDisplay.setPixelSize(30);
    SFProDislplayMetrics = QFontMetrics(SFProDisplay);

    chapters = new QLabel(this);
    chapters->setFont(SFProDisplay);
    chapters->setText("Name:\nSurname:\nRank:");
    chapters->setAlignment(Qt::AlignRight);
    chapters->setGeometry(profilePict->geometry().topRight().x()+mainProfileInfoShift,
                                 profilePict->geometry().topRight().y()+(profilePict->height()-SFProDislplayMetrics.height()*3)/2,
                                 SFProDislplayMetrics.horizontalAdvance("Last Name: "),SFProDislplayMetrics.height()*3);
    chapters->setStyleSheet("color: rgb(130,130,130);");
    chapters->hide();

    profileInfo = new QLabel(this);
    profileInfo->hide();

    department = new QLabel(this);
    department->hide();

    chapter1 = new QLabel(this);
    chapter1->setFont(SFProDisplay);
    chapter1->setText("Task Decription");
    chapter1->setGeometry(pictureShift,chapter1Shift,
                          SFProDislplayMetrics.horizontalAdvance("Task Description"),SFProDislplayMetrics.height());
    chapter1->setStyleSheet("color: rgb(130,130,130);");
    chapter1->hide();

    chapter2 = new QLabel(this);
    chapter2->setFont(SFProDisplay);
    chapter2->setText("Employment Date");
    chapter2->setGeometry(pictureShift,this->height()-this->height()/5,
                          SFProDislplayMetrics.horizontalAdvance("Employment Date"),SFProDislplayMetrics.height());
    chapter2->setStyleSheet("color: rgb(130,130,130);");
    chapter2->hide();

    SFProDislplayMetrics = QFontMetrics(SFProDisplay);

    taskDescription = new QLabel(this);
    taskDescription->setStyleSheet("color: rgb(80,80,80);");
    taskDescription->hide();

    employmentDate = new QLabel(this);
    employmentDate->setStyleSheet("color: rgb(80,80,80);");
    employmentDate->hide();

    deadLineDate = new QLabel(this);
    deadLineDate->setStyleSheet("color: rgb(100,100,100);");
    deadLineDate->hide();

    startLineDate = new QLabel(this);
    startLineDate->setStyleSheet("color: rgb(100,100,100);");
    startLineDate->hide();

    responceEmployee = new QLabel(this);
    responceEmployee->setStyleSheet("color: rgb(100,100,100);");
    responceEmployee->hide();

    m_name = new WritePanel(this);
    m_surname = new WritePanel(this);
    m_hiringDate = new QDateEdit(this);

    m_name->setFont(SFProDisplay);
    m_name->resize(250,SFProDislplayMetrics.height());
    m_name->hide();
    m_surname->setFont(SFProDisplay);
    m_surname->resize(250,SFProDislplayMetrics.height());
    m_surname->hide();

    m_hiringDate->resize(200,50);
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
    m_hiringDate->hide();

    SFProDisplay.setPixelSize(15);

    save = new QPushButton(this);
    save->setStyleSheet("QPushButton {"
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
    save->setFont(SFProDisplay);
    save->setText("Save");
    save->setGeometry(this->width()/2-105,this->height()-50,
                       100,30);
    save->setGraphicsEffect(shadows[1]);
    save->hide();
    connect(save,&QPushButton::clicked,this,&DescriptionField::saveChanges);

    cancel = new QPushButton(this);
    cancel->setStyleSheet(save->styleSheet());
    cancel->setFont(SFProDisplay);
    cancel->setText("Cancel");
    cancel->setGeometry(this->width()/2+5,this->height()-50,
                      100,30);
    cancel->setGraphicsEffect(shadows[2]);
    cancel->hide();
    connect(cancel,&QPushButton::clicked,this,&DescriptionField::exitEditMode);

    vacStart = new QLabel(this);
    vacEnd = new QLabel(this);

    vacStart->setStyleSheet("color: rgb(120,120,120);");
    vacEnd->setStyleSheet("color: rgb(120,120,120);");
    vacStart->hide();
    vacEnd->hide();

    addVacationBtn = new QPushButton(this);
    addVacationBtn->setStyleSheet("QPushButton {"
                                  "background-color: rgb(28, 28, 28);"
                                  "color: rgb(100,100,100);"
                                  "border: 2px solid rgb(80,80,80);"
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
    addVacationBtn->setFont(SFProDisplay);
    addVacationBtn->setText("Create Vacation");
    addVacationBtn->resize(200,40);
    addVacationBtn->move(this->width()/2-addVacationBtn->width()/2,20);
    addVacationBtn->setGraphicsEffect(shadows[3]);
    addVacationBtn->hide();
    connect(addVacationBtn,&QPushButton::clicked,this,&DescriptionField::vacBtnPressed);

    SFProDisplay.setPixelSize(30);
}

void DescriptionField::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter drawer(this);
    doPainting(&drawer);
}

void DescriptionField::doPainting(QPainter* drawer)
{
    drawer->setRenderHint(QPainter::Antialiasing);

    QPen myPen;
    QBrush myBrush;
    QPainterPath myPath;

    myPen.setColor(QColor(10,10,10));
    myPen.setWidth(1);
    myBrush.setColor(QColor(28,28,28));
    myBrush.setStyle(Qt::SolidPattern);

    drawer->setPen(myPen);
    drawer->setBrush(myBrush);
    drawer->drawRect(0,0,this->width()-1,this->height()-1);

    myPen.setColor(QColor(50,50,50));
    myPen.setWidth(2);
    drawer->setPen(myPen);

    if(isProfileSelected)
    {
        myPen.setColor(QColor(50,50,50));
        myPen.setWidth(2);
        drawer->setPen(myPen);

        drawer->drawLine(chapter1->geometry().topRight().x()+lineShift,chapter1->geometry().topRight().y()+chapter1->height()/2+2,                 //Task description
                         this->width()-lineShift,chapter1->geometry().topRight().y()+chapter1->height()/2+2);

        drawer->drawLine(chapter2->geometry().topRight().x()+lineShift,chapter2->geometry().topRight().y()+chapter2->height()/2+2,                 //Employment Date
                         this->width()-lineShift,chapter2->geometry().topRight().y()+chapter2->height()/2+2);

        myPath.moveTo(0,0);
        myPath.addRoundedRect(QRect(department->geometry().topLeft().x()-5,
                                    department->geometry().topLeft().y()+2,department->width()+10,department->height()),5,5);

        myPen.setColor(QColor(200,200,200));
        myPen.setWidth(1);

        myBrush.setColor(QColor(20,20,20));
        myBrush.setStyle(Qt::SolidPattern);

        drawer->setBrush(myBrush);
        drawer->setPen(myPen);
        drawer->drawPath(myPath);

        myPath.clear();

        if(isInVac)
        {
            vacRect = QRect(QPoint(vacEnd->geometry().topLeft().x()-5,vacEnd->geometry().topLeft().y()-5),
                            QPoint(vacStart->geometry().bottomRight().x()+5,vacStart->geometry().bottomRight().y()+5));
            myPath.addRoundedRect(vacRect,5,5);
            drawer->drawPath(myPath);
        }
    }

}

void DescriptionField::initShifts()
{
    pictureShift = 40;
    pictureSideSize = 200;
    mainProfileInfoShift = 30;
    chapter1Shift = 300;
    lineShift = 50;
    topBarHeight = 50;
}

void DescriptionField::setSelectedNum(int number)
{
    selectedNum = number;
    setVisibility(true);
    setEmploymentDate();
    setInfo();
}

void DescriptionField::changeDesc(int number)
{
    SFProDisplay.setPixelSize(18);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    taskDescription->setFont(SFProDisplay);
    taskDescription->setText(referBase->employee(selectedNum)->task(number)->description());
    taskDescription->setGeometry(chapter1->geometry().bottomLeft().x(), chapter1->geometry().bottomLeft().y()+20,
                                 SFProDislplayMetrics.horizontalAdvance(referBase->employee(selectedNum)->task(number)->description()),SFProDislplayMetrics.height());

    deadLineDate->setText("Dead Line: " + referBase->employee(selectedNum)->task(number)->deadline().toString());
    deadLineDate->setFont(SFProDisplay);
    deadLineDate->resize(SFProDislplayMetrics.horizontalAdvance("Dead Line: " + referBase->employee(selectedNum)->task(number)->deadline().toString()),
                         SFProDislplayMetrics.height());
    deadLineDate->move(this->width()/2-deadLineDate->width()/2,chapter2->geometry().topLeft().y()-30);

    startLineDate->setText("Start Line: " + referBase->employee(selectedNum)->task(number)->startline().toString());
    startLineDate->setFont(SFProDisplay);
    startLineDate->resize(SFProDislplayMetrics.horizontalAdvance("Start Line: " + referBase->employee(selectedNum)->task(number)->startline().toString()),
                          SFProDislplayMetrics.height());
    startLineDate->move(this->width()/2-startLineDate->width()/2,deadLineDate->geometry().topLeft().y()-25);

    responceEmployee->setText("Responce by this task: " + referBase->employee(referBase->employee(selectedNum)->task(number)->responce_id())->name()+
                              " " + referBase->employee(referBase->employee(selectedNum)->task(number)->responce_id())->surname());
    responceEmployee->setFont(SFProDisplay);
    responceEmployee->resize(SFProDislplayMetrics.horizontalAdvance("Responce by this task: " + referBase->employee(referBase->employee(selectedNum)->task(number)->responce_id())->name()+
                                                                    " " + referBase->employee(referBase->employee(selectedNum)->task(number)->responce_id())->surname()),
                             SFProDislplayMetrics.height());
    responceEmployee->move(deadLineDate->geometry().topRight().x()+50,deadLineDate->geometry().topRight().y());
}

void DescriptionField::setEditMode()
{
    m_name->show();
    m_surname->show();
    m_hiringDate->show();
    save->show();
    cancel->show();
}

void DescriptionField::exitEditMode()
{
    m_name->hide();
    m_surname->hide();
    m_hiringDate->hide();
    save->hide();
    cancel->hide();
}

void DescriptionField::saveChanges()
{
    MessageWindow* wrongInfo = new MessageWindow("Wrong Information","You've entered too short name",true,false,this);
    connect(wrongInfo,&MessageWindow::okPressed,wrongInfo,&MessageWindow::close);

    if(m_name->getText().length() < 2 and m_name->getText() != "")
    {
        wrongInfo->show();
        return;
    }
    if(m_surname->getText().length() < 3 and m_surname->getText() != "")
    {
        wrongInfo->setMainText("You've entered too short surname");
        wrongInfo->show();
        return;
    }

    if(m_name->getText() != "")
    {
        referBase->employee(selectedNum)->setName(m_name->getText());
    }
    if(m_surname->getText()!="")
    {
        referBase->employee(selectedNum)->setSurname(m_surname->getText());
    }
    referBase->employee(selectedNum)->setHireDate(m_hiringDate->date());

    exitEditMode();
    setInfo();
    setEmploymentDate();

    emit baseChanged();
}

void DescriptionField::resize(QMainWindow* changed)
{
    this->setGeometry(changed->width()/6,topBarHeight,changed->width()/3*2,changed->height()-topBarHeight*2);

    chapter1->move(pictureShift,chapter1Shift);
    chapter2->move(pictureShift,this->height()-this->height()/5);
    employmentDate->move(chapter2->geometry().bottomLeft().x(), chapter2->geometry().bottomLeft().y()+20);
    department->move(this->width()/1.6,profileInfo->geometry().center().y());
    cancel->move(this->width()/2+5,this->height()-50);
    save->move(this->width()/2-105,this->height()-50);
    deadLineDate->move(this->width()/2-deadLineDate->width()/2,chapter2->geometry().topLeft().y()-30);
    startLineDate->move(this->width()/2-startLineDate->width()/2,deadLineDate->geometry().topLeft().y()-25);
    m_hiringDate->move(employmentDate->geometry().topLeft().x(),employmentDate->geometry().topLeft().y()-3);
    vacStart->move((this->width()-vacStart->width())/2,chapter1->geometry().topLeft().y()-30);
    vacEnd->move((this->width()-vacStart->width())/2,vacStart->geometry().topLeft().y()-25);
    addVacationBtn->move(this->width()/2-addVacationBtn->width()/2,20);
}

void DescriptionField::setInfo()
{
    if(selectedNum == -1)
    {
        return;
    }

    SFProDisplay.setPixelSize(30);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    QString info = referBase->employee(selectedNum)->name() + '\n' + referBase->employee(selectedNum)->surname()
                   + '\n' + referBase->employee(selectedNum)->rank()->name();
    profileInfo->setText(info);
    profileInfo->setFont(SFProDisplay);
    profileInfo->setGeometry(chapters->geometry().topRight().x()+20,
                             chapters->geometry().topRight().y(),
                             SFProDislplayMetrics.horizontalAdvance(searchLongestWord(referBase->employee(selectedNum)))+10,SFProDislplayMetrics.height()*3);
    profileInfo->setStyleSheet("color: rgb(130,130,130);");

    department->setText("Depatment: " + referBase->employee(selectedNum)->rank()->department()->name());
    department->setFont(SFProDisplay);
    department->setGeometry(this->width()/1.6,profileInfo->geometry().center().y(),
                            SFProDislplayMetrics.horizontalAdvance("Depatment: " + referBase->employee(selectedNum)->rank()->department()->name()),
                            SFProDislplayMetrics.height());
    department->setStyleSheet("color: rgb(130,130,130);");

    m_name->move(profileInfo->geometry().topLeft().x(),profileInfo->geometry().topLeft().y());
    m_surname->move(m_name->geometry().bottomLeft().x(),m_name->geometry().bottomLeft().y()+2);
    m_hiringDate->move(employmentDate->geometry().topLeft().x(),employmentDate->geometry().topLeft().y()-3);
    m_hiringDate->setDate(referBase->employee(selectedNum)->hireDate());
}

void DescriptionField::setDescription()
{
    if(selectedNum == -1)
    {
        return;
    }

    SFProDisplay.setPixelSize(18);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    taskDescription->setText(referBase->employee(selectedNum)->task(0)->description());
    taskDescription->setFont(SFProDisplay);
    taskDescription->setGeometry(chapter1->geometry().bottomLeft().x(), chapter1->geometry().bottomLeft().y()+20,
                                 SFProDislplayMetrics.horizontalAdvance(referBase->employee(selectedNum)->task(0)->description()),SFProDislplayMetrics.height());

    deadLineDate->setText("Dead Line: " + referBase->employee(selectedNum)->task(0)->deadline().toString());
    deadLineDate->setFont(SFProDisplay);
    deadLineDate->resize(SFProDislplayMetrics.horizontalAdvance("Dead Line: " + referBase->employee(selectedNum)->task(0)->deadline().toString()),
                         SFProDislplayMetrics.height());
    deadLineDate->move(this->width()/2-deadLineDate->width()/2,chapter2->geometry().topLeft().y()-30);

    startLineDate->setText("Start Line: " + referBase->employee(selectedNum)->task(0)->startline().toString());
    startLineDate->setFont(SFProDisplay);
    startLineDate->resize(SFProDislplayMetrics.horizontalAdvance("Start Line: " + referBase->employee(selectedNum)->task(0)->startline().toString()),
                          SFProDislplayMetrics.height());

    startLineDate->move(this->width()/2-startLineDate->width()/2,deadLineDate->geometry().topLeft().y()-25);

    responceEmployee->setText("Responce by this task: " + referBase->employee(referBase->employee(selectedNum)->task(0)->responce_id())->name()+
                              " " + referBase->employee(referBase->employee(selectedNum)->task(0)->responce_id())->surname());
    responceEmployee->setFont(SFProDisplay);
    responceEmployee->resize(SFProDislplayMetrics.horizontalAdvance("Responce by this task: " + referBase->employee(referBase->employee(selectedNum)->task(0)->responce_id())->name()+
                                                                    " " + referBase->employee(referBase->employee(selectedNum)->task(0)->responce_id())->surname()),
                          SFProDislplayMetrics.height());
    responceEmployee->move(deadLineDate->geometry().topRight().x()+50,deadLineDate->geometry().topRight().y());

    vacStart->setFont(SFProDisplay);
    vacEnd->setFont(SFProDisplay);

    for(int a=0;a<referBase->vacationsAmount();a++)
    {
        if(referBase->employee(selectedNum)->id() == referBase->vacation(a)->employee()->id() and
            referBase->vacation(a)->endDate() > QDate::currentDate())
        {
            isInVac = true;
            vacStart->setText("Vacation Start Date: " + referBase->vacation(a)->beginDate().toString());
            vacEnd->setText("Vacation End Date: " + referBase->vacation(a)->endDate().toString());

            vacStart->resize(SFProDislplayMetrics.horizontalAdvance("Vacation Start Date: " + QString(referBase->vacation(a)->beginDate().toString())),
                             SFProDislplayMetrics.height());
            vacEnd->resize(SFProDislplayMetrics.horizontalAdvance("Vacation End Date: " + QString(referBase->vacation(a)->endDate().toString())),
                           SFProDislplayMetrics.height());

            vacStart->move((this->width()-vacStart->width())/2,chapter1->geometry().topLeft().y()-30);
            vacEnd->move((this->width()-vacStart->width())/2,vacStart->geometry().topLeft().y()-25);

            vacStart->show();
            vacEnd->show();
            break;
        }

        isInVac = false;
        vacStart->hide();
        vacEnd->hide();
    }

    m_name->setText(referBase->employee(selectedNum)->name());
    m_surname->setText(referBase->employee(selectedNum)->surname());

    addVacationBtn->show();
}

void DescriptionField::setEmploymentDate()
{
    if(selectedNum == -1)
    {
        return;
    }

    SFProDisplay.setPixelSize(25);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    employmentDate->setText(referBase->employee(selectedNum)->hireDate().toString());
    employmentDate->setFont(SFProDisplay);
    employmentDate->setGeometry(chapter2->geometry().bottomLeft().x(), chapter2->geometry().bottomLeft().y()+20,
                                SFProDislplayMetrics.horizontalAdvance(referBase->employee(selectedNum)->hireDate().toString()),SFProDislplayMetrics.height());
}

QString DescriptionField::searchLongestWord(Employee* refer)
{
    QString longest = refer->name();

    if(longest.length() < refer->surname().length()){longest = refer->surname();}
    if(longest.length() < refer->rank()->name().length()){longest = refer->rank()->name();}

    return longest;
}

void DescriptionField::setVisibility(bool choice)
{
    isProfileSelected = choice;

    if(isProfileSelected)
    {
        profilePict->show();
        chapters->show();
        profileInfo->show();
        chapter1->show();
        chapter2->show();
        taskDescription->show();
        department->show();
        employmentDate->show();
        startLineDate->show();
        deadLineDate->show();
        addVacationBtn->show();
        responceEmployee->show();
    }
    else
    {
        profilePict->hide();
        chapters->hide();
        profileInfo->hide();
        chapter1->hide();
        chapter2->hide();
        taskDescription->hide();
        department->hide();
        employmentDate->hide();
        startLineDate->hide();
        deadLineDate->hide();
        addVacationBtn->hide();
        vacStart->hide();
        vacEnd->hide();
        responceEmployee->hide();
    }
    this->update();
}
