/* $Id$   */
/* DO NOT EDIT - file generated by ObitTables.pl                      */
/*--------------------------------------------------------------------*/
/*;  Copyright (C)  2008                                              */
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
/*;         Internet email: bcotton@nrao.edu.                        */
/*;         Postal address: William Cotton                            */
/*;                         National Radio Astronomy Observatory      */
/*;                         520 Edgemont Road                         */
/*;                         Charlottesville, VA 22903-2475 USA        */
/*--------------------------------------------------------------------*/
/*  Define the basic components of the ObitTableRow structure       */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitTableIDI_SOURCERowDef.h
 * ObitTableIDI_SOURCERow structure members for derived classes.
 */
#include "ObitTableRowDef.h"  /* Parent class definitions */
/** Source ID */
oint  SourID;
/** Source qualifier */
oint  Qual;
/** Frequency group (AKA Band) ID */
oint  FreqID;
/** Right ascension at mean EPOCH (actually equinox) */
odouble  RAMean;
/** Declination at mean EPOCH (actually equinox) */
odouble  DecMean;
/** Mean Epoch (really equinox) for position in yr. since year 0.0 */
odouble  Epoch;
/** Apparent Right ascension */
odouble  RAApp;
/** Apparent Declination */
odouble  DecApp;
/** Proper motion (deg/day) in RA */
odouble  PMRa;
/** Proper motion (deg/day) in declination */
odouble  PMDec;
/** Parallax */
ofloat  parallax;
/** Source name */
gchar*  Source;
/** Calibrator code */
gchar*  CalCode;
/** Total Stokes I flux density per IF */
ofloat*  IFlux;
/** Total Stokes Q flux density per IF */
ofloat*  QFlux;
/** Total Stokes U flux density per IF */
ofloat*  UFlux;
/** Total Stokes V flux density per IF */
ofloat*  VFlux;
/** Spectral index per IF */
ofloat*  alpha;
/** Frequency offset (Hz) from IF nominal per IF */
odouble*  FreqOff;
/** Systemic velocity per Band (IF) */
odouble*  SysVel;
/** Velocity type */
gchar*  VelTyp;
/** Velocity definition 'RADIO' or 'OPTICAL' */
gchar*  VelDef;
/** Line rest frequency per Band (IF) */
odouble*  RestFreq;
/** status 0=normal, 1=modified, -1=flagged */
olong  status;
