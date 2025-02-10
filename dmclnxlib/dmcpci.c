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

#ifdef DMC_PCIBUS

//
// Purpose	:
//
// Returns	:
//
long PCIBUSReadData(int iIndex, PCHAR pchResponse, ULONG cbResponse, PULONG pulBytesRead)
{
	LONG     rc = 0L;
	CHAR     szBuffer[RESPONSE_BUFFER_SIZE];
	ULONG    iBytesRead = 0L;
	
	*pulBytesRead = 0L;
	
	rc = read(controller[iIndex].iDriver, szBuffer, MIN(cbResponse - 1, sizeof(szBuffer) - 1));
	if (rc > 0L)
	{
	  iBytesRead = rc;
	  rc = 0L;
	}
	else if (rc == -1)
	{
		if (errno == EAGAIN)
			rc = 0L;
		else
		{
			rc = DMCERROR_DRIVER;
	}	}

	if (rc == 0L && iBytesRead > 0L)  /* No problem */
	{
		ULONG i;
		
		for (i = 0; i < iBytesRead; i++)
		{
			/* Is this a binary command? */
			if (controller[iIndex].fBinaryCommand)
			{
				if (i < cbResponse)
			  	pchResponse[(size_t)i] = szBuffer[(size_t)i];
			}
			else
			{
			 	/* Separate repsonses (from commands) from unsolicited responses (from messages) */
			  if (isascii((int)szBuffer[(size_t)i]))
			  {
					if (pchResponse)
					{
					  if (strlen(pchResponse) < cbResponse - 1)
					     /* User buffer can hold more data */
					  	strncat(pchResponse, &szBuffer[(size_t)i], 1);
					  else
					  {
					    /* User buffer is full - try to save the data */
					    rc = DMCERROR_BUFFERFULL;
					    if (strlen(controller[iIndex].szResponse) < sizeof(controller[iIndex].szResponse) - 1)
					    	strncat(controller[iIndex].szResponse, &szBuffer[(size_t)i], 1);
					    else
					    	rc = DMCERROR_RESPONSEDATA;
			  }	}	}
			  else
			  {
			  	szBuffer[(size_t)i] ^= 0x80;
			    if (strlen(controller[iIndex].szUnsolicitedResponse) < sizeof(controller[iIndex].szUnsolicitedResponse) - 1)
			    	strncat(controller[iIndex].szUnsolicitedResponse, &szBuffer[(size_t)i], 1);
	}	}	}	}      

  *pulBytesRead = iBytesRead;

  return rc;
}

//
// Purpose	:
//
// Returns	:
//
long PCIBUSWriteData(int iIndex, PSZ pchCommand, ULONG cbCommand, PULONG pulBytesWritten)
{
   LONG     rc = 0L;
   ULONG    iBytesWritten;

   *pulBytesWritten = 0L;

   rc = write(controller[iIndex].iDriver, pchCommand, cbCommand);
   if (rc > 0L)
   {
      iBytesWritten = rc;
      rc = 0L;
   }
   else if (rc == -1)
   {
      if (errno == EAGAIN)
         rc = 0L;
      else
      {
	      rc = DMCERROR_DRIVER;
   }	}

   *pulBytesWritten = iBytesWritten;

   return rc;
}

//
// Purpose	: Handle PCI testing for availability of data
//
// Returns	: return from called function
//
int PCIBUSCharAvailableInput(int iIndex)
{
	return ioctl( controller[ iIndex ].iDriver, GALIL_PCI_CHARAVAIL );
}

//
// Purpose	:
//
// Returns	:
//
long PCIBUSClear( int iIndex )
{
	return ioctl( controller[ iIndex ].iDriver, GALIL_PCI_CLEARFIFO );
}


#endif /* DMC_PCIBUS */


