#pragma once


#ifndef __MARLIN_FIRMWARE__
#define __MARLIN_FIRMWARE__
#endif

#include <stdint.h>

#include "Configuration.h"
#define Compiler 1 // {0: Auto,1: Manual} DO NOT CHANGE, auto mode will auto-change for compile when needed

#if Compiler == 0
    #define SapphireType    //  {V2,V3,V4} Choose between V2(2Endstop),V3(1 Endstop, Flipped Screen) , V4 (STM32F4 Chip)
    #define BoardName       //  = {Stock}
    #define ABL         //  = {Manual, Inductive, BlTouch}
    #define MeshNumber 0     // Meshnumber = {3, 5}
    #define UI          //  {Marlin, ColourUI}
    #define AltFan 0        // {1: Heatsink Fan wired to Heater 1 on stock Board, 0:Default Always On Heatsink Fan}
#elif Compiler == 1 
    #define VL    //  {V2,V3,V4,VL} Choose between V2(2Endstop),V3(1 Endstop, Flipped Screen) , V4 (STM32F4 Chip), VL(Test Build/DONT USE(Ballscrew, Flipped Screen, Experimental Extruder))
    #define Stock       //  = {Stock}
    #define Inductive         //  = {Manual, Inductive(ideagen), BlTouch}
    #define MeshNumber 5      // Meshnumber = {3, 5}
    #define Marlin          //  {Marlin, ColourUI}
    #define AltFan 1        // {1: Heatsink Fan wired to Heater 1 on stock Board, 0:Default Always On Heatsink Fan}
#endif


/*----------------------------------------------Sapphire Version-----------------------------------------------------*/

#if ENABLED(VL)
    #define MOTHERBOARD BOARD_MKS_ROBIN_NANO
    #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 800, 284 }
    #define INVERT_Z_DIR true
    #define X_DRIVER_TYPE  TMC2208_STANDALONE
    #define Y_DRIVER_TYPE  TMC2208_STANDALONE
    #define Z_DRIVER_TYPE  TMC2208_STANDALONE
    #define Z2_DRIVER_TYPE TMC2208_STANDALONE
    #define E0_DRIVER_TYPE TMC2208_STANDALONE
    #define USE_PROBE_FOR_Z_HOMING
    #define INVERT_X_DIR false
    #define INVERT_Y_DIR false
    #define Z_STEPPER_AUTO_ALIGN
#endif

#if ENABLED(V2)
    #define INVERT_X_DIR true
    #define INVERT_Y_DIR true
    #define MOTHERBOARD BOARD_MKS_ROBIN_NANO
    #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 410 }
    #define INVERT_Z_DIR false
    #define X_DRIVER_TYPE  TMC2208_STANDALONE
    #define Y_DRIVER_TYPE  TMC2208_STANDALONE
    #define Z_DRIVER_TYPE  A4988
    #define Z2_DRIVER_TYPE A4988
    #define E0_DRIVER_TYPE TMC2208_STANDALONE
    #if ENABLED(Manual)
        #define Z_MULTI_ENDSTOPS
    #else 
        #define Z_STEPPER_AUTO_ALIGN
    #endif
#endif

#if ENABLED(V3)
    #define INVERT_X_DIR true
    #define INVERT_Y_DIR true
    #define MOTHERBOARD BOARD_MKS_ROBIN_NANO
    #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 800, 410 }
    #define INVERT_Z_DIR true
    #define X_DRIVER_TYPE  TMC2208_STANDALONE
    #define Y_DRIVER_TYPE  TMC2208_STANDALONE
    #define Z_DRIVER_TYPE  TMC2208_STANDALONE
    #define Z2_DRIVER_TYPE TMC2208_STANDALONE
    #define E0_DRIVER_TYPE TMC2208_STANDALONE
    #define TFT_ROTATION TFT_ROTATE_180
#endif

#if ENABLED(V4)
    #define INVERT_X_DIR true
    #define INVERT_Y_DIR true
    #define MOTHERBOARD BOARD_MKS_ROBIN_NANO_V1_3_F4
    #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 410 }
    #define INVERT_Z_DIR true
    #define X_DRIVER_TYPE  TMC2208_STANDALONE
    #define Y_DRIVER_TYPE  TMC2208_STANDALONE
    #define Z_DRIVER_TYPE  TMC2208_STANDALONE
    #define Z2_DRIVER_TYPE TMC2208_STANDALONE
    #define E0_DRIVER_TYPE TMC2208_STANDALONE
    #define TFT_ROTATION TFT_ROTATE_180
#endif

/*----------------------------------------------ScreenUI-----------------------------------------------------*/

#if ENABLED(Marlin)
    #define TFT_CLASSIC_UI
#endif

#if ENABLED(ColourUI) 
    #define TFT_COLOR_UI
#endif
/*----------------------------------------------Board-----------------------------------------------------*/
#if ENABLED(Stock)
#endif

#if ENABLED(AltFan)
    #define E0_AUTO_FAN_PIN 16
    
#endif
 /*----------------------------------------------LEVELING-----------------------------------------------------*/

#if ENABLED(Manual)
    #define Z_MIN_ENDSTOP_INVERTING true
    #define Z_MAX_ENDSTOP_INVERTING true
    #define Z_MIN_PROBE_ENDSTOP_INVERTING true
    #define MESH_BED_LEVELING
#else 
    #define LEVEL_CORNERS_USE_PROBE
    #define G29_RETRY_AND_RECOVER
    #define G38_PROBE_TARGET
    #define Z_PROBE_END_SCRIPT "M500"
    #if DISABLED(ColourUI)
        #define BABYSTEP_ZPROBE_GFX_OVERLAY
    #endif     
#endif

#if ENABLED(BlTouch)
    #define USE_ZMAX_PLUG
    #define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
    #define Z_MIN_ENDSTOP_INVERTING false
    #define Z_MAX_ENDSTOP_INVERTING true
    #define Z_MIN_PROBE_ENDSTOP_INVERTING false
    #define BLTOUCH
    #define AUTO_BED_LEVELING_BILINEAR
    #define LEVEL_CORNERS_USE_PROBE
    #define Z_SAFE_HOMING
    #define BABYSTEP_ZPROBE_OFFSET 
    #define ASSISTED_TRAMMING
    #define Z_CLEARANCE_DEPLOY_PROBE    5 // Z Clearance for Deploy/Stow
    #define Z_CLEARANCE_BETWEEN_PROBES  5 // Z Clearance between probe points
    #define Z_CLEARANCE_MULTI_PROBE     5 // Z Clearance between multiple probes
    //#define Z_AFTER_PROBING           5 // Z position after probing is done
    #define Z_PROBE_LOW_POINT          -2 // Farthest distance below the trigger-point to go before stopping

    // For M851 give a range for adjusting the Z probe offset
    #define Z_PROBE_OFFSET_RANGE_MIN -20
    #define Z_PROBE_OFFSET_RANGE_MAX 20

    #define MULTIPLE_PROBING 2
    //#define EXTRA_PROBING    1
    #define HOMING_BUMP_MM      { 5, 5, 5 }       // (mm) Backoff from endstops after first bump
    #define HOMING_BUMP_DIVISOR { 2, 2, 2 }       // Re-Bump Speed Divisor (Divides the Homing Feedrate)
#else
    #define HOMING_BUMP_MM      { 5, 5, 2 }       // (mm) Backoff from endstops after first bump
    #define HOMING_BUMP_DIVISOR { 2, 2, 2 }       // Re-Bump Speed Divisor (Divides the Homing Feedrate)
#endif

#if ENABLED(Inductive)
    #define USE_ZMAX_PLUG
    #define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN
    #define Z_MIN_ENDSTOP_INVERTING false
    #define Z_MAX_ENDSTOP_INVERTING true
    #define Z_MIN_PROBE_ENDSTOP_INVERTING false
    #define FIX_MOUNTED_PROBE
    #define AUTO_BED_LEVELING_BILINEAR
    #define LEVEL_CORNERS_USE_PROBE
    #define Z_SAFE_HOMING
    #define BABYSTEP_ZPROBE_OFFSET 
    #define Z_CLEARANCE_DEPLOY_PROBE    1 // Z Clearance for Deploy/Stow
    #define Z_CLEARANCE_BETWEEN_PROBES  3 // Z Clearance between probe points
    #define Z_CLEARANCE_MULTI_PROBE     0.5 // Z Clearance between multiple probes
    //#define Z_AFTER_PROBING           5 // Z position after probing is done
    #define Z_PROBE_LOW_POINT          -5 // Farthest distance below the trigger-point to go before stopping

    // For M851 give a range for adjusting the Z probe offset
    #define Z_PROBE_OFFSET_RANGE_MIN -20
    #define Z_PROBE_OFFSET_RANGE_MAX 20

    #define MULTIPLE_PROBING 2
    #define EXTRA_PROBING    1
#endif

#if DISABLED(Manual)
    // Enable the M48 repeatability test to test probe accuracy
    #define Z_MIN_PROBE_REPEATABILITY_TEST
#endif
