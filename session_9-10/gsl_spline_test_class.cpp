//  file: gsl_spline_test_class.cpp
// 
//  Test program for the gsl spline routines using the Spline class
//
//  Programmer:  Dick Furnstahl  furnstahl.1@osu.edu
//
//  Revision history:
//      02/10/09 -- created from gsl_cubic_spline_test.cpp
//
//  Notes:
//   * uses the GSL interpolation functions (see online documentation) 
//
//*****************************************************************
// include files
#include <iostream>    // cout and cin
#include <iomanip>     // manipulators like setprecision
#include <cmath>
#include <string>     // C++ strings                                 
using namespace std;    
#include "GslSpline.h"  // Header file for the GSL Spline class
#include <fstream>

inline double sqr (double z) {return z*z;}  // inline function for z^2

int
main (void)
{
  ofstream output ("spline.dat");
 // const int NMAX = 300;   // maximum number of array points 
  double x_values[5]={0.,50.,100.,150.,200.},\
  y_values[5]={10.6,45.0,52.8,10.8,4.7};

  // Test: interpolate y = sin(x^2) from xmin to xmax with npts points 
//  double xmin = 1.;
//  double xmax = 3.;
    int npts = 9;
//  double deltax = (xmax - xmin)/double(npts-1);
//  for (int i = 0; i < npts; i++)
//  {
//    double x_temp = xmin + double(i) * deltax;   // grid of x points
//    x_values[i] = x_temp;
//    y_values[i] = sin (x_temp * x_temp);
//  }

  // Make the spline object
  string type = "polynomial";
  Spline my_cubic_spline (x_values, y_values, npts, type);

  output << "    x     y_exact   y_spline   y'_exact  y'_spline";
  output << "  y''_exact  y''_spline  exact" << endl;

  for (int x = 0; x < 200; x+=5){

  // Evaluate the spline and derivatives
  double y = my_cubic_spline.y (x);
  double y_deriv = my_cubic_spline.yp (x);
  double y_deriv2 = my_cubic_spline.ypp (x);

  double x_sq = sqr(x);

  output << fixed << setprecision(6) 
       << x << "   " << sin(x_sq) << "   " <<  y << "   "
       <<  2.*x*cos(x_sq) << "   " << y_deriv << "   "
       <<  -4.*x_sq* sin(x_sq) + 2.*cos(x_sq) << "   " <<  y_deriv2
       <<"  "<<(63900./((x-78.)*(x-78.)+(55.*55.)/4.)) <<  endl;
  }
  output.close();
  return (0);      // successful completion 
}
