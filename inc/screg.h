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
 * Program:     Register R, C, and S
 * File:        rcs.h
 * Functions:   None
 *
 * Description: Declare global variables for R-Registers, C-Registers, S-Registers and
 *              Special R-Registers for Novellus.
 *              These variables are only global to local module (RCS) only.
 *              -   R-Registers have 100 registers (0-99)
 *              -   C-Registers have 100 registers (0-99)
 *              -   S-Registers have 20 registers (1-20), each string register's length is 256.
 *              -   Special R-Registers have 25 registers (for novellus only)
 *
 * Modification history:
 * Rev      ECO#    Date    Author          Brief Description
 *
\***************************************************************/

#ifndef _H_RCS_H
#define _H_RCS_H

#include "scregg.h"

/********** VARIABLES USED LOCALLY **********/

long *RGplRegister;                  /* R-variable */
long *RGplSpecialRegister;           /* R-Special variable for novellus*/
char *RGpcCharacter;                 /* C-variable */
char *RGpacString[MAXSTRINGVARS+1];  /* S-variable */

#endif
