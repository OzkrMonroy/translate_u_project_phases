#include <iostream>
#include "./utils/jsonReader/JSONReader.h"
#include "./translateManager/TranslateManager.h"
#include "./structs/WordTranslations.h"

using namespace std;
typedef WordTranslations *WordTranslationsRef;

TranslateManager manager = TranslateManager();

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

	string currentLine;
	WordTranslationsRef currentWord = nullptr;

	while (getline(filePath, currentLine))
	{
		if (currentLine.find("{") != string::npos && currentWord == nullptr)
		{
			currentWord = new WordTranslations;
		}
		else if (currentLine.find("\"es\"") != string::npos)
		{
			currentWord->spanish = reader.getValueFromJSON(currentLine);
		}
		else if (currentLine.find("\"it\"") != string::npos)
		{
			currentWord->italian = reader.getValueFromJSON(currentLine);
		}
		else if (currentLine.find("\"fr\"") != string::npos)
		{
			currentWord->french = reader.getValueFromJSON(currentLine);
		}
		else if (currentLine.find("\"de\"") != string::npos)
		{
			currentWord->german = reader.getValueFromJSON(currentLine);
		}
		else if (currentLine.find("\"en\"") != string::npos)
		{
			currentWord->english = reader.getValueFromJSON(currentLine);
		}
		else if (currentLine.find("}") != string::npos)
		{
			manager.addWordToCollection(currentWord);
			currentWord = nullptr;
		}
	}

	filePath.close();
}

int main()
{
	TranslateManager::WordCollectionRef wordCollection = nullptr;
	loadWordsFromJSONFile(wordCollection);

	manager.displayWordsInCollection();
	return 0;
}