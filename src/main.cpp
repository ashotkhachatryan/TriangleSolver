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
  Synopsis - Entry point.
**********************************************************************/

#include <iostream>
#include "triangle.h"
#include "trpoints.h"
#include "area.h"
#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
  Area area;
  area.width = 200;
  area.height = 200;
  area.topMargin = 20;
  area.bottomMargin = 20;
  area.leftMargin = 20;
  area.rightMargin = 20;
  area.X = 10;
  area.Y = 50;

  Triangle* tr = new Triangle(15,29,20);
  //Triangle tr(a, b, c);
  TrPoints calc(tr, area); 

  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
}
