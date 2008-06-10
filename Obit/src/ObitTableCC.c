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
#include "ObitTableCC.h"
#include "ObitTableList.h"
#include "ObitData.h"

/*----------------Obit:  Merx mollis mortibus nuper ------------------*/
/**
 * \file ObitTableCC.c
 * ObitTableCC class function definitions.
 *
 * This class is derived from the #ObitTable class.
 */

/** name of the class defined in this file */
static gchar *myClassName = "ObitTableCC";

/**  Function to obtain parent Table ClassInfo - ObitTable */
static ObitGetClassFP ObitParentGetClass = ObitTableGetClass;

/** name of the Row class defined in this file */
static gchar *myRowClassName = "ObitTableCCRow";

/**  Function to obtain parent TableRow ClassInfo */
static ObitGetClassFP ObitParentGetRowClass = ObitTableRowGetClass;

/*--------------- File Global Variables  ----------------*/
/*----------------  Table Row  ----------------------*/
/**
 * ClassInfo structure ObitTableClassInfo.
 * This structure is used by class objects to access class functions.
 */
static ObitTableCCRowClassInfo myRowClassInfo = {FALSE};

/*------------------  Table  ------------------------*/
/**
 * ClassInfo structure ObitTableCCClassInfo.
 * This structure is used by class objects to access class functions.
 */
static ObitTableCCClassInfo myClassInfo = {FALSE};

/*---------------Private function prototypes----------------*/
/** Private: Initialize newly instantiated Row object. */
void  ObitTableCCRowInit  (gpointer in);

/** Private: Deallocate Row members. */
void  ObitTableCCRowClear (gpointer in);

/** Private: Initialize newly instantiated object. */
void  ObitTableCCInit  (gpointer in);

/** Private: Deallocate members. */
void  ObitTableCCClear (gpointer in);

/** Private: update table specific info */
static void ObitTableCCUpdate (ObitTableCC *in, ObitErr *err);

/** Private: copy table keywords to descriptor info list */
static void ObitTableCCDumpKey (ObitTableCC *in, ObitErr *err);

/** Private: Set Class function pointers */
static void ObitTableCCClassInfoDefFn (gpointer inClass);

/** Private: Set Row Class function pointers */
static void ObitTableCCRowClassInfoDefFn (gpointer inClass);
/*----------------------Public functions---------------------------*/

/*------------------  Table Row ------------------------*/
/**
 * Constructor.
 * If table is open and for write, the row is attached to the buffer
 * Initializes Row class if needed on first call.
 * \param name An optional name for the object.
 * \return the new object.
 */
ObitTableCCRow* newObitTableCCRow (ObitTableCC *table)
{
  ObitTableCCRow* out;
  odouble   *dRow;
  oint      *iRow;
  gshort    *siRow;
  ofloat    *fRow;
  gchar     *cRow;
  gboolean  *lRow;
  guint8    *bRow;

  /* Class initialization if needed */
  if (!myRowClassInfo.initialized) ObitTableCCRowClassInit();

  /* allocate/init structure */
  out = g_malloc0(sizeof(ObitTableCCRow));

  /* initialize values */
  out->name = g_strdup("TableCC Row");

  /* set ClassInfo */
  out->ClassInfo = (gpointer)&myRowClassInfo;

  /* initialize other stuff */
  ObitTableCCRowInit((gpointer)out);
  out->myTable   = (ObitTable*)ObitTableRef((ObitTable*)table);

  /* If writing attach to buffer */
  if ((table->buffer) && (table->myDesc->access != OBIT_IO_ReadOnly) &&
      (table->myStatus != OBIT_Inactive)) {
    /* Typed pointers to row of data */  
    dRow  = (odouble*)table->buffer;
    iRow  = (oint*)table->buffer;
    siRow = (gshort*)table->buffer;
    fRow  = (ofloat*)table->buffer;
    cRow  = (gchar*)table->buffer;
    lRow  = (gboolean*)table->buffer;
    bRow  = (guint8*)table->buffer;
  
    /* Set row pointers to buffer */
    out->parms = fRow + table->parmsOff;
  } /* end attaching row to table buffer */

 return out;
} /* end newObitTableCCRow */

/**
 * Returns ClassInfo pointer for the Row class.
 * \return pointer to the Row class structure.
 */
gconstpointer ObitTableCCRowGetClass (void)
{
  /* Class initialization if needed */
  if (!myRowClassInfo.initialized) ObitTableCCRowClassInit();
  return (gconstpointer)&myRowClassInfo;
} /* end ObitTableCCRowGetClass */

/*------------------  Table  ------------------------*/
/**
 * Constructor.
 * Initializes class if needed on first call.
 * \param name An optional name for the object.
 * \return the new object.
 */
ObitTableCC* newObitTableCC (gchar* name)
{
  ObitTableCC* out;

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableCCClassInit();

  /* allocate/init structure */
  out = g_malloc0(sizeof(ObitTableCC));

  /* initialize values */
  if (name!=NULL) out->name = g_strdup(name);
  else out->name = g_strdup("Noname");

  /* set ClassInfo */
  out->ClassInfo = (gpointer)&myClassInfo;

  /* initialize other stuff */
  ObitTableCCInit((gpointer)out);

 return out;
} /* end newObitTableCC */

/**
 * Returns ClassInfo pointer for the class.
 * \return pointer to the class structure.
 */
gconstpointer ObitTableCCGetClass (void)
{
  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableCCClassInit();

  return (gconstpointer)&myClassInfo;
} /* end ObitCCGetClass */

/**
 * Constructor from values.
 * Creates a new table structure and attaches to the TableList of file.
 * If the specified table already exists then it is returned.
 * Initializes class if needed on first call.
 * Forces an update of any disk resident structures (e.g. AIPS header).
 * \param name   An optional name for the object.
 * \param file   ObitData which which the table is to be associated.
 * \param ver    Table version number. 0=> add higher, value used returned
 * \param access access (OBIT_IO_ReadOnly, means do not create if it doesn't exist.
 * \param noParms Number of parameters for non point components, usually 0 or 4
 * \param err Error stack, returns if not empty.
 * \return the new object, NULL on failure.
 */
ObitTableCC* newObitTableCCValue (gchar* name, ObitData *file, olong *ver,
 	                    ObitIOAccess access,
  		     oint noParms,
		     ObitErr *err)
{
  ObitTableCC* out=NULL;
  ObitTable *testTab=NULL;
  ObitTableDesc *desc=NULL;
  ObitTableList *list=NULL;
  ObitInfoList  *info=NULL;
  gboolean exist, optional;
  olong colNo, i, ncol, highVer;
  ObitIOCode retCode;
  gchar *tabType = "AIPS CC";
  gchar *routine = "newObitTableCCValue";

 /* error checks */
  g_assert(ObitErrIsA(err));
  if (err->error) return NULL;
  g_assert (ObitDataIsA(file));

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableCCClassInit();

  /* Check if the table already exists */
  /* Get TableList */
  list = ((ObitData*)file)->tableList;
  info = ((ObitData*)file)->info;

  /* Get highest version number if not specified */
  if (*ver==0) { 
    highVer = ObitTableListGetHigh (list, "AIPS CC");
    if (access==OBIT_IO_ReadOnly) *ver = highVer;
    else if (access==OBIT_IO_ReadWrite) *ver = highVer;
    else if (access==OBIT_IO_WriteOnly) *ver = highVer+1;
  }
  /* See if it already exists */
  exist = FALSE;
  if (*ver>0) { /* has to be specified */
    exist = ObitTableListGet(list, tabType, ver, &testTab, err);
    if (err->error) /* add traceback,return */
      Obit_traceback_val (err, routine,"", out);
  
    /* if readonly, it must exist to proceed */
    if ((access==OBIT_IO_ReadOnly) && !exist) return out;
    if (testTab!=NULL) { /* it exists, use it if is an ObitTableCC */
      if (ObitTableCCIsA(testTab)) { /* it is an ObitTableCC */
	out = ObitTableRef(testTab);
      } else { /* needs conversion */
 	out = ObitTableCCConvert(testTab);
	/* Update the TableList */
	ObitTableListPut(list, tabType, ver, (ObitTable*)out, err);
	if (err->error) /* add traceback,return */
	  Obit_traceback_val (err, routine,"", out);
      }
      testTab = ObitTableUnref(testTab); /* remove reference */
      return out; /* done */
    }
  } /* end of test for previously existing table */
  
  /* If access is ReadOnly make sure one exists */
  if (access==OBIT_IO_ReadOnly) { 
    highVer = ObitTableListGetHigh (list, "AIPS CC");
    if (highVer<=0) return out;
  }
  
  /* create basal table */
  testTab = newObitDataTable ((ObitData*)file, access, tabType,
			       ver, err);
  if (err->error) Obit_traceback_val (err, routine,"", out);
  
  /* likely need to convert */
  if (ObitTableCCIsA(testTab)) { 
    out = ObitTableRef(testTab);
  } else { /* needs conversion */
    out = ObitTableCCConvert(testTab);
  }
  testTab = ObitTableUnref(testTab); /* remove reference */

  /* Update the TableList */
  ObitTableListPut(list, tabType, ver, (ObitTable*)out, err);
  if (err->error) Obit_traceback_val (err, routine,"", out);

  /* if it previously existed merely return it */
  if (exist) return out; 

  /* set ClassInfo */
  out->ClassInfo = (gpointer)&myClassInfo;

  /* Set values */
  out->noParms = MAX (0, noParms);

  /* initialize descriptor */
  desc = out->myDesc;
  /* How many columns actually in table? */
  ncol = 4 + out->noParms*0 ;
  desc->FieldName = g_malloc0((ncol+1)*sizeof(gchar*));
  desc->FieldUnit = g_malloc0((ncol+1)*sizeof(gchar*));
  desc->type      = g_malloc0((ncol+1)*sizeof(ObitInfoType));
  desc->dim       = g_malloc0((ncol+1)*sizeof(gint32*));
  for (i=0; i<ncol+1; i++) 
    desc->dim[i] = g_malloc0(MAXINFOELEMDIM*sizeof(gint32));

  desc->TableName = g_strdup(tabType);
  desc->sort[0] = 0;
  desc->sort[1] = 0;
  colNo = 0;

  /* Define Columns */
  desc->FieldName[colNo] = g_strdup("FLUX    ");
  desc->FieldUnit[colNo] = g_strdup("JY");
  desc->type[colNo] = OBIT_float;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("DELTAX  ");
  desc->FieldUnit[colNo] = g_strdup("DEGREE");
  desc->type[colNo] = OBIT_float;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("DELTAY  ");
  desc->FieldUnit[colNo] = g_strdup("DEGREE");
  desc->type[colNo] = OBIT_float;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  optional = TRUE;
  if ((noParms > 0) || (!optional)) {
    desc->FieldName[colNo] = g_strdup("PARMS   ");
    desc->FieldUnit[colNo] = g_strdup("");
    desc->type[colNo] = OBIT_float;
    for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
    desc->dim[colNo][0] = noParms;
    colNo++;
  }
  /* Add _status column at end */
  desc->FieldName[colNo] = g_strdup("_status");
  desc->FieldUnit[colNo] = g_strdup("        ");
  desc->type[colNo] = OBIT_long;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  
  /* number of fields */
  desc->nfield = colNo + 1;

  /* initialize descriptor keywords */
  ObitTableCCDumpKey (out, err);
 
  /* index table descriptor */
  ObitTableDescIndex (desc);

  /* Open and Close to fully instantiate */
  retCode = ObitTableCCOpen(out, OBIT_IO_WriteOnly, err);
  if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
    Obit_traceback_val (err, routine, out->name, out);    
  
  retCode = ObitTableCCClose(out, err);
  if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
    Obit_traceback_val (err, routine, out->name, out); 

  /* Force update of disk resident info */
  retCode = ObitIOUpdateTables (((ObitData*)file)->myIO, info, err);
  if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
    Obit_traceback_val (err, routine, out->name, out); 
  
 return out;
} /* end newObitTableCCValue */

/**
 * Convert an ObitTable to an ObitTableCC.
 * New object will have references to members of in.
 * \param in  The object to copy, will still exist afterwards 
 *            and should be Unrefed if not needed.
 * \return pointer to the new object.
 */
ObitTableCC* ObitTableCCConvert (ObitTable* in)
{
  ObitTableCC *out;

  /* error check */
  g_assert(ObitTableIsA(in));

  /* create basic object */
  out = newObitTableCC(in->name);

  /* Delete structures on new */
  out->info   = ObitInfoListUnref(out->info);
  out->thread = ObitThreadUnref(out->thread);
  out->myDesc = ObitTableDescUnref(out->myDesc);
  out->mySel  = ObitTableSelUnref(out->mySel);
  
  /* Reference members of in */
  
  out->info   = ObitInfoListRef(in->info);
  out->thread = ObitThreadRef(in->thread);
  out->myDesc = ObitTableDescRef(in->myDesc);
  out->mySel  = ObitTableSelRef(in->mySel);

  /* Remember who I am */
 out->tabType = g_strdup(in->tabType);
 out->tabVer  = in->tabVer;
  /* Secret reference to host */ 
 out->myHost  = in->myHost;

  return out;
} /* end ObitTableCCConvert */


/**
 * Make a deep copy of input object.
 * Copies are made of complex members including disk files; these 
 * will be copied applying whatever selection is associated with the input.
 * Objects should be closed on input and will be closed on output.
 * In order for the disk file structures to be copied, the output file
 * must be sufficiently defined that it can be written.
 * The copy will be attempted but no errors will be logged until
 * both input and output have been successfully opened.
 * ObitInfoList and ObitThread members are only copied if the output object
 * didn't previously exist.
 * Parent class members are included but any derived class info is ignored.
 * \param in  The object to copy
 * \param out An existing object pointer for output or NULL if none exists.
 * \param err Error stack, returns if not empty.
 * \return pointer to the new object.
 */
ObitTableCC* ObitTableCCCopy (ObitTableCC *in, ObitTableCC *out, ObitErr *err)
{
  gchar *routine = "ObitTableCCCopy";

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableCCClassInit();

 /* error checks */
  g_assert(ObitErrIsA(err));
  if (err->error) return NULL;
  g_assert (ObitIsA(in, &myClassInfo));
  if (out) g_assert (ObitIsA(out, &myClassInfo));

  /* Use parent class to copy */
  out = (ObitTableCC*)ObitTableCopy ((ObitTable*)in, (ObitTable*)out, err);
  if (err->error) /* add traceback,return */
    Obit_traceback_val (err, routine,in->name, out);

  /* Copy this class  info */
  out->noParms = in->noParms;
  /* Update class specific info */
  ObitTableCCUpdate (out, err);
    
  return out;
} /* end ObitTableCCCopy */

/**
 * Initialize structures and open file.
 * The image descriptor is read if OBIT_IO_ReadOnly or 
 * OBIT_IO_ReadWrite and written to disk if opened OBIT_IO_WriteOnly.
 * After the file has been opened the member, buffer is initialized
 * for reading/storing the table unless member bufferSize is <0.
 * If the requested version ("Ver" in InfoList) is 0 then the highest
 * numbered table of the same type is opened on Read or Read/Write, 
 * or a new table is created on on Write.
 * The file etc. info should have been stored in the ObitInfoList:
 * \li "FileType" OBIT_long scalar = OBIT_IO_FITS or OBIT_IO_AIPS 
 *               for file type (see class documentation for details).
 * \li "nRowPIO" OBIT_long scalar = Maximum number of table rows
 *               per transfer, this is the target size for Reads (may be 
 *               fewer) and is used to create buffers.
 * \param in Pointer to object to be opened.
 * \param access access (OBIT_IO_ReadOnly,OBIT_IO_ReadWrite,
 *               or OBIT_IO_WriteOnly).
 *               If OBIT_IO_WriteOnly any existing data in the output file
 *               will be lost.
 * \param err ObitErr for reporting errors.
 * \return return code, OBIT_IO_OK=> OK
 */
ObitIOCode ObitTableCCOpen (ObitTableCC *in, ObitIOAccess access, 
			  ObitErr *err)
{
  ObitIOCode retCode = OBIT_IO_SpecErr;
  gint32 dim[MAXINFOELEMDIM] = {1,1,1,1,1};
  olong nRowPIO;
  gchar *routine = "ObitTableCCOpen";

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableCCClassInit();

  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA(in, &myClassInfo));

   /* Do one row at a time */
   nRowPIO = 1;
   ObitInfoListPut(in->info, "nRowPIO", OBIT_long, dim, (gconstpointer)&nRowPIO, err);
   if (err->error) /* add traceback,return */
     Obit_traceback_val (err, routine, in->name, retCode);
   
   /* use parent class open */
   retCode = ObitTableOpen ((ObitTable*)in, access, err);
   if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
     Obit_traceback_val (err, routine, in->name, retCode);
   
   /* Update class specific info */
   ObitTableCCUpdate (in, err);
   
   return retCode;
} /* end ObitTableCCOpen */

/**
 * Read a table row and return an easily digested version.
 * Scalar values are copied but for array values, pointers 
 * into the data array are returned.
 * \param in       Table to read
 * \param iCCRow   Row number, -1 -> next
 * \param row      Table Row structure to receive data
 * \param err ObitErr for reporting errors.
 * \return return code, OBIT_IO_OK=> OK
 */
ObitIOCode 
ObitTableCCReadRow  (ObitTableCC *in, olong iCCRow, ObitTableCCRow *row,
		     ObitErr *err)
{
  ObitIOCode retCode = OBIT_IO_SpecErr;
  odouble   *dRow;
  oint      *iRow;
  gshort    *siRow;
  ofloat    *fRow;
  gchar     *cRow;
  gboolean  *lRow;
  guint8    *bRow;
  gchar *routine = "ObitTableCCReadRow";
  
  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA(in, &myClassInfo));

  if (in->myStatus == OBIT_Inactive) {
    Obit_log_error(err, OBIT_Error,
		   "AIPS CC Table is inactive for  %s ", in->name);
    return retCode;
 }

  /* read row iCCRow */
  retCode = ObitTableRead ((ObitTable*)in, iCCRow, NULL,  err);
  if (err->error) 
    Obit_traceback_val (err, routine, in->name, retCode);

  /* Typed pointers to row of data */  
  dRow  = (odouble*)in->buffer;
  iRow  = (oint*)in->buffer;
  siRow = (gshort*)in->buffer;
  fRow  = (ofloat*)in->buffer;
  cRow  = (gchar*)in->buffer;
  lRow  = (gboolean*)in->buffer;
  bRow  = (guint8*)in->buffer;
  
  /* Copy scalar fields, for arrays only set pointer*/
  row->Flux = fRow[in->FluxOff];
  row->DeltaX = fRow[in->DeltaXOff];
  row->DeltaY = fRow[in->DeltaYOff];
  row->parms = fRow + in->parmsOff;
  row->status = iRow[in->myDesc->statusOff];

  return retCode;
} /*  end ObitTableCCReadRow */

/**
 * Attach an ObitTableRow to the buffer of an ObitTable.
 * This is only useful prior to filling a row structure in preparation .
 * for a WriteRow operation.  Array members of the Row structure are .
 * pointers to independently allocated memory, this routine allows using .
 * the table IO buffer instead of allocating yet more memory..
 * This routine need only be called once to initialize a Row structure for write..
 * \param in  Table with buffer to be written 
 * \param row Table Row structure to attach 
 * \param err ObitErr for reporting errors.
 */
void 
ObitTableCCSetRow  (ObitTableCC *in, ObitTableCCRow *row,
		     ObitErr *err)
{
  odouble   *dRow;
  oint      *iRow;
  gshort    *siRow;
  ofloat    *fRow;
  gchar     *cRow;
  gboolean  *lRow;
  guint8    *bRow;
  
  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return;
  g_assert (ObitIsA(in, &myClassInfo));
  g_assert (ObitIsA(row, &myRowClassInfo));

  if (in->myStatus == OBIT_Inactive) {
    Obit_log_error(err, OBIT_Error,
		   "CC Table is inactive for  %s ", in->name);
    return;
 }

  /* Typed pointers to row of data */  
  dRow  = (odouble*)in->buffer;
  iRow  = (oint*)in->buffer;
  siRow = (gshort*)in->buffer;
  fRow  = (ofloat*)in->buffer;
  cRow  = (gchar*)in->buffer;
  lRow  = (gboolean*)in->buffer;
  bRow  = (guint8*)in->buffer;
  
  /* Set row pointers to buffer */
  row->parms = fRow + in->parmsOff;

} /*  end ObitTableCCSetRow */

/**
 * Write a table row.
 * Before calling this routine, the row structure needs to be initialized
 * and filled with data. The array members of the row structure are  
 * pointers to independently allocated memory.  These pointers can be set to the 
 * correct table buffer locations using ObitTableCCSetRow  
 * \param in       Table to read
 * \param iCCRow   Row number, -1 -> next
 * \param row Table Row structure containing data
 * \param err ObitErr for reporting errors.
 * \return return code, OBIT_IO_OK=> OK
 */
ObitIOCode 
ObitTableCCWriteRow  (ObitTableCC *in, olong iCCRow, ObitTableCCRow *row,
		      ObitErr *err)
{
  ObitIOCode retCode = OBIT_IO_SpecErr;
  gshort    *siRow;
  odouble   *dRow;
  oint      *iRow, i;
  ofloat    *fRow;
  gchar     *cRow;
  gboolean  *lRow;
  guint8    *bRow;
  gchar *routine = "ObitTableCCWriteRow";
  

  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA(in, &myClassInfo));

  if (in->myStatus == OBIT_Inactive) {
    Obit_log_error(err, OBIT_Error,
		   "AIPS CC Table is inactive for %s ", in->name);
    return retCode;
 }

  /* Typed pointers to row of data */  
  dRow  = (odouble*)in->buffer;
  siRow = (gshort*)in->buffer;
  iRow  = (oint*)in->buffer;
  fRow  = (ofloat*)in->buffer;
  cRow  = (gchar*)in->buffer;
  lRow  = (gboolean*)in->buffer;
  bRow  = (guint8*)in->buffer;
  
  /* Make full copy of all data */
  fRow[in->FluxOff] = row->Flux;
  fRow[in->DeltaXOff] = row->DeltaX;
  fRow[in->DeltaYOff] = row->DeltaY;
  if (in->parmsCol >= 0) { 
    for (i=0; i<in->myDesc->repeat[in->parmsCol]; i++) 
      fRow[in->parmsOff+i] = row->parms[i];
  } 

  /* copy status */
  iRow[in->myDesc->statusOff] = row->status;
   
  /* Write one row */
  in->myDesc->numRowBuff = 1;
 
  /* Write row iCCRow */
  retCode = ObitTableWrite ((ObitTable*)in, iCCRow, NULL,  err);
  if (err->error) 
    Obit_traceback_val (err, routine,in->name, retCode);

  return retCode;
} /*  end ObitTableCCWriteRow */

/**
 * Shutdown I/O.
 * \param in Pointer to object to be closed.
 * \param err ObitErr for reporting errors.
 * \return error code, OBIT_IO_OK=> OK
 */
ObitIOCode ObitTableCCClose (ObitTableCC *in, ObitErr *err)
{
  ObitIOCode retCode = OBIT_IO_SpecErr;
  gchar *routine = "ObitTableCCClose";

  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA((Obit*)in, &myClassInfo));
  /* Something going on? */
  if (in->myStatus == OBIT_Inactive) return OBIT_IO_OK;

  /* Update keywords on descriptor if not ReadOnly*/
  if (in->myDesc->access != OBIT_IO_ReadOnly) 
    ObitTableCCDumpKey (in, err);
  if (err->error) 
    Obit_traceback_val (err, routine, in->name, retCode);

  /* Close */
  retCode = ObitTableClose ((ObitTable*)in, err);
  if (err->error) 
    Obit_traceback_val (err, routine, in->name, retCode);

  return retCode;
} /* end ObitTableCCClose */

/*---------------Private functions--------------------------*/
/*----------------  TableCC Row  ----------------------*/
/**
 * Creates empty member objects, initialize reference count.
 * Parent classes portions are (recursively) initialized first
 * \param inn Pointer to the object to initialize.
 */
void ObitTableCCRowInit  (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableCCRow *in = inn;

  /* error checks */
  g_assert (in != NULL);

  /* recursively initialize parent class members */
  ParentClass = (ObitClassInfo*)(myRowClassInfo.ParentClass);
  if ((ParentClass!=NULL) && ( ParentClass->ObitInit!=NULL)) 
    ParentClass->ObitInit (inn);

  /* set members in this class */
  /* Set array members to NULL */
  in->parms = NULL;

} /* end ObitTableCCRowInit */

/**
 * Deallocates member objects.
 * Does (recursive) deallocation of parent class members.
 * For some reason this wasn't build into the GType class.
 * \param  inn Pointer to the object to deallocate.
 *           Actually it should be an ObitTableCCRow* cast to an Obit*.
 */
void ObitTableCCRowClear (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableCCRow *in = inn;

  /* error checks */
  g_assert (ObitIsA(in, &myRowClassInfo));

  /* delete this class members */
  /* Do not free data array pointers as they were not malloced */
  
  /* unlink parent class members */
  ParentClass = (ObitClassInfo*)(myRowClassInfo.ParentClass);
  /* delete parent class members */
  if ((ParentClass!=NULL) && ( ParentClass->ObitClear!=NULL)) 
    ParentClass->ObitClear (inn);
  
} /* end ObitTableCCRowClear */

/**
 * Initialize global ClassInfo Structure.
 */
void ObitTableCCRowClassInit (void)
{
  if (myRowClassInfo.initialized) return;  /* only once */
  
  /* Set name and parent for this class */
  myRowClassInfo.ClassName   = g_strdup(myRowClassName);
  myRowClassInfo.ParentClass = ObitParentGetRowClass();

  /* Set function pointers */
  ObitTableCCRowClassInfoDefFn ((gpointer)&myRowClassInfo);
 
  myRowClassInfo.initialized = TRUE; /* Now initialized */
 
} /* end ObitTableCCRowClassInit */

/**
 * Initialize global ClassInfo Function pointers.
 */
static void ObitTableCCRowClassInfoDefFn (gpointer inClass)
{
  ObitTableCCRowClassInfo *theClass = (ObitTableCCRowClassInfo*)inClass;
  ObitClassInfo *ParentClass = (ObitClassInfo*)myRowClassInfo.ParentClass;

  if (theClass->initialized) return;  /* only once */

  /* Check type of inClass */
  g_assert (ObitInfoIsA(inClass, (ObitClassInfo*)&myRowClassInfo));

  /* Initialize (recursively) parent class first */
  if ((ParentClass!=NULL) && 
      (ParentClass->ObitClassInfoDefFn!=NULL))
    ParentClass->ObitClassInfoDefFn(theClass);

  /* function pointers defined or overloaded this class */
  theClass->ObitClassInit = (ObitClassInitFP)ObitTableCCRowClassInit;
  theClass->ObitClassInfoDefFn = (ObitClassInfoDefFnFP)ObitTableCCRowClassInfoDefFn;
  theClass->ObitGetClass  = (ObitGetClassFP)ObitTableCCRowGetClass;
  theClass->newObit         = NULL;
  theClass->newObitTableRow = (newObitTableRowFP)newObitTableCCRow;
  theClass->ObitCopy        = NULL;
  theClass->ObitClone       = NULL;
  theClass->ObitClear       = (ObitClearFP)ObitTableCCRowClear;
  theClass->ObitInit        = (ObitInitFP)ObitTableCCRowInit;

} /* end ObitTableCCRowClassDefFn */

/*------------------  TableCC  ------------------------*/

/**
 * Creates empty member objects, initialize reference count.
 * Parent classes portions are (recursively) initialized first
 * \param inn Pointer to the object to initialize.
 */
void ObitTableCCInit  (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableCC *in = inn;

  /* error checks */
  g_assert (in != NULL);

  /* recursively initialize parent class members */
  ParentClass = (ObitClassInfo*)(myClassInfo.ParentClass);
  if ((ParentClass!=NULL) && ( ParentClass->ObitInit!=NULL)) 
    ParentClass->ObitInit (inn);

  /* set members in this class */

} /* end ObitTableCCInit */

/**
 * Deallocates member objects.
 * Does (recursive) deallocation of parent class members.
 * For some reason this wasn't build into the GType class.
 * \param  inn Pointer to the object to deallocate.
 *           Actually it should be an ObitTableCC* cast to an Obit*.
 */
void ObitTableCCClear (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableCC *in = inn;

  /* error checks */
  g_assert (ObitIsA(in, &myClassInfo));

  /* delete this class members */
  
  /* unlink parent class members */
  ParentClass = (ObitClassInfo*)(myClassInfo.ParentClass);
  /* delete parent class members */
  if ((ParentClass!=NULL) && ( ParentClass->ObitClear!=NULL)) 
    ParentClass->ObitClear (inn);
  
} /* end ObitTableCCClear */

/**
 * Initialize global ClassInfo Structure.
 */
void ObitTableCCClassInit (void)
{
  if (myClassInfo.initialized) return;  /* only once */
  
  /* Set name and parent for this class */
  myClassInfo.ClassName   = g_strdup(myClassName);
  myClassInfo.ParentClass = ObitParentGetClass();

  /* Set function pointers */
  ObitTableCCClassInfoDefFn ((gpointer)&myClassInfo);
 
  myClassInfo.initialized = TRUE; /* Now initialized */
 
} /* end ObitTableCCClassInit */

/**
 * Initialize global ClassInfo Function pointers.
 */
static void ObitTableCCClassInfoDefFn (gpointer inClass)
{
  ObitTableCCClassInfo *theClass = (ObitTableCCClassInfo*)inClass;
  ObitClassInfo *ParentClass = (ObitClassInfo*)myClassInfo.ParentClass;

  if (theClass->initialized) return;  /* only once */

  /* Check type of inClass */
  g_assert (ObitInfoIsA(inClass, (ObitClassInfo*)&myClassInfo));

  /* Initialize (recursively) parent class first */
  if ((ParentClass!=NULL) && 
      (ParentClass->ObitClassInfoDefFn!=NULL))
    ParentClass->ObitClassInfoDefFn(theClass);

  /* function pointers defined or overloaded this class */
  theClass->ObitClassInit = (ObitClassInitFP)ObitTableCCClassInit;
  theClass->ObitClassInfoDefFn = (ObitClassInfoDefFnFP)ObitTableCCClassInfoDefFn;
  theClass->ObitGetClass  = (ObitGetClassFP)ObitTableCCGetClass;
  theClass->newObit       = (newObitFP)newObitTableCC;
  theClass->ObitCopy      = (ObitCopyFP)ObitTableCCCopy;
  theClass->ObitClone     = (ObitCloneFP)ObitTableClone;
  theClass->ObitClear     = (ObitClearFP)ObitTableCCClear;
  theClass->ObitInit      = (ObitInitFP)ObitTableCCInit;
  theClass->ObitTableConvert = (ObitTableConvertFP)ObitTableCCConvert;
  theClass->ObitTableOpen    = (ObitTableOpenFP)ObitTableCCOpen;
  theClass->ObitTableClose   = (ObitTableCloseFP)ObitTableCCClose;
  theClass->ObitTableRead    = (ObitTableReadFP)ObitTableRead;
  theClass->ObitTableReadSelect = 
    (ObitTableReadSelectFP)ObitTableReadSelect;
  theClass->ObitTableWrite = (ObitTableWriteFP)ObitTableWrite;
  theClass->ObitTableReadRow = 
    (ObitTableReadRowFP)ObitTableCCReadRow;
  theClass->ObitTableWriteRow = 
    (ObitTableWriteRowFP)ObitTableCCWriteRow;

} /* end ObitTableCCClassDefFn */

/**
 * Get table specific information from the infolist or descriptor
 * \param info Table to update
 * \param err  ObitErr for reporting errors.
 */
static void ObitTableCCUpdate (ObitTableCC *in, ObitErr *err)
{
  olong i;
  ObitInfoType type;
  gint32 dim[MAXINFOELEMDIM];
  ObitTableDesc *desc;
   

 /* error checks */
   g_assert(ObitErrIsA(err));
  if (err->error) return;
  g_assert (ObitIsA(in, &myClassInfo));

  /* Get Keywords */
   /* noParms */
  in->noParms = 0; 
  ObitInfoListGetTest(in->myDesc->info, "NO_PARMS", &type, dim, 
		       (gpointer)&in->noParms);

  /* initialize column numbers/offsets */
  in->FluxOff = -1;
  in->FluxCol = -1;
  in->DeltaXOff = -1;
  in->DeltaXCol = -1;
  in->DeltaYOff = -1;
  in->DeltaYCol = -1;
  in->parmsOff = -1;
  in->parmsCol = -1;
  /* Find columns and set offsets */
  desc = in->myDesc;
  if (desc->FieldName) {
    for (i=0; i<desc->nfield; i++) {
      if (!strncmp (desc->FieldName[i], "FLUX    ", 8)) {
	 in->FluxOff = desc->offset[i];
 	 in->FluxCol = i;
      }
      if (!strncmp (desc->FieldName[i], "DELTAX  ", 8)) {
	 in->DeltaXOff = desc->offset[i];
 	 in->DeltaXCol = i;
      }
      if (!strncmp (desc->FieldName[i], "DELTAY  ", 8)) {
	 in->DeltaYOff = desc->offset[i];
 	 in->DeltaYCol = i;
      }
      if (!strncmp (desc->FieldName[i], "PARMS   ", 8)) {
	 in->parmsOff = desc->offset[i];
 	 in->parmsCol = i;
      }
     }
  }

  /* Check required columns */
  Obit_return_if_fail((in->FluxOff > -1), err,
       "ObitTableCCUpdate: Could not find column Flux");
  Obit_return_if_fail((in->DeltaXOff > -1), err,
       "ObitTableCCUpdate: Could not find column DeltaX");
  Obit_return_if_fail((in->DeltaYOff > -1), err,
       "ObitTableCCUpdate: Could not find column DeltaY");
} /* end ObitTableCCUpdate */

/**
 * Copy table specific (keyword) information  to infolist.
 * \param info Table to update
 * \param err  ObitErr for reporting errors.
 */
static void ObitTableCCDumpKey (ObitTableCC *in, ObitErr *err)
{
  ObitInfoList *info=NULL;
  ObitInfoType type;
  gint32 dim[MAXINFOELEMDIM] = {1,1,1,1,1};

 /* error checks */
   g_assert(ObitErrIsA(err));
  if (err->error) return;
  g_assert (ObitIsA(in, &myClassInfo));

  /* Set Keywords */
  if (in->myIO!=NULL) info = ((ObitTableDesc*)(in->myIO->myDesc))->info;
  else info = in->myDesc->info;
  /* noParms */
  type  = OBIT_oint;
  dim[0] = 1;
  ObitInfoListAlwaysPut(info, "NO_PARMS", type, dim, 
		  (gpointer)&in->noParms);
   
} /* end ObitTableCCDumpKey */
