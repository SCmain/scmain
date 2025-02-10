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
 * Program:     Scan mapper IO Module
 * File:        mapio.h
 * Functions:   Map IO functions.
 *
 * Description: Header file for map.c
 *
 * Modification history:
 * Rev      ECO#    Date    Author          Description
 *
\******************************************************************************/

#ifndef _H_MAPIO_H
#define _H_MAPIO_H

// constants
#define     WES_INTNO           0x73
#define     WES_MASK            0x08
#define     NOTSCANNING         13
#define     Z_S293_SPEED        300     /* S293 Z Speed */

// Interrupt call function prototypes
void  TESTWES_PROC( );
void  WES_PROC( );

// Function prototypes
int     MPInitScanIO(void);
void    MPRestorePROC(void);
int     MPEnableWES( void );
void    MPDisableWES( void );
int     MPEnableTestWES( void );
void    MPDisableTestWES( void );
int     MPReadLatchedPosition(long *lValue);

// new functions for pass TestWes vars for Diagnostic routine
int     MPIsNotScanning( void );
void    MPSetNotScanning( void );

int     MPGetHitcount(int iArg);
void    MPSetScanPointers(int *ipCount, long *lpZPos, int *ipTrans);
void    MPInitScanDataBuffer( void );

int     MPTestScanning( int iCardNoArg, int iVacExistsArg );

void	MPUpdateIO(int iFlagArg);
#endif
