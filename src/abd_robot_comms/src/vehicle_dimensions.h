#ifndef __VEHICLE_DIMENSIONS_H__
#define __VEHICLE_DIMENSIONS_H__

#include <stdint.h>

#define VEHICLE_DIMENSIONS_LOCATION 45076

// Vehicle dimension / wireframe types
#define VEH_DIM_ROBOT 0x01
#define VEH_DIM_TRANSPONDER_VEHICLE 0x02
#define VEH_DIM_TRANSPONDER_PEDESTRIAN 0x03

typedef struct
{
	//Vehicle info
	uint16_t pmVehicleStatusX;			 //pmVehicleStatusX->X:$060013,0,12  (Daimler concept car stuff)
	uint16_t pmVehicleStatusY;			 //pmVehicleStatusY->Y:$060013,0,16
	uint16_t pmVehicleDisplayType;		 //pmVehicleDisplayType->X:$060013,12,4
	unsigned char vehicle_dimension_type;
	unsigned char padding;
	float pmFwdShift;					 //pmFwdShift->F:$06004B
	float pmWheelBase;					 //pmWheelBase->F:$06004C
	float pmVehicleLength;				 //pmVehicleLength->F:$06004E
	float pmVehicleWidth;				 //pmVehicleWidth->F:$06004F
	float pmVehicleFrontOverhang;	     //pmVehicleFrontOverhang->F:$060050
} _VEHICLEDATA;

#endif
