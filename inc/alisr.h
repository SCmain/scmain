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
 *  Program:        Aligner Module Interrupt Functions
 *  Function:
 *  Description:    Contains Functions used durint the CCD interrupt process while
 *                  collecting data
 *
 *  Modification history:
 *
 *  Rev     ECO#    Date    Author          Brief Description
 *
 *********************************************************************/

#ifndef _H_ALPROC_H
#define _H_ALPROC_H

int ALSetProc(int iActionArg);
int ALSelectCCDType(unsigned uMaskArg, int iIsrCCDTypeArg);
void ALCCDInterrupt1(void);              // ff_interrupt
void ALCCDInterrupt2(void);              // ff1_interrupt

int ALSelectCCDNumber(int iCCDNumArg);        // set_CCD_no - allows selection of correct CCD
                                        //      corresponding to wafer size
int ALReturnCCDMask(int iCCDNumArg);  // return CCD Mask to select the given CCD Number
int ALEnableCCD(void);                  // enable_CCD - Install CCD interrupt routine
int ALResetChuck(void);          // chuck_counter_reset - reset chuck counter
int ALStartMeasurement(void);           // mesument_start - enable data collection
int ALStopMeasurement(void);            // mesument_stop - disable data collection
int ALTakeMeasurement(long *lpAngleArg, long *lpDataArg);  // mesument_one - enable,
                                        //    - collect some data, disable collection

int ALTestChuckAndCCD(void);               // test_CCD_CHUCK
// Returns debug variable
int ALReturnDebugVar();

#endif
