#ifndef __DRIVERLESS_VALUES_STRUCT_H__
#define __DRIVERLESS_VALUES_STRUCT_H__

#include <stdint.h>

#define DRIVERLESSVALUES_LOCATION 38020

typedef struct driverless_values_t
{
	float pmBrEmergencyDisp;
	float pmBrHoldForce;
	float pmBrEmergencyForce;
	float pmBrNormalDecel;
	float pmBrEmergencyDecel;
	uint16_t pmBaseStationTimeout;
}_DRIVERLESSVALUES; 

#endif
