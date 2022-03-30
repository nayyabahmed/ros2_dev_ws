/**
 * @file pf_segment_functions.c
 * @author Louis Kempton
 * @date  1 Jan 1970
 *
 * @brief Source file for calculating x,y,t data from path file segments
 *
 * Contains functions for for calculating x,y,t data from path file segments
 *
 * @remarks Modifications:
 * Start        LCK  Pulled from robots project
 * 25-Oct-2019  LCK  Add documentation. Fix cppcheck and MISRA C violations for logSpiral and optimise.
 */

#include "pf_segment_functions.h"

 /**
  * @brief Calculate the time spent on a segment given a distance along that segment
  *
  * Calculate the time spent on a segment (travelling at path file speed) given a distance along that segment
  *
  * @author Louis Kempton
  * @param[in] d - The distance along the segment in metres. d must be in [0,D], where D is the length of the segment.
  * @param[in] seg - The segment data structure version 0. Used by robots with pmStructVerNum 0 and 1.
  * @return Returns the time in seconds that the robot should have spent on the segment, travelling at the path file speed.
  * @date 25 Oct 2019
  *
  */
double timeOnSegment(double d, _SEGMENTDATA_0 seg)
{
	double t;

	float u1 = seg.InitialVel;
	float u2 = seg.FinalVel;
	double D = seg.Length; // Length of this segment

	// Generate unit test data
	//recordFunctionInput("%lf, %f, %f, %lf,", d, seg.InitialVel, seg.FinalVel, seg.Length);

	if ((d < 0.0) || (d > D))
	{
		t = NAN; // invalid d
	}
	else if (d < 1e-6)
	{
		t = 0.0; // d ~ 0, so takes 0 time to get there
	}
	else if (fabs(u2 - u1) < 1e-6)
	{ // velocity approximately constant (no acceleration). Linear case
		if (fabs(u1) < 1e-6)
		{
			t = NAN; // note if u1~0, then u2~0, stays at d=0 forever...
		}
		else
		{
			t = d / u1; // note if u1~0, then u2~0
		}
	}
	else
	{	// Calculate the total time require to traverse the segment
		double T = (2.0 * D) / (u1 + u2);

		if (fabs(u1) < 1e-6)
		{
			t = sqrt((2.0 * T * d) / u2); // u1~0 and u2 != 0
		}
		else
		{
			// Else quadratic formula
			// u2 != u1, u1 != 0
			double a = (u2 - u1) / (2.0 * T);
			t = (-u1 + sqrt((u1 * u1) + (4.0 * a * d))) / (2.0 * a);
		}
	}

	// Generate unit test data
	//recordFunctionOutput( "%lf,", t);

	return t;
}

/**
 * @brief Calculate the time spent on a segment given a distance along that segment
 *
 * Calculate the time spent on a segment (travelling at path file speed) given a distance along that segment
 *
 * @author Louis Kempton
 * @param[in] d - The distance along the segment in metres. d must be in [0,D], where D is the length of the segment.
 * @param[in] seg - The segment data structure version 0. Used by robots with pmStructVerNum 0 and 1.
 * @return Returns the time in seconds that the robot should have spent on the segment, travelling at the path file speed.
 * @date 25 Oct 2019
 *
 */
double timeOnSegment_2(double d, _SEGMENTDATA_2 seg)
{
	double t;

	float u1 = seg.InitialVel;
	float u2 = seg.FinalVel;
	float D = seg.Length; // Length of this segment

	if ((d < 0.0) || (d > D))
	{
		t = NAN; // invalid d
	}
	else if (d < 1e-6)
	{
		t = 0.0; // d ~ 0, so takes 0 time to get there
	}
	else if (fabs(u2 - u1) < 1e-6)
	{ // velocity approximately constant (no acceleration). Linear case
		if (fabs(u1) < 1e-6)
		{
			t = NAN; // note if u1~0, then u2~0, stays at d=0 forever...
		}
		else
		{
			t = d / u1; // note if u1~0, then u2~0
		}
	}
	else
	{ // Calculate the total time require to traverse the segment		
		double T = (2.0 * D) / (u1 + u2);

		if (fabs(u1) < 1e-6)
		{
			t = sqrt((2.0 * T * d) / u2); // u1~0 and u2 != 0
		}
		else
		{
			// Else quadratic formula
			// u2 != u1, u1 != 0
			double a = (u2 - u1) / (2.0 * T);
			t = (-u1 + sqrt((u1 * u1) + (4.0 * a * d))) / (2.0 * a);
		}
	}

	return t;
}

/**
 * @brief Calculate the coordinate of the point at distance d metres along a line segment
 *
 * Calculate the x, y, yaw, time, and total distance coordinates of the point at distance d metres along a line segment
 *
 * @author Unknown
 * @param[in] d - The distance along the segment in metres.
 * @param[in] seg - The segment data structure version 0. Used by robots with pmStructVerNum 0 and 1. Should be used with line type segments (seg.Type = SEG_STRAIGHT)
 * @return Returns the _COORDS data structure that contains x, y, yaw, t, and distance
 * @date
 *
 */
_COORDS line(double d, _SEGMENTDATA_0 seg, float extraTime)
{
	// Generate unit test data
	//recordFunctionInput("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %f, %f, %lf", d, seg.InitialX, seg.InitialY, seg.InitialHeadingCos, seg.InitialHeadingSin, seg.InitialTime, seg.InitialDist, seg.InitialVel, seg.FinalVel, seg.Length );

	// Returns the x and y position of the point d metres along a line segment
	_COORDS car;

	car.xPos = seg.InitialX + (d * seg.InitialHeadingCos);
	car.yPos = seg.InitialY + (d * seg.InitialHeadingSin);
	car.yaw = atan2(seg.InitialHeadingSin, seg.InitialHeadingCos);

	// calculate the time
	car.timeOnPath = seg.InitialTime + timeOnSegment(d, seg) + extraTime;

	// record the distance
	car.distanceOnPath = seg.InitialDist + d;

	//recordFunctionOutput( "%lf, %lf, %lf, %f, %f,", car.xPos, car.yPos, car.yaw, car.timeOnPath, car.distanceOnPath);
	return car;
}

/**
 * @brief Calculate the coordinate of the point at distance d metres along an arc segment
 *
 * Calculate the x, y, yaw, time, and total distance coordinates of the point at distance d metres along an arc segment
 *
 * @author Unknown
 * @param[in] d - The distance along the segment in metres.
 * @param[in] seg - The segment data structure, version 0. Used by robots with pmStructVerNum 0 and 1. Should be used with arc type segments (seg.Type = SEG_ARC)
 * @return Returns the _COORDS data structure that contains x, y, yaw, t, and distance
 * @date
 *
 */
_COORDS arc(double d, _SEGMENTDATA_0 seg, float extraTime)
{
	// Generate unit test data
	//recordFunctionInput("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %f, %f, %lf", d, seg.InitialX, seg.InitialY, seg.InitialHeadingCos, seg.InitialHeadingSin, seg.Radius, seg.InitialTime, seg.InitialDist, seg.InitialVel, seg.FinalVel, seg.Length );

	// Returns the x and y position of the point d metres along an arc segment (negative radius is a right turn)
	_COORDS car;

	double theta = d / seg.Radius; // angle of travel in radians
	double tempX = seg.Radius * sin(theta);
	double tempY = seg.Radius * (1.0 - cos(theta));

	car.xPos = seg.InitialX + (tempX * seg.InitialHeadingCos) - (tempY * seg.InitialHeadingSin);
	car.yPos = seg.InitialY + (tempX * seg.InitialHeadingSin) + (tempY * seg.InitialHeadingCos);
	car.yaw = atan2(seg.InitialHeadingSin, seg.InitialHeadingCos) + theta;

	// calculate the time
	car.timeOnPath = seg.InitialTime + timeOnSegment(d, seg) + extraTime;

	// record the distance
	car.distanceOnPath = seg.InitialDist + d;

	//recordFunctionOutput("%lf, %lf, %lf, %f, %f,", car.xPos, car.yPos, car.yaw, car.timeOnPath, car.distanceOnPath);
	return car;
}

/**
 * @brief Calculate the coordinate of the point at distance d metres along a log spiral segment
 *
 * Calculate the x, y, yaw, time, and total distance coordinates of the point at distance d metres along a logarithmic spiral segment
 *
 * @author Unknown
 * @param[in] d - The distance along the segment in metres.
 * @param[in] seg - The segment data structure, version 0. Used by robots with pmStructVerNum 0 and 1. Should be used with log spiral type segments (seg.Type = SEG_SPIRAL)
 * @return Returns the _COORDS data structure that contains x, y, yaw, t, and distance
 * @date 5 Nov 2019
 *
 * @remarks Modifications:
 * Start        LCK  Pulled from robots project
 *  5-Nov-2019  LCK  Fix cppcheck and MISRA C violations. Optimisation for performance ~1250IR/call to ~425IR/call
 */
_COORDS logSpiral(double d, _SEGMENTDATA_0 seg, float extraTime)
{
	//recordFunctionInput("%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %f, %f, %lf,", d, seg.InitialX, seg.InitialY, seg.InitialHeadingCos, seg.InitialHeadingSin, seg.Radius, seg.EndRadius, seg.InitialTime, seg.InitialDist, seg.InitialVel, seg.FinalVel, seg.Length );
	_COORDS car;

	float radius1, radius2;
	double sinArc, cosArc;
	int k;
	if (seg.Radius < 0)
	{ //right turn
		k = -1;
		radius1 = -(float)seg.Radius;	//initial radius
		radius2 = -(float)seg.EndRadius;	//final radius
	}
	else
	{
		k = 1;
		radius1 = (float)seg.Radius;	//initial radius
		radius2 = (float)seg.EndRadius;	//final radius
	}

	double radius_diff = (double)(radius2 - radius1);
	float length = (float)seg.Length;
	//float hyp = sqrt((radius_diff * radius_diff) + (length * length)); // it appears that PPMAC IDE cannot compile sqrt of floats
	float hyp = (float)sqrt((double)((radius_diff * radius_diff) + (length * length)));

	float cos_C = (radius_diff / hyp);
	float sin_C = (length / hyp);

	float B = radius_diff / length;
	float A = radius1 * sin_C;

	float F = (B * (float)d) / radius1;
	float E = log1p(F);
	float exp_E = 1.0f + F;

	double D = (double)(E / B);
	sincos(D, &sinArc, &cosArc); // It appears that PPMAC IDE cannot compile sincos of floats

	float X1 = A * ((cosArc * exp_E) - 1.0);  //temp var
	float Y1 = A * sinArc * exp_E;  //temp var

	float X2 = (X1 * cos_C) + (Y1 * sin_C);
	float Y2 = -k * ((X1 * sin_C) - (Y1 * cos_C));

	car.xPos = seg.InitialX + (X2 * (float)seg.InitialHeadingCos) - (Y2 * (float)seg.InitialHeadingSin);
	car.yPos = seg.InitialY + (X2 * (float)seg.InitialHeadingSin) + (Y2 * (float)seg.InitialHeadingCos);
	car.yaw = atan2(seg.InitialHeadingSin, seg.InitialHeadingCos) + D;

	// calculate the time
	car.timeOnPath = seg.InitialTime + timeOnSegment(d, seg) + extraTime;

	// record the distance
	car.distanceOnPath = seg.InitialDist + d;

	//recordFunctionOutput("%lf, %lf, %lf, %f, %f,", car.xPos, car.yPos, car.yaw, car.timeOnPath, car.distanceOnPath);
	return car;
}

_COORDS stopPoint(_SEGMENTDATA_0 seg, float *extraTime)
{
	// Returns the x and y position of the stop point and increments extra time accordingly
	_COORDS car;

	car.xPos = seg.InitialX;
	car.yPos = seg.InitialY;
	car.yaw = atan2(seg.InitialHeadingSin, seg.InitialHeadingCos);

	// calculate the time
	car.timeOnPath = seg.InitialTime + *extraTime;

	// increment extra time according
	if (seg.StartTriggerChan != -1)
	{
		*extraTime += 1000.0f;
	}

	// record the distance
	car.distanceOnPath = seg.InitialDist;

	return car;
}

/**
 * @brief Calculate the coordinate of the point at distance d metres along a b spline point segment
 *
 * Calculate the x, y, yaw, time, and total distance coordinates of the point at distance d metres along a b spline point segment
 *
 * @author Unknown
 * @param[in] d - The distance along the segment in metres.
 * @param[in] seg - The segment data structure, version 0. Used by robots with pmStructVerNum 0 and 1. Should be used with log spiral type segments (seg.Type = SEG_SPIRAL)
 * @param[in] *spline - Pointer to the array of spline point data for this segment
 * @return Returns the _COORDS data structure that contains x, y, yaw, t, and distance
 * @date
 *
 */
_COORDS bSpline(double d, _SEGMENTDATA_0 seg, _SPLINEDATA_0* spline, float extraTime)
{
	// Record function input
	//char *function_input = (char*)malloc(32000);
	//char* p = function_input;
	//
	//p += sprintf(p, "%lf, %lf, %d,", d, seg.InvPointDist, seg.nPoints);
	//int i;
	//for (i = 0; i < seg.nPoints + 3; ++i)
	//{
	//	p += sprintf(p, " %lf, %lf, %lf,", spline[i].X, spline[i].Y, spline[i].Time);
	//}
	//recordFunctionInput("%s", function_input);	
	//free(function_input);
	//(void)p;

	_COORDS car;
	double arrayFloat = d * seg.InvPointDist;  //array idx on spline (including fractional part) 0 => start point
	int nodeidx = (int)arrayFloat + 1; // idx of the preceding spline point

	// calculate the proportion of the distance between consecutive nodes (cubic b spline)
	double A = arrayFloat - (double)(short)arrayFloat;
	double B = A * A; // A^2
	double C = A * B; // A^3

	// calculate the coefficients (this might not have to be done every time if we stay on the same segment)
	double xCoeffA = -spline[nodeidx - 1].X + (3.0 * spline[nodeidx].X) - (3.0 * spline[nodeidx + 1].X) + spline[nodeidx + 2].X;
	double xCoeffB = (3.0 * spline[nodeidx - 1].X) - (6.0 * spline[nodeidx].X) + (3.0 * spline[nodeidx + 1].X);
	double xCoeffC = -(3.0 * spline[nodeidx - 1].X) + (3.0 * spline[nodeidx + 1].X);
	double xCoeffD = spline[nodeidx - 1].X + (4.0 * spline[nodeidx].X) + spline[nodeidx + 1].X;

	double yCoeffA = -spline[nodeidx - 1].Y + (3.0 * spline[nodeidx].Y) - (3.0 * spline[nodeidx + 1].Y) + spline[nodeidx + 2].Y;
	double yCoeffB = (3.0 * spline[nodeidx - 1].Y) - (6.0 * spline[nodeidx].Y) + (3.0 * spline[nodeidx + 1].Y);
	double yCoeffC = -(3.0 * spline[nodeidx - 1].Y) + (3.0 * spline[nodeidx + 1].Y);
	double yCoeffD = spline[nodeidx - 1].Y + (4.0 * spline[nodeidx].Y) + spline[nodeidx + 1].Y;

	double tCoeffA = -spline[nodeidx - 1].Time + (3.0 * spline[nodeidx].Time) - (3.0 * spline[nodeidx + 1].Time) + spline[nodeidx + 2].Time;
	double tCoeffB = (3.0 * spline[nodeidx - 1].Time) - (6.0 * spline[nodeidx].Time) + (3.0 * spline[nodeidx + 1].Time);
	double tCoeffC = -(3.0 * spline[nodeidx - 1].Time) + (3.0 * spline[nodeidx + 1].Time);
	double tCoeffD = spline[nodeidx - 1].Time + (4.0 * spline[nodeidx].Time) + spline[nodeidx + 1].Time;

	car.xPos = 0.1666666 * ((xCoeffA * C) + (xCoeffB * B) + (xCoeffC * A) + xCoeffD);
	car.yPos = 0.1666666 * ((yCoeffA * C) + (yCoeffB * B) + (yCoeffC * A) + yCoeffD);

	double X1 = 0.1666666 * ((3.0 * xCoeffA * B) + (2.0 * xCoeffB * A) + xCoeffC);
	double Y1 = 0.1666666 * ((3.0 * yCoeffA * B) + (2.0 * yCoeffB * A) + yCoeffC);

	car.yaw = atan2(Y1, X1);

	// calculate the time
	car.timeOnPath = 0.1666666 * ((tCoeffA * C) + (tCoeffB * B) + (tCoeffC * A) + tCoeffD) + extraTime;

	// record the distance
	car.distanceOnPath = seg.InitialDist + d;

	//recordFunctionOutput("%lf, %lf, %lf, %f, %f,", car.xPos, car.yPos, car.yaw, car.timeOnPath, car.distanceOnPath);
	return car;
}

/**
 * @brief Calculate the coordinate of the point at distance d metres along a cubic transition
 *
 * Calculate the x, y, yaw, time, and total distance coordinates of the point at distance d metres along a cubic transition
 *
 * @author Louis Kempton
 * @param[in] d - The distance along the segment in metres.
 * @param[in] trans - The transition data structure, version 0. Used by robots with pmStructVerNum 0 and 1.
 * @param[in] x1 - The first valid x position on the transition.
 * @return Returns the _COORDS data structure that contains x, y, yaw, t, and distance
 * @date 1 Jan 2018
 *
 */
_COORDS cubTransition(double d, _TRANSITIONDATA_0 trans, double x1)
{
	//recordFunctionInput("%lf, %lf, %0.9lf, %0.9lf, %lf, %lf, %lf, %lf, %lf, %lf, %f,", d, x1, trans.CoeffA, trans.CoeffB, trans.LocalOriginX, trans.LocalOriginY, trans.LocalSin, trans.LocalCos, trans.InitialVel, trans.Accel, trans.FirstValidX );

	// Returns the x and y position of a point on the transition curve trans that is distance d along the curve from (x1,y1)
	_COORDS car;

	double a = trans.CoeffA;
	double b = trans.CoeffB;
	// c and d are always 0 for cubic transitions

	double tol = 1e-4; // tolerance of the solution	

	double x = newtonsMethod_Val(cubicDist, a, b, 0, x1, x1 + d, d, tol); // initial guess is x1+d (should be accurate for flat curves)
	double y = cubic(a, b, 0, 0, x);

	double z = atan2( (3.0 * a * x * x) + (2.0 * b * x), 1.0 );

	// x, y and z are in the local transition coordinate system, so transform to global coords	
	car.xPos = trans.LocalOriginX + (x * trans.LocalCos) - (y * trans.LocalSin);
	car.yPos = trans.LocalOriginY + (x * trans.LocalSin) + (y * trans.LocalCos);
	car.yaw = atan2(trans.LocalSin, trans.LocalCos) + z;

	// for linear lead in (constant acceleration or decel)
	double acc = trans.Accel; // acceleration
	double u = trans.InitialVel;
	double v = sqrt( (u * u) + (2.0 * acc * d)); // current speed using SUVAT
	car.timeOnPath = (2.0 * d) / (u + v);

	// record the distance
	car.distanceOnPath = d;

	//recordFunctionOutput("%lf, %lf, %lf, %f, %f,", car.xPos, car.yPos, car.yaw, car.timeOnPath, car.distanceOnPath);
	return car;
}

/**
 * @brief Calculate the coordinate of the point at distance d metres along a line segment
 *
 * Calculate the x, y, yaw, time, and total distance coordinates of the point at distance d metres along a line segment
 *
 * @author Unknown
 * @param[in] d - The distance along the segment in metres.
 * @param[in] seg - The segment data structure version 2. Used by robots with pmStructVerNum 2. Should be used with line type segments (seg.Type = SEG_STRAIGHT)
 * @return Returns the _COORDS data structure that contains x, y, yaw, t, and distance
 * @date
 *
 */
_COORDS line_2(double d, _SEGMENTDATA_2 seg, float extraTime)
{
	// Returns the x and y position of the point d metres along a line segment
	_COORDS car;

	car.xPos = seg.InitialX + (d * seg.InitialHeadingCos);
	car.yPos = seg.InitialY + (d * seg.InitialHeadingSin);
	car.yaw = atan2(seg.InitialHeadingSin, seg.InitialHeadingCos);

	// calculate the time
	car.timeOnPath = seg.InitialTime + timeOnSegment_2(d, seg) + extraTime;

	// record the distance
	car.distanceOnPath = seg.InitialDist + d;

	return car;
}

/**
 * @brief Calculate the coordinate of the point at distance d metres along an arc segment
 *
 * Calculate the x, y, yaw, time, and total distance coordinates of the point at distance d metres along an arc segment
 *
 * @author Unknown
 * @param[in] d - The distance along the segment in metres.
 * @param[in] seg - The segment data structure, version 2. Used by robots with pmStructVerNum 2. Should be used with arc type segments (seg.Type = SEG_ARC)
 * @return Returns the _COORDS data structure that contains x, y, yaw, t, and distance
 * @date 1 Oct 2019
 *
 */
_COORDS arc_2(double d, _SEGMENTDATA_2 seg, float extraTime)
{
	// Returns the x and y position of the point d metres along an arc segment (negative radius is a right turn)
	_COORDS car;

	double tempX, tempY, theta;

	theta = d / seg.Radius; // angle of travel in radians
	tempX = seg.Radius * sin(theta);
	tempY = seg.Radius * (1.0 - cos(theta));

	car.xPos = seg.InitialX + (tempX * seg.InitialHeadingCos) - (tempY * seg.InitialHeadingSin);
	car.yPos = seg.InitialY + (tempX * seg.InitialHeadingSin) + (tempY * seg.InitialHeadingCos);
	car.yaw = atan2(seg.InitialHeadingSin, seg.InitialHeadingCos) + theta;

	// calculate the time
	car.timeOnPath = seg.InitialTime + timeOnSegment_2(d, seg) + extraTime;

	// record the distance
	car.distanceOnPath = seg.InitialDist + d;

	return car;
}

/**
 * @brief Calculate the coordinate of the point at distance d metres along a log spiral segment
 *
 * Calculate the x, y, yaw, time, and total distance coordinates of the point at distance d metres along a logarithmic spiral segment
 *
 * @author Unknown
 * @param[in] d - The distance along the segment in metres.
 * @param[in] seg - The segment data structure, version 2. Used by robots with pmStructVerNum 2. Should be used with log spiral type segments (seg.Type = SEG_SPIRAL)
 * @return Returns the _COORDS data structure that contains x, y, yaw, t, and distance
 * @date 5 Nov 2019
 *
 * @remarks Modifications:
 * Start        LCK  Pulled from robots project
 *  5-Nov-2019  LCK  Fix cppcheck and MISRA C violations. Optimisation for performance ~1250IR/call to ~425IR/call
 */
_COORDS logSpiral_2(double d, _SEGMENTDATA_2 seg, float extraTime)
{
	_COORDS car;

	float radius1, radius2;
	double sinArc, cosArc;
	int k;
	if (seg.Radius < 0)
	{ //right turn
		k = -1;
		radius1 = -seg.Radius;	//initial radius
		radius2 = -seg.EndRadius;	//final radius
	}
	else
	{
		k = 1;
		radius1 = seg.Radius;	//initial radius
		radius2 = seg.EndRadius;	//final radius
	}
	
	double radius_diff = (double)(radius2 - radius1);
	//float hyp = sqrt((radius_diff * radius_diff) + (length * length)); // it appears that PPMAC IDE cannot compile sqrt of floats
	float hyp = (float)sqrt((double)((radius_diff * radius_diff) + (seg.Length * seg.Length)));

	float cos_C = (radius_diff / hyp);
	float sin_C = (seg.Length / hyp);

	float B = radius_diff / seg.Length;
	float A = radius1 * sin_C;

	float F = (B * (float)d) / radius1;
	float E = log1p(F);
	float exp_E = 1.0f + F;

	double D = (double)(E / B);
	sincos(D, &sinArc, &cosArc); // It appears that PPMAC IDE cannot compile sincos of floats

	float X1 = A * ((cosArc * exp_E) - 1.0);  //temp var
	float Y1 = A * sinArc * exp_E;  //temp var

	float X2 = (X1 * cos_C) + (Y1 * sin_C);
	float Y2 = -k * ((X1 * sin_C) - (Y1 * cos_C));

	car.xPos = seg.InitialX + (X2 * seg.InitialHeadingCos) - (Y2 * seg.InitialHeadingSin);
	car.yPos = seg.InitialY + (X2 * seg.InitialHeadingSin) + (Y2 * seg.InitialHeadingCos);
	car.yaw = atan2(seg.InitialHeadingSin, seg.InitialHeadingCos) + D;

	// calculate the time
	car.timeOnPath = seg.InitialTime + timeOnSegment_2(d, seg) + extraTime;

	// record the distance
	car.distanceOnPath = seg.InitialDist + d;

	return car;
}

_COORDS stopPoint_2(_SEGMENTDATA_2 seg, float *extraTime)
{
	// Returns the x and y position of the stop point and increments extra time accordingly
	_COORDS car;

	car.xPos = seg.InitialX;
	car.yPos = seg.InitialY;
	car.yaw = atan2(seg.InitialHeadingSin, seg.InitialHeadingCos);

	// calculate the time
	car.timeOnPath = seg.InitialTime + *extraTime;

	// increment extra time accordingly
	if (seg.StartTriggerChan != -1)
	{
		*extraTime += 1000.0f;
	}

	// record the distance
	car.distanceOnPath = seg.InitialDist;

	return car;
}

/**
 * @brief Calculate the coordinate of the point at distance d metres along a b spline point segment
 *
 * Calculate the x, y, yaw, time, and total distance coordinates of the point at distance d metres along a b spline point segment
 *
 * @author Unknown
 * @param[in] d - The distance along the segment in metres.
 * @param[in] seg - The segment data structure, version 2. Used by robots with pmStructVerNum 2. Should be used with log spiral type segments (seg.Type = SEG_SPIRAL)
 * @param[in] *spline - Pointer to the array of spline point data for this segment
 * @return Returns the _COORDS data structure that contains x, y, yaw, t, and distance
 * @date 1 Oct 2019
 *
 */
_COORDS bSpline_2(double d, _SEGMENTDATA_2 seg, _SPLINEDATA_0* spline, float extraTime)
{
	_COORDS car;
	double arrayFloat;
	arrayFloat = d * seg.InvPointDist;  //array idx on spline (including fractional part) 0 => start point
	int nodeidx = (int)arrayFloat + 1; // idx of the preceding spline point

	// calculate the proportion of the distance between consecutive nodes (cubic b spline)
	double A = arrayFloat - (double)(short)arrayFloat;
	double B = A * A; // A^2
	double C = A * B; // A^3

	// calculate the coefficients (this might not have to be done every time if we stay on the same segment)
	double xCoeffA = -spline[nodeidx - 1].X + (3.0 * spline[nodeidx].X) - (3.0 * spline[nodeidx + 1].X) + spline[nodeidx + 2].X;
	double xCoeffB = (3.0 * spline[nodeidx - 1].X) - (6.0 * spline[nodeidx].X) + (3.0 * spline[nodeidx + 1].X);
	double xCoeffC = -(3.0 * spline[nodeidx - 1].X) + (3.0 * spline[nodeidx + 1].X);
	double xCoeffD = spline[nodeidx - 1].X + (4.0 * spline[nodeidx].X) + spline[nodeidx + 1].X;

	double yCoeffA = -spline[nodeidx - 1].Y + (3.0 * spline[nodeidx].Y) - (3.0 * spline[nodeidx + 1].Y) + spline[nodeidx + 2].Y;
	double yCoeffB = (3.0 * spline[nodeidx - 1].Y) - (6.0 * spline[nodeidx].Y) + (3.0 * spline[nodeidx + 1].Y);
	double yCoeffC = -(3.0 * spline[nodeidx - 1].Y) + (3.0 * spline[nodeidx + 1].Y);
	double yCoeffD = spline[nodeidx - 1].Y + (4.0 * spline[nodeidx].Y) + spline[nodeidx + 1].Y;

	double tCoeffA = -spline[nodeidx - 1].Time + (3.0 * spline[nodeidx].Time) - (3.0 * spline[nodeidx + 1].Time) + spline[nodeidx + 2].Time;
	double tCoeffB = (3.0 * spline[nodeidx - 1].Time) - (6.0 * spline[nodeidx].Time) + (3.0 * spline[nodeidx + 1].Time);
	double tCoeffC = -(3.0 * spline[nodeidx - 1].Time) + (3.0 * spline[nodeidx + 1].Time);
	double tCoeffD = spline[nodeidx - 1].Time + (4.0 * spline[nodeidx].Time) + spline[nodeidx + 1].Time;

	car.xPos = 0.1666666 * ((xCoeffA * C) + (xCoeffB * B) + (xCoeffC * A) + xCoeffD);
	car.yPos = 0.1666666 * ((yCoeffA * C) + (yCoeffB * B) + (yCoeffC * A) + yCoeffD);

	double X1 = 0.1666666 * ((3.0 * xCoeffA * B) + (2.0 * xCoeffB * A) + xCoeffC);
	double Y1 = 0.1666666 * ((3.0 * yCoeffA * B) + (2.0 * yCoeffB * A) + yCoeffC);

	car.yaw = atan2(Y1, X1);

	// calculate the time
	car.timeOnPath = 0.1666666 * ((tCoeffA * C) + (tCoeffB * B) + (tCoeffC * A) + tCoeffD) + extraTime;

	// record the distance
	car.distanceOnPath = seg.InitialDist + d;

	return car;
}

/**
 * @brief Calculate the coordinate of the point at distance d metres along a cubic transition
 *
 * Calculate the x, y, yaw, time, and total distance coordinates of the point at distance d metres along a cubic transition
 *
 * @author Louis Kempton
 * @param[in] d - The distance along the segment in metres.
 * @param[in] trans - The transition data structure, version 2. Used by robots with pmStructVerNum 2.
 * @param[in] x1 - The first valid x position on the transition.
 * @return Returns the _COORDS data structure that contains x, y, yaw, t, and distance
 * @date 1 Oct 2019
 *
 */
_COORDS cubTransition_2(double d, _TRANSITIONDATA_2 trans, double x1)
{
	// Returns the x and y position of a point on the transition curve trans that is distance d along the curve from (x1,y1)
	_COORDS car;

	double a = trans.CoeffA;
	double b = trans.CoeffB;
	// c and d are always 0 for cubic transitions

	double tol = 1e-4; // tolerance of the solution	

	double x = newtonsMethod_Val(cubicDist, a, b, 0, x1, x1 + d, d, tol); // initial guess is x1+d (should be accurate for flat curves)
	double y = cubic(a, b, 0, 0, x);

	double z = atan2( (3.0 * a * x * x ) + (2.0 * b * x), 1.0 );

	// x, y and z are in the local transition coordinate system, so transform to global coords	
	car.xPos = trans.LocalOriginX + (x * trans.LocalCos) - (y * trans.LocalSin);
	car.yPos = trans.LocalOriginY + (x * trans.LocalSin) + (y * trans.LocalCos);
	car.yaw = atan2(trans.LocalSin, trans.LocalCos) + z;

	// for linear lead in (constant acceleration or decel)
	double acc = trans.Accel; // acceleration
	double u = trans.InitialVel;
	double v = sqrt( (u * u) + (2.0 * acc * d) ); // current speed using SUVAT
	car.timeOnPath = (2.0 * d) / (u + v);

	// record the distance
	car.distanceOnPath = d;

	return car;
}

/**
 * @brief Calculate the coordinate of the point at a time t seconds along a cubic transition
 *
 * Calculate the x, y, yaw, time, and total distance coordinates of the point at distance d metres along a cubic transition
 *
 * @author Louis Kempton
 * @param[in] t - The time along the segment in seconds.
 * @param[in] trans - The transition data structure, version 2. Used by robots with pmStructVerNum 2.
 * @param[in] x1 - The first valid x position on the transition.
 * @return Returns the _COORDS data structure that contains x, y, yaw, t, and distance
 * @date 26 Apr 2021
 *
 */
_COORDS cubTransition_2_t( double t, _TRANSITIONDATA_2 trans, double x1 )
{
	// Returns the x and y position of a point on the transition curve trans that is time t along the curve from (x1,y1)
	_COORDS car;

	double a = trans.CoeffA;
	double b = trans.CoeffB;
	// c and d are always 0 for cubic transitions

	double tol = 1e-4; // tolerance of the solution

	// for linear lead in (constant acceleration or decel)
	double acc = trans.Accel; // acceleration
	double u = trans.InitialVel;

	double v = u + acc * t;
	double d = 0.5 * (u + v) * t;

	double x = newtonsMethod_Val( cubicDist, a, b, 0, x1, x1 + d, d, tol ); // initial guess is x1+d (should be accurate for flat curves)
	double y = cubic( a, b, 0, 0, x );

	double z = atan2( (3.0 * a * x * x) + (2.0 * b * x), 1.0 );

	// x, y and z are in the local transition coordinate system, so transform to global coords	
	car.xPos = trans.LocalOriginX + (x * trans.LocalCos) - (y * trans.LocalSin);
	car.yPos = trans.LocalOriginY + (x * trans.LocalSin) + (y * trans.LocalCos);
	car.yaw = atan2( trans.LocalSin, trans.LocalCos ) + z;

	car.timeOnPath = t;

	// record the distance
	car.distanceOnPath = d;

	return car;
}


/**
 * @brief Calculate the coordinate of the point at a distance d metres along a test
 *
 * Calculate the x, y, yaw, time, and total distance coordinates of the point at distance d metres along a test
 *
 * @author Louis Kempton
 * @param[in] d - The time along the segment in seconds.
 * @param[in] test - The test data structure, version 2. Used by robots with pmStructVerNum 4.
 * @param[in] seg - The pointer to the segment data structure
 * @param[out] car - Output coordinate, must not be NULL
 * @return Returns 1 if successful, negative otherwise
 * @date 14 Mar 2022
 *
 */
int testPoint_4( double d, _TESTDATA_2 test, _SEGMENTDATA_2 *seg, _SPLINEDATA_0* spline, _COORDS *car )
{
	_COORDS p;	

	if ((car == NULL) || (seg == NULL))
		return -1;
	
	if (( d < 0.0 ) || (d > test.Length)) // check distance
		return -1;
	
	uint16_t seg_id = test.FirstSegmentIndex;
	int thisSegment = -1;
	
	while (seg_id < test.FirstSegmentIndex + test.nSegments)
	{
		if (seg[seg_id].Type == SEG_STOP)
		{
			++seg_id;
			continue;
		}
	
		if (seg[seg_id].InitialDist < d)
		{
			thisSegment = seg_id;		
		}
		else
			break;
		
		++seg_id;
	}
	
	if ( thisSegment < 0 )
	{
		return -2;
	}
		
	if (( d > seg[thisSegment].InitialDist ) && ( d < seg[thisSegment].InitialDist + seg[thisSegment].Length ))
	{
		switch(seg[thisSegment].Type)
		{
			case SEG_STRAIGHT:
				p = line_2( d - seg[thisSegment].InitialDist, seg[thisSegment], 0.0 );
				break;
			case SEG_ARC:
				p = arc_2( d - seg[thisSegment].InitialDist, seg[thisSegment], 0.0 );
				break;				
			case SEG_SPIRAL:
				p = logSpiral_2( d - seg[thisSegment].InitialDist, seg[thisSegment], 0.0 );
				break;	
			case SEG_BSPLINE:
				p = bSpline_2( d - seg[thisSegment].InitialDist, seg[thisSegment], spline, 0.0 );
				break;	
			default:
				return -3;								
		}
				
		*car = p;		
	}
	else
	{
		return -4;
	}
	
	return 1;
}

/**
 * @brief Calculate the coordinate of the point at a distance d metres along a test
 *
 * Calculate the x, y, yaw, time, and total distance coordinates of the point at distance d metres along a test
 *
 * @author Louis Kempton
 * @param[in] d - The time along the segment in seconds.
 * @param[in] test - The test data structure, version 5. Used by robots with pmStructVerNum 5.
 * @param[in] seg - The pointer to the segment data structure
 * @param[out] car - Output coordinate, must not be NULL
 * @return Returns 1 if successful, negative otherwise
 * @date 14 Mar 2022
 *
 */
int testPoint_5( double d, _TESTDATA_5 test, _SEGMENTDATA_2 *seg, _SPLINEDATA_0* spline, _COORDS *car )
{
	_COORDS p;
	

	if ((car == NULL) || (seg == NULL))
		return -1;
	
	if (( d < 0.0 ) || (d > test.Length)) // check distance
		return -1;
	
	uint16_t seg_id = test.FirstSegmentIndex;
	int thisSegment = -1;
	
	
	while (seg_id < test.FirstSegmentIndex + test.nSegments)
	{
		if (seg[seg_id].Type == SEG_STOP)
		{
			++seg_id;
			continue;
		}
	
		if (seg[seg_id].InitialDist < d)
		{
			thisSegment = seg_id;		
		}
		else
			break;
		
		++seg_id;
	}
	
	if ( thisSegment < 0 )
	{
		return -2;
	}
		
	if (( d > seg[thisSegment].InitialDist ) && ( d < seg[thisSegment].InitialDist + seg[thisSegment].Length ))
	{
		switch(seg[thisSegment].Type)
		{
			case SEG_STRAIGHT:
				p = line_2( d - seg[thisSegment].InitialDist, seg[thisSegment], 0.0 );
				break;
			case SEG_ARC:
				p = arc_2( d - seg[thisSegment].InitialDist, seg[thisSegment], 0.0 );
				break;				
			case SEG_SPIRAL:
				p = logSpiral_2( d - seg[thisSegment].InitialDist, seg[thisSegment], 0.0 );
				break;	
			case SEG_BSPLINE:
				p = bSpline_2( d - seg[thisSegment].InitialDist, seg[thisSegment], spline, 0.0 );
				break;	
			default:
				return -3;								
		}
				
		*car = p;
	}
	else
	{
		return -4;
	}
	
	return 1;
}
