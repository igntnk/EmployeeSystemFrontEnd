
#include "descriptionfield.h"

DescriptionField::DescriptionField(DataBase* base, QMainWindow* parent):
    QLabel(parent), localBase(base)
{
    initShifts();

    this->setGeometry(parent->width()/6,topPanelHeight,parent->width()/3*2,parent->height()-topPanelHeight*2);

    QFontMetrics SFProDislplayMetrics(localBase->font());

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

    localBase->setFontPixelSize(20);
    SFProDislplayMetrics = QFontMetrics(localBase->font());

    chapters = new QLabel(this);
    chapters->setFont(localBase->font());
    chapters->setText("Name:\nSurname:\nRank:");
    chapters->setAlignment(Qt::AlignRight);
    chapters->setGeometry(profilePict->geometry().topRight().x()+mainProfileInfoShift,
                                 profilePict->geometry().topRight().y()+(profilePict->height()-SFProDislplayMetrics.height()*3)/2,
                                 SFProDislplayMetrics.horizontalAdvance("Last Name: "),SFProDislplayMetrics.height()*3);
    chapters->setStyleSheet("color: rgb(130,130,130);");
    chapters->hide();

    profileInfo = new QLabel(this);
    profileInfo->hide();

    chapter1 = new QLabel(this);
    chapter1->setFont(localBase->font());
    chapter1->setText("Task Decription");
    chapter1->setGeometry(pictureShift,chapter1Shift,
                          SFProDislplayMetrics.horizontalAdvance("Task Description"),SFProDislplayMetrics.height());
    chapter1->setStyleSheet("color: rgb(130,130,130);");
    chapter1->hide();

    chapter2 = new QLabel(this);
    chapter2->setFont(localBase->font());
    chapter2->setText("Employment Date");
    chapter2->setGeometry(pictureShift,this->height()-this->height()/5,
                          SFProDislplayMetrics.horizontalAdvance("Employment Date"),SFProDislplayMetrics.height());
    chapter2->setStyleSheet("color: rgb(130,130,130);");
    chapter2->hide();

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

    m_name->setFont(localBase->font());
    m_name->resize(150,SFProDislplayMetrics.height());
    m_name->hide();
    m_surname->setFont(localBase->font());
    m_surname->resize(150,SFProDislplayMetrics.height());
    m_surname->hide();

    m_hiringDate->resize(200,50);
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
    m_hiringDate->hide();

    localBase->setFontPixelSize(15);

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
    save->setFont(localBase->font());
    save->setText("Save");
    save->setGeometry(this->width()/2-105,this->height()-50,
                       100,30);
    save->setGraphicsEffect(shadows[1]);
    save->hide();
    connect(save,&QPushButton::clicked,this,&DescriptionField::saveChanges);

    cancel = new QPushButton(this);
    cancel->setStyleSheet(save->styleSheet());
    cancel->setFont(localBase->font());
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
    addVacationBtn->setFont(localBase->font());
    addVacationBtn->setText("Create Vacation");
    addVacationBtn->resize(buttonSize);
    addVacationBtn->move(this->width()/2-addVacationBtn->width()/2,20);
    addVacationBtn->setGraphicsEffect(shadows[3]);
    addVacationBtn->hide();
    connect(addVacationBtn,&QPushButton::clicked,this,&DescriptionField::vacBtnPressed);

    localBase->setFontPixelSize(30);
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
            vacRect = QRect(QPoint(vacEnd->geometry().bottomRight().x()+5,vacEnd->geometry().bottomRight().y()+5),
                            QPoint(vacStart->geometry().topLeft().x()-5,vacStart->geometry().topLeft().y()-5));
            myPath.addRoundedRect(vacRect,5,5);
            drawer->drawPath(myPath);
        }
    }

}

void DescriptionField::initShifts()
{
    buttonSize = QSize(150,20);

    pictureShift = 40;
    pictureSideSize = 150;
    mainProfileInfoShift = 30;
    chapter1Shift = 300;
    lineShift = 50;
    topPanelHeight = 30;
}

void DescriptionField::changeToInWorkTask()
{
    localBase->task(selectedTask)->setCompleteStage(2);
    emit baseChanged();
}

void DescriptionField::changeToDoneTask()
{
    localBase->task(selectedTask)->setCompleteStage(3);
    emit baseChanged();
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
    selectedTask = number;

    localBase->setFontPixelSize(15);
    QFontMetrics SFProDislplayMetrics(localBase->font());

    taskDescription->setFont(localBase->font());
    taskDescription->setText(localBase->employee(selectedNum)->task(number)->description());
    taskDescription->setGeometry(chapter1->geometry().bottomLeft().x(), chapter1->geometry().bottomLeft().y()+20,
                                 SFProDislplayMetrics.horizontalAdvance(localBase->employee(selectedNum)->task(number)->description()),SFProDislplayMetrics.height());

    deadLineDate->setText("Dead Line: " + localBase->employee(selectedNum)->task(number)->deadline().toString());
    deadLineDate->setFont(localBase->font());
    deadLineDate->resize(SFProDislplayMetrics.horizontalAdvance("Dead Line: " + localBase->employee(selectedNum)->task(number)->deadline().toString()),
                         SFProDislplayMetrics.height());
    deadLineDate->move(this->width()/2-deadLineDate->width()/2,chapter2->geometry().topLeft().y()-30);

    startLineDate->setText("Start Line: " + localBase->employee(selectedNum)->task(number)->startline().toString());
    startLineDate->setFont(localBase->font());
    startLineDate->resize(SFProDislplayMetrics.horizontalAdvance("Start Line: " + localBase->employee(selectedNum)->task(number)->startline().toString()),
                          SFProDislplayMetrics.height());
    startLineDate->move(this->width()/2-startLineDate->width()/2,deadLineDate->geometry().topLeft().y()-25);

    localBase->setFontPixelSize(13);
    SFProDislplayMetrics = QFontMetrics(localBase->font());

    responceEmployee->setText("Responsible: " + localBase->employee(localBase->employee(selectedNum)->task(number)->responce_id())->name()+
                              " " + localBase->employee(localBase->employee(selectedNum)->task(number)->responce_id())->surname());
    responceEmployee->setFont(localBase->font());
    responceEmployee->resize(SFProDislplayMetrics.horizontalAdvance("Responsible: " + localBase->employee(localBase->employee(selectedNum)->task(number)->responce_id())->name()+
                                                                    " " + localBase->employee(localBase->employee(selectedNum)->task(number)->responce_id())->surname()),
                             SFProDislplayMetrics.height());
    responceEmployee->move(deadLineDate->geometry().topRight().x()+50,deadLineDate->geometry().topRight().y());

    localBase->setFontPixelSize(15);
    SFProDislplayMetrics = QFontMetrics(localBase->font());

    for(int a=0;a<localBase->vacationsAmount();a++)
    {
        if(localBase->employee(selectedNum)->id() == localBase->vacation(a)->employee()->id() and
            localBase->vacation(a)->endDate() > QDate::currentDate())
        {
            isInVac = true;
            vacStart->setFont(localBase->font());
            vacStart->setText("Vacation Start Date: " + localBase->vacation(a)->beginDate().toString());
            vacEnd->setText("Vacation End Date: " + localBase->vacation(a)->endDate().toString());
            vacEnd->setFont(localBase->font());

            vacStart->resize(SFProDislplayMetrics.horizontalAdvance("Vacation Start Date: " + QString(localBase->vacation(a)->beginDate().toString())),
                             SFProDislplayMetrics.height());
            vacEnd->resize(SFProDislplayMetrics.horizontalAdvance("Vacation End Date: " + QString(localBase->vacation(a)->endDate().toString())),
                           SFProDislplayMetrics.height());

            vacStart->move((this->width()-vacStart->width())/2,vacStart->geometry().topLeft().y()-25);
            vacEnd->move((this->width()-vacEnd->width())/2,chapter1->geometry().topLeft().y()-30);

            vacStart->show();
            vacEnd->show();
            break;
        }

        isInVac = false;
        vacStart->hide();
        vacEnd->hide();
    }

    if(localBase->task(number)->complete_stage() == 1 and selectedNum == localBase->loggindeId())
    {
        delete completeStageBtn;
        completeStageBtn = new QPushButton(this);
        completeStageBtn->setStyleSheet(save->styleSheet());
        completeStageBtn->setGeometry(pictureShift,chapter2->geometry().topLeft().y()-50,200,30);
        completeStageBtn->setFont(localBase->font());
        completeStageBtn->setText("Start the Task");
        completeStageBtn->show();
        connect(completeStageBtn,&QPushButton::clicked,this,&DescriptionField::changeToInWorkTask);
    }
    else if(localBase->task(number)->complete_stage() == 2 and selectedNum == localBase->loggindeId())
    {
        delete completeStageBtn;
        completeStageBtn = new QPushButton(this);
        completeStageBtn->setStyleSheet(save->styleSheet());
        completeStageBtn->setGeometry(pictureShift,chapter2->geometry().topLeft().y()-50,200,30);
        completeStageBtn->setFont(localBase->font());
        completeStageBtn->setText("Task Completed");
        completeStageBtn->show();
        connect(completeStageBtn,&QPushButton::clicked,this,&DescriptionField::changeToDoneTask);
    }
    else
    {
        completeStageBtn->hide();
    }
    this->update();
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
        localBase->employee(selectedNum)->setName(m_name->getText());
    }
    if(m_surname->getText()!="")
    {
        localBase->employee(selectedNum)->setSurname(m_surname->getText());
    }
    localBase->employee(selectedNum)->setHireDate(m_hiringDate->date());

    exitEditMode();
    setInfo();
    setEmploymentDate();

    emit baseChanged();
}

void DescriptionField::resize(QMainWindow* changed)
{
    this->setGeometry(changed->width()/6,topPanelHeight,changed->width()/3*2,changed->height()-topPanelHeight*2);

    chapter1->move(pictureShift,chapter1Shift);
    chapter2->move(pictureShift,this->height()-this->height()/5);
    employmentDate->move(chapter2->geometry().bottomLeft().x(), chapter2->geometry().bottomLeft().y()+20);
    cancel->move(this->width()/2+5,this->height()-50);
    save->move(this->width()/2-105,this->height()-50);
    deadLineDate->move(this->width()/2-deadLineDate->width()/2,chapter2->geometry().topLeft().y()-30);
    startLineDate->move(this->width()/2-startLineDate->width()/2,deadLineDate->geometry().topLeft().y()-25);
    m_hiringDate->move(employmentDate->geometry().topLeft().x(),employmentDate->geometry().topLeft().y()-3);
    vacStart->move((this->width()-vacStart->width())/2,chapter1->geometry().topLeft().y()-30);
    vacEnd->move((this->width()-vacStart->width())/2,vacStart->geometry().topLeft().y()-25);
    addVacationBtn->move(this->width()/2-addVacationBtn->width()/2,20);

    if(this->width() < 820){responceEmployee->hide();}
    else{responceEmployee->show();}
}

void DescriptionField::setInfo()
{
    if(selectedNum == -1)
    {
        return;
    }

    localBase->setFontPixelSize(20);
    QFontMetrics SFProDislplayMetrics(localBase->font());

    QString info = localBase->employee(selectedNum)->name() + '\n' + localBase->employee(selectedNum)->surname()
                   + '\n' + localBase->employee(selectedNum)->rank()->name();
    profileInfo->setText(info);
    profileInfo->setFont(localBase->font());
    profileInfo->setGeometry(chapters->geometry().topRight().x()+20,
                             chapters->geometry().topRight().y(),
                             SFProDislplayMetrics.horizontalAdvance(searchLongestWord(localBase->employee(selectedNum)))+10,SFProDislplayMetrics.height()*3);
    profileInfo->setStyleSheet("color: rgb(130,130,130);");

    m_name->move(profileInfo->geometry().topLeft().x(),profileInfo->geometry().topLeft().y());
    m_name->setText(localBase->employee(selectedNum)->name());
    m_surname->move(m_name->geometry().bottomLeft().x(),m_name->geometry().bottomLeft().y()+2);
    m_surname->setText(localBase->employee(selectedNum)->surname());
    m_hiringDate->move(employmentDate->geometry().topLeft().x(),employmentDate->geometry().topLeft().y()-3);
    m_hiringDate->setDate(localBase->employee(selectedNum)->hireDate());
}

void DescriptionField::setDescription()
{
    if(selectedNum == -1)
    {
        return;
    }

    localBase->setFontPixelSize(13);
    QFontMetrics SFProDislplayMetrics(localBase->font());

    taskDescription->setText(localBase->employee(selectedNum)->firstTask()->description());
    taskDescription->setFont(localBase->font());
    taskDescription->setGeometry(chapter1->geometry().bottomLeft().x(), chapter1->geometry().bottomLeft().y()+20,
                                 SFProDislplayMetrics.horizontalAdvance(localBase->employee(selectedNum)->firstTask()->description()),SFProDislplayMetrics.height());

    deadLineDate->setText("Dead Line: " + localBase->employee(selectedNum)->firstTask()->deadline().toString());
    deadLineDate->setFont(localBase->font());
    deadLineDate->resize(SFProDislplayMetrics.horizontalAdvance("Dead Line: " + localBase->employee(selectedNum)->firstTask()->deadline().toString()),
                         SFProDislplayMetrics.height());
    deadLineDate->move(this->width()/2-deadLineDate->width()/2,chapter2->geometry().topLeft().y()-30);

    startLineDate->setText("Start Line: " + localBase->employee(selectedNum)->firstTask()->startline().toString());
    startLineDate->setFont(localBase->font());
    startLineDate->resize(SFProDislplayMetrics.horizontalAdvance("Start Line: " + localBase->employee(selectedNum)->firstTask()->startline().toString()),
                          SFProDislplayMetrics.height());

    startLineDate->move(this->width()/2-startLineDate->width()/2,deadLineDate->geometry().topLeft().y()-25);

    responceEmployee->setText("Responce by this task: " + localBase->employee(localBase->employee(selectedNum)->firstTask()->responce_id())->name()+
                              " " + localBase->employee(localBase->employee(selectedNum)->firstTask()->responce_id())->surname());
    responceEmployee->setFont(localBase->font());
    responceEmployee->resize(SFProDislplayMetrics.horizontalAdvance("Responce by this task: " + localBase->employee(localBase->employee(selectedNum)->firstTask()->responce_id())->name()+
                                                                    " " + localBase->employee(localBase->employee(selectedNum)->firstTask()->responce_id())->surname()),
                          SFProDislplayMetrics.height());
    responceEmployee->move(deadLineDate->geometry().topRight().x()+50,deadLineDate->geometry().topRight().y());

    vacStart->setFont(localBase->font());
    vacEnd->setFont(localBase->font());

    for(int a=0;a<localBase->vacationsAmount();a++)
    {
        if(localBase->employee(selectedNum)->id() == localBase->vacation(a)->employee()->id() and
            localBase->vacation(a)->endDate() > QDate::currentDate())
        {
            isInVac = true;
            vacStart->setText("Vacation Start Date: " + localBase->vacation(a)->beginDate().toString());
            vacEnd->setText("Vacation End Date: " + localBase->vacation(a)->endDate().toString());

            vacStart->resize(SFProDislplayMetrics.horizontalAdvance("Vacation Start Date: " + QString(localBase->vacation(a)->beginDate().toString())),
                             SFProDislplayMetrics.height());
            vacEnd->resize(SFProDislplayMetrics.horizontalAdvance("Vacation End Date: " + QString(localBase->vacation(a)->endDate().toString())),
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

    m_name->setText(localBase->employee(selectedNum)->name());
    m_surname->setText(localBase->employee(selectedNum)->surname());

    addVacationBtn->show();
}

void DescriptionField::setEmploymentDate()
{
    if(selectedNum == -1)
    {
        return;
    }

    localBase->setFontPixelSize(25);
    QFontMetrics SFProDislplayMetrics(localBase->font());

    employmentDate->setText(localBase->employee(selectedNum)->hireDate().toString());
    employmentDate->setFont(localBase->font());
    employmentDate->setGeometry(chapter2->geometry().bottomLeft().x(), chapter2->geometry().bottomLeft().y()+20,
                                SFProDislplayMetrics.horizontalAdvance(localBase->employee(selectedNum)->hireDate().toString()),SFProDislplayMetrics.height());
}

QString DescriptionField::searchLongestWord(Employee* refer)
{
    QString longest = refer->name();

    QFontMetrics SFProDislplayMetrics(localBase->font());
    if(SFProDislplayMetrics.horizontalAdvance(longest) <
        SFProDislplayMetrics.horizontalAdvance(refer->surname())){longest = refer->surname();}
    if(SFProDislplayMetrics.horizontalAdvance(longest) <
        SFProDislplayMetrics.horizontalAdvance(refer->rank()->name())){longest = refer->rank()->name();}

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
