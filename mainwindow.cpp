#include "mainwindow.h"

void MainWindow::resizeWindow()
{
    if(this->windowState() == Qt::WindowMaximized)
    {
        this->setWindowState(Qt::WindowNoState);
        maxTrigger=false;
    }
    else
    {
        this->setWindowState(Qt::WindowMaximized);
        maxTrigger = true;
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
    QFont SFProDisplay("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    this->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    this->resize(QSize(1800,800));
    this->setAttribute(Qt::WA_TranslucentBackground );
    this->setMouseTracking(true);

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
                                        "border: 1px solid rgb(80,80,80);"
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
                          "color: rgb(240,240,240);"
                          "}"
                          "QPushButton:hover {"
                          "color: rgb(220,220,220);"
                          "}"
                          "QPushButton:pressed {"
                          "color: rgb(180,180,180);"
                          "}");
    inWork->setText("In Work");
    inWork->setGeometry(12,55,SFProDislplayMetrics.horizontalAdvance("In Work"),SFProDislplayMetrics.height());
    connect(inWork,&QPushButton::clicked,this,&MainWindow::inWorkPressed);

    inVacation->setFont(SFProDisplay);
    inVacation->setStyleSheet("QPushButton {"
                          "background-color: rgba(0,0,0,0);"
                          "color: rgb(240,240,240);"
                          "}"
                          "QPushButton:hover {"
                          "color: rgb(220,220,220);"
                          "}"
                          "QPushButton:pressed {"
                          "color: rgb(180,180,180);"
                          "}");
    inVacation->setText("In Vacation");
    inVacation->setGeometry(12,65 + inWork->height(),SFProDislplayMetrics.horizontalAdvance("In Vacation"),SFProDislplayMetrics.height());
    connect(inVacation,&QPushButton::clicked,this, &MainWindow::inVacationPressed);
}

MainWindow::~MainWindow()
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    windowTitle->setGeometry(QRect(QPoint(this->width()/2-120,15),QSize(300,25)));

    for(int c=0;c<5;c++)
    {
        employeeTools[c]->setGeometry(QRect(QPoint(this->width()/2-512.5+205*c,this->height()-45),QSize(200,40)));
    }

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

    //////////Creating Task Desription Field//////////

    myPen.setColor(QColor(10,10,10));
    myBrush.setColor(QColor(28,28,28));

    drawer->setPen(myPen);
    drawer->setBrush(myBrush);
    drawer->drawRect(QRect(QPoint(this->width()/6,0),QPoint(this->width()-this->width()/6,this->height()-5)));

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
}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton &&
        event->modifiers() == Qt::NoModifier &&
        isOnField(event->pos(),QRect(QPoint(1,1),QPoint(this->width()-5,50))))
    {
        pressPoint = event->pos();
        isClicked = true;
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if(isClicked)
    {
        this->move(event->globalPosition().x()-pressPoint.x(),event->globalPosition().y()-pressPoint.y());
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    Q_UNUSED(event);
    isClicked = false;
}

bool MainWindow::isOnField(const QPointF& point, const QRectF& rect)
{
    return (rect.topLeft().x()<point.x() && rect.topLeft().y()<point.y() &&
            rect.bottomRight().x()>point.x() && rect.bottomRight().y()>point.y());
}

void MainWindow::changeEvent(QEvent* event)
{
    if(event->type() == QEvent::WindowStateChange && waiting)
    {
        this->setWindowState(Qt::WindowMaximized);

    }

    waiting = false;
    if(event->type() == QEvent::WindowStateChange && maxTrigger)
    {
        waiting = true;
    }
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
