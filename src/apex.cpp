#include "apex.h"

Apex::Apex(Point pPoint, std::string pLetter)
{
  m_point = pPoint;
  m_letter = pLetter;
  m_letterDistance = 8;
  m_color = new QColor(Qt::black);
  m_apexLetterLocation = new Point();
}

Point
Apex::GetLocation()
{
  return m_point;
}

Point*
Apex::GetApexLetterLocation()
{
  return m_apexLetterLocation;
}

double
Apex::GetLetterDistance()
{
  return m_letterDistance;
}

void
Apex::Draw(QPainter *pPainter)
{
  pPainter->setPen(*m_color);
  QString lLetter = QString::fromStdString(m_letter);
  QFontMetrics fm = pPainter->fontMetrics();
  int lWidth = fm.width(lLetter);
  int lHeight = fm.height();

  pPainter->drawText(m_apexLetterLocation->X - (lWidth/2), m_apexLetterLocation->Y + (lHeight/2), QString::fromStdString(m_letter));
}
