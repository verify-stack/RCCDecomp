# RCCDecomp
This is a partial decompilcation attempt of a ROBLOX legacy binary dated from May 13, 2008. The decompilcation may be scuffed because this is my first time doing this.

## What
RCCService is a service that ROBLOX still uses today to host gameservers and take thumbnails. This version is a legacy Windows version, as ROBLOX now hosts their servers on Linux.

## Get Started
Open the solution in Visual Studio 2005, build RCCService. And that's it, nothing else required.

## SOAP
When generating gSOAP files, you have to go into .nsmap files and replace the SOAP 1.2 links with SOAP 1.1 links. Sadly, I haven't figured out how to properly setup SOAP this without touching .nsmap.

To interact with RCCDecomp, use SoapUI (by p0s). Only HelloWorld is complete.

## Disclaimer
I don't speak legalese, you most likely don't. So let's make this simple.
RCCDecomp is not related to ROBLOX, Roblox, ROBLOX Corporation, or any thing related. RCCDecomp is a free open-source project using public binaries to view legacy code.

## Requirements
* Visual Studio 2005
* Visual C++ 8
