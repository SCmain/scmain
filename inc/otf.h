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
 * Program:     OTF Header File
 * File:        otf.H
 * Functions:
 *
 * Description: Declarations of local variables and functions
 *              for OTF module
 *
 * Modification history:
 * Rev      ECO#    Date    Author          Brief Description
 *
\***************************************************************/

#ifndef  _H_OTF_H
#define  _H_OTF_H

#include "mapk.h"

#define NUMBER_OF_OTF_POINTS    6
#define MAX_OTF_INTERRUPTS      12
#define OTF_FILE_NAME           "/root/controller/scmain/otf.par"
#define MM_TO_INCHES            25.4

typedef  struct  stOTFStationStructure
{
    char  m_cStationName;
    float m_fOTFRef[NOFSLOTS][2];                             // 0 = X, 1 = Y
    float m_fOTFDistance[3];                                  // Distance of 1., 2., 3. sensor from Xxis
    float m_fOTFSensorComp[NOFSLOTS][NUMBER_OF_OTF_POINTS];   // sensor hysteresys compensation
    long  m_lOTFFinalCorrection[NOFSLOTS][3];                 // Stored final correction for T, R, R-offset
    long  m_lOTFReserved[5];
    int   m_iSortedIndex[NOFSLOTS][NUMBER_OF_OTF_POINTS];             // Sorted Index
    long  m_lEELength;
    long  m_lSlotNumber;
    long  m_lRStartSampling;                                  // Used by Macro to store the R coordinate to start Interrupt mask
    long  m_lROffset;
    long  m_lFinalPos[2];                                     // Final position for T and R
    struct stOTFStationStructure  *m_pstNextOTFStation;
    long  m_lOTFData[6];
    long  m_lSensorMap[6];
} stOTFStation,  *psOTFStation;

int MPSetOTFPositions(int iArrayIndexArg, int iValueArg);
int MPGetOTFPositions(long laXCoordinate[], long laYCoordinate[]);
int MPSetOTFSensorMap(int iArrayIndexArg, int iValueArg);
int MPGetOTFSensorMap(int iaSensorsBitMap[]);
int MPGetOTFCenters(float faXCentersCoordinates[], float faYCentersCoordinates[]);
int MPGetNumberOfOTFInterrupts(int *piNumOfOTFInterrupts);
psOTFStation MPGetOTFHeadStationsPointer();
psOTFStation MPGetOTFCurrentStationPointer();
int MPSetOTFHeadStationsPointer(psOTFStation psPointerArg);
int MPSetOTFCurrentStationPointer(psOTFStation psPointerArg);
int MPAddNewOTFStation (char cStationNameArg);
int MPFindOTFStation (char cStationNameArg, int iCreateNewFlag);
void MPBitMapInit(int *piSenArg, int iBitMapArg);
int MPSetOTFItem(char cStationNameArg, long *plValuesArg);
int MPReadOTFItem(char cStationNameArg, long *plValuesArg);
int MPAligning(double dTOffsetDestinationArg, double dROffsetDestinationArg, double dTOffsetSourceArg,
            int iCalibrateArg, char cSourceStationNameArg, int iIOShiftArg );
int MPPrepareOTFAligning();
int MPQuitOTFAligning(int *piOTFBufferOverflowArg);
int MPEnableOTFInterrupts(void);
int MPDisableOTFInterrupts(void);
int MPCollectOTFData(int aiCustomerPortBitmapArg[]);
int MPGetOTFBufferOverflow();
int MPGetOTFAligning();

#endif
