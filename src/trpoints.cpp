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
  double lsideA = m_triangle->GetSideA()->GetLength() * GetScale();
  double lsideB = m_triangle->GetSideB()->GetLength() * GetScale();
  double lsideC = m_triangle->GetSideC()->GetLength() * GetScale();

  m_triangle->SetSideA(lsideA);
  m_triangle->SetSideB(lsideB);
  m_triangle->SetSideC(lsideC);
  m_triangle->SetProperties();

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
  m_pointB.Y = m_pointA.Y - m_triangle->GetSideA()->GetLength();
}

void
TrPoints::SetPointC(void)
{
  // Calculate point C
  double disC = 0;

  if (m_triangle->GetAngleA() >= 89) {
    disC = sqrt((m_triangle->GetSideC()->GetLength() * m_triangle->GetSideC()->GetLength()) - (m_triangle->GetAltitudeA() * m_triangle->GetAltitudeA()));
  }
  else if (m_triangle->GetAngleB() >= 90) {
    disC = 0 - (m_triangle->GetSideA()->GetLength() + sqrt((m_triangle->GetSideB()->GetLength() * m_triangle->GetSideB()->GetLength()) - (m_triangle->GetAltitudeA() * m_triangle->GetAltitudeA())));
  }
  else {
    disC = 0 - (sqrt((m_triangle->GetSideC()->GetLength() * m_triangle->GetSideC()->GetLength()) - (m_triangle->GetAltitudeA() * m_triangle->GetAltitudeA())));
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

void 
TrPoints::Draw(QPainter *pPainter)
{
  pPainter->drawRect(0 + m_area.X, 0 + m_area.Y, m_area.width, m_area.height);
  m_triangle->GetSideA()->Draw(pPainter);
  m_triangle->GetSideB()->Draw(pPainter);
  m_triangle->GetSideC()->Draw(pPainter);
}

TrPoints::TrPoints(Triangle* tr, Area area)
{
  m_triangle = tr;
  m_area = area;
  SetPoints();
  FixPoints();
  ReCalculate();
  Apex* apexA = new Apex(this->GetPointA(), "A");
  Apex* apexB = new Apex(this->GetPointB(), "B");
  Apex* apexC = new Apex(this->GetPointC(), "C");

  m_triangle->GetSideA()->SetMiddleLetter("a");
  m_triangle->GetSideB()->SetMiddleLetter("b");
  m_triangle->GetSideC()->SetMiddleLetter("c");

  m_triangle->GetSideA()->SetStartApex(apexA);
  m_triangle->GetSideA()->SetEndApex(apexB);
  m_triangle->GetSideB()->SetStartApex(apexB);
  m_triangle->GetSideB()->SetEndApex(apexC);
  m_triangle->GetSideC()->SetStartApex(apexC);
  m_triangle->GetSideC()->SetEndApex(apexA);
  
  m_triangle->GetSideA()->FindApexLetterLocation();
  m_triangle->GetSideB()->FindApexLetterLocation();
  m_triangle->GetSideC()->FindApexLetterLocation();

  m_triangle->GetSideA()->FindMiddleLetterLocation();
  m_triangle->GetSideB()->FindMiddleLetterLocation();
  m_triangle->GetSideC()->FindMiddleLetterLocation();
}

TrPoints::~TrPoints()
{
  delete m_triangle;
}
