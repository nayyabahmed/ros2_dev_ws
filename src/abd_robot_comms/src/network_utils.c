/**
 * @file network_utils.c
 * @author Louis Kempton
 * @date  29 August 2018
 *
 * @brief Source file for functions that deal with serialising and deserialising various types and structures into byte streams.
 *
 * Contains functions for serialising data types into byte streams and deserialising data from byte streams.
 * Functions are providied for big and little endian data types in byte streams.
 *
 *
 * @remarks Modifications:
 * 29-Aug-2018  LCK  Copied library from robots project.
 * 21-Nov-2019  LCK  Wrote unit tests and standardised procedure using htoxx() functions from endian.h
 *
 * TODO:
 * 100% unit test coverage
 * Standardise operation
 * Remove unused functions and libraries
 * Compliance with MISRA C
 * Make memory safe wrappers with failure cases
 */

#include "network_utils.h"

//-------------------------------------
// endianness swapping for floats

float htole_float( float in )
{
	float out;
	uint32_t in_u;
	memcpy( &in_u, &in, sizeof( in_u ) );
	uint32_t out_u = htole32( in_u );
	memcpy( &out, &out_u, sizeof( in_u ) );

	return out;
}

float htobe_float( float in )
{
	float out;
	uint32_t in_u;
	memcpy( &in_u, &in, sizeof( in_u ) );
	uint32_t out_u = htobe32( in_u );
	memcpy( &out, &out_u, sizeof( in_u ) );

	return out;
}

float letoh_float( float in )
{
	float out;
	uint32_t in_u;
	memcpy( &in_u, &in, sizeof( in_u ) );
	uint32_t out_u = le32toh( in_u );
	memcpy( &out, &out_u, sizeof( in_u ) );

	return out;
}

float betoh_float( float in )
{
	float out;
	uint32_t in_u;
	memcpy( &in_u, &in, sizeof( in_u ) );
	uint32_t out_u = be32toh( in_u );
	memcpy( &out, &out_u, sizeof( in_u ) );

	return out;
}

//-------------------------------------
// endianness swapping for doubles

double htole_double( double in )
{
	double out;
	uint64_t in_u;
	memcpy( &in_u, &in, sizeof( in_u ) );
	uint64_t out_u = htole64( in_u );
	memcpy( &out, &out_u, sizeof( in_u ) );

	return out;
}

double htobe_double( double in )
{
	double out;
	uint64_t in_u;
	memcpy( &in_u, &in, sizeof( in_u ) );
	uint64_t out_u = htobe64( in_u );
	memcpy( &out, &out_u, sizeof( in_u ) );

	return out;
}

double letoh_double( double in )
{
	double out;
	uint64_t in_u;
	memcpy( &in_u, &in, sizeof( in_u ) );
	uint64_t out_u = le64toh( in_u );
	memcpy( &out, &out_u, sizeof( in_u ) );

	return out;
}

double betoh_double( double in )
{
	double out;
	uint64_t in_u;
	memcpy( &in_u, &in, sizeof( in_u ) );
	uint64_t out_u = be64toh( in_u );
	memcpy( &out, &out_u, sizeof( in_u ) );

	return out;
}


//--------------------------------------------------
// Serialisation and deserialisation functions

//----------------
// uchar

/**
 * @brief Deserialise a big endian uint16 from a byte stream.
 *
 * Deserialises a uchar value from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] *value - Pointer to the recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit test
 *
 */
unsigned char *deserialise_uchar(unsigned char *buffer, unsigned char *value)
{
	*value = buffer[0];
	return &(buffer[1]);
}

/**
 * @brief Serialise a uchar value to a byte stream
 *
 * Serialises a uchar value to a byte stream
 *
 * @author Louis Kempton
 * @param[out] *buffer - The byte stream
 * @param[in] value - The value to write
 * @return Returns the new write location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit test
 *
 */
unsigned char *serialise_uchar(unsigned char *buffer, unsigned char value)
{
	buffer[0] = value;
	return &(buffer[1]);
}


//----------------
// uint16_t

/**
 * @brief Deserialise a big endian uint16 from a byte stream.
 *
 * Deserialises a uint16 value in big endian format from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] value - The recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit tests
 *                   Reduced IR per call from 16.65 to 6
 * 
 */
unsigned char *deserialise_uint16(unsigned char *buffer, uint16_t *value)
{
	// Read big-endian uint16 value from buffer
	uint16_t ui;
	memcpy( &ui, buffer, sizeof( ui ) );
	*value = be16toh( ui );

	return &(buffer[sizeof( ui )]);
}

/**
 * @brief Deserialise a little endian uint16 from a byte stream.
 *
 * Deserialises a uint16 value in little endian format from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] value - The recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit tests
 *
 */
unsigned char *deserialise_uint16_l(unsigned char *buffer, uint16_t *value)
{
	// Read little-endian uint16 value from buffer
	uint16_t ui;
	memcpy( &ui, buffer, sizeof(ui) );
	*value = le16toh( ui );

	return &(buffer[sizeof( ui )]);
}

/**
 * @brief Serialise a uint16 value to a byte stream in big endian format
 *
 * Serialises a uint16 value to a byte stream in big endian format
 *
 * @author Louis Kempton
 * @param[out] *buffer - The byte stream
 * @param[in] value - The value to write
 * @return Returns the new write location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit test
 *                   Reduced IR per call from 12.65 to 4
 */
unsigned char *serialise_uint16(unsigned char *buffer, uint16_t value)
{
	// Write big-endian uint16 into buffer
	uint16_t ui = htobe16( value );
	memcpy(buffer, &ui, sizeof( ui ));

	return &(buffer[sizeof( ui )]);
}

/**
 * @brief Serialise a uint16 value to a byte stream in little endian format
 *
 * Serialises a uint16 value to a byte stream in little endian format
 *
 * @author Louis Kempton
 * @param[out] *buffer - The byte stream
 * @param[in] value - The value to write
 * @return Returns the new write location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit test
 */
unsigned char *serialise_uint16_l(unsigned char *buffer, uint16_t value)
{
	// Write little-endian uint16 into buffer
	uint16_t ui = htole16( value );
	memcpy( buffer, &ui, sizeof( ui ) );

	return &(buffer[sizeof( ui )]);
}


//----------------
// int16_t

 /**
  * @brief Deserialise a big endian uint16 from a byte stream.
  *
  * Deserialises a uint16 value in big endian format from a byte stream
  *
  * @author Louis Kempton
  * @param[in] *buffer - The byte stream
  * @param[out] value - The recovered value
  * @return Returns the new read location in the byte stream
  * @date
  *
  * @remarks Modifications:
  * 21-Nov-2019  LCK  Wrote unit tests
  *                   Reduce IR per call from 51.29 to 6
  *
  */
unsigned char *deserialise_int16(unsigned char *buffer, int16_t *value)
{
	// Read big-endian int16 value from buffer
	int16_t i;
	memcpy( &i, buffer, sizeof( i ) );
	*value = be16toh( i );

	return &(buffer[sizeof( i )]);
}

/**
 * @brief Deserialise a big endian uint16 from a byte stream.
 *
 * Deserialises a uint16 value in big endian format from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] value - The recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit tests
 *
 */
unsigned char *deserialise_int16_l(unsigned char *buffer, int16_t *value)
{
	// Read little-endian int16 value from buffer
	int16_t i;
	memcpy( &i, buffer, sizeof( i ) );
	*value = le16toh( i );

	return &(buffer[sizeof( i )]);
}

/**
 * @brief Serialise an int16 value to a byte stream in big endian format
 *
 * Serialises an int16 value to a byte stream in big endian format
 *
 * @author Louis Kempton
 * @param[out] *buffer - The byte stream
 * @param[in] value - The value to write
 * @return Returns the new write location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit test
 *                   Reduce IR per call from 46.29 to 4
 */
unsigned char *serialise_int16(unsigned char *buffer, int16_t value)
{
	// Write big-endian int16 into buffer
	int16_t i = htobe16( value );
	memcpy( buffer, &i, sizeof( i ) );

	return &(buffer[sizeof( i )]);
}

/**
 * @brief Serialise an int16 value to a byte stream in little endian format
 *
 * Serialises an int16 value to a byte stream in little endian format
 *
 * @author Louis Kempton
 * @param[out] *buffer - The byte stream
 * @param[in] value - The value to write
 * @return Returns the new write location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit test
 *
 */
unsigned char *serialise_int16_l(unsigned char *buffer, int16_t value)
{
	// Write little-endian int16 into buffer
	int16_t i = htole16( value );
	memcpy( buffer, &i, sizeof( i ) );

	return &(buffer[sizeof( i )]);
}


//-------------------
// uint32

/**
 * @brief Deserialise a big endian uint32 from a byte stream.
 *
 * Deserialises a uint32 value in big endian format from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] value - The recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit tests
 *                   
 *
 */
unsigned char *deserialise_uint32(unsigned char *buffer, uint32_t *value)
{
	// Read big-endian uint32 value from buffer
	uint32_t ui;
	memcpy(&ui, buffer, sizeof(ui));
	*value = be32toh( ui );

	return &(buffer[sizeof( ui )]);
}

/**
 * @brief Deserialise a little endian uint32 from a byte stream.
 *
 * Deserialises a uint32 value in little endian format from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] value - The recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit tests
 *                   
 *
 */
unsigned char *deserialise_uint32_l(unsigned char *buffer, uint32_t *value)
{
	// Read little-endian uint32 value from buffer
	uint32_t ui;
	memcpy( &ui, buffer, sizeof( ui ) );
	*value = le32toh( ui );

	return &(buffer[sizeof( ui )]);
}

/**
 * @brief Serialise a uint32 value to a byte stream in big endian format
 *
 * Serialises a uint32 value to a byte stream in big endian format
 *
 * @author Louis Kempton
 * @param[out] *buffer - The byte stream
 * @param[in] value - The value to write
 * @return Returns the new write location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit test
 *                   Reduced IR per call from 54.29 to 4 using htobe
 */
unsigned char *serialise_uint32(unsigned char *buffer, uint32_t value)
{
	// Write big-endian uint32 into buffer
	uint32_t ui = htobe32( value );
	memcpy( buffer, &ui, sizeof( ui ) );

	return &(buffer[sizeof( ui )]);
}

/**
 * @brief Serialise a uint32 value to a byte stream in little endian format
 *
 * Serialises a uint32 value to a byte stream in little endian format
 *
 * @author Louis Kempton
 * @param[out] *buffer - The byte stream
 * @param[in] value - The value to write
 * @return Returns the new write location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit test
 *                   Refactor to use htole
 */
unsigned char *serialise_uint32_l(unsigned char *buffer, uint32_t value)
{
	// Write little-endian uint32 into buffer
	uint32_t ui = htole32( value );
	memcpy( buffer, &ui, sizeof( ui ) );

	return &(buffer[sizeof( ui )]);
}


//-------------------
// int32

/**
 * @brief Deserialise a big endian int32 from a byte stream.
 *
 * Deserialises an int32 value in big endian format from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] value - The recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit tests
 *
 */
unsigned char *deserialise_int32(unsigned char *buffer, int32_t *value)
{
	// Read big-endian int32 value from buffer
	int32_t i;
	memcpy(&i, buffer, sizeof(i));
	*value = be32toh( i );

	return &(buffer[sizeof( i )]);
}

/**
 * @brief Deserialise a little endian int32 from a byte stream.
 *
 * Deserialises an int32 value in little endian format from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] value - The recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit tests
 *
 */
unsigned char *deserialise_int32_l(unsigned char *buffer, int32_t *value)
{
	// Read little-endian int32 value from buffer
	int32_t i;
	memcpy(&i, buffer, sizeof(i));
	*value = le32toh( i );

	return &(buffer[sizeof( i )]);
}

/**
 * @brief Serialise an int32 value to a byte stream in big endian format
 *
 * Serialises an int32 value to a byte stream in big endian format
 *
 * @author Louis Kempton
 * @param[out] *buffer - The byte stream
 * @param[in] value - The value to write
 * @return Returns the new write location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit test
 *                   Reduced IR per call from 54.29 to 4 using htobe
 */
unsigned char *serialise_int32(unsigned char *buffer, int32_t value)
{
	// Write big-endian int32 into buffer
	int32_t i = htobe32( value );
	memcpy( buffer, &i, sizeof( i ) );

	return &(buffer[sizeof( i )]);
}

/**
 * @brief Serialise an int32 value to a byte stream in little endian format
 *
 * Serialises an int32 value to a byte stream in little endian format
 *
 * @author Louis Kempton
 * @param[out] *buffer - The byte stream
 * @param[in] value - The value to write
 * @return Returns the new write location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit test
 *
 */
unsigned char *serialise_int32_l(unsigned char *buffer, int32_t value)
{
	// Write little-endian int32 into buffer
	int32_t i = htole32( value );
	memcpy( buffer, &i, sizeof( i ) );

	return &(buffer[sizeof( i )]);
}

/**
 * @brief Serialise an uint64 value to a byte stream in big endian format
 *
 * Serialises an uint64 value to a byte stream in big endian format
 *
 * @author Louis Kempton
 * @param[out] *buffer - The byte stream
 * @param[in] value - The value to write
 * @return Returns the new write location in the byte stream
 * @date 31-Jul-2020
 *
 * @remarks Modifications:
 */
unsigned char *serialise_uint64(unsigned char *buffer, uint64_t value)
{
	// Write big-endian int64 into buffer
	uint64_t i = htobe64( value );
	memcpy( buffer, &i, sizeof( i ) );

	return &(buffer[sizeof( i )]);
}

/**
 * @brief Serialise an uint64 value to a byte stream in little endian format
 *
 * Serialises an uint64 value to a byte stream in little endian format
 *
 * @author Louis Kempton
 * @param[out] *buffer - The byte stream
 * @param[in] value - The value to write
 * @return Returns the new write location in the byte stream
 * @date 31-Jul-2020
 *
 * @remarks Modifications:
 *
 */
unsigned char *serialise_uint64_l(unsigned char *buffer, uint64_t value)
{
	// Write little-endian int64 into buffer
	uint64_t i = htole64( value );
	memcpy( buffer, &i, sizeof( i ) );

	return &(buffer[sizeof( i )]);
}

//-------------------
// int64

/**
 * @brief Deserialise a big endian int64 from a byte stream.
 *
 * Deserialises an int64 value in big endian format from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] value - The recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 *
 */
unsigned char *deserialise_int64(unsigned char *buffer, int64_t *value)
{
	// Read big-endian int64 value from buffer
	int64_t i;
	memcpy(&i, buffer, sizeof(i));
	*value = be64toh( i );

	return &(buffer[sizeof( i )]);
}

/**
 * @brief Deserialise a little endian int64 from a byte stream.
 *
 * Deserialises an int64 value in little endian format from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] value - The recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 *
 */
unsigned char *deserialise_int64_l(unsigned char *buffer, int64_t *value)
{
	// Read little-endian int64 value from buffer
	int64_t i;
	memcpy(&i, buffer, sizeof(i));
	*value = le64toh( i );

	return &(buffer[sizeof( i )]);
}

/**
 * @brief Serialise an int64 value to a byte stream in big endian format
 *
 * Serialises an int64 value to a byte stream in big endian format
 *
 * @author Louis Kempton
 * @param[out] *buffer - The byte stream
 * @param[in] value - The value to write
 * @return Returns the new write location in the byte stream
 * @date 31-Jul-2020
 *
 * @remarks Modifications:
 */
unsigned char *serialise_int64(unsigned char *buffer, int64_t value)
{
	// Write big-endian int64 into buffer
	int64_t i = htobe64( value );
	memcpy( buffer, &i, sizeof( i ) );

	return &(buffer[sizeof( i )]);
}

/**
 * @brief Serialise an int64 value to a byte stream in little endian format
 *
 * Serialises an int64 value to a byte stream in little endian format
 *
 * @author Louis Kempton
 * @param[out] *buffer - The byte stream
 * @param[in] value - The value to write
 * @return Returns the new write location in the byte stream
 * @date 31-Jul-2020
 *
 * @remarks Modifications:
 *
 */
unsigned char *serialise_int64_l(unsigned char *buffer, int64_t value)
{
	// Write little-endian int64 into buffer
	int64_t i = htole64( value );
	memcpy( buffer, &i, sizeof( i ) );

	return &(buffer[sizeof( i )]);
}

//----------------
// float

/**
 * @brief Deserialise a big endian float from a byte stream.
 *
 * Deserialises a float value in big endian format from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] value - The recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 21-Nov-2019  LCK  Wrote unit tests
 *                   Reduce IR per call from 19.64 to 5
 */
unsigned char *deserialise_float(unsigned char *buffer, float *value)
{
	// Read big-endian float value from buffer
	float f;
	memcpy( &f, buffer, sizeof( f ) );
	*value = betoh_float( f );

	return &(buffer[sizeof( f )]);
}

/**
 * @brief Deserialise a little endian float from a byte stream.
 *
 * Deserialises a float value in little endian format from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] value - The recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 22-Nov-2019  LCK  Wrote unit tests
 */
unsigned char *deserialise_float_l(unsigned char *buffer, float *value)
{
	// Read little-endian float value from buffer
	float f;
	memcpy( &f, buffer, sizeof( f ) );
	*value = letoh_float( f );

	return &(buffer[sizeof( f )]);
}

/**
 * @brief Serialise a big endian float to a byte stream.
 *
 * Serialises a float value in big endian format to a byte stream
 *
 * @author Louis Kempton
 * @param[in,out] *buffer - The byte stream
 * @param[in] value - The value to be written
 * @return Returns the new write location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 22-Nov-2019  LCK  Wrote unit tests
 *                   Reduced IR per call from 13.64 to 5
 */
unsigned char *serialise_float(unsigned char *buffer, float value)
{
	// Write big-endian float value to buffer
	float f = htobe_float( value );
	memcpy( buffer, &f, sizeof( f ) );

	return &(buffer[sizeof( f )]);
}

/**
 * @brief Serialise a little endian float to a byte stream.
 *
 * Serialises a float value in little endian format to a byte stream
 *
 * @author Louis Kempton
 * @param[in,out] *buffer - The byte stream
 * @param[in] value - The value to be written
 * @return Returns the new write location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 22-Nov-2019  LCK  Wrote unit tests
 */
unsigned char *serialise_float_l(unsigned char *buffer, float value)
{
	// Write little-endian float value to buffer
	float f = htole_float( value );
	memcpy( buffer, &f, sizeof( f ) );

	return &(buffer[sizeof( f )]);
}

//----------------
// double

/**
 * @brief Deserialise a big endian double from a byte stream.
 *
 * Deserialises a double value in big endian format from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] value - The recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 22-Nov-2019  LCK  Wrote unit tests
 *                   Reduce IR per call from 19.16 to
 */
unsigned char *deserialise_double(unsigned char *buffer, double *value)
{
	// Read big-endian double value from buffer
	double d;
	memcpy( &d, buffer, sizeof( d ) );
	*value = betoh_double( d );

	return &(buffer[sizeof( d )]);
}

/**
 * @brief Deserialise a little endian double from a byte stream.
 *
 * Deserialises a double value in little endian format from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] value - The recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 22-Nov-2019  LCK  Wrote unit tests
 */
unsigned char *deserialise_double_l(unsigned char *buffer, double *value)
{
	// Read little-endian double value from buffer
	double d;
	memcpy( &d, buffer, sizeof( d ) );
	*value = letoh_double( d );

	return &(buffer[sizeof( d )]);
}

/**
 * @brief Deserialise a big endian double from a byte stream.
 *
 * Deserialises a double value in big endian format from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] value - The recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 22-Nov-2019  LCK  Wrote unit tests
 *                   Reduce IR per call from 13.16 to
 */
unsigned char *serialise_double(unsigned char *buffer, double value)
{
	// Write big-endian double into buffer
	double d = htobe_double( value );
	memcpy( buffer, &d, sizeof( d ) );

	return &(buffer[sizeof( d )]);
}

/**
 * @brief Deserialise a big endian double from a byte stream.
 *
 * Deserialises a double value in big endian format from a byte stream
 *
 * @author Louis Kempton
 * @param[in] *buffer - The byte stream
 * @param[out] value - The recovered value
 * @return Returns the new read location in the byte stream
 * @date
 *
 * @remarks Modifications:
 * 22-Nov-2019  LCK  Wrote unit tests
 */
unsigned char *serialise_double_l(unsigned char *buffer, double value)
{
	// Write little-endian double into buffer
	double d = htole_double( value );
	memcpy( buffer, &d, sizeof( d ) );

	return &(buffer[sizeof( d )]);
}

//-----------------------------------------------
// Memory safe wrappers

unsigned char *try_deserialise_uchar( unsigned char *buffer, unsigned char *value, uint32_t bufferSize, uint32_t *bufferSizeRemaining )
{
	unsigned char *p;

	if (bufferSize >= sizeof( unsigned char ))
	{
		p = deserialise_uchar( buffer, value );
		*bufferSizeRemaining = bufferSize - sizeof( unsigned char );
	}
	else
	{
		p = NULL;
		*bufferSizeRemaining = bufferSize;
	}

	return p;
}

unsigned char *try_serialise_uchar( unsigned char *buffer, unsigned char value, uint32_t bufferSize, uint32_t *bufferSizeRemaining )
{
	unsigned char *p;

	if (bufferSize >= sizeof( unsigned char ))
	{
		p = serialise_uchar( buffer, value );
		*bufferSizeRemaining = bufferSize - sizeof( unsigned char );
	}
	else
	{
		p = NULL;
		*bufferSizeRemaining = bufferSize;
	}

	return p;
}

unsigned char *try_deserialise_uint16( unsigned char *buffer, uint16_t *value, uint32_t bufferSize, uint32_t *bufferSizeRemaining )
{
	unsigned char *p;

	if (bufferSize >= sizeof( uint16_t ))
	{
		p = deserialise_uint16( buffer, value );
		*bufferSizeRemaining = bufferSize - sizeof( uint16_t );
	}
	else
	{
		p = NULL;
		*bufferSizeRemaining = bufferSize;
	}

	return p;
}

unsigned char *try_deserialise_uint16_l( unsigned char *buffer, uint16_t *value, uint32_t bufferSize, uint32_t *bufferSizeRemaining )
{
	unsigned char *p;

	if (bufferSize >= sizeof( uint16_t ))
	{
		p = deserialise_uint16_l( buffer, value );
		*bufferSizeRemaining = bufferSize - sizeof( uint16_t );
	}
	else
	{
		p = NULL;
		*bufferSizeRemaining = bufferSize;
	}

	return p;
}


unsigned char *try_deserialise_uint32( unsigned char *buffer, uint32_t *value, uint32_t bufferSize, uint32_t *bufferSizeRemaining )
{
	unsigned char *p;
	
	if (bufferSize >= sizeof(uint32_t))
	{
		p = deserialise_uint32( buffer, value );
		*bufferSizeRemaining = bufferSize - sizeof( uint32_t );
	}
	else
	{
		p = NULL;
		*bufferSizeRemaining = bufferSize;
	}

	return p;
}

unsigned char *try_deserialise_uint32_l( unsigned char *buffer, uint32_t *value, uint32_t bufferSize, uint32_t *bufferSizeRemaining )
{
	unsigned char *p;

	if (bufferSize >= sizeof( uint32_t ))
	{
		p = deserialise_uint32_l( buffer, value );
		*bufferSizeRemaining = bufferSize - sizeof( uint32_t );
	}
	else
	{
		p = NULL;
		*bufferSizeRemaining = bufferSize;
	}

	return p;
}

unsigned char *try_deserialise_byteArray( unsigned char *buffer, unsigned char *out_array, uint32_t numBytes, uint32_t bufferSize, uint32_t *bufferSizeRemaining )
{
	unsigned char *p;
	if (bufferSize >= numBytes)
	{
		memcpy( out_array, buffer, numBytes );
		p = &(buffer[numBytes]);
		*bufferSizeRemaining = bufferSize - numBytes;
	}
	else
	{
		p = NULL;
		*bufferSizeRemaining = bufferSize;
	}

	return p;
}

unsigned char *try_serialise_byteArray( unsigned char *buffer, unsigned char *in_array, uint32_t numBytes, uint32_t bufferSize, uint32_t *bufferSizeRemaining )
{
	unsigned char *p;
	if (bufferSize >= numBytes)
	{
		memcpy( buffer, in_array, numBytes );
		p = &(buffer[numBytes]);
		*bufferSizeRemaining = bufferSize - numBytes;
	}
	else
	{
		p = NULL;
		*bufferSizeRemaining = bufferSize;
	}

	return p;
}


//----------------
// others


//-----------------------------------------------
// Driverless structures

// Switching endianness - little endian to host
void letoh_DMAP1DATA( DMAP1DATA *in )
{
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	
		(void)in;
		return;
		
	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

		in->SyncCode = (unsigned short)le16toh( in->SyncCode );
		in->BoundaryLines = (unsigned short)le16toh( in->BoundaryLines );
		// Island1Lines and Island2Lines are chars
		in->SpareW = (unsigned short)le16toh( in->SpareW );
	
		int i;
		for ( i = 0; i < 32; ++i )
		{
			in->XNode[i] = letoh_float( in->XNode[i] );
			in->YNode[i] = letoh_float( in->YNode[i] );
		}
		
		return;
		
	#else
	
		#error "Unsupported endianness"
	
	#endif
}

void letoh_DMAP2DATA( DMAP2DATA *in )
{
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	
		(void)in;
		return;
		
	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

		in->ExitPathPoints = (unsigned short)le16toh( in->ExitPathPoints );
		in->EntryPathPoints = (unsigned short)le16toh( in->EntryPathPoints );
		in->ExitPoint = (unsigned short)le16toh( in->ExitPoint );
		in->EntryPoint = (unsigned short)le16toh( in->EntryPoint );
		in->MaxX = letoh_float( in->MaxX );
		in->MinX = letoh_float( in->MinX );
		in->MaxY = letoh_float( in->MaxY );
		in->MinY = letoh_float( in->MinY );
		in->Points = (unsigned long)le32toh( in->Points );
		in->LongInt = (long)le32toh( in->LongInt );
		in->LongFract = letoh_float( in->LongFract );
		in->LatInt = (long)le32toh( in->LatInt );
		in->LatFract = letoh_float( in->LatFract );
		in->XAxisBearing = letoh_float( in->XAxisBearing );
		in->RefHeight = letoh_float( in->RefHeight );
		in->FwdShift = letoh_float( in->FwdShift ); 
		in->WheelBase = letoh_float( in->WheelBase );
		in->AccelDist = letoh_float( in->AccelDist );
		in->VehicleLength = letoh_float( in->VehicleLength );
		in->VehicleWidth = letoh_float( in->VehicleWidth );
		in->FrontOverhang = letoh_float( in->FrontOverhang );
		in->SpeedMultiplier = letoh_float( in->SpeedMultiplier );
		in->KdistCorrection = letoh_float( in->KdistCorrection );
		in->LapTime = (unsigned long)le32toh( in->LapTime );
		in->DistanceStep = letoh_float( in->DistanceStep );
		
		return;
		
	#else
	
		#error "Unsupported endianness"
	
	#endif
}

void letoh_DMAP3DATA( DMAP3DATA *in )
{
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	
		(void)in;		
		return;
		
	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
		in->LeadInAccel = letoh_float( in->LeadInAccel );
		in->LeadInDecel = letoh_float( in->LeadInDecel );
		in->ParallelOffsetRate = letoh_float( in->ParallelOffsetRate );
		in->RefPointX = letoh_float( in->RefPointX );
		in->RefPointY = letoh_float( in->RefPointY );
		//in->DoBoundaryChecking = in->DoBoundaryChecking; // no need to reverse bytes for uchar
		in->ImageMapCollisionCheckCode = (unsigned long)le32toh( in->ImageMapCollisionCheckCode );
		return;
		
	#else
	
		#error "Unsupported endianness"
	
	#endif
}

void letoh_DRESTARTDATA( DRESTARTDATA *in )
{
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
	
		(void)in;		
		return;
		
	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
		
		in->RobotMode = (unsigned short)le16toh( in->RobotMode );
		in->SpareW = (unsigned short)le16toh( in->SpareW );
		in->RestartX = letoh_float( in->RestartX );
		in->RestartY = letoh_float( in->RestartY );
		in->RestartAng = letoh_float( in->RestartAng );
		in->RestartXDist = letoh_float( in->RestartXDist );
		in->SpeedRestartX = letoh_float( in->SpeedRestartX );
		in->SpeedRestartY = letoh_float( in->SpeedRestartY );
		in->SpeedRestartAng = letoh_float( in->SpeedRestartAng );
		in->CoeffA = letoh_float( in->CoeffA );
		in->CoeffB = letoh_float( in->CoeffB );
		in->AccelDistEther = letoh_float( in->AccelDistEther );
		in->SpeedEntryPointTime = letoh_float( in->SpeedEntryPointTime );
		in->LeadInTime = letoh_float( in->LeadInTime );
		in->EntryDist = letoh_float( in->EntryDist );

		return;
		
	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_VEHICLEDATA letoh_VehicleData( _VEHICLEDATA vehDataIn)
{
	// Convert the vehicle data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes
		
		return vehDataIn;

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

		_VEHICLEDATA vehDataOut;

		//Vehicle info
		vehDataOut.pmVehicleStatusX = le16toh(vehDataIn.pmVehicleStatusX);			 //pmVehicleStatusX->X:$060013,0,12  (Daimler concept car stuff)
		vehDataOut.pmVehicleStatusY = le16toh(vehDataIn.pmVehicleStatusY);			 //pmVehicleStatusY->Y:$060013,0,16
		vehDataOut.pmVehicleDisplayType = le16toh(vehDataIn.pmVehicleDisplayType);	 //pmVehicleDisplayType->X:$060013,12,4
		vehDataOut.pmFwdShift = letoh_float(vehDataIn.pmFwdShift);						 //pmFwdShift->F:$06004B
		vehDataOut.pmWheelBase = letoh_float(vehDataIn.pmWheelBase);						 //pmWheelBase->F:$06004C
		vehDataOut.pmVehicleLength = letoh_float(vehDataIn.pmVehicleLength);				 //pmVehicleLength->F:$06004E
		vehDataOut.pmVehicleWidth = letoh_float(vehDataIn.pmVehicleWidth);				 //pmVehicleWidth->F:$06004F
		vehDataOut.pmVehicleFrontOverhang = letoh_float(vehDataIn.pmVehicleFrontOverhang); //pmVehicleFrontOverhang->F:$060050

		return vehDataOut;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_VEHICLEDATA betoh_VehicleData( _VEHICLEDATA vehDataIn)
{
	// Convert the vehicle data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ 

		_VEHICLEDATA vehDataOut;

		//Vehicle info
		vehDataOut.pmVehicleStatusX = be16toh(vehDataIn.pmVehicleStatusX);			 //pmVehicleStatusX->X:$060013,0,12  (Daimler concept car stuff)
		vehDataOut.pmVehicleStatusY = be16toh(vehDataIn.pmVehicleStatusY);			 //pmVehicleStatusY->Y:$060013,0,16
		vehDataOut.pmVehicleDisplayType = be16toh(vehDataIn.pmVehicleDisplayType);	 //pmVehicleDisplayType->X:$060013,12,4
		vehDataOut.pmFwdShift = betoh_float(vehDataIn.pmFwdShift);						 //pmFwdShift->F:$06004B
		vehDataOut.pmWheelBase = betoh_float(vehDataIn.pmWheelBase);						 //pmWheelBase->F:$06004C
		vehDataOut.pmVehicleLength = betoh_float(vehDataIn.pmVehicleLength);				 //pmVehicleLength->F:$06004E
		vehDataOut.pmVehicleWidth = betoh_float(vehDataIn.pmVehicleWidth);				 //pmVehicleWidth->F:$06004F
		vehDataOut.pmVehicleFrontOverhang = betoh_float(vehDataIn.pmVehicleFrontOverhang); //pmVehicleFrontOverhang->F:$060050

		return vehDataOut;

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ // host is big endian, so no need to swap bytes

		return vehDataIn;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_DATUMDATA letoh_DatumData (_DATUMDATA datumIn)
{
	// Convert the datum data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return datumIn;

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

		_DATUMDATA datumOut;

		datumOut.pmLongitudeInt = le32toh(datumIn.pmLongitudeInt);
		datumOut.pmLongitudeFract = letoh_float(datumIn.pmLongitudeFract);
		datumOut.pmLatitudeInt = le32toh(datumIn.pmLatitudeInt);
		datumOut.pmLatitudeFract = letoh_float(datumIn.pmLatitudeFract);
		datumOut.pmXaxisDatumBearing = letoh_float(datumIn.pmXaxisDatumBearing);
		datumOut.pmRefHeight = letoh_float(datumIn.pmRefHeight);

		return datumOut;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_DATUMDATA betoh_DatumData (_DATUMDATA datumIn)
{
	// Convert the datum data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		_DATUMDATA datumOut;

		datumOut.pmLongitudeInt = be32toh(datumIn.pmLongitudeInt);
		datumOut.pmLongitudeFract = betoh_float(datumIn.pmLongitudeFract);
		datumOut.pmLatitudeInt = be32toh(datumIn.pmLatitudeInt);
		datumOut.pmLatitudeFract = betoh_float(datumIn.pmLatitudeFract);
		datumOut.pmXaxisDatumBearing = betoh_float(datumIn.pmXaxisDatumBearing);
		datumOut.pmRefHeight = betoh_float(datumIn.pmRefHeight);

		return datumOut;		

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

		return datumIn;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_DRIVERLESSVALUES letoh_DriverlessValues( _DRIVERLESSVALUES driverlessValuesIn )
{
	// Convert the driverless values structure from little endian format to the host system

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

	return driverlessValuesIn;

#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

	_DRIVERLESSVALUES driverlessValuesOut;

	driverlessValuesOut.pmBrEmergencyDisp = letoh_float( driverlessValuesIn.pmBrEmergencyDisp );
	driverlessValuesOut.pmBrHoldForce = letoh_float( driverlessValuesIn.pmBrHoldForce );
	driverlessValuesOut.pmBrEmergencyForce = letoh_float( driverlessValuesIn.pmBrEmergencyForce );
	driverlessValuesOut.pmBrNormalDecel = letoh_float( driverlessValuesIn.pmBrNormalDecel );
	driverlessValuesOut.pmBrEmergencyDecel = letoh_float( driverlessValuesIn.pmBrEmergencyDecel );
	driverlessValuesOut.pmBaseStationTimeout = le16toh( driverlessValuesIn.pmBaseStationTimeout );

	return driverlessValuesOut;

#else

#error "Unsupported endianness"

#endif
}

_DRIVERLESSVALUES betoh_DriverlessValues( _DRIVERLESSVALUES driverlessValuesIn )
{
	// Convert the driverless values structure from big endian format to the host system

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

	_DRIVERLESSVALUES driverlessValuesOut;

	driverlessValuesOut.pmBrEmergencyDisp = betoh_float( driverlessValuesIn.pmBrEmergencyDisp );
	driverlessValuesOut.pmBrHoldForce = betoh_float( driverlessValuesIn.pmBrHoldForce );
	driverlessValuesOut.pmBrEmergencyForce = betoh_float( driverlessValuesIn.pmBrEmergencyForce );
	driverlessValuesOut.pmBrNormalDecel = betoh_float( driverlessValuesIn.pmBrNormalDecel );
	driverlessValuesOut.pmBrEmergencyDecel = betoh_float( driverlessValuesIn.pmBrEmergencyDecel );
	driverlessValuesOut.pmBaseStationTimeout = be16toh( driverlessValuesIn.pmBaseStationTimeout );

	return driverlessValuesOut;

#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

	return driverlessValuesIn;

#else

#error "Unsupported endianness"

#endif
}

_GROUPDATA_0 letoh_GroupData_0(_GROUPDATA_0 groupIn)
{
	// Convert the group data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return groupIn;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

		_GROUPDATA_0 groupOut;
	
		groupOut.FirstTestOffset = le32toh(groupIn.FirstTestOffset);
		groupOut.FirstDriverlessOffset = le32toh(groupIn.FirstDriverlessOffset);
		groupOut.FirstReturnPathOffset = le32toh(groupIn.FirstReturnPathOffset);
		groupOut.FirstSegmentOffset = le32toh(groupIn.FirstSegmentOffset);
		groupOut.FirstBSplineOffset = le32toh(groupIn.FirstBSplineOffset);
		groupOut.FirstCritSectOffset = le32toh(groupIn.FirstCritSectOffset);
		groupOut.FirstTransitionOffset = le32toh(groupIn.FirstTransitionOffset);
		groupOut.FirstSROffset = le32toh(groupIn.FirstSROffset);
		groupOut.FirstGenOffset = le32toh(groupIn.FirstGenOffset);
		groupOut.FirstBROffset = le32toh(groupIn.FirstBROffset);
		groupOut.FirstAROffset = le32toh(groupIn.FirstAROffset);
		groupOut.nSRUserPoints = le32toh(groupIn.nSRUserPoints);
		groupOut.nBRUserPoints = le32toh(groupIn.nBRUserPoints);
		groupOut.nARUserPoints = le32toh(groupIn.nARUserPoints);
		groupOut.FirstSRUserFIndex = le32toh(groupIn.FirstSRUserFIndex);
		groupOut.FirstBRUserFIndex = le32toh(groupIn.FirstBRUserFIndex);
		groupOut.FirstARUserFIndex = le32toh(groupIn.FirstARUserFIndex);
		groupOut.FirstBRStartCycleTriggerFIndex = le32toh(groupIn.FirstBRStartCycleTriggerFIndex);
		groupOut.FirstARStartCycleTriggerFIndex = le32toh(groupIn.FirstARStartCycleTriggerFIndex);
		groupOut.FirstAREndCycleTriggerFIndex = le32toh(groupIn.FirstAREndCycleTriggerFIndex);
		groupOut.FirstARAmpCycleFIndex = le32toh(groupIn.FirstARAmpCycleFIndex);
		groupOut.FirstARDwellCycleFIndex = le32toh(groupIn.FirstARDwellCycleFIndex);
		groupOut.Type = le16toh(groupIn.Type);
		groupOut.nSubGroups = le16toh(groupIn.nSubGroups);
		groupOut.nReturnPaths = le16toh(groupIn.nReturnPaths);
		groupOut.RunNumber = le16toh(groupIn.RunNumber);
		groupOut.VehicleID = le16toh(groupIn.VehicleID);
		groupOut.DriverlessTrue = le16toh(groupIn.DriverlessTrue);
		groupOut.LongPosRef = le16toh(groupIn.LongPosRef);
		groupOut.nTests = le16toh(groupIn.nTests);
		groupOut.nSegments = le16toh(groupIn.nSegments);
		groupOut.nBSpoints = le16toh(groupIn.nBSpoints);
		groupOut.nCriticalSections = le16toh(groupIn.nCriticalSections);
		groupOut.nTransitions = le16toh(groupIn.nTransitions);
		groupOut.nBRStartCycleTriggers = le16toh(groupIn.nBRStartCycleTriggers);
		groupOut.nARStartCycleTriggers = le16toh(groupIn.nARStartCycleTriggers);
		groupOut.nAREndCycleTriggers = le16toh(groupIn.nAREndCycleTriggers);
		groupOut.nARAmpCycles = le16toh(groupIn.nARAmpCycles);
		groupOut.nARDwellCycles = le16toh(groupIn.nARDwellCycles);
		// don't worry about flipping dummy[3]
	
		return groupOut;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_GROUPDATA_0 betoh_GroupData_0(_GROUPDATA_0 groupIn)
{
	// Convert the group data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_GROUPDATA_0 groupOut;
	
		groupOut.FirstTestOffset = be32toh(groupIn.FirstTestOffset);
		groupOut.FirstDriverlessOffset = be32toh(groupIn.FirstDriverlessOffset);
		groupOut.FirstReturnPathOffset = be32toh(groupIn.FirstReturnPathOffset);
		groupOut.FirstSegmentOffset = be32toh(groupIn.FirstSegmentOffset);
		groupOut.FirstBSplineOffset = be32toh(groupIn.FirstBSplineOffset);
		groupOut.FirstCritSectOffset = be32toh(groupIn.FirstCritSectOffset);
		groupOut.FirstTransitionOffset = be32toh(groupIn.FirstTransitionOffset);
		groupOut.FirstSROffset = be32toh(groupIn.FirstSROffset);
		groupOut.FirstGenOffset = be32toh(groupIn.FirstGenOffset);
		groupOut.FirstBROffset = be32toh(groupIn.FirstBROffset);
		groupOut.FirstAROffset = be32toh(groupIn.FirstAROffset);
		groupOut.nSRUserPoints = be32toh(groupIn.nSRUserPoints);
		groupOut.nBRUserPoints = be32toh(groupIn.nBRUserPoints);
		groupOut.nARUserPoints = be32toh(groupIn.nARUserPoints);
		groupOut.FirstSRUserFIndex = be32toh(groupIn.FirstSRUserFIndex);
		groupOut.FirstBRUserFIndex = be32toh(groupIn.FirstBRUserFIndex);
		groupOut.FirstARUserFIndex = be32toh(groupIn.FirstARUserFIndex);
		groupOut.FirstBRStartCycleTriggerFIndex = be32toh(groupIn.FirstBRStartCycleTriggerFIndex);
		groupOut.FirstARStartCycleTriggerFIndex = be32toh(groupIn.FirstARStartCycleTriggerFIndex);
		groupOut.FirstAREndCycleTriggerFIndex = be32toh(groupIn.FirstAREndCycleTriggerFIndex);
		groupOut.FirstARAmpCycleFIndex = be32toh(groupIn.FirstARAmpCycleFIndex);
		groupOut.FirstARDwellCycleFIndex = be32toh(groupIn.FirstARDwellCycleFIndex);
		groupOut.Type = be16toh(groupIn.Type);
		groupOut.nSubGroups = be16toh(groupIn.nSubGroups);
		groupOut.nReturnPaths = be16toh(groupIn.nReturnPaths);
		groupOut.RunNumber = be16toh(groupIn.RunNumber);
		groupOut.VehicleID = be16toh(groupIn.VehicleID);
		groupOut.DriverlessTrue = be16toh(groupIn.DriverlessTrue);
		groupOut.LongPosRef = be16toh(groupIn.LongPosRef);
		groupOut.nTests = be16toh(groupIn.nTests);
		groupOut.nSegments = be16toh(groupIn.nSegments);
		groupOut.nBSpoints = be16toh(groupIn.nBSpoints);
		groupOut.nCriticalSections = be16toh(groupIn.nCriticalSections);
		groupOut.nTransitions = be16toh(groupIn.nTransitions);
		groupOut.nBRStartCycleTriggers = be16toh(groupIn.nBRStartCycleTriggers);
		groupOut.nARStartCycleTriggers = be16toh(groupIn.nARStartCycleTriggers);
		groupOut.nAREndCycleTriggers = be16toh(groupIn.nAREndCycleTriggers);
		groupOut.nARAmpCycles = be16toh(groupIn.nARAmpCycles);
		groupOut.nARDwellCycles = be16toh(groupIn.nARDwellCycles);
		// don't worry about flipping dummy[3]
	
		return groupOut;		

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ // host is big endian, so no need to swap bytes

		return groupIn;	

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

// Version 2

_GROUPDATA_2 letoh_GroupData_2(_GROUPDATA_2 groupIn)
{
	// Convert the group data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return groupIn;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

		_GROUPDATA_2 groupOut;

		groupOut.StartXoffset = letoh_float(groupIn.StartXoffset);
		groupOut.StartYoffset = letoh_float(groupIn.StartYoffset);
		groupOut.StartHeadingOffset = letoh_float(groupIn.StartHeadingOffset);	
		groupOut.FirstTestOffset = le32toh(groupIn.FirstTestOffset);
		groupOut.FirstDriverlessOffset = le32toh(groupIn.FirstDriverlessOffset);
		groupOut.FirstReturnPathOffset = le32toh(groupIn.FirstReturnPathOffset);
		groupOut.FirstSegmentOffset = le32toh(groupIn.FirstSegmentOffset);
		groupOut.FirstBSplineOffset = le32toh(groupIn.FirstBSplineOffset);
		groupOut.FirstCritSectOffset = le32toh(groupIn.FirstCritSectOffset);
		groupOut.FirstTransitionOffset = le32toh(groupIn.FirstTransitionOffset);
		groupOut.FirstSROffset = le32toh(groupIn.FirstSROffset);
		groupOut.FirstGenOffset = le32toh(groupIn.FirstGenOffset);
		groupOut.FirstBROffset = le32toh(groupIn.FirstBROffset);
		groupOut.FirstAROffset = le32toh(groupIn.FirstAROffset);
		groupOut.nSRUserPoints = le32toh(groupIn.nSRUserPoints);
		groupOut.nBRUserPoints = le32toh(groupIn.nBRUserPoints);
		groupOut.nARUserPoints = le32toh(groupIn.nARUserPoints);
		groupOut.FirstSRUserFIndex = le32toh(groupIn.FirstSRUserFIndex);
		groupOut.FirstBRUserFIndex = le32toh(groupIn.FirstBRUserFIndex);
		groupOut.FirstARUserFIndex = le32toh(groupIn.FirstARUserFIndex);
		groupOut.FirstBRStartCycleTriggerFIndex = le32toh(groupIn.FirstBRStartCycleTriggerFIndex);
		groupOut.FirstARStartCycleTriggerFIndex = le32toh(groupIn.FirstARStartCycleTriggerFIndex);
		groupOut.FirstAREndCycleTriggerFIndex = le32toh(groupIn.FirstAREndCycleTriggerFIndex);
		groupOut.FirstARAmpCycleFIndex = le32toh(groupIn.FirstARAmpCycleFIndex);
		groupOut.FirstARDwellCycleFIndex = le32toh(groupIn.FirstARDwellCycleFIndex);
		groupOut.Type = le16toh(groupIn.Type);
		groupOut.nSubGroups = le16toh(groupIn.nSubGroups);
		groupOut.nReturnPaths = le16toh(groupIn.nReturnPaths);
		groupOut.RunNumber = le16toh(groupIn.RunNumber);
		groupOut.VehicleID = le16toh(groupIn.VehicleID);
		groupOut.DriverlessTrue = le16toh(groupIn.DriverlessTrue);
		groupOut.LongPosRef = le16toh(groupIn.LongPosRef);
		groupOut.nTests = le16toh(groupIn.nTests);
		groupOut.nSegments = le16toh(groupIn.nSegments);
		groupOut.nBSpoints = le16toh(groupIn.nBSpoints);
		groupOut.nCriticalSections = le16toh(groupIn.nCriticalSections);
		groupOut.nTransitions = le16toh(groupIn.nTransitions);
		groupOut.nBRStartCycleTriggers = le16toh(groupIn.nBRStartCycleTriggers);
		groupOut.nARStartCycleTriggers = le16toh(groupIn.nARStartCycleTriggers);
		groupOut.nAREndCycleTriggers = le16toh(groupIn.nAREndCycleTriggers);
		groupOut.nARAmpCycles = le16toh(groupIn.nARAmpCycles);
		groupOut.nARDwellCycles = le16toh(groupIn.nARDwellCycles);
		// don't worry about flipping dummy[1]
	
		return groupOut;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_GROUPDATA_2 betoh_GroupData_2(_GROUPDATA_2 groupIn)
{
	// Convert the group data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_GROUPDATA_2 groupOut;
	
		groupOut.StartXoffset = betoh_float(groupIn.StartXoffset);
		groupOut.StartYoffset = betoh_float(groupIn.StartYoffset);
		groupOut.StartHeadingOffset = betoh_float(groupIn.StartHeadingOffset);
		groupOut.FirstTestOffset = be32toh(groupIn.FirstTestOffset);
		groupOut.FirstDriverlessOffset = be32toh(groupIn.FirstDriverlessOffset);
		groupOut.FirstReturnPathOffset = be32toh(groupIn.FirstReturnPathOffset);
		groupOut.FirstSegmentOffset = be32toh(groupIn.FirstSegmentOffset);
		groupOut.FirstBSplineOffset = be32toh(groupIn.FirstBSplineOffset);
		groupOut.FirstCritSectOffset = be32toh(groupIn.FirstCritSectOffset);
		groupOut.FirstTransitionOffset = be32toh(groupIn.FirstTransitionOffset);
		groupOut.FirstSROffset = be32toh(groupIn.FirstSROffset);
		groupOut.FirstGenOffset = be32toh(groupIn.FirstGenOffset);
		groupOut.FirstBROffset = be32toh(groupIn.FirstBROffset);
		groupOut.FirstAROffset = be32toh(groupIn.FirstAROffset);
		groupOut.nSRUserPoints = be32toh(groupIn.nSRUserPoints);
		groupOut.nBRUserPoints = be32toh(groupIn.nBRUserPoints);
		groupOut.nARUserPoints = be32toh(groupIn.nARUserPoints);
		groupOut.FirstSRUserFIndex = be32toh(groupIn.FirstSRUserFIndex);
		groupOut.FirstBRUserFIndex = be32toh(groupIn.FirstBRUserFIndex);
		groupOut.FirstARUserFIndex = be32toh(groupIn.FirstARUserFIndex);
		groupOut.FirstBRStartCycleTriggerFIndex = be32toh(groupIn.FirstBRStartCycleTriggerFIndex);
		groupOut.FirstARStartCycleTriggerFIndex = be32toh(groupIn.FirstARStartCycleTriggerFIndex);
		groupOut.FirstAREndCycleTriggerFIndex = be32toh(groupIn.FirstAREndCycleTriggerFIndex);
		groupOut.FirstARAmpCycleFIndex = be32toh(groupIn.FirstARAmpCycleFIndex);
		groupOut.FirstARDwellCycleFIndex = be32toh(groupIn.FirstARDwellCycleFIndex);
		groupOut.Type = be16toh(groupIn.Type);
		groupOut.nSubGroups = be16toh(groupIn.nSubGroups);
		groupOut.nReturnPaths = be16toh(groupIn.nReturnPaths);
		groupOut.RunNumber = be16toh(groupIn.RunNumber);
		groupOut.VehicleID = be16toh(groupIn.VehicleID);
		groupOut.DriverlessTrue = be16toh(groupIn.DriverlessTrue);
		groupOut.LongPosRef = be16toh(groupIn.LongPosRef);
		groupOut.nTests = be16toh(groupIn.nTests);
		groupOut.nSegments = be16toh(groupIn.nSegments);
		groupOut.nBSpoints = be16toh(groupIn.nBSpoints);
		groupOut.nCriticalSections = be16toh(groupIn.nCriticalSections);
		groupOut.nTransitions = be16toh(groupIn.nTransitions);
		groupOut.nBRStartCycleTriggers = be16toh(groupIn.nBRStartCycleTriggers);
		groupOut.nARStartCycleTriggers = be16toh(groupIn.nARStartCycleTriggers);
		groupOut.nAREndCycleTriggers = be16toh(groupIn.nAREndCycleTriggers);
		groupOut.nARAmpCycles = be16toh(groupIn.nARAmpCycles);
		groupOut.nARDwellCycles = be16toh(groupIn.nARDwellCycles);
		// don't worry about flipping dummy[1]
	
		return groupOut;		

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ // host is big endian, so no need to swap bytes

		return groupIn;	

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_GROUPDATA_4 letoh_GroupData_4(_GROUPDATA_4 groupIn)
{
	// Convert the group data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return groupIn;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

		_GROUPDATA_4 groupOut;
		groupOut.GroupShiftX = letoh_float(groupIn.GroupShiftX);
		groupOut.GroupShiftY = letoh_float(groupIn.GroupShiftY);
		groupOut.GroupRotCos = letoh_float(groupIn.GroupRotCos);
		groupOut.GroupRotSin = letoh_float(groupIn.GroupRotSin);
		groupOut.StartXoffset = letoh_float(groupIn.StartXoffset);
		groupOut.StartYoffset = letoh_float(groupIn.StartYoffset);
		groupOut.StartHeadingOffset = letoh_float(groupIn.StartHeadingOffset);	
		groupOut.HighwayMaxLateralOffsetLeft = letoh_float(groupIn.HighwayMaxLateralOffsetLeft);
		groupOut.HighwayMaxLateralOffsetRight = letoh_float(groupIn.HighwayMaxLateralOffsetRight);
		groupOut.FirstTestOffset = le32toh(groupIn.FirstTestOffset);
		groupOut.FirstDriverlessOffset = le32toh(groupIn.FirstDriverlessOffset);
		groupOut.FirstReturnPathOffset = le32toh(groupIn.FirstReturnPathOffset);
		groupOut.FirstSegmentOffset = le32toh(groupIn.FirstSegmentOffset);
		groupOut.FirstBSplineOffset = le32toh(groupIn.FirstBSplineOffset);
		groupOut.FirstCritSectOffset = le32toh(groupIn.FirstCritSectOffset);
		groupOut.FirstTransitionOffset = le32toh(groupIn.FirstTransitionOffset);
		groupOut.FirstSROffset = le32toh(groupIn.FirstSROffset);
		groupOut.FirstGenOffset = le32toh(groupIn.FirstGenOffset);
		groupOut.FirstBROffset = le32toh(groupIn.FirstBROffset);
		groupOut.FirstAROffset = le32toh(groupIn.FirstAROffset);
		groupOut.nSRUserPoints = le32toh(groupIn.nSRUserPoints);
		groupOut.nBRUserPoints = le32toh(groupIn.nBRUserPoints);
		groupOut.nARUserPoints = le32toh(groupIn.nARUserPoints);
		groupOut.FirstSRUserFIndex = le32toh(groupIn.FirstSRUserFIndex);
		groupOut.FirstBRUserFIndex = le32toh(groupIn.FirstBRUserFIndex);
		groupOut.FirstARUserFIndex = le32toh(groupIn.FirstARUserFIndex);
		groupOut.FirstBRStartCycleTriggerFIndex = le32toh(groupIn.FirstBRStartCycleTriggerFIndex);
		groupOut.FirstARStartCycleTriggerFIndex = le32toh(groupIn.FirstARStartCycleTriggerFIndex);
		groupOut.FirstAREndCycleTriggerFIndex = le32toh(groupIn.FirstAREndCycleTriggerFIndex);
		groupOut.FirstARAmpCycleFIndex = le32toh(groupIn.FirstARAmpCycleFIndex);
		groupOut.FirstARDwellCycleFIndex = le32toh(groupIn.FirstARDwellCycleFIndex);
		groupOut.Type = le16toh(groupIn.Type);
		groupOut.nSubGroups = le16toh(groupIn.nSubGroups);
		groupOut.nReturnPaths = le16toh(groupIn.nReturnPaths);
		groupOut.RunNumber = le16toh(groupIn.RunNumber);
		groupOut.VehicleID = le16toh(groupIn.VehicleID);
		groupOut.DriverlessTrue = le16toh(groupIn.DriverlessTrue);
		groupOut.LongPosRef = le16toh(groupIn.LongPosRef);
		groupOut.nTests = le16toh(groupIn.nTests);
		groupOut.nSegments = le16toh(groupIn.nSegments);
		groupOut.nBSpoints = le16toh(groupIn.nBSpoints);
		groupOut.nCriticalSections = le16toh(groupIn.nCriticalSections);
		groupOut.nTransitions = le16toh(groupIn.nTransitions);
		groupOut.nBRStartCycleTriggers = le16toh(groupIn.nBRStartCycleTriggers);
		groupOut.nARStartCycleTriggers = le16toh(groupIn.nARStartCycleTriggers);
		groupOut.nAREndCycleTriggers = le16toh(groupIn.nAREndCycleTriggers);
		groupOut.nARAmpCycles = le16toh(groupIn.nARAmpCycles);
		groupOut.nARDwellCycles = le16toh(groupIn.nARDwellCycles);
		groupOut.InitialSrProgram = le16toh(groupIn.InitialSrProgram);
		groupOut.InitialBrProgram = le16toh(groupIn.InitialBrProgram);
		groupOut.InitialArProgram = le16toh(groupIn.InitialArProgram);
		groupOut.UseHighwayScenario = groupIn.UseHighwayScenario;
		// don't worry about flipping dummy[1]
	
		return groupOut;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_GROUPDATA_4 betoh_GroupData_4(_GROUPDATA_4 groupIn)
{
	// Convert the group data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_GROUPDATA_4 groupOut;
		groupOut.GroupShiftX = betoh_float(groupIn.GroupShiftX);
		groupOut.GroupShiftY = betoh_float(groupIn.GroupShiftY);
		groupOut.GroupRotCos = betoh_float(groupIn.GroupRotCos);
		groupOut.GroupRotSin = betoh_float(groupIn.GroupRotSin);
		groupOut.StartXoffset = betoh_float(groupIn.StartXoffset);
		groupOut.StartYoffset = betoh_float(groupIn.StartYoffset);
		groupOut.StartHeadingOffset = betoh_float(groupIn.StartHeadingOffset);
		groupOut.HighwayMaxLateralOffsetLeft = betoh_float(groupIn.HighwayMaxLateralOffsetLeft);
		groupOut.HighwayMaxLateralOffsetRight = betoh_float(groupIn.HighwayMaxLateralOffsetRight);
		groupOut.FirstTestOffset = be32toh(groupIn.FirstTestOffset);
		groupOut.FirstDriverlessOffset = be32toh(groupIn.FirstDriverlessOffset);
		groupOut.FirstReturnPathOffset = be32toh(groupIn.FirstReturnPathOffset);
		groupOut.FirstSegmentOffset = be32toh(groupIn.FirstSegmentOffset);
		groupOut.FirstBSplineOffset = be32toh(groupIn.FirstBSplineOffset);
		groupOut.FirstCritSectOffset = be32toh(groupIn.FirstCritSectOffset);
		groupOut.FirstTransitionOffset = be32toh(groupIn.FirstTransitionOffset);
		groupOut.FirstSROffset = be32toh(groupIn.FirstSROffset);
		groupOut.FirstGenOffset = be32toh(groupIn.FirstGenOffset);
		groupOut.FirstBROffset = be32toh(groupIn.FirstBROffset);
		groupOut.FirstAROffset = be32toh(groupIn.FirstAROffset);
		groupOut.nSRUserPoints = be32toh(groupIn.nSRUserPoints);
		groupOut.nBRUserPoints = be32toh(groupIn.nBRUserPoints);
		groupOut.nARUserPoints = be32toh(groupIn.nARUserPoints);
		groupOut.FirstSRUserFIndex = be32toh(groupIn.FirstSRUserFIndex);
		groupOut.FirstBRUserFIndex = be32toh(groupIn.FirstBRUserFIndex);
		groupOut.FirstARUserFIndex = be32toh(groupIn.FirstARUserFIndex);
		groupOut.FirstBRStartCycleTriggerFIndex = be32toh(groupIn.FirstBRStartCycleTriggerFIndex);
		groupOut.FirstARStartCycleTriggerFIndex = be32toh(groupIn.FirstARStartCycleTriggerFIndex);
		groupOut.FirstAREndCycleTriggerFIndex = be32toh(groupIn.FirstAREndCycleTriggerFIndex);
		groupOut.FirstARAmpCycleFIndex = be32toh(groupIn.FirstARAmpCycleFIndex);
		groupOut.FirstARDwellCycleFIndex = be32toh(groupIn.FirstARDwellCycleFIndex);
		groupOut.Type = be16toh(groupIn.Type);
		groupOut.nSubGroups = be16toh(groupIn.nSubGroups);
		groupOut.nReturnPaths = be16toh(groupIn.nReturnPaths);
		groupOut.RunNumber = be16toh(groupIn.RunNumber);
		groupOut.VehicleID = be16toh(groupIn.VehicleID);
		groupOut.DriverlessTrue = be16toh(groupIn.DriverlessTrue);
		groupOut.LongPosRef = be16toh(groupIn.LongPosRef);
		groupOut.nTests = be16toh(groupIn.nTests);
		groupOut.nSegments = be16toh(groupIn.nSegments);
		groupOut.nBSpoints = be16toh(groupIn.nBSpoints);
		groupOut.nCriticalSections = be16toh(groupIn.nCriticalSections);
		groupOut.nTransitions = be16toh(groupIn.nTransitions);
		groupOut.nBRStartCycleTriggers = be16toh(groupIn.nBRStartCycleTriggers);
		groupOut.nARStartCycleTriggers = be16toh(groupIn.nARStartCycleTriggers);
		groupOut.nAREndCycleTriggers = be16toh(groupIn.nAREndCycleTriggers);
		groupOut.nARAmpCycles = be16toh(groupIn.nARAmpCycles);
		groupOut.nARDwellCycles = be16toh(groupIn.nARDwellCycles);
		groupOut.InitialSrProgram = be16toh(groupIn.InitialSrProgram);
		groupOut.InitialBrProgram = be16toh(groupIn.InitialBrProgram);
		groupOut.InitialArProgram = be16toh(groupIn.InitialArProgram);
		groupOut.UseHighwayScenario = groupIn.UseHighwayScenario;
		// don't worry about flipping dummy[1]
	
		return groupOut;		

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ // host is big endian, so no need to swap bytes

		return groupIn;	

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

// Version 0
_SUBGROUPDATA_0 letoh_SubGroupData_0(_SUBGROUPDATA_0 subgroupIn)
{
	// Convert the subgroup data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return subgroupIn;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

		_SUBGROUPDATA_0 subgroupOut;

		subgroupOut.TransitTime = letoh_float(subgroupIn.TransitTime);
		subgroupOut.MaxSWA = letoh_float(subgroupIn.MaxSWA);
		subgroupOut.MaxSWV = letoh_float(subgroupIn.MaxSWV);
		subgroupOut.MaxSWAcc = letoh_float(subgroupIn.MaxSWAcc);
		subgroupOut.MaxLateralError = letoh_float(subgroupIn.MaxLateralError);
		subgroupOut.MaxLongitudinalError = letoh_float(subgroupIn.MaxLongitudinalError);
		subgroupOut.Type = le16toh(subgroupIn.Type);
		subgroupOut.nTests = le16toh(subgroupIn.nTests);
		subgroupOut.FirstTestIndex = le16toh(subgroupIn.FirstTestIndex);
		subgroupOut.nReturnPaths = le16toh(subgroupIn.nReturnPaths);

		return subgroupOut;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

// Version 0
_SUBGROUPDATA_0 betoh_SubGroupData_0(_SUBGROUPDATA_0 subgroupIn)
{
	// Convert the subgroup data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_SUBGROUPDATA_0 subgroupOut;

		subgroupOut.TransitTime = betoh_float(subgroupIn.TransitTime);
		subgroupOut.MaxSWA = betoh_float(subgroupIn.MaxSWA);
		subgroupOut.MaxSWV = betoh_float(subgroupIn.MaxSWV);
		subgroupOut.MaxSWAcc = betoh_float(subgroupIn.MaxSWAcc);
		subgroupOut.MaxLateralError = betoh_float(subgroupIn.MaxLateralError);
		subgroupOut.MaxLongitudinalError = betoh_float(subgroupIn.MaxLongitudinalError);
		subgroupOut.Type = be16toh(subgroupIn.Type);
		subgroupOut.nTests = be16toh(subgroupIn.nTests);
		subgroupOut.FirstTestIndex = be16toh(subgroupIn.FirstTestIndex);
		subgroupOut.nReturnPaths = be16toh(subgroupIn.nReturnPaths);

		return subgroupOut;		

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ // host is big endian, so no need to swap bytes

		return subgroupIn;	

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

// Version 1
_SUBGROUPDATA_1 letoh_SubGroupData_1(_SUBGROUPDATA_1 subgroupIn)
{
	// Convert the subgroup data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return subgroupIn;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

		_SUBGROUPDATA_1 subgroupOut;

		subgroupOut.TransitTime = letoh_float(subgroupIn.TransitTime);
		subgroupOut.MaxSWA = letoh_float(subgroupIn.MaxSWA);
		subgroupOut.MaxSWV = letoh_float(subgroupIn.MaxSWV);
		subgroupOut.MaxSWAcc = letoh_float(subgroupIn.MaxSWAcc);
		subgroupOut.MaxLateralError = letoh_float(subgroupIn.MaxLateralError);
		subgroupOut.MaxLongitudinalError = letoh_float(subgroupIn.MaxLongitudinalError);
		subgroupOut.Type = le16toh(subgroupIn.Type);
		subgroupOut.nTests = le16toh(subgroupIn.nTests);
		subgroupOut.FirstTestIndex = le16toh(subgroupIn.FirstTestIndex);
		subgroupOut.nReturnPaths = le16toh(subgroupIn.nReturnPaths);
		subgroupOut.TotalCircuitsComplete = le16toh(subgroupIn.TotalCircuitsComplete);

		return subgroupOut;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

// Version 1
_SUBGROUPDATA_1 betoh_SubGroupData_1(_SUBGROUPDATA_1 subgroupIn)
{
	// Convert the subgroup data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_SUBGROUPDATA_1 subgroupOut;

		subgroupOut.TransitTime = betoh_float(subgroupIn.TransitTime);
		subgroupOut.MaxSWA = betoh_float(subgroupIn.MaxSWA);
		subgroupOut.MaxSWV = betoh_float(subgroupIn.MaxSWV);
		subgroupOut.MaxSWAcc = betoh_float(subgroupIn.MaxSWAcc);
		subgroupOut.MaxLateralError = betoh_float(subgroupIn.MaxLateralError);
		subgroupOut.MaxLongitudinalError = betoh_float(subgroupIn.MaxLongitudinalError);
		subgroupOut.Type = be16toh(subgroupIn.Type);
		subgroupOut.nTests = be16toh(subgroupIn.nTests);
		subgroupOut.FirstTestIndex = be16toh(subgroupIn.FirstTestIndex);
		subgroupOut.nReturnPaths = be16toh(subgroupIn.nReturnPaths);
		subgroupOut.TotalCircuitsComplete = be16toh(subgroupIn.TotalCircuitsComplete);

		return subgroupOut;		

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ // host is big endian, so no need to swap bytes

		return subgroupIn;	

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

// Version 2
_SUBGROUPDATA_2 letoh_SubGroupData_2(_SUBGROUPDATA_2 subgroupIn)
{
	// Convert the subgroup data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return subgroupIn;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

		_SUBGROUPDATA_2 subgroupOut;

		subgroupOut.pathRelativeOffsetX = letoh_double(subgroupIn.pathRelativeOffsetX);
		subgroupOut.pathRelativeOffsetY = letoh_double(subgroupIn.pathRelativeOffsetY);
		subgroupOut.pathRelativeSin = letoh_float(subgroupIn.pathRelativeSin);
		subgroupOut.pathRelativeCos = letoh_float(subgroupIn.pathRelativeCos);
		subgroupOut.TransitTime = letoh_float(subgroupIn.TransitTime);
		subgroupOut.MaxSWA = letoh_float(subgroupIn.MaxSWA);
		subgroupOut.MaxSWV = letoh_float(subgroupIn.MaxSWV);
		subgroupOut.MaxSWAcc = letoh_float(subgroupIn.MaxSWAcc);
		subgroupOut.MaxLateralError = letoh_float(subgroupIn.MaxLateralError);
		subgroupOut.MaxLongitudinalError = letoh_float(subgroupIn.MaxLongitudinalError);
		subgroupOut.Type = le16toh(subgroupIn.Type);
		subgroupOut.nTests = le16toh(subgroupIn.nTests);
		subgroupOut.FirstTestIndex = le16toh(subgroupIn.FirstTestIndex);
		subgroupOut.nReturnPaths = le16toh(subgroupIn.nReturnPaths);
		subgroupOut.TotalCircuitsComplete = le16toh(subgroupIn.TotalCircuitsComplete);

		return subgroupOut;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

// Version 2
_SUBGROUPDATA_2 betoh_SubGroupData_2(_SUBGROUPDATA_2 subgroupIn)
{
	// Convert the subgroup data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_SUBGROUPDATA_2 subgroupOut;

		subgroupOut.pathRelativeOffsetX = betoh_double(subgroupIn.pathRelativeOffsetX);
		subgroupOut.pathRelativeOffsetY = betoh_double(subgroupIn.pathRelativeOffsetY);
		subgroupOut.pathRelativeSin = betoh_float(subgroupIn.pathRelativeSin);
		subgroupOut.pathRelativeCos = betoh_float(subgroupIn.pathRelativeCos);
		subgroupOut.TransitTime = betoh_float(subgroupIn.TransitTime);
		subgroupOut.MaxSWA = betoh_float(subgroupIn.MaxSWA);
		subgroupOut.MaxSWV = betoh_float(subgroupIn.MaxSWV);
		subgroupOut.MaxSWAcc = betoh_float(subgroupIn.MaxSWAcc);
		subgroupOut.MaxLateralError = betoh_float(subgroupIn.MaxLateralError);
		subgroupOut.MaxLongitudinalError = betoh_float(subgroupIn.MaxLongitudinalError);
		subgroupOut.Type = be16toh(subgroupIn.Type);
		subgroupOut.nTests = be16toh(subgroupIn.nTests);
		subgroupOut.FirstTestIndex = be16toh(subgroupIn.FirstTestIndex);
		subgroupOut.nReturnPaths = be16toh(subgroupIn.nReturnPaths);
		subgroupOut.TotalCircuitsComplete = be16toh(subgroupIn.TotalCircuitsComplete);

		return subgroupOut;		

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__ // host is big endian, so no need to swap bytes

		return subgroupIn;	

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

// Version 0
_TESTDATA_0 letoh_TestData_0(_TESTDATA_0 testIn)
{
	// Convert the test data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return testIn;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

		_TESTDATA_0 testOut;
	
		testOut.StartTriggerVal = letoh_double(testIn.StartTriggerVal);
		testOut.StartTimeOffset = letoh_double(testIn.StartTimeOffset);
		testOut.InitialTransitionLocation = letoh_double(testIn.InitialTransitionLocation);
		testOut.PathExitTriggerVal = letoh_double(testIn.PathExitTriggerVal);
		testOut.TriggeredExitLocation = letoh_double(testIn.TriggeredExitLocation);
		testOut.TriggeredExitTime = letoh_double(testIn.TriggeredExitTime);
		testOut.PathAbortTriggerVal = letoh_double(testIn.PathAbortTriggerVal);
		testOut.InitialDist = letoh_double(testIn.InitialDist);
		testOut.Length = letoh_double(testIn.Length);
		testOut.TransitTime = letoh_double(testIn.TransitTime);
		testOut.TestID = le16toh(testIn.TestID);
		testOut.Type = le16toh(testIn.Type);
		testOut.SyncCode = le16toh(testIn.SyncCode);
		testOut.nSegments = le16toh(testIn.nSegments);
		testOut.nCriticalSections = le16toh(testIn.nCriticalSections);
		testOut.Layer = le16toh(testIn.Layer);
		testOut.StartTriggerChan = le16toh(testIn.StartTriggerChan);
		testOut.PathExitTriggerChan = le16toh(testIn.PathExitTriggerChan);
		testOut.PathAbortTriggerChan = le16toh(testIn.PathAbortTriggerChan);
		testOut.SRtestProg = le16toh(testIn.SRtestProg);
		testOut.BRtestProg = le16toh(testIn.BRtestProg);
		testOut.ARtestProg = le16toh(testIn.ARtestProg);
		testOut.NormalExitIndex = le16toh(testIn.NormalExitIndex);
		testOut.TriggeredExitIndex = le16toh(testIn.TriggeredExitIndex);
		testOut.FirstSegmentIndex = le16toh(testIn.FirstSegmentIndex);
		testOut.FirstCritSectIndex = le16toh(testIn.FirstCritSectIndex);
		testOut.SRTestIndex = le16toh(testIn.SRTestIndex);
		testOut.BRTestIndex = le16toh(testIn.BRTestIndex);
		testOut.ARTestIndex = le16toh(testIn.ARTestIndex);
		testOut.GenTestIndex = le16toh(testIn.GenTestIndex);
		testOut.NoTTTrigReset = le16toh(testIn.NoTTTrigReset);
		testOut.DataCaptureFreq = le16toh(testIn.DataCaptureFreq);
		testOut.FinalLapNum = le16toh(testIn.FinalLapNum);
		testOut.dummy3 = le16toh(testIn.dummy3);
		testOut.BRProgFromLastTest = le16toh(testIn.BRProgFromLastTest);
		testOut.BRInhibitStart = le16toh(testIn.BRInhibitStart);
		testOut.BRInhibitEnd = le16toh(testIn.BRInhibitEnd);
		testOut.ARProgFromLastTest = le16toh(testIn.ARProgFromLastTest);
		testOut.ARInhibitStart = le16toh(testIn.ARInhibitStart);
		testOut.ARInhibitEnd = le16toh(testIn.ARInhibitEnd);
		testOut.ARInhibitSCAbort = le16toh(testIn.ARInhibitSCAbort);
		//char ExitTrigTrue; chars are one byte so no need to swap byte order
		//char DBSexitTrigTrue;

		return testOut;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

// Version 0
_TESTDATA_0 betoh_TestData_0(_TESTDATA_0 testIn)
{
	// Convert the test data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_TESTDATA_0 testOut;
	
		testOut.StartTriggerVal = betoh_double(testIn.StartTriggerVal);
		testOut.StartTimeOffset = betoh_double(testIn.StartTimeOffset);
		testOut.InitialTransitionLocation = betoh_double(testIn.InitialTransitionLocation);
		testOut.PathExitTriggerVal = betoh_double(testIn.PathExitTriggerVal);
		testOut.TriggeredExitLocation = betoh_double(testIn.TriggeredExitLocation);
		testOut.TriggeredExitTime = betoh_double(testIn.TriggeredExitTime);
		testOut.PathAbortTriggerVal = betoh_double(testIn.PathAbortTriggerVal);
		testOut.InitialDist = betoh_double(testIn.InitialDist);
		testOut.Length = betoh_double(testIn.Length);
		testOut.TransitTime = betoh_double(testIn.TransitTime);
		testOut.TestID = be16toh(testIn.TestID);
		testOut.Type = be16toh(testIn.Type);
		testOut.SyncCode = be16toh(testIn.SyncCode);
		testOut.nSegments = be16toh(testIn.nSegments);
		testOut.nCriticalSections = be16toh(testIn.nCriticalSections);
		testOut.Layer = be16toh(testIn.Layer);
		testOut.StartTriggerChan = be16toh(testIn.StartTriggerChan);
		testOut.PathExitTriggerChan = be16toh(testIn.PathExitTriggerChan);
		testOut.PathAbortTriggerChan = be16toh(testIn.PathAbortTriggerChan);
		testOut.SRtestProg = be16toh(testIn.SRtestProg);
		testOut.BRtestProg = be16toh(testIn.BRtestProg);
		testOut.ARtestProg = be16toh(testIn.ARtestProg);
		testOut.NormalExitIndex = be16toh(testIn.NormalExitIndex);
		testOut.TriggeredExitIndex = be16toh(testIn.TriggeredExitIndex);
		testOut.FirstSegmentIndex = be16toh(testIn.FirstSegmentIndex);
		testOut.FirstCritSectIndex = be16toh(testIn.FirstCritSectIndex);
		testOut.SRTestIndex = be16toh(testIn.SRTestIndex);
		testOut.BRTestIndex = be16toh(testIn.BRTestIndex);
		testOut.ARTestIndex = be16toh(testIn.ARTestIndex);
		testOut.GenTestIndex = be16toh(testIn.GenTestIndex);
		testOut.NoTTTrigReset = be16toh(testIn.NoTTTrigReset);
		testOut.DataCaptureFreq = be16toh(testIn.DataCaptureFreq);
		testOut.FinalLapNum = be16toh(testIn.FinalLapNum);
		testOut.dummy3 = be16toh(testIn.dummy3);
		testOut.BRProgFromLastTest = be16toh(testIn.BRProgFromLastTest);
		testOut.BRInhibitStart = be16toh(testIn.BRInhibitStart);
		testOut.BRInhibitEnd = be16toh(testIn.BRInhibitEnd);
		testOut.ARProgFromLastTest = be16toh(testIn.ARProgFromLastTest);
		testOut.ARInhibitStart = be16toh(testIn.ARInhibitStart);
		testOut.ARInhibitEnd = be16toh(testIn.ARInhibitEnd);
		testOut.ARInhibitSCAbort = be16toh(testIn.ARInhibitSCAbort);
		//char ExitTrigTrue; chars are one byte so no need to swap byte order
		//char DBSexitTrigTrue;

		return testOut;			

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  // host is big endian, so no need to swap bytes

		return testIn;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

// Version 1
_TESTDATA_1 letoh_TestData_1(_TESTDATA_1 testIn)
{
	// Convert the test data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return testIn;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

		_TESTDATA_1 testOut;
	
		testOut.StartTriggerVal = letoh_double(testIn.StartTriggerVal);
		testOut.StartTimeOffset = letoh_double(testIn.StartTimeOffset);
		testOut.InitialTransitionLocation = letoh_double(testIn.InitialTransitionLocation);
		testOut.PathExitTriggerVal = letoh_double(testIn.PathExitTriggerVal);
		testOut.TriggeredExitLocation = letoh_double(testIn.TriggeredExitLocation);
		testOut.TriggeredExitTime = letoh_double(testIn.TriggeredExitTime);
		testOut.PathAbortTriggerVal = letoh_double(testIn.PathAbortTriggerVal);
		testOut.InitialDist = letoh_double(testIn.InitialDist);
		testOut.Length = letoh_double(testIn.Length);
		testOut.TransitTime = letoh_double(testIn.TransitTime);
		testOut.TestID = le16toh(testIn.TestID);
		testOut.Type = le16toh(testIn.Type);
		testOut.SyncCode = le16toh(testIn.SyncCode);
		testOut.nSegments = le16toh(testIn.nSegments);
		testOut.nCriticalSections = le16toh(testIn.nCriticalSections);
		testOut.Layer = le16toh(testIn.Layer);
		testOut.StartTriggerChan = le16toh(testIn.StartTriggerChan);
		testOut.PathExitTriggerChan = le16toh(testIn.PathExitTriggerChan);
		testOut.PathAbortTriggerChan = le16toh(testIn.PathAbortTriggerChan);
		testOut.SRtestProg = le16toh(testIn.SRtestProg);
		testOut.BRtestProg = le16toh(testIn.BRtestProg);
		testOut.ARtestProg = le16toh(testIn.ARtestProg);
		testOut.NormalExitIndex = le16toh(testIn.NormalExitIndex);
		testOut.TriggeredExitIndex = le16toh(testIn.TriggeredExitIndex);
		testOut.FirstSegmentIndex = le16toh(testIn.FirstSegmentIndex);
		testOut.FirstCritSectIndex = le16toh(testIn.FirstCritSectIndex);
		testOut.SRTestIndex = le16toh(testIn.SRTestIndex);
		testOut.BRTestIndex = le16toh(testIn.BRTestIndex);
		testOut.ARTestIndex = le16toh(testIn.ARTestIndex);
		testOut.GenTestIndex = le16toh(testIn.GenTestIndex);
		testOut.NoTTTrigReset = le16toh(testIn.NoTTTrigReset);
		testOut.DataCaptureFreq = le16toh(testIn.DataCaptureFreq);
		testOut.BRProgFromLastTest = le16toh(testIn.BRProgFromLastTest);
		testOut.BRInhibitStart = le16toh(testIn.BRInhibitStart);
		testOut.BRInhibitEnd = le16toh(testIn.BRInhibitEnd);
		testOut.ARProgFromLastTest = le16toh(testIn.ARProgFromLastTest);
		testOut.ARInhibitStart = le16toh(testIn.ARInhibitStart);
		testOut.ARInhibitEnd = le16toh(testIn.ARInhibitEnd);
		testOut.ARInhibitSCAbort = le16toh(testIn.ARInhibitSCAbort);
		testOut.FinalLapsRemaining = le16toh(testIn.FinalLapsRemaining);
		testOut.TotalPassesComplete = le16toh(testIn.TotalPassesComplete);
		//char ExitTrigTrue; chars are one byte so no need to swap byte order
		//char DBSexitTrigTrue;

		return testOut;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}



// Version 1
_TESTDATA_1 betoh_TestData_1(_TESTDATA_1 testIn)
{
	// Convert the test data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_TESTDATA_1 testOut;
	
		testOut.StartTriggerVal = betoh_double(testIn.StartTriggerVal);
		testOut.StartTimeOffset = betoh_double(testIn.StartTimeOffset);
		testOut.InitialTransitionLocation = betoh_double(testIn.InitialTransitionLocation);
		testOut.PathExitTriggerVal = betoh_double(testIn.PathExitTriggerVal);
		testOut.TriggeredExitLocation = betoh_double(testIn.TriggeredExitLocation);
		testOut.TriggeredExitTime = betoh_double(testIn.TriggeredExitTime);
		testOut.PathAbortTriggerVal = betoh_double(testIn.PathAbortTriggerVal);
		testOut.InitialDist = betoh_double(testIn.InitialDist);
		testOut.Length = betoh_double(testIn.Length);
		testOut.TransitTime = betoh_double(testIn.TransitTime);
		testOut.TestID = be16toh(testIn.TestID);
		testOut.Type = be16toh(testIn.Type);
		testOut.SyncCode = be16toh(testIn.SyncCode);
		testOut.nSegments = be16toh(testIn.nSegments);
		testOut.nCriticalSections = be16toh(testIn.nCriticalSections);
		testOut.Layer = be16toh(testIn.Layer);
		testOut.StartTriggerChan = be16toh(testIn.StartTriggerChan);
		testOut.PathExitTriggerChan = be16toh(testIn.PathExitTriggerChan);
		testOut.PathAbortTriggerChan = be16toh(testIn.PathAbortTriggerChan);
		testOut.SRtestProg = be16toh(testIn.SRtestProg);
		testOut.BRtestProg = be16toh(testIn.BRtestProg);
		testOut.ARtestProg = be16toh(testIn.ARtestProg);
		testOut.NormalExitIndex = be16toh(testIn.NormalExitIndex);
		testOut.TriggeredExitIndex = be16toh(testIn.TriggeredExitIndex);
		testOut.FirstSegmentIndex = be16toh(testIn.FirstSegmentIndex);
		testOut.FirstCritSectIndex = be16toh(testIn.FirstCritSectIndex);
		testOut.SRTestIndex = be16toh(testIn.SRTestIndex);
		testOut.BRTestIndex = be16toh(testIn.BRTestIndex);
		testOut.ARTestIndex = be16toh(testIn.ARTestIndex);
		testOut.GenTestIndex = be16toh(testIn.GenTestIndex);
		testOut.NoTTTrigReset = be16toh(testIn.NoTTTrigReset);
		testOut.DataCaptureFreq = be16toh(testIn.DataCaptureFreq);
		testOut.BRProgFromLastTest = be16toh(testIn.BRProgFromLastTest);
		testOut.BRInhibitStart = be16toh(testIn.BRInhibitStart);
		testOut.BRInhibitEnd = be16toh(testIn.BRInhibitEnd);
		testOut.ARProgFromLastTest = be16toh(testIn.ARProgFromLastTest);
		testOut.ARInhibitStart = be16toh(testIn.ARInhibitStart);
		testOut.ARInhibitEnd = be16toh(testIn.ARInhibitEnd);
		testOut.ARInhibitSCAbort = be16toh(testIn.ARInhibitSCAbort);
		testOut.FinalLapsRemaining = be16toh(testIn.FinalLapsRemaining);
		testOut.TotalPassesComplete = be16toh(testIn.TotalPassesComplete);
		//char ExitTrigTrue; chars are one byte so no need to swap byte order
		//char DBSexitTrigTrue;

		return testOut;			

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  // host is big endian, so no need to swap bytes

		return testIn;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

// Version 2
_TESTDATA_2 letoh_TestData_2(_TESTDATA_2 testIn)
{
	// Convert the test data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return testIn;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

		_TESTDATA_2 testOut;
	
		testOut.StartTriggerVal = letoh_double(testIn.StartTriggerVal);
		testOut.StartTimeOffset = letoh_double(testIn.StartTimeOffset);
		testOut.InitialTransitionLocation = letoh_double(testIn.InitialTransitionLocation);
		testOut.PathExitTriggerVal = letoh_double(testIn.PathExitTriggerVal);
		testOut.TriggeredExitLocation = letoh_double(testIn.TriggeredExitLocation);
		testOut.TriggeredExitTime = letoh_double(testIn.TriggeredExitTime);
		testOut.PathAbortTriggerVal = letoh_double(testIn.PathAbortTriggerVal);
		testOut.InitialDist = letoh_double(testIn.InitialDist);
		testOut.Length = letoh_double(testIn.Length);
		testOut.TransitTime = letoh_double(testIn.TransitTime);
		testOut.FinalXlocation = letoh_double(testIn.FinalXlocation);
		testOut.FinalYlocation = letoh_double(testIn.FinalYlocation);
		testOut.TestID = le16toh(testIn.TestID);
		testOut.Type = le16toh(testIn.Type);
		testOut.SyncCode = le16toh(testIn.SyncCode);
		testOut.nSegments = le16toh(testIn.nSegments);
		testOut.nCriticalSections = le16toh(testIn.nCriticalSections);
		testOut.Layer = le16toh(testIn.Layer);
		testOut.StartTriggerChan = le16toh(testIn.StartTriggerChan);
		testOut.PathExitTriggerChan = le16toh(testIn.PathExitTriggerChan);
		testOut.PathAbortTriggerChan = le16toh(testIn.PathAbortTriggerChan);
		testOut.SRtestProg = le16toh(testIn.SRtestProg);
		testOut.BRtestProg = le16toh(testIn.BRtestProg);
		testOut.ARtestProg = le16toh(testIn.ARtestProg);
		testOut.NormalExitIndex = le16toh(testIn.NormalExitIndex);
		testOut.FirstTriggeredExitIndex = le16toh(testIn.FirstTriggeredExitIndex);
		testOut.nTriggeredExits = le16toh(testIn.nTriggeredExits);
		testOut.FirstSegmentIndex = le16toh(testIn.FirstSegmentIndex);
		testOut.FirstCritSectIndex = le16toh(testIn.FirstCritSectIndex);
		testOut.SRTestIndex = le16toh(testIn.SRTestIndex);
		testOut.BRTestIndex = le16toh(testIn.BRTestIndex);
		testOut.ARTestIndex = le16toh(testIn.ARTestIndex);
		testOut.GenTestIndex = le16toh(testIn.GenTestIndex);
		testOut.DataCaptureFreq = le16toh(testIn.DataCaptureFreq);
		testOut.TotalPassesComplete = le16toh(testIn.TotalPassesComplete);
		testOut.ActualTriggeredExitIndex = le16toh(testIn.ActualTriggeredExitIndex);

		// No need to flip one byte fields
		//int8_t NoTTTrigReset;
		//int8_t BRProgFromLastTest;
		//int8_t BRInhibitStart;
		//int8_t BRInhibitEnd;
		//int8_t ARProgFromLastTest;
		//int8_t ARInhibitStart;
		//int8_t ARInhibitEnd;
		//int8_t ARInhibitSCAbort;
		//int8_t FinalLapsRemaining;
		//uint8_t ExitTrigTrue;
		//char dummyChar[6];

		return testOut;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

// Version 2
_TESTDATA_2 betoh_TestData_2(_TESTDATA_2 testIn)
{
	// Convert the test data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_TESTDATA_2 testOut;
	
		testOut.StartTriggerVal = betoh_double(testIn.StartTriggerVal);
		testOut.StartTimeOffset = betoh_double(testIn.StartTimeOffset);
		testOut.InitialTransitionLocation = betoh_double(testIn.InitialTransitionLocation);
		testOut.PathExitTriggerVal = betoh_double(testIn.PathExitTriggerVal);
		testOut.TriggeredExitLocation = betoh_double(testIn.TriggeredExitLocation);
		testOut.TriggeredExitTime = betoh_double(testIn.TriggeredExitTime);
		testOut.PathAbortTriggerVal = betoh_double(testIn.PathAbortTriggerVal);
		testOut.InitialDist = betoh_double(testIn.InitialDist);
		testOut.Length = betoh_double(testIn.Length);
		testOut.TransitTime = betoh_double(testIn.TransitTime);
		testOut.FinalXlocation = betoh_double(testIn.FinalXlocation);
		testOut.FinalYlocation = betoh_double(testIn.FinalYlocation);
		testOut.TestID = be16toh(testIn.TestID);
		testOut.Type = be16toh(testIn.Type);
		testOut.SyncCode = be16toh(testIn.SyncCode);
		testOut.nSegments = be16toh(testIn.nSegments);
		testOut.nCriticalSections = be16toh(testIn.nCriticalSections);
		testOut.Layer = be16toh(testIn.Layer);
		testOut.StartTriggerChan = be16toh(testIn.StartTriggerChan);
		testOut.PathExitTriggerChan = be16toh(testIn.PathExitTriggerChan);
		testOut.PathAbortTriggerChan = be16toh(testIn.PathAbortTriggerChan);
		testOut.SRtestProg = be16toh(testIn.SRtestProg);
		testOut.BRtestProg = be16toh(testIn.BRtestProg);
		testOut.ARtestProg = be16toh(testIn.ARtestProg);
		testOut.NormalExitIndex = be16toh(testIn.NormalExitIndex);
		testOut.FirstTriggeredExitIndex = be16toh(testIn.FirstTriggeredExitIndex);
		testOut.nTriggeredExits = be16toh(testIn.nTriggeredExits);
		testOut.FirstSegmentIndex = be16toh(testIn.FirstSegmentIndex);
		testOut.FirstCritSectIndex = be16toh(testIn.FirstCritSectIndex);
		testOut.SRTestIndex = be16toh(testIn.SRTestIndex);
		testOut.BRTestIndex = be16toh(testIn.BRTestIndex);
		testOut.ARTestIndex = be16toh(testIn.ARTestIndex);
		testOut.GenTestIndex = be16toh(testIn.GenTestIndex);
		testOut.DataCaptureFreq = be16toh(testIn.DataCaptureFreq);
		testOut.TotalPassesComplete = be16toh(testIn.TotalPassesComplete);
		testOut.ActualTriggeredExitIndex = be16toh(testIn.ActualTriggeredExitIndex);

		// No need to flip one byte fields
		//int8_t NoTTTrigReset;
		//int8_t BRProgFromLastTest;
		//int8_t BRInhibitStart;
		//int8_t BRInhibitEnd;
		//int8_t ARProgFromLastTest;
		//int8_t ARInhibitStart;
		//int8_t ARInhibitEnd;
		//int8_t ARInhibitSCAbort;
		//int8_t FinalLapsRemaining;
		//uint8_t ExitTrigTrue;
		//char dummyChar[6];

		return testOut;			

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  // host is big endian, so no need to swap bytes

		return testIn;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

// Version 5
_TESTDATA_5 letoh_TestData_5(_TESTDATA_5 testIn)
{
	// Convert the test data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return testIn;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__

		_TESTDATA_5 testOut;
	
		testOut.StartTriggerVal = letoh_double(testIn.StartTriggerVal);
		testOut.StartTimeOffset = letoh_double(testIn.StartTimeOffset);
		testOut.InitialTransitionLocation = letoh_double(testIn.InitialTransitionLocation);
		testOut.PathExitTriggerVal = letoh_double(testIn.PathExitTriggerVal);
		testOut.TriggeredExitLocation = letoh_double(testIn.TriggeredExitLocation);
		testOut.TriggeredExitTime = letoh_double(testIn.TriggeredExitTime);
		testOut.PathAbortTriggerVal = letoh_double(testIn.PathAbortTriggerVal);
		testOut.InitialDist = letoh_double(testIn.InitialDist);
		testOut.Length = letoh_double(testIn.Length);
		testOut.TransitTime = letoh_double(testIn.TransitTime);
		testOut.FinalXlocation = letoh_double(testIn.FinalXlocation);
		testOut.FinalYlocation = letoh_double(testIn.FinalYlocation);
		testOut.POIdistance = letoh_double(testIn.POIdistance);
		testOut.TestID = le16toh(testIn.TestID);
		testOut.Type = le16toh(testIn.Type);
		testOut.SyncCode = le16toh(testIn.SyncCode);
		testOut.nSegments = le16toh(testIn.nSegments);
		testOut.nCriticalSections = le16toh(testIn.nCriticalSections);
		testOut.Layer = le16toh(testIn.Layer);
		testOut.StartTriggerChan = le16toh(testIn.StartTriggerChan);
		testOut.PathExitTriggerChan = le16toh(testIn.PathExitTriggerChan);
		testOut.PathAbortTriggerChan = le16toh(testIn.PathAbortTriggerChan);
		testOut.SRtestProg = le16toh(testIn.SRtestProg);
		testOut.BRtestProg = le16toh(testIn.BRtestProg);
		testOut.ARtestProg = le16toh(testIn.ARtestProg);
		testOut.NormalExitIndex = le16toh(testIn.NormalExitIndex);
		testOut.FirstTriggeredExitIndex = le16toh(testIn.FirstTriggeredExitIndex);
		testOut.nTriggeredExits = le16toh(testIn.nTriggeredExits);
		testOut.FirstSegmentIndex = le16toh(testIn.FirstSegmentIndex);
		testOut.FirstCritSectIndex = le16toh(testIn.FirstCritSectIndex);
		testOut.SRTestIndex = le16toh(testIn.SRTestIndex);
		testOut.BRTestIndex = le16toh(testIn.BRTestIndex);
		testOut.ARTestIndex = le16toh(testIn.ARTestIndex);
		testOut.GenTestIndex = le16toh(testIn.GenTestIndex);
		testOut.DataCaptureFreq = le16toh(testIn.DataCaptureFreq);
		testOut.TotalPassesComplete = le16toh(testIn.TotalPassesComplete);
		testOut.ActualTriggeredExitIndex = le16toh(testIn.ActualTriggeredExitIndex);
		testOut.FinalLapsRemaining = le16toh(testIn.FinalLapsRemaining);
		testOut.TTPOIdisableSeg =  le16toh(testIn.TTPOIdisableSeg);

		// No need to flip one byte fields
		//int8_t NoTTTrigReset;
		//int8_t BRProgFromLastTest;
		//int8_t BRInhibitStart;
		//int8_t BRInhibitEnd;
		//int8_t ARProgFromLastTest;
		//int8_t ARInhibitStart;
		//int8_t ARInhibitEnd;
		//int8_t ARInhibitSCAbort;
		//int8_t FinalLapsRemaining;
		//uint8_t ExitTrigTrue;
		//char dummyChar[6];

		return testOut;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

// Version 5
_TESTDATA_5 betoh_TestData_5(_TESTDATA_5 testIn)
{
	// Convert the test data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_TESTDATA_5 testOut;
	
		testOut.StartTriggerVal = betoh_double(testIn.StartTriggerVal);
		testOut.StartTimeOffset = betoh_double(testIn.StartTimeOffset);
		testOut.InitialTransitionLocation = betoh_double(testIn.InitialTransitionLocation);
		testOut.PathExitTriggerVal = betoh_double(testIn.PathExitTriggerVal);
		testOut.TriggeredExitLocation = betoh_double(testIn.TriggeredExitLocation);
		testOut.TriggeredExitTime = betoh_double(testIn.TriggeredExitTime);
		testOut.PathAbortTriggerVal = betoh_double(testIn.PathAbortTriggerVal);
		testOut.InitialDist = betoh_double(testIn.InitialDist);
		testOut.Length = betoh_double(testIn.Length);
		testOut.TransitTime = betoh_double(testIn.TransitTime);
		testOut.FinalXlocation = betoh_double(testIn.FinalXlocation);
		testOut.FinalYlocation = betoh_double(testIn.FinalYlocation);
		testOut.POIdistance = betoh_double(testIn.POIdistance);
		testOut.TestID = be16toh(testIn.TestID);
		testOut.Type = be16toh(testIn.Type);
		testOut.SyncCode = be16toh(testIn.SyncCode);
		testOut.nSegments = be16toh(testIn.nSegments);
		testOut.nCriticalSections = be16toh(testIn.nCriticalSections);
		testOut.Layer = be16toh(testIn.Layer);
		testOut.StartTriggerChan = be16toh(testIn.StartTriggerChan);
		testOut.PathExitTriggerChan = be16toh(testIn.PathExitTriggerChan);
		testOut.PathAbortTriggerChan = be16toh(testIn.PathAbortTriggerChan);
		testOut.SRtestProg = be16toh(testIn.SRtestProg);
		testOut.BRtestProg = be16toh(testIn.BRtestProg);
		testOut.ARtestProg = be16toh(testIn.ARtestProg);
		testOut.NormalExitIndex = be16toh(testIn.NormalExitIndex);
		testOut.FirstTriggeredExitIndex = be16toh(testIn.FirstTriggeredExitIndex);
		testOut.nTriggeredExits = be16toh(testIn.nTriggeredExits);
		testOut.FirstSegmentIndex = be16toh(testIn.FirstSegmentIndex);
		testOut.FirstCritSectIndex = be16toh(testIn.FirstCritSectIndex);
		testOut.SRTestIndex = be16toh(testIn.SRTestIndex);
		testOut.BRTestIndex = be16toh(testIn.BRTestIndex);
		testOut.ARTestIndex = be16toh(testIn.ARTestIndex);
		testOut.GenTestIndex = be16toh(testIn.GenTestIndex);
		testOut.DataCaptureFreq = be16toh(testIn.DataCaptureFreq);
		testOut.TotalPassesComplete = be16toh(testIn.TotalPassesComplete);
		testOut.ActualTriggeredExitIndex = be16toh(testIn.ActualTriggeredExitIndex);
		testOut.FinalLapsRemaining = be16toh(testIn.FinalLapsRemaining);
		testOut.TTPOIdisableSeg =  be16toh(testIn.TTPOIdisableSeg);

		// No need to flip one byte fields
		//int8_t NoTTTrigReset;
		//int8_t BRProgFromLastTest;
		//int8_t BRInhibitStart;
		//int8_t BRInhibitEnd;
		//int8_t ARProgFromLastTest;
		//int8_t ARInhibitStart;
		//int8_t ARInhibitEnd;
		//int8_t ARInhibitSCAbort;
		//int8_t FinalLapsRemaining;
		//uint8_t ExitTrigTrue;
		//char dummyChar[6];

		return testOut;			

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  // host is big endian, so no need to swap bytes

		return testIn;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_TRANSITIONDATA_0 letoh_TransitionData_0(_TRANSITIONDATA_0 transIn)
{
	// Convert the transition data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return transIn;		

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  

		_TRANSITIONDATA_0 transOut;
	
		transOut.EntryPointDistance = letoh_double(transIn.EntryPointDistance);
		transOut.LocalOriginX = letoh_double(transIn.LocalOriginX);
		transOut.LocalOriginY = letoh_double(transIn.LocalOriginY);
		transOut.LocalCos = letoh_double(transIn.LocalCos);
		transOut.LocalSin = letoh_double(transIn.LocalSin);
		transOut.CoeffA = letoh_double(transIn.CoeffA);
		transOut.CoeffB = letoh_double(transIn.CoeffB);
		transOut.InitialVel = letoh_double(transIn.InitialVel);
		transOut.Length = letoh_double(transIn.Length);
		transOut.Accel = letoh_double(transIn.Accel);
		transOut.SpeedEntryPointTime = letoh_double(transIn.SpeedEntryPointTime);
		transOut.TransitTime = letoh_double(transIn.TransitTime);
		transOut.FinalVel = letoh_float(transIn.FinalVel);
		transOut.FirstValidX = letoh_float(transIn.FirstValidX);
		transOut.DestinationSubGroupIndex = le16toh(transIn.DestinationSubGroupIndex);
		transOut.DestinationTestIndex = le16toh(transIn.DestinationTestIndex);
		// don't worry about flipping dummy
	
		return transOut;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_TRANSITIONDATA_0 betoh_TransitionData_0(_TRANSITIONDATA_0 transIn)
{
	// Convert the transition data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_TRANSITIONDATA_0 transOut;
	
		transOut.EntryPointDistance = betoh_double(transIn.EntryPointDistance);
		transOut.LocalOriginX = betoh_double(transIn.LocalOriginX);
		transOut.LocalOriginY = betoh_double(transIn.LocalOriginY);
		transOut.LocalCos = betoh_double(transIn.LocalCos);
		transOut.LocalSin = betoh_double(transIn.LocalSin);
		transOut.CoeffA = betoh_double(transIn.CoeffA);
		transOut.CoeffB = betoh_double(transIn.CoeffB);
		transOut.InitialVel = betoh_double(transIn.InitialVel);
		transOut.Length = betoh_double(transIn.Length);
		transOut.Accel = betoh_double(transIn.Accel);
		transOut.SpeedEntryPointTime = betoh_double(transIn.SpeedEntryPointTime);
		transOut.TransitTime = betoh_double(transIn.TransitTime);
		transOut.FinalVel = betoh_float(transIn.FinalVel);
		transOut.FirstValidX = betoh_float(transIn.FirstValidX);
		transOut.DestinationSubGroupIndex = be16toh(transIn.DestinationSubGroupIndex);
		transOut.DestinationTestIndex = be16toh(transIn.DestinationTestIndex);
		// don't worry about flipping dummy
	
		return transOut;		

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  // host is big endian, so no need to swap bytes

		return transIn;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_TRANSITIONDATA_2 letoh_TransitionData_2(_TRANSITIONDATA_2 transIn)
{
	// Convert the transition data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return transIn;		

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  

		_TRANSITIONDATA_2 transOut;
		
		transOut.LocalOriginX = letoh_double(transIn.LocalOriginX);
		transOut.LocalOriginY = letoh_double(transIn.LocalOriginY);
		transOut.EntryPointDistance = letoh_double(transIn.EntryPointDistance);
		transOut.SpeedEntryPointTime = letoh_double(transIn.SpeedEntryPointTime);
		transOut.ExitTriggerVal = letoh_double(transIn.ExitTriggerVal);
		transOut.ExitLocation = letoh_double(transIn.ExitLocation);
		transOut.CoeffA = letoh_double(transIn.CoeffA);
		transOut.CoeffB = letoh_double(transIn.CoeffB);

		transOut.LocalCos = letoh_float(transIn.LocalCos);
		transOut.LocalSin = letoh_float(transIn.LocalSin);
		transOut.Length = letoh_float(transIn.Length);
		transOut.Accel = letoh_float(transIn.Accel);
		transOut.TransitTime = letoh_float(transIn.TransitTime);
		transOut.InitialVel = letoh_float(transIn.InitialVel);
		transOut.FinalVel = letoh_float(transIn.FinalVel);
		transOut.FirstValidX = letoh_float(transIn.FirstValidX);

		transOut.DestinationSubGroupIndex = le16toh(transIn.DestinationSubGroupIndex);
		transOut.DestinationTestIndex = le16toh(transIn.DestinationTestIndex);
		transOut.TrigChan = le16toh(transIn.TrigChan);
		transOut.TrigRateVarNum = le16toh(transIn.TrigRateVarNum);
		transOut.TrigOffsetVarNum = le16toh(transIn.TrigOffsetVarNum);

		// No need to flip single byte members
		//int8_t TrigType;
		//int8_t TrigSense;
		//uint8_t TrigDigVal;
		//uint8_t TrigEnabled;	
		//uint8_t TrigTrue; 
		//int8_t TrigAbs;	
	
		return transOut;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_TRANSITIONDATA_2 betoh_TransitionData_2(_TRANSITIONDATA_2 transIn)
{
	// Convert the transition data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_TRANSITIONDATA_2 transOut;
	
		transOut.LocalOriginX = betoh_double(transIn.LocalOriginX);
		transOut.LocalOriginY = betoh_double(transIn.LocalOriginY);
		transOut.EntryPointDistance = betoh_double(transIn.EntryPointDistance);
		transOut.SpeedEntryPointTime = betoh_double(transIn.SpeedEntryPointTime);
		transOut.ExitTriggerVal = betoh_double(transIn.ExitTriggerVal);
		transOut.ExitLocation = betoh_double(transIn.ExitLocation);
		transOut.CoeffA = betoh_double(transIn.CoeffA);
		transOut.CoeffB = betoh_double(transIn.CoeffB);

		transOut.LocalCos = betoh_float(transIn.LocalCos);
		transOut.LocalSin = betoh_float(transIn.LocalSin);
		transOut.Length = betoh_float(transIn.Length);
		transOut.Accel = betoh_float(transIn.Accel);
		transOut.TransitTime = betoh_float(transIn.TransitTime);
		transOut.InitialVel = betoh_float(transIn.InitialVel);
		transOut.FinalVel = betoh_float(transIn.FinalVel);
		transOut.FirstValidX = betoh_float(transIn.FirstValidX);

		transOut.DestinationSubGroupIndex = be16toh(transIn.DestinationSubGroupIndex);
		transOut.DestinationTestIndex = be16toh(transIn.DestinationTestIndex);
		transOut.TrigChan = be16toh(transIn.TrigChan);
		transOut.TrigRateVarNum = be16toh(transIn.TrigRateVarNum);
		transOut.TrigOffsetVarNum = be16toh(transIn.TrigOffsetVarNum);

		// No need to flip single byte members
		//int8_t TrigType;
		//int8_t TrigSense;
		//uint8_t TrigDigVal;
		//uint8_t TrigEnabled;	
		//uint8_t TrigTrue; 
		//int8_t TrigAbs;	
	
		return transOut;		

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  // host is big endian, so no need to swap bytes

		return transIn;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_SEGMENTDATA_0 letoh_SegmentData_0(_SEGMENTDATA_0 segmentIn)
{
	// Convert the segment data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return segmentIn;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  

		_SEGMENTDATA_0 segmentOut;
	
		segmentOut.InitialHeadingCos = letoh_double(segmentIn.InitialHeadingCos);
		segmentOut.InitialHeadingSin = letoh_double(segmentIn.InitialHeadingSin);
		segmentOut.InitialX = letoh_double(segmentIn.InitialX);
		segmentOut.InitialY = letoh_double(segmentIn.InitialY);
		segmentOut.Length = letoh_double(segmentIn.Length);
		segmentOut.InitialTime = letoh_double(segmentIn.InitialTime);
		segmentOut.InitialDist = letoh_double(segmentIn.InitialDist);
		segmentOut.Radius = letoh_double(segmentIn.Radius);
		segmentOut.EndRadius = letoh_double(segmentIn.EndRadius);
		segmentOut.HoldTime = letoh_double(segmentIn.HoldTime);
		segmentOut.StartTriggerVal = letoh_double(segmentIn.StartTriggerVal);
		segmentOut.InvPointDist = letoh_double(segmentIn.InvPointDist);
		segmentOut.PointDist = letoh_double(segmentIn.PointDist);
		segmentOut.InitialVel = letoh_float(segmentIn.InitialVel);
		segmentOut.FinalVel = letoh_float(segmentIn.FinalVel);
		segmentOut.Type = le16toh(segmentIn.Type);
		segmentOut.nPoints = le16toh(segmentIn.nPoints);
		segmentOut.StartTriggerChan = le16toh(segmentIn.StartTriggerChan);
		segmentOut.FirstBsplineIndex = le16toh(segmentIn.FirstBsplineIndex);
	
		return segmentOut;			

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_SEGMENTDATA_0 betoh_SegmentData_0(_SEGMENTDATA_0 segmentIn)
{
	// Convert the segment data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_SEGMENTDATA_0 segmentOut;
	
		segmentOut.InitialHeadingCos = betoh_double(segmentIn.InitialHeadingCos);
		segmentOut.InitialHeadingSin = betoh_double(segmentIn.InitialHeadingSin);
		segmentOut.InitialX = betoh_double(segmentIn.InitialX);
		segmentOut.InitialY = betoh_double(segmentIn.InitialY);
		segmentOut.Length = betoh_double(segmentIn.Length);
		segmentOut.InitialTime = betoh_double(segmentIn.InitialTime);
		segmentOut.InitialDist = betoh_double(segmentIn.InitialDist);
		segmentOut.Radius = betoh_double(segmentIn.Radius);
		segmentOut.EndRadius = betoh_double(segmentIn.EndRadius);
		segmentOut.HoldTime = betoh_double(segmentIn.HoldTime);
		segmentOut.StartTriggerVal = betoh_double(segmentIn.StartTriggerVal);
		segmentOut.InvPointDist = betoh_double(segmentIn.InvPointDist);
		segmentOut.PointDist = betoh_double(segmentIn.PointDist);
		segmentOut.InitialVel = betoh_float(segmentIn.InitialVel);
		segmentOut.FinalVel = betoh_float(segmentIn.FinalVel);
		segmentOut.Type = be16toh(segmentIn.Type);
		segmentOut.nPoints = be16toh(segmentIn.nPoints);
		segmentOut.StartTriggerChan = be16toh(segmentIn.StartTriggerChan);
		segmentOut.FirstBsplineIndex = be16toh(segmentIn.FirstBsplineIndex);
	
		return segmentOut;		

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  // host is big endian, so no need to swap bytes

		return segmentIn;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

// Version 2
_SEGMENTDATA_2 letoh_SegmentData_2(_SEGMENTDATA_2 segmentIn)
{
	// Convert the segment data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return segmentIn;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  

		_SEGMENTDATA_2 segmentOut;
	
		segmentOut.InitialX = letoh_double(segmentIn.InitialX);
		segmentOut.InitialY = letoh_double(segmentIn.InitialY);
		segmentOut.InitialTime = letoh_double(segmentIn.InitialTime);
		segmentOut.InitialDist = letoh_double(segmentIn.InitialDist);
		segmentOut.StartTriggerVal = letoh_double(segmentIn.StartTriggerVal);

		segmentOut.InitialHeadingCos = letoh_float(segmentIn.InitialHeadingCos);
		segmentOut.InitialHeadingSin = letoh_float(segmentIn.InitialHeadingSin);
		segmentOut.Length = letoh_float(segmentIn.Length);
		segmentOut.Radius = letoh_float(segmentIn.Radius);
		segmentOut.EndRadius = letoh_float(segmentIn.EndRadius);
		segmentOut.HoldTime = letoh_float(segmentIn.HoldTime);	
		segmentOut.InvPointDist = letoh_float(segmentIn.InvPointDist);
		segmentOut.PointDist = letoh_float(segmentIn.PointDist);
		segmentOut.InitialVel = letoh_float(segmentIn.InitialVel);
		segmentOut.FinalVel = letoh_float(segmentIn.FinalVel);

		segmentOut.Type = le16toh(segmentIn.Type);
		segmentOut.nPoints = le16toh(segmentIn.nPoints);
		segmentOut.StartTriggerChan = le16toh(segmentIn.StartTriggerChan);
		segmentOut.FirstBsplineIndex = le16toh(segmentIn.FirstBsplineIndex);
	
		return segmentOut;			

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_SEGMENTDATA_2 betoh_SegmentData_2(_SEGMENTDATA_2 segmentIn)
{
	// Convert the segment data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_SEGMENTDATA_2 segmentOut;
	
		segmentOut.InitialX = betoh_double(segmentIn.InitialX);
		segmentOut.InitialY = betoh_double(segmentIn.InitialY);
		segmentOut.InitialTime = betoh_double(segmentIn.InitialTime);
		segmentOut.InitialDist = betoh_double(segmentIn.InitialDist);
		segmentOut.StartTriggerVal = betoh_double(segmentIn.StartTriggerVal);

		segmentOut.InitialHeadingCos = betoh_float(segmentIn.InitialHeadingCos);
		segmentOut.InitialHeadingSin = betoh_float(segmentIn.InitialHeadingSin);
		segmentOut.Length = betoh_float(segmentIn.Length);
		segmentOut.Radius = betoh_float(segmentIn.Radius);
		segmentOut.EndRadius = betoh_float(segmentIn.EndRadius);
		segmentOut.HoldTime = betoh_float(segmentIn.HoldTime);	
		segmentOut.InvPointDist = betoh_float(segmentIn.InvPointDist);
		segmentOut.PointDist = betoh_float(segmentIn.PointDist);
		segmentOut.InitialVel = betoh_float(segmentIn.InitialVel);
		segmentOut.FinalVel = betoh_float(segmentIn.FinalVel);

		segmentOut.Type = be16toh(segmentIn.Type);
		segmentOut.nPoints = be16toh(segmentIn.nPoints);
		segmentOut.StartTriggerChan = be16toh(segmentIn.StartTriggerChan);
		segmentOut.FirstBsplineIndex = be16toh(segmentIn.FirstBsplineIndex);
	
		return segmentOut;		

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  // host is big endian, so no need to swap bytes

		return segmentIn;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_SPLINEDATA_0 letoh_SplineData_0(_SPLINEDATA_0 splineIn)
{
	// Convert the spline data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return splineIn;

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  
		
		_SPLINEDATA_0 splineOut;
	
		splineOut.X = letoh_double(splineIn.X);
		splineOut.Y = letoh_double(splineIn.Y);
		splineOut.Time = letoh_double(splineIn.Time);
		splineOut.Velocity = letoh_float(splineIn.Velocity);
		// don't worry about flipping dummy
	
		return splineOut;	

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_SPLINEDATA_0 betoh_SplineData_0(_SPLINEDATA_0 splineIn)
{
	// Convert the spline data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_SPLINEDATA_0 splineOut;
	
		splineOut.X = betoh_double(splineIn.X);
		splineOut.Y = betoh_double(splineIn.Y);
		splineOut.Time = betoh_double(splineIn.Time);
		splineOut.Velocity = betoh_float(splineIn.Velocity);
		// don't worry about flipping dummy
	
		return splineOut;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  // host is big endian, so no need to swap bytes

		return splineIn;

	#else
	
		#error "Unsupported endianness"
	
	#endif
}

_CRITSECTDATA_0 letoh_CritSectData_0(_CRITSECTDATA_0 critSectIn) {
	// Convert the critical section data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return critSectIn;

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  

		_CRITSECTDATA_0 critSectOut;

		critSectOut.StartDistance = letoh_double(critSectIn.StartDistance);
		critSectOut.EndDistance = letoh_double(critSectIn.EndDistance);

		critSectOut.MaxLateralError = letoh_float(critSectIn.MaxLateralError);
		critSectOut.MinLateralError = letoh_float(critSectIn.MinLateralError);
		critSectOut.MaxDistanceError = letoh_float(critSectIn.MaxDistanceError);
		critSectOut.MinDistanceError = letoh_float(critSectIn.MinDistanceError);
		critSectOut.MaxSWA = letoh_float(critSectIn.MaxSWA);
		critSectOut.MinSWA = letoh_float(critSectIn.MinSWA);
		critSectOut.MaxSWV = letoh_float(critSectIn.MaxSWV);
		critSectOut.MinSWV = letoh_float(critSectIn.MinSWV);
		critSectOut.SRabortParameter1 = letoh_float(critSectIn.SRabortParameter1);
		critSectOut.SRabortParameter2 = letoh_float(critSectIn.SRabortParameter2);
		critSectOut.SRabortParameter3 = letoh_float(critSectIn.SRabortParameter3);
		critSectOut.SRabortParameter4 = letoh_float(critSectIn.SRabortParameter4);
		critSectOut.ARabortDwellTime = letoh_float(critSectIn.ARabortDwellTime);
		critSectOut.BRabortDwellTime = letoh_float(critSectIn.BRabortDwellTime);
		critSectOut.ResetLengthVGR = letoh_float(critSectIn.ResetLengthVGR);
		critSectOut.SRgainVGR = letoh_float(critSectIn.SRgainVGR);
		critSectOut.SRangleVGR = letoh_float(critSectIn.SRangleVGR);
		critSectOut.SRtorqueVGR = letoh_float(critSectIn.SRtorqueVGR);
		critSectOut.SRangleVelocityVGR = letoh_float(critSectIn.SRangleVelocityVGR);
		critSectOut.SRtorqueVelocityVGR = letoh_float(critSectIn.SRtorqueVelocityVGR);
		critSectOut.SRtorqueLimitVGR = letoh_float(critSectIn.SRtorqueLimitVGR);
		critSectOut.ARparameterVGR = letoh_float(critSectIn.ARparameterVGR);
		critSectOut.StartTriggerVal = letoh_float(critSectIn.StartTriggerVal);
		critSectOut.EndTriggerVal = letoh_float(critSectIn.EndTriggerVal);

		critSectOut.Type = le16toh(critSectIn.Type);
		critSectOut.GearPosition = le16toh(critSectIn.GearPosition);
		critSectOut.SRabortMode = le16toh(critSectIn.SRabortMode);
		critSectOut.ARabortLevel = le16toh(critSectIn.ARabortLevel);
		critSectOut.BRabortLevel = le16toh(critSectIn.BRabortLevel);
		critSectOut.SRactionVGR = le16toh(critSectIn.SRactionVGR);
		critSectOut.ARactionVGR = le16toh(critSectIn.ARactionVGR);
		critSectOut.StartTriggerChan = le16toh(critSectIn.StartTriggerChan);
		critSectOut.EndTriggerChan = le16toh(critSectIn.EndTriggerChan);
		critSectOut.RestoreDistCtrlVGR = le16toh(critSectIn.RestoreDistCtrlVGR);
		critSectOut.SRintegralActionVGR = le16toh(critSectIn.SRintegralActionVGR);
		// don't worry about flipping dummy

		return critSectOut;	

	#else

		#error "Unsupported endianness"

	#endif
}

_CRITSECTDATA_0 betoh_CritSectData_0(_CRITSECTDATA_0 critSectIn) {
	// Convert the critical section data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_CRITSECTDATA_0 critSectOut;
	
		critSectOut.StartDistance = betoh_double(critSectIn.StartDistance);
		critSectOut.EndDistance = betoh_double(critSectIn.EndDistance);

		critSectOut.MaxLateralError = betoh_float(critSectIn.MaxLateralError);
		critSectOut.MinLateralError = betoh_float(critSectIn.MinLateralError);
		critSectOut.MaxDistanceError = betoh_float(critSectIn.MaxDistanceError);
		critSectOut.MinDistanceError = betoh_float(critSectIn.MinDistanceError);
		critSectOut.MaxSWA = betoh_float(critSectIn.MaxSWA);
		critSectOut.MinSWA = betoh_float(critSectIn.MinSWA);
		critSectOut.MaxSWV = betoh_float(critSectIn.MaxSWV);
		critSectOut.MinSWV = betoh_float(critSectIn.MinSWV);
		critSectOut.SRabortParameter1 = betoh_float(critSectIn.SRabortParameter1);
		critSectOut.SRabortParameter2 = betoh_float(critSectIn.SRabortParameter2);
		critSectOut.SRabortParameter3 = betoh_float(critSectIn.SRabortParameter3);
		critSectOut.SRabortParameter4 = betoh_float(critSectIn.SRabortParameter4);
		critSectOut.ARabortDwellTime = betoh_float(critSectIn.ARabortDwellTime);
		critSectOut.BRabortDwellTime = betoh_float(critSectIn.BRabortDwellTime);
		critSectOut.ResetLengthVGR = betoh_float(critSectIn.ResetLengthVGR);
		critSectOut.SRgainVGR = betoh_float(critSectIn.SRgainVGR);
		critSectOut.SRangleVGR = betoh_float(critSectIn.SRangleVGR);
		critSectOut.SRtorqueVGR = betoh_float(critSectIn.SRtorqueVGR);
		critSectOut.SRangleVelocityVGR = betoh_float(critSectIn.SRangleVelocityVGR);
		critSectOut.SRtorqueVelocityVGR = betoh_float(critSectIn.SRtorqueVelocityVGR);
		critSectOut.SRtorqueLimitVGR = betoh_float(critSectIn.SRtorqueLimitVGR);
		critSectOut.ARparameterVGR = betoh_float(critSectIn.ARparameterVGR);
		critSectOut.StartTriggerVal = betoh_float(critSectIn.StartTriggerVal);
		critSectOut.EndTriggerVal = betoh_float(critSectIn.EndTriggerVal);

		critSectOut.Type = be16toh(critSectIn.Type);
		critSectOut.GearPosition = be16toh(critSectIn.GearPosition);
		critSectOut.SRabortMode = be16toh(critSectIn.SRabortMode);
		critSectOut.ARabortLevel = be16toh(critSectIn.ARabortLevel);
		critSectOut.BRabortLevel = be16toh(critSectIn.BRabortLevel);
		critSectOut.SRactionVGR = be16toh(critSectIn.SRactionVGR);
		critSectOut.ARactionVGR = be16toh(critSectIn.ARactionVGR);
		critSectOut.StartTriggerChan = be16toh(critSectIn.StartTriggerChan);
		critSectOut.EndTriggerChan = be16toh(critSectIn.EndTriggerChan);
		critSectOut.RestoreDistCtrlVGR = be16toh(critSectIn.RestoreDistCtrlVGR);
		critSectOut.SRintegralActionVGR = be16toh(critSectIn.SRintegralActionVGR);
		// don't worry about flipping dummy

		return critSectOut;		

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  // host is big endian, so no need to swap bytes

		return critSectIn;

	#else

		#error "Unsupported endianness"

	#endif
}

_CRITSECTDATA_2 letoh_CritSectData_2(_CRITSECTDATA_2 critSectIn) {
	// Convert the critical section data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return critSectIn;

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  

		_CRITSECTDATA_2 critSectOut;

		critSectOut.StartTriggerVal = letoh_double(critSectIn.StartTriggerVal);
		critSectOut.EndTriggerVal = letoh_double(critSectIn.EndTriggerVal);

		critSectOut.StartDistance = letoh_float(critSectIn.StartDistance);
		critSectOut.EndDistance = letoh_float(critSectIn.EndDistance);

		critSectOut.MaxLateralError = letoh_float(critSectIn.MaxLateralError);
		critSectOut.MinLateralError = letoh_float(critSectIn.MinLateralError);
		critSectOut.MaxDistanceError = letoh_float(critSectIn.MaxDistanceError);
		critSectOut.MinDistanceError = letoh_float(critSectIn.MinDistanceError);
		critSectOut.MaxSWA = letoh_float(critSectIn.MaxSWA);
		critSectOut.MinSWA = letoh_float(critSectIn.MinSWA);
		critSectOut.MaxSWV = letoh_float(critSectIn.MaxSWV);
		critSectOut.MinSWV = letoh_float(critSectIn.MinSWV);
		critSectOut.SRabortParameter1 = letoh_float(critSectIn.SRabortParameter1);
		critSectOut.SRabortParameter2 = letoh_float(critSectIn.SRabortParameter2);
		critSectOut.SRabortParameter3 = letoh_float(critSectIn.SRabortParameter3);
		critSectOut.SRabortParameter4 = letoh_float(critSectIn.SRabortParameter4);
		critSectOut.ARabortDwellTime = letoh_float(critSectIn.ARabortDwellTime);
		critSectOut.BRabortDwellTime = letoh_float(critSectIn.BRabortDwellTime);
		critSectOut.ResetLengthVGR = letoh_float(critSectIn.ResetLengthVGR);
		critSectOut.SRgainVGR = letoh_float(critSectIn.SRgainVGR);
		critSectOut.SRangleVGR = letoh_float(critSectIn.SRangleVGR);
		critSectOut.SRtorqueVGR = letoh_float(critSectIn.SRtorqueVGR);
		critSectOut.SRangleVelocityVGR = letoh_float(critSectIn.SRangleVelocityVGR);
		critSectOut.SRtorqueVelocityVGR = letoh_float(critSectIn.SRtorqueVelocityVGR);
		critSectOut.SRtorqueLimitVGR = letoh_float(critSectIn.SRtorqueLimitVGR);
		critSectOut.ARparameterVGR = letoh_float(critSectIn.ARparameterVGR);

		critSectOut.ARabortLevel = le16toh(critSectIn.ARabortLevel);
		critSectOut.BRabortLevel = le16toh(critSectIn.BRabortLevel);
		critSectOut.StartTriggerChan = le16toh(critSectIn.StartTriggerChan);
		critSectOut.EndTriggerChan = le16toh(critSectIn.EndTriggerChan);

		//No need to flip one byte fields
		// int8_t GearPosition;
		// int8_t SRabortMode;
		// int8_t Type;
		// int8_t SRactionVGR;
		// int8_t ARactionVGR;
		// int8_t RestoreDistCtrlVGR;
		// int8_t SRintegralActionVGR;
		// char dummyChar;

		return critSectOut;	

	#else

		#error "Unsupported endianness"

	#endif
}

_CRITSECTDATA_2 betoh_CritSectData_2(_CRITSECTDATA_2 critSectIn) {
	// Convert the critical section data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_CRITSECTDATA_2 critSectOut;

		critSectOut.StartTriggerVal = betoh_double(critSectIn.StartTriggerVal);
		critSectOut.EndTriggerVal = betoh_double(critSectIn.EndTriggerVal);

		critSectOut.StartDistance = betoh_float(critSectIn.StartDistance);
		critSectOut.EndDistance = betoh_float(critSectIn.EndDistance);

		critSectOut.MaxLateralError = betoh_float(critSectIn.MaxLateralError);
		critSectOut.MinLateralError = betoh_float(critSectIn.MinLateralError);
		critSectOut.MaxDistanceError = betoh_float(critSectIn.MaxDistanceError);
		critSectOut.MinDistanceError = betoh_float(critSectIn.MinDistanceError);
		critSectOut.MaxSWA = betoh_float(critSectIn.MaxSWA);
		critSectOut.MinSWA = betoh_float(critSectIn.MinSWA);
		critSectOut.MaxSWV = betoh_float(critSectIn.MaxSWV);
		critSectOut.MinSWV = betoh_float(critSectIn.MinSWV);
		critSectOut.SRabortParameter1 = betoh_float(critSectIn.SRabortParameter1);
		critSectOut.SRabortParameter2 = betoh_float(critSectIn.SRabortParameter2);
		critSectOut.SRabortParameter3 = betoh_float(critSectIn.SRabortParameter3);
		critSectOut.SRabortParameter4 = betoh_float(critSectIn.SRabortParameter4);
		critSectOut.ARabortDwellTime = betoh_float(critSectIn.ARabortDwellTime);
		critSectOut.BRabortDwellTime = betoh_float(critSectIn.BRabortDwellTime);
		critSectOut.ResetLengthVGR = betoh_float(critSectIn.ResetLengthVGR);
		critSectOut.SRgainVGR = betoh_float(critSectIn.SRgainVGR);
		critSectOut.SRangleVGR = betoh_float(critSectIn.SRangleVGR);
		critSectOut.SRtorqueVGR = betoh_float(critSectIn.SRtorqueVGR);
		critSectOut.SRangleVelocityVGR = betoh_float(critSectIn.SRangleVelocityVGR);
		critSectOut.SRtorqueVelocityVGR = betoh_float(critSectIn.SRtorqueVelocityVGR);
		critSectOut.SRtorqueLimitVGR = betoh_float(critSectIn.SRtorqueLimitVGR);
		critSectOut.ARparameterVGR = betoh_float(critSectIn.ARparameterVGR);

		critSectOut.ARabortLevel = be16toh(critSectIn.ARabortLevel);
		critSectOut.BRabortLevel = be16toh(critSectIn.BRabortLevel);
		critSectOut.StartTriggerChan = be16toh(critSectIn.StartTriggerChan);
		critSectOut.EndTriggerChan = be16toh(critSectIn.EndTriggerChan);

		//No need to flip one byte fields
		// int8_t GearPosition;
		// int8_t SRabortMode;
		// int8_t Type;
		// int8_t SRactionVGR;
		// int8_t ARactionVGR;
		// int8_t RestoreDistCtrlVGR;
		// int8_t SRintegralActionVGR;
		// char dummyChar;

		return critSectOut;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  // host is big endian, so no need to swap bytes

		return critSectIn;

	#else

		#error "Unsupported endianness"

	#endif
}

_DRIVERLESSDATA_0 letoh_DriverlessData_0(_DRIVERLESSDATA_0 driverlessIn)
{
	// Convert the driverless data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return driverlessIn;

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  

		_DRIVERLESSDATA_0 driverlessOut;

		driverlessOut.TestBoundaryMinX = letoh_double(driverlessIn.TestBoundaryMinX);
		driverlessOut.TestBoundaryMinY = letoh_double(driverlessIn.TestBoundaryMinY);
		driverlessOut.TestBoundaryMaxX = letoh_double(driverlessIn.TestBoundaryMaxX);
		driverlessOut.TestBoundaryMaxY = letoh_double(driverlessIn.TestBoundaryMaxY);
		driverlessOut.TestSpeedLimit = letoh_float(driverlessIn.TestSpeedLimit);
		driverlessOut.ReturnSpeedLimit = letoh_float(driverlessIn.ReturnSpeedLimit);
		driverlessOut.ReturnMaxSWA = letoh_float(driverlessIn.ReturnMaxSWA);
		driverlessOut.ReturnPathIndex = le16toh(driverlessIn.ReturnPathIndex);
		driverlessOut.RemoteControlTrue = le16toh(driverlessIn.RemoteControlTrue);

		return driverlessOut;	

	#else

		#error "Unsupported endianness"

	#endif
}

_DRIVERLESSDATA_0 betoh_DriverlessData_0(_DRIVERLESSDATA_0 driverlessIn)
{
	// Convert the driverless data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_DRIVERLESSDATA_0 driverlessOut;

		driverlessOut.TestBoundaryMinX = betoh_double(driverlessIn.TestBoundaryMinX);
		driverlessOut.TestBoundaryMinY = betoh_double(driverlessIn.TestBoundaryMinY);
		driverlessOut.TestBoundaryMaxX = betoh_double(driverlessIn.TestBoundaryMaxX);
		driverlessOut.TestBoundaryMaxY = betoh_double(driverlessIn.TestBoundaryMaxY);
		driverlessOut.TestSpeedLimit = betoh_float(driverlessIn.TestSpeedLimit);
		driverlessOut.ReturnSpeedLimit = betoh_float(driverlessIn.ReturnSpeedLimit);
		driverlessOut.ReturnMaxSWA = betoh_float(driverlessIn.ReturnMaxSWA);
		driverlessOut.ReturnPathIndex = be16toh(driverlessIn.ReturnPathIndex);
		driverlessOut.RemoteControlTrue = be16toh(driverlessIn.RemoteControlTrue);

		return driverlessOut;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  // host is big endian, so no need to swap bytes

		return driverlessIn;

	#else

		#error "Unsupported endianness"

	#endif
}

_DRIVERLESSDATA_2 letoh_DriverlessData_2(_DRIVERLESSDATA_2 driverlessIn)
{
	// Convert the driverless data structure from little endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__ // host is little endian, so no need to swap bytes

		return driverlessIn;

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  

		_DRIVERLESSDATA_2 driverlessOut;

		driverlessOut.TestBoundaryMinX = letoh_float(driverlessIn.TestBoundaryMinX);
		driverlessOut.TestBoundaryMinY = letoh_float(driverlessIn.TestBoundaryMinY);
		driverlessOut.TestBoundaryMaxX = letoh_float(driverlessIn.TestBoundaryMaxX);
		driverlessOut.TestBoundaryMaxY = letoh_float(driverlessIn.TestBoundaryMaxY);
		driverlessOut.TestSpeedLimit = letoh_float(driverlessIn.TestSpeedLimit);
		driverlessOut.ReturnSpeedLimit = letoh_float(driverlessIn.ReturnSpeedLimit);
		driverlessOut.ReturnMaxSWA = letoh_float(driverlessIn.ReturnMaxSWA);
		driverlessOut.ReturnPathIndex = le16toh(driverlessIn.ReturnPathIndex);
		driverlessOut.RemoteControlTrue = le16toh(driverlessIn.RemoteControlTrue);

		return driverlessOut;	

	#else

		#error "Unsupported endianness"

	#endif
}

_DRIVERLESSDATA_2 betoh_DriverlessData_2(_DRIVERLESSDATA_2 driverlessIn)
{
	// Convert the driverless data structure from big endian format to the host system
	
	#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__

		_DRIVERLESSDATA_2 driverlessOut;

		driverlessOut.TestBoundaryMinX = betoh_float(driverlessIn.TestBoundaryMinX);
		driverlessOut.TestBoundaryMinY = betoh_float(driverlessIn.TestBoundaryMinY);
		driverlessOut.TestBoundaryMaxX = betoh_float(driverlessIn.TestBoundaryMaxX);
		driverlessOut.TestBoundaryMaxY = betoh_float(driverlessIn.TestBoundaryMaxY);
		driverlessOut.TestSpeedLimit = betoh_float(driverlessIn.TestSpeedLimit);
		driverlessOut.ReturnSpeedLimit = betoh_float(driverlessIn.ReturnSpeedLimit);
		driverlessOut.ReturnMaxSWA = betoh_float(driverlessIn.ReturnMaxSWA);
		driverlessOut.ReturnPathIndex = be16toh(driverlessIn.ReturnPathIndex);
		driverlessOut.RemoteControlTrue = be16toh(driverlessIn.RemoteControlTrue);

		return driverlessOut;	

	#elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__  // host is big endian, so no need to swap bytes

		return driverlessIn;

	#else

		#error "Unsupported endianness"

	#endif
}
