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
  Synopsis - Triangle side implementation.
**********************************************************************/

#include "qpainter.h"
#include "point.h"

class Side
{
public:
  Side();
  Side(double pLength);
  ~Side();
private:
  double m_length;
  QColor* m_color;  
  Point m_startPoint;
  Point m_endPoint;
public:
  double GetLength();
  void SetLength(double pLength);
  void SetColor(QColor* pColor);
  QColor* GetColor();
  void SetStartPoint(Point pStartPoint);
  void SetEndPoint(Point pEndPoint);
public:
  void Draw(QPainter *pPainter);
  static QColor* gDefaultColor;
};
