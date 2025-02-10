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
 * Program:     task module interface header
 * File:        task.h
 * Functions:   None
 *
 * Description: Provide interface between task module other
 *              modules
 *
 * Modification history:
 * Rev      ECO#    Date    Author          Brief Description
 *
\***************************************************************/

#ifndef _H_TASK_H
#define _H_TASK_H

#include "sctag.h"

/********** VARIABLES USED LOCALLY **********/
pstTaskList pstCurrentTaskList;         /* current task list pointer */
int iCurrentMacro;                      /* current macro is running in task */
int iPCCriticalSectionFlag;             /* flag for enter and exit critical section */
int iNoTaskFlag;                        /* flag signal with or without multi-tasking */
stTaskList staTaskList[MAXTASKS];       /* list of 0-9 tasks */
int iTaskID;                            /* current task id */
int iTimerForTKWait;

#endif
