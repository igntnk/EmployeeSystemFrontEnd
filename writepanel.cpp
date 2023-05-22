#include "writepanel.h"

WritePanel::WritePanel(QLabel* parent):
    QLabel(parent)
{
    shadow = new QGraphicsDropShadowEffect(this);
    shadow->setBlurRadius(30);
    shadow->setOffset(0,0);
    shadow->setColor(QColor(0,0,0,200));

    SFProDisplay = QFont("SF Pro Display", 13);
    SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
    SFProDisplay.setWeight(QFont::Bold);
    QFontMetrics SFProDislplayMetrics(SFProDisplay);

    this->setGeometry(0,0,200,40);
    this->setGraphicsEffect(shadow);

    edit = new QLineEdit(this);
    edit->setGeometry(8,5,this->width()-10,this->height()-10);
    edit->setFont(SFProDisplay);
    edit->setStyleSheet("QLineEdit{"
                        "color: rgb(180,180,180);"
                        "background-color: rgba(0,0,0,0);"
                        "}");
    edit->setFrame(false);

    text = new QLabel(this);
    text->setText("SETTEXT");
    text->setFont(SFProDisplay);
    text->setStyleSheet("color: rgb(80,80,80)");
    text->setGeometry(this->geometry().topLeft().x()+10,this->height()/4,
                      this->width(),SFProDislplayMetrics.height());
    text->setAttribute(Qt::WA_TransparentForMouseEvents);
}

void WritePanel::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter drawer(this);
    doPainting(&drawer);
}

void WritePanel::doPainting(QPainter* drawer)
{
    drawer->setRenderHint(QPainter::Antialiasing);

    QPen myPen;
    QBrush myBrush;
    QPainterPath myPath;

    myPath.moveTo(0,0);
    myPath.addRoundedRect(QRect(1,1,this->width()-2,this->height()-2),5,5);

    myPen.setColor(QColor(200,200,200));
    myPen.setWidth(1);

    myBrush.setColor(QColor(20,20,20));
    myBrush.setStyle(Qt::SolidPattern);

    drawer->setBrush(myBrush);
    drawer->setPen(myPen);
    drawer->drawPath(myPath);

    connect(edit,&QLineEdit::textChanged,this,&WritePanel::setVisibility);

    myPath.clear();
}

void WritePanel::setVisibility()
{
    if(getText() == "")
    {
        showText();
    }
    else
    {
        hideText();
    }
}

QString WritePanel::getText()
{
    return edit->text();
}

void WritePanel::setPasswordType(bool type)
{
    if(type)
    {
        SFProDisplay = QFont("SF Pro Display", 9);
        SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
        SFProDisplay.setWeight(QFont::Thin);
        edit->setEchoMode(QLineEdit::Password);
        edit->setFont(SFProDisplay);
        edit->move(8,6);
    }
    else
    {
        SFProDisplay = QFont("SF Pro Display", 13);
        SFProDisplay.setStyleStrategy(QFont::PreferAntialias);
        SFProDisplay.setWeight(QFont::Bold);
        edit->setEchoMode(QLineEdit::Normal);
        edit->move(8,5);
    }
}

void WritePanel::setText(const QString& refer)
{
    edit->clear();
    text->setText(refer);
}

QLineEdit* WritePanel::getEditPanel()
{
    return edit;
}

void WritePanel::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    edit->setGeometry(8,5,this->width()-10,this->height()-10);
}

void WritePanel::hideText()
{
    text->hide();
}

void WritePanel::showText()
{
    text->show();
}
