// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "header.h"
#include"Game/UObject/UObject.h"
#define DEBUG 1

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
#if DEBUG
      AllocConsole();
      freopen("CONOUT$", "w+", stdout);
      LOG("注入成功!");
      UObject::getInstance()->init();
      


#endif // DEBUG
     
    }
    break;
       
    }
    return TRUE;
}

