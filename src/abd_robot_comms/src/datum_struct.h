#ifndef __DATUM_STRUCT_H__
#define __DATUM_STRUCT_H__

#include <stdint.h>

#define DATUM_LOCATION 45472

typedef struct
{
	// Structure containing data regarding the position of a car's datum for its coordinate system
	// follows the same pattern as ushm address 45472, so we can extract it in one chunk
	int32_t pmLongitudeInt;
	float pmLongitudeFract;
	int32_t pmLatitudeInt;
	float pmLatitudeFract;
	float pmXaxisDatumBearing;
	float pmRefHeight;
} _DATUMDATA;

#endif
