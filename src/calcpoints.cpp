#include "triangle.h"
#include "calcpoints.h"
#include <iostream>
#include <vector>
#include <cmath>

double
CalcPoints::GetScale()
{
  double lScale = 0;
  double lS1 = (m_area.width - (m_area.rightMargin + m_area.leftMargin)) / m_width;
  double lS2 = (m_area.height - (m_area.bottomMargin + m_area.topMargin)) / m_height;
  if (lS1 < lS2) lScale = lS1;
  else lScale = lS2;

  return lScale;
}

void
CalcPoints::ReCalculate()
{
  Triangle t( m_triangle.GetSideA()*GetScale(),
              m_triangle.GetSideB()*GetScale(),
              m_triangle.GetSideC()*GetScale());
  m_triangle = t;
  SetPoints();
  FixPoints(); 
}

Point
CalcPoints::GetPointA(void)
{
  return m_pointA; 
}

Point
CalcPoints::GetPointB(void)
{
  return m_pointB; 
}

Point
CalcPoints::GetPointC(void)
{
  return m_pointC; 
}

void
CalcPoints::SetPointA(void)
{
  // Calculate point A
  m_pointA.X = 0;
  m_pointA.Y = 0;
}

void
CalcPoints::SetPointB(void)
{
  // Calculate point B
  m_pointB.X = 0;
  m_pointB.Y = m_pointA.Y - m_triangle.GetSideA();
}

void
CalcPoints::SetPointC(void)
{
  // Calculate point C
  double disC = 0;

  if (m_triangle.GetAngleA() >= 90)
    disC = sqrt((m_triangle.GetSideC() * m_triangle.GetSideC()) - (m_triangle.GetAltitudeA() * m_triangle.GetAltitudeA()));
  else if (m_triangle.GetAngleB() >= 90)
    disC = 0 - (m_triangle.GetSideA() + sqrt((m_triangle.GetSideB() * m_triangle.GetSideB()) - (m_triangle.GetAltitudeA() * m_triangle.GetAltitudeA())));
  else
    disC = 0 - (sqrt((m_triangle.GetSideC() * m_triangle.GetSideC()) - (m_triangle.GetAltitudeA() * m_triangle.GetAltitudeA())));

  m_pointC.X = m_pointA.X + m_triangle.GetAltitudeA();
  m_pointC.Y = m_pointA.Y + disC;
}

void
CalcPoints::SetPoints(void)
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
CalcPoints::FixPoints()
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

CalcPoints::CalcPoints(Triangle tr, Area area)
{
  m_triangle = tr;
  m_area = area;
  SetPoints();
  FixPoints();
  ReCalculate();
}
