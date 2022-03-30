#ifndef _NUMERIC_ANALYSIS_H_
#define _NUMERIC_ANALYSIS_H_

#include <math.h>

#ifdef __cplusplus
extern "C" {
#endif

double cubic( double a, double b, double c, double d, double x);
double cubicDist( double a, double b, double c, double x);
double gaussQuad5_4( double (*f)(double,double,double,double), double a, double b, double c, double x1, double x2 );
double newtonsMethod_Val( double (*g)(double,double,double,double),
						  double a, double b, double c, double x1, double x_in, double val, double tol);
double sinc( double x );
double dsinc_dx( double x );

#ifdef __cplusplus
}
#endif

#endif
