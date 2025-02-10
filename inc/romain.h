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
 * File:        romain.h
 * Functions:   None
 * Description: Provide globally used defines
 *
 * Modification history:
 * Rev      ECO#    Date    Author          Brief Description
 *
\***************************************************************/

#ifndef _H_ROMAIN_H
#define _H_ROMAIN_H

/********** DEFINES **********/

/* The CAPITAL T,R,Z,W designate first motion control card. */
#define RO_AXIS_T   0x0001
#define RO_AXIS_R   0x0002
#define RO_AXIS_Z   0x0004
#define RO_AXIS_W   0x0008

/* The lowercase t,r,z,w designate second motion control card. */
//#define RO_AXIS_t   0x0001
//#define RO_AXIS_r   0x0002 
//#define RO_AXIS_z   0x0004 
//#define RO_AXIS_w   0x0008 
#define RO_AXIS_t   0x0010  
#define RO_AXIS_r   0x0020 
#define RO_AXIS_z   0x0040 
#define RO_AXIS_w   0x0080

/* Designate a special axis that may have custom code and/or
 * axes designations that are needed by other modules. */
#define RO_NO_COMBINED_AXES 0x100
#define RO_NO_SPECIAL       0
#define RO_TRACK            1
#define RO_FLIPPER          2
#define RO_DUAL_ARM         3
#define RO_TILTER           4
#define RO_SINGLE_PRE       5
#define RO_INDEXER_T1       6           /* Typically 't' */
#define RO_INDEXER_T2       7           /* Typically 'w' */
#define RO_INDEXER_Z1       8           /* Typically 'r' */
#define RO_INDEXER_Z2       9           /* Typically 'z' */
#define RO_ROBOT            10
#define RO_3_AXIS_PRE       11

#define RO_CONFLICT         0x88

#endif
