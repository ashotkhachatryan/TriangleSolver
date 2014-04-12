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
  Synopsis - Triangle class library.
**********************************************************************/

#ifndef TRIANGLE_H
#define TRIANGLE_H

#define PI 3.1415926535897

class Triangle
{
public:
  enum TrAngles { eANGLEA, eANGLEB, eANGLEC };
public:
  Triangle();
  Triangle(double pSideA, double pSideB, double pSideC);
  Triangle(double pSideF, double pSideS, double pAngle, TrAngles pTrAngle);
private:
  double m_sideA;
  double m_sideB;
  double m_sideC;
  double m_angleA;
  double m_angleB;
  double m_angleC;
  double m_perimeter;
  double m_area;
  double m_altitudeA;
  double m_altitudeB;
  double m_altitudeC;
  double m_bisectorA;
  double m_bisectorB;
  double m_bisectorC;
  double m_medianA;
  double m_medianB;
  double m_medianC;
  double m_inscribedR;
  double m_outscribedR;
private:
  void SetProperties(void);
  void SetArea();
  void SetPerimeter();
  double SetAltitude(double pSide);
  void SetAltitudeA();
  void SetAltitudeB();
  void SetAltitudeC();
  double SetBisector(double pSideX, double pSideY, double pAngle);
  void SetBisectorA();
  void SetBisectorB();
  void SetBisectorC();
  double SetMedian(double pSide, double pSideX, double pSideY);
  void SetMedianA();
  void SetMedianB();
  void SetMedianC(void);
  double SetAngle(double pSideX, double pSideY, double pSideZ);
  void SetAngleA();
  void SetAngleB();
  void SetAngleC();
  void SetInscribedR();
  void SetOutscribedR();
  double GetSideByTwoSidesAngle(double pSideA, double pSideB, double pAngle);
  void Init(double pSideA, double pSideB, double pSideC);
public:
  double GetSideA();
  double GetSideB();
  double GetSideC();

  double GetArea();
  double GetPerimeter();

  double GetAltitudeA();
  double GetAltitudeB();
  double GetAltitudeC();

  double GetBisectorA();
  double GetBisectorB();
  double GetBisectorC();

  double GetMedianA();
  double GetMedianB();
  double GetMedianC();

  double GetAngleA();
  double GetAngleB();
  double GetAngleC();

  double GetInscribedR();
  double GetOutscribedR();
};

#endif
