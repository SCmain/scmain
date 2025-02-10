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
 * File:        teach.h
 * Functions:   TMTeach
 *              TMGetTeachFlag
 *              TMSetTeachFlag
 *
 * Description: Handles the interface to teach mode
 *
 * Modification history:
 * Rev      ECO#    Date    Author      Brief Description
 *
 * NOTE: The way teach mode was accessed in the old code
 *      was through the go_to_teach flag. A value of 1
 *      meant "run teach mode through COM1". A value
 *      of 2 meant "run teach mode through COM2".
 *      a new flag, iTeachFlag, has been introduced to handle
 *      that access independently of diagnostics mode. It can
 *      be set and retrieved through the TMSetTeachFlag and
 *      TMGetTeachFlag functions, respectively, and
 *      can have values of NO_PORT_NUM, COM1, and COM2, the
 *      communications port that teach mode is to
 *      be run through.
 *
 * NOTE: Function returns SUCCESS or FAILURE unless otherwise
 *          specified
 *
 ****************************************************************/

#ifndef _H_TEACH_H
#define _H_TEACH_H

/******** FUNCTION PROTOTYPES ***********/

/****************************************************************
 *
 * Replaces: teach
 * Used in: main
 * Abstract:    Main entry point for teach mode. Starts teach mode.
 *      It begins by setting up the teach pendant appropriately.
 *      It then asks the user whether to go to terminal mode,
 *      teach mode, or quit back to the previous screen (typically
 *      the Equipe logo screen). If teach mode is selected, TMTeachMenu
 *      is invoked which is the core of teach mode. It finishes by
 *      resetting all the interrupt macro flags, restoring normal
 *      teach pendant settings, and printing a prompt to the active terminal.
 *
 ***************************************************************/
int TMTeach(int iPortNumArg, int iDefineFlagArg, int iEmulatorArg);

/****************************************************************
 *
 * Replaces: go_to_teach variable
 * Used in: main, execute
 * Abstract:    Gets the value of the teach flag (was go_to_teach
 *      variable). See header notes for more details.
 *
 ***************************************************************/
int TMGetTeachFlag();

/****************************************************************
 *
 * Replaces: go_to_teach variable
 * Used in: main, execute
 * Abstract:    Sets the value of the teach flag (was go_to_teach
 *      variable). See header notes for more details.
 *
 ***************************************************************/
int TMSetTeachFlag(int iPortNumArg);

#endif
