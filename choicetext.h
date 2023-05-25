#ifndef CHOICETEXT_H
#define CHOICETEXT_H

#include <QLabel>
#include <QMouseEvent>
#include <QPainter>
#include <QRadialGradient>

class ChoiceText : public QLabel
{
    Q_OBJECT
public:
    ChoiceText(QString referText = "set text",QLabel* parent = nullptr);

    void setText(QString refer);
protected:
    void mouseMoveEvent(QMouseEvent* event);

    bool isOnField(const QPointF& point, const QRectF& rect);

private:
    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    QFont SFProDisplay;

    QLabel* text;

    QPoint mousePoint = QPoint(-120,-120);
    bool pressed = false;
    bool outSide = false;

public slots:
    void setPressed(bool choice);
};

#endif // CHOICETEXT_H
