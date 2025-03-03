// RCCService.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

// creates the reg
int createRegMain()
{
  LSTATUS regStatus;
  HKEY hkeyResult;
  DWORD isNew;
  
  hkeyResult = (HKEY)0x0;
  regStatus = RegCreateKeyExA(
	  HKEY_LOCAL_MACHINE,  
	  "SYSTEM\\CurrentControlSet\\Services\\Eventlog\\Application\\RCCService",
	  0,
	  (LPSTR)0x0,
	  0,
	  0x2001f,
	  (LPSECURITY_ATTRIBUTES)0x0,
	  &hkeyResult,
	  &isNew
  );

  if (regStatus == ERROR_SUCCESS) {
    RegCloseKey(hkeyResult);
  }
  return regStatus; // review this
}

void createRCCReg()
{
  HKEY eventHKey;
  HKEY hKey;
  DWORD moduleNameResult;
  char lpFilename[268];

  int result;
  std::string errorString;

  eventHKey = (HKEY)0x0;
  result = createRegMain();
#if _DEBUG
  printf("reg status %ld\n", result);
#endif
  if (result != ERROR_SUCCESS) {
	errorString = "couldn\'t create RCCService reg key";
    // FUN_00402220(errorString); // TODO: add roblox crash reporter
	LOGEX(errorString)
  }
  moduleNameResult = GetModuleFileNameA(NULL, lpFilename, sizeof(lpFilename));
  if (moduleNameResult == NULL) {
    errorString = "GetModuleFileName failed";
    // FUN_00402220(errorString); // TODO: add roblox crash reporter
	LOGEX(errorString)
  }

  result = lstrlenA(lpFilename);
  hKey = eventHKey;
  RegSetValueExA(eventHKey, "EventMessageFile", 0, REG_EXPAND_SZ, (const BYTE *)lpFilename, result + 1);

  eventHKey = (HKEY)0x1f;
  RegSetValueExA(hKey, "TypesSupported", 0, REG_DWORD, (const BYTE *)&eventHKey, 4);
  
  if (hKey != NULL) {
    RegCloseKey(hKey);
  }
}

// create rcc service
void createRCCService()
{
  SC_HANDLE hSCManager;
  SC_HANDLE hService;
  SERVICE_FAILURE_ACTIONS lpInfoPointer = {};

  BOOL serviceConfigResult;
  DWORD moduleNameResult;

  std::string messageStatus;
  char lpFilename[268] = {};
  
  // setup misc stuff
  lpInfoPointer.dwResetPeriod = INFINITE;
  lpInfoPointer.lpRebootMsg = NULL;
  lpInfoPointer.lpCommand = NULL;
  lpInfoPointer.cActions = 0;
  lpInfoPointer.lpsaActions = NULL;

  moduleNameResult = GetModuleFileNameA(NULL, (LPCH)lpFilename, 0x104);
  if (moduleNameResult == 0) {
    messageStatus = "GetModuleFileName failed";
    // FUN_00402220(messageStatus); // TODO: add roblox crash reporter
	LOGEX(messageStatus)
  }

  hSCManager = OpenSCManagerA(NULL, NULL, 2);
  if (hSCManager == (SC_HANDLE)0x0) {
    messageStatus = "OpenSCManager failed";
    // FUN_00402220(messageStatus); // TODO: add roblox crash reporter
	LOGEX(messageStatus)
  }

  hService = CreateServiceA(
	  hSCManager,
	  "RCCService",
	  "Roblox Compute Cloud Service",
	  0xf01ff, // might be SC_MANAGER_ALL_ACCESS
	  SERVICE_WIN32_OWN_PROCESS,
	  SERVICE_AUTO_START,
	  SERVICE_ERROR_NORMAL,
      lpFilename,
	  NULL,
	  NULL,
	  NULL,
	  NULL,
	  NULL
  );
  if (hService == 0) { 
    CloseServiceHandle(hSCManager);
    moduleNameResult = GetLastError();
    if (moduleNameResult != ERROR_SERVICE_EXISTS) {
      messageStatus = "CreateService failed";
      // FUN_00402220(messageStatus); // TODO: add roblox crash reporter
      LOGEX(messageStatus)
    }
    printf("Service already installed\n");
  }
  else {
    printf("Service installed successfully\n");

    serviceConfigResult = ChangeServiceConfig2A(hService, SERVICE_CONFIG_FAILURE_ACTIONS, &lpInfoPointer);
    CloseServiceHandle(hService);
    CloseServiceHandle(hSCManager);
    if (serviceConfigResult == FALSE) {
      messageStatus = "ChangeServiceConfig2 failed";
      // FUN_00402220(messageStatus); // TODO: add roblox crash reporter
	  LOGEX(messageStatus)
    }
  }
}

// entry point
int main(int argc,char **argv)
{
  BOOL dispatchResult;
  DWORD lastError;
  SERVICE_TABLE_ENTRYA dispatchTable;

  int command;
  int pressedKey;
  char currentRawChar;
  char keyTerm;
  char currentChar;
  
  keyTerm = '\x01';
  currentRawChar = '\0';
  pressedKey = 1;

  // main loop
  while (pressedKey < argc) {
    if (*argv[pressedKey] == '/') {
      *argv[pressedKey] = '-';
    }

    command = _mbsicmp((const unsigned char*)argv[pressedKey], (const unsigned char*)"-Install");
    if (command == 0) {
      createRCCReg();
      createRCCService();
      keyTerm = '\0';
      pressedKey = pressedKey + 1;
    }
    else {
      command = _mbsicmp((const unsigned char*)argv[pressedKey], (const unsigned char*)"-Uninstall");
      if (command == 0) {
        //FUN_00406190();
        //FUN_004062f0();
        keyTerm = '\0';
        pressedKey = pressedKey + 1;
      }
      else {
        command = _mbsicmp((const unsigned char*)argv[pressedKey], (const unsigned char*)"-Start");
        if (command == 0) {
          //FUN_004061f0();
          keyTerm = '\0';
          pressedKey = pressedKey + 1;
        }
        else {
          command = _mbsicmp((const unsigned char*)argv[pressedKey], (const unsigned char*)"-Stop");
          if (command == 0) {
            //FUN_00406280();
            keyTerm = '\0';
            pressedKey = pressedKey + 1;
          }
          else {
            command = _mbsicmp((const unsigned char*)argv[pressedKey], (const unsigned char*)"-Console");
            if (command == 0) {
              currentRawChar = '\x01';
              keyTerm = '\0';
            }
            pressedKey = pressedKey + 1;
          }
        }
      }
    }
  }
  if (currentRawChar != '\0') {
    for (pressedKey = 1; pressedKey < argc; pressedKey = pressedKey + 1) {
      currentChar = *argv[pressedKey];
      if ((currentChar != '/') && (currentChar != '-')) {
        atoi(argv[pressedKey]);
      }
    }

    //FUN_00405b50();
    printf("Press ESC key to exit\n");
	
	// esc checking
    do {
      pressedKey = _kbhit();
      if (pressedKey != 0) {
        pressedKey = _getch();
        if (pressedKey == 0x1b) {
          printf("Service Shut Down\n");
          return 0;
        }
      }
      //FUN_00405ca0();
    } while( true );
  }

  // dispatch service
  // i don't know what this is lol
  if (keyTerm != '\0') {
    dispatchTable.lpServiceName = "RCCService";
    dispatchTable.lpServiceProc = NULL; //FUN_00406040;
    //dispatchResult = StartServiceCtrlDispatcherA(&dispatchTable);
	dispatchResult = 0;
    if (dispatchResult == 0) {
      lastError = GetLastError();
      printf("StartServiceCtrlDispatcher failed (%d)\n",lastError);
    }
  }

  return 0;
}