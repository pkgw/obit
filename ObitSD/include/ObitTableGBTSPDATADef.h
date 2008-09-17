/* $Id$  */
/* DO NOT EDIT - file generated by ObitSDTables.pl                    */
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
/*  Define the basic components of the ObitTableGBTSPDATA  structure          */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitTableGBTSPDATADef.h
 * ObitTableGBTSPDATA structure members for derived classes.
 */
#include "ObitTableDef.h"  /* Parent class definitions */
/** Source name */
gchar  object[MAXKEYCHARTABLEDATA];
/** Scan number */
oint  scan;
/** MJD of start time */
oint  utdate;
/** Start time in seconds. */
odouble  utcstart;
/** Stop time in seconds. */
odouble  utcstop;
/** Integration time in seconds. */
odouble  inttime;
/** First data axis is State */
gchar  ctype1[MAXKEYCHARTABLEDATA];
/** Second data axis is Receiver */
gchar  ctype2[MAXKEYCHARTABLEDATA];
/** Column offset for  in table record */
olong  subscanOff;
/** Physical column number for  in table record */
olong  subscanCol;
/** Column offset for  in table record */
olong  utdateOff;
/** Physical column number for  in table record */
olong  utdateCol;
/** Column offset for  in table record */
olong  utcstartOff;
/** Physical column number for  in table record */
olong  utcstartCol;
/** Column offset for Pulsar period. in table record */
olong  psrperOff;
/** Physical column number for Pulsar period. in table record */
olong  psrperCol;
/** Column offset for Data in table record */
olong  dataOff;
/** Physical column number for Data in table record */
olong  dataCol;
