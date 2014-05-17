#ifndef TRPOINTS_H
#define TRPOINTS_H

#include <vector>
#include "area.h"
#include "qpainter.h"
#include "point.h"

class TrPoints
{
public:
  TrPoints(Triangle* tr, Area area);
  ~TrPoints();
public:
  Point GetPointA();
  Point GetPointB();
  Point GetPointC();
  void Draw(QPainter *pPainter);
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
  Triangle* m_triangle;
  std::vector<Point*> m_points;
  Area m_area;
};

#endif
