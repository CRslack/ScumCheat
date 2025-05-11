#pragma once
#include"../../header.h"


class UObject
{
public:
	static UObject* getInstance();

private:
	UObject() {};
	UObject(const UObject&) = delete;
	UObject& operator=(const UObject&) = delete;

	// ¾²Ì¬ÊµÀýÖ¸Õë
	static UObject* instance;
public:
	BOOLEAN init();

private:
	DWORD64 get_module();
	DWORD64 get_fname_addr();
	DWORD64 get_gworld_addr();
	DWORD64 get_findobject_addr();
	DWORD64 get_processevent_addr();
public:
	DWORD64 Module			= NULL;
	DWORD64 FName			= NULL;
	DWORD64 GWorld			= NULL;
	DWORD64 FindObject		= NULL;
	DWORD64 ProcessEvent	= NULL;
};
