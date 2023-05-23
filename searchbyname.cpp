
#include "searchbyname.h"

SearchByName::SearchByName(QMainWindow* parent):
    QLabel(parent)
{
    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(30);
    shadow->setOffset(0,0);
    shadow->setColor(QColor(0,0,0,100));

    SFProDisplay = QFont("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);

    this->resize(parent->width()/6-20,30);
    this->setGraphicsEffect(shadow);
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
    connect(searchText,&QLineEdit::textChanged,this,&SearchByName::textChanged);

    SFProDisplay.setPixelSize(22);

    searchTextShower = new QLabel(this);
    searchTextShower->setFont(SFProDisplay);
    searchTextShower->move(40,1);
    searchTextShower->setStyleSheet("color: rgb(140,140,140);");
}

void SearchByName::resizeEvent(QRect refer)
{
    this->resize(refer.width()/6-20,40);
    this->move(10,refer.height()-90);

}

void SearchByName::mousePressEvent(QMouseEvent *event)
{
    if(isOnField(event->position(),QRect(1,1,28,28)))
    {
        searchPressed = true;
        searchText->show();
        searchTextShower->hide();
        this->update();
    }
}

void SearchByName::mouseMoveEvent(QMouseEvent *event)
{
    if(!searchPressed)
    {
        if(isOnField(event->position(),QRect(1,1,28,28)))
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

void SearchByName::keyPressEvent(QKeyEvent *event)
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
    }
}


void SearchByName::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter drawer(this);
    doPainting(&drawer);
}

void SearchByName::doPainting(QPainter *drawer)
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

    if(!searchPressed)
    {
        drawer->drawEllipse(QRect(1,1,28,28));

        myPath.addEllipse(QRect(8,8,12,12));
        myBrush.setColor(QColor(0,0,0,0));
        myPen.setWidth(3);
        drawer->setPen(myPen);
        drawer->setBrush(myBrush);

        drawer->drawPath(myPath);

        drawer->drawLine(21,21,19,19);
    }
    else
    {
        myPath.addRoundedRect(1,1,this->width()-2,this->height()-2,5,5);
        drawer->drawPath(myPath);
    }
}

bool SearchByName::isOnField(const QPointF& point, const QRectF& rect)
{
    return (rect.topLeft().x()<point.x() && rect.topLeft().y()<point.y() &&
            rect.bottomRight().x()>point.x() && rect.bottomRight().y()>point.y());
}
