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
  Synopsis - QT GUI header file.
**********************************************************************/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "triangle.h"
#include "area.h"
#include "trpoints.h"
#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
  Triangle* m_triangle;    
  TrPoints* m_calc; 
  Area m_area;
  QPainter *m_painter;
  QColor *m_color;
  QPen *m_pen;
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
    void paintEvent(QPaintEvent *);
    bool eventFilter(QObject *obj, QEvent *event);
public slots:
  void handleSelectionChanged(int index);    
private slots:
    void on_pushButton1_clicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
