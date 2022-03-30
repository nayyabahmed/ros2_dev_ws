#ifndef _DRIVERLESS_STRUCT_H
#define _DRIVERLESS_STRUCT_H

#include <stdint.h>

typedef struct tagWriteData
{
	unsigned long long Header;
	unsigned char AutonomousCommand; 
	unsigned char AutonomousCommandExtra;
	unsigned short AutonomousWD;
	float ManualSteer;
	float ManualThrottle;
} DWRITEDATA;

typedef struct tagWriteData_v2
{
	unsigned long long Header;
	unsigned char AutonomousCommand; 
	unsigned char AutonomousCommandExtra;
	unsigned short AutonomousWD;
	unsigned char OverrideSpeed;
	signed char SetOverrideSpeed;
	//unsigned char SCval;
	float ManualSteer;
	float ManualThrottle;
} DWRITEDATA_v2;

typedef struct tagWDOnlyData
{
	unsigned long long Header;
	unsigned short AutonomousWD;
} DWDONLYDATA;

typedef struct tagMap1Data
{
	unsigned short SyncCode; 
	unsigned short BoundaryLines; 
	unsigned char Island1Lines;
	unsigned char Island2Lines;
	unsigned short SpareW;
	float XNode[32];
	float YNode[32];
} DMAP1DATA;

typedef struct tagMap2Data
{
	unsigned short ExitPathPoints; 
	unsigned short EntryPathPoints; 
	unsigned short ExitPoint; 
	unsigned short EntryPoint; 
	float MaxX;
	float MinX;
	float MaxY;
	float MinY;
	unsigned long Points;
	long LongInt;
	float LongFract;
	long LatInt;
	float LatFract;
	float XAxisBearing;
	float RefHeight;
	float FwdShift;
	float WheelBase;
	float AccelDist;
	float VehicleLength;
	float VehicleWidth;
	float FrontOverhang;
	float SpeedMultiplier;
	float KdistCorrection;
	unsigned long LapTime;
	float DistanceStep;
} DMAP2DATA;

typedef struct tagMap3Data
{
	float LeadInAccel;
	float LeadInDecel;
	float ParallelOffsetRate;
	float RefPointX;
	float RefPointY;
	unsigned char DoBoundaryChecking;
	unsigned long ImageMapCollisionCheckCode;
} DMAP3DATA;

typedef struct tagReportDatav8p0
{
	unsigned char AutonomousStatus;
	unsigned char SyncModeRangeMode;
	unsigned short SecondStatus;
	unsigned short ErrorState;
	unsigned short ErrorStateB;
	unsigned short ErrorStateC;
	unsigned short ErrorStateD;
	unsigned char TestState;
	unsigned char SpareB;
	unsigned short SpareW;
	unsigned short DetailedStatus;
	short Laps;
	float XPosition;
	float YPosition;
	float YawAngle;
	float Speed;
	float SRAngle;
	float BRForce;
	float ARPos;
	long LatInt;
	float LatFract;
	long LongInt;
	float LongFract;
	short StartError;
	unsigned short TestPathIndex;
	long GPSTime;
	unsigned short SafetyControllerState;
	unsigned short CBARState;
	unsigned short CANExternalComms;
	unsigned short SubGroupIndex;
	unsigned short SafetyControllerError;
	unsigned short TestDataLoaded;
	unsigned short VehicleStatusY;
	unsigned short VehicleStatusX;
	float YawRate;
	float DistanceTravelled;
	float EmergencyDecelDist;
} DREPORTDATAv8p0;

typedef struct tagReportData
{
	unsigned char AutonomousStatus;
	unsigned char SyncModeRangeMode;
	unsigned short SecondStatus;
	unsigned short ErrorState;
	unsigned short ErrorStateB;
	unsigned short ErrorStateC;
	unsigned short ErrorStateD;
	unsigned char TestState;
	unsigned char SpareB;
	unsigned short SpareW;
	unsigned short DetailedStatus;
	short Laps;
	float XPosition;
	float YPosition;
	float YawAngle;
	float Speed;
	float SRAngle;
	float BRForce;
	float ARPos;
	long LatInt;
	float LatFract;
	long LongInt;
	float LongFract;
	short StartError;
	unsigned short TestPathIndex;
	long GPSTime;
	unsigned short SafetyControllerState;
	unsigned short CBARState;
	unsigned short CANExternalComms;
	unsigned short SubGroupIndex;
	unsigned short SafetyControllerError;
	unsigned short TestDataLoaded;
	unsigned short VehicleStatusY;
	unsigned short VehicleStatusX;
	float YawRate;
	float DistanceTravelled;
	float EmergencyDecelDist;
	float LookAheadDistance;
	long ControlPhase;
	int32_t TestPhase;
} DREPORTDATA;

typedef struct tagRestartData // added EntryDist for v8.2.0
{
	unsigned short RobotMode;
	unsigned short SpareW; 
	float RestartX;
	float RestartY;
	float RestartAng;
	float RestartXDist;
	float SpeedRestartX;
	float SpeedRestartY;
	float SpeedRestartAng;
	float CoeffA;
	float CoeffB;
	float AccelDistEther;
	float SpeedEntryPointTime;
	float LeadInTime;
	float EntryDist;
} DRESTARTDATA;

typedef struct tagDesiredRestartData
{
	uint64_t Header;
	float RestartDistance;
	uint16_t TestPathIndex;
	uint16_t SubGroupIndex;
} DDESIREDRESTARTDATA;

typedef struct tagGPSOffsetData
{
	uint64_t Header;
	int32_t GPSStartTime; // seconds since midnight of start time
    int32_t GPSStartTimeOffset;
    int32_t SyncTimeDifference; // no longer needed
} DGPSOFFSETDATA;

typedef struct tagGPSTimeData
{
	uint64_t Header;
	int32_t GPSTime;
} DGPSTIMEDATA;

#endif
