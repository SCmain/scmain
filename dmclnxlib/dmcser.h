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
 */

#ifndef INCLUDE_SERIAL
#define INCLUDE_SERIAL

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>

#include <termios.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMPORTS   8
#define NO_MORE_DATA    -99

extern long SERIALReadData(int iIndex, PCHAR pchResponse, ULONG cbResponse, PULONG pulBytesRead);
extern long SERIALWriteData(int iIndex, PCHAR pchCommand, ULONG cbCommand, PULONG pulBytesWritten);
extern long SERIALClear(int iIndex);
extern int SERIALCharAvailableInput(int iIndex);

long OpenPort(int iIndex);
long ClosePort(int iIndex);
int ReadyToRead(int iIndex);
int ReadyToWrite(int iIndex);
long ReadAChar(int iIndex, PCHAR pch);
long WriteAChar(int iIndex, CHAR ch);

#endif /* INCLUDE_SERIAL */
