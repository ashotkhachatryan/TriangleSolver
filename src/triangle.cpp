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
  Synopsis - Triangle implementation.
**********************************************************************/
#include <iostream>
#include "triangle.h"
#include "math.h"

// Sets all properties
void
Triangle::SetProperties(void)
{
  this->SetPerimeter();
  SetArea();
  SetAngleA();
  SetAngleB();
  SetAngleC();
  SetAltitudeA();
  SetAltitudeB();
  SetAltitudeC();
  SetBisectorA();
  SetBisectorB();
  SetBisectorC();
  SetMedianA();
  SetMedianB();
  SetMedianC();
  SetOutscribedR();
  SetInscribedR();
}

void
Triangle::SetArea(void)
{
  // The Heron formula s=sqrt(p(p-a)(p-b)(p-c))
  m_area = sqrt((GetPerimeter()/2) *
                ((GetPerimeter()/2) - m_sideA.GetLength()) *
                ((GetPerimeter()/2) - m_sideB.GetLength()) *
                ((GetPerimeter()/2) - m_sideC.GetLength()));
}

double
Triangle::SetAngle(Side pSideX, Side pSideY, Side pSideZ)
{
  // asin(2S/ab)
  double lAngle = (180 * asin((2 * m_area) / (pSideX.GetLength() * pSideY.GetLength())))/PI;
  if ((pSideZ.GetLength() * pSideZ.GetLength()) > ((pSideX.GetLength() * pSideX.GetLength()) + (pSideY.GetLength() * pSideY.GetLength())))
    return lAngle + ((90-lAngle)*2);
  else 
    return lAngle;
}

double
Triangle::SetAltitude(Side pSide)
{
  // 2*S/a;
  return (2 * GetArea()) / pSide.GetLength();
}

double
Triangle::SetBisector(Side pSideX, Side pSideY, Side pAngle)
{
  // 2*b*c*cos(C/2)/(b+c)
  return  2 * pSideX.GetLength()  * pSideY.GetLength() * 
          cos(((PI * (pAngle.GetLength() / 2)) / 180)) / 
          (pSideX.GetLength() + pSideY.GetLength());
}

double
Triangle::SetMedian(Side pSide, Side pSideX, Side pSideY)
{
  // sqrt(2b^2+2c^2-a^2)/2;
  return (sqrt(2 * pSideX.GetLength() * pSideX.GetLength() + 
              2 * pSideY.GetLength() * pSideY.GetLength() - 
              pSide.GetLength() * pSide.GetLength())) / 2;
}

void
Triangle::SetOutscribedR(void)
{
  // (abc)/sqrt(a+b+c)(b+c-a)(c+a-b)(a+b-c)
  m_outscribedR = (m_sideA.GetLength() * m_sideB.GetLength() * m_sideC.GetLength()) / 
          sqrt(
          (m_sideA.GetLength() + m_sideB.GetLength() + m_sideC.GetLength()) * 
          (m_sideB.GetLength() + m_sideC.GetLength() - m_sideA.GetLength()) * 
          (m_sideC.GetLength() + m_sideA.GetLength() - m_sideB.GetLength()) * 
          (m_sideA.GetLength() + m_sideB.GetLength() - m_sideC.GetLength()));
}

double
Triangle::GetSideByTwoSidesAngle(Side pSideA, Side pSideB, double pAngle)
{
  // The cosin formula. a^2+b^2-2abcos(alpha)
  return sqrt((pSideA.GetLength() * pSideA.GetLength()) + (pSideB.GetLength() * pSideB.GetLength()) - 
      (2 * pSideA.GetLength() * pSideB.GetLength() * cos((pAngle * PI) / 180)));
}


// Getter and Setter simple functions
double
Triangle::GetArea(void)
{
  return m_area;
}

void
Triangle::SetAngleA(void)
{
 m_angleA = SetAngle(m_sideA, m_sideC, m_sideB); 
}

double
Triangle::GetAngleA(void)
{
  return m_angleA;
}

void
Triangle::SetAngleB(void)
{
 m_angleB = SetAngle(m_sideA, m_sideB, m_sideC); 
}

double
Triangle::GetAngleB(void)
{
  return m_angleB;
}

void
Triangle::SetAngleC(void)
{
 m_angleC = SetAngle(m_sideB, m_sideC, m_sideA); 
}

double
Triangle::GetAngleC(void)
{
  return m_angleC;
}

void
Triangle::SetPerimeter(void)
{
  m_perimeter = m_sideA.GetLength() + m_sideB.GetLength() + m_sideC.GetLength();
}

double
Triangle::GetPerimeter(void)
{
  return m_perimeter;
}


void
Triangle::SetAltitudeA(void)
{
  m_altitudeA = SetAltitude(m_sideA); 
}

double
Triangle::GetAltitudeA(void)
{
  return m_altitudeA;
}

void
Triangle::SetAltitudeB(void)
{
  m_altitudeB = SetAltitude(m_sideB); 
}

double
Triangle::GetAltitudeB(void)
{
  return m_altitudeB;
}

void
Triangle::SetAltitudeC(void)
{
  m_altitudeC = SetAltitude(m_sideC);
}

double
Triangle::GetAltitudeC(void)
{
  return m_altitudeC;
}

void
Triangle::SetBisectorA(void)
{
  m_bisectorA = SetBisector(m_sideB, m_sideC, m_angleC);
}

double
Triangle::GetBisectorA(void)
{
  return m_bisectorA;
}

void
Triangle::SetBisectorB(void)
{
  m_bisectorB = SetBisector(m_sideA, m_sideC, m_angleA);
}

double
Triangle::GetBisectorB(void)
{
  return m_bisectorB;
}

void
Triangle::SetBisectorC(void)
{
  m_bisectorC = SetBisector(m_sideA, m_sideB, m_angleB);
}

double
Triangle::GetBisectorC(void)
{
  return m_bisectorC;
}

void
Triangle::SetMedianA(void)
{
  m_medianA = SetMedian(m_sideA, m_sideB, m_sideC);
}

double
Triangle::GetMedianA(void)
{
  return m_medianA;
}

void
Triangle::SetMedianB(void)
{
  m_medianB = SetMedian(m_sideB, m_sideA, m_sideC);
}

double
Triangle::GetMedianB(void)
{
  return m_medianB;
}

void
Triangle::SetMedianC(void)
{
  m_medianC = SetMedian(m_sideC, m_sideB, m_sideA);
}

double
Triangle::GetMedianC(void)
{
  return m_medianC;
}

void
Triangle::SetInscribedR(void)
{
  m_inscribedR = GetArea() / (GetPerimeter()/2);
}

double
Triangle::GetInscribedR(void)
{
  return m_inscribedR;
}

double
Triangle::GetOutscribedR(void)
{
  return m_outscribedR;
}

Side*
Triangle::GetSideA(void)
{
  return &m_sideA;
}

void
Triangle::SetSideA(double pSideA)
{
  m_sideA.SetLength(pSideA);
}

Side*
Triangle::GetSideB(void)
{
  return &m_sideB;
}

void
Triangle::SetSideB(double pSideB)
{
  m_sideB.SetLength(pSideB);
}


Side*
Triangle::GetSideC(void)
{
  return &m_sideC;
}

void
Triangle::SetSideC(double pSideC)
{
  m_sideC.SetLength(pSideC);
}


Triangle::Triangle()
{
}

void
Triangle::Init(double pSideA, double pSideB, double pSideC)
{
  m_sideA.SetLength(pSideA);
  m_sideB.SetLength(pSideB);
  m_sideC.SetLength(pSideC);
  SetProperties();
}

Triangle::Triangle(double pSideA, double pSideB, double pSideC)
{
  // TODO: Check side correctness.
  Init(pSideA, pSideB, pSideC);
}

Triangle::Triangle(double pSideF, double pSideS, double pAngle, TrAngles pTrAngle)
{
  double lSideT = GetSideByTwoSidesAngle(pSideF, pSideS, pAngle);
  if (pTrAngle == eANGLEA) {
    Init(pSideF, lSideT, pSideS);
  } else if (pTrAngle == eANGLEB) {
    Init(pSideF, pSideS, lSideT);
  } else if (pTrAngle == eANGLEC) {
    Init(lSideT, pSideF, pSideS);
  } else {
    // TODO: Error Handling.
  }
}

