#include "comms.h"

#include <stdio.h>

int requestDataFromPowerPMAC(int s, uint32_t address, uint32_t numBytes, unsigned char *const reply)
{
	// Sends a message to the Power PMAC, requesting numBytes bytes of data, starting at address
	// Assumes that a socket has already been created and connection established
	// Expects address and numBytes to be in host endianness
	
	// Returns the number of bytes read from the PPMAC
	
	// Send the message requesting data back from the PPMAC
	unsigned char msgOut[12];
	
	// Specify we want to get data from the user shared memory
	msgOut[0] = 0xC0;
	msgOut[1] = 0xB4; // C0B4 for get data
	
	serialise_uint32( &msgOut[2], address );
	
	// Index - always 0x 00 00
	msgOut[6] = 0x00;
	msgOut[7] = 0x00;

	serialise_uint32( &msgOut[8], numBytes );
	
	// Send the message
	if( send( s, msgOut, sizeof(msgOut), 0) < 0)
	{
		return -1;
	}
	
	//Receive a reply from the server
	int recv_size; // number of bytes that were received
	if((recv_size = recv( s, reply, numBytes, 0)) == -1)
	{
		return -2;
	}
	
	return recv_size;
}

int getVarFromPowerPMAC(int s, char *const var_name, uint32_t name_length)
{
	// Sends a message to the Power PMAC, requesting a named variable to be set to a particular value

	// Send the message requesting data back from the PPMAC
	unsigned char msgOut[128] = {0};
	
	if (name_length > 100)
	{
		return -1;
	}
	
	if (var_name == NULL)
	{
		return -2;
	}	
	
	// Specify we want to get data from the user shared memory
	msgOut[0] = 0xC0;
	msgOut[1] = 0xBE; // C0BE for get variable	

	// Serialise the payload length
	serialise_uint32( &msgOut[8], htole32(name_length) );
	
	// Serialise the variable name
	memcpy( &msgOut[12], var_name, name_length );
	
	int msg_length = 12 + name_length;
	
	// Send the message
	if( send( s, msgOut, msg_length, 0) < 0)
	{
		return -3;
	}
	
	//Receive a reply from the server
	int recv_size; // number of bytes that were received
	if((recv_size = recv( s, msgOut, sizeof(msgOut), 0)) == -1)
	{
		return -4;
	}
	
	float value = atof( (char *)msgOut );
	return (int)value;
}

int setDataOnPowerPMAC(int s, uint32_t address, uint32_t numBytes, unsigned char *const data)
{
	// Sends a message to the Power PMAC, requesting numBytes bytes of data to be set starting at address
	// Assumes that a socket has already been created and connection established
	// Expects address and numBytes to be in host endianness
	
	if ( numBytes >= 1000 )
	{
		return -1; // too many bytes to set
	}
	
	// Send the message requesting data set to the PPMAC
	unsigned char msgOut[1012];
	
	// Specify we want to get data from the user shared memory
	msgOut[0] = 0xC0;
	msgOut[1] = 0xB5; // C0B5 for set data
	
	serialise_uint32( &msgOut[2], address );
	
	// Index - always 0x 00 00
	msgOut[6] = 0x00;
	msgOut[7] = 0x00;

	serialise_uint32( &msgOut[8], numBytes );
	
	unsigned int i;
	for ( i = 0; i < numBytes; ++i )
	{
		serialise_uchar( &msgOut[12+i], data[i] );
	}	
	
	// Send the message
	if( send( s, msgOut, numBytes + 12, 0) < 0)
	{
		return -1;
	}
	
	//Receive a reply from the server
	int recv_size; // number of bytes that were received
	if((recv_size = recv( s, msgOut, numBytes, 0)) == -1)
	{
		return -2;
	}
	
	if (( recv_size == 1 ) && ( msgOut[0] == 0x06 ))
	{
		return 1; // success
	}
	else
	{
		return -3;
	}
}

int checkPMAC_endianness( int s )
{
	uint32_t magic_no = 1234;

	uint32_t val = htole32(magic_no);
	int set = setDataOnPowerPMAC( s, 8, sizeof(magic_no), (void *)&val );	
	if (set < 0)
		return -1;
	
	uint32_t test = getVarFromPowerPMAC( s, "reservedReadAddress", strlen("reservedReadAddress") );
	
	if ( test == val )
		return __ORDER_LITTLE_ENDIAN__;
		
	if ( test ==  htobe32(magic_no) )
		return __ORDER_BIG_ENDIAN__;
		
	return test;	
}





