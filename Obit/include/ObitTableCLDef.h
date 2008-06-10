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
/*  Define the basic components of the ObitTableCL  structure          */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitTableCLDef.h
 * ObitTableCL structure members for derived classes.
 */
#include "ObitTableDef.h"  /* Parent class definitions */
/** Revision number of the table definition */
oint  revision;
/** The number of polarizations */
oint  numPol;
/** The number of IFs */
oint  numIF;
/** The number of antennas in table */
oint  numAnt;
/** The number of terms in model polynomial */
oint  numTerm;
/** The Mean Gain modulus */
gdouble  mGMod;
/** Column offset for The center time of the solution in table record */
olong  TimeOff;
/** Physical column number for The center time of the solution in table record */
olong  TimeCol;
/** Column offset for Solution interval. in table record */
olong  TimeIOff;
/** Physical column number for Solution interval. in table record */
olong  TimeICol;
/** Column offset for Source Identifier number in table record */
olong  SourIDOff;
/** Physical column number for Source Identifier number in table record */
olong  SourIDCol;
/** Column offset for Antenna number in table record */
olong  antNoOff;
/** Physical column number for Antenna number in table record */
olong  antNoCol;
/** Column offset for Subarray number. in table record */
olong  SubAOff;
/** Physical column number for Subarray number. in table record */
olong  SubACol;
/** Column offset for Frequency ID in table record */
olong  FreqIDOff;
/** Physical column number for Frequency ID in table record */
olong  FreqIDCol;
/** Column offset for Ionospheric Faraday Rotation in table record */
olong  IFROff;
/** Physical column number for Ionospheric Faraday Rotation in table record */
olong  IFRCol;
/** Column offset for Atmospheric delay in table record */
olong  atmosOff;
/** Physical column number for Atmospheric delay in table record */
olong  atmosCol;
/** Column offset for Time derivative of ATMOS in table record */
olong  DatmosOff;
/** Physical column number for Time derivative of ATMOS in table record */
olong  DatmosCol;
/** Column offset for Geometric delay polynomial series at TIME in table record */
olong  GeoDelayOff;
/** Physical column number for Geometric delay polynomial series at TIME in table record */
olong  GeoDelayCol;
/** Column offset for Doppler offset for each IF in table record */
olong  DopplerOffOff;
/** Physical column number for Doppler offset for each IF in table record */
olong  DopplerOffCol;
/** Column offset for Multiband delay poln # 1 in table record */
olong  MBDelay1Off;
/** Physical column number for Multiband delay poln # 1 in table record */
olong  MBDelay1Col;
/** Column offset for "Clock" epoch error in table record */
olong  clock1Off;
/** Physical column number for "Clock" epoch error in table record */
olong  clock1Col;
/** Column offset for Time derivative of CLOCK in table record */
olong  Dclock1Off;
/** Physical column number for Time derivative of CLOCK in table record */
olong  Dclock1Col;
/** Column offset for Dispersive delay (sec at wavelength = 1m)for Poln # 1 in table record */
olong  dispers1Off;
/** Physical column number for Dispersive delay (sec at wavelength = 1m)for Poln # 1 in table record */
olong  dispers1Col;
/** Column offset for Time derivative of DISPfor Poln # 1 in table record */
olong  Ddispers1Off;
/** Physical column number for Time derivative of DISPfor Poln # 1 in table record */
olong  Ddispers1Col;
/** Column offset for Real (gain Poln # 1 ) in table record */
olong  Real1Off;
/** Physical column number for Real (gain Poln # 1 ) in table record */
olong  Real1Col;
/** Column offset for Imaginary (gain Poln # 1) in table record */
olong  Imag1Off;
/** Physical column number for Imaginary (gain Poln # 1) in table record */
olong  Imag1Col;
/** Column offset for Residual fringe rate  Poln # 1 in table record */
olong  Rate1Off;
/** Physical column number for Residual fringe rate  Poln # 1 in table record */
olong  Rate1Col;
/** Column offset for Residual group delay Poln # 1 in table record */
olong  Delay1Off;
/** Physical column number for Residual group delay Poln # 1 in table record */
olong  Delay1Col;
/** Column offset for Weight of soln. Poln # 1 in table record */
olong  Weight1Off;
/** Physical column number for Weight of soln. Poln # 1 in table record */
olong  Weight1Col;
/** Column offset for Reference antenna Poln # 1 in table record */
olong  RefAnt1Off;
/** Physical column number for Reference antenna Poln # 1 in table record */
olong  RefAnt1Col;
/** Column offset for Multiband delay poln # 2 in table record */
olong  MBDelay2Off;
/** Physical column number for Multiband delay poln # 2 in table record */
olong  MBDelay2Col;
/** Column offset for "Clock" epoch error in table record */
olong  clock2Off;
/** Physical column number for "Clock" epoch error in table record */
olong  clock2Col;
/** Column offset for Time derivative of CLOCK in table record */
olong  Dclock2Off;
/** Physical column number for Time derivative of CLOCK in table record */
olong  Dclock2Col;
/** Column offset for Dispersive delay (sec at wavelength = 1m)for Poln # 2 in table record */
olong  dispers2Off;
/** Physical column number for Dispersive delay (sec at wavelength = 1m)for Poln # 2 in table record */
olong  dispers2Col;
/** Column offset for Time derivative of DISPfor Poln # 2 in table record */
olong  Ddispers2Off;
/** Physical column number for Time derivative of DISPfor Poln # 2 in table record */
olong  Ddispers2Col;
/** Column offset for Real (gain Poln # 2 ) in table record */
olong  Real2Off;
/** Physical column number for Real (gain Poln # 2 ) in table record */
olong  Real2Col;
/** Column offset for Imaginary (gain Poln # 2) in table record */
olong  Imag2Off;
/** Physical column number for Imaginary (gain Poln # 2) in table record */
olong  Imag2Col;
/** Column offset for Residual fringe rate  Poln # 2 in table record */
olong  Rate2Off;
/** Physical column number for Residual fringe rate  Poln # 2 in table record */
olong  Rate2Col;
/** Column offset for Residual group delay Poln # 2 in table record */
olong  Delay2Off;
/** Physical column number for Residual group delay Poln # 2 in table record */
olong  Delay2Col;
/** Column offset for Weight of soln. Poln # 2 in table record */
olong  Weight2Off;
/** Physical column number for Weight of soln. Poln # 2 in table record */
olong  Weight2Col;
/** Column offset for Reference antenna Poln # 2 in table record */
olong  RefAnt2Off;
/** Physical column number for Reference antenna Poln # 2 in table record */
olong  RefAnt2Col;
