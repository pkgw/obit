/* $Id:  $   */
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
/*  Define the basic components of the ObitTableIDI_SYSTEM_TEMPERATURE  structure          */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitTableIDI_SYSTEM_TEMPERATUREDef.h
 * ObitTableIDI_SYSTEM_TEMPERATURE structure members for derived classes.
 */
#include "ObitTableDef.h"  /* Parent class definitions */
/** Table format revision number */
oint  tabrev;
/** The number of polarizations */
oint  numPol;
/** Number of Stokes parameters */
oint  no_stkd;
/** First Stokes parameter */
oint  stk_1;
/** Number of frequency bands */
oint  no_band;
/** Number of frequency channels */
oint  no_chan;
/** Reference frequency (Hz) */
odouble  ref_freq;
/** Channel bandwidth (Hz) */
odouble  chan_bw;
/** Reference frequency bin */
oint  ref_pixl;
/** Observation project code */
gchar  obscode[MAXKEYCHARTABLEIDI_SYSTEM_TEMPERATURE];
/** Array name */
gchar  ArrName[MAXKEYCHARTABLEIDI_SYSTEM_TEMPERATURE];
/** Reference date as "YYYY-MM-DD" */
gchar  RefDate[MAXKEYCHARTABLEIDI_SYSTEM_TEMPERATURE];
/** Column offset for The center time in table record */
olong  TimeOff;
/** Physical column number for The center time in table record */
olong  TimeCol;
/** Column offset for Time interval. in table record */
olong  TimeIOff;
/** Physical column number for Time interval. in table record */
olong  TimeICol;
/** Column offset for Source Identifier number in table record */
olong  SourIDOff;
/** Physical column number for Source Identifier number in table record */
olong  SourIDCol;
/** Column offset for Antenna number in table record */
olong  antNoOff;
/** Physical column number for Antenna number in table record */
olong  antNoCol;
/** Column offset for Array number. in table record */
olong  ArrayOff;
/** Physical column number for Array number. in table record */
olong  ArrayCol;
/** Column offset for Frequency ID number for row, this is a random parameter in the uv data in table record */
olong  fqidOff;
/** Physical column number for Frequency ID number for row, this is a random parameter in the uv data in table record */
olong  fqidCol;
/** Column offset for System temperature for poln # 1 in table record */
olong  TSys1Off;
/** Physical column number for System temperature for poln # 1 in table record */
olong  TSys1Col;
/** Column offset for Antenna temperature for poln # 1 in table record */
olong  TAnt1Off;
/** Physical column number for Antenna temperature for poln # 1 in table record */
olong  TAnt1Col;
/** Column offset for System temperature for poln # 2 in table record */
olong  TSys2Off;
/** Physical column number for System temperature for poln # 2 in table record */
olong  TSys2Col;
/** Column offset for Antenna temperature for poln # 2 in table record */
olong  TAnt2Off;
/** Physical column number for Antenna temperature for poln # 2 in table record */
olong  TAnt2Col;
