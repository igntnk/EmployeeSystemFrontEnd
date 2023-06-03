
#ifndef SEARCHBYNAME_H
#define SEARCHBYNAME_H

#include <QLabel>
#include <QMainWindow>
#include <QPainter>
#include <QPainterPath>
#include <QMouseEvent>
#include <QLineEdit>
#include <vector>
#include "choicetext.h"

class SearchByPar : public QLabel
{
    Q_OBJECT
public:
    SearchByPar(QMainWindow* parent = nullptr);

    void resizeEvent(QRect refer);

protected:
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void keyPressEvent(QKeyEvent *event);

    bool isOnField(const QPointF& point, const QRectF& rect);

private:
    void paintEvent(QPaintEvent *event);
    void doPainting(QPainter* drawer);

    QFont SFProDisplay;

    bool searchPressed = false;
    QLineEdit* searchText;
    bool settingsPressed = false;

    QLabel* searchTextShower;

    std::vector<ChoiceText*> choicePanel;
    void replaceChoicePanels();
    void showChoicePanel();
    void hideChoicePanel();
    int sortType= 0;
    QLabel* sortText;

    void initShifts();

    int panelShift;
    int lineEditShift;
    int strokeWidth;
    int ellipsesRad;
    int defaultSearchPanelHeight;
    int extendedSearchPanelHeight;
    int topPanelHeight;
    int leftShift;

signals:
    void textChanged(const QString &text);
    void changeSize(bool opened);
    void sortTypeChanged(int type);
};

#endif // SEARCHBYNAME_H
