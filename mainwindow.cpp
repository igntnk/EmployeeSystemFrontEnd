#include "mainwindow.h"

void MainWindow::resizeWindow()
{
    if(this->windowState() == Qt::WindowMaximized)
    {
        if(!mouseResize){this->setWindowState(Qt::WindowNoState);}
    }
    else
    {
        if(!mouseResize){this->setWindowState(Qt::WindowMaximized);}
    }

    initShifts();

    maxTrigger = true;
    descriptionField->resize(this);
    windowTitle->move((this->width()-windowTitle->width())/2,(topPanelHeight-windowTitle->height()+toCenterShift)/2);
    myProfile->move((topPanelHeight-myProfileBtnSize.width()+strokeWidth)/2,this->height()-topPanelHeight+(topPanelHeight-myProfileBtnSize.width())/2);
    myProfileText->move(myProfile->geometry().topRight().x()+buttonShift,
                        myProfile->geometry().topRight().y()+(myProfile->height()/2-myProfileText->height()/2));
    lockScreen->setGeometry(1,51,this->width()-3,this->height()-53);
    leftPanel->setGeometry(shiftForScrolling,topPanelHeight,this->width()/6-shiftForScrolling,this->height()-strokeWidth - topPanelHeight*2);;
    leftPanel->resizePanel();
    rightPanel->setGeometry(this->width()-this->width()/6,topPanelHeight,this->width()/6-shiftForScrolling,this->height()-topPanelHeight*2-strokeWidth);
    rightPanel->resize();
    addEmMenu->resize(this->geometry());
    addTaskMenu->resize(this->geometry());
    addVacationMenu->resize(this->geometry());
    searchPanel->resizeEvent(this->geometry());

    for(int c=0;c<5;c++)
    {
        employeeTools[c]->move(QPoint((this->width()-employeeControllButtonSize.width()*5)/2+(employeeControllButtonSize.width()+employeeControllButtonShift)*c,
                                      this->height()-topPanelHeight+(topPanelHeight-employeeControllButtonSize.height())/2));
    }
}

void MainWindow::hideWindow()
{
    if(this->windowState() != Qt::WindowMinimized){this->setWindowState(Qt::WindowMinimized);}
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    dataBase = new DataBase();

    dataBase->setFontPixelSize(17);
    QFontMetrics SFProDisplayMetrics(dataBase->font());

    for(int c=0;c<1;c++)
    {
        shadows.push_back(new QGraphicsDropShadowEffect(this));
        shadows[c]->setBlurRadius(30);
        shadows[c]->setOffset(0,0);
        shadows[c]->setColor(QColor(0,0,0,200));
    }

    initShifts();

    setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    resize(QSize(1800,800));
    setAttribute(Qt::WA_TranslucentBackground );
    setMouseTracking(true);
    setMinimumSize(mainWindowMinimumSize);

    leftPanel = new LeftPanel(dataBase,this);
    leftPanel->setMouseTracking(true);
    connect(leftPanel,&LeftPanel::changedSelected,this,&MainWindow::setSelected);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////My profile button

    myProfile = new QPushButton(this);
    myProfile->resize(myProfileBtnSize);
    myProfile->move((topPanelHeight-myProfileBtnSize.width()+strokeWidth)/2,this->height()-topPanelHeight+(topPanelHeight-myProfileBtnSize.width())/2);
    myProfile->setStyleSheet("QPushButton {"
                             "border: 2px solid rgb(60,60,60);"
                             "border-radius: 9px;"
                             "background-color: rgb(40,40,40);"
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
    myProfile->setIcon(QIcon(QPixmap(":icons/profile_icon.png")));
    myProfile->setIconSize(myProfileIconSize);
    connect(myProfile,&QPushButton::clicked,this,&MainWindow::myProfileSelected);

    dataBase->setFontPixelSize(14);
    SFProDisplayMetrics = QFontMetrics(dataBase->font());

    myProfileText = new QLabel(this);
    myProfileText->setFont(dataBase->font());
    myProfileText->setText("My Profile");
    myProfileText->setStyleSheet("color: rgb(150,150,150);");
    myProfileText->resize(SFProDisplayMetrics.horizontalAdvance("My Profile"),SFProDisplayMetrics.height());
    myProfileText->move(myProfile->geometry().topRight().x()+buttonShift,
                        myProfile->geometry().topRight().y()+(myProfile->height()/2-myProfileText->height()/2));

///////////////////////////////////////////////////////////////////////////////////////////////////////////////Title text

    windowTitle = new QLabel(this);
    windowTitle->setText("Employee Task Control System");
    windowTitle->resize(SFProDisplayMetrics.horizontalAdvance("Employee Task Control System"),SFProDisplayMetrics.height());
    windowTitle->move((this->width()-windowTitle->width())/2,(topPanelHeight-windowTitle->height()+toCenterShift)/2);
    windowTitle->setFont(dataBase->font());
    windowTitle->setStyleSheet("color: rgb(100, 100, 100)");

    //////////Creating control buttons//////////

    exitButton = new QPushButton(this);
    exitButton->setStyleSheet("QPushButton {"
                              "background-color: rgb(230, 78, 78);"
                              "border: 1px solid rgb(150, 28, 28);"
                              "border-radius: 6px"
                              "}"
                              "QPushButton:hover {"
                              "background-color: rgb(210, 68, 68);"
                              "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(150, 28, 28);"
                              "border: 1px solid rgb(180, 48, 48);"
                              "}");
    exitButton->resize(controlButtonSize);
    exitButton->move(leftSideShift,(topPanelHeight-exitButton->height())/2+toCenterShift);
    connect(exitButton, &QPushButton::clicked,this, &QMainWindow::close);

    resizeButton = new QPushButton(this);
    resizeButton->setStyleSheet("QPushButton {"
                                "background-color: rgb(230, 197, 78);"
                                "border: 1px solid rgb(150, 110, 28);"
                                "border-radius: 6px"
                                "}"
                                "QPushButton:hover {"
                                "background-color: rgb(200, 177, 58);"
                                "}"
                                "QPushButton:pressed {"
                                "background-color: rgb(180, 140, 48);"
                                "border: 1px solid rgb(200, 150, 58);"
                                "}");
    resizeButton->resize(controlButtonSize);
    resizeButton->move(leftSideShift + buttonShift,(topPanelHeight-resizeButton->height())/2+toCenterShift);
    connect(resizeButton, &QPushButton::clicked,this,&MainWindow::resizeWindow);

    hideButton = new QPushButton(this);
    hideButton->setStyleSheet("QPushButton {"
                              "background-color: rgb(194, 194, 194);"
                              "border: 1px solid rgb(120,120,120);"
                              "border-radius: 6px"
                              "}"
                              "QPushButton:hover {"
                              "background-color: rgb(174, 177, 174);"
                              "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(160,160,160);"
                              "border: 1px solid rgb(170, 170, 170);"
                              "}");
    hideButton->resize(controlButtonSize);
    hideButton->move(leftSideShift + buttonShift*2,(topPanelHeight-hideButton->height())/2+toCenterShift);
    connect(hideButton, &QPushButton::clicked,this,&MainWindow::hideWindow);

    //////////Creating employee control buttons//////////
    /// 0-add employee
    /// 1-fire employee
    /// 2-edit info about employee
    /// 3-add task for employee
    /// 4-promote employee
    /////////////////////////////////////////////////////

    dataBase->setFontPixelSize(15);
    SFProDisplayMetrics = QFontMetrics(dataBase->font());

    for(int c=0;c<5;c++)
    {
        employeeTools.push_back(new QPushButton(this));
        employeeTools[c]->setStyleSheet("QPushButton {"
                                        "background-color: rgb(28, 28, 28);"
                                        "color: rgb(100,100,100);"
                                        "border: 1.5px solid rgb(60,60,60);"
                                        "border-radius: 6px"
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
        employeeTools[c]->resize(employeeControllButtonSize);
        employeeTools[c]->move(QPoint((this->width()-employeeControllButtonSize.width()*5)/2+(employeeControllButtonSize.width()+employeeControllButtonShift)*c,
                                      this->height()-topPanelHeight+(topPanelHeight-employeeControllButtonSize.height())/2));
        employeeTools[c]->setFont(dataBase->font());
    }

    employeeTools[0]->setText("Add");
    employeeTools[1]->setText("Fire");
    employeeTools[2]->setText("Edit Info");
    employeeTools[3]->setText("Create Task");
    employeeTools[4]->setText("Promote");

    connect(employeeTools[0],&QPushButton::clicked,this,&MainWindow::showAddEmMenu);
    connect(employeeTools[1],&QPushButton::clicked, this, &MainWindow::deleteEmployee);
    connect(employeeTools[2],&QPushButton::clicked,this,&MainWindow::editMenu);
    connect(employeeTools[3],&QPushButton::clicked,this,&MainWindow::showAddTaskMenu);
    connect(employeeTools[4],&QPushButton::clicked, this, &MainWindow::promoteEmployee);

    //////////Creating description panel//////////

    descriptionField = new DescriptionField(dataBase,this);
    descriptionField->setVisibility(false);
    descriptionField->setMouseTracking(true);

    connect(leftPanel,&LeftPanel::changedSelected,descriptionField,&DescriptionField::setSelectedNum);
    connect(descriptionField,&DescriptionField::baseChanged,leftPanel,&LeftPanel::changePTInfo);

    //////////Creating rigth panel//////////

    rightPanel = new RightPanel(dataBase,leftPanel->getSelectedPanelNum(),this);
    connect(leftPanel,&LeftPanel::changedSelected,rightPanel,&RightPanel::updateSelectedEmployee);
    connect(rightPanel,&RightPanel::changedSelected,descriptionField,&DescriptionField::changeDesc);
    connect(descriptionField,&DescriptionField::baseChanged,rightPanel,&RightPanel::updateTaskPanel);

    //////////Creating lock screen//////////

    searchPanel = new SearchByPar(this);
    searchPanel->move(bootomLeftSideShift,this->height()-topPanelHeight-defaultSearchPanelHeight-bootomLeftSideShift);
    connect(searchPanel,&SearchByPar::textChanged,leftPanel,&LeftPanel::updateBySearch);
    connect(searchPanel,&SearchByPar::changeSize,this,&MainWindow::resizeByFilter);
    connect(searchPanel,&SearchByPar::sortTypeChanged,leftPanel,&LeftPanel::getSortType);

    lockScreen = new LockScreen(dataBase, this);
    lockScreen->setMouseTracking(true);
    lockScreen->hide();

    addEmMenu = new AddEmployeeMenu(dataBase,this);
    connect(addEmMenu,&AddEmployeeMenu::baseChanged,leftPanel,&LeftPanel::updateProfilesList);

    addTaskMenu = new AddTaskMenu(dataBase,this);

    addVacationMenu = new AddVacationMenu(dataBase,this);
    connect(descriptionField,&DescriptionField::vacBtnPressed,addVacationMenu,&AddVacationMenu::showMenu);
    connect(addVacationMenu,&AddVacationMenu::baseChanged,leftPanel,&LeftPanel::updateProfilesList);
    connect(addVacationMenu,&AddVacationMenu::baseChanged,descriptionField,&DescriptionField::setDescription);
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter drawer(this);
    doPainting(&drawer);
}

void MainWindow::doPainting(QPainter* drawer)
{
    drawer->setRenderHint(QPainter::Antialiasing);

    QBrush myBrush;
    QPen myPen;
    QPainterPath myPath;

    //////////Creating middle opacity backgrpound//////////

    myPen.setColor(QColor(10,10,10));
    myBrush.setColor(QColor(50,50,50,200));
    myBrush.setStyle(Qt::SolidPattern);
    myPath.moveTo(0,0);
    myPath.addRoundedRect(QRect(QPoint(1,1),QPoint(this->width()-strokeWidth,this->height()-strokeWidth)),10,10);

    drawer->setPen(myPen);
    drawer->setBrush(myBrush);
    drawer->drawPath(myPath);

    myPath.clear();

    //////////Creating app control panel//////////

    myPath.moveTo(0,0);
    myPath.addRoundedRect(QRect(QPoint(1,1),QPoint(this->width()-strokeWidth,topPanelHeight)),10,10);
    myPen.setColor(QColor(80,80,80));
    myPen.setWidth(1);
    myBrush.setColor(QColor(28,28,28));

    drawer->setPen(myPen);
    drawer->setBrush(myBrush);
    drawer->drawPath(myPath);
    myPen.setColor(QColor(15,15,15));
    drawer->setPen(myPen);
    drawer->drawRect(QRect(QPoint(1,topPanelHeight-2),QPoint(this->width()-strokeWidth,topPanelHeight)));

    myPen.setColor(QColor(28,28,28));

    drawer->setPen(myPen);
    drawer->drawRect(QRect(QPoint(1,topPanelHeight-20),QPoint(this->width()-strokeWidth,topPanelHeight-strokeWidth)));

    myPath.clear();

    //////////Creating employeers control panel//////////

    myPath.addRoundedRect(QRect(QPoint(1,this->height()-topPanelHeight),QPoint(this->width()-strokeWidth,this->height()-strokeWidth)),10,10);

    QLinearGradient gradient;
    gradient.setStart(0,this->height());
    gradient.setFinalStop(0,this->height()-topPanelHeight);
    gradient.setColorAt(0, QColor(40,40,40));
    gradient.setColorAt(1, QColor(48,48,48));
    myPen.setColor(QColor(10,10,10));
    myBrush.setColor(QColor(70,70,70));

    drawer->setPen(myPen);
    drawer->setBrush(gradient);
    drawer->drawPath(myPath);

    myPath.clear();


    drawer->drawRect(QRect(QPoint(1,this->height()-topPanelHeight),QPoint(this->width()-strokeWidth,this->height()-topPanelHeight+10)));

    myPen.setColor(QColor(70,70,70,0));
    drawer->setPen(myPen);
    drawer->drawRect(QRect(QPoint(2,this->height()-topPanelHeight+5),QPoint(this->width()-strokeWidth,this->height()-topPanelHeight+15)));
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    pressPoint = event->pos();
    globalPressPoint = event->globalPosition();
    currentTopLeft = this->geometry().topLeft();
    currentBottomRigth = this->geometry().bottomRight();
    isClicked = true;
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{

    if(isOnField(event->pos(),QRect(0,this->height()-10,10,10)) or (mouseResize and whichSide == 8))///////                         BOTTOM LEFT
    {
        whichSide =8;
        this->setCursor(Qt::SizeBDiagCursor);
        if(isClicked)
        {

            this->setCursor(Qt::ClosedHandCursor);
            mouseResize = true;
            QRect deader = neadedRect;
            neadedRect = QRect(QPoint(event->globalPosition().x()-5,currentTopLeft.y()),
                                     QPoint(currentBottomRigth.x(),event->globalPosition().y()-5));

            if(neadedRect.width()< this->minimumWidth() )
            {
                neadedRect = QRect(QPoint(deader.topLeft().x(),currentTopLeft.y()),
                                   QPoint(currentBottomRigth.x(),event->globalPosition().y()-5));;
            }

            this->setGeometry(neadedRect);
            resizeWindow();
            return;
        }
    }

    if(isOnField(event->pos(),QRect(this->width()-10,this->height()-10,10,10))or (mouseResize and whichSide == 6)) ///////          BOTTOM RIGTH
    {
        whichSide =6;
        this->setCursor(Qt::SizeFDiagCursor);
        if(isClicked)
        {
            this->setCursor(Qt::ClosedHandCursor);
            mouseResize = true;
            neadedRect = QRect(QPoint(currentTopLeft.x(),currentTopLeft.y()),
                                     QPoint(event->globalPosition().x()-5,event->globalPosition().y()-5));

            this->setGeometry(neadedRect);
            resizeWindow();
            return;
        }
    }

    if(isOnField(event->pos(),QRect(this->width()-10,0,10,10)) or (mouseResize and whichSide == 4)) ///////                         TOP RIGHT
    {
        whichSide =4;
        this->setCursor(Qt::SizeBDiagCursor);
        if(isClicked)
        {
            this->setCursor(Qt::ClosedHandCursor);
            mouseResize = true;

            QRect deader = neadedRect;
            neadedRect = QRect(QPoint(currentTopLeft.x(),event->globalPosition().y()-5),
                                     QPoint(event->globalPosition().x()-5,currentBottomRigth.y()));

            if(neadedRect.height()< this->minimumHeight() )
            {
                neadedRect = QRect(QPoint(currentTopLeft.x(),deader.topLeft().y()),
                                   QPoint(event->globalPosition().x()-5,currentBottomRigth.y()));;
            }
            this->setGeometry(neadedRect);
            resizeWindow();
            return;
        }
    }

    if(isOnField(event->pos(),QRect(0,0,10,10)) or (mouseResize and whichSide == 2)) ///////                                        TOP LEFT
    {
        whichSide =2;
        this->setCursor(Qt::SizeFDiagCursor);
        if(isClicked)
        {
            this->setCursor(Qt::ClosedHandCursor);
            mouseResize = true;

            QRect deader = neadedRect;
            neadedRect = QRect(QPoint(event->globalPosition().x()-5,event->globalPosition().y()-5),
                                     QPoint(currentBottomRigth.x(),currentBottomRigth.y()));
            if(neadedRect.width()< this->minimumWidth() and neadedRect.height()< this->minimumHeight())
            {
                neadedRect = QRect(QPoint(deader.topLeft().x(),deader.topLeft().y()),
                                   QPoint(currentBottomRigth.x(),currentBottomRigth.y()));
            }
            else if(neadedRect.width()< this->minimumWidth() )
            {
                neadedRect = QRect(QPoint(deader.topLeft().x(),event->globalPosition().y()-5),
                                   QPoint(currentBottomRigth.x(),currentBottomRigth.y()));
            }
            else if(neadedRect.height()< this->minimumHeight())
            {
                neadedRect = QRect(QPoint(event->globalPosition().x()-5,deader.topLeft().y()),
                                   QPoint(currentBottomRigth.x(),currentBottomRigth.y()));
            }
            this->setGeometry(neadedRect);
            resizeWindow();
            return;
        }
    }

    if(isOnField(event->pos(),QRect(0,10,10,this->height()-20)) or (mouseResize and whichSide == 1)) ///////                        LEFT SIDE
    {
        whichSide =1;
        this->setCursor(Qt::SizeHorCursor);
        if(isClicked)
        {
            this->setCursor(Qt::ClosedHandCursor);
            mouseResize = true;

            QRect deader = neadedRect;
            neadedRect = QRect(QPoint(event->globalPosition().x()-5,currentTopLeft.y()),
                                     QPoint(currentBottomRigth.x(),currentBottomRigth.y()));

            if(neadedRect.width()< this->minimumWidth() )
            {
                neadedRect = QRect(QPoint(deader.topLeft().x(),currentTopLeft.y()),
                      QPoint(currentBottomRigth.x(),currentBottomRigth.y()));
            }
            this->setGeometry(neadedRect);
            resizeWindow();
            return;
        }
    }

    if(isOnField(event->pos(),QRect(10,0,this->width()-20,10)) or (mouseResize and whichSide == 3)) ///////                         TOP SIDE
    {
        whichSide =3;
        this->setCursor(Qt::SizeVerCursor);
        if(isClicked)
        {
            this->setCursor(Qt::ClosedHandCursor);
            mouseResize = true;

            QRect deader = neadedRect;
            neadedRect = QRect(QPoint(currentTopLeft.x(),event->globalPosition().y()-5),
                                     QPoint(currentBottomRigth.x(),currentBottomRigth.y()));
            if(neadedRect.height()< this->minimumHeight() )
            {
                neadedRect = deader;
            }
            this->setGeometry(neadedRect);
            resizeWindow();
            return;
        }
    }

    if(isOnField(event->pos(),QRect(this->width()-10,10,10,this->height()-20)) or (mouseResize and whichSide == 5)) ///////         RIGHT SIDE
    {
        whichSide =5;
        this->setCursor(Qt::SizeHorCursor);
        if(isClicked)
        {
            this->setCursor(Qt::ClosedHandCursor);
            mouseResize = true;
            neadedRect = QRect(QPoint(currentTopLeft.x(),currentTopLeft.y()),
                                     QPoint(event->globalPosition().x()-5,currentBottomRigth.y()));
            this->setGeometry(neadedRect);
            resizeWindow();
            return;
        }
    }

    if(isOnField(event->pos(),QRect(10,this->height()-10,this->width()-20,20)) or (mouseResize and whichSide == 7)) ///////         BOTTOM SIDE
    {
        whichSide =7;
        this->setCursor(Qt::SizeVerCursor);
        if(isClicked)
        {
            this->setCursor(Qt::ClosedHandCursor);
            mouseResize = true;
            neadedRect = QRect(QPoint(currentTopLeft.x(),currentTopLeft.y()),
                                     QPoint(currentBottomRigth.x(),event->globalPosition().y()));
            this->setGeometry(neadedRect);
            resizeWindow();
            return;
        }
    }

    if(isClicked &&
        event->modifiers() == Qt::NoModifier &&
        isOnField(event->pos(),QRect(QPoint(10,10),QPoint(this->width()-10,50))))
    {
        this->move(event->globalPosition().x()-pressPoint.x(),event->globalPosition().y()-pressPoint.y());
    }


    if(isOnField(event->pos(),QRect(10,10,this->width()-20,this->height()-20)))
    {
        this->setCursor(Qt::ArrowCursor);
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    isClicked = false;
    mouseResize = false;
    whichSide = 0;

}

void MainWindow::promoteEmployee()
{
    message = new MessageWindow("Warning","",true,false,this);

    if(selected == -1)
    {
        message->setMainText("You haven't selected any user");
        connect(message,&MessageWindow::okPressed,message,&MessageWindow::close);
        message->show();
        return;
    }

    if(lockScreen->getLogginedId() == selected)
    {
        message->setMainText("You can't promote yourself");
        connect(message,&MessageWindow::okPressed,message,&MessageWindow::close);
        message->show();
        return;
    }
    if(dataBase->employee(selected)->rank()->id() < 1)
    {
        message = new MessageWindow("Warning","You can't promote director or admin",true,false,this);
        connect(message,&MessageWindow::okPressed,message,&MessageWindow::close);
        message->show();
        return;
    }

    message->setCancelButton(true);
    message->setMainText("Are you sure, promote " + dataBase->employee(selected)->name() + " ?");
    message->show();

    connect(message,&MessageWindow::okPressed,this,&MainWindow::promoteSlot);
    connect(message,&MessageWindow::okPressed,message,&MessageWindow::close);
    connect(message,&MessageWindow::cnslPressed,message,&MessageWindow::close);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        lockScreen->checkPasswords();
    }
}

void MainWindow::setSelected(int number)
{
    selected = number;
    leftPanel->setSelected(selected);
}

void MainWindow::deleteSlot()
{
    dataBase->removeEmployee(selected);
    leftPanel->updateProfilesList();
    descriptionField->setVisibility(false);
    rightPanel->hideAddTaskMode();
    rightPanel->hideTaskPanels();
}

void MainWindow::promoteSlot()
{
    dataBase->employee(selected)->setRank(dataBase->rank(dataBase->employee(selected)->rank()->id()-1));
    leftPanel->changePTInfo();
    descriptionField->setInfo();
}

void MainWindow::myProfileSelected()
{
    selected = lockScreen->getLogginedId();
    emit leftPanel->changedSelected(selected);
}

void MainWindow::resizeByFilter(bool opened)
{
    if(opened){searchPanel->setGeometry(bootomLeftSideShift,this->height()-topPanelHeight-extendedSearchPanelHeight-bootomLeftSideShift,
                                 this->width()/6-leftSideShift*2,extendedSearchPanelHeight+strokeWidth);}
    else{searchPanel->setGeometry(bootomLeftSideShift,this->height()-topPanelHeight-defaultSearchPanelHeight-bootomLeftSideShift,
                                 this->width()/6-leftSideShift*2,defaultSearchPanelHeight+strokeWidth);}
}

void MainWindow::initShifts()
{
    topPanelHeight = 30;
    strokeWidth = 2;

    mainWindowMinimumSize = QSize(1050,650);
    controlButtonSize = QSize(13,13);
    employeeControllButtonSize = QSize(120,23);
    myProfileIconSize = QSize(16,16);
    myProfileBtnSize = QSize(22,22);

    leftSideShift = 10;
    bootomLeftSideShift = 6;
    buttonShift = 20;
    toCenterShift = 2;
    shiftForScrolling = 10;

    employeeControllButtonShift = 5;

    defaultSearchPanelHeight =20;
    extendedSearchPanelHeight =60;
}

void MainWindow::deleteEmployee()
{
    message = new MessageWindow("Warning","You can't delete yourself",true,false,this);

    if(selected == lockScreen->getLogginedId())
    {
        message->show();
        connect(message,&MessageWindow::okPressed,message,&MessageWindow::close);
        return;
    }

    if(selected == -1)
    {
        message->setMainText("You haven't selected any user");
        connect(message,&MessageWindow::okPressed,message,&MessageWindow::close);
        message->show();
        return;
    }

    message->setMainText("Are you sure, delete " + dataBase->employee(selected)->name() + " ?");
    message->setCancelButton(true);

    message->show();
    connect(message,&MessageWindow::okPressed,this,&MainWindow::deleteSlot);
    connect(message,&MessageWindow::okPressed,message,&MessageWindow::close);
    connect(message,&MessageWindow::cnslPressed,message,&MessageWindow::close);
}

bool MainWindow::isOnField(const QPointF& point, const QRectF& rect)
{
    return (rect.topLeft().x()<point.x() && rect.topLeft().y()<point.y() &&
            rect.bottomRight().x()>point.x() && rect.bottomRight().y()>point.y());
}

void MainWindow::showAddEmMenu()
{
    addEmMenu->showMenu();
}

void MainWindow::editMenu()
{
    message = new MessageWindow("Warning","",true,false,this);

    if(selected == -1)
    {
        message->setMainText("You haven't selected any user");
        connect(message,&MessageWindow::okPressed,message,&MessageWindow::close);
        message->show();
        return;
    }

    descriptionField->setEditMode();
}

void MainWindow::showAddTaskMenu()
{
    addTaskMenu->show();
}
