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
 *  Program:        Aligner Module File I/O and Read/Set Variable functions
 *  Function:
 *  Description:    Contains access Functions for Wafer Calibration Structure
 *                  as well as Get and Set Functions for Aligner module variables
 *                  needed from outside the module
 *
 *  Modification history:
 *
 *  Rev     ECO#    Date    Author          Brief Description
 *
 *********************************************************************/

#ifndef _H_ALFIO_H
#define _H_ALFIO_H

extern int giFlatIndexEndPrev;                              // flat_i_end_old

int ALGetPreData(long lIndexArg, unsigned int *puiDataArg);    // data - data collection buf
int ALSetPreData(long lIndexArg, unsigned int uiDataArg);
int ALGetDUPCount(unsigned long *ulpDuplicateCountArg);
int ALSetDUPCount(unsigned long ulDuplicateCountArg);
int ALGetBadCounter(unsigned long *ulpBadCountArg);
int ALSetBadCounter(unsigned long ulBadCountArg);
int ALGetIntVars(int iVariableTypeArg, int iIndexArg, int *ipVariableValueArg);
int ALSetIntVars(int iVariableTypeArg, int iIndexArg, int iVariableValueArg);
int ALGetLongVars(int iVariableTypeArg, int iIndexArg, long *lpVariableValueArg);
int ALSetLongVars(int iVariableTypeArg, int iIndexArg, long lVariableValueArg);

int ALSetAligningGASpeed(unsigned long ulAxisArg, long *lpWaferSpeedArg, long *lpWaferAccelArg);
int ALGetAligningSpeed(int iWhichArg, long *lpWaferSpeedArg, long *lpWaferAccelArg);

#endif
