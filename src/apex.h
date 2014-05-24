#ifndef APEX_H
#define APEX_H

#include "qpainter.h"
#include <iostream>
#include "point.h"

class Apex
{
public:
  Apex(Point pPoint, std::string pLetter);
private:
  Point m_point;
  QColor* m_color;  
  int m_width;
  std::string m_letter;
  Point* m_apexLetterLocation;
  double m_letterDistance;
public:
  Point GetLocation();
  Point* GetApexLetterLocation();
  void Draw(QPainter *pPainter);
  double GetLetterDistance();
};

#endif
