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
 * File:        rofn.h
 * Functions:   
 * Description: Provides the interface between the Main module and Mechanism
 *      module. Initializes the system configuration.
 *
 * Modification history:
 * Rev      ECO#    Date    Author          Brief Description
 *
\***************************************************************/

#ifndef _H_ROFN_H
#define _H_ROFN_H

#include "romain.h"

/********** FUNCTION PROTOTYPES **********/

/* Main module initializes the Mechanism module configuration */
int ROInit(int iNumAxesArg,         /* The total number of axes in the system */
            int *iaMechTypeArg,     /* Array of the datafile type in the system; by axis */
            int *iaEquipeAxisArg,   /* Array of the Equipe axes definitions in the system; by axis */
            int *iaGalilAxisArg,    /* Array of the corresponding Galil axes; by axis */
            int *iaSpecialAxisArg,  /* Array defining if a particular axes has special characteristics,
                                     * i.e. RO_TRACK, RO_DUAL_ARM, etc.; by axis */
            int iDefineFlagArg,     /* The define flags for the current system configuration */
            int iEmulatorArg);      /* The emulation type for the current system configuration */

#endif
