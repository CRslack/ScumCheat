#pragma once
#include"../UObject/UObject.h"
class Engine
{
public:
	static Engine* find_object(Engine* Class, Engine* InOuter, const TCHAR* Name, bool ExactClass);
	void process_event(Engine* fun, void* param);
	


};

