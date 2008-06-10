/* $Id: ObitDConCleanPxList.h,v 1.5 2007/08/31 17:24:48 bcotton Exp $ */
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
#ifndef OBITDCONCLEANPXLIST_H 
#define OBITDCONCLEANPXLIST_H 

#include "Obit.h"
#include "ObitErr.h"
#include "ObitImageMosaic.h"
#include "ObitDConCleanWindow.h"
#include "ObitTableCC.h"

/*-------- Obit: Merx mollis mortibus nuper ------------------*/
/**
 * \file ObitDConCleanPxList.h
 * ObitDConCleanPxList CLEAN image pixel list/CLEAN class.
 *
 * This class is derived from the #Obit class.
 * 
 * \section ObitDConCleanPxListaccess Creators and Destructors
 * An ObitDConCleanPxList will usually be created using ObitDConCleanPxListCreate which allows 
 * specifying a name for the object as well as other information.
 *
 * A copy of a pointer to an ObitDConCleanPxList should always be made using the
 * #ObitDConCleanPxListRef function which updates the reference count in the object.
 * Then whenever freeing an ObitDConCleanPxList or changing a pointer, the function
 * #ObitDConCleanPxListUnref will decrement the reference count and destroy the object
 * when the reference count hits 0.
 * There is no explicit destructor.
 */

/*--------------Class definitions-------------------------------------*/
/** ObitDConCleanPxList Class structure. */
typedef struct {
#include "ObitDConCleanPxListDef.h"   /* this class definition */
} ObitDConCleanPxList;

/*----------------- Macroes ---------------------------*/
/** 
 * Macro to unreference (and possibly destroy) an ObitDConCleanPxList
 * returns a ObitDConCleanPxList*.
 * in = object to unreference
 */
#define ObitDConCleanPxListUnref(in) ObitUnref (in)

/** 
 * Macro to reference (update reference count) an ObitDConCleanPxList.
 * returns a ObitDConCleanPxList*.
 * in = object to reference
 */
#define ObitDConCleanPxListRef(in) ObitRef (in)

/** 
 * Macro to determine if an object is the member of this or a 
 * derived class.
 * Returns TRUE if a member, else FALSE
 * in = object to reference
 */
#define ObitDConCleanPxListIsA(in) ObitIsA (in, ObitDConCleanPxListGetClass())

/*---------------Public functions---------------------------*/
/** Public: Class initializer. */
void ObitDConCleanPxListClassInit (void);

/** Public: Default Constructor. */
ObitDConCleanPxList* newObitDConCleanPxList (gchar* name);

/** Public: ClassInfo pointer */
gconstpointer ObitDConCleanPxListGetClass (void);

/** Public: Copy (deep) constructor. */
ObitDConCleanPxList* 
ObitDConCleanPxListCopy  (ObitDConCleanPxList *in, ObitDConCleanPxList *out, 
			  ObitErr *err);

/** Public: Copy structure. */
void ObitDConCleanPxListClone (ObitDConCleanPxList *in, 
			       ObitDConCleanPxList *out, 
			       ObitErr *err);

/** Public: Create/initialize ObitDCon structures */
ObitDConCleanPxList* 
ObitDConCleanPxListCreate (gchar* name, ObitImageMosaic *mosaic, 
			  olong maxPixel, ObitErr *err);

/** Public: Get Parameters. */
void ObitDConCleanPxListGetParms (ObitDConCleanPxList *in, ObitErr *err);

/** Public: Reset Clean. */
void ObitDConCleanPxListReset (ObitDConCleanPxList *in, ObitErr *err);

/** Public: Resize Arrrays. */
void ObitDConCleanPxListResize (ObitDConCleanPxList *in, olong maxPixel, 
				ObitErr *err);

/** Public: Update with new image and window. */
void ObitDConCleanPxListUpdate (ObitDConCleanPxList *in, 
				olong *fields, olong nSkip, 
				ofloat minFluxLoad,
				ofloat autoWinFlux,
				ObitDConCleanWindow *window, 
				ObitFArray *BeamPatch,
				ObitErr *err);

/** Public: Do minor cycle CLEANing. */
gboolean ObitDConCleanPxListCLEAN (ObitDConCleanPxList *in, ObitErr *err);

/** Public: Get results of CLEAN */
olong ObitDConCleanPxListResult (ObitDConCleanPxList *in, olong *ncomp,
				 ObitErr *err);

/*----------- ClassInfo Structure -----------------------------------*/
/**
 * ClassInfo Structure.
 * Contains class name, a pointer to any parent class
 * (NULL if none) and function pointers.
 */
typedef struct  {
#include "ObitDConCleanPxListClassDef.h"
} ObitDConCleanPxListClassInfo; 

#endif /*  OBITDCONCLEANBMLIST_H  */ 
