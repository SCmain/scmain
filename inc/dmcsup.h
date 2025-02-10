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
 */

#ifndef INCLUDE_DMCSUP
#define INCLUDE_DMCSUP

/* Conditional includes */

/* ISA bus communications */
#ifdef DMC_ISABUS
   #include "dmcisa.h"
#endif

/* PCI bus communications */
#ifdef DMC_PCIBUS
   #include "dmcpci.h"
#endif

/* For ISA or PCI communications */
#ifdef DMC_INTERRUPTS
   #include "dmcint.h"
#endif

/* Serial communications */
#ifdef DMC_SERIAL
   #include "dmcser.h"
#endif

/* Ethernet communications */
#ifdef DMC_ETHERNET
   #include "dmceth.h"
#endif

/* For advanced communications */
#ifdef DMC_BINARYCOMMANDS
   #include "dmcbin.h"
#endif
#ifdef DMC_FIRMWARE
   #include "dmcfmw.h"
#endif
#ifdef DMC_DATARECORDACCESS
   #include "dmcdma.h"
#endif

#define MAX_DEVICES 4

#define OUTP   outp
#define INP    inp
#define OUTPW  outpw
#define INPW   inpw

enum DMCBusIOStyle
{
   DMC600IOStyle = 0,            /* For DMC-600, DMC-1400 */
   DMC1000IOStyle = 1,           /* For DMC-1200, DMC-1000, DMC-1700, DMC-1802 */
   DMC1600IOStyle = 2            /* For DMC-1600, DMC-1800 */
};

enum DMCInterruptStyle
{
   DMC1000InterruptStyle = 0,    /* For DMC-1000 */
   DMC1400InterruptStyle = 1,    /* For DMC-1400 */
   DMC1700InterruptStyle = 2,    /* For DMC-1200, DMC-1700, DMC-1802 */
   DMC1600InterruptStyle = 3,    /* For DMC-1600, DMC-1800 */
   DMCNoInterruptStyle = 99      /* No interrupts */
};

typedef struct _CONTROLLER
{
   SHORT          fInUse;              /* Array member in use */
   SHORT          fBinaryCommand;      /* Is the command ASCII or binary */
   int            iDriver;
#ifdef DMC_INTERRUPTS
   SHORT          fInterruptEnabled;   /* Interrupts are enabled */
#endif
#ifdef DMC_DATARECORDACCESS   
   CHAR           usRevision;          /* Data Record Access revision */
   USHORT         usDataRecordSize;    /* Data record size */
   USHORT         usMaxGeneralOffset;  /* Max value for general offsets */
   USHORT         usMaxAxisOffset;     /* Max value for axis offsets */
   PBYTE          pbDataRecord;        /* Copy of data record for data record access */
   PBYTE          pTemp1;              /* Data record access temp storage */
   PBYTE          pTemp2;              /* Data record access temp storage */
#ifdef DMC_DMA 
   DMADATA        dmadata;             /* DMA info */
#endif /* DMC_DMA */   
#endif /* DMC_DATARECORDACCESS */
#ifdef DMC_ETHERNET
   SOCKET         socket;
   SOCKET         socketMulticast;
   SOCKET         socketMessages;
   ULONG          ulMessageSize;
   SHORT          fReadMulticast;
#endif /* DMC_ETHERNET */
   CHAR           szResponse[RESPONSE_BUFFER_SIZE];
   CHAR           szUnsolicitedResponse[RESPONSE_BUFFER_SIZE];
   CONTROLLERINFO controllerinfo;
} CONTROLLER, FAR* PCONTROLLER;   

/* Global variables */
extern CHAR szTempCommand[COMMAND_BUFFER_SIZE]; 
extern CHAR szTempResponse[RESPONSE_BUFFER_SIZE]; 
extern CHAR szFileTrace[MAX_PATH];
extern CONTROLLER controller[MAX_CONTROLLERS];

/* Libary utility functions */
extern int AddIndex(PCONTROLLERINFO pcontrollerinfo);
extern int DeleteIndex(int iIndex);
extern int Handle2Index(HANDLEDMC hdmc);
extern HANDLEDMC Index2Handle(int iIndex);
extern ULONG DMCGetTime(void);
extern void /*__cdecl*/ DMCTrace(char* pFormat, ...);

/* Library I/O rotuines */
extern long ReadData(int iIndex, PCHAR pchResponse, ULONG cbResponse, PULONG pulBytesRead);
extern long WriteData(int iIndex, PCHAR pchCommand, ULONG cbCommand, PULONG pulBytesWritten);
extern long Clear();
extern int CharAvailableInput(int iIndex);

#if defined(DMC_ISABUS) || defined(DMC_PCIBUS)
/* Common bus functions */
extern long OpenDriver( int, PCONTROLLERINFO );
extern long CloseDriver(int iIndex);
#endif

#endif /* INCLUDE_DMCSUP */


