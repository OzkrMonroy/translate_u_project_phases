#include "TranslateManager.h"

using namespace std;

TranslateManager::TranslateManager() : dictionary(), reader() {}

void TranslateManager::loadWordsFromJSONFile()
{
	ifstream filePath = reader.getJsonFile("data/translates.json");

	if (!filePath)
	{
		cout << "Error al abrir el archivo JSON \n"
				 << endl;
		return;
	}

	string currentLine;
	WordTranslations word;

	while (getline(filePath, currentLine))
	{
		if (currentLine.find("\"es\"") != string::npos)
		{
			word.spanish = reader.getValueFromJSON(currentLine);
		}
		else if (currentLine.find("\"it\"") != string::npos)
		{
			word.italian = reader.getValueFromJSON(currentLine);
		}
		else if (currentLine.find("\"fr\"") != string::npos)
		{
			word.french = reader.getValueFromJSON(currentLine);
		}
		else if (currentLine.find("\"de\"") != string::npos)
		{
			word.german = reader.getValueFromJSON(currentLine);
		}
		else if (currentLine.find("\"en\"") != string::npos)
		{
			word.english = reader.getValueFromJSON(currentLine);
		}
		else if (currentLine.find("}") != string::npos)
		{
			if (word.spanish.empty() || word.english.empty() ||
					word.italian.empty() || word.french.empty() || word.german.empty())
			{
				cout << "Advertencia: Se omitió una palabra por campos incompletos." << endl;
			}
			else
			{
				dictionary.insert(word);
			}

			word = WordTranslations();
		}
	}

	filePath.close();
}

void TranslateManager::displayWordsInDictionary()
{
	cout << "\nPalabras en el Diccionario:\n";
	dictionary.inOrderTraversal();
}