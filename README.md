# RCCDecomp
This is a partial decompilcation attempt of a ROBLOX legacy binary dated from May 13, 2008. The decompilcation may be scuffed because this is my first time doing this.

## What
RCCService is a service that ROBLOX still uses today to host gameservers and take thumbnails. This version is a legacy Windows version, as ROBLOX now hosts their servers on Linux.

## Requirements
* Visual Studio 2005
* Visual C++ 8.0
* Boost 1.35.0 (compiled)
* gSOAP 2.7.18 (already included with the repo)
* G3D 6.09 (VC8 libs)

### Useful Applications
* objdiff (if comparing binaries)
* SoapUI (by p0s)

## Get Started
Open the solution in Visual Studio 2005, compile Boost 1.35.0 and link G3D 6.09 libs (read more in the /libs folder).

Then, build RCCService in Release.

### Compiling In Debug
Due to the way Debug works when compiling, it is not currently viable to compile it without removing the App project completely.

## Helping Decompile
It's important to note that the App project is based on the last version of RBXGS due to a PDB being provided. So somethings may be wrong, if possible use the RCCService.exe application.

## SOAP
When generating gSOAP files, you have to go into .nsmap files and replace the SOAP 1.2 links with SOAP 1.1 links. Sadly, I haven't figured out how to properly setup SOAP this without touching .nsmap.
<br>
You also have to 

To interact with RCCDecomp, use SoapUI (by p0s). Only HelloWorld is complete.

## Disclaimer
I don't speak legalese, you most likely don't. So let's make this simple.
RCCDecomp is not related to ROBLOX, Roblox, ROBLOX Corporation, or any thing related. RCCDecomp is a free open-source project using public binaries to view legacy code.