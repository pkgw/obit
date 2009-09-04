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
 * \file ObitTableVLRowDef.h
 * ObitTableVLRow structure members for derived classes.
 */
#include "ObitTableRowDef.h"  /* Parent class definitions */
/** RA (J2000) */
odouble  Ra2000;
/** Dec (J2000) */
odouble  Dec2000;
/** Peak Ipol */
ofloat  PeakInt;
/** Fitted major axis size */
ofloat  MajorAxis;
/** Fitted minor axis siz */
ofloat  MinorAxis;
/** Fitted PA */
ofloat  PosAngle;
/** Center Q flux density */
ofloat  QCenter;
/** enter U flux density */
ofloat  UCenter;
/** Integrated polarized flux density */
ofloat  PFlux;
/** Ipol RMS uncertainty */
ofloat  IRMS;
/** RMS (sigma) in Qpol and Upol */
ofloat  PolRMS;
/** RMS of Ipol residual */
ofloat  ResRMS;
/** Peak in Ipol residual */
ofloat  ResPeak;
/** Integrated Ipol residual */
ofloat  ResFlux;
/** Center x position in pixels in FIELD */
ofloat  CenterX;
/** Center y position in pixels in FIELD */
ofloat  CenterY;
/** Julian date on which entry was derived from image. */
oint  JDProcess;
/** Name of survey field */
gchar*  Field;
/** status 0=normal, 1=modified, -1=flagged */
olong  status;
