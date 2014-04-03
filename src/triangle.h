#ifndef TRIANGLE_H
#define TRIANGLE_H

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
private:
  double GetSideByTwoSidesAngle(double pSideA, double pSideB, double pAngle);
};

#endif
