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
#include "apex.h"

class Side
{
public:
  Side();
  Side(double pLength);
  ~Side();
private:
  double m_length;
  QColor* m_color;  
  Apex* m_startApex;
  Apex* m_endApex;
  Point m_middleLetterLocation;
  std::string m_middleLetter;
public:
  double GetLength();
  void SetLength(double pLength);
  void SetColor(QColor* pColor);
  QColor* GetColor();
  void SetStartApex(Apex* pStartApex);
  void SetEndApex(Apex* pEndApex);
  Point GetMiddleLetterLocation();
  void FindMiddleLetterLocation();
  void FindApexLetterLocation();
  void SetMiddleLetter(std::string pMiddleLetter);
public:
  void Draw(QPainter *pPainter);
  static QColor* gDefaultColor;
private:
};
