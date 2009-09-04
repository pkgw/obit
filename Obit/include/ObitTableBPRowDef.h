/* $Id$   */
/* DO NOT EDIT - file generated by ObitTables.pl                      */
/*--------------------------------------------------------------------*/
/*;  Copyright (C)  2009                                              */
/*;  Associated Universities, Inc. Washington DC, USA.                */
/*;                                                                   */
/*;  This program is free software; you can redistribute it and/or    */
/*;  modify it under the terms of the GNU General Public License as   */
/*;  published by the Free Software Foundation; either version 2 of   */
/*;  the License, or (at your option) any later version.              */
/*;                                                                   */
/*;  This program is distributed in the hope that it will be useful,  */
/*;  but WITHOUT ANY WARRANTY; without even the implied warranty of   */
/*;  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    */
/*;  GNU General Public License for more details.                     */
/*;                                                                   */
/*;  You should have received a copy of the GNU General Public        */
/*;  License along with this program; if not, write to the Free       */
/*;  Software Foundation, Inc., 675 Massachusetts Ave, Cambridge,     */
/*;  MA 02139, USA.                                                   */
/*;                                                                   */
/*;Correspondence about this software should be addressed as follows: */
/*;         Internet email: bcotton@nrao.edu.                         */
/*;         Postal address: William Cotton                            */
/*;                         National Radio Astronomy Observatory      */
/*;                         520 Edgemont Road                         */
/*;                         Charlottesville, VA 22903-2475 USA        */
/*--------------------------------------------------------------------*/
/*  Define the basic components of the ObitTableRow structure       */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitTableBPRowDef.h
 * ObitTableBPRow structure members for derived classes.
 */
#include "ObitTableRowDef.h"  /* Parent class definitions */
/** The center time. */
odouble  Time;
/** Time interval of record */
ofloat  TimeI;
/** Source ID number */
oint  SourID;
/** Subarray number */
oint  SubA;
/** Antenna number */
oint  antNo;
/** andwidth of an individual channel */
ofloat  BW;
/** Freq. id number */
oint  FreqID;
/** Frequency shift for each IF */
odouble*  ChanShift;
/** Reference Antenna */
oint  RefAnt1;
/** Weights for complex bandpass */
ofloat*  Weight1;
/** Real (channel gain Poln # 1 ) */
ofloat*  Real1;
/** Imaginary (channel gain Poln # 1) */
ofloat*  Imag1;
/** Reference Antenna */
oint  RefAnt2;
/** Weights for complex bandpass */
ofloat*  Weight2;
/** Real (channel gain Poln # 2 ) */
ofloat*  Real2;
/** Imaginary (channel gain Poln # 2) */
ofloat*  Imag2;
/** status 0=normal, 1=modified, -1=flagged */
olong  status;
