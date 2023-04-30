#include "mainwindow.h"

void MainWindow::resizeWindow()
{
    if(this->windowState() == Qt::WindowMaximized)
    {
        this->update();
        if(!mouseResize)
        {
            this->setWindowState(Qt::WindowNoState);
        }
    }
    else
    {
        this->update();
        if(!mouseResize)
        {
            this->setWindowState(Qt::WindowMaximized);
        }
    }

    initShifts();

    maxTrigger = true;
    employeeTasks->move(this->width()-this->width()/6+12,58);
    descriptionField->resize(this);
    refreshButton->setGeometry(QRect(QPoint(this->width()-136,6),QSize(130,40)));
    windowTitle->move(this->width()/2-120,15);
    for(int c=0;c<5;c++)
    {
        employeeTools[c]->move(this->width()/2-512.5+205*c,this->height()-45);
    }
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

    initShifts();

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

    //////////Creating in work in vacation buttons//////////

    inWork = new QPushButton(this);
    inVacation = new QPushButton(this);

    SFProDisplay.setPixelSize(20);
    SFProDisplay.setWeight(QFont::DemiBold);
    SFProDislplayMetrics = QFontMetrics(SFProDisplay);

    inWork->setFont(SFProDisplay);
    inWork->setStyleSheet("QPushButton {"
                          "background-color: rgba(0,0,0,0);"
                          "color: rgb(200,200,200);"
                          "}"
                          "QPushButton:hover {"
                          "color: rgb(180,180,180);"
                          "}"
                          "QPushButton:pressed {"
                          "color: rgb(150,150,150);"
                          "}");
    inWork->setText("In Work");
    inWork->setGeometry(12,60,SFProDislplayMetrics.horizontalAdvance("In Work"),SFProDislplayMetrics.height());
    connect(inWork,&QPushButton::clicked,this,&MainWindow::inWorkPressed);

    inVacation->setFont(SFProDisplay);
    inVacation->setStyleSheet("QPushButton {"
                              "background-color: rgba(0,0,0,0);"
                              "color: rgb(200,200,200);"
                              "}"
                              "QPushButton:hover {"
                              "color: rgb(180,180,180);"
                              "}"
                              "QPushButton:pressed {"
                              "color: rgb(150,150,150);"
                              "}");
    inVacation->setText("In Vacation");
    inVacation->setGeometry(12,70 + inWork->height(),SFProDislplayMetrics.horizontalAdvance("In Vacation"),SFProDislplayMetrics.height());
    connect(inVacation,&QPushButton::clicked,this, &MainWindow::inVacationPressed);

    //////////Creating task panel//////////

    employeeTasks = new QLabel(this);
    employeeTasks->setText("Employee Tasks");
    employeeTasks->setFont(SFProDisplay);
    employeeTasks->setGeometry(this->width()-this->width()/6+12,58,
                               SFProDislplayMetrics.horizontalAdvance("Employee Tasks"),SFProDislplayMetrics.height());
    employeeTasks->setStyleSheet("color: rgb(200,200,200);");

    //////////Creating description panel//////////

    descriptionField = new DescriptionField(this);
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
    myBrush.setColor(QColor(50,50,50,150));
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
    drawer->drawRect(QRect(QPoint(1,45),QPoint(this->width()-2,50)));

    myPen.setColor(QColor(28,28,28));

    drawer->setPen(myPen);
    drawer->drawRect(QRect(QPoint(2,41),QPoint(this->width()-3,48)));

    myPath.clear();

    //////////Creating employeers control panel//////////

    myPath.addRoundedRect(QRect(QPoint(1,this->height()-50),QPoint(this->width()-3,this->height()-2)),10,10);
    myPen.setColor(QColor(10,10,10));
    myBrush.setColor(QColor(70,70,70));

    drawer->setPen(myPen);
    drawer->setBrush(myBrush);
    drawer->drawPath(myPath);

    myPath.clear();

    drawer->drawRect(QRect(QPoint(1,this->height()-50),QPoint(this->width()-3,this->height()-30)));

    myPen.setColor(QColor(70,70,70));
    drawer->setPen(myPen);
    drawer->drawRect(QRect(QPoint(2,this->height()-45),QPoint(this->width()-4,this->height()-20)));

    //////////Creating left panel triangles//////////

    myPen.setColor(QColor(240,240,240));
    myBrush.setColor(QColor(240,240,240));
    drawer->setPen(myPen);
    drawer->setBrush(myBrush);

    if(inWorkClicked)
    {
        myPath.moveTo(inWork->geometry().topRight().x()+11,inWork->geometry().topRight().y()+10);
        myPath.lineTo(inWork->geometry().topRight().x()+20,inWork->geometry().topRight().y()+10);
        myPath.lineTo(inWork->geometry().topRight().x()+15,inWork->geometry().topRight().y()+17);
        myPath.lineTo(inWork->geometry().topRight().x()+10,inWork->geometry().topRight().y()+10);
    }
    else
    {
        myPath.moveTo(inWork->geometry().topRight().x()+12,inWork->geometry().topRight().y()+8);
        myPath.lineTo(inWork->geometry().topRight().x()+19,inWork->geometry().topRight().y()+12);
        myPath.lineTo(inWork->geometry().topRight().x()+12,inWork->geometry().topRight().y()+17);
        myPath.lineTo(inWork->geometry().topRight().x()+12,inWork->geometry().topRight().y()+9);
    }
    drawer->drawPath(myPath);

    myPath.clear();

    if(inVacationClicked)
    {
        myPath.moveTo(inVacation->geometry().topRight().x()+11,inVacation->geometry().topRight().y()+10);
        myPath.lineTo(inVacation->geometry().topRight().x()+20,inVacation->geometry().topRight().y()+10);
        myPath.lineTo(inVacation->geometry().topRight().x()+15,inVacation->geometry().topRight().y()+17);
        myPath.lineTo(inVacation->geometry().topRight().x()+10,inVacation->geometry().topRight().y()+10);
    }
    else
    {
        myPath.moveTo(inVacation->geometry().topRight().x()+12,inVacation->geometry().topRight().y()+8);
        myPath.lineTo(inVacation->geometry().topRight().x()+19,inVacation->geometry().topRight().y()+12);
        myPath.lineTo(inVacation->geometry().topRight().x()+12,inVacation->geometry().topRight().y()+17);
        myPath.lineTo(inVacation->geometry().topRight().x()+12,inVacation->geometry().topRight().y()+9);
    }
    drawer->drawPath(myPath);

    myPath.clear();

    //////////Creating lines near text//////////

    myPen.setColor(QColor(150,150,150,150));
    myPen.setWidth(1);
    myBrush.setColor(QColor(0,0,0,0));
    drawer->setPen(myPen);
    drawer->setBrush(myBrush);
    drawer->drawLine(inWork->geometry().topRight().x()+40,inWork->geometry().topRight().y()+inWork->height()/2,                         //In Work
                     this->width()/6-20,inWork->geometry().topRight().y()+inWork->height()/2);

    drawer->drawLine(inVacation->geometry().topRight().x()+40,inVacation->geometry().topRight().y()+inVacation->height()/2,             //In Vacation
                     this->width()/6-20,inVacation->geometry().topRight().y()+inWork->height()/2);

    drawer->drawLine(this->width()/6*5+employeeTasks->width()+30,employeeTasks->geometry().topRight().y()+employeeTasks->height()/2,    //Employee Task
                     this->width()-20,employeeTasks->geometry().topRight().y()+employeeTasks->height()/2);

    myPen.setColor(QColor(50,50,50));
    drawer->setPen(myPen);

//    drawer->drawLine(chapter1->geometry().topRight().x()+40,chapter1->geometry().topRight().y()+chapter1->height()/2+2,                 //Task description
//                     this->width()/6*5-70,chapter1->geometry().topRight().y()+chapter1->height()/2+2);

//    drawer->drawLine(chapter2->geometry().topRight().x()+50,chapter2->geometry().topRight().y()+chapter2->height()/2+2,                 //Employment Date
//                     this->width()/6*5-70,chapter2->geometry().topRight().y()+chapter2->height()/2+2);


}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    pressPoint = event->pos();
    globalPressPoint = event->globalPosition();
    currentPos = this->geometry().topLeft();
    currentWidth = this->width();
    currentHeight = this->height();
    isClicked = true;
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if(isClicked &&
        event->modifiers() == Qt::NoModifier &&
        isOnField(event->pos(),QRect(QPoint(10,10),QPoint(this->width()-10,50))))
    {
        this->move(event->globalPosition().x()-pressPoint.x(),event->globalPosition().y()-pressPoint.y());
    }

    if(isOnField(event->pos(),QRect(0,this->height()-10,10,10)) or (mouseResize and whichSide == 8))// BOTTOM LEFT
    {
        whichSide =8;
        this->setCursor(Qt::SizeBDiagCursor);
        if(isClicked)
        {
            this->setCursor(Qt::ClosedHandCursor);
            mouseResize = true;
            this->setGeometry(event->globalPosition().x()-5,currentPos.y(),
                              currentWidth+(globalPressPoint.x()-event->globalPosition().x()),currentHeight-(globalPressPoint.y()-event->globalPosition().y()));
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
            this->setGeometry(currentPos.x(),currentPos.y(),
                              currentWidth-(globalPressPoint.x()-event->globalPosition().x()),currentHeight-(globalPressPoint.y()-event->globalPosition().y()));
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
            this->setGeometry(currentPos.x(),event->globalPosition().y()-5,
                              currentWidth-(globalPressPoint.x()-event->globalPosition().x()),currentHeight+(globalPressPoint.y()-event->globalPosition().y()));
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
            this->setGeometry(event->globalPosition().x()-5,event->globalPosition().y()-5,
                              currentWidth+(globalPressPoint.x()-event->globalPosition().x()),currentHeight+(globalPressPoint.y()-event->globalPosition().y()));
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
            this->setGeometry(event->globalPosition().x()-5,this->geometry().topLeft().y(),
                              currentWidth+(globalPressPoint.x()-event->globalPosition().x()),this->height());
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
            this->setGeometry(currentPos.x(),event->globalPosition().y()-5,
                              this->width(),currentHeight+(globalPressPoint.y()-event->globalPosition().y()));
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
            this->setGeometry(currentPos.x(),currentPos.y(),
                              currentWidth-(globalPressPoint.x()-event->globalPosition().x()),currentHeight);
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
            this->setGeometry(currentPos.x(),currentPos.y(),
                              currentWidth,currentHeight-(globalPressPoint.y()-event->globalPosition().y()));
            resizeWindow();
            return;
        }
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

void MainWindow::inWorkPressed()
{
    if(inWorkClicked){inWorkClicked = false;}
    else{inWorkClicked = true;}

    qDebug()<< "Should Open Later))";
    this->update();
}

void MainWindow::inVacationPressed()
{
    if(inVacationClicked){inVacationClicked = false; }
    else {inVacationClicked = true;}

    qDebug() << "This Shoul Be Open Too)))";
    this->update();
}

void MainWindow::initShifts()
{
    descPanelShift = this->width()/6;
}
