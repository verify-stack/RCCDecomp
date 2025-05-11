# Libraries
Important libraries are not automaticly included.
You'll have to compile these seperately from Visual Studio 2005.

This is what the root folders should look like:
```
libs ............................................Root folder
	README.md ...............................Instructions!!!
	boost_1_35_0 ......................................Boost
		Files here (make sure it's not another folder!)
	g3d-6_09 ............................................G3D
		Files here (make sure it's not another folder!)
```
Links to the libraries mentioned:
* [Boost 1.35.1](https://www.boost.org/users/history/version_1_35_0.html)
* [G3D 6.09 (Compilied)](https://sourceforge.net/projects/g3d/files/g3d-cpp/6.09/)

## Boost
You can find it in Boost's older releases (unlike gSOAP).
Next, you'll need to build Boost via bjam.

Extract it so the directory looks a bit like this:
```
boost_1_35_0 .....................................Root folder
	index.htm ............A copy of www.boost.org starts here
	   boost\ .........................All Boost Header files
	   lib\ .....................precompiled library binaries
	   libs\ ............Tests, .cpps, docs, etc., by library
		 index.html ........Library documentation starts here
		 algorithm\
		 any\
		 array\
						 …more libraries…
	   status\ .........................Boost-wide test suite
	   tools\ ...........Utilities, e.g. bjam, quickbook, bcp
	   more\ ..........................Policy documents, etc.
	   doc\ ...............A subset of all Boost library docs
```
	   
## G3D
The SourceForge should have 6.09, make sure you extract g3d-6_09.zip.

Should look like this:
```
g3d-6_09 .....................................Root folder
	include ................................Include files
	win32-vc8-lib ..........................Library files
```
	
The rest isn't required, only the two above