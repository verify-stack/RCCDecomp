// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#ifndef STRICT
#define STRICT
#endif

#ifndef NOMINMAX
#define NOMINMAX
#endif

#define _CRT_SECURE_NO_WARNINGS 1
#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

#define _ATL_APARTMENT_THREADED

#define _WIN32_WINNT 0x0501
#define WINVER _WIN32_WINNT
#define _WIN32_WINDOWS _WIN32_WINNT 
#define NTDDI_VERSION 0x05010100	// NTDDI_WINXPSP1

#define _WIN32_IE 0x0601

#include <windows.h>
#include <conio.h>
#include <winreg.h>
#ifndef LSTATUS // i hate windows :D
typedef LONG LSTATUS;
#endif


// TODO: this disables support for registering COM objects
// exported by this project since the project contains no
// COM objects or typelib. If you wish to export COM objects
// from this project, add a typelib and remove this line
#define _ATL_NO_COM_SUPPORT

#include <atlbase.h>
#include <atlstr.h>
#include <atlcom.h>
#include <atlutil.h>

#include <iostream>
#include <string>
#include <stdexcept>

#define NO_SDL_MAIN
#define G3DEXPORT __declspec(dllimport)

// TODO: reference additional headers your program requires here

// debugging stuff
// only here until RobloxCrashReporter is here
#if _DEBUG
#define LOGEX(x) { std::cout << x << std::endl; printf("%ld \n", GetLastError()); }
#else
#define LOGEX(x) { std::cout << x << std::endl; exit(0); } // throw std::runtime_error(x);
#endif

#define strcmp(x, y) _mbsicmp((const unsigned char*)x, (const unsigned char*)y); // keep the function of _mbsicmp but remove the not so nice parts