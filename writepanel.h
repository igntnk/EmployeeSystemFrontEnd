
#ifndef WRITEPANEL_H
#define WRITEPANEL_H

#include <QLabel>
#include <QTextEdit>
#include <QLineEdit>
#include <QEvent>
#include <QMainWindow>
#include <QPainter>
#include <QPainterPath>
#include <QFontMetrics>


class WritePanel : public QLabel
{
public:
    WritePanel(QLabel* parent = nullptr);

    QString getText();
    void setPasswordType(bool);
    void setText(const QString& refer);
    void hideText();
    void showText();


    QLineEdit* getEditPanel();

private:
    QFont SFProDisplay;

    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    bool isOnField(const QPointF& point, const QRectF& rect);

    QLineEdit* edit;

    QLabel* text;
};

#endif // WRITEPANEL_H
