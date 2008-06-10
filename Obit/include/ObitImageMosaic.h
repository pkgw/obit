/* $Id: ObitImageMosaic.h,v 1.13 2007/08/31 17:24:48 bcotton Exp $ */
/*--------------------------------------------------------------------*/
/*;  Copyright (C) 2004-2008                                          */
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
#ifndef OBITIMAGEMOSAIC_H 
#define OBITIMAGEMOSAIC_H 

#include "Obit.h"
#include "ObitErr.h"
#include "ObitThread.h"
#include "ObitInfoList.h"
#include "ObitIO.h"
#include "ObitImage.h"
#include "ObitTableCC.h"

/*-------- Obit: Merx mollis mortibus nuper ------------------*/
/**
 * \file ObitImageMosaic.h
 * ObitImageMosaic class definition.
 *
 * This class is derived from the #Obit class.
 *
 * This class contains an array of astronomical images and allows access.
 * An ObitImageMosaic is the front end to persistent disk resident 
 * structures.
 * An ObitImageMosaic is an array of associated images, generally 
 * intended to cover a region of the sky.
 * Access to members is via the member's functions.
 * Both FITS and AIPS cataloged images are supported.
 *
 * \section ObitImageMosaicaccess Creators and Destructors
 * An ObitImageMosaic can be created using newObitImageMosaic which 
 * allows specifying  a name for the object.  
 * This name is used to label messages.
 * The copy constructor ObitImageMosaicCopy will make a shallow copy
 * of an extant #ObitImageMosaic.  
 *
 * A copy of a pointer to an ObitImageMosaic should always be made using the
 * ObitImageMosaicRef function which updates the reference count in the object.
 * Then whenever freeing an ObitImageMosaic or changing a pointer, the function
 * ObitImageMosaicUnref will decrement the reference count and destroy the 
 * object when the reference count hits 0.
 *
 */

/*--------------Class definitions-------------------------------------*/
/** ObitImageMosaic Class structure. */
typedef struct {
#include "ObitImageMosaicDef.h"   /* this class definition */
} ObitImageMosaic;

/*----------------- Macroes ---------------------------*/
/** 
 * Macro to unreference (and possibly destroy) an ObitImageMosaic
 * returns a ObitImageMosaic*.
 * in = object to unreference
 */
#define ObitImageMosaicUnref(in) ObitUnref ( in)

/** 
 * Macro to reference (update reference count) an ObitImageMosaic.
 * returns a ObitImageMosaic*.
 * in = object to reference
 */
#define ObitImageMosaicRef(in) ObitRef (in)

/** 
 * Macro to determine if an object is the member of this or a 
 * derived class.
 * Returns TRUE if a member, else FALSE
 * in = object to reference
 */
#define ObitImageMosaicIsA(in) ObitIsA (in, ObitImageMosaicGetClass())

/*---------------Public functions---------------------------*/
/** Public: Class initializer. */
void ObitImageMosaicClassInit (void);

/** Public: Constructor. */
ObitImageMosaic* newObitImageMosaic (gchar* name, olong number);

/** Public: ClassInfo pointer */
gconstpointer ObitImageMosaicGetClass (void);

/** Public: Copy (shallow) constructor. */
ObitImageMosaic* 
ObitImageMosaicCopy  (ObitImageMosaic *in, ObitImageMosaic *out, 
		      ObitErr *err);

/** Public: Zap specified image. */
void 
ObitImageMosaicZapImage  (ObitImageMosaic *in, olong number,
			  ObitErr *err);

/** Public: Return specified image. */
ObitImage* 
ObitImageMosaicGetImage  (ObitImageMosaic *in, olong number,
			  ObitErr *err);

/** Public: Set specified image. */
void 
ObitImageMosaicSetImage  (ObitImageMosaic *in, olong number, 
			  ObitImage* image, ObitErr *err);

/** Public: Return RMS pixel value of  image. */
ofloat 
ObitImageMosaicGetImageRMS  (ObitImageMosaic *in, olong number,
			     ObitErr *err);

/** Public: return Full Field image image. */
ObitImage* 
ObitImageMosaicGetFullImage  (ObitImageMosaic *in, ObitErr *err);

/** Public: Set  Full Field  image. */
void 
ObitImageMosaicSetFullImage  (ObitImageMosaic *in, 
			      ObitImage* image, ObitErr *err);

/** Public: Set underlying files */
void ObitImageMosaicSetFiles  (ObitImageMosaic *in, gboolean doBeam, ObitErr *err);

/** Public: Create Mosaic from uv data */
ObitImageMosaic *ObitImageMosaicCreate (gchar *name, ObitUV *uvData, ObitErr *err);

/** Public: Define parameters of images */
void ObitImageMosaicDefine (ObitImageMosaic *in, ObitUV *uvData, gboolean doBeam,
			    ObitErr *err);

/** Public: Flatten tiles onto full field image */
void ObitImageMosaicFlatten (ObitImageMosaic *in, ObitErr *err);

/** Public: Flatten tiles onto full field image */
void ObitImageMosaicFlatten (ObitImageMosaic *in, ObitErr *err);

/** Public: Give field of view */
ofloat ObitImageMosaicFOV (ObitImageMosaic *in, ObitErr *err);

/** Public: Reimaging needed to center strong source on pixel? */
gboolean ObitImageMosaicReimage (ObitImageMosaic *mosaic, ObitErr* err);

/** Public: Get max summed CC and determine offset from nearest pixel */
void ObitImageMosaicMaxCC (ObitTableCC *CCTab, olong nccpos, ofloat radius, 
			   ofloat* maxcmp, ofloat* xcenter, ofloat* ycenter, 
			   ofloat* xoff, ofloat* yoff, ObitErr* err);

/** Public: Zero selected CC entries */
void ObitImageMosaicFlagCC (ObitTableCC *CCTab, olong nccpos, ofloat radius, 
			   ofloat xcenter, ofloat ycenter, ObitErr* err);

/** Public: Add field to mosaic */
void ObitImageMosaicAddField (ObitImageMosaic *in, ObitUV *uvData, 
			      olong nx, olong ny, olong nplane, 
			      ofloat RAShift, ofloat DecShift, ObitErr *err);
/** Public:  Generate a mosaic for peeling */
ObitImageMosaic* ObitImageMosaicMaxField (ObitImageMosaic *mosaic, 
					  ofloat MinFlux, olong *ignore, olong *field,
					  ObitErr* err); 

/*----------- ClassInfo Structure -----------------------------------*/
/**
 * ClassInfo Structure.
 * Contains class name, a pointer to any parent class
 * (NULL if none) and function pointers.
 */
typedef struct  {
#include "ObitImageMosaicClassDef.h"
} ObitImageMosaicClassInfo; 

#endif /* OBITIMAGEMOSAIC_H */ 
