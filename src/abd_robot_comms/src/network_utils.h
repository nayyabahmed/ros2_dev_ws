#ifndef _NETWORK_UTILS_H_
#define _NETWORK_UTILS_H_

#include <arpa/inet.h>
#include <stdint.h>
#include <endian.h>
#include <string.h>

//#include "../../Include/car_structure.h"
#include "datum_struct.h"
#include "driverless_struct.h"
#include "driverless_values_struct.h"
#include "vehicle_dimensions.h"
#include "pf_structures.h"

#ifdef __cplusplus
extern "C" {
#endif

//-------------------------------------
// endianness swapping for floats

float htole_float( float in );
float htobe_float( float in );
float letoh_float( float in );
float betoh_float( float in );

//-------------------------------------
// endianness swapping for doubles

double htole_double( double in );
double htobe_double( double in );
double letoh_double( double in );
double betoh_double( double in );


// serialisation and deserialisation functions

unsigned char *deserialise_uchar(unsigned char *buffer, unsigned char *value);
unsigned char *serialise_uchar(unsigned char *buffer, unsigned char value);

unsigned char *deserialise_uint16(unsigned char *buffer, uint16_t *value);
unsigned char *deserialise_uint16_l(unsigned char *buffer, uint16_t *value);
unsigned char *serialise_uint16(unsigned char *buffer, uint16_t value);
unsigned char *serialise_uint16_l(unsigned char *buffer, uint16_t value);

unsigned char *deserialise_int16(unsigned char *buffer, int16_t *value);
unsigned char *deserialise_int16_l(unsigned char *buffer, int16_t *value);
unsigned char *serialise_int16(unsigned char *buffer, int16_t value);
unsigned char *serialise_int16_l(unsigned char *buffer, int16_t value);

unsigned char *deserialise_uint32(unsigned char *buffer, uint32_t *value);
unsigned char *deserialise_uint32_l(unsigned char *buffer, uint32_t *value);
unsigned char *serialise_uint32(unsigned char *buffer, uint32_t value);
unsigned char *serialise_uint32_l(unsigned char *buffer, uint32_t value);

unsigned char *deserialise_int32(unsigned char *buffer, int32_t *value);
unsigned char *deserialise_int32_l(unsigned char *buffer, int32_t *value);
unsigned char *serialise_int32(unsigned char *buffer, int32_t value);
unsigned char *serialise_int32_l(unsigned char *buffer, int32_t value);

unsigned char *serialise_uint64(unsigned char *buffer, uint64_t value);
unsigned char *serialise_uint64_l(unsigned char *buffer, uint64_t value);

unsigned char *deserialise_int64(unsigned char *buffer, int64_t *value);
unsigned char *deserialise_int64_l(unsigned char *buffer, int64_t *value);
unsigned char *serialise_int64(unsigned char *buffer, int64_t value);
unsigned char *serialise_int64_l(unsigned char *buffer, int64_t value);

unsigned char *deserialise_float(unsigned char *buffer, float *value);
unsigned char *deserialise_float_l(unsigned char *buffer, float *value);
unsigned char *serialise_float(unsigned char *buffer, float value);
unsigned char *serialise_float_l(unsigned char *buffer, float value);

unsigned char *deserialise_double(unsigned char *buffer, double *value);
unsigned char *deserialise_double_l(unsigned char *buffer, double *value);
unsigned char *serialise_double(unsigned char *buffer, double value);
unsigned char *serialise_double_l(unsigned char *buffer, double value);

//---- 
// memory safe

unsigned char *try_deserialise_uchar( unsigned char *buffer, unsigned char *value, uint32_t bufferSize, uint32_t *bufferSizeRemaining );
unsigned char *try_serialise_uchar( unsigned char *buffer, unsigned char value, uint32_t bufferSize, uint32_t *bufferSizeRemaining );
unsigned char *try_deserialise_uint16( unsigned char *buffer, uint16_t *value, uint32_t bufferSize, uint32_t *bufferSizeRemaining );
unsigned char *try_deserialise_uint16_l( unsigned char *buffer, uint16_t *value, uint32_t bufferSize, uint32_t *bufferSizeRemaining );
unsigned char *try_deserialise_uint32( unsigned char *buffer, uint32_t *value, uint32_t bufferSize, uint32_t *bufferSizeRemaining );
unsigned char *try_deserialise_uint32_l( unsigned char *buffer, uint32_t *value, uint32_t bufferSize, uint32_t *bufferSizeRemaining );

unsigned char *try_deserialise_byteArray( unsigned char *buffer, unsigned char *out_array, uint32_t numBytes, uint32_t bufferSize, uint32_t *bufferSizeRemaining );
unsigned char *try_serialise_byteArray( unsigned char *buffer, unsigned char *in_array, uint32_t numBytes, uint32_t bufferSize, uint32_t *bufferSizeRemaining );

void letoh_DMAP1DATA( DMAP1DATA *in );
void letoh_DMAP2DATA( DMAP2DATA *in );
void letoh_DMAP3DATA( DMAP3DATA *in );

void letoh_DRESTARTDATA( DRESTARTDATA *in );

_VEHICLEDATA letoh_VehicleData( _VEHICLEDATA vehDataIn);
_VEHICLEDATA betoh_VehicleData( _VEHICLEDATA vehDataIn);

_DATUMDATA letoh_DatumData (_DATUMDATA datumIn);
_DATUMDATA betoh_DatumData (_DATUMDATA datumIn);

_DRIVERLESSVALUES letoh_DriverlessValues( _DRIVERLESSVALUES driverlessValuesIn );
_DRIVERLESSVALUES betoh_DriverlessValues( _DRIVERLESSVALUES driverlessValuesIn );

// Pf structures

_GROUPDATA_0 letoh_GroupData_0(_GROUPDATA_0 groupIn);
_GROUPDATA_0 betoh_GroupData_0(_GROUPDATA_0 groupIn);

_GROUPDATA_2 letoh_GroupData_2(_GROUPDATA_2 groupIn);
_GROUPDATA_2 betoh_GroupData_2(_GROUPDATA_2 groupIn);

_GROUPDATA_4 letoh_GroupData_4(_GROUPDATA_4 groupIn);
_GROUPDATA_4 betoh_GroupData_4(_GROUPDATA_4 groupIn);

_SUBGROUPDATA_0 letoh_SubGroupData_0(_SUBGROUPDATA_0 subgroupIn);
_SUBGROUPDATA_0 betoh_SubGroupData_0(_SUBGROUPDATA_0 subgroupIn);

_SUBGROUPDATA_1 letoh_SubGroupData_1(_SUBGROUPDATA_1 subgroupIn);
_SUBGROUPDATA_1 betoh_SubGroupData_1(_SUBGROUPDATA_1 subgroupIn);

_SUBGROUPDATA_2 letoh_SubGroupData_2(_SUBGROUPDATA_2 subgroupIn);
_SUBGROUPDATA_2 betoh_SubGroupData_2(_SUBGROUPDATA_2 subgroupIn);

_TESTDATA_0 letoh_TestData_0(_TESTDATA_0 testIn);
_TESTDATA_0 betoh_TestData_0(_TESTDATA_0 testIn);

_TESTDATA_1 letoh_TestData_1(_TESTDATA_1 testIn);
_TESTDATA_1 betoh_TestData_1(_TESTDATA_1 testIn);

_TESTDATA_2 letoh_TestData_2(_TESTDATA_2 testIn);
_TESTDATA_2 betoh_TestData_2(_TESTDATA_2 testIn);

_TESTDATA_5 letoh_TestData_5(_TESTDATA_5 testIn);
_TESTDATA_5 betoh_TestData_5(_TESTDATA_5 testIn);

_TRANSITIONDATA_0 letoh_TransitionData_0(_TRANSITIONDATA_0 transIn);
_TRANSITIONDATA_0 betoh_TransitionData_0(_TRANSITIONDATA_0 transIn);

_TRANSITIONDATA_2 letoh_TransitionData_2(_TRANSITIONDATA_2 transIn);
_TRANSITIONDATA_2 betoh_TransitionData_2(_TRANSITIONDATA_2 transIn);

_SEGMENTDATA_0 letoh_SegmentData_0(_SEGMENTDATA_0 segmentIn);
_SEGMENTDATA_0 betoh_SegmentData_0(_SEGMENTDATA_0 segmentIn);

_SEGMENTDATA_2 letoh_SegmentData_2(_SEGMENTDATA_2 segmentIn);
_SEGMENTDATA_2 betoh_SegmentData_2(_SEGMENTDATA_2 segmentIn);

_SPLINEDATA_0 letoh_SplineData_0(_SPLINEDATA_0 splineIn);
_SPLINEDATA_0 betoh_SplineData_0(_SPLINEDATA_0 splineIn);

_CRITSECTDATA_0 letoh_CritSectData_0(_CRITSECTDATA_0 critSectIn);
_CRITSECTDATA_0 betoh_CritSectData_0(_CRITSECTDATA_0 critSectIn);

_CRITSECTDATA_2 letoh_CritSectData_2(_CRITSECTDATA_2 critSectIn);
_CRITSECTDATA_2 betoh_CritSectData_2(_CRITSECTDATA_2 critSectIn);

_DRIVERLESSDATA_0 letoh_DriverlessData_0(_DRIVERLESSDATA_0 driverlessIn);
_DRIVERLESSDATA_0 betoh_DriverlessData_0(_DRIVERLESSDATA_0 driverlessIn);

_DRIVERLESSDATA_2 letoh_DriverlessData_2(_DRIVERLESSDATA_2 driverlessIn);
_DRIVERLESSDATA_2 betoh_DriverlessData_2(_DRIVERLESSDATA_2 driverlessIn);

#ifdef __cplusplus
}
#endif

#endif
