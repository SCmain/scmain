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
 * Program:     Motion Control Test Routines (Diagnostics)
 * File:        gatst.h
 * Functions:   GATestGalil
 *              GATestLSHS
 *              GATestEncoder
 *              GASetupAMPBoard
 *              GASetupAMPMode
 *
 * Description: Provide test routines for Motion Control module
 *      testing. They are used by the diagnostics test steps.
 *
 * Modification history:
 * Rev      ECO#    Date    Author          Brief Description
 *
\***************************************************************/

#ifndef _H_GATST_H
#define _H_GATST_H

/********** FUNCTION PROTOTYPES **********/
int GATestGalil( int iCardNoArg );
int GATestLSHS( int iCardNoArg, int iVacExistsArg );
int GATestEncoder( int iCardNoArg, int iVacExistsArg );
int GASetupAMPBoard( int iCardNoArg );
int GASetupAMPMode( int iCardNoArg, int iVacExistsArg );

#endif
