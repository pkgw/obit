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
#ifndef OBITTABLEPC_H 
#define OBITTABLEPC_H 

#include "Obit.h"
#include "ObitErr.h"
#include "ObitTable.h"
#include "ObitData.h"

/*-------- Obit: Merx mollis mortibus nuper ------------------*/
/**
 * \file ObitTablePC.h
 * ObitTablePC class definition.
 *
 * This class is derived from the #ObitTable class.
 *
 * This class contains tabular data and allows access.
 * "AIPS PC" contains pulsed phase cal. info
 * An ObitTablePC is the front end to a persistent disk resident structure.
 * Both FITS and AIPS cataloged data are supported.
 * This class is derived from the ObitTable class. 
 *
 * This class contains tabular data and allows access.
 * "AIPS PC" table
 * An ObitTablePC is the front end to a persistent disk resident structure.
 * Both FITS (as Tables) and AIPS cataloged data are supported.
 *
 * \section TableDataStorage Table data storage
 * In memory tables are stored in a fashion similar to how they are 
 * stored on disk - in large blocks in memory rather than structures.
 * Due to the word alignment requirements of some machines, they are 
 * stored by order of the decreasing element size: 
 * double, float long, int, short, char rather than the logical order.
 * The details of the storage in the buffer are kept in the 
 * #ObitTablePCDesc.
 *
 * In addition to the normal tabular data, a table will have a "_status"
 * column to indicate the status of each row.
 * The status value is read from and written to (some modification) AIPS 
 * tables but are not written to externally generated FITS tables which
 * don't have these colummns.  It will be written to Obit generated tables
 * which will have these columns.
 * Status values:
 * \li status = 0 => normal
 * \li status = 1 => row has been modified (or created) and needs to be
 *                   written.
 * \li status = -1 => row has been marked invalid.
 *
 * \section ObitTablePCSpecification Specifying desired data transfer parameters
 * The desired data transfers are specified in the member ObitInfoList.
 * There are separate sets of parameters used to specify the FITS or AIPS 
 * data files.
 * In the following an ObitInfoList entry is defined by 
 * the name in double quotes, the data type code as an #ObitInfoType enum 
 * and the dimensions of the array (? => depends on application).
 * To specify whether the underlying data files are FITS or AIPS
 * \li "FileType" OBIT_int (1,1,1) OBIT_IO_FITS or OBIT_IO_AIPS 
 * which are values of an #ObitIOType enum defined in ObitIO.h.
 *
 * The following apply to both types of files:
 * \li "nRowPIO", OBIT_int, Max. Number of visibilities per 
 *     "Read" or "Write" operation.  Default = 1.
 *
 * \subsection TableFITS FITS files
 * This implementation uses cfitsio which allows using, in addition to 
 * regular FITS images, gzip compressed files, pipes, shared memory 
 * and a number of other input forms.
 * The convenience Macro #ObitTablePCSetFITS simplifies specifying the 
 * desired data.
 * Binary tables are used for storing visibility data in FITS.
 * For accessing FITS files the following entries in the ObitInfoList 
 * are used:
 * \li "FileName" OBIT_string (?,1,1) FITS file name.
 * \li "TabName"  OBIT_string (?,1,1) Table name (e.g. "AIPS CC").
 * \li "Ver"      OBIT_int    (1,1,1) Table version number
 *
 * subsection ObitTablePCAIPS AIPS files
 * The ObitAIPS class must be initialized before accessing AIPS files; 
 * this uses #ObitAIPSClassInit.
 * For accessing AIPS files the following entries in the ObitInfoList 
 * are used:
 * \li "Disk" OBIT_int (1,1,1) AIPS "disk" number.
 * \li "User" OBIT_int (1,1,1) user number.
 * \li "CNO"  OBIT_int (1,1,1) AIPS catalog slot number.
 * \li "TableType" OBIT_string (2,1,1) AIPS Table type
 * \li "Ver"  OBIT_int    (1,1,1) AIPS table version number.
 *
 * \section ObitTablePCaccess Creators and Destructors
 * An ObitTablePC can be created using newObitTablePCValue which attaches the 
 * table to an ObitData for the object.  
 * If the output ObitTablePC has previously been specified, including file information,
 * then ObitTablePCCopy will copy the disk resident as well as the memory 
 * resident information.
 *
 * A copy of a pointer to an ObitTablePC should always be made using the
 * ObitTablePCRef function which updates the reference count in the object.
 * Then whenever freeing an ObitTablePC or changing a pointer, the function
 * ObitTablePCUnref will decrement the reference count and destroy the object
 * when the reference count hits 0.
 *
 * \section ObitTablePCUsage I/O
 * Visibility data is available after an input object is "Opened"
 * and "Read".
 * I/O optionally uses a buffer attached to the ObitTablePC or some external
 * location.
 * To Write an ObitTablePC, create it, open it, and write.
 * The object should be closed to ensure all data is flushed to disk.
 * Deletion of an ObitTablePC after its final unreferencing will automatically
 * close it.
 */

/*--------------Class definitions-------------------------------------*/

/** Number of characters for Table keyword */
 #define MAXKEYCHARTABLEPC 24

/** ObitTablePC Class structure. */
typedef struct {
#include "ObitTablePCDef.h"   /* this class definition */
} ObitTablePC;

/** ObitTablePCRow Class structure. */
typedef struct {
#include "ObitTablePCRowDef.h"   /* this class row definition */
} ObitTablePCRow;

/*----------------- Macroes ---------------------------*/
/** 
 * Macro to unreference (and possibly destroy) an ObitTablePC
 * returns an ObitTablePC*.
 * in = object to unreference
 */
#define ObitTablePCUnref(in) ObitUnref (in)

/** 
 * Macro to reference (update reference count) an ObitTablePC.
 * returns an ObitTablePC*.
 * in = object to reference
 */
#define ObitTablePCRef(in) ObitRef (in)

/** 
 * Macro to determine if an object is the member of this or a 
 * derived class.
 * Returns TRUE if a member, else FALSE
 * in = object to reference
 */
#define ObitTablePCIsA(in) ObitIsA (in, ObitTablePCGetClass())

/** 
 * Macro to unreference (and possibly destroy) an ObitTablePCRow
 * returns an ObitTablePCRow*.
 * in = object to unreference
 */
#define ObitTablePCRowUnref(in) ObitUnref (in)

/** 
 * Macro to reference (update reference count) an ObitTablePCRow.
 * returns an ObitTablePCRow*.
 * in = object to reference
 */
#define ObitTablePCRowRef(in) ObitRef (in)

/** 
 * Macro to determine if an object is the member of this or a 
 * derived class.
 * Returns TRUE if a member, else FALSE
 * in = object to reference
 */
#define ObitTablePCRowIsA(in) ObitIsA (in, ObitTablePCRowGetClass())

/*---------------Public functions---------------------------*/
/*----------------Table Row Functions ----------------------*/
/** Public: Row Class initializer. */
void ObitTablePCRowClassInit (void);

/** Public: Constructor. */
ObitTablePCRow* newObitTablePCRow (ObitTablePC *table);

/** Public: ClassInfo pointer */
gconstpointer ObitTablePCRowGetClass (void);

/*------------------Table Functions ------------------------*/
/** Public: Class initializer. */
void ObitTablePCClassInit (void);

/** Public: Constructor. */
ObitTablePC* newObitTablePC (gchar* name);

/** Public: Constructor from values. */
ObitTablePC* 
newObitTablePCValue (gchar* name, ObitData *file, olong *ver,
  		     ObitIOAccess access,
                     oint numPol, oint numBand, oint numTones,
		     ObitErr *err);

/** Public: Class initializer. */
void ObitTablePCClassInit (void);

/** Public: ClassInfo pointer */
gconstpointer ObitTablePCGetClass (void);

/** Public: Copy (deep) constructor. */
ObitTablePC* ObitTablePCCopy  (ObitTablePC *in, ObitTablePC *out, 
			   ObitErr *err);

/** Public: Copy (shallow) constructor. */
ObitTablePC* ObitTablePCClone (ObitTablePC *in, ObitTablePC *out);

/** Public: Convert an ObitTable to an ObitTablePC */
ObitTablePC* ObitTablePCConvert  (ObitTable *in);

/** Public: Create ObitIO structures and open file */
ObitIOCode ObitTablePCOpen (ObitTablePC *in, ObitIOAccess access, 
			  ObitErr *err);

/** Public: Read a table row */
ObitIOCode 
ObitTablePCReadRow  (ObitTablePC *in, olong iPCRow, ObitTablePCRow *row,
		     ObitErr *err);

/** Public: Init a table row for write */
void 
ObitTablePCSetRow  (ObitTablePC *in, ObitTablePCRow *row,
		     ObitErr *err);

/** Public: Write a table row */
ObitIOCode 
ObitTablePCWriteRow  (ObitTablePC *in, olong iPCRow, ObitTablePCRow *row,
		     ObitErr *err);

/** Public: Close file and become inactive */
ObitIOCode ObitTablePCClose (ObitTablePC *in, ObitErr *err);

/*----------- ClassInfo Structure -----------------------------------*/
/**
 * ClassInfo Structure.
 * Contains class name, a pointer to any parent class
 * (NULL if none) and function pointers.
 */
typedef struct  {
#include "ObitTablePCClassDef.h"
} ObitTablePCClassInfo; 

/**
 * ClassInfo Structure For TablePCRow.
 * Contains class name, a pointer to any parent class
 * (NULL if none) and function pointers.
 */
typedef struct  {
#include "ObitTablePCRowClassDef.h"
} ObitTablePCRowClassInfo; 
#endif /* OBITTABLEPC_H */ 
