#include "mainwindow.h"

void MainWindow::handleTimer() {
    item->move( WINDOW_MAX_X, WINDOW_MAX_Y );
    for(int i = 0; i < rectangles.size(); i++) {
    	rectangles[i]->move( WINDOW_MAX_X, WINDOW_MAX_Y );
    }
}

void MainWindow::buttonPress() {
		if(timer->isActive()) {
			timer->stop();
		} else {
			timer->start();
		}
		
		if(timer2->isActive()) {
			timer2->stop();
		} else {
			timer2->start();
		}		
}

void MainWindow::addRectangle() {
		BouncingRectangle* newRectangle = new BouncingRectangle(rand()%250, rand()%250, 20.0, 20.0, rand()%6, rand()%6);
		
		QBrush redBrush(Qt::red);
		QBrush blueBrush(Qt::blue);
		QBrush greenBrush(Qt::green);
		QBrush yellowBrush(Qt::yellow);
		
		int color = rand()%5;
		switch(color) {
			case 0:
			newRectangle->setBrush( redBrush );
			break;
			
			case 1:
			newRectangle->setBrush( blueBrush );
			break;
			
			case 2:
			newRectangle->setBrush( greenBrush );
			break;
			
			case 3:
			newRectangle->setBrush( yellowBrush );
			break;
		}
	
	rectangles.push_back(newRectangle);
	scene->addItem( newRectangle );
			
}

MainWindow::MainWindow()  {
    //We need a scene and a view to do graphics in QT
    scene = new QGraphicsScene();
    view = new QGraphicsView( scene );
		
		//This adds a button to the window and connects it to the timer
		button = new QPushButton("Start/Stop", view);
    connect(button, SIGNAL(clicked()), this, SLOT(buttonPress()));

    //To fill a rectangle use a QBrush. To draw the border of a shape, use a QPen
    QBrush redBrush(Qt::red);

    //First 2 arguments are the x, y, of the upper left of the rectangle.
    //The second 2 arguments are the width and height
    //The last 2 arguments are the velocity in the x, and y, directions
    item = new BouncingRectangle( 11.0, 74.0, 20.0, 20.0, 2, 3 );
    item->setBrush( redBrush );
    scene->addItem( item );

    //This sets the size of the window and gives it a title.
    view->setFixedSize( WINDOW_MAX_X*2, WINDOW_MAX_Y*2 );
    view->setWindowTitle( "Bouncing Rectangles!");

    //This is how we do animation. We use a timer with an interval of 5 milliseconds
    //We connect the signal from the timer - the timeout() function to a function
    //of our own - called handleTimer - which is in this same MainWindow class
    timer = new QTimer(this);
    timer->setInterval(5);
    connect(timer, SIGNAL(timeout()), this, SLOT(handleTimer()));
    
    timer2 = new QTimer(this);
    timer2->setInterval(250);
    connect(timer2, SIGNAL(timeout()), this, SLOT(addRectangle()));

}

void MainWindow::show() {
    //This is only called once by main. Timers don't start working until
    //we call start
    timer->start();
    
    timer2->start();
    
    //This is how we get our view displayed.
    view->show();
}

MainWindow::~MainWindow()
{
    timer->stop();
    timer2->stop();
    delete timer;
    delete timer2;
    delete item;
    for(int i = 0; i < rectangles.size(); i++) {
    	delete rectangles[i];
    }
    delete button;
    delete scene;
    delete view;
}
