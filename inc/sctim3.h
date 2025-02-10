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
 * Program:     Controller firmware
 * File:        timerM.h
 * Functions:   TIEnableTimer
 *              TIActivateWD
 *
 * Description: Handles low-level counter/timer initialization
 *      including software watchdog initialization
 *
 * Modification history:
 * Rev      ECO#    Date    Author          Brief Description
 *
 * NOTE: Function returns SUCCESS or FAILURE unless otherwise
 *          specified
 *
\***************************************************************/

#ifndef _H_TIMER_MAIN_H
#define _H_TIMER_MAIN_H

/********** FUNCTION PROTOTYES *********/

/***************************************************************\
 *
 * Replaces: enable_timer
 * Used in: main
 *
\***************************************************************/
int TIEnableTimer();

/***************************************************************\
 *
 * Replaces: activate_wd
 * Used in: main
 * Description: Enables the software watchdog timer. See the note
 *      in the header comments for more details.
 *
\***************************************************************/
int TIActivateWD();

#endif
