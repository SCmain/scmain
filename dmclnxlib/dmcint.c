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
 */

#include "dmclnx.h"
#include "../PCIDriver/pciioctl.h"
//#include "../ISADriver/isaioctl.h"

#ifdef DMC_INTERRUPTS

long BUSGetInterruptStatus(int iIndex, PUSHORT pusStatus) //passing argument as 0 is normal:  sleep until interrupt.  passing argument as 1 means clear the status byte queue (does not sleep)
{
	long lRetCode=0;
	long item = 3;
	int nArg = *pusStatus;

/*	if ( controller[iIndex].controllerinfo.fControllerType == ControllerTypeISABus )
   		item = GALIL_ISA_INTSTATUS;
	else*/
		item = GALIL_PCI_INTSTATUS;

	lRetCode = ioctl( controller[ iIndex ].iDriver, item, &nArg );
	*pusStatus = nArg;
   	
	return lRetCode;
}

#endif
