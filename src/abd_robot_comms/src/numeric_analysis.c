#include "numeric_analysis.h"

double cubic( double a, double b, double c, double d, double x)
{
	// Definition of a cubic function that returns y = ax^3 + bx^2 + cx + d
	double y = (c * x) + d;
			
	double z = x * x; // temporary variable to reduce the number of multiplications
	y += b * z;
	
	z = x * z;
	y += a * z;
		
	return y;
}

double cubicDist( double a, double b, double c, double x)
{
	// This function is the integrand for finding the distance along the curve of a cubic function y = ax^3 + bx^2 + cx + d, as a function of x
	// To find the distance along the curve between x1 and x2 this integrand will need to be integrated numerically
	
	double dy_dx = (3.0f * a * x * x) + (2.0f * b * x) + c; // The derivative of the cubic function
	double integrand = sqrt( (dy_dx * dy_dx) + 1.0f );
	
	return integrand;
}

double gaussQuad5_4( double (*f)(double,double,double,double), double a, double b, double c, double x1, double x2 )
{ 
	// Performs numerical integration on the multivariate function f() using five point Gaussian quadrature (exact for polynomials of degree 9 or below), between the limits of x1 and x2 (with x1 < x2)
	//   x2/
	// y = | f(a,b,c,x) dx
	//   x1/
	// The function f takes four arguments and integrates over x, between x1 and x2, for constant a, b, c.

	// change the limits from x1 to x2 to -1 to 1
	double r = 0.5*(x1 + x2);
	double s = 0.5*(x2 - x1);
	
	// numbers here are hard coded for five point gauss quad
	double y = s * ( ( 0.236926885 * (*f)(a, b, c, (-0.906179846*s ) + r) )
	               + ( 0.478628670 * (*f)(a, b, c, (-0.538469310*s ) + r) )
	               + ( 0.568888889 * (*f)(a, b, c, r) )
	               + ( 0.478628670 * (*f)(a, b, c, ( 0.538469310*s ) + r) )
	               + ( 0.236926885 * (*f)(a, b, c, ( 0.906179846*s ) + r) ) );
	
	return y;
}

double newtonsMethod_Val( double (*g)(double,double,double,double),
						  double a, double b, double c, double x1, double x_in, double val, double tol)
{
	// This function uses Newton's method to find x which satisfies f(x) = val, to a tolerance of +-tol, i.e. val-tol <= f(x_out) <= val+tol
	// x_in is the initial guess for x, and the function returns x_out
	// In this function the derivative of f(x) is given by g(x), and f(x) is found by numeric integration using 5-point Gaussian quadrature.
	//                                      x/
	//	 Update the difference diff = f(x) = | g(z) dz
	//	                                   x1/
	// The lower limit on the integration is given by x1
	// g(x) also takes additional parameters a,b,c as arguments which are constant.
		
	double x_out = x_in;
	
	double diff = gaussQuad5_4( (*g), a, b, c, x1, x_out ) - val;

	while (fabs(diff) > tol)
	{
	
		// This is the Newton step
		x_out = x_out - ( diff / (*g)( a, b, c, x_out ));
		
		/*                                          x/
		** Update the difference diff = f(x) - val = | g(z) dz - val
		**                                         x1/
		*/
		diff = gaussQuad5_4( (*g), a, b, c, x1, x_out ) - val;
	}
	
	return x_out;	
}

double sinc( double x )
{
	// Returns y = sinc(x)
	double x_sq = x * x;
	double y;

	if (x_sq < 1e-6)
	{
		y = 1.0f - (x_sq / 6.0f);
	}
	else
	{
		y = sin(x) / x;
	}

	return y;
}

double dsinc_dx( double x )
{
	// Returns y = d/dz sinc(z)|z=x
	double x_sq = x*x;
	double y;

	if (x_sq < 1e-6)
	{
		y = ( (x_sq * x) / 30.0f ) - (x / 3.0f);
	}
	else
	{
		y = (cos(x) / x) - (sin(x) / x_sq);
	}

	return y;
}