/* $Id:  $  */
/* DO NOT EDIT - file generated by ObitSDTables.pl                    */
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
#include "ObitTableGBTBEAM_OFFSETS.h"
#include "ObitTableList.h"
#include "ObitData.h"

/*----------------Obit: Merx mollis mortibus nuperS ------------------*/
/**
 * \file ObitTableGBTBEAM_OFFSETS.c
 * ObitTableGBTBEAM_OFFSETS class function definitions.
 * This class is derived from the ObitTable class.
 */

/** name of the class defined in this file */
static gchar *myClassName = "ObitTableGBTBEAM_OFFSETS";

/**  Function to obtain parent Table ClassInfo - ObitTable */
static ObitGetClassFP ObitParentGetClass = ObitTableGetClass;

/** name of the Row class defined in this file */
static gchar *myRowClassName = "ObitTableGBTBEAM_OFFSETSRow";

/**  Function to obtain parent TableRow ClassInfo */
static ObitGetClassFP ObitParentGetRowClass = ObitTableRowGetClass;

/*--------------- File Global Variables  ----------------*/
/*----------------  Table Row  ----------------------*/
/**
 * ClassInfo structure ObitTableClassInfo.
 * This structure is used by class objects to access class functions.
 */
static ObitTableGBTBEAM_OFFSETSRowClassInfo myRowClassInfo = {FALSE};

/*------------------  Table  ------------------------*/
/**
 * ClassInfo structure ObitTableGBTBEAM_OFFSETSClassInfo.
 * This structure is used by class objects to access class functions.
 */
static ObitTableGBTBEAM_OFFSETSClassInfo myClassInfo = {FALSE};


/*---------------Private function prototypes----------------*/
/** Private: Initialize newly instantiated Row object. */
void  ObitTableGBTBEAM_OFFSETSRowInit  (gpointer in);

/** Private: Deallocate Row members. */
void  ObitTableGBTBEAM_OFFSETSRowClear (gpointer in);

/** Private: Initialize newly instantiated object. */
void  ObitTableGBTBEAM_OFFSETSInit  (gpointer in);

/** Private: Deallocate members. */
void  ObitTableGBTBEAM_OFFSETSClear (gpointer in);

/** Private: update table specific info */
static void ObitTableGBTBEAM_OFFSETSUpdate (ObitTableGBTBEAM_OFFSETS *in, ObitErr *err);

/** Private: copy table keywords to descriptor info list */
static void ObitTableGBTBEAM_OFFSETSDumpKey (ObitTableGBTBEAM_OFFSETS *in, ObitErr *err);

/** Private: Set Class function pointers */
static void ObitTableGBTBEAM_OFFSETSClassInfoDefFn (gpointer inClass);

/** Private: Set Row Class function pointers */
static void ObitTableGBTBEAM_OFFSETSRowClassInfoDefFn (gpointer inClass);
/*----------------------Public functions---------------------------*/

/*------------------  Table Row ------------------------*/
/**
 * Constructor.
 * If table is open and for write, the row is attached to the buffer
 * Initializes Row class if needed on first call.
 * \param name An optional name for the object.
 * \return the new object.
 */
ObitTableGBTBEAM_OFFSETSRow* newObitTableGBTBEAM_OFFSETSRow (ObitTableGBTBEAM_OFFSETS *table)
{
  ObitTableGBTBEAM_OFFSETSRow* out;
  odouble   *dRow;
  oint      *iRow;
  gshort    *siRow;
  ofloat    *fRow;
  gchar     *cRow;
  gboolean  *lRow;
  guint8    *bRow;

  /* Class initialization if needed */
  if (!myRowClassInfo.initialized) ObitTableGBTBEAM_OFFSETSRowClassInit();

  /* allocate/init structure */
  out = g_malloc0(sizeof(ObitTableGBTBEAM_OFFSETSRow));

  /* initialize values */
  out->name = g_strdup("TableObitTableGBTBEAM_OFFSETS Row");

  /* set ClassInfo */
  out->ClassInfo = (gpointer)&myRowClassInfo;

  /* initialize other stuff */
  ObitTableGBTBEAM_OFFSETSRowInit((gpointer)out);
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
    out->Name = cRow + table->NameOff;
  } /* end attaching row to table buffer */

 return out;
} /* end newObitTableBEAM_OFFSETSRow */

/**
 * Returns ClassInfo pointer for the Row class.
 * \return pointer to the Row class structure.
 */
gconstpointer ObitTableGBTBEAM_OFFSETSRowGetClass (void)
{
  /* Class initialization if needed */
  if (!myRowClassInfo.initialized) ObitTableGBTBEAM_OFFSETSRowClassInit();
  return (gconstpointer)&myRowClassInfo;
} /* end ObitTableGBTBEAM_OFFSETSRowGetClass */

/*------------------  Table  ------------------------*/
/**
 * Constructor.
 * Initializes class if needed on first call.
 * \param name An optional name for the object.
 * \return the new object.
 */
ObitTableGBTBEAM_OFFSETS* newObitTableGBTBEAM_OFFSETS (gchar* name)
{
  ObitTableGBTBEAM_OFFSETS* out;

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableGBTBEAM_OFFSETSClassInit();

  /* allocate/init structure */
  out = g_malloc0(sizeof(ObitTableGBTBEAM_OFFSETS));

  /* initialize values */
  if (name!=NULL) out->name = g_strdup(name);
  else out->name = g_strdup("Noname");

  /* set ClassInfo */
  out->ClassInfo = (gpointer)&myClassInfo;

  /* initialize other stuff */
  ObitTableGBTBEAM_OFFSETSInit((gpointer)out);

 return out;
} /* end newObitTableGBTBEAM_OFFSETS */

/**
 * Returns ClassInfo pointer for the class.
 * \return pointer to the class structure.
 */
gconstpointer ObitTableGBTBEAM_OFFSETSGetClass (void)
{
  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableGBTBEAM_OFFSETSClassInit();
  return (gconstpointer)&myClassInfo;
} /* end ObitTableGBTBEAM_OFFSETSGetClass */

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
 * \param err Error stack, returns if not empty.
 * \return the new object, NULL on failure.
 */
ObitTableGBTBEAM_OFFSETS* newObitTableGBTBEAM_OFFSETSValue (gchar* name, ObitData *file, olong *ver,
 				  ObitIOAccess access,
  		    
		     ObitErr *err)
{
  ObitTableGBTBEAM_OFFSETS* out=NULL;
  ObitTable *testTab=NULL;
  ObitTableDesc *desc=NULL;
  ObitTableList *list=NULL;
  ObitInfoList  *info=NULL;
  gboolean exist, optional;
  olong colNo, i, ncol, highVer;
  ObitIOCode retCode;
  gchar *tabType = "BEAM_OFFSETS";
  gchar *routine = "newObitTableGBTBEAM_OFFSETSValue";

 /* error checks */
  g_assert(ObitErrIsA(err));
  if (err->error) return NULL;
  g_assert (ObitDataIsA(file));

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableGBTBEAM_OFFSETSClassInit();

  /* Check if the table already exists */
  /* Get TableList */
  list = ((ObitData*)file)->tableList;
  info = ((ObitData*)file)->info;

  /* See if it already exists */
  exist = FALSE;
  if (*ver>0) { /* has to be specified */
    exist = ObitTableListGet(list, tabType, ver, &testTab, err);
    if (err->error) /* add traceback,return */
      Obit_traceback_val (err, routine,"", out);
  
    /* if readonly, it must exist to proceed */
    if ((access==OBIT_IO_ReadOnly) && !exist) return out;
    if (testTab!=NULL) { /* it exists, use it if is an ObitTableGBTBEAM_OFFSETS */
      if (ObitTableGBTBEAM_OFFSETSIsA(testTab)) { /* it is an ObitTableGBTBEAM_OFFSETS */
	out = ObitTableRef(testTab);
      } else { /* needs conversion */
 	out = ObitTableGBTBEAM_OFFSETSConvert(testTab);
	/* Update the TableList */
	ObitTableListPut(list, tabType, ver, (ObitTable*)out, err);
	if (err->error) Obit_traceback_val (err, routine,"", out);
      }
      testTab = ObitTableUnref(testTab); /* remove reference */
      return out; /* done */
    }
  } /* end of test for previously existing table */
  
  /* If access is ReadOnly make sure one exists */
  if (access==OBIT_IO_ReadOnly) { 
    highVer = ObitTableListGetHigh (list, "BEAM_OFFSETS");
    if (highVer<=0) return out;
  }
  
  /* create basal table */
  testTab = newObitDataTable ((ObitData*)file, access, tabType,
			       ver, err);
  if (err->error) Obit_traceback_val (err, routine,"", out);
  
  /* likely need to convert */
  if (ObitTableGBTBEAM_OFFSETSIsA(testTab)) { 
    out = ObitTableRef(testTab);
  } else { /* needs conversion */
    out = ObitTableGBTBEAM_OFFSETSConvert(testTab);
  }
  testTab = ObitTableUnref(testTab); /* remove reference */

  /* Update the TableList */
  ObitTableListPut(list, tabType, ver, (ObitTable*)out, err);
  if (err->error) /* add traceback,return */
    Obit_traceback_val (err, routine,"", out);

  /* if it previously existed merely return it */
  if (exist) return out; 

  /* set ClassInfo */
  out->ClassInfo = (gpointer)&myClassInfo;

  /* Set values */

  /* initialize descriptor */
  desc = out->myDesc;
  /* How many columns actually in table? */
  ncol = 5 ;
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
  desc->FieldName[colNo] = g_strdup("BEAMXELOFFSET");
  desc->FieldUnit[colNo] = g_strdup("DEGREE");
  desc->type[colNo] = OBIT_double;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("BEAMELOFFSET");
  desc->FieldUnit[colNo] = g_strdup("DEGREE");
  desc->type[colNo] = OBIT_double;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("SRFEED1  ");
  desc->FieldUnit[colNo] = g_strdup("");
  desc->type[colNo] = OBIT_oint;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  desc->FieldName[colNo] = g_strdup("SRFEED2  ");
  desc->FieldUnit[colNo] = g_strdup("");
  desc->type[colNo] = OBIT_oint;
  for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
  colNo++;
  optional = FALSE;
  if ((32 > 0) || (!optional)) {
    desc->FieldName[colNo] = g_strdup("NAME    ");
    desc->FieldUnit[colNo] = g_strdup("");
    desc->type[colNo] = OBIT_string;
    for (i=0; i<MAXINFOELEMDIM; i++) desc->dim[colNo][i] = 1;
    desc->dim[colNo][0] = 32;
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
  ObitTableGBTBEAM_OFFSETSDumpKey (out, err);
 
  /* index table descriptor */
  ObitTableDescIndex (desc);

  /* Open and Close to fully instantiate */
  retCode = ObitTableGBTBEAM_OFFSETSOpen(out, OBIT_IO_WriteOnly, err);
  if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
    Obit_traceback_val (err, routine, out->name, out);    
  
  retCode = ObitTableGBTBEAM_OFFSETSClose(out, err);
  if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
    Obit_traceback_val (err, routine, out->name, out); 

  /* Force update of disk resident info */
  retCode = ObitIOUpdateTables (((ObitData*)file)->myIO, info, err);
  if ((retCode!=OBIT_IO_OK) || (err->error)) /* add traceback,return */
    Obit_traceback_val (err, routine, out->name, out); 
  
 return out;
} /* end newObitTableGBTBEAM_OFFSETSValue */

/**
 * Convert an ObitTable to an ObitTableGBTBEAM_OFFSETS.
 * New object will have references to members of in.
 * \param in  The object to copy, will still exist afterwards 
 *            and should be Unrefed if not needed.
 * \return pointer to the new object.
 */
ObitTableGBTBEAM_OFFSETS* ObitTableGBTBEAM_OFFSETSConvert (ObitTable* in)
{
  ObitTableGBTBEAM_OFFSETS *out;

  /* error check */
  g_assert(ObitTableIsA(in));

  /* create basic object */
  out = newObitTableGBTBEAM_OFFSETS(in->name);

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
} /* end ObitTableGBTBEAM_OFFSETSConvert */


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
ObitTableGBTBEAM_OFFSETS* ObitTableGBTBEAM_OFFSETSCopy (ObitTableGBTBEAM_OFFSETS *in, ObitTableGBTBEAM_OFFSETS *out, ObitErr *err)
{
  gchar *routine = "ObitTableGBTBEAM_OFFSETSCopy";

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableGBTBEAM_OFFSETSClassInit();

 /* error checks */
  g_assert(ObitErrIsA(err));
  if (err->error) return NULL;
  g_assert (ObitIsA(in, &myClassInfo));
  if (out) g_assert (ObitIsA(out, &myClassInfo));

  /* Use parent class to copy */
  out = (ObitTableGBTBEAM_OFFSETS*)ObitTableCopy ((ObitTable*)in, (ObitTable*)out, err);
  if (err->error) /* add traceback,return */
    Obit_traceback_val (err, routine,in->name, out);

  /* Copy this class  info */
  /* Update class specific info */
  ObitTableGBTBEAM_OFFSETSUpdate (out, err);
    
  return out;
} /* end ObitTableGBTBEAM_OFFSETSCopy */

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
 * \li "FileType" OBIT_long scalar = OBIT_IO_FITS 
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
ObitIOCode ObitTableGBTBEAM_OFFSETSOpen (ObitTableGBTBEAM_OFFSETS *in, ObitIOAccess access, 
			  ObitErr *err)
{
  ObitIOCode retCode = OBIT_IO_SpecErr;
  gint32 dim[MAXINFOELEMDIM] = {1,1,1,1,1};
  olong nRowPIO;
  gchar *routine = "ObitTableGBTBEAM_OFFSETSOpen";

  /* Class initialization if needed */
  if (!myClassInfo.initialized) ObitTableGBTBEAM_OFFSETSClassInit();

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
   ObitTableGBTBEAM_OFFSETSUpdate (in, err);
   
   return retCode;
} /* end ObitTableGBTBEAM_OFFSETSOpen */

/**
 * Read a table row and return an easily digested version.
 * Scalar values are copied but for array values, pointers 
 * into the data array are returned.
 * \param in       Table to read
 * \param iBEAM_OFFSETSRow   Row number, -1 -> next
 * \param row      Table Row structure to receive data
 * \param err ObitErr for reporting errors.
 * \return return code, OBIT_IO_OK=> OK
 */
ObitIOCode 
ObitTableGBTBEAM_OFFSETSReadRow  (ObitTableGBTBEAM_OFFSETS *in, olong iBEAM_OFFSETSRow, ObitTableGBTBEAM_OFFSETSRow *row,
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
  gchar *routine = "ObitTableGBTBEAM_OFFSETSReadRow";
  
  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA(in, &myClassInfo));

  if (in->myStatus == OBIT_Inactive) {
    Obit_log_error(err, OBIT_Error,
		   "ObitTableGBTBEAM_OFFSETS Table is inactive for  %s ", in->name);
    return retCode;
 }

  /* read row iBEAM_OFFSETSRow */
  retCode = ObitTableRead ((ObitTable*)in, iBEAM_OFFSETSRow, NULL,  err);
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
  row->xeloff = dRow[in->xeloffOff];
  row->eloff = dRow[in->eloffOff];
  row->srfeed1 = iRow[in->srfeed1Off];
  row->srfeed2 = iRow[in->srfeed2Off];
  row->Name = cRow + in->NameOff;
  row->status = iRow[in->myDesc->statusOff];

  return retCode;
} /*  end ObitTableGBTBEAM_OFFSETSReadRow */

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
ObitTableGBTBEAM_OFFSETSSetRow  (ObitTableGBTBEAM_OFFSETS *in, ObitTableGBTBEAM_OFFSETSRow *row,
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
		   "BEAM_OFFSETS Table is inactive for  %s ", in->name);
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
  row->Name = cRow + in->NameOff;

} /*  end ObitTableGBTBEAM_OFFSETSSetRow */

/**
 * Write a table row.
 * Before calling this routine, the row structure needs to be initialized
 * and filled with data. The array members of the row structure are  
 * pointers to independently allocated memory.  These pointers can be set to the 
 * correct table buffer locations using ObitTableGBTBEAM_OFFSETSSetRow  
 * \param in       Table to read
 * \param iBEAM_OFFSETSRow   Row number, -1 -> next
 * \param row      Table Row structure containing data
 * \param err ObitErr for reporting errors.
 * \return return code, OBIT_IO_OK=> OK
 */
ObitIOCode 
ObitTableGBTBEAM_OFFSETSWriteRow  (ObitTableGBTBEAM_OFFSETS *in, olong iBEAM_OFFSETSRow, ObitTableGBTBEAM_OFFSETSRow *row,
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
  gchar *routine = "ObitTableGBTBEAM_OFFSETSWriteRow";
  

  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA(in, &myClassInfo));

  if (in->myStatus == OBIT_Inactive) {
    Obit_log_error(err, OBIT_Error,
		   "ObitTableGBTBEAM_OFFSETS Table is inactive for %s ", in->name);
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
  dRow[in->xeloffOff] = row->xeloff;
  dRow[in->eloffOff] = row->eloff;
  iRow[in->srfeed1Off] = row->srfeed1;
  iRow[in->srfeed2Off] = row->srfeed2;
  if (in->NameCol >= 0) { 
    for (i=0; i<in->myDesc->repeat[in->NameCol]; i++) 
      cRow[in->NameOff+i] = row->Name[i];
  } 

  /* copy status */
  iRow[in->myDesc->statusOff] = row->status;
   
  /* Write one row */
  in->myDesc->numRowBuff = 1;
 
  /* Write row iBEAM_OFFSETSRow */
  retCode = ObitTableWrite ((ObitTable*)in, iBEAM_OFFSETSRow, NULL,  err);
  if (err->error) 
    Obit_traceback_val (err, routine,in->name, retCode);

  return retCode;
} /*  end ObitTableGBTBEAM_OFFSETSWriteRow */

/**
 * Shutdown I/O.
 * \param in Pointer to object to be closed.
 * \param err ObitErr for reporting errors.
 * \return error code, OBIT_IO_OK=> OK
 */
ObitIOCode ObitTableGBTBEAM_OFFSETSClose (ObitTableGBTBEAM_OFFSETS *in, ObitErr *err)
{
  ObitIOCode retCode = OBIT_IO_SpecErr;
  gchar *routine = "ObitTableGBTBEAM_OFFSETSClose";

  /* error checks */
  g_assert (ObitErrIsA(err));
  if (err->error) return retCode;
  g_assert (ObitIsA((Obit*)in, &myClassInfo));
  /* Something going on? */
  if (in->myStatus == OBIT_Inactive) return OBIT_IO_OK;

  /* Update keywords on descriptor if not ReadOnly*/
  if (in->myDesc->access != OBIT_IO_ReadOnly) 
    ObitTableGBTBEAM_OFFSETSDumpKey (in, err);
  if (err->error) 
    Obit_traceback_val (err, routine, in->name, retCode);

  /* Close */
  retCode = ObitTableClose ((ObitTable*)in, err);
  if (err->error) 
    Obit_traceback_val (err, routine, in->name, retCode);

  return retCode;
} /* end ObitTableGBTBEAM_OFFSETSClose */

/*---------------Private functions--------------------------*/
/*----------------  ObitTableGBTBEAM_OFFSETS Row  ----------------------*/
/**
 * Creates empty member objects, initialize reference count.
 * Parent classes portions are (recursively) initialized first
 * \param inn Pointer to the object to initialize.
 */
void ObitTableGBTBEAM_OFFSETSRowInit  (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableGBTBEAM_OFFSETSRow *in = inn;

  /* error checks */
  g_assert (in != NULL);

  /* recursively initialize parent class members */
  ParentClass = (ObitClassInfo*)(myRowClassInfo.ParentClass);
  if ((ParentClass!=NULL) && ( ParentClass->ObitInit!=NULL)) 
    ParentClass->ObitInit (inn);

  /* set members in this class */
  /* Set array members to NULL */
  in->Name = NULL;

} /* end ObitTableGBTBEAM_OFFSETSRowInit */

/**
 * Deallocates member objects.
 * Does (recursive) deallocation of parent class members.
 * For some reason this wasn't build into the GType class.
 * \param  inn Pointer to the object to deallocate.
 *           Actually it should be an ObitTableGBTBEAM_OFFSETSRow* cast to an Obit*.
 */
void ObitTableGBTBEAM_OFFSETSRowClear (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableGBTBEAM_OFFSETSRow *in = inn;

  /* error checks */
  g_assert (ObitIsA(in, &myRowClassInfo));

  /* delete this class members */
  /* Do not free data array pointers as they were not malloced */
  
  /* unlink parent class members */
  ParentClass = (ObitClassInfo*)(myRowClassInfo.ParentClass);
  /* delete parent class members */
  if ((ParentClass!=NULL) && ( ParentClass->ObitClear!=NULL)) 
    ParentClass->ObitClear (inn);
  
} /* end ObitTableGBTBEAM_OFFSETSRowClear */

/**
 * Initialize global ClassInfo Structure.
 */
void ObitTableGBTBEAM_OFFSETSRowClassInit (void)
{
  if (myRowClassInfo.initialized) return;  /* only once */
  
  /* Set name and parent for this class */
  myRowClassInfo.ClassName   = g_strdup(myRowClassName);
  myRowClassInfo.ParentClass = ObitParentGetRowClass();

  /* Set function pointers */
  ObitTableGBTBEAM_OFFSETSRowClassInfoDefFn ((gpointer)&myRowClassInfo);
 
  myRowClassInfo.initialized = TRUE; /* Now initialized */
 
} /* end ObitTableGBTBEAM_OFFSETSRowClassInit */

/**
 * Initialize global ClassInfo Function pointers.
 */
static void ObitTableGBTBEAM_OFFSETSRowClassInfoDefFn (gpointer inClass)
{
  ObitTableGBTBEAM_OFFSETSRowClassInfo *theClass = (ObitTableGBTBEAM_OFFSETSRowClassInfo*)inClass;
  ObitClassInfo *ParentClass = (ObitClassInfo*)myRowClassInfo.ParentClass;

  if (theClass->initialized) return;  /* only once */

  /* Check type of inClass */
  g_assert (ObitInfoIsA(inClass, (ObitClassInfo*)&myRowClassInfo));

  /* Initialize (recursively) parent class first */
  if ((ParentClass!=NULL) && 
      (ParentClass->ObitClassInfoDefFn!=NULL))
    ParentClass->ObitClassInfoDefFn(theClass);

  /* function pointers defined or overloaded this class */
  theClass->ObitClassInit = (ObitClassInitFP)ObitTableGBTBEAM_OFFSETSRowClassInit;
  theClass->ObitClassInfoDefFn = (ObitClassInfoDefFnFP)ObitTableGBTBEAM_OFFSETSRowClassInfoDefFn;
  theClass->ObitGetClass  = (ObitGetClassFP)ObitTableGBTBEAM_OFFSETSRowGetClass;
  theClass->newObit         = NULL;
  theClass->newObitTableRow = (newObitTableRowFP)newObitTableGBTBEAM_OFFSETSRow;
  theClass->ObitCopy        = NULL;
  theClass->ObitClone       = NULL;
  theClass->ObitClear       = (ObitClearFP)ObitTableGBTBEAM_OFFSETSRowClear;
  theClass->ObitInit        = (ObitInitFP)ObitTableGBTBEAM_OFFSETSRowInit;

} /* end ObitTableGBTBEAM_OFFSETSRowClassDefFn */

/*------------------  ObitTableGBTBEAM_OFFSETS  ------------------------*/

/**
 * Creates empty member objects, initialize reference count.
 * Parent classes portions are (recursively) initialized first
 * \param inn Pointer to the object to initialize.
 */
void ObitTableGBTBEAM_OFFSETSInit  (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableGBTBEAM_OFFSETS *in = inn;

  /* error checks */
  g_assert (in != NULL);

  /* recursively initialize parent class members */
  ParentClass = (ObitClassInfo*)(myClassInfo.ParentClass);
  if ((ParentClass!=NULL) && ( ParentClass->ObitInit!=NULL)) 
    ParentClass->ObitInit (inn);

  /* set members in this class */

} /* end ObitTableGBTBEAM_OFFSETSInit */

/**
 * Deallocates member objects.
 * Does (recursive) deallocation of parent class members.
 * For some reason this wasn't build into the GType class.
 * \param  inn Pointer to the object to deallocate.
 *           Actually it should be an ObitTableGBTBEAM_OFFSETS* cast to an Obit*.
 */
void ObitTableGBTBEAM_OFFSETSClear (gpointer inn)
{
  ObitClassInfo *ParentClass;
  ObitTableGBTBEAM_OFFSETS *in = inn;

  /* error checks */
  g_assert (ObitIsA(in, &myClassInfo));

  /* delete this class members */
  
  /* unlink parent class members */
  ParentClass = (ObitClassInfo*)(myClassInfo.ParentClass);
  /* delete parent class members */
  if ((ParentClass!=NULL) && ( ParentClass->ObitClear!=NULL)) 
    ParentClass->ObitClear (inn);
  
} /* end ObitTableGBTBEAM_OFFSETSClear */

/**
 * Initialize global ClassInfo Structure.
 */
void ObitTableGBTBEAM_OFFSETSClassInit (void)
{
  if (myClassInfo.initialized) return;  /* only once */
  
  /* Set name and parent for this class */
  myClassInfo.ClassName   = g_strdup(myClassName);
  myClassInfo.ParentClass = ObitParentGetClass();

  /* Set function pointers */
  ObitTableGBTBEAM_OFFSETSClassInfoDefFn ((gpointer)&myClassInfo);
 
  myClassInfo.initialized = TRUE; /* Now initialized */
 
} /* end ObitTableGBTBEAM_OFFSETSClassInit */

/**
 * Initialize global ClassInfo Function pointers.
 */
static void ObitTableGBTBEAM_OFFSETSClassInfoDefFn (gpointer inClass)
{
  ObitTableGBTBEAM_OFFSETSClassInfo *theClass = (ObitTableGBTBEAM_OFFSETSClassInfo*)inClass;
  ObitClassInfo *ParentClass = (ObitClassInfo*)myClassInfo.ParentClass;

  if (theClass->initialized) return;  /* only once */

  /* Check type of inClass */
  g_assert (ObitInfoIsA(inClass, (ObitClassInfo*)&myClassInfo));

  /* Initialize (recursively) parent class first */
  if ((ParentClass!=NULL) && 
      (ParentClass->ObitClassInfoDefFn!=NULL))
    ParentClass->ObitClassInfoDefFn(theClass);

  /* function pointers defined or overloaded this class */
  theClass->ObitClassInit = (ObitClassInitFP)ObitTableGBTBEAM_OFFSETSClassInit;
  theClass->ObitClassInfoDefFn = (ObitClassInfoDefFnFP)ObitTableGBTBEAM_OFFSETSClassInfoDefFn;
  theClass->ObitGetClass  = (ObitGetClassFP)ObitTableGBTBEAM_OFFSETSGetClass;
  theClass->newObit       = (newObitFP)newObitTableGBTBEAM_OFFSETS;
  theClass->ObitCopy      = (ObitCopyFP)ObitTableGBTBEAM_OFFSETSCopy;
  theClass->ObitClone     = (ObitCloneFP)ObitTableClone;
  theClass->ObitClear     = (ObitClearFP)ObitTableGBTBEAM_OFFSETSClear;
  theClass->ObitInit      = (ObitInitFP)ObitTableGBTBEAM_OFFSETSInit;
  theClass->ObitTableConvert = (ObitTableConvertFP)ObitTableGBTBEAM_OFFSETSConvert;
  theClass->ObitTableOpen    = (ObitTableOpenFP)ObitTableGBTBEAM_OFFSETSOpen;
  theClass->ObitTableClose   = (ObitTableCloseFP)ObitTableGBTBEAM_OFFSETSClose;
  theClass->ObitTableRead    = (ObitTableReadFP)ObitTableRead;
  theClass->ObitTableReadSelect = 
    (ObitTableReadSelectFP)ObitTableReadSelect;
  theClass->ObitTableWrite = (ObitTableWriteFP)ObitTableWrite;
  theClass->ObitTableReadRow = 
    (ObitTableReadRowFP)ObitTableGBTBEAM_OFFSETSReadRow;
  theClass->ObitTableWriteRow = 
    (ObitTableWriteRowFP)ObitTableGBTBEAM_OFFSETSWriteRow;

} /* end ObitTableGBTBEAM_OFFSETSClassDefFn */

/**
 * Get table specific information from the infolist or descriptor
 * \param info Table to update
 * \param err  ObitErr for reporting errors.
 */
static void ObitTableGBTBEAM_OFFSETSUpdate (ObitTableGBTBEAM_OFFSETS *in, ObitErr *err)
{
  olong i;
  ObitTableDesc *desc;
   

 /* error checks */
   g_assert(ObitErrIsA(err));
  if (err->error) return;
  g_assert (ObitIsA(in, &myClassInfo));

  /* Get Keywords */

  /* initialize column numbers/offsets */
  in->NameOff = -1;
  in->NameCol = -1;
  in->xeloffOff = -1;
  in->xeloffCol = -1;
  in->eloffOff = -1;
  in->eloffCol = -1;
  in->srfeed1Off = -1;
  in->srfeed1Col = -1;
  in->srfeed2Off = -1;
  in->srfeed2Col = -1;
  /* Find columns and set offsets */
  desc = in->myDesc;
  if (desc->FieldName) {
    for (i=0; i<desc->nfield; i++) {
      if (!strncmp (desc->FieldName[i], "NAME    ", 8)) {
	 in->NameOff = desc->offset[i];
 	 in->NameCol = i;
      }
      if (!strncmp (desc->FieldName[i], "BEAMXELOFFSET", 13)) {
	 in->xeloffOff = desc->offset[i];
 	 in->xeloffCol = i;
      }
      if (!strncmp (desc->FieldName[i], "BEAMELOFFSET", 12)) {
	 in->eloffOff = desc->offset[i];
 	 in->eloffCol = i;
      }
      if (!strncmp (desc->FieldName[i], "SRFEED1  ", 9)) {
	 in->srfeed1Off = desc->offset[i];
 	 in->srfeed1Col = i;
      }
      if (!strncmp (desc->FieldName[i], "SRFEED2  ", 9)) {
	 in->srfeed2Off = desc->offset[i];
 	 in->srfeed2Col = i;
      }
     }
  }

  Obit_return_if_fail((in->NameOff > -1), err,
       "ObitTableBEAM_OFFSETSUpdate: Could not find column Name");
  Obit_return_if_fail((in->xeloffOff > -1), err,
       "ObitTableBEAM_OFFSETSUpdate: Could not find column xeloff");
  Obit_return_if_fail((in->eloffOff > -1), err,
       "ObitTableBEAM_OFFSETSUpdate: Could not find column eloff");
  Obit_return_if_fail((in->srfeed1Off > -1), err,
       "ObitTableBEAM_OFFSETSUpdate: Could not find column srfeed1");
} /* end ObitTableGBTBEAM_OFFSETSUpdate */

/**
 * Copy table specific (keyword) information  to infolist.
 * \param info Table to update
 * \param err  ObitErr for reporting errors.
 */
static void ObitTableGBTBEAM_OFFSETSDumpKey (ObitTableGBTBEAM_OFFSETS *in, ObitErr *err)
{
  ObitInfoList *info=NULL;

 /* error checks */
   g_assert(ObitErrIsA(err));
  if (err->error) return;
  g_assert (ObitIsA(in, &myClassInfo));

  /* Set Keywords */
  if (in->myIO!=NULL) info = ((ObitTableDesc*)(in->myIO->myDesc))->info;
  else info = in->myDesc->info;
   
} /* end ObitTableGBTBEAM_OFFSETSDumpKey */
