// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows XP or later.                   
#define _WIN32_WINNT 0x0501	// Change this to the appropriate value to target other versions of Windows.
#endif						

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers


// windows header
#include <windows.h>


// boost libraries
#include "boost/shared_ptr.hpp"
#include "boost/noncopyable.hpp"

// std libraries
#include <vector>
#include <string>

// TODO: reference additional headers your program requires here

// Taken from the source code it self.
// Some classes don't include vtable, they do this via this:
#define RBXBaseClass	__declspec(novtable)

// Filler for functions that are unknown
// aka _invalid_parameter_noinfo();
#define UNKNOWN()