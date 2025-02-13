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
 * Program:     Controller firmware
 * File:        dg.h
 * Functions:   DiagStart
 *              DiagGetFlag
 *              DiagSetFlag
 *
 * Description: Handles the interface to diagnostics mode
 *
 * Modification history:
 *
 *
 ****************************************************************/

#ifndef _H_DIAG_H
#define _H_DIAG_H

/******** Function Prototypes ***********/

/****************************************************************
 *
 * Used in: main
 * Description: Starts diagnostics mode. This function is the primary
 *      interface to the diagnostics module. It handles setting up the
 *      teach pendant to be used in diagnostics mode, the user keypresses
 *      to continue into either robot or prealigner diagnostics mode,
 *      and returns the teach pendant and robot to their normal
 *      working conditions when finished.
 *
 *
 ***************************************************************/
int DiagStart(int iPortNumArg, int iRobArg, int iPreArg, int iVacArg, int iDefineFlagArg, int iEmulatorArg);

/***************************************************************\
 *
 *                  NEW FUNCTION
 *
 * Description: This GETS the value of the iDiagFlag variable.
 *      It replaces the diagnostics mode operation of the old
 *      go_to_teach variable used in the main (main loop)
 *      and execute (ex_DIAG) functions.
 *
\***************************************************************/
int DiagGetFlag();

/***************************************************************\
 *
 *                  NEW FUNCTION
 *
 * Description: This SETS the value of the iDiagFlag variable.
 *      It replaces the diagnostics mode operation of the old
 *      go_to_teach variable used in the main (main loop)
 *      and execute (ex_DIAG) functions.
 *
\***************************************************************/
int DiagSetFlag(int iPortNumArg);

#endif
