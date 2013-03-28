#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QTimeLine>
#include <QGraphicsItemAnimation>
#include <QPushButton>

#include "bouncingrectangle.h"

#define WINDOW_MAX_X 250
#define WINDOW_MAX_Y 250

class MainWindow : public QWidget {
    Q_OBJECT
    
public:
    explicit MainWindow();
    ~MainWindow();

    void show();
    
private:
    QGraphicsScene *scene;
    QGraphicsView *view;
    QTimer *timer;
    QTimer *timer2;
    BouncingRectangle *item;
    QPushButton *button;
    QList<BouncingRectangle*> rectangles;

public slots:
    void handleTimer();
    void buttonPress();
    void addRectangle();

};

#endif // MAINWINDOW_H
