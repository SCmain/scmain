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
 * Program:     Mapper Module
 * File:        mapk.h
 * Functions:   Cassette mapping constants
 *
 * Description: Header file for scanner constants definition
 *
 * Modification history:
 *
 * Rev      ECO#    Date    Author          Brief Description
 *
\******************************************************************************/

#ifndef _MAPK_H
#define _MAPK_H

// the define flags for the current system configuration
extern int iDefFlags;
// the emulation type of the current system configuration
extern int iEmulMode;

// constants
#define     NOFPASSES           3
#define     NOFSLOTS            31

// Scan data buffer size changed due to memory limitation -- 1/27/99 CKK
// #define     SCAN_ARRAY_SIZE     (NOFSLOTS*10)
// #define     HALF_SCAN_ARRAY     (NOFSLOTS*5)
#define     SCAN_ARRAY_SIZE     (NOFSLOTS*20)
#define     HALF_SCAN_ARRAY     (NOFSLOTS*10)
#define     NO_OF_SLOTS         (NOFSLOTS-1)

#define     TRANS_UP    2
#define     TRANS_DN    0

#define     M_OKAY    1
#define     M_CROSSSLOT 2
#define     M_UNSEEN    3
#define     M_DOUBLE    4
#define     M_UNSURE    5

#define     MP_ON_ROBOT_VAL_0   0
#define     MP_ON_ROBOT_VAL_1   1
#define     MP_ON_VAC_IDX_Z1    5
#define     MP_ON_VAC_IDX_Z2    6
#define     MP_ON_TRACK_VAL_0   7
#define     MP_ON_TRACK_VAL_1   8

#endif
