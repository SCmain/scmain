/***************************************************************\
 *
 *              Copyright (c) 2007 SCFI Automation, Inc.
 * Code taken over by Georges Sancosme after the author (Canh Le) passed away and
 * published under GNU GPLv3
 *
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
 * File:        const.h
 * Functions:   None
 * Description: Global include file
 *
 * Modification history:
 * Rev      ECO#    Date    Author      Brief Description
 *
 ****************************************************************/
#ifndef _H_CONST_H
#define _H_CONST_H

#include <stdio.h>

//#define _FAR_ __far

#define TRUE    1
#define FALSE	0
#define ON	1
#define OFF	0
#define SUCCESS 0
#define FAILURE -1
#define BLANKLINE -2
#define MACRO -3

#define CR	13
#define LF	10
#define CTRL_Z	26
#define ESC	27

enum ATTRIB { NORMAL, RDONLY, HIDDEN, SYSTEM = 4 };

typedef char    INT8;
typedef short   INT16;
typedef	int		INT32;

typedef	unsigned char	UINT8;
typedef	unsigned short	UINT16;
typedef	unsigned int	UINT32;

typedef unsigned char   BYTE;
typedef unsigned int    WORD;
typedef unsigned long   DWORD;

typedef	unsigned char	UCHAR;
typedef unsigned short	USHORT;
typedef	unsigned int	UINT;
typedef unsigned long	ULONG;

typedef	int		BOOL;
typedef	int		STATUS;
typedef int     ARGINT;
typedef void    VOID;

#define DFSAP4      1       // Single axis pre-aligner for 4-axis controller - includes MCOR
#define DFVACPRE    2       // Vacuum prealigner
#define DFPRE       4       // Pre-aligner, any type
#define DFAK        8       // KLA Stage controller
#define DFSS        16      // Track servo Axis on first Galil card (special case)
#define DFVAC514    32      // VAC514 robot with 1:1 ratio, geared Theta and Radial axes

// emulator type
#define DFEMULATORP     1   // Prometrics emulation
#define DFEMULATORM     2   // MECS Compatible emulation
#define DFEMULATORA     4   // ADE compatible emulation
#define DFEMULATORC     8   // Cybeq emulation
#define DFEMULATORG     16  // Genmark emulation
#define DFEMULATORB     32  // Brooks emulation

#endif      // End of _H_CONST_H include file
