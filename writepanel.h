
#ifndef WRITEPANEL_H
#define WRITEPANEL_H

#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QEvent>
#include <QResizeEvent>
#include <QMainWindow>
#include <QPainter>
#include <QPainterPath>
#include <QFontMetrics>
#include <QGraphicsDropShadowEffect>


class WritePanel : public QLabel
{
public:
    WritePanel(QLabel* parent = nullptr);

    QGraphicsDropShadowEffect* shadow;

    QString getText();
    void setPasswordType(bool);
    void setText(const QString& refer);
    void hideText();
    void showText();

    QLineEdit* getEditPanel();

protected:

    void resizeEvent(QResizeEvent* event);

private:
    QFont SFProDisplay;

    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    bool isOnField(const QPointF& point, const QRectF& rect);

    QLineEdit* edit;

    QLabel* text;

    void setVisibility();
};

#endif // WRITEPANEL_H
