#include "triangle.h"

double
Triangle::GetSideByTwoSidesAngle(double pSideA, double pSideB, double pAngle)
{
  (void)pSideA;
  (void)pSideB;
  (void)pAngle;
  return 0;
}

Triangle::Triangle()
{
}

Triangle::Triangle(double pSideA, double pSideB, double pSideC)
{
  // TODO: Check side correctness.
  m_sideA = pSideA;
  m_sideB = pSideB;
  m_sideC = pSideC;
}

Triangle::Triangle(double pSideF, double pSideS, double pAngle, TrAngles pTrAngle)
{
  double lSideT = GetSideByTwoSidesAngle(pSideF, pSideS, pAngle);
  if (pTrAngle == eANGLEA) {
    Triangle(pSideF, lSideT, pSideS);
  } else if (pTrAngle == eANGLEB) {
    Triangle(pSideF, pSideS, lSideT);
  } else if (pTrAngle == eANGLEC) {
    Triangle(lSideT, pSideF, pSideS);
  } else {
    // TODO: Error Handling.
  }
}
