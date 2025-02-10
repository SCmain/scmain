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
 * Program:     Predictive IO algorithm
 * Modification history:
 *
 * Rev      ECO#    Date    Author          Brief Description
 *
\******************************************************************************/
#ifndef _PDIO_H
#define _PDIO_H

int PDConvAxis(ULONG ulAxis);
int PDInitLatch(void);
int PDComputeAlarm(int iAxisArg, int iDirArg, int iRunArg, int iTotalArg);
int ex_SPDA(instr_ptr instr);
int ex_RPDA(instr_ptr instr);
int ex_RDEU(instr_ptr instr);
int ex_SPCT(instr_ptr instr);
int ex_RPCT(instr_ptr instr);
int ex_RPCTE(instr_ptr instr);
int ex_SLPT(instr_ptr instr);
int ex_RLPT(instr_ptr instr);
int PDWriteLatchDataFile(void);
int PDReadLatchDataFile(void);
int PDWriteLatchCalFile(void);
int PDReadLatchCalFile(void);
int PDOutOfRange(int iAxisArg, int iDirArg, int iRunArg);
int ex_XCL(instr_ptr instr);

#endif
