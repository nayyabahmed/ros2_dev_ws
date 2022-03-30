#ifndef _PF_STRUCTURE_H_
#define _PF_STRUCTURE_H_

#include <stdint.h>

#define TEST_TYPE_OPENLOOP -3
#define TEST_TYPE_AUTO_DIR -2
#define TEST_TYPE_RELATIVE -1
#define TEST_TYPE_STANDARD 0

//-----------------------------------------------------------
// Shared structures with robot code. For backward compatability, structures are suffixed by the robot pmStructVerNum.
// The variable pmStructVerNum is discovered in the robot info broadcast packet.

// User-code seems to align on 4-byte boundaries. Kernel-code seems to align
// on 8-byte boundaries. We need to make sure memory mapped structures are the
// same layout in each space. Use padding as necessary. Ordering members in
// decreasing size should help and create smallest record size.

#define PATH_LOCATION 60000

// Header for Group (128 bytes)
// Version 0, Version 1
typedef struct
{
	unsigned int FirstTestOffset;					// Calc: Address offset of test array (type tTestData)
	unsigned int FirstDriverlessOffset;				// Calc: Address offset of driverless array (type tDriverlessData) (0 if not driverless)
	unsigned int FirstReturnPathOffset;				// Calc: Address offset of return path array (type tReturnPathData)
	unsigned int FirstSegmentOffset;				// Calc: Address offset of segment array (type tSegmentData)
	unsigned int FirstBSplineOffset;				// Calc: Address offset of spline array (type tSplineData) - Only for type 4 segments
	unsigned int FirstCritSectOffset;				// Calc: Address offset of critical section array (type tCritSectData)
	unsigned int FirstTransitionOffset;				// Calc: Address offset of transition array (type tTransitionData)
	unsigned int FirstSROffset;						// Calc: Address offset of SR array (block size SRBLOCKSIZE for copying into ptr var area)
	unsigned int FirstGenOffset;					// Calc: Address offset of Gen array (block size GENBLOCKSIZE for copying into ptr var area)
	unsigned int FirstBROffset;						// Calc: Address offset of BR array (block size BRBLOCKSIZE for copying into ptr var area)
	unsigned int FirstAROffset;						// Calc: Address offset of AR array (block size ARBLOCKSIZE for copying into ptr var area)
	unsigned int nSRUserPoints;						// Calc: Total for tracking and debug
	unsigned int nBRUserPoints;						// Calc: Total for tracking and debug
	unsigned int nARUserPoints;						// Calc: Total for tracking and debug
	unsigned int FirstSRUserFIndex;					// Calc: Index in FData of first SR user point. The test FIndex will be an offset from this in PF mode
	unsigned int FirstBRUserFIndex;					// Calc: Index in FData of first BR user point. The test FIndex will be an offset from this in PF mode
	unsigned int FirstARUserFIndex;					// Calc: Index in FData of first AR user point. The test FIndex will be an offset from this in PF mode
	unsigned int FirstBRStartCycleTriggerFIndex;	// Calc: Index in FData of first BR start cycle trigger. The test FIndex will be an offset from this in PF mode
	unsigned int FirstARStartCycleTriggerFIndex;	// Calc: Index in FData of first AR start cycle trigger. The test FIndex will be an offset from this in PF mode
	unsigned int FirstAREndCycleTriggerFIndex;		// Calc: Index in FData of first AR end cycle trigger. The test FIndex will be an offset from this in PF mode
	unsigned int FirstARAmpCycleFIndex;				// Calc: Index in FData of first AR amp cycle. The test FIndex will be an offset from this in PF mode
	unsigned int FirstARDwellCycleFIndex;			// Calc: Index in FData of first AR dwell cycle. The test FIndex will be an offset from this in PF mode
	unsigned short Type;							// File: Group type
	unsigned short nSubGroups;						// File: No of subgroups
	unsigned short nReturnPaths;					// File: No of return paths
	unsigned short RunNumber;						// File: For data capture use
	unsigned short VehicleID;						// File: For data capture use
	unsigned short DriverlessTrue;					// File: Are we driverless
	unsigned short LongPosRef;						// File: Location on vehicle for longitudinal timing
	unsigned short nTests;							// Calc: Total for tracking and debug
	unsigned short nSegments;						// Calc: Total for tracking and debug
	unsigned short nBSpoints;						// Calc: Total for tracking and debug
	short nCriticalSections;						// Calc: Total for tracking and debug (critical section index logic uses negative numbers)
	short nTransitions;								// Calc: Total for tracking and debug (transition index has to take negative numbers - so this halves the number of transitions possible)
	unsigned short nBRStartCycleTriggers;			// Calc: Total for tracking and debug
	unsigned short nARStartCycleTriggers;			// Calc: Total for tracking and debug
	unsigned short nAREndCycleTriggers;				// Calc: Total for tracking and debug
	unsigned short nARAmpCycles;					// Calc: Total for tracking and debug
	unsigned short nARDwellCycles;					// Calc: Total for tracking and debug
	short dummy[3];									// Pad
} _GROUPDATA_0;

// Header for Group (136 bytes)
// Version 2
typedef struct
{
	float StartXoffset;								// File: Reserved for future use to show ideal vehicle location before test start
	float StartYoffset;								// File: ditto
	float StartHeadingOffset;						// File: ditto
	unsigned int FirstTestOffset;					// Calc: Address offset of test array (type tTestData)
	unsigned int FirstDriverlessOffset;				// Calc: Address offset of driverless array (type tDriverlessData) (0 if not driverless)
	unsigned int FirstReturnPathOffset;				// Calc: Address offset of return path array (type tReturnPathData)
	unsigned int FirstSegmentOffset;				// Calc: Address offset of segment array (type tSegmentData)
	unsigned int FirstBSplineOffset;				// Calc: Address offset of spline array (type tSplineData) - Only for type 4 segments
	unsigned int FirstCritSectOffset;				// Calc: Address offset of critical section array (type tCritSectData)
	unsigned int FirstTransitionOffset;				// Calc: Address offset of transition array (type tTransitionData)
	unsigned int FirstSROffset;						// Calc: Address offset of SR array (block size SRBLOCKSIZE for copying into ptr var area)
	unsigned int FirstGenOffset;					// Calc: Address offset of Gen array (block size GENBLOCKSIZE for copying into ptr var area)
	unsigned int FirstBROffset;						// Calc: Address offset of BR array (block size BRBLOCKSIZE for copying into ptr var area)
	unsigned int FirstAROffset;						// Calc: Address offset of AR array (block size ARBLOCKSIZE for copying into ptr var area)
	unsigned int nSRUserPoints;						// Calc: Total for tracking and debug
	unsigned int nBRUserPoints;						// Calc: Total for tracking and debug
	unsigned int nARUserPoints;						// Calc: Total for tracking and debug
	unsigned int FirstSRUserFIndex;					// Calc: Index in FData of first SR user point. The test FIndex will be an offset from this in PF mode
	unsigned int FirstBRUserFIndex;					// Calc: Index in FData of first BR user point. The test FIndex will be an offset from this in PF mode
	unsigned int FirstARUserFIndex;					// Calc: Index in FData of first AR user point. The test FIndex will be an offset from this in PF mode
	unsigned int FirstBRStartCycleTriggerFIndex;	// Calc: Index in FData of first BR start cycle trigger. The test FIndex will be an offset from this in PF mode
	unsigned int FirstARStartCycleTriggerFIndex;	// Calc: Index in FData of first AR start cycle trigger. The test FIndex will be an offset from this in PF mode
	unsigned int FirstAREndCycleTriggerFIndex;		// Calc: Index in FData of first AR end cycle trigger. The test FIndex will be an offset from this in PF mode
	unsigned int FirstARAmpCycleFIndex;				// Calc: Index in FData of first AR amp cycle. The test FIndex will be an offset from this in PF mode
	unsigned int FirstARDwellCycleFIndex;			// Calc: Index in FData of first AR dwell cycle. The test FIndex will be an offset from this in PF mode
	unsigned short Type;							// File: Group type
	unsigned short nSubGroups;						// File: No of subgroups
	unsigned short nReturnPaths;					// File: No of return paths
	unsigned short RunNumber;						// File: For data capture use
	unsigned short VehicleID;						// File: For data capture use
	unsigned short DriverlessTrue;					// File: Are we driverless
	unsigned short LongPosRef;						// File: Location on vehicle for longitudinal timing
	unsigned short nTests;							// Calc: Total for tracking and debug
	unsigned short nSegments;						// Calc: Total for tracking and debug
	unsigned short nBSpoints;						// Calc: Total for tracking and debug
	short nCriticalSections;						// Calc: Total for tracking and debug (critical section index logic uses negative numbers)
	short nTransitions;								// Calc: Total for tracking and debug (transition index has to take negative numbers - so this halves the number of transitions possible)
	unsigned short nBRStartCycleTriggers;			// Calc: Total for tracking and debug
	unsigned short nARStartCycleTriggers;			// Calc: Total for tracking and debug
	unsigned short nAREndCycleTriggers;				// Calc: Total for tracking and debug
	unsigned short nARAmpCycles;					// Calc: Total for tracking and debug
	unsigned short nARDwellCycles;					// Calc: Total for tracking and debug
	short dummy[1];									// Pad
} _GROUPDATA_2;

// Header for Group (168 bytes)
// Version 4, 5
typedef struct
{
	float GroupShiftX;								// File: Metres path data is shifted in the X direction
	float GroupShiftY;								// File: Metres path data is shifted in the Y direction
	float GroupRotCos;								// File: Direction cosine in the X direction for rotating the path data
	float GroupRotSin;								// File: Direction cosine in the Y direction for rotating the path data
	float StartXoffset;								// File: Reserved for future use to show ideal vehicle location before test start
	float StartYoffset;								// File: ditto
	float StartHeadingOffset;						// File: ditto
	float HighwayMaxLateralOffsetLeft;				// File: Maximum left lateral offset allowed from the path for a Highway
	float HighwayMaxLateralOffsetRight;				// File: Maximum right lateral offset allowed from the path for a Highway
	unsigned int FirstTestOffset;					// Calc: Address offset of test array (type tTestData)
	unsigned int FirstDriverlessOffset;				// Calc: Address offset of driverless array (type tDriverlessData) (0 if not driverless)
	unsigned int FirstReturnPathOffset;				// Calc: Address offset of return path array (type tReturnPathData)
	unsigned int FirstSegmentOffset;				// Calc: Address offset of segment array (type tSegmentData)
	unsigned int FirstBSplineOffset;				// Calc: Address offset of spline array (type tSplineData) - Only for type 4 segments
	unsigned int FirstCritSectOffset;				// Calc: Address offset of critical section array (type tCritSectData)
	unsigned int FirstTransitionOffset;				// Calc: Address offset of transition array (type tTransitionData)
	unsigned int FirstSROffset;						// Calc: Address offset of SR array (block size SRBLOCKSIZE for copying into ptr var area)
	unsigned int FirstGenOffset;					// Calc: Address offset of Gen array (block size GENBLOCKSIZE for copying into ptr var area)
	unsigned int FirstBROffset;						// Calc: Address offset of BR array (block size BRBLOCKSIZE for copying into ptr var area)
	unsigned int FirstAROffset;						// Calc: Address offset of AR array (block size ARBLOCKSIZE for copying into ptr var area)
	unsigned int nSRUserPoints;						// Calc: Total for tracking and debug
	unsigned int nBRUserPoints;						// Calc: Total for tracking and debug
	unsigned int nARUserPoints;						// Calc: Total for tracking and debug
	unsigned int FirstSRUserFIndex;					// Calc: Index in FData of first SR user point. The test FIndex will be an offset from this in PF mode
	unsigned int FirstBRUserFIndex;					// Calc: Index in FData of first BR user point. The test FIndex will be an offset from this in PF mode
	unsigned int FirstARUserFIndex;					// Calc: Index in FData of first AR user point. The test FIndex will be an offset from this in PF mode
	unsigned int FirstBRStartCycleTriggerFIndex;	// Calc: Index in FData of first BR start cycle trigger. The test FIndex will be an offset from this in PF mode
	unsigned int FirstARStartCycleTriggerFIndex;	// Calc: Index in FData of first AR start cycle trigger. The test FIndex will be an offset from this in PF mode
	unsigned int FirstAREndCycleTriggerFIndex;		// Calc: Index in FData of first AR end cycle trigger. The test FIndex will be an offset from this in PF mode
	unsigned int FirstARAmpCycleFIndex;				// Calc: Index in FData of first AR amp cycle. The test FIndex will be an offset from this in PF mode
	unsigned int FirstARDwellCycleFIndex;			// Calc: Index in FData of first AR dwell cycle. The test FIndex will be an offset from this in PF mode
	unsigned short Type;							// File: Group type
	unsigned short nSubGroups;						// File: No of subgroups
	unsigned short nReturnPaths;					// File: No of return paths
	unsigned short RunNumber;						// File: For data capture use
	unsigned short VehicleID;						// File: For data capture use
	unsigned short DriverlessTrue;					// File: Are we driverless
	unsigned short LongPosRef;						// File: Location on vehicle for longitudinal timing
	unsigned short nTests;							// Calc: Total for tracking and debug
	unsigned short nSegments;						// Calc: Total for tracking and debug
	unsigned short nBSpoints;						// Calc: Total for tracking and debug
	short nCriticalSections;						// Calc: Total for tracking and debug (critical section index logic uses negative numbers)
	short nTransitions;								// Calc: Total for tracking and debug (transition index has to take negative numbers - so this halves the number of transitions possible)
	unsigned short nBRStartCycleTriggers;			// Calc: Total for tracking and debug
	unsigned short nARStartCycleTriggers;			// Calc: Total for tracking and debug
	unsigned short nAREndCycleTriggers;				// Calc: Total for tracking and debug
	unsigned short nARAmpCycles;					// Calc: Total for tracking and debug
	unsigned short nARDwellCycles;					// Calc: Total for tracking and debug
	unsigned short InitialSrProgram;				// File: 1007 => no SR open-loop test, otherwise this holds the test type number 10xx
	unsigned short InitialBrProgram;				// File: This holds the test type number 10xx (must always have a valid 102x value)
	unsigned short InitialArProgram;				// File
	unsigned short dummyShort;						// Pad
	uint8_t UseHighwayScenario;						// File
	uint8_t dummyChar[1];							// Pad
}_GROUPDATA_4;


// Header for Sub-Groups (32 bytes)
// Version 0
typedef struct
{
	float TransitTime;				// File: To be resolved whether this is needed (could be calculated by pre-processing)
	float MaxSWA;					// File: Steering wheel angle (both turns) [set in test in UMAC]
	float MaxSWV;					// File: Steering wheel velocity (both turns) [set in test in UMAC]
	float MaxSWAcc;					// File: Steering wheel accel (both turns) [set in test in UMAC]
	float MaxLateralError;			// File: [set in vehicle in UMAC]
	float MaxLongitudinalError;		// File: [set in vehicle in UMAC]
	short Type;						// File: Sub group type (single pass or multiple loops)
	unsigned short nTests;			// File: No of tests
	unsigned short FirstTestIndex;	// Calc: Position in full list of tests for the first test of this sub-group
	unsigned short nReturnPaths;	// File: No of return paths
} _SUBGROUPDATA_0;

// Header for Sub-Groups (40 bytes)
// Version 1
typedef struct
{
	float TransitTime;						// File: To be resolved whether this is needed (could be calculated by pre-processing)
	float MaxSWA;							// File: Steering wheel angle (both turns) [set in test in UMAC]
	float MaxSWV;							// File: Steering wheel velocity (both turns) [set in test in UMAC]
	float MaxSWAcc;							// File: Steering wheel accel (both turns) [set in test in UMAC]
	float MaxLateralError;					// File: [set in vehicle in UMAC]
	float MaxLongitudinalError;				// File: [set in vehicle in UMAC]
	short Type;								// File: Sub group type (single pass or multiple loops)
	unsigned short nTests;					// File: No of tests
	unsigned short FirstTestIndex;			// Calc: Position in full list of tests for the first test of this sub-group
	unsigned short nReturnPaths;			// File: No of return paths
	unsigned short TotalCircuitsComplete;	// RT: logs the total number of times this sub-group has been repeated in this session (the sub-group may have been repeatedly entered in a Power Sequence)
	short dummy[3];
} _SUBGROUPDATA_1;

// Header for Sub-Groups (64 bytes)
// Version 2,4,5
typedef struct
{
	double pathRelativeOffsetX;				// RT: Normally zero unless it's a relative sub-group
	double pathRelativeOffsetY;				// RT: Normally zero unless it's a relative sub-group
	float pathRelativeSin;					// RT: Normally zero unless it's a relative sub-group
	float pathRelativeCos;					// RT: Normally zero unless it's a relative sub-group
	float TransitTime;						// File: Not currently used
	float MaxSWA;							// File: Steering wheel angle (both turns) [set in test in UMAC]
	float MaxSWV;							// File: Steering wheel velocity (both turns) [set in test in UMAC]
	float MaxSWAcc;							// File: Steering wheel accel (both turns) [set in test in UMAC]
	float MaxLateralError;					// File: [set in vehicle in UMAC]
	float MaxLongitudinalError;				// File: [set in vehicle in UMAC]
	short Type;								// File: Sub group type (single pass or multiple loops, Type < 0 => relative sub-group)
	unsigned short nTests;					// File: No of tests
	unsigned short FirstTestIndex;			// Calc: Position in full list of tests for the first test of this sub-group
	unsigned short nReturnPaths;			// File: No of return paths
	unsigned short TotalCircuitsComplete;	// RT: logs the total number of times this sub-group has been repeated in this session (the sub-group may have been repeatedly entered in a Power Sequence)
	short dummy[3];
} _SUBGROUPDATA_2;

// Header for Tests (144 bytes)
// Version 0
typedef struct
{
	double StartTriggerVal;				// File
	double StartTimeOffset;				// File
	double InitialTransitionLocation;	// File: Maximum allowed entry distance (0 => enter at start of path only)
	double PathExitTriggerVal;			// File
	double TriggeredExitLocation;		// File: Distance from start of path
	double TriggeredExitTime;			// Calc: Time from start of path
	double PathAbortTriggerVal;			// File
	double InitialDist;					// File - NOT CURRENTLY USED
	double Length;						// File
	double TransitTime;					// File
	unsigned short TestID;				// File: For data capture use
	short Type;							// File: Test type (can be negative) - single pass, lap, relative, open-loop only, auto direction etc...
	unsigned short SyncCode;			// File
	unsigned short nSegments;			// File
	unsigned short nCriticalSections;	// File
	short Layer;						// File
	short StartTriggerChan;				// File
	short PathExitTriggerChan;			// File
	short PathAbortTriggerChan;			// File 
	unsigned short SRtestProg;			// File: 0 => no SR open-loop test, otherwise this holds the test type number 10xx
	unsigned short BRtestProg;			// File: This holds the test type number 10xx (must always have a valid 102x value)
	unsigned short ARtestProg;			// File
	short NormalExitIndex;				// File: Index into array of transition structures (-1 for no associated cubic transition)  *************************************??? -1 for end, 0 for next path without transition, +ve for a pre-defined transition
	short TriggeredExitIndex;			// File: Index into array of transition structures (-1 for no associated cubic transition)  *************************************??? -1 for end, 0 for next path without transition, +ve for a pre-defined transition
	unsigned short FirstSegmentIndex;	// Calc: Position in full list of segments for the first segment of this test
	unsigned short FirstCritSectIndex;	// Calc: Position in full list of CSs for the first CS of this test
	unsigned short SRTestIndex;			// Calc: Position in list of SR test definitions
	unsigned short BRTestIndex;			// Calc: Position in list of BR test definitions
	unsigned short ARTestIndex;			// Calc: Position in list of AR test definitions
	unsigned short GenTestIndex;		// Calc: Position in list of general test definitions
	unsigned short NoTTTrigReset;				// File: First bit from GenSpecialFlag
	unsigned short DataCaptureFreq;		// File: Data capture frequency for test
	short FinalLapNum;					// RT: shows exit lap when triggered so that all points exit on the same lap (can be needed with short lap transitions)
	short dummy3;						// Pad
	short BRProgFromLastTest;			// File: First bit from BRSpecialInhibitFlag
	short BRInhibitStart;				// File: Second bit from BRSpecialInhibitFlag
	short BRInhibitEnd;					// File: Third bit from BRSpecialInhibitFlag
	short ARProgFromLastTest;			// File: First bit from ARSpecialInhibitFlag
	short ARInhibitStart;				// File: Second bit from ARSpecialInhibitFlag
	short ARInhibitEnd;					// File: Third bit from ARSpecialInhibitFlag
	short ARInhibitSCAbort;				// File: Fourth bit from ARSpecialInhibitFlag
	char ExitTrigTrue;					// RT: Shows that the trigger to leave at the branching exit has been activated (using a flagging system for each vehicle location)
	char DBSexitTrigTrue;				// RT by DBS: Shows that DBS commands to leave at the branching exit
} _TESTDATA_0;

// Header for Tests (144 bytes)
// Version 1
typedef struct
{
	double StartTriggerVal;				// File
	double StartTimeOffset;				// File
	double InitialTransitionLocation;	// File: Maximum allowed entry distance (0 => enter at start of path only)
	double PathExitTriggerVal;			// File
	double TriggeredExitLocation;		// File: Distance from start of path
	double TriggeredExitTime;			// Calc: Time from start of path
	double PathAbortTriggerVal;			// File
	double InitialDist;					// File - NOT CURRENTLY USED
	double Length;						// File
	double TransitTime;					// File
	unsigned short TestID;				// File: For data capture use
	short Type;							// File: Test type (can be negative) - single pass, lap, relative, open-loop only, auto direction etc...
	unsigned short SyncCode;			// File
	unsigned short nSegments;			// File
	unsigned short nCriticalSections;	// File
	short Layer;						// File
	short StartTriggerChan;				// File
	short PathExitTriggerChan;			// File
	short PathAbortTriggerChan;			// File 
	unsigned short SRtestProg;			// File: 0 => no SR open-loop test, otherwise this holds the test type number 10xx
	unsigned short BRtestProg;			// File: This holds the test type number 10xx (must always have a valid 102x value)
	unsigned short ARtestProg;			// File
	short NormalExitIndex;				// File: Index into array of transition structures (-1 for no associated cubic transition)  *************************************??? -1 for end, 0 for next path without transition, +ve for a pre-defined transition
	short TriggeredExitIndex;			// File: Index into array of transition structures (-1 for no associated cubic transition)  *************************************??? -1 for end, 0 for next path without transition, +ve for a pre-defined transition
	unsigned short FirstSegmentIndex;	// Calc: Position in full list of segments for the first segment of this test
	unsigned short FirstCritSectIndex;	// Calc: Position in full list of CSs for the first CS of this test
	unsigned short SRTestIndex;			// Calc: Position in list of SR test definitions
	unsigned short BRTestIndex;			// Calc: Position in list of BR test definitions
	unsigned short ARTestIndex;			// Calc: Position in list of AR test definitions
	unsigned short GenTestIndex;		// Calc: Position in list of general test definitions
	unsigned short NoTTTrigReset;		// File: First bit from GenSpecialFlag
	unsigned short DataCaptureFreq;		// File: Data capture frequency for test
	short BRProgFromLastTest;			// File: First bit from BRSpecialInhibitFlag
	short BRInhibitStart;				// File: Second bit from BRSpecialInhibitFlag
	short BRInhibitEnd;					// File: Third bit from BRSpecialInhibitFlag
	short ARProgFromLastTest;			// File: First bit from ARSpecialInhibitFlag
	short ARInhibitStart;				// File: Second bit from ARSpecialInhibitFlag
	short ARInhibitEnd;					// File: Third bit from ARSpecialInhibitFlag
	short ARInhibitSCAbort;				// File: Fourth bit from ARSpecialInhibitFlag
	short FinalLapsRemaining;			// RT: shows exit lap when triggered so that all points exit on the same lap (can be needed with short lap transitions)
	unsigned short TotalPassesComplete;	// RT: logs the total number of times this path has been repeated in this session (individual full laps for a lap test)
	char ExitTrigTrue;					// RT: Shows that the trigger to leave at the branching exit has been activated (using a flagging system for each vehicle location)
	char DBSexitTrigTrue;				// RT by DBS: Shows that DBS commands to leave at the branching exit
} _TESTDATA_1;

// Header for Tests (160 bytes)
// Version 2,4
typedef struct
{
       double StartTriggerVal;                         // File
       double StartTimeOffset;                         // File
       double InitialTransitionLocation; // File: Maximum allowed entry distance (0 => enter at start of path only)
       double PathExitTriggerVal;               // File: legacy use only if PF file version < 6 (for copying data from PF test to transition) - should be removed at the next major code version change
       double TriggeredExitLocation;            // Calc: Distance from start of path - now copied from transition that's being used
       double TriggeredExitTime;                // Calc: Time from start of path
       double PathAbortTriggerVal;              // File
       double InitialDist;                             // File - NOT CURRENTLY USED
       double Length;                                         // File
       double TransitTime;                             // File
       double FinalXlocation;                          // File: for data integrity checks
       double FinalYlocation;                          // File: for data integrity checks
       unsigned short TestID;                          // File: For data capture use
       short Type;                                            // File: Test type (can be negative) - single pass, lap, relative, open-loop only, auto direction etc...
       unsigned short SyncCode;                 // File
       unsigned short nSegments;                // File
       unsigned short nCriticalSections; // File
       short Layer;                                    // File 
       short StartTriggerChan;                         // File
       short PathExitTriggerChan;               // File: legacy use only (for copying data from PF test to transition) - should be removed at the next major code version change
       short PathAbortTriggerChan;              // File 
       unsigned short SRtestProg;               // File: 0 => no SR open-loop test, otherwise this holds the test type number 10xx
       unsigned short BRtestProg;               // File: This holds the test type number 10xx (must always have a valid 102x value)
       unsigned short ARtestProg;               // File
       short NormalExitIndex;                          // File: Index into array of transition structures, -1 for end, +ve for a pre-defined transition
       short FirstTriggeredExitIndex;           // File: Index into array of transition structures (-1 for no triggered exits, +ve for first pre-defined transition)
       unsigned short nTriggeredExits;          // File
       unsigned short FirstSegmentIndex; // Calc: Position in full list of segments for the first segment of this test
       unsigned short FirstCritSectIndex; // Calc: Position in full list of CSs for the first CS of this test
       unsigned short SRTestIndex;              // Calc: Position in list of SR test definitions
       unsigned short BRTestIndex;              // Calc: Position in list of BR test definitions
       unsigned short ARTestIndex;              // Calc: Position in list of AR test definitions
       unsigned short GenTestIndex;             // Calc: Position in list of general test definitions
       unsigned short DataCaptureFreq;          // File: Data capture frequency for test
       unsigned short TotalPassesComplete;      // RT: logs the total number of times this path has been repeated in this session (individual full laps for a lap test)
       short ActualTriggeredExitIndex;          // RT: the index of the triggered exit currently to be used (more than one could have been triggered - but this is the one that will currently be used)
       short FinalLapsRemaining;                // RT: shows exit lap when triggered so that all points exit on the same lap (can be needed with short lap transitions) - can go negative on exit lap
       int8_t NoTTTrigReset;                           // File: First bit from GenSpecialFlag
       int8_t BRProgFromLastTest;               // File: First bit from BRSpecialInhibitFlag
       int8_t BRInhibitStart;                          // File: Second bit from BRSpecialInhibitFlag
       int8_t BRInhibitEnd;                     // File: Third bit from BRSpecialInhibitFlag
       int8_t ARProgFromLastTest;               // File: First bit from ARSpecialInhibitFlag
       int8_t ARInhibitStart;                          // File: Second bit from ARSpecialInhibitFlag
       int8_t ARInhibitEnd;                     // File: Third bit from ARSpecialInhibitFlag
       int8_t ARInhibitSCAbort;                 // File: Fourth bit from ARSpecialInhibitFlag
       uint8_t ExitTrigTrue;                           // RT: Shows that the trigger to leave at the branching exit has been activated (using a flagging system for each vehicle location)
       char dummyChar[5];
} _TESTDATA_2;

// Header for Tests (168 bytes)
// Version 5
typedef struct
{
	double StartTriggerVal;				// File
	double StartTimeOffset;				// File / 28-4-20 Calc (done in PPMAC as RC does not set this for each test) - really means InitialTime to mirror InitialDist
	double InitialTransitionLocation;	// File: Maximum allowed entry distance (0 => enter at start of path only)
	double PathExitTriggerVal;			// File: legacy use only if PF file version < 6 (for copying data from PF test to transition) - should be removed at the next major code version change
	double TriggeredExitLocation;		// Calc: Distance from start of path - now copied from transition that's being used
	double TriggeredExitTime;			// Calc: Time from start of path
	double PathAbortTriggerVal;			// File
	double InitialDist;					// Calc (done in PPMAC as RC does not set this!)
	double Length;						// File
	double TransitTime;					// File
	double FinalXlocation;				// File: for data integrity checks
	double FinalYlocation;				// File: for data integrity checks
	double POIdistance;					// File: version 8 onwards - distance to target POI on path for time to here calculation
	uint16_t TestID;					// File: For data capture use
	int16_t Type;						// File: Test type (can be negative) - single pass, lap, relative, open-loop only, auto direction etc...
	uint16_t SyncCode;					// File
	uint16_t nSegments;					// File
	uint16_t nCriticalSections;			// File
	int16_t Layer;						// File 
	int16_t StartTriggerChan;			// File
	int16_t PathExitTriggerChan;		// File: legacy use only (for copying data from PF test to transition) - should be removed at the next major code version change
	int16_t PathAbortTriggerChan;		// File 
	uint16_t SRtestProg;				// File: 0 => no SR open-loop test, otherwise this holds the test type number 10xx
	uint16_t BRtestProg;				// File: This holds the test type number 10xx (must always have a valid 102x value)
	uint16_t ARtestProg;				// File
	int16_t NormalExitIndex;			// File: Index into array of transition structures, -1 for end, +ve for a pre-defined transition
	int16_t FirstTriggeredExitIndex;	// File: Index into array of transition structures (-1 for no triggered exits, +ve for first pre-defined transition)
	uint16_t nTriggeredExits;			// File
	uint16_t FirstSegmentIndex;			// Calc: Position in full list of segments for the first segment of this test
	uint16_t FirstCritSectIndex;		// Calc: Position in full list of CSs for the first CS of this test
	uint16_t SRTestIndex;				// Calc: Position in list of SR test definitions
	uint16_t BRTestIndex;				// Calc: Position in list of BR test definitions
	uint16_t ARTestIndex;				// Calc: Position in list of AR test definitions
	uint16_t GenTestIndex;				// Calc: Position in list of general test definitions
	uint16_t DataCaptureFreq;			// File: Data capture frequency for test
	uint16_t TotalPassesComplete;		// RT: logs the total number of times this path has been repeated in this session (individual full laps for a lap test)
	int16_t ActualTriggeredExitIndex;	// RT: the index of the triggered exit currently to be used (more than one could have been triggered - but this is the one that will currently be used)
	int16_t FinalLapsRemaining;			// RT: shows exit lap when triggered so that all points exit on the same lap (can be needed with short lap transitions) - can go negative on exit lap
	uint16_t TTPOIdisableSeg;			// RT: shows last triggered stop point before POI (if there is one)
	int8_t NoTTTrigReset;				// File: First bit from GenSpecialFlag
	int8_t BRProgFromLastTest;			// File: First bit from BRSpecialInhibitFlag
	int8_t BRInhibitStart;				// File: Second bit from BRSpecialInhibitFlag
	int8_t BRInhibitEnd;				// File: Third bit from BRSpecialInhibitFlag
	int8_t ARProgFromLastTest;			// File: First bit from ARSpecialInhibitFlag
	int8_t ARInhibitStart;				// File: Second bit from ARSpecialInhibitFlag
	int8_t ARInhibitEnd;				// File: Third bit from ARSpecialInhibitFlag
	int8_t ARInhibitSCAbort;			// File: Fourth bit from ARSpecialInhibitFlag
	uint8_t ExitTrigTrue;				// RT: Shows that the trigger to leave at the branching exit has been activated (using a flagging system for each vehicle location)
	uint8_t dummyChar[3];
} _TESTDATA_5;

// Header for Driverless (48 bytes)
// Version 0, Version 1
typedef struct
{
	double TestBoundaryMinX;      // File
	double TestBoundaryMinY;      // File
	double TestBoundaryMaxX;      // File
	double TestBoundaryMaxY;      // File
	float TestSpeedLimit;         // File
	float ReturnSpeedLimit;       // File (was in return path structure)
	float ReturnMaxSWA;           // File (was in return path structure)
	short ReturnPathIndex;        // File: Position in full list of tests for this return path (-1 for no return path)
	short RemoteControlTrue;      // File: Use appropriate bits
} _DRIVERLESSDATA_0;

// Header for Driverless (32 bytes)
// Version 2, 4, 5
typedef struct
{
	float TestBoundaryMinX;      // File
	float TestBoundaryMinY;      // File
	float TestBoundaryMaxX;      // File
	float TestBoundaryMaxY;      // File
	float TestSpeedLimit;         // File
	float ReturnSpeedLimit;       // File (was in return path structure)
	float ReturnMaxSWA;           // File (was in return path structure)
	short ReturnPathIndex;        // File: Position in full list of tests for this return path (-1 for no return path)
	short RemoteControlTrue;      // File: Use appropriate bits
} _DRIVERLESSDATA_2;

// Header for Segments (120 bytes)
// Version 0, Version 1
typedef struct
{
	double InitialHeadingCos;		// File
	double InitialHeadingSin;		// File
	double InitialX;				// File
	double InitialY;				// File
	double Length;					// File
	double InitialTime;				// File
	double InitialDist;				// File
	double Radius;					// File
	double EndRadius;				// File
	double HoldTime;				// File
	double StartTriggerVal;			// File
	double InvPointDist;			// Calc
	double PointDist;				// Calc
	float InitialVel;				// File
	float FinalVel;					// File
	short Type;						// File
	unsigned short nPoints;			// File
	short StartTriggerChan;			// File
	unsigned short FirstBsplineIndex;	// Calc: Only for type 4 segments
} _SEGMENTDATA_0;

// Header for Segments (88 bytes)
// Version 2, 4, 5
typedef struct
{
	double InitialX;				// File
	double InitialY;				// File
	double InitialTime;				// File
	double InitialDist;				// File
	double StartTriggerVal;			// File
	float InitialHeadingCos;		// File
	float InitialHeadingSin;		// File
	float Length;					// File - limit to 5 km for resolution reasons
	float Radius;					// File
	float EndRadius;				// File
	float HoldTime;					// File
	float InvPointDist;				// Calc
	float PointDist;				// Calc
	float InitialVel;				// File
	float FinalVel;					// File
	short Type;						// File
	unsigned short nPoints;			// File
	short StartTriggerChan;			// File
	unsigned short FirstBsplineIndex;	// Calc: Only for type 4 segments
} _SEGMENTDATA_2;

// Header for B-Spline Points (3 extra points needed for each B-Spline, 1 before the start, 1 for the beginning copied from the header, 1 after the end) (32 bytes)
// point[0] is imaginary point calculated during pre-processing for pre-path - corresponds to the "FirstBsplineIndex" location
// point[1] is the point that marks the start of the spline (should be co-incident with end of previous segment) - it is a copy of the start X, Y positions of the header with T=0)
// point[2] is the first spline point transferred by the PC in the spline points list
// point[Parameter3+1] is the last real point (should be co-incident with start of next segment)
// point[Parameter3+2] is imaginary point calculated during pre-processing for post-path
// (24 bytes)
// Version 0, Version 1, Version 2, Version 4, Version 5
typedef struct
{
	double X;			// File
	double Y;			// File
	double Time;		// File
	float Velocity;		// File
	float dummy;		// Pad
} _SPLINEDATA_0;

// Header for Critical Sections (136 bytes)
// Version 0, Version 1
typedef struct
{
	double StartDistance;		// File
	double EndDistance;			// File
	float MaxLateralError;		// File
	float MinLateralError;		// File: Should be negative
	float MaxDistanceError;		// File
	float MinDistanceError;		// File: Should be negative
	float MaxSWA;				// File: Steering wheel angle (left turn)
	float MinSWA;				// File: Should be negative
	float MaxSWV;				// File: Steering wheel velocity (left turn)
	float MinSWV;				// File: Should be negative
	float SRabortParameter1;	// File
	float SRabortParameter2;	// File
	float SRabortParameter3;	// File
	float SRabortParameter4;	// File
	float ARabortDwellTime;		// File
	float BRabortDwellTime;		// File
	float ResetLengthVGR;		// File
	float SRgainVGR;			// ***new name (was SRparameterVGR - now split into SRgainVGR and SRangleVGR)
	float SRangleVGR;			// File (new use)
	float SRtorqueVGR;			// ***new
	float SRangleVelocityVGR;	// ***new
	float SRtorqueVelocityVGR;	// ***new
	float SRtorqueLimitVGR;		// ***new
	float ARparameterVGR;		// File
	float StartTriggerVal;		// ***new
	float EndTriggerVal;		// ***new
	short Type;					// File
	short GearPosition;			// File
	short SRabortMode;			// File
	short ARabortLevel;			// File: %
	short BRabortLevel;			// File: %
	short SRactionVGR;			// File
	short ARactionVGR;			// File
	short StartTriggerChan;		// ***new
	short EndTriggerChan;		// ***new
	short RestoreDistCtrlVGR;	// ***new
	short SRintegralActionVGR;	// ***new
	short dummy;				// Pad
} _CRITSECTDATA_0;

// Header for Critical Sections (128 bytes)
// Version 2, Version 4, Version 5
typedef struct
{
	double StartTriggerVal;		// ***new
	double EndTriggerVal;		// ***new
	float StartDistance;		// File
	float EndDistance;			// File
	float MaxLateralError;		// File
	float MinLateralError;		// File: Should be negative
	float MaxDistanceError;		// File
	float MinDistanceError;		// File: Should be negative
	float MaxSWA;				// File: Steering wheel angle (left turn)
	float MinSWA;				// File: Should be negative
	float MaxSWV;				// File: Steering wheel velocity (left turn)
	float MinSWV;				// File: Should be negative
	float SRabortParameter1;	// File
	float SRabortParameter2;	// File
	float SRabortParameter3;	// File
	float SRabortParameter4;	// File
	float ARabortDwellTime;		// File
	float BRabortDwellTime;		// File
	float ResetLengthVGR;		// File
	float SRgainVGR;			// ***new name (was SRparameterVGR - now split into SRgainVGR and SRangleVGR)
	float SRangleVGR;			// File (new use)
	float SRtorqueVGR;			// ***new
	float SRangleVelocityVGR;	// ***new
	float SRtorqueVelocityVGR;	// ***new
	float SRtorqueLimitVGR;		// ***new
	float ARparameterVGR;		// File
	short ARabortLevel;			// File: %
	short BRabortLevel;			// File: %
	short StartTriggerChan;		// ***new
	short EndTriggerChan;		// ***new
	int8_t GearPosition;			// File
	int8_t SRabortMode;			// File
	int8_t Type;					// File
	int8_t SRactionVGR;			// File
	int8_t ARactionVGR;			// File
	int8_t RestoreDistCtrlVGR;	// ***new
	int8_t SRintegralActionVGR;	// ***new
	char dummyChar;				// Pad
} _CRITSECTDATA_2;

// Header for Cubic Transitions (112 bytes)
// Version 0, Version 1
typedef struct
{
	double EntryPointDistance;					// File
	double LocalOriginX;						// File
	double LocalOriginY;						// File
	double LocalCos;							// File
	double LocalSin;							// File
	double CoeffA;								// File
	double CoeffB;								// File
	double InitialVel;							// File
	double Length;								// File
	double Accel;								// Calc: To reduce real-time calculations
	double SpeedEntryPointTime;					// Calc: Time when speed lead in joins path
	double TransitTime;							// File
	float FinalVel;								// File
	float FirstValidX;							// File: X position of start of cubic in local coordinate system (negative number)
	unsigned short DestinationSubGroupIndex;	// File
	unsigned short DestinationTestIndex;		// File
	short dummy[2];								// Pad
} _TRANSITIONDATA_0;

// Header for Cubic Transitions (112 bytes) - normal exits won't use the triggering parameters
// Version 2, Version 4, Version 5
typedef struct
{
	double LocalOriginX;					// File
	double LocalOriginY;					// File
	double EntryPointDistance;				// File
	double SpeedEntryPointTime;				// Calc: Time when speed lead in joins path
	double ExitTriggerVal;					// File: only relevant to triggered exits 
	double ExitLocation;					// File/Calc: Distance from start of path - relative triggered transitions calculated on-the-fly
	double CoeffA;							// File
	double CoeffB;							// File
	float LocalCos;							// File
	float LocalSin;							// File
	float Length;							// File
	float Accel;							// Calc: To reduce real-time calculations
	float TransitTime;						// File
	float InitialVel;						// File
	float FinalVel;							// File
	float FirstValidX;						// File: X position of start of cubic in local coordinate system (negative number)
	unsigned short DestinationSubGroupIndex;	// File
	unsigned short DestinationTestIndex;	// File
	short TrigChan;							// File
	short TrigRateVarNum;					// Calc
	short TrigOffsetVarNum;					// Calc
	int8_t TrigType;						// Calc
	int8_t TrigSense;						// Calc
	uint8_t TrigDigVal;						// Calc
	uint8_t TrigEnabled;					// Calc
	uint8_t TrigTrue;						// Calc/set externally - bit 0 trigger set internally, bits 1...5 external triggers, bit 6 is un-set trigger, bit 7 is latch state when re-entering the test using this exit transition
	int8_t TrigAbs;							// Calc
} _TRANSITIONDATA_2;

//Structures for Highway Scenarios---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//group highway scenario header (24 bytes) - space reserved in ushm for 1024 scenario headers
typedef struct
{
	uint32_t ID;						// File - reference number for scenario
	uint32_t BaselineScenarioOffset;	// Calc - Address offset for scenario structure
	uint32_t FirstLatSegOffset;			// Calc - Address offset for first lateral segment structure
	uint32_t FirstSpeedSegOffset;		// Calc - Address offset for first speed segment structure
	uint16_t nTrigScenarios;			// File
	uint16_t nLateralSegments;			// Calc: Total for tracking and debug
	uint16_t nSpeedSegments;			// Calc: Total for tracking and debug
	uint16_t dummy16;					// Spare - Pad
} tHighwayScenarioGroup;

//individual highway scenario header (64 bytes) - max 33 = 2112 bytes
typedef struct
{
	double StartTriggerVal;				// File
	double StartDistOffset;				// File / Calc - determined real-time for relative scenarios
	double StartTimeOffset;				// Calc - determined real-time for triggered speed scenarios
	float InitialLateralOffset;			// Calc - determined real-time for relative lateral scenarios
	float MaxExcursionLeft;				// Calc
	float MaxExcursionRight;			// Calc
	float dummy32;						// Pad
	uint16_t nLateralSegments;			// File
	uint16_t nSpeedSegments;			// File
	uint16_t FirstLateralSegIndex;		// Calc: Position in full list of segments for the first lateral offset segment of this scenario
	uint16_t FirstSpeedSegIndex;		// Calc: Position in full list of segments for the first lateral offset segment of this scenario
	int16_t StartTriggerChan;			// File
	int16_t TrigRateVarNum;				// Calc
	int16_t TrigOffsetVarNum;			// Calc
	int8_t TrigType;					// Calc
	int8_t TrigSense;					// Calc
	uint8_t TrigDigVal;					// Calc
	uint8_t TrigEnabled;				// Calc
	uint8_t TrigTrue;					// Calc /set externally - bit 0 trigger set internally, bits 1...5 external triggers, bit 6 is un-set trigger, bit 7 is latch state when re-entering the test using this exit transition
	int8_t TrigAbs;						// Calc
	int8_t LocationType;				// Calc: -1 => relative to trigger being set true, 1 => at preset distance
	uint8_t ScenarioType;				// Calc: 1 => lateral segments present (bit 0), 2 => speed segments present (bit 1), 3 => both present, bit 2 = 1 => repeat triggering of this scenario allowed, bit 3 = 1 => can be re-enabled if trigger failed
	uint8_t dummy8[2];					// Pad
} tHighwayScenario;

//lateral offset segment (56 bytes) - max 65536 = 3,670,016 bytes
typedef struct
{
	double RelStartDist;				// File
	double K1;							// File/Calc depending upon Type
	double K2;							// File/Calc depending upon Type
	double K3;							// File/Calc depending upon Type
	float Length;						// File	
	float InitialOffset;				// File
	float FinalOffset;					// File
	float dYdX;							// File
	float ActualLength;					// Calc
	uint8_t Type;						// File
	int8_t CalcsDone;					// Calc
	uint8_t dummy8[2];					// Pad
} tHW_LateralSegment;

//speed segment (60 bytes) - max 65536 = 3,932,160 bytes
typedef struct
{
	double RelStartDist;				// Calc
	double RelStartTime;				// File
	double ElapsedTime;					// File 
	double ActualElapsedTime;			// Calc depending upon Type
	float InitialVel;					// File/Calc depending upon Type
	float FinalVel;						// File/Calc depending upon Type
	float InitialAccel;					// File/Calc depending upon Type
	float ActualAccel;					// Calc depending upon Type
	float Jerk;							// File/Calc depending upon Type
	float Length;						// File (m)
	float TimeAdjustment;				// Calc (s)
	uint8_t Type;						// File 0 => pre-defined, 1 => clculated on-the-fly, 2 => return to default (last segment only)
	int8_t CalcsDone;					// Calc
	uint8_t ReturnCtrl;					// 0 = > base-line, 1 => path-speed
	uint8_t dummy8;						// Pad
} tHW_SpeedSegment;

// End shared structures

//-----------------------------------------------------------
// GTC Specific structures

// Structure for holding 2D coordinate data (we could expand this to include velocity or heading or curvature later on)
typedef struct
{
	double xPos;
	double yPos;
	double longitude;
	double latitude;
	double yaw;
	float timeOnPath;
	float distanceOnPath;
} _COORDS;

typedef struct
{
	float xPos;
	float yPos;
	float timeOnPath;
} _COORDS_SMALL;


#endif
