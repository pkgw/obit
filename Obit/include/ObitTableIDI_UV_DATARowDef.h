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
 * \file ObitTableIDI_UV_DATARowDef.h
 * ObitTableIDI_UV_DATARow structure members for derived classes.
 */
#include "ObitTableRowDef.h"  /* Parent class definitions */
/** U component of baseline. */
gfloat  uu;
/** V component of baseline. */
gfloat  vv;
/** W component of baseline. */
gfloat  ww;
/** Julian Date */
gdouble  date;
/** The center time. */
gdouble  Time;
/** Interferometer baseline as ant 1*256+ant1 (1-rel). */
oint  Baseline;
/** Filter. */
oint  Filter;
/** Source ID, index into SOURCE table. */
oint  Source;
/** Frequency group ID, index into FREQUENCY table. */
oint  FreqID;
/** The integration time. */
gfloat  IntTim;
/** Gate ID. */
oint  GateID;
/** Weight per correlation, same order as data. */
gfloat*  Weight;
/** Visibility matrix */
gfloat*  Flux;
/** status 0=normal, 1=modified, -1=flagged */
olong  status;
