#include"UObject.h"
// ��ʼ����̬��Ա����
UObject* UObject::instance = nullptr;


BOOLEAN UObject::init()
{
    Module = get_module();
    if (!Module) return FALSE;
    FName = get_fname_addr();
    if (!FName) return FALSE;
    GWorld = get_gworld_addr();  
    if (!GWorld) return FALSE;
    FindObject = get_findobject_addr();
    if (!FindObject) return FALSE;
    ProcessEvent = get_processevent_addr();
    if (!ProcessEvent) return FALSE;

    return (TRUE);
}

DWORD64 UObject::get_module()
{
    LOG("��ȡmodule:%p", (DWORD64)GetModuleHandleA(NULL));
    return (DWORD64)GetModuleHandleA(NULL);
}

DWORD64 UObject::get_fname_addr()
{
    auto fnameaddr = Search((void*)Module, pattern_fname, mask_fname);
    if (fnameaddr)
    {
        LOG("��ȡfname:%p", *(DWORD*)((unsigned char*)fnameaddr + 3) + (PUCHAR)fnameaddr + 7);
        return  (DWORD64)(*(DWORD*)((unsigned char*)fnameaddr + 3) + (PUCHAR)fnameaddr + 7);
    }

    return DWORD64();
}

DWORD64 UObject::get_gworld_addr()
{
    auto uwordaddr = Search((void*)Module, pattern_uworld, mask_uworld);
    if (uwordaddr)
    {
        LOG("��ȡgworld:%p", *(DWORD*)((unsigned char*)uwordaddr + 3) + (PUCHAR)uwordaddr + 11);
        return  (DWORD64) (* (DWORD*)((unsigned char*)uwordaddr + 3) + (PUCHAR)uwordaddr + 11);
    }
 
    return DWORD64();
}

DWORD64 UObject::get_findobject_addr()
{
    auto findaddr = Search((void*)Module, pattern_find_object, mask__find_object);
    if (findaddr)
    {
        findaddr = (PUCHAR)findaddr + 18;
        LOG("��ȡfindobject:%p", *(DWORD*)((unsigned char*)findaddr + 1) + (PUCHAR)findaddr + 5);
        return  (DWORD64)(*(DWORD*)((unsigned char*)findaddr + 1) + (PUCHAR)findaddr + 5);
    }

    return DWORD64();
}

DWORD64 UObject::get_processevent_addr()
{
    auto addr = Search((void*)Module, pattern_processevent, mask__processevent);
    if (addr)
    {
      
        addr = (PUCHAR)addr + 15;
     
        LOG("��ȡprocessevent:%x", *(short*)((unsigned char*)addr + 2));
        return  (DWORD64)(*(short*)((unsigned char*)addr + 2));
    }

    return DWORD64();
}

UObject* UObject::getInstance()
{
	if (instance==nullptr)
	{
		instance = new UObject();

	}
	return instance;
}
