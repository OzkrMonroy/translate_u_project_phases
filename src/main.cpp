#include <iostream>
#include "./dictionaryMenu/DictionaryMenu.h"

#ifdef PLATFORM_WINDOWS
#include <windows.h>
#endif

using namespace std;

int main()
{
#ifdef PLATFORM_WINDOWS
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
#endif
	DictionaryMenu menu;
	menu.run();
	return 0;
}