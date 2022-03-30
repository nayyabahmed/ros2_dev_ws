#ifndef _SEGMENT_FUNCTIONS_H_
#define _SEGMENT_FUNCTIONS_H_

#include <stddef.h>
#ifndef _GNU_SOURCE
	#define _GNU_SOURCE
#endif
#include <math.h>
#include <stdio.h>

#include "numeric_analysis.h"
#include "pf_structures.h"

// Segment types
#define SEG_STOP 0
#define SEG_STRAIGHT 1
#define SEG_ARC 2
#define SEG_SPIRAL 3
#define SEG_BSPLINE 4

#ifdef __cplusplus
extern "C" {
#endif

// Version 0 segments (for pmStructVerNum 0 and 1)

double timeOnSegment(double d, _SEGMENTDATA_0 seg);

_COORDS line(double d,_SEGMENTDATA_0 seg, float extraTime);
_COORDS arc(double d,_SEGMENTDATA_0 seg, float extraTime);
_COORDS logSpiral(double d,_SEGMENTDATA_0 seg, float extraTime);
_COORDS bSpline(double d,_SEGMENTDATA_0 seg,_SPLINEDATA_0* spline, float extraTime);
_COORDS stopPoint(_SEGMENTDATA_0 seg, float *extraTime);
_COORDS cubTransition(double d, _TRANSITIONDATA_0 trans, double x1);

// Version 2 segments (for pmStructVerNum 2 and above)

double timeOnSegment_2(double d, _SEGMENTDATA_2 seg);

_COORDS line_2(double d,_SEGMENTDATA_2 seg, float extraTime);
_COORDS arc_2(double d,_SEGMENTDATA_2 seg, float extraTime);
_COORDS logSpiral_2(double d,_SEGMENTDATA_2 seg, float extraTime);
_COORDS bSpline_2(double d,_SEGMENTDATA_2 seg,_SPLINEDATA_0* spline, float extraTime);
_COORDS stopPoint_2(_SEGMENTDATA_2 seg, float *extraTime);
_COORDS cubTransition_2(double d, _TRANSITIONDATA_2 trans, double x1);
_COORDS cubTransition_2_t( double t, _TRANSITIONDATA_2 trans, double x1 );

int testPoint_4( double d, _TESTDATA_2 test, _SEGMENTDATA_2 *seg, _SPLINEDATA_0* spline, _COORDS *car );
int testPoint_5( double d, _TESTDATA_5 test, _SEGMENTDATA_2 *seg, _SPLINEDATA_0* spline, _COORDS *car );

#ifdef __cplusplus
}
#endif

#endif
