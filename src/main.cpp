#include <iostream>
#include "./utils/jsonReader/JSONReader.h"
#include "./translateManager/TranslateManager.h"
#include "./structs/WordTranslations.h"
#include "./dictionaryAVLTree/DictionaryAVLTree.h"

using namespace std;
typedef WordTranslations *WordTranslationsRef;

TranslateManager manager = TranslateManager();
DictionaryAVLTree dictionary;

void loadWordsFromJSONFile(TranslateManager::WordCollectionRef &collectionRef)
{
	JSONReader reader = JSONReader();
	ifstream filePath = reader.getJsonFile("translate/translates.json");

	if (!filePath)
	{
		cout << "Error al abrir el archivo JSON \n"
				 << endl;
		return;
	}

	string currentLine, spanish, english, italian, french, german;
	WordTranslationsRef currentWord = nullptr;

	while (getline(filePath, currentLine))
	{
		if (currentLine.find("{") != string::npos && currentWord == nullptr)
		{
			currentWord = new WordTranslations;
		}
		else if (currentLine.find("\"es\"") != string::npos)
		{
			spanish = reader.getValueFromJSON(currentLine);
		}
		else if (currentLine.find("\"it\"") != string::npos)
		{
			italian = reader.getValueFromJSON(currentLine);
		}
		else if (currentLine.find("\"fr\"") != string::npos)
		{
			french = reader.getValueFromJSON(currentLine);
		}
		else if (currentLine.find("\"de\"") != string::npos)
		{
			german = reader.getValueFromJSON(currentLine);
		}
		else if (currentLine.find("\"en\"") != string::npos)
		{
			english = reader.getValueFromJSON(currentLine);
		}
		else if (currentLine.find("}") != string::npos)
		{
			dictionary.insert({spanish, italian, french, german, english});
			// manager.addWordToCollection(currentWord);
			// currentWord = nullptr;
		}
	}

	filePath.close();
}

int main()
{
	TranslateManager::WordCollectionRef wordCollection = nullptr;
	loadWordsFromJSONFile(wordCollection);

	// manager.displayWordsInCollection();
	dictionary.inOrderTraversal();
	return 0;
}