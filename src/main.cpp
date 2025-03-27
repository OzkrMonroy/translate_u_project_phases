#include <iostream>
#include "./translateManager/TranslateManager.h"

using namespace std;

int main()
{
	TranslateManager manager;
	manager.loadWordsFromJSONFile();
	manager.displayWordsInDictionary();
	return 0;
}