// RegApp.h : Include file for standard system include files,
// or project specific include files.

#pragma once

#include <iostream>

// TODO: Reference additional headers your program requires here.

#include <windows.h>
#include <winreg.h>

class RegApp
{
public:
  
    LSTATUS EnabledUAC(BOOL bEnabled = FALSE)
    {
        HKEY hKey = NULL;
        DWORD dwValue = bEnabled ? 1 : 0;
        LSTATUS lStatus = ERROR_SUCCESS;
        lStatus &= RegOpenKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Policies\\System", 0, KEY_WRITE, &hKey);
        dwValue = bEnabled ? 5 : 0;
        lStatus &= RegSetValueExA(hKey, ("ConsentPromptBehaviorAdmin"), 0, REG_DWORD, (LPBYTE)&dwValue, sizeof(dwValue));
        dwValue = bEnabled ? 1 : 0;
        lStatus &= RegSetValueExA(hKey, ("EnableLUA"), 0, REG_DWORD, (LPBYTE)&dwValue, sizeof(dwValue));
        dwValue = bEnabled ? 1 : 0;
        lStatus &= RegSetValueExA(hKey, ("PromptOnSecureDesktop"), 0, REG_DWORD, (LPBYTE)&dwValue, sizeof(dwValue));
        dwValue = bEnabled ? 1 : 0;
        lStatus &= RegSetValueExA(hKey, ("FilterAdministratorToken"), 0, REG_DWORD, (LPBYTE)&dwValue, sizeof(dwValue));
        lStatus &= RegCloseKey(hKey);
        return lStatus;
    }

    LSTATUS RegAuto(BOOL bAuto)
    {
        HKEY hKey = NULL;
        DWORD dwValue = 0;
        LSTATUS lStatus = ERROR_SUCCESS;
        CHAR czFileName[MAX_PATH] = { 0 };
        lStatus &= RegOpenKeyExA(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_WRITE, &hKey);
        if (bAuto == TRUE)
        {
            GetModuleFileNameA(NULL, czFileName, sizeof(czFileName) / sizeof(*czFileName));
            lStatus &= RegSetValueExA(hKey, (strrchr(czFileName, '\\') + 1), 0, REG_SZ, (LPBYTE)czFileName, lstrlenA(czFileName) + 1);
        }
        else 
        {
            lStatus &= RegSetValueExA(hKey, (strrchr(czFileName, '\\') + 1), 0, REG_SZ, (LPBYTE)czFileName, lstrlenA(czFileName) + 1);
        }
        lStatus &= RegCloseKey(hKey);
        return lStatus;
    }
public:
    static RegApp* Inst() {
        static RegApp RegAppInstance;
        return &RegAppInstance;
    }
};
