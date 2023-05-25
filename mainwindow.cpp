#include "mainwindow.h"

void MainWindow::resizeWindow()
{
    if(this->windowState() == Qt::WindowMaximized)
    {
        if(!mouseResize)
        {
            this->setWindowState(Qt::WindowNoState);
        }
    }
    else
    {
        if(!mouseResize)
        {
            this->setWindowState(Qt::WindowMaximized);
        }
    }

    initShifts();

    maxTrigger = true;
    descriptionField->resize(this);
    refreshButton->setGeometry(QRect(QPoint(this->width()-136,6),QSize(130,40)));
    windowTitle->move(this->width()/2-120,15);
    lockScreen->setGeometry(1,51,this->width()-3,this->height()-53);
    leftPanel->setGeometry(5,50,this->width()/6,this->height()-101);
    leftPanel->resizePanel();
    rightPanel->setGeometry(this->width()-this->width()/6-2,50,this->width()/6,this->height()-101);
    rightPanel->resize();
    addEmMenu->resize(this->geometry());
    addTaskMenu->resize(this->geometry());
    addVacationMenu->resize(this->geometry());
    for(int c=0;c<5;c++)
    {
        employeeTools[c]->move(this->width()/2-512.5+205*c,this->height()-45);
    }
    searchPanel->resizeEvent(this->geometry());
}

void MainWindow::hideWindow()
{
    if(this->windowState() != Qt::WindowMinimized)
    {
        this->setWindowState(Qt::WindowMinimized);
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    dataBase = new DataBase();


    SFProDisplay = QFont("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(30);
    shadow->setOffset(0,0);
    shadow->setColor(QColor(0,0,0,200));

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->resize(QSize(1800,800));
    this->setAttribute(Qt::WA_TranslucentBackground );
    this->setMouseTracking(true);
    this->setMinimumSize(QSize(1500,800));

    initShifts();

    leftPanel = new LeftPanel(dataBase,this);
    leftPanel->setMouseTracking(true);
    connect(leftPanel,&LeftPanel::changedSelected,this,&MainWindow::setSelected);

    refreshButton = new QPushButton(this);
    refreshButton->setStyleSheet("QPushButton {"
                                    "background-color: rgb(28, 28, 28);"
                                    "color: rgb(100,100,100);"
                                    "border: 1px solid rgb(50,50,50);"
                                    "border-radius: 5px"
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
    refreshButton->setGeometry(QRect(QPoint(this->width()-136,6),QSize(130,40)));
    refreshButton->setFont(SFProDisplay);
    refreshButton->setText("Update");

    //////////Creating title text//////////

    windowTitle = new QLabel(this);
    windowTitle->setText("Employee Task Control System");
    windowTitle->setGeometry(QRect(QPoint(this->width()/2-120,15),QSize(300,25)));
    windowTitle->setFont(SFProDisplay);
    windowTitle->setStyleSheet("color: rgb(100, 100, 100)");

    //////////Creating control buttons//////////

    exitButton = new QPushButton(this);
    exitButton->setStyleSheet("QPushButton {"
                              "background-color: rgb(230, 78, 78);"
                              "border: 1px solid rgb(150, 28, 28);"
                              "border-radius: 8px"
                              "}"
                              "QPushButton:hover {"
                              "background-color: rgb(210, 68, 68);"
                              "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(150, 28, 28);"
                              "border: 1px solid rgb(180, 48, 48);"
                              "}");
    exitButton->setGeometry(15,20,16,16);
    connect(exitButton, &QPushButton::clicked,this, &QMainWindow::close);

    resizeButton = new QPushButton(this);
    resizeButton->setStyleSheet("QPushButton {"
                                "background-color: rgb(230, 197, 78);"
                                "border: 1px solid rgb(150, 110, 28);"
                                "border-radius: 8px"
                                "}"
                                "QPushButton:hover {"
                                "background-color: rgb(200, 177, 58);"
                                "}"
                                "QPushButton:pressed {"
                                "background-color: rgb(180, 140, 48);"
                                "border: 1px solid rgb(200, 150, 58);"
                                "}");
    resizeButton->setGeometry(40,20,16,16);
    connect(resizeButton, &QPushButton::clicked,this,&MainWindow::resizeWindow);

    hideButton = new QPushButton(this);
    hideButton->setStyleSheet("QPushButton {"
                              "background-color: rgb(194, 194, 194);"
                              "border: 1px solid rgb(120,120,120);"
                              "border-radius: 8px"
                              "}"
                              "QPushButton:hover {"
                              "background-color: rgb(174, 177, 174);"
                              "}"
                              "QPushButton:pressed {"
                              "background-color: rgb(160,160,160);"
                              "border: 1px solid rgb(170, 170, 170);"
                              "}");
    hideButton->setGeometry(65,20,16,16);
    connect(hideButton, &QPushButton::clicked,this,&MainWindow::hideWindow);

    //////////Creating employee control buttons//////////
    /// 0-add employee
    /// 1-fire employee
    /// 2-edit info about employee
    /// 3-add task for employee
    /// 4-promote employee
    /////////////////////////////////////////////////////

    for(int c=0;c<5;c++)
    {
        employeeTools.push_back(new QPushButton(this));
        employeeTools[c]->setStyleSheet("QPushButton {"
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
        employeeTools[c]->setGeometry(QRect(QPoint(this->width()/2-512.5+205*c,this->height()-45),QSize(200,40)));
        employeeTools[c]->setFont(SFProDisplay);
    }

    employeeTools[0]->setText("Add Eployee");
    employeeTools[1]->setText("Fire Employee");
    employeeTools[2]->setText("Edit Employee Info");
    employeeTools[3]->setText("Add Task");
    employeeTools[4]->setText("Promote Employee");

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

    //////////Creating lock screen//////////

    searchPanel = new SearchByPar(this);
    searchPanel->move(10,this->height()-90);
    connect(searchPanel,&SearchByPar::textChanged,leftPanel,&LeftPanel::updateBySearch);
    connect(searchPanel,&SearchByPar::changeSize,this,&MainWindow::resizeByFilter);
    connect(searchPanel,&SearchByPar::sortTypeChanged,leftPanel,&LeftPanel::getSortType);

    lockScreen = new LockScreen(dataBase, this);
    lockScreen->setMouseTracking(true);

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
    myPath.addRoundedRect(QRect(QPoint(1,1),QPoint(this->width()-2,this->height()-2)),10,10);

    drawer->setPen(myPen);
    drawer->setBrush(myBrush);
    drawer->drawPath(myPath);

    myPath.clear();

    //////////Creating app control panel//////////

    myPath.moveTo(0,0);
    myPath.addRoundedRect(QRect(QPoint(1,1),QPoint(this->width()-2,50)),10,10);
    myPen.setColor(QColor(80,80,80));
    myPen.setWidth(1);
    myBrush.setColor(QColor(28,28,28));

    drawer->setPen(myPen);
    drawer->setBrush(myBrush);
    drawer->drawPath(myPath);
    myPen.setColor(QColor(15,15,15));
    drawer->setPen(myPen);
    drawer->drawRect(QRect(QPoint(1,49),QPoint(this->width()-2,50)));

    myPen.setColor(QColor(28,28,28));

    drawer->setPen(myPen);
    drawer->drawRect(QRect(QPoint(2,41),QPoint(this->width()-3,48)));

    myPath.clear();

    //////////Creating employeers control panel//////////

    myPath.addRoundedRect(QRect(QPoint(1,this->height()-50),QPoint(this->width()-3,this->height()-2)),10,10);

    QLinearGradient gradient;
    gradient.setStart(0,this->height());
    gradient.setFinalStop(0,this->height()-50);
    gradient.setColorAt(0, QColor(40,40,40));
    gradient.setColorAt(1, QColor(48,48,48));
    myPen.setColor(QColor(10,10,10));
    myBrush.setColor(QColor(70,70,70));

    drawer->setPen(myPen);
    drawer->setBrush(gradient);
    drawer->drawPath(myPath);

    myPath.clear();


    drawer->drawRect(QRect(QPoint(1,this->height()-50),QPoint(this->width()-3,this->height()-30)));

    myPen.setColor(QColor(70,70,70,0));
    drawer->setPen(myPen);
    drawer->drawRect(QRect(QPoint(2,this->height()-45),QPoint(this->width()-4,this->height()-20)));

    //////////Creating lines near text//////////

    myPen.setColor(QColor(150,150,150,150));
    myPen.setWidth(1);
    myBrush.setColor(QColor(0,0,0,0));
    drawer->setPen(myPen);
    drawer->setBrush(myBrush);

    myPen.setColor(QColor(50,50,50));
    drawer->setPen(myPen);
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

    if(isOnField(event->pos(),QRect(0,this->height()-10,10,10)) or (mouseResize and whichSide == 8))// BOTTOM LEFT
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

    if(isOnField(event->pos(),QRect(this->width()-10,this->height()-10,10,10))or (mouseResize and whichSide == 6)) // BOTTOM RIGTH
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

    if(isOnField(event->pos(),QRect(this->width()-10,0,10,10)) or (mouseResize and whichSide == 4)) //TOP RIGHT
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

    if(isOnField(event->pos(),QRect(0,0,10,10)) or (mouseResize and whichSide == 2)) //TOP LEFT
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

    if(isOnField(event->pos(),QRect(0,10,10,this->height()-20)) or (mouseResize and whichSide == 1)) //LEFT SIDE
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

    if(isOnField(event->pos(),QRect(10,0,this->width()-20,10)) or (mouseResize and whichSide == 3)) //TOP SIDE
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

    if(isOnField(event->pos(),QRect(this->width()-10,10,10,this->height()-20)) or (mouseResize and whichSide == 5)) // RIGHT SIDE
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

    if(isOnField(event->pos(),QRect(10,this->height()-10,this->width()-20,20)) or (mouseResize and whichSide == 7)) // BOTTOM SIDE
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
    test = new MessageWindow("Warning","",true,false,this);

    if(selected == -1)
    {
        test->setMainText("You haven't selected any user");
        connect(test,&MessageWindow::okPressed,test,&MessageWindow::close);
        test->show();
        return;
    }

    descriptionField->setEditMode();
}

void MainWindow::showAddTaskMenu()
{
    addTaskMenu->show();
}

void MainWindow::promoteEmployee()
{
    test = new MessageWindow("Warning","",true,false,this);

    if(selected == -1)
    {
        test->setMainText("You haven't selected any user");
        connect(test,&MessageWindow::okPressed,test,&MessageWindow::close);
        test->show();
        return;
    }

    if(lockScreen->getLogginedId() == selected)
    {
        test->setMainText("You can't promote yourself");
        connect(test,&MessageWindow::okPressed,test,&MessageWindow::close);
        test->show();
        return;
    }

    test->setCancelButton(true);
    test->setMainText("Are you sure, promote " + dataBase->employee(selected)->name() + " ?");
    test->show();

    connect(test,&MessageWindow::okPressed,this,&MainWindow::promoteSlot);
    connect(test,&MessageWindow::okPressed,test,&MessageWindow::close);
    connect(test,&MessageWindow::cnslPressed,test,&MessageWindow::close);
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
    if(dataBase->employee(selected)->rank()->id() > 1)
    {
        dataBase->employee(selected)->setRank(dataBase->rank(dataBase->employee(selected)->rank()->id()-1));
        leftPanel->changePTInfo();
        descriptionField->setInfo();
    }
    else
    {
        test = new MessageWindow("Warning","You can't promote director or admin",true,false,this);
        connect(test,&MessageWindow::okPressed,test,&MessageWindow::close);
        test->show();
    }
}

void MainWindow::resizeByFilter(bool opened)
{
    if(opened)
    {
        searchPanel->setGeometry(10,this->height()-150,this->width()/6-20,90);
    }
    else
    {
        searchPanel->setGeometry(10,this->height()-90,this->width()/6-20,30);
    }
}

void MainWindow::initShifts()
{
    descPanelShift = this->width()/6;
}

void MainWindow::deleteEmployee()
{
    test = new MessageWindow("Warning","You can't delete yourself",true,false,this);

    if(selected == lockScreen->getLogginedId())
    {
        test->show();
        connect(test,&MessageWindow::okPressed,test,&MessageWindow::close);
        return;
    }

    if(selected == -1)
    {
        test->setMainText("You haven't selected any user");
        connect(test,&MessageWindow::okPressed,test,&MessageWindow::close);
        test->show();
        return;
    }

    test->setMainText("Are you sure, delete " + dataBase->employee(selected)->name() + " ?");
    test->setCancelButton(true);

    test->show();
    connect(test,&MessageWindow::okPressed,this,&MainWindow::deleteSlot);
    connect(test,&MessageWindow::okPressed,test,&MessageWindow::close);
    connect(test,&MessageWindow::cnslPressed,test,&MessageWindow::close);
}

