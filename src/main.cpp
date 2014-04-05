#include <iostream>
#include "triangle.h"

int main()
{
  Triangle tr(15,29,20);
  std::cout << tr.GetSideA() << std::endl;
  std::cout << tr.GetSideB() << std::endl;
  std::cout << tr.GetSideC() << std::endl;
  std::cout << tr.GetAltitudeA() << std::endl;
  std::cout << tr.GetAltitudeB() << std::endl;
  std::cout << tr.GetAltitudeC() << std::endl;
  std::cout << tr.GetBisectorA() << std::endl;
  std::cout << tr.GetBisectorB() << std::endl;
  std::cout << tr.GetBisectorC() << std::endl;
  std::cout << tr.GetMedianA() << std::endl;
  std::cout << tr.GetMedianB() << std::endl;
  std::cout << tr.GetMedianC() << std::endl;
  std::cout << tr.GetInscribedR() << std::endl;
  std::cout << tr.GetOutscribedR() << std::endl; 
  std::cout << tr.GetArea() << std::endl;
  std::cout << tr.GetPerimeter() << std::endl;
  std::cout << tr.GetAngleA() << std::endl;
  std::cout << tr.GetAngleB() << std::endl;
  std::cout << tr.GetAngleC() << std::endl;
  return 0;
}
