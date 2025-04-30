#if !defined(AUDIOPLAYER_H)
#define AUDIOPLAYER_H

#include <iostream>
#include <string>

#ifdef _WIN32
#include <windows.h>
#include <sapi.h>
#include <sphelper.h>
#include <sstream>
#endif


class AUDIOPlayer
{
	private: 
	void winSpeak(std::string &text, int & languageOption);
	void macSpeak(std::string &text);

	public:
	AUDIOPlayer();
	 void speak(std::string &text, int & languageOption);

};

#endif