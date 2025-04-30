#if !defined(WELCOMEUI_H)
#define WELCOMEUI_H

#include <iostream>


class WelcomeUI {
	private:
        void displayWelcomeOptions()const;
        void handleUserChoise();
		void login();
		void registerUser();
		void translator();
		

	public:
		WelcomeUI();
		void run();
};
#endif