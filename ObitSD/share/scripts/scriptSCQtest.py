# Program to self calibrate galactic center C band data
# Takes input data in OTF FITS format with basic instrumental
# and atmospheric calibration applied.
# The script iteratively inprovesd the derived image and calibration.

import OTF, OTFGetSoln, Image, OSystem, OErr

# Init Obit
err=OErr.OErr()
ObitSys=OSystem.OSystem ("SCGCC", 1, 103, 1, ["None"], 1, ["../PythonData/"], 1, 0, err)
OErr.printErrMsg(err, "Error with Obit startup")

# Files
disk = 1
inFile   = "QbandCalOTF.fits"         # input OTF data
dirtFile = "!QTestSecond.fits"         # output dirty image file
#beamFile = "DirtyBeam.fits"           # input dirty beam image
#cleanFile= "!GCCClean.fits"           # output CLEAN image

# Images for cleaning
#Beam  = Image.newPImage("Dirty Beam", beamFile, disk, 1, err)
#Clean = Image.newPImage("Clean Image", cleanFile, disk, 0, err)

# Set data
inData = OTF.newPOTF("Input data", inFile, disk, 1, err)
OErr.printErrMsg(err, "Error creating input data object")

# Imaging parameters
OTF.ImageInput["InData"]  = inData
OTF.ImageInput["disk"]    = disk
OTF.ImageInput["OutName"] = dirtFile
OTF.ImageInput["ra"]  = 194.04646          # Center RA
OTF.ImageInput["dec"] = -5.78892           # Center Dec
OTF.ImageInput["xCells"] = 4.0 / 3600.0    # "X" cell spacing, deg
OTF.ImageInput["yCells"] = 4.0 / 3600.0    # "Y" cell spacing, deg
OTF.ImageInput["nx"] = 100                 # number of cells in X
OTF.ImageInput["ny"] = 100                 # number of cells in Y
OTF.ImageInput["gainuse"] = 0              # Which cal table to apply, -1 = none
OTF.ImageInput["flagver"] = 1              # Which flag table to apply, -1 = none

# CLEAN parameters
#OTF.CleanInput["Beam"]     = Beam          # Dirty beam
#OTF.CleanInput["Clean"]    = Clean         # Clean image
#OTF.CleanInput["niter"]    = 5000          # Number of iterations
#OTF.CleanInput["gain"]     = 0.05          # CLEAN loop gain
#OTF.CleanInput["beamsize"] = 80.0          # CLEAN restoring beam size in asec
#OTF.CleanInput["minFlux"]  = 0.3           # Minimum image brightness to CLEAN

# Calibration parameters (some reset in loop)
OTF.ResidCalInput["InData"]  = inData      # Input data object
OTF.ResidCalInput["solType"] = "Filter"    # Solution type
OTF.ResidCalInput["solint"]  = 500.0       # Solution interval (sec)
OTF.ResidCalInput["minFlux"] = 1.0         # Minimum image brightness to use in model
OTF.ResidCalInput["Clip"]    = 0.1         # Minimum image brightness to use in model
OTF.ResidCalInput["gainuse"] = 0           # Prior calibration, 0> highest
OTF.ResidCalInput["minEl"] = 5.0           # minimum elevation

# Soln2Cal parameters (most defaulted)
OTF.Soln2CalInput["InData"]  = inData       # Input data object
OTF.Soln2CalInput["oldCal"]  = 0            # Use highest extant Cal table as input

# Initialize calibtration tables
# delete any prior calibration tables
OTF.ClearCal(inData,err)

# Create an initial dummy table with a interval 1/4 of the shortest
# Filter type solution interval.
inter = 1.25
OTFGetSoln.POTFGetDummyCal (inData, inData, inter, 1, 1, err)

# Solution intervals, Residual clipping pairs
# The residual clipping is needed to suppress artifacts due to large
# residuals near bright point sources; it should start off large
# and decrease to several times the noise.
# It not needed, set to a large value (1.0e20)
# These define the number and parameters of the iterations
soln = [(60.0,30.0), (45.0,8.0), (30.0,8.), (20.0,5.0), (10.0,2.5), (5.0,1.0), (5.0,0.5), (5.0,0.2)]
# Loop over self cal
count=0
for si,mf in soln:
    count = count+1
    print "\n *** Self calibration loop ",count,"si=",si
    OTF.ResidCalInput["solint"]  = si
    OTF.ResidCalInput["minFlux"] = mf
    OTF.ResidCalInput["Clip"] = mf
    #OTF.SelfCal(err, OTF.ImageInput, OTF.CleanInput, OTF.ResidCalInput, OTF.Soln2CalInput)
    OTF.SelfCal(err, OTF.ImageInput, "None", OTF.ResidCalInput, OTF.Soln2CalInput)

print 'Finished with loop, final image and clean'

# Final image and Clean
image = OTF.makeImage(err,  OTF.ImageInput)
#OTF.CleanInput["Dirty"] = image                  # Clean image just produced
#OTF.Clean (err,  OTF.CleanInput)

# Shutdown 
OErr.printErr(err)
print 'Done, calibrated',inFile,'image',dirtFile
del ObitSys
