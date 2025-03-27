#if !defined(TRANSLATEMANAGER_H)
#define TRANSLATEMANAGER_H

#include <iostream>
#include <string>
#include "../dictionaryAVLTree/DictionaryAVLTree.h"
#include "../utils/jsonReader/JSONReader.h"

class TranslateManager
{
private:
	DictionaryAVLTree dictionary;
	JSONReader reader;

public:
	TranslateManager();
	void loadWordsFromJSONFile();
	void displayWordsInDictionary();
	void addWord(const WordTranslations &word);
	void removeWord(const std::string &spanish);
};

#endif // TRANSLATEMANAGER
