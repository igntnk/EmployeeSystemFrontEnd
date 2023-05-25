
#include "searchbyname.h"

SearchByPar::SearchByPar(QMainWindow* parent):
    QLabel(parent)
{
    SFProDisplay = QFont("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);

    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    this->resize(parent->width()/6-20,30);
    this->setMouseTracking(true);

    searchText = new QLineEdit(this);
    searchText->setStyleSheet("QLineEdit{"
                        "color: rgb(180,180,180);"
                        "background-color: rgba(0,0,0,0);"
                        "}");
    searchText->setFrame(false);
    searchText->setGeometry(this->geometry().topLeft().x()+5,this->geometry().topLeft().y(),this->width()-10,this->height());
    searchText->setFont(SFProDisplay);
    searchText->hide();
    connect(searchText,&QLineEdit::textChanged,this,&SearchByPar::textChanged);

    SFProDisplay.setPixelSize(22);

    searchTextShower = new QLabel(this);
    searchTextShower->setFont(SFProDisplay);
    searchTextShower->move(40,1);
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
    if(searchPressed)
    {
        this->resize(refer.width()/6-20,30);
        this->move(10,refer.height()-90);
    }
    else if (settingsPressed)
    {
        this->resize(refer.width()/6-20,90);
        this->move(10,refer.height()-150);
        replaceChoicePanels();
    }
    sortText->move(2,this->width()-40-sortText->text().length()*SFProDislplayMetrics.horizontalAdvance(sortText->text()));
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
        this->update();
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
        this->update();
        this->setFocus();
    }
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
            sortText->setGeometry(this->width()-40-SFProDislplayMetrics.horizontalAdvance(sortText->text()),1,
                                  SFProDislplayMetrics.horizontalAdvance(sortText->text()),SFProDislplayMetrics.height());
            break;
            case 0:
            sortText->setText(":Name");
            sortText->setGeometry(this->width()-40-SFProDislplayMetrics.horizontalAdvance(sortText->text()),1,
                                  SFProDislplayMetrics.horizontalAdvance(sortText->text()),SFProDislplayMetrics.height());
            break;
            case 1:
            sortText->setText(":Surname");
            sortText->setGeometry(this->width()-40-SFProDislplayMetrics.horizontalAdvance(sortText->text()),1,
                                  SFProDislplayMetrics.horizontalAdvance(sortText->text()),SFProDislplayMetrics.height());
            break;
            case 2:
            sortText->setText(":Rank");
            sortText->setGeometry(this->width()-40-SFProDislplayMetrics.horizontalAdvance(sortText->text()),1,
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
        drawer->drawEllipse(QRect(1,1,28,28));
        drawer->drawEllipse(QRect(this->width()-30,1,28,28));

        myPath.addEllipse(QRect(8,8,12,12));
        myBrush.setColor(QColor(0,0,0,0));
        myPen.setWidth(3);
        drawer->setPen(myPen);
        drawer->setBrush(myBrush);

        drawer->drawPath(myPath);

        myPath.clear();

        drawer->drawLine(21,21,19,19);

        myBrush.setColor(QColor(29,29,29));
        drawer->setPen(myPen);
        drawer->setBrush(myBrush);

        myPath.moveTo(this->width()-23,10);
        myPath.lineTo(this->width()-9,10);
        myPath.lineTo(this->width()-16,18);
        myPath.lineTo(this->width()-23,10);
        myPath.moveTo(this->width()-16,18);
        myPath.lineTo(this->width()-16,22);

        drawer->drawPath(myPath);
        myPath.clear();
    }
    else if(searchPressed)
    {
        myPath.addRoundedRect(1,1,this->width()-2,this->height()-2,15,15);
        drawer->drawPath(myPath);
        myPath.clear();
    }
    else if(settingsPressed)
    {
        myPen.setColor(QColor(29,29,29));
        myBrush.setColor(QColor(40,40,40));

        drawer->setPen(myPen);
        drawer->setBrush(myBrush);

        myPath.addRoundedRect(100,1,this->width()-101,this->height()-2,15,15);

        drawer->drawPath(myPath);
        myPath.clear();
    }
}

void SearchByPar::replaceChoicePanels()
{
    for(int c=0;c<choicePanel.size();c++)
    {
        choicePanel[c]->resize(this->width()-101,choicePanel[c]->height());
        choicePanel[c]->move(100,2+c*choicePanel[c]->height());
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

bool SearchByPar::isOnField(const QPointF& point, const QRectF& rect)
{
    return (rect.topLeft().x()<point.x() && rect.topLeft().y()<point.y() &&
            rect.bottomRight().x()>point.x() && rect.bottomRight().y()>point.y());
}
