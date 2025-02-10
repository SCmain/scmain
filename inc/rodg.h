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
 * File:        rodg.h
 * Functions:   ROTestHome
 *              ROAdjustRAtHome
 *              ROAdjustRAtIndex
 *              ROSetHomeR
 *              ROSetTestScaling
 *              RODoROffset
 *              ROPresetHomeR
 *              ROTestVacuum
 *              ROTestRobotIO
 *
 * Description: Provide an interface to mechanism based diagnostics
 *      functions
 *
 * Modification history:
 * Rev      ECO#    Date    Author          Brief Description
 *
\***************************************************************/

#ifndef _H_RODG_H
#define _H_RODG_H

#include "romain.h"

/********** DIAGNOSTICS FUNCTIONS **********/

int ROTestHome(int iCardNoArg, int iVacExistsArg);
int ROAdjustRAtHome(unsigned long ulAxisArg);
int ROAdjustRAtIndex(unsigned long ulAxisArg);
int ROSetHomeR(void);
int ROSetTestScaling(int iDevModeArg, int iVacExistsArg);
int RODoROffset(void);
int ROPresetHomeR(void);
int ROTestVacuum(int iCardNoArg);
int ROTestRobotIO(int iDevModeArg);

#endif
