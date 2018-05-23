#include <math.h>
#include "gsw_internal_const.h"

double
gsw_o2sol_sp_pt(double sp, double pt)
{
  GSW_TEOS10_CONSTANTS;
  double x, pt68, y, o2sol;
  double a0, a1, a2, a3, a4, a5, b0, b1, b2, b3, c0;

  x = sp;

  pt68 = pt*1.00024;

  y = log((298.15 - pt68)/(gsw_t0 + pt68));

  // The coefficents below are from the second column of Table 1 of Garcia and
  //  Gordon (1992)
  a0 =  5.80871; 
  a1 =  3.20291;
  a2 =  4.17887;
  a3 =  5.10006;
  a4 = -9.86643e-2;
  a5 =  3.80369;
  b0 = -7.01577e-3;
  b1 = -7.70028e-3;
  b2 = -1.13864e-2;
  b3 = -9.51519e-3;
  c0 = -2.75915e-7;

  o2sol = exp(a0 + y*(a1 + y*(a2 + y*(a3 + y*(a4 + a5*y))))
                + x*(b0 + y*(b1 + y*(b2 + b3*y)) + c0*x));

  return o2sol;
}
