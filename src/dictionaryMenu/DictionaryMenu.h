#if !defined(DICTIONARYMENU_H)
#define DICTIONARYMENU_H

#include <iostream>
#include "../translateManager/TranslateManager.h"

class DictionaryMenu {
	private:
		TranslateManager manager;
		void displayMenu() const;
		void handleUserChoise();
		void displayWords();
		void addWord();
		void deleteWord();

	public:
		DictionaryMenu();
		void run();
};
#endif // DICTIONARYMENU_H
