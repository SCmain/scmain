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
 *              Copyright (c) 2007 XyZ Automation, Inc.
 *
 * Program:     main header
 *
 * File:        scmain.h
 *
 * Functions:   Init
 *
 *
 * Description: This is main module for the whole project.  In this module, it does all the
 *              initialization of other modules. It provides all the configuration of the
 *              system.
 *
 *
 *
 * Environment: SUSE LINUX C
 *
 * Modification history:
 *
 * Rev      Date    Brief Description
 * 01A      040607  Initial version
 *
\***************************************************************/

#ifndef _H_SCMAIN_H
#define _H_SCMAIN_H

/********** DEFINES **********/

#define EX_AUTOMACRO    100


/********** FUNCTIONS USED LOCALLY **********/

/****************************************************************\
 *
 * Description: Do initialization of all the other
 *      modules, providing all the configuration information
 *      for the entire system.
 *
\*****************************************************************/
int Init(int iWatchDog);

/***************************************************************\
 *
 *                  NEW FUNCTION
 *
 * Description: Prints a message of which module failed initialization
 *      and then error exits to the prompt, in DEBUG MODE ONLY!!!
 *      In normal operation, the firmware continues even after
 *      an initialization failure. So the user can determine what
 *      failed later through host commands.
 *
\***************************************************************/
int FailureExit(char *cpFailMsg);

#endif


