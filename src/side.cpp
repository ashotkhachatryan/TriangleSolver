
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
#include <iostream>
#include <side.h>

QColor* Side::gDefaultColor = new QColor(Qt::black);

Side::Side()
{
  m_color = new QColor(Qt::black);
}

Side::Side(double pLength)
{
  m_color = new QColor(Qt::black);
  m_length = pLength;
}

Side::~Side()
{
  //delete m_color;
}

double
Side::GetLength()
{
  return m_length;
}

void
Side::SetLength(double pLength)
{
  m_length = pLength;
}

void
Side::SetColor(QColor* pColor)
{
  m_color = pColor;
}

QColor*
Side::GetColor()
{
  return m_color;
}

void
Side::SetStartPoint(Point pStartPoint)
{
  m_startPoint = pStartPoint;
}

void
Side::SetEndPoint(Point pEndPoint)
{
  m_endPoint = pEndPoint;
}

void
Side::Draw(QPainter *pPainter)
{
  pPainter->setPen(*m_color);
  pPainter->drawLine(m_startPoint.X, m_startPoint.Y, m_endPoint.X, m_endPoint.Y);
}
