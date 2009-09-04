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
/*  Define the basic components of the ObitTableOF  structure          */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitTableOFDef.h
 * ObitTableOF structure members for derived classes.
 */
#include "ObitTableDef.h"  /* Parent class definitions */
/** Revision number of the table definition */
oint  revision;
/** Observation code */
gchar  obscode[MAXKEYCHARTABLEOF];
/** Reference date as "YYYYMMDD" */
gchar  RefDate[MAXKEYCHARTABLEOF];
/** Column offset for The center time of the sscan. in table record */
olong  TimeOff;
/** Physical column number for The center time of the sscan. in table record */
olong  TimeCol;
/** Column offset for Duration of scan in table record */
olong  TimeIOff;
/** Physical column number for Duration of scan in table record */
olong  TimeICol;
/** Column offset for Source ID as defined in then SOURCE table in table record */
olong  SourIDOff;
/** Physical column number for Source ID as defined in then SOURCE table in table record */
olong  SourIDCol;
/** Column offset for Antenna number in table record */
olong  antNoOff;
/** Physical column number for Antenna number in table record */
olong  antNoCol;
/** Column offset for Subarray number in table record */
olong  SubAOff;
/** Physical column number for Subarray number in table record */
olong  SubACol;
/** Column offset for Frequency id of scan in table record */
olong  FreqIDOff;
/** Physical column number for Frequency id of scan in table record */
olong  FreqIDCol;
/** Column offset for Reference pointing(?) flag in table record */
olong  refPntOff;
/** Physical column number for Reference pointing(?) flag in table record */
olong  refPntCol;
/** Column offset for Antenna shadowed(?) flag in table record */
olong  shadowOff;
/** Physical column number for Antenna shadowed(?) flag in table record */
olong  shadowCol;
