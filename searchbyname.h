
#ifndef SEARCHBYNAME_H
#define SEARCHBYNAME_H

#include <QLabel>
#include <QMainWindow>
#include <QPainter>
#include <QPainterPath>
#include <QGraphicsDropShadowEffect>
#include <QMouseEvent>
#include <QLineEdit>

class SearchByName : public QLabel
{
    Q_OBJECT
public:
    SearchByName(QMainWindow* parent = nullptr);

    void resizeEvent(QRect refer);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void keyPressEvent(QKeyEvent *event);

    bool isOnField(const QPointF& point, const QRectF& rect);

private:
    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    QGraphicsDropShadowEffect* shadow;
    QFont SFProDisplay;

    bool searchPressed = false;
    QLineEdit* searchText;

    QLabel* searchTextShower;

signals:
    void textChanged(const QString &text);
};

#endif // SEARCHBYNAME_H
