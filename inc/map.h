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
 * Program:     scanner mapper Module
 * File:        map.h
 * Functions:   Cassette mapping scanner functions
 *
 * Description: Header file for map.c
 *
 * Modification history:
 *
 * Rev      ECO#    Date    Author          Brief Description
 *
\******************************************************************************/

#ifndef _MAP_H
#define _MAP_H

// scan station structure
// function prototypes for execute.c
int  MPDoScan(int iPassNum, int iScOnWhichDev);
int  MPFilterPass0(int iStn, int iMaxTh);
int  MPFilterPass1(int iStn);
int  MPFilterPass2(int iStn, int iPassNum);
int  MPFilterPass3(int iStn, int iCalib, int iIter, int iNewScheme);
int  MPFilterPass4( int iStationIndexArg, int iCalibArg, long lTorgArg, char cCalStationArg, int iIOShift );

#endif
