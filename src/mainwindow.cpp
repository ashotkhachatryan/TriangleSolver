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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
  ui->setupUi(this);
  connect(ui->comboBox, SIGNAL(currentIndexChanged(int)),this,SLOT(handleSelectionChanged(int)));
  m_triangle = new Triangle(10,10,10);

  m_area.width = 200;
  m_area.height = 200;
  m_area.topMargin = 20;
  m_area.bottomMargin = 20;
  m_area.leftMargin = 20;
  m_area.rightMargin = 20;
  m_area.X = 10;
  m_area.Y = 50;

  m_calc = new TrPoints(m_triangle, m_area);
  ui->lineEdit1->installEventFilter(this);
  ui->lineEdit2->installEventFilter(this);
  ui->lineEdit3->installEventFilter(this);
  ui->lineEdit4->installEventFilter(this);
  ui->lineEdit5->installEventFilter(this);
  ui->lineEdit6->installEventFilter(this);

}

bool
MainWindow::eventFilter(QObject *obj, QEvent *event)
{
  QLineEdit* edit = dynamic_cast<QLineEdit*>(obj);
  if (event->type() == QEvent::MouseButtonPress)
  {
    if (edit == ui->lineEdit1 || edit == ui->lineEdit4) {
      m_triangle->GetSideA()->SetColor(new QColor(Qt::red));
      m_triangle->GetSideB()->SetColor(Side::gDefaultColor);
      m_triangle->GetSideC()->SetColor(Side::gDefaultColor);
    } else if (edit == ui->lineEdit2 || edit == ui->lineEdit5) {
      m_triangle->GetSideA()->SetColor(new QColor(Qt::black));
      m_triangle->GetSideB()->SetColor(new QColor(Qt::red));
      m_triangle->GetSideC()->SetColor(new QColor(Qt::black));
    } else if (edit == ui->lineEdit3 || edit == ui->lineEdit6) {
      m_triangle->GetSideA()->SetColor(new QColor(Qt::black));
      m_triangle->GetSideB()->SetColor(new QColor(Qt::black));
      m_triangle->GetSideC()->SetColor(new QColor(Qt::red));
    } 
    return true;
  } else {
    return false;
  }
}

void
MainWindow::paintEvent(QPaintEvent* event)
{
  (void)event;
  m_painter = new QPainter(this);//QPainter painter(this);
//  m_painter->setPen(Qt::black); 

  //m_triangle->GetSideA()->SetColor(m_color);
  //m_triangle->GetSideB()->SetColor(q);
//  std::cout << m_triangle->GetSideA()->GetColor()->name().toStdString() << std::endl;
  m_calc->Draw(m_painter);
  delete m_painter;
  this->update();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton1_clicked()
{
  if (ui->tabWidget->currentIndex() == 0) {
    double a = ui->lineEdit1->text().toDouble();
    double b = ui->lineEdit2->text().toDouble();
    double c = ui->lineEdit3->text().toDouble();
    m_triangle = new Triangle(a,b,c);
  } else {
    double a = ui->lineEdit4->text().toDouble();
    double b = ui->lineEdit5->text().toDouble();
    double angle = ui->lineEdit6->text().toDouble();
    if (ui->comboBox->currentIndex() == 0) {
      m_triangle = new Triangle(a, b, angle, Triangle::eANGLEA);
    } else if (ui->comboBox->currentIndex() == 1) {
      m_triangle = new Triangle(a, b, angle, Triangle::eANGLEB);
    } else if (ui->comboBox->currentIndex() == 2) {
      m_triangle = new Triangle(a, b, angle, Triangle::eANGLEC);
    }
  }
  m_calc = new TrPoints(m_triangle, m_area);
}

void MainWindow::handleSelectionChanged(int index)
{
  if (index == 0) {
    ui->label4->setText("a =");
    ui->label5->setText("c =");
    ui->label6->setText("^A =");
  } else if (index == 1) {
    ui->label4->setText("a =");
    ui->label5->setText("b =");
    ui->label6->setText("^B =");
  } else if (index == 2) {
    ui->label4->setText("b =");
    ui->label5->setText("c =");
    ui->label6->setText("^C =");
  }
}
