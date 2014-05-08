#include "triangle.h"
#include "trpoints.h"
#include <iostream>
#include <vector>
#include <cmath>

double
TrPoints::GetScale()
{
  double lScale = 0;
  double lS1 = (m_area.width - (m_area.rightMargin + m_area.leftMargin)) / m_width;
  double lS2 = (m_area.height - (m_area.bottomMargin + m_area.topMargin)) / m_height;
  if (lS1 < lS2) lScale = lS1;
  else lScale = lS2;

  return lScale;
}

void
TrPoints::ReCalculate()
{
  double lsideA = m_triangle->GetSideA() * GetScale();
  double lsideB = m_triangle->GetSideB() * GetScale();
  double lsideC = m_triangle->GetSideC() * GetScale();

  m_triangle = new Triangle(lsideA, lsideB, lsideC);

  SetPoints();
  FixPoints(); 
}

Point
TrPoints::GetPointA(void)
{
  return m_pointA; 
}

Point
TrPoints::GetPointB(void)
{
  return m_pointB; 
}

Point
TrPoints::GetPointC(void)
{
  return m_pointC; 
}

void
TrPoints::SetPointA(void)
{
  // Calculate point A
  m_pointA.X = 0;
  m_pointA.Y = 0;
}

void
TrPoints::SetPointB(void)
{
  // Calculate point B
  m_pointB.X = 0;
  m_pointB.Y = m_pointA.Y - m_triangle->GetSideA();
}

void
TrPoints::SetPointC(void)
{
  // Calculate point C
  double disC = 0;

  if (m_triangle->GetAngleA() >= 89) {
    disC = sqrt((m_triangle->GetSideC() * m_triangle->GetSideC()) - (m_triangle->GetAltitudeA() * m_triangle->GetAltitudeA()));
  }
  else if (m_triangle->GetAngleB() >= 90) {
    disC = 0 - (m_triangle->GetSideA() + sqrt((m_triangle->GetSideB() * m_triangle->GetSideB()) - (m_triangle->GetAltitudeA() * m_triangle->GetAltitudeA())));
  }
  else {
    disC = 0 - (sqrt((m_triangle->GetSideC() * m_triangle->GetSideC()) - (m_triangle->GetAltitudeA() * m_triangle->GetAltitudeA())));
  }

  m_pointC.X = m_pointA.X + m_triangle->GetAltitudeA();
  m_pointC.Y = m_pointA.Y + disC;
}

void
TrPoints::SetPoints(void)
{
  SetPointA();
  SetPointB();
  SetPointC();

  m_points.clear();
  m_points.push_back(&m_pointA);
  m_points.push_back(&m_pointB);
  m_points.push_back(&m_pointC);

}

void
TrPoints::FixPoints()
{
  double minX = m_pointA.X;
  double minY = m_pointA.Y;
  double maxX = m_pointA.X;
  double maxY = m_pointA.Y;
  for (unsigned int i = 0; i < m_points.size(); ++i) {
    if ((m_points[i])->X < minX) minX = (m_points[i])->X;
    if ((m_points[i])->Y < minY) minY = (m_points[i])->Y;

    if ((m_points[i])->X > maxX) maxX = (m_points[i])->X;
    if ((m_points[i])->Y > maxY) maxY = (m_points[i])->Y;
  }
  m_width = maxX - minX;
  m_height = maxY - minY;

  for (unsigned int i = 0; i < m_points.size(); i++) {
    (m_points[i])->X += (std::abs(minX) + m_area.leftMargin + m_area.X);
    (m_points[i])->Y += (std::abs(minY) + m_area.topMargin + m_area.Y);
  }
}

TrPoints::TrPoints(Triangle* tr, Area area)
{
  m_triangle = tr;
  m_area = area;
  SetPoints();
  FixPoints();

  ReCalculate();
}

TrPoints::~TrPoints()
{
  delete m_triangle;
}
