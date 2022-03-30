#ifndef _COMMS_H_
#define _COMMS_H_

#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#include "network_utils.h"

#ifdef __cplusplus
extern "C" {
#endif

// Function prototypes
int requestDataFromPowerPMAC(int s, uint32_t address, uint32_t numBytes, unsigned char *const reply);
int getVarFromPowerPMAC(int s, char *const var_name, uint32_t name_length);
int setDataOnPowerPMAC(int s, uint32_t address, uint32_t numBytes, unsigned char *const data);
int checkPMAC_endianness( int s );

#ifdef __cplusplus
}
#endif

#endif
