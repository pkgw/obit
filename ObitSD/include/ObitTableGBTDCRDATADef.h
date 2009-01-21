/* $Id$  */
/* DO NOT EDIT - file generated by ObitSDTables.pl                    */
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
/*;         Internet email: bcotton@nrao.edu.                        */
/*;         Postal address: William Cotton                            */
/*;                         National Radio Astronomy Observatory      */
/*;                         520 Edgemont Road                         */
/*;                         Charlottesville, VA 22903-2475 USA        */
/*--------------------------------------------------------------------*/
/*  Define the basic components of the ObitTableGBTDCRDATA  structure          */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitTableGBTDCRDATADef.h
 * ObitTableGBTDCRDATA structure members for derived classes.
 */
#include "ObitTableDef.h"  /* Parent class definitions */
/** Scan numbe */
oint  scan;
/** MJD of start tim */
oint  utdate;
/** Start tim */
odouble  utcstart;
/** Which backen */
gchar  backend[MAXKEYCHARTABLEDATA];
/** First data axis is Stat */
gchar  ctype1[MAXKEYCHARTABLEDATA];
/** Second data axis is Receive */
gchar  ctype2[MAXKEYCHARTABLEDATA];
/** Column offset for  in table record */
olong  ifflagOff;
/** Physical column number for  in table record */
olong  ifflagCol;
/** Column offset for  in table record */
olong  subscanOff;
/** Physical column number for  in table record */
olong  subscanCol;
/** Column offset for  in table record */
olong  timetagOff;
/** Physical column number for  in table record */
olong  timetagCol;
/** Column offset for  in table record */
olong  dataOff;
/** Physical column number for  in table record */
olong  dataCol;
