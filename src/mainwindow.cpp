#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include "triangle.h"
#include "calcpoints.h"
#include "area.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void
MainWindow::paintEvent(QPaintEvent* event)
{
  (void)event;
  Area area;
  area.width = 200;
  area.height = 200;
  area.topMargin = 20;
  area.bottomMargin = 20;
  area.leftMargin = 20;
  area.rightMargin = 20;
  area.X = 10;
  area.Y = 50;

  QPainter painter(this);
  Triangle tr(200,320,150);
  CalcPoints calc(tr, area); 
  
  painter.drawRect(0 + area.X, 0 + area.Y, area.width, area.height);
  painter.drawLine(calc.GetPointA().X, calc.GetPointA().Y, calc.GetPointB().X, calc.GetPointB().Y);
  painter.drawLine(calc.GetPointB().X, calc.GetPointB().Y, calc.GetPointC().X, calc.GetPointC().Y);
  painter.drawLine(calc.GetPointA().X, calc.GetPointA().Y, calc.GetPointC().X, calc.GetPointC().Y);
}

MainWindow::~MainWindow()
{
    delete ui;
}
