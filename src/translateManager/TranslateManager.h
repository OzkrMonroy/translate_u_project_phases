#if !defined(TRANSLATEMANAGER_H)
#define TRANSLATEMANAGER_H

#include <iostream>
#include "../structs/WordTranslations.h"

class TranslateManager
{
public:
	struct WordCollection
	{
		WordTranslations *wordTranslations;
		WordCollection *nextSpaceInCollection;
	};
	typedef WordCollection *WordCollectionRef;

public:
	WordCollectionRef wordCollection;

public:
	TranslateManager();
	void addWordToCollection(WordTranslations *wordTranslations);
	void displayWordsInCollection();
};

#endif // TRANSLATEMANAGER
