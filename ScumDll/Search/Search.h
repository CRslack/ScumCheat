#pragma once
#include<Windows.h>
/// <summary>
/// 
/// </summary>
/// <param name="imagebase"></param>
/// <param name="size"></param>
/// <param name="pattern"></param>
/// <param name="mask"></param>
/// <param name="sectname"></param>
/// <returns></returns>

void* Search(void* imagebase, const char* pattern, const char* mask,const char* sectname=".text");

