/***************************************************************\
 *
 *              Copyright (c) 2007 SCFI Automation, Inc.
 * Code taken over by Georges Sancosme after the author (Canh Le) passed away and
 * published under GNU GPLv3
 *
 * File Name            : alfio.c
 * Description          : Contains access Functions for Wafer Calibration Structure
 *                  as well as Get and Set Functions for Aligner module variables
 *                  needed from outside the module
 * Original Author      : Canh Le (Deceased)
 * Current Maintainer   : Georges Sancosme (georges@sancosme.net)
 * Maintained Since     : 13.01.2025
 * Created On           : 04.06.2007
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 *
 *
 * Program:     Controller Firmware
 * File:        roloc.h
 * Functions:   ROGetMappedAxis
 *              ROGetMilScale
 *              ROSetMilScale
 *              ROArrangeGetArrayForW
 *              ROArrangeSetArrayForW
 *              ROCorrectDistance
 *              ROAxisReadyToMove
 *              ROMoveToAbsOrRel
 *              ROStopMotionLocal
 *              ROServoMCOffLocal
 *              ROServoMCOnLocal
 *              ROInitGalilLocal
 *              ROSendMoveToHSorIP
 *              ROMoveAllOrAxisDirect
 *
 * Description: Functions and variables used locally within the
 *      mechanism module
 *
 * Modification history:
 * Rev      Date    Author          Brief Description
 *
\***************************************************************/

#ifndef _H_ROLOC_H
#define _H_ROLOC_H

#include "romain.h"

/********** DEFINES **********/

/* Character to exit Galil mode (^I) */
#define END_TALK    9

/* uaAxisMap type definitions. Used to set and get system configuration information */
#define MECH_TYPE       0
#define EQUIPE_AXIS     1
#define GALIL_AXIS      2
#define SPECIAL_AXIS    3

/* The gearing ration for a VAC514 robot with a 1-to-1 arm. */
#define VAC514_T_GEARING_RATIO      -1.0
#define VAC514_R_GEARING_RATIO      1.0


/********** VARIABLES USED LOCALLY **********/

extern unsigned long ulAxisALLRbt;  /* The axis #Define combination for a 3-axis robot only */
extern unsigned long ulAxisallPre;  /* The axis #Define combination for a pre-aligner only */
extern unsigned long ulAllAMFlag;   /* The axis combination for all available axes */
extern unsigned long ulHoming;      /* 1 = in the process of homing; bitwise by axis */
extern unsigned long ulHomed;       /* 1 = axis has previously homed; bitwise by axis */
extern unsigned long ulServoFlag;   /* 1 = servo off; 0 = servo on; bitwise by axis */
extern unsigned long ulERFlag;      /* 1 = position error on axis; bitwise by axis */
extern unsigned long ulAMFlag;      /* 1 = motion completed on axis; bitwise by axis */
extern unsigned long ulLMPosFlag;   /* 1 = pos limit sw now on; bitwise by axis */
extern unsigned long ulLMNegFlag;   /* 1 = neg limit sw now on; bitwise by axis */
extern unsigned long ulLMPosMom;    /* 1 = pos limit sw momentarily on; bitwise by axis */
extern unsigned long ulLMNegMom;    /* 1 = neg limit sw momemtarily on; bitwise by axis */
extern unsigned long ulLMPosChanged;/* 1 = positive limit switch value has changed; bitwise by axis */
extern unsigned long ulLMNegChanged;/* 1 = negative limit switch value has changed; bitwise by axis */
extern unsigned uSCurveFlag;        /* 1 = S-curve profile on; bitwise by axis */
extern int iDefineFlag;             /* The define flags for the current system configuration */
extern int iEmulator;               /* The emulation type of the current system configuration */
extern int iPreOnly;                /* Special considerations for a pre-aligner only system */

/********** FUNCTIONS USED LOCALLY **********/

/* Checks that the axes requested are present in this configuration */
unsigned ROGetMappedAxis(unsigned uAxisArg, unsigned uWhichMapArg);
/* Scales a set of 4 values by 1000. Used to scale Kp, Kd, Ki, and torque limit. */
void ROGetMilScale(double *dInArg, long *lOutArg);
/* Scales a set of 4 values by 1000. Used to scale Kp, Kd, Ki, and torque limit. */
void ROSetMilScale(long *lInArg, double *dOutArg);
/* Puts the W axes returned from a datafile operation into the 4th element of the array */
void ROArrangeGetArrayForW(unsigned long ulEquipeAxisArg, long *lValue);
/* Puts the W axes from the 4th element of the array into the appropriate location
 * in preparation for a datafile operation */
void ROArrangeSetArrayForW(unsigned long ulEquipeAxisArg, long *lValue);
int ROCorrectDistance(int iCardNoArg, long lHomeIndexArg, unsigned uAxisIndexArg);
int ROMoveToAbsOrRel(unsigned long ulEquipeAxisArg, int iRelativeFlagArg, long *lPositionArg);
// Combines ROMoveDirect and ROMoveAxisDirect
int ROMoveAllOrAxisDirect(unsigned long ulAxisArg, int iStnArg, int iOffDirArg, int iFlagArg);
// Combines ROSendMoveToHomeSwitch & ROSendMoveToIndexPulse
int ROSendMoveToHSorIP(ULONG ulAxisArg, int iFlagArg, int iResetParsFlag, int iGearingFlagArg);
// Internalized function. Actually replaces part of ex_STOP.
int ROStopMotionLocal(unsigned long ulEquipeAxisArg);
// Internalized function. Actually replaces part of ex_SVOF.
int ROServoMCOffLocal(unsigned long ulEquipeAxisArg);
// Internalized function. Actually replaces part of ex_SVON.
int ROServoMCOnLocal(unsigned long ulEquipeAxisArg);
// Replaces: init_galil, init_galil1, init_auxgalil
int ROInitGalilLocal(unsigned long ulEquipeAxesArg);

#endif
