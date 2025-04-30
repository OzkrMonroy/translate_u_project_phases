#include <iostream>
#include "./dictionaryMenu/DictionaryMenu.h"

#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main()
{
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);
#endif
 	DictionaryMenu menu;
	menu.run();
	return 0;
}