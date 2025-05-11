
#include"Engine.h"

Engine* Engine::find_object(Engine* Class, Engine* InOuter, const TCHAR* Name, bool ExactClass)
{
	typedef Engine* (_fastcall* Fn)(Engine* Class, Engine* InOuter, const TCHAR* Name, bool ExactClass);
	Fn fn{ (Fn)UObject::getInstance()->FindObject };

	return fn(nullptr, (Engine*)-1, Name, false);
}

void Engine::process_event(Engine* fun, void* param)
{
	DWORD64** vtb = (*(DWORD64***)this);

	typedef void(_fastcall* Pe)(PVOID this_, Engine* fun, void* param);
	Pe fn{ (Pe)UObject::getInstance()->ProcessEvent };
	fn(this, fun, param);
}
