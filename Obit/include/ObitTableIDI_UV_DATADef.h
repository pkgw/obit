/* $Id:  $   */
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
/*  Define the basic components of the ObitTableIDI_UV_DATA  structure          */
/*  This is intended to be included in a class structure definition   */
/**
 * \file ObitTableIDI_UV_DATADef.h
 * ObitTableIDI_UV_DATA structure members for derived classes.
 */
#include "ObitTableDef.h"  /* Parent class definitions */
/** Table format revision number */
oint  tabrev;
/** Number of Stokes parameters */
oint  no_stkd;
/** First Stokes parameter */
oint  stk_1;
/** Number of frequency bands (IF) */
oint  no_band;
/** Number of frequency channels */
oint  no_chan;
/** Reference frequency (Hz) */
gdouble  ref_freq;
/** Channel bandwidth (Hz) */
gdouble  chan_bw;
/** Reference frequency bin */
oint  ref_pixl;
/** Observation project code */
gchar  obscode[MAXKEYCHARTABLEIDI_UV_DATA];
/** Array name */
gchar  ArrName[MAXKEYCHARTABLEIDI_UV_DATA];
/** Reference date as "YYYY-MM-DD" */
gchar  RefDate[MAXKEYCHARTABLEIDI_UV_DATA];
/** Number of UV data matricies */
oint  nmatrix;
/** Number of UV data matrix axes */
oint  maxis;
/** [OPTIONAL] If TRUE col. 1 has the visibility matrix */
gboolean  tmatx01;
/** [OPTIONAL] If TRUE col. 2 has the visibility matrix */
gboolean  tmatx02;
/** [OPTIONAL] If TRUE col. 3 has the visibility matrix */
gboolean  tmatx03;
/** [OPTIONAL] If TRUE col. 4 has the visibility matrix */
gboolean  tmatx04;
/** [OPTIONAL] If TRUE col. 5 has the visibility matrix */
gboolean  tmatx05;
/** [OPTIONAL] If TRUE col. 6 has the visibility matrix */
gboolean  tmatx06;
/** [OPTIONAL] If TRUE col. 7 has the visibility matrix */
gboolean  tmatx07;
/** [OPTIONAL] If TRUE col. 8 has the visibility matrix */
gboolean  tmatx08;
/** [OPTIONAL] If TRUE col. 9 has the visibility matrix */
gboolean  tmatx09;
/** [OPTIONAL] If TRUE col. 10 has the visibility matrix */
gboolean  tmatx10;
/** [OPTIONAL] If TRUE col. 11 has the visibility matrix */
gboolean  tmatx11;
/** [OPTIONAL] If TRUE col. 12 has the visibility matrix */
gboolean  tmatx12;
/** [OPTIONAL] If TRUE col. 13 has the visibility matrix */
gboolean  tmatx13;
/** [OPTIONAL] If TRUE col. 14 has the visibility matrix */
gboolean  tmatx14;
/** [OPTIONAL] If TRUE col. 15 has the visibility matrix */
gboolean  tmatx15;
/** [OPTIONAL] Number of pixels on axis 1 */
oint  maxis1;
/** [OPTIONAL] Type of data axis 1 */
gchar  ctype1[MAXKEYCHARTABLEIDI_UV_DATA];
/** [OPTIONAL] Increment in coordinate between pixels on axis 1 */
gdouble  cdelt1;
/** [OPTIONAL] Reference pixel on axis 1 */
gfloat  crpix1;
/** [OPTIONAL] Reference coordinate on axis 1 */
gdouble  crval1;
/** [OPTIONAL] Number of pixels on axis 2 */
oint  maxis2;
/** [OPTIONAL] Type of data axis 2 */
gchar  ctype2[MAXKEYCHARTABLEIDI_UV_DATA];
/** [OPTIONAL] Increment in coordinate between pixels on axis 2 */
gdouble  cdelt2;
/** [OPTIONAL] Reference pixel on axis 2 */
gfloat  crpix2;
/** [OPTIONAL] Reference coordinate on axis 2 */
gdouble  crval2;
/** [OPTIONAL] Number of pixels on axis 3 */
oint  maxis3;
/** [OPTIONAL] Type of data axis 3 */
gchar  ctype3[MAXKEYCHARTABLEIDI_UV_DATA];
/** [OPTIONAL] Increment in coordinate between pixels on axis 3 */
gdouble  cdelt3;
/** [OPTIONAL] Reference pixel on axis 3 */
gfloat  crpix3;
/** [OPTIONAL] Reference coordinate on axis 3 */
gdouble  crval3;
/** [OPTIONAL] Number of pixels on axis 4 */
oint  maxis4;
/** [OPTIONAL] Type of data axis 4 */
gchar  ctype4[MAXKEYCHARTABLEIDI_UV_DATA];
/** [OPTIONAL] Increment in coordinate between pixels on axis 4 */
gdouble  cdelt4;
/** [OPTIONAL] Reference pixel on axis 4 */
gfloat  crpix4;
/** [OPTIONAL] Reference coordinate on axis 4 */
gdouble  crval4;
/** [OPTIONAL] Number of pixels on axis 5 */
oint  maxis5;
/** [OPTIONAL] Type of data axis 5 */
gchar  ctype5[MAXKEYCHARTABLEIDI_UV_DATA];
/** [OPTIONAL] Increment in coordinate between pixels on axis 5 */
gdouble  cdelt5;
/** [OPTIONAL] Reference pixel on axis 5 */
gfloat  crpix5;
/** [OPTIONAL] Reference coordinate on axis 5 */
gdouble  crval5;
/** [OPTIONAL] Number of pixels on axis 6 */
oint  maxis6;
/** [OPTIONAL] Type of data axis 6 */
gchar  ctype6[MAXKEYCHARTABLEIDI_UV_DATA];
/** [OPTIONAL] Increment in coordinate between pixels on axis 6 */
gdouble  cdelt6;
/** [OPTIONAL] Reference pixel on axis 6 */
gfloat  crpix6;
/** [OPTIONAL] Reference coordinate on axis 6 */
gdouble  crval6;
/** [OPTIONAL] Number of pixels on axis 7 */
oint  maxis7;
/** [OPTIONAL] Type of data axis 7 */
gchar  ctype7[MAXKEYCHARTABLEIDI_UV_DATA];
/** [OPTIONAL] Increment in coordinate between pixels on axis 7 */
gdouble  cdelt7;
/** [OPTIONAL] Reference pixel on axis 7 */
gfloat  crpix7;
/** [OPTIONAL] Reference coordinate on axis 7 */
gdouble  crval7;
/** Telescope used */
gchar  teles[MAXKEYCHARTABLEIDI_UV_DATA];
/** Observer making the observations */
gchar  observer[MAXKEYCHARTABLEIDI_UV_DATA];
/** Sort order of data */
gchar  sort[MAXKEYCHARTABLEIDI_UV_DATA];
/** Column offset for U component of baseline. in table record */
olong  uuOff;
/** Physical column number for U component of baseline. in table record */
olong  uuCol;
/** Column offset for V component of baseline. in table record */
olong  vvOff;
/** Physical column number for V component of baseline. in table record */
olong  vvCol;
/** Column offset for W component of baseline. in table record */
olong  wwOff;
/** Physical column number for W component of baseline. in table record */
olong  wwCol;
/** Column offset for Julian Date in table record */
olong  dateOff;
/** Physical column number for Julian Date in table record */
olong  dateCol;
/** Column offset for The center time. in table record */
olong  TimeOff;
/** Physical column number for The center time. in table record */
olong  TimeCol;
/** Column offset for Interferometer baseline as ant 1*256+ant1 (1-rel). in table record */
olong  BaselineOff;
/** Physical column number for Interferometer baseline as ant 1*256+ant1 (1-rel). in table record */
olong  BaselineCol;
/** Column offset for Filter. in table record */
olong  FilterOff;
/** Physical column number for Filter. in table record */
olong  FilterCol;
/** Column offset for Source ID, index into SOURCE table. in table record */
olong  SourceOff;
/** Physical column number for Source ID, index into SOURCE table. in table record */
olong  SourceCol;
/** Column offset for Frequency group ID, index into FREQUENCY table. in table record */
olong  FreqIDOff;
/** Physical column number for Frequency group ID, index into FREQUENCY table. in table record */
olong  FreqIDCol;
/** Column offset for The integration time. in table record */
olong  IntTimOff;
/** Physical column number for The integration time. in table record */
olong  IntTimCol;
/** Column offset for Gate ID. in table record */
olong  GateIDOff;
/** Physical column number for Gate ID. in table record */
olong  GateIDCol;
/** Column offset for Weight per correlation, same order as data. in table record */
olong  WeightOff;
/** Physical column number for Weight per correlation, same order as data. in table record */
olong  WeightCol;
/** Column offset for Visibility matrix in table record */
olong  FluxOff;
/** Physical column number for Visibility matrix in table record */
olong  FluxCol;
