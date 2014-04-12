#ifndef CALCPOINTS_H
#define CALCPOINTS_H

#include <vector>
#include "area.h"

struct Point
{
  double X;
  double Y;
};

class CalcPoints
{
public:
  CalcPoints(Triangle tr, Area area);
public:
  Point GetPointA();
  Point GetPointB();
  Point GetPointC();
private:
  void SetPointA();
  void SetPointB();
  void SetPointC();
  void SetPoints();
  double GetScale();
  void FixPoints();
  void ReCalculate();
private:
  Point m_pointA;
  Point m_pointB;
  Point m_pointC;
  double m_width;
  double m_height;
  Triangle m_triangle;
  std::vector<Point*> m_points;
  Area m_area;
};

#endif