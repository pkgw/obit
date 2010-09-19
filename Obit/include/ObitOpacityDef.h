/* $Id: ObitOpacityDef.h 2 2008-06-10 15:32:27Z bill.cotton $ */
/*--------------------------------------------------------------------*/
/*;  Copyright (C) 2010                                               */
/*;  Associated Universities, Inc. Washington DC, USA.                */
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
/*  Define the basic components of the ObitOpacity structure          */
/*  This is intended to be included in a class structure definition   */
/* and to be used as the template for generating new classes derived  */
/* from Obit.                                                         */
/**
 * \file ObitOpacityDef.h
 * ObitOpacity structure members for this and any derived classes.
 */
#include "ObitDef.h"  /* Parent class instance definitions */
/** Have I been properly initialized? */
gboolean amInit;
/** UV data */
ObitUV *myData;
/** Weather interpolator */
ObitWeather *weather;
/** Fractional weight of weather vs seasonal model */
ofloat WeaWt;
/** Number of subarrays */
olong numSubA;
/** Antenna list one per subarray */
ObitAntennaList **antList;
/** Source list */
ObitSourceList *souList;
/** Single source - used for single source file */
ObitSource *oneSource;
