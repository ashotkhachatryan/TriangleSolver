/********************************************************************

   Copyright (C) 2014 Ashot Khachatryan <ashkhachatryana@gmail.com>

*********************************************************************
   This progarm is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
 
   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  
   02110-1301, USA.

**********************************************************************
  Synopsis - QT GUI implementation.
**********************************************************************/

#include <iostream>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include "triangle.h"
#include "trpoints.h"
#include "area.h"

double a;
double b;
double c;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    a = 10; b = 10; c = 10;
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
  Triangle tr(a, b, c);
  TrPoints calc(tr, area); 
  
  painter.drawRect(0 + area.X, 0 + area.Y, area.width, area.height);
  painter.drawLine(calc.GetPointA().X, calc.GetPointA().Y, calc.GetPointB().X, calc.GetPointB().Y);
  painter.drawLine(calc.GetPointB().X, calc.GetPointB().Y, calc.GetPointC().X, calc.GetPointC().Y);
  painter.drawLine(calc.GetPointA().X, calc.GetPointA().Y, calc.GetPointC().X, calc.GetPointC().Y);
  this->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
  a = ui->lineEdit1->text().toDouble();
  b = ui->lineEdit2->text().toDouble();
  c = ui->lineEdit3->text().toDouble();
}
