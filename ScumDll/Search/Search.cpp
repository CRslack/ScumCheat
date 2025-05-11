#include "Search.h"



uintptr_t pattern_scan(uintptr_t base, size_t range, const char* pattern, const char* mask)
{
	const auto check_mask = [](const char* base, const char* pattern, const char* mask) -> bool {
		for (; *mask; ++base, ++pattern, ++mask) {
			if (*mask == 'x' && *base != *pattern)
				return false;
		}

		return true;
	};

	range = range - strlen(mask);

	for (size_t i = 0; i < range; ++i) {
		if (check_mask((const char*)base + i, pattern, mask))
			return base + i;
	}

	return NULL;
}






void* Search(void* imagebase, const char* pattern, const char* mask, const char* sectname)
{
	void* start = 0;
	void* end = 0;


	PIMAGE_DOS_HEADER        pDos = (PIMAGE_DOS_HEADER)imagebase;
	PIMAGE_NT_HEADERS        pNth = (PIMAGE_NT_HEADERS)((PCHAR)imagebase + pDos->e_lfanew);
	PIMAGE_FILE_HEADER		 pFil = (PIMAGE_FILE_HEADER)((PCHAR)pNth + sizeof(pNth->Signature));
	PIMAGE_OPTIONAL_HEADER   pOpo = (PIMAGE_OPTIONAL_HEADER)((PUCHAR)pFil + IMAGE_SIZEOF_FILE_HEADER);
	PIMAGE_SECTION_HEADER    pSec = (PIMAGE_SECTION_HEADER)((PUCHAR)pOpo + pFil->SizeOfOptionalHeader);

	CHAR szSecName[9] = { 0 };
	for (size_t i = 0; i < pFil->NumberOfSections; i++)
	{
		memset(szSecName, 0, 9);
		memcpy(szSecName, pSec[i].Name, IMAGE_SIZEOF_SHORT_NAME);
		if (strcmp(szSecName, sectname)==0)
		{
			start = (void*)(pSec[i].VirtualAddress+ (PUCHAR)imagebase);
			const uintptr_t match = pattern_scan((uintptr_t)start, pSec[i].Misc.VirtualSize, pattern, mask);
			if (match)
				return (void*)match;
			break;
		}

	}





	return nullptr;
}
