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

#include <QtGui/QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
  Triangle tr(15,29,20);
  std::cout << tr.GetSideA() << std::endl;
  std::cout << tr.GetSideB() << std::endl;
  std::cout << tr.GetSideC() << std::endl;
  std::cout << tr.GetAltitudeA() << std::endl;
  std::cout << tr.GetAltitudeB() << std::endl;
  std::cout << tr.GetAltitudeC() << std::endl;
  std::cout << tr.GetBisectorA() << std::endl;
  std::cout << tr.GetBisectorB() << std::endl;
  std::cout << tr.GetBisectorC() << std::endl;
  std::cout << tr.GetMedianA() << std::endl;
  std::cout << tr.GetMedianB() << std::endl;
  std::cout << tr.GetMedianC() << std::endl;
  std::cout << tr.GetInscribedR() << std::endl;
  std::cout << tr.GetOutscribedR() << std::endl; 
  std::cout << tr.GetArea() << std::endl;
  std::cout << tr.GetPerimeter() << std::endl;
  std::cout << tr.GetAngleA() << std::endl;
  std::cout << tr.GetAngleB() << std::endl;
  std::cout << tr.GetAngleC() << std::endl;
  QApplication a(argc, argv);
  MainWindow w;
  w.show();

  return a.exec();
  return 0;
}
