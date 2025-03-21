#include "TranslateManager.h"

using namespace std;

TranslateManager::TranslateManager()
{
	TranslateManager::wordCollection = nullptr;
}

void TranslateManager::addWordToCollection(WordTranslations *wordTranslations)
{
	if (!wordTranslations)
		return;

	TranslateManager::WordCollectionRef newWordCollection = new TranslateManager::WordCollection;
	newWordCollection->wordTranslations = wordTranslations;
	newWordCollection->nextSpaceInCollection = TranslateManager::wordCollection;
	TranslateManager::wordCollection = newWordCollection;
}

void TranslateManager::displayWordsInCollection()
{
	TranslateManager::WordCollectionRef collection = TranslateManager::wordCollection;

	if (!collection)
	{
		cout << "El traductor no tiene ninguna palabra \n"
				 << endl;
		return;
	}

	while (collection)
	{
		if (collection->wordTranslations)
		{
			cout << "Traducción de " << collection->wordTranslations->spanish << " es: \n";
			cout << "Inglés: " << collection->wordTranslations->english << endl;
			cout << "Italiano: " << collection->wordTranslations->italian << endl;
			cout << "Francés: " << collection->wordTranslations->french << endl;
			cout << "Alemán: " << collection->wordTranslations->german << endl;
		}
		collection = collection->nextSpaceInCollection;
		cout << "\n";
	}
}