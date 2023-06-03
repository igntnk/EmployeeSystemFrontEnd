
#include "searchbyname.h"

SearchByPar::SearchByPar(QMainWindow* parent):
    QLabel(parent)
{
    SFProDisplay = QFont("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);

    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    initShifts();
    resize(parent->width()/6-panelShift,ellipsesRad*2+strokeWidth);
    setMouseTracking(true);

    searchText = new QLineEdit(this);
    searchText->setStyleSheet("QLineEdit{"
                        "color: rgb(180,180,180);"
                        "background-color: rgba(0,0,0,0);"
                        "}");
    searchText->setFrame(false);
    searchText->setGeometry(this->geometry().topLeft().x()+lineEditShift,this->geometry().topLeft().y(),this->width()-panelShift/2,defaultSearchPanelHeight);
    searchText->setFont(SFProDisplay);
    searchText->hide();
    connect(searchText,&QLineEdit::textChanged,this,&SearchByPar::textChanged);

    SFProDisplay.setPixelSize(14);

    searchTextShower = new QLabel(this);
    searchTextShower->setFont(SFProDisplay);
    searchTextShower->move(ellipsesRad*3,strokeWidth);
    searchTextShower->setStyleSheet("color: rgb(140,140,140);");

    for(int c=0;c<3;c++)
    {
        choicePanel.push_back(new ChoiceText("",this));
        choicePanel[c]->hide();
        choicePanel[c]->setStyleSheet("color: rgb(150,150,150);");
    }
    choicePanel[0]->setText("Name");
    choicePanel[1]->setText("Surname");
    choicePanel[2]->setText("Rank");

    sortText = new QLabel(this);
    sortText->setFont(SFProDisplay);
    sortText->setStyleSheet("color: rgb(140,140,140);");
    sortText->hide();
}

void SearchByPar::resizeEvent(QRect refer)
{
    QFontMetrics SFProDislplayMetrics(SFProDisplay);
    if(searchPressed or (!searchPressed and !settingsPressed))
    {
        resize(refer.width()/6-panelShift,defaultSearchPanelHeight+strokeWidth);
        move(leftShift,refer.height()-topPanelHeight-defaultSearchPanelHeight-leftShift);
    }
    else if (settingsPressed)
    {
        resize(refer.width()/6-panelShift,extendedSearchPanelHeight+strokeWidth);
        move(leftShift,refer.height()-topPanelHeight-extendedSearchPanelHeight-leftShift);
        replaceChoicePanels();
    }
    sortText->move(this->width()-ellipsesRad*3-SFProDislplayMetrics.horizontalAdvance(sortText->text()),strokeWidth);
}

void SearchByPar::mousePressEvent(QMouseEvent *event)
{
    if(isOnField(event->pos(),QRect(100,1,this->width()-101,this->height()-2)))
    {
        for(int c=0;c<choicePanel.size();c++)
        {
            if(isOnField(event->pos(),choicePanel[c]->geometry()))
            {
                choicePanel[c]->setPressed(true);
                sortType = c;
                emit sortTypeChanged(sortType);
            }
            else
            {
                choicePanel[c]->setPressed(false);
            }
        }
    }
    if(isOnField(event->position(),QRect(1,1,28,28)))
    {
        searchPressed = true;
        searchText->show();
        searchTextShower->hide();
        sortText->hide();
        searchText->setFocus();
    }
    else if(isOnField(event->position(),QRect(this->width()-30,1,28,28)))
    {
        QFontMetrics SFProDislplayMetrics(SFProDisplay);

        settingsPressed = true;
        emit changeSize(settingsPressed);
        searchTextShower->hide();
        replaceChoicePanels();
        showChoicePanel();
        sortText->hide();
    }
    this->update();
    this->setFocus();
}

void SearchByPar::mouseMoveEvent(QMouseEvent *event)
{
    if(!searchPressed and !settingsPressed)
    {
        if(isOnField(event->position(),QRect(1,1,28,28)))
        {
            this->setCursor(Qt::PointingHandCursor);
        }
        else if(isOnField(event->position(),QRect(this->width()-30,1,28,28)))
        {
            this->setCursor(Qt::PointingHandCursor);
        }
        else
        {
            this->setCursor(Qt::ArrowCursor);
        }
    }
    else
    {
        this->setCursor(Qt::ArrowCursor);
    }
}

void SearchByPar::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Enter || event->key() == Qt::Key_Return)
    {
        QFontMetrics SFProDislplayMetrics(SFProDisplay);

        searchPressed = false;
        searchText->hide();
        this->update();

        searchTextShower->setText(searchText->text());
        searchTextShower->resize(SFProDislplayMetrics.horizontalAdvance(searchText->text()),SFProDislplayMetrics.height());
        searchTextShower->show();

        settingsPressed= false;
        hideChoicePanel();
        switch(sortType)
        {
            case -1:
            sortText->setText("");
            sortText->setGeometry(this->width()-ellipsesRad*3-SFProDislplayMetrics.horizontalAdvance(sortText->text()),1,
                                  SFProDislplayMetrics.horizontalAdvance(sortText->text()),SFProDislplayMetrics.height());
            break;
            case 0:
            sortText->setText(":Name");
            sortText->setGeometry(this->width()-ellipsesRad*3-SFProDislplayMetrics.horizontalAdvance(sortText->text()),1,
                                  SFProDislplayMetrics.horizontalAdvance(sortText->text()),SFProDislplayMetrics.height());
            break;
            case 1:
            sortText->setText(":Surname");
            sortText->setGeometry(this->width()-ellipsesRad*3-SFProDislplayMetrics.horizontalAdvance(sortText->text()),1,
                                  SFProDislplayMetrics.horizontalAdvance(sortText->text()),SFProDislplayMetrics.height());
            break;
            case 2:
            sortText->setText(":Rank");
            sortText->setGeometry(this->width()-ellipsesRad*3-SFProDislplayMetrics.horizontalAdvance(sortText->text()),1,
                                  SFProDislplayMetrics.horizontalAdvance(sortText->text()),SFProDislplayMetrics.height());
            break;
        }
            sortText->show();

        emit changeSize(settingsPressed);

    }
}

void SearchByPar::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter drawer(this);
    doPainting(&drawer);
}

void SearchByPar::doPainting(QPainter *drawer)
{
    drawer->setRenderHint(QPainter::Antialiasing);

    QPen myPen;
    QBrush myBrush;
    QPainterPath myPath;

    myPen.setColor(QColor(29,29,29));
    myPen.setWidth(2);
    myBrush.setColor(QColor(70,70,70));
    myBrush.setStyle(Qt::SolidPattern);

    drawer->setPen(myPen);
    drawer->setBrush(myBrush);

    if(!searchPressed and !settingsPressed)
    {
        drawer->drawEllipse(QRect(strokeWidth,strokeWidth,ellipsesRad*2-strokeWidth,ellipsesRad*2-strokeWidth));
        drawer->drawEllipse(QRect(this->width()-ellipsesRad*2-strokeWidth,strokeWidth,ellipsesRad*2-strokeWidth,ellipsesRad*2-strokeWidth));

        myPath.addEllipse(QRect(strokeWidth*5,strokeWidth*5,ellipsesRad-strokeWidth,ellipsesRad-strokeWidth));
        myBrush.setColor(QColor(0,0,0,0));
        myPen.setWidth(3);
        drawer->setPen(myPen);
        drawer->setBrush(myBrush);

        drawer->drawPath(myPath);

        myPath.clear();

        drawer->drawLine(strokeWidth*4+ellipsesRad,strokeWidth*4+ellipsesRad,ellipsesRad*2-strokeWidth*5,ellipsesRad*2-strokeWidth*5);

        myBrush.setColor(QColor(29,29,29));
        drawer->setPen(myPen);
        drawer->setBrush(myBrush);

        myPath.moveTo(this->width()-ellipsesRad*2+4,8);
        myPath.lineTo(this->width()-ellipsesRad*2+13,8);
        myPath.lineTo(this->width()-ellipsesRad*2+8.5,13);
        myPath.lineTo(this->width()-ellipsesRad*2+4,8);
        myPath.moveTo(this->width()-ellipsesRad*2+8.5,13);
        myPath.lineTo(this->width()-ellipsesRad*2+8.5,14);

        drawer->drawPath(myPath);
        myPath.clear();
    }
    else if(searchPressed)
    {
        myPath.addRoundedRect(1,1,this->width()-2,this->height()-2,10,10);
        drawer->drawPath(myPath);
        myPath.clear();
    }
    else if(settingsPressed)
    {
        myPen.setColor(QColor(29,29,29));
        myBrush.setColor(QColor(40,40,40));

        drawer->setPen(myPen);
        drawer->setBrush(myBrush);

        myPath.addRoundedRect(this->width()/2,1,this->width()/2-strokeWidth,this->height()-2,10,10);

        drawer->drawPath(myPath);
        myPath.clear();
    }
}

void SearchByPar::replaceChoicePanels()
{
    for(int c=0;c<choicePanel.size();c++)
    {
        choicePanel[c]->resize(this->width()/2-strokeWidth,choicePanel[c]->height());
        choicePanel[c]->move(this->width()/2,2+c*choicePanel[c]->height());
    }
}

void SearchByPar::showChoicePanel()
{
    for(int c=0;c<choicePanel.size();c++)
    {
        choicePanel[c]->show();
        choicePanel[c]->setPressed(false);
    }
}

void SearchByPar::hideChoicePanel()
{
    for(int c=0;c<choicePanel.size();c++)
    {
        choicePanel[c]->hide();
    }
}

void SearchByPar::initShifts()
{
    panelShift =20;
    lineEditShift =5;
    leftShift = 6;
    strokeWidth = 1;
    ellipsesRad = 10;

    defaultSearchPanelHeight = 20;
    extendedSearchPanelHeight = 60;

    topPanelHeight = 30;
}

bool SearchByPar::isOnField(const QPointF& point, const QRectF& rect)
{
    return (rect.topLeft().x()<point.x() && rect.topLeft().y()<point.y() &&
            rect.bottomRight().x()>point.x() && rect.bottomRight().y()>point.y());
}
