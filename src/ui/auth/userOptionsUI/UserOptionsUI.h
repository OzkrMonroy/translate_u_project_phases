#if !defined(USEROPTIONSUI_H)
#define USEROPTIONSUI_H

#include <iostream>
#include <string>
#include "../translateManager/TranslateManager.h"



class UserOptionsUI {
	private:
        TranslateManager manager;
		void displayMenu() const;
		void handleUserChoise();
		void translatorScreen();
		void translateHistory();
		void topMostSearchedWords ();

	public:
		UserOptionsUI();
		void run();
};
#endif // USEROPTIONSUI_H