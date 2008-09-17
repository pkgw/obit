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
/*  Define the basic components of the ObitTableVL  structure          */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitTableVLDef.h
 * ObitTableVL structure members for derived classes.
 */
#include "ObitTableDef.h"  /* Parent class definitions */
/** Revision number of the table definition */
oint  revision;
/** Restoring beam major axis in deg. */
ofloat  BeamMajor;
/** Restoring beam minor axis in deg. */
ofloat  BeamMinor;
/** Restoring beam position angle of major axis in deg. */
ofloat  BeamPA;
/** Column number for sort (neg -> descending) */
oint  SortOrder;
/** Number of rows in table when indexed */
oint  numIndexed;
/** First entry for RA=00 h */
oint  index00;
/** First entry for RA=01 h */
oint  index01;
/** First entry for RA=02 h */
oint  index02;
/** First entry for RA=03 h */
oint  index03;
/** First entry for RA=04 h */
oint  index04;
/** First entry for RA=05 h */
oint  index05;
/** First entry for RA=06 h */
oint  index06;
/** First entry for RA=07 h */
oint  index07;
/** First entry for RA=08 h */
oint  index08;
/** First entry for RA=09 h */
oint  index09;
/** First entry for RA=10 h */
oint  index10;
/** First entry for RA=11 h */
oint  index11;
/** First entry for RA=12 h */
oint  index12;
/** First entry for RA=13 h */
oint  index13;
/** First entry for RA=14 h */
oint  index14;
/** First entry for RA=15 h */
oint  index15;
/** First entry for RA=16 h */
oint  index16;
/** First entry for RA=17 h */
oint  index17;
/** First entry for RA=18 h */
oint  index18;
/** First entry for RA=19 h */
oint  index19;
/** First entry for RA=20 h */
oint  index20;
/** First entry for RA=21 h */
oint  index21;
/** First entry for RA=22 h */
oint  index22;
/** First entry for RA=23 h */
oint  index23;
/** Column offset for RA (J2000) in table record */
olong  Ra2000Off;
/** Physical column number for RA (J2000) in table record */
olong  Ra2000Col;
/** Column offset for Dec (J2000) in table record */
olong  Dec2000Off;
/** Physical column number for Dec (J2000) in table record */
olong  Dec2000Col;
/** Column offset for Peak Ipol in table record */
olong  PeakIntOff;
/** Physical column number for Peak Ipol in table record */
olong  PeakIntCol;
/** Column offset for Fitted major axis size in table record */
olong  MajorAxisOff;
/** Physical column number for Fitted major axis size in table record */
olong  MajorAxisCol;
/** Column offset for Fitted minor axis siz in table record */
olong  MinorAxisOff;
/** Physical column number for Fitted minor axis siz in table record */
olong  MinorAxisCol;
/** Column offset for Fitted PA in table record */
olong  PosAngleOff;
/** Physical column number for Fitted PA in table record */
olong  PosAngleCol;
/** Column offset for Center Q flux density in table record */
olong  QCenterOff;
/** Physical column number for Center Q flux density in table record */
olong  QCenterCol;
/** Column offset for enter U flux density in table record */
olong  UCenterOff;
/** Physical column number for enter U flux density in table record */
olong  UCenterCol;
/** Column offset for Integrated polarized flux density in table record */
olong  PFluxOff;
/** Physical column number for Integrated polarized flux density in table record */
olong  PFluxCol;
/** Column offset for Ipol RMS uncertainty in table record */
olong  IRMSOff;
/** Physical column number for Ipol RMS uncertainty in table record */
olong  IRMSCol;
/** Column offset for RMS (sigma) in Qpol and Upol in table record */
olong  PolRMSOff;
/** Physical column number for RMS (sigma) in Qpol and Upol in table record */
olong  PolRMSCol;
/** Column offset for RMS of Ipol residual in table record */
olong  ResRMSOff;
/** Physical column number for RMS of Ipol residual in table record */
olong  ResRMSCol;
/** Column offset for Peak in Ipol residual in table record */
olong  ResPeakOff;
/** Physical column number for Peak in Ipol residual in table record */
olong  ResPeakCol;
/** Column offset for Integrated Ipol residual in table record */
olong  ResFluxOff;
/** Physical column number for Integrated Ipol residual in table record */
olong  ResFluxCol;
/** Column offset for Center x position in pixels in FIELD in table record */
olong  CenterXOff;
/** Physical column number for Center x position in pixels in FIELD in table record */
olong  CenterXCol;
/** Column offset for Center y position in pixels in FIELD in table record */
olong  CenterYOff;
/** Physical column number for Center y position in pixels in FIELD in table record */
olong  CenterYCol;
/** Column offset for Julian date on which entry was derived from image. in table record */
olong  JDProcessOff;
/** Physical column number for Julian date on which entry was derived from image. in table record */
olong  JDProcessCol;
/** Column offset for Name of survey field in table record */
olong  FieldOff;
/** Physical column number for Name of survey field in table record */
olong  FieldCol;
