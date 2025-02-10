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
 *  Program:        Aligner Module Computation Functions
 *
 *  File:           alcomp.h
 *
 *  Function:
 *
 *  Description:    Contains Functions and Declarations used in the alignment
 *                  computations.
 *
 *  Modification history:
 *
 *  Rev     ECO#    Date    Author          Brief Description
 *
 *********************************************************************/

#ifndef _H_ALCOMP_H
#define _H_ALCOMP_H

int ALInitNotchMeasure(int iFlatMeasureArg);
int ALMoveToNotchMeasure(int iFlatMeasArg, int iBegArg);

int ALStartNotchMeasure(int iFlatBeginingArg);
int ALNotchMeasureDir(int *ipFlatBeginingArg);
int ALComputeOffset(long lOffsetArg, int iRMovementArg);
int ALCorrectOffset(void);
int ALHomeChuck(void); 
int ALFilterRound(int iIndexArg); 
int ALFindFlat(void); 
int ALCalcCenterOffset(int *ipIndex1Arg, int *ipIndex2Arg, int *ipIndex3Arg);

int ALCalcCircleOffset(int *ipIndexArg, double *dpAngleArg, double *dpRadiusArg );
int ALFindNotchStartIndex(void);   
int ALCorrectNotchAngle(int iFlatBeginArg, int iPassNumArg);  
int ALFindNotchPosition(int iFlatBeginArg); 
int ALRotateChuck420(void);          
int ALFindShortestMove(long lFixAngleArg, long *lpMoveAngleArg);  
int ALCorrectNormAngle(long lOldPosArg, long *lpNewPosArg); 
int ALComputeWaferCenter(void);  
int ALInitWaferCenterVar(void);  
int ALCenterCircuit(void);  
int ALGetSpeedChange(long lOldPos, long lNewPos, long *lpMult);
int ALOffsetAnglePosition(void); 
int ALMoveToNotchPosition(void);      
void ALSQCalcFittest(double *dpSideXArg, double *dpSideYArg, int iLenArg);
                                    
int  ALSQCheckPeak(int iIndexArg);
void ALSQListBreaks(void); 
int  ALSQAlign(void);        
void ALSQCalibrateCCD(void);   
int  ALSQFindNotch(void);    

int ALDetectPrealigner(void);  
int ALSetPrealignerMode(int iModeArg); 
int ALSetFineScanSpeed(void);
int ALSinglePickAlignment(void);
int ALSinglePickPosition();
int ALFindNotchMidAngle(long *lpPositionArg);
int ALSinglePickNormAngle (double *dAngleArg);
int ALChangeFastMode(int iFlagArg, long lDistArg);
int ALCalcSinglePick(void);

long ALReadNotchAngle( void );

#endif
