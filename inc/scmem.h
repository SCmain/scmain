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
 * File:        heap.h
 * Functions:   HPHeapDump
 *              HPHeapStat
 *              HPmalloc
 *              HPfree
 *              HPGetMemLowFlag
 *              HPPreallocate
 *
 * Description: Tests the heap memory and NVSRAM memory for
 *      status and availability
 *
 * Modification history:
 * Rev      ECO#    Date    Author      Brief Description
 *
 ****************************************************************/

#ifndef _H_HEAP_H
#define _H_HEAP_H

/********** FUNCTION PROTOTYPES **********/
int HPGetMemLowFlag();
int HPPreAllocate();
void  *HPmalloc(size_t MemSizeArg);
void HPfree(void *pMem);

/***************************************************************\
 *
 * Replaces: heapdump
 * Used in: execute, heap
 * Description: This function is multi-purpose. It starts by
 *      finding the amount of heap space used and the amount
 *      freed during the last operation. Then it optimizies the
 *      heap. Then it checks the B: drive (NVSRAM) and reports on
 *      the amount of memory still available. Finally it
 *      allocates memory in 1kB blocks until there are no more
 *      contiguous 1kB blocks of memory left. It then frees
 *      that memory and exits.
 *
\***************************************************************/
int HPHeapDump(long *lpHeapResultsArg);

/***************************************************************\
 *
 * Replaces: heapstat
 * Used in: heap
 * Description: Reports on the status returned by _heapwalk,
 *      _heapset, or _heapchk. This function is the first
 *      call made to check initially that the heap is OK.
 *      It is called a second time after the check for heap
 *      space used and freed during the last operation. It is
 *      basically a status printing function.
 *
\***************************************************************/
int HPHeapStat(int iHeapStatArg);

#endif
