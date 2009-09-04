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
/*  Define the basic components of the ObitTableIDI_WEATHER  structure          */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitTableIDI_WEATHERDef.h
 * ObitTableIDI_WEATHER structure members for derived classes.
 */
#include "ObitTableDef.h"  /* Parent class definitions */
/** Table format revision number */
oint  tabrev;
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
gchar  obscode[MAXKEYCHARTABLEIDI_WEATHER];
/** Array name */
gchar  ArrName[MAXKEYCHARTABLEIDI_WEATHER];
/** Reference date as "YYYY-MM-DD" */
gchar  RefDate[MAXKEYCHARTABLEIDI_WEATHER];
/** Column offset for The center time in table record */
olong  TimeOff;
/** Physical column number for The center time in table record */
olong  TimeCol;
/** Column offset for Time interval. in table record */
olong  TimeIOff;
/** Physical column number for Time interval. in table record */
olong  TimeICol;
/** Column offset for Antenna number in table record */
olong  antNoOff;
/** Physical column number for Antenna number in table record */
olong  antNoCol;
/** Column offset for Air temperature in table record */
olong  temperatureOff;
/** Physical column number for Air temperature in table record */
olong  temperatureCol;
/** Column offset for Air pressure. in table record */
olong  pressureOff;
/** Physical column number for Air pressure. in table record */
olong  pressureCol;
/** Column offset for Dew point in table record */
olong  dewpointOff;
/** Physical column number for Dew point in table record */
olong  dewpointCol;
/** Column offset for Wind velocity in table record */
olong  wind_velocityOff;
/** Physical column number for Wind velocity in table record */
olong  wind_velocityCol;
/** Column offset for Wind direction, east from north in table record */
olong  wind_directionOff;
/** Physical column number for Wind direction, east from north in table record */
olong  wind_directionCol;
/** Column offset for Water column density in table record */
olong  wvr_h2oOff;
/** Physical column number for Water column density in table record */
olong  wvr_h2oCol;
/** Column offset for Electron column density in table record */
olong  ionos_electronOff;
/** Physical column number for Electron column density in table record */
olong  ionos_electronCol;
