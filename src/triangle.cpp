#include "triangle.h"
#include "math.h"

void
Triangle::SetArea(void)
{
  // The Heron formula s=sqrt(p(p-a)(p-b)(p-c))
  m_area = sqrt((GetPerimeter()/2) *
                ((GetPerimeter()/2) - m_sideA) *
                ((GetPerimeter()/2) - m_sideB) *
                ((GetPerimeter()/2) - m_sideC));
}

double
Triangle::SetAngle(double pSideX, double pSideY, double pSideZ)
{
  // asin(2S/ab)
  double lAngle = (180 * asin((2 * m_area) / (pSideX * pSideY)))/PI;
  if ((pSideZ * pSideZ) > ((pSideX * pSideX) + (pSideY * pSideY)))
    return lAngle + ((90-lAngle)*2);
  else 
    return lAngle;
}

double
Triangle::SetAltitude(double pSide)
{
  // 2*S/a;
  return (2 * GetArea())/pSide;
}

double
Triangle::SetBisector(double pSideX, double pSideY, double pAngle)
{
  // 2*b*c*cos(C/2)/(b+c)
  return  2 * pSideX  * pSideY * 
          cos(((PI * (pAngle / 2)) / 180)) / 
          (pSideX + pSideY);
}

double
Triangle::SetMedian(double pSide, double pSideX, double pSideY)
{
  // sqrt(2b^2+2c^2-a^2)/2;
  return (sqrt(2 * pSideX * pSideX + 
              2 * pSideY * pSideY - 
              pSide * pSide)) / 2;
}

double
Triangle::GetArea(void)
{
  return m_area;
}

void
Triangle::SetAngleA(void)
{
 m_angleA = SetAngle(m_sideA, m_sideC, m_sideB); 
}

double
Triangle::GetAngleA(void)
{
  return m_angleA;
}

void
Triangle::SetAngleB(void)
{
 m_angleB = SetAngle(m_sideA, m_sideB, m_sideC); 
}

double
Triangle::GetAngleB(void)
{
  return m_angleB;
}

void
Triangle::SetAngleC(void)
{
 m_angleC = SetAngle(m_sideB, m_sideC, m_sideA); 
}

double
Triangle::GetAngleC(void)
{
  return m_angleC;
}

void
Triangle::SetPerimeter(void)
{
  m_perimeter = m_sideA + m_sideB + m_sideC;
}

double
Triangle::GetPerimeter(void)
{
  return m_perimeter;
}


void
Triangle::SetAltitudeA(void)
{
  m_altitudeA = SetAltitude(m_sideA); 
}

double
Triangle::GetAltitudeA(void)
{
  return m_altitudeA;
}

void
Triangle::SetAltitudeB(void)
{
  m_altitudeA = SetAltitude(m_sideB); 
}

double
Triangle::GetAltitudeB(void)
{
  return m_altitudeB;
}

void
Triangle::SetAltitudeC(void)
{
  m_altitudeA = SetAltitude(m_sideC);
}

double
Triangle::GetAltitudeC(void)
{
  return m_altitudeC;
}

void
Triangle::SetBisectorA(void)
{
  m_bisectorA = SetBisector(m_sideB, m_sideC, m_angleC);
}

double
Triangle::GetBisectorA(void)
{
  return m_bisectorA;
}

void
Triangle::SetBisectorB(void)
{
  m_bisectorA = SetBisector(m_sideA, m_sideC, m_angleA);
}

double
Triangle::GetBisectorB(void)
{
  return m_bisectorB;
}

void
Triangle::SetBisectorC(void)
{
  m_bisectorA = SetBisector(m_sideA, m_sideB, m_angleB);
}

double
Triangle::GetBisectorC(void)
{
  return m_bisectorC;
}

void
Triangle::SetMedianA(void)
{
  m_medianA = SetMedian(m_sideA, m_sideB, m_sideC);
}

double
Triangle::GetMedianA(void)
{
  return m_medianA;
}

void
Triangle::SetMedianB(void)
{
  m_medianA = SetMedian(m_sideB, m_sideA, m_sideC);
}

double
Triangle::GetMedianB(void)
{
  return m_medianB;
}

void
Triangle::SetMedianC(void)
{
  m_medianA = SetMedian(m_sideC, m_sideB, m_sideA);
}

double
Triangle::GetMedianC(void)
{
  return m_medianC;
}

void
Triangle::SetInscribedR(void)
{
  m_inscribedR = GetArea() / (GetPerimeter()/2);
}

void
Triangle::SetOutscribedR(void)
{
  // (abc)/sqrt(a+b+c)(b+c-a)(c+a-b)(a+b-c)
  m_outscribedR = (m_sideA * m_sideB * m_sideC) / 
          sqrt(
          (m_sideA + m_sideB + m_sideC) * 
          (m_sideB + m_sideC - m_sideA) * 
          (m_sideC + m_sideA - m_sideB) * 
          (m_sideA + m_sideB - m_sideC));
}

double
Triangle::GetInscribedR(void)
{
  return m_inscribedR;
}

double
Triangle::GetOutscribedR(void)
{
  return m_outscribedR;
}

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
  SetPerimeter();
  SetArea();
  SetAngleA();
  SetAngleB();
  SetAngleC();
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
