
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
Side::SetStartApex(Apex* pStartApex)
{
  m_startApex = pStartApex;
}

void
Side::SetEndApex(Apex* pEndApex)
{
  m_endApex = pEndApex;
}

Point
Side::GetMiddleLetterLocation()
{
  return m_middleLetterLocation;
}

void
Side::SetMiddleLetter(std::string pMiddleLetter)
{
  m_middleLetter = pMiddleLetter;
}

void
Side::FindMiddleLetterLocation()
{
  m_middleLetterLocation.X = m_startApex->GetLocation().X;
  m_middleLetterLocation.Y = m_startApex->GetLocation().Y;
}

void
Side::FindApexLetterLocation()
{
  m_startApex->GetApexLetterLocation()->X = (((m_startApex->GetLetterDistance() + m_length)*m_startApex->GetLocation().X) - m_startApex->GetLetterDistance()*m_endApex->GetLocation().X) / m_length;
  m_startApex->GetApexLetterLocation()->Y = (((m_startApex->GetLetterDistance() + m_length)*m_startApex->GetLocation().Y) - m_startApex->GetLetterDistance()*m_endApex->GetLocation().Y) / m_length;
  //m_startApex->GetApexLetterLocation()->X = m_startApex->GetLocation().X;
  //m_startApex->GetApexLetterLocation()->Y = m_startApex->GetLocation().Y;
}

void
Side::Draw(QPainter *pPainter)
{
  pPainter->setPen(*m_color);
  pPainter->drawLine(m_startApex->GetLocation().X, m_startApex->GetLocation().Y, m_endApex->GetLocation().X, m_endApex->GetLocation().Y);
  //pPainter->drawText(m_middleLetterLocation.X, m_middleLetterLocation.Y, QString::fromStdString(m_middleLetter));
  m_startApex->Draw(pPainter);
}
