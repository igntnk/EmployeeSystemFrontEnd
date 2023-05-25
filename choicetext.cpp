#include "choicetext.h"

ChoiceText::ChoiceText(QString referText,QLabel* parent):
    QLabel(parent)
{
    SFProDisplay = QFont("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);

    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    this->resize(parent->width()-100,SFProDislplayMetrics.height()+8);
    this->setMouseTracking(true);

    text = new QLabel(this);

    text->setFont(SFProDisplay);
    text->setMouseTracking(true);
    text->setText(referText);
    text->resize(SFProDislplayMetrics.horizontalAdvance(referText),SFProDislplayMetrics.height());
    text->move(this->geometry().topLeft().x()+12,this->geometry().topLeft().y()+4);
}

void ChoiceText::setText(QString refer)
{
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    text->setText(refer);
    text->resize(SFProDislplayMetrics.horizontalAdvance(refer),SFProDislplayMetrics.height());
}

void ChoiceText::mouseMoveEvent(QMouseEvent *event)
{
    if(isOnField(event->pos(),QRect(2,0,this->width(),this->height()-4)))
    {
        mousePoint = event->pos();
        outSide = false;
        this->update();
    }
    else
    {
        outSide = true;
        this->update();
    }

}

bool ChoiceText::isOnField(const QPointF &point, const QRectF &rect)
{
    return (rect.topLeft().x()<point.x() && rect.topLeft().y()<point.y() &&
            rect.bottomRight().x()>point.x() && rect.bottomRight().y()>point.y());
}

void ChoiceText::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter drawer(this);
    doPainting(&drawer);
}

void ChoiceText::doPainting(QPainter *drawer)
{
    drawer->setRenderHint(QPainter::Antialiasing);

    QPen myPen;
    QBrush myBrush;
    QRadialGradient gradient(mousePoint,80);
    gradient.setColorAt(0,QColor(200,200,200,60));
    gradient.setColorAt(1,QColor(0,0,0,0));
    drawer->setBrush(gradient);

    myPen.setColor(QColor(200,200,200,0));
    myPen.setWidth(2);

    drawer->setPen(myPen);

    if(pressed)
    {
        drawer->fillRect(QRect(0,0,this->width(),this->height()),QColor(200,200,200,70));
    }
    else
    {
        if(outSide)
        {
            myPen.setColor(QColor(200,200,200,0));
            myBrush.setColor(QColor(200,200,200,0));
            drawer->setPen(myPen);
            drawer->setBrush(myBrush);
        }
        drawer->drawEllipse(mousePoint.x()-80,mousePoint.y()-80,160,160);
    }
}

void ChoiceText::setPressed(bool choice)
{
    pressed = choice;
    this->update();
}
