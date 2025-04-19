#if !defined(AUDIOPLAYER_H)
#define AUDIOPLAYER_H

#include <iostream>
#include <string>

#ifdef _WIN32
#include <sapi.h>
#include <sphelper.h>
#endif


class AUDIOPlayer
{

public:
	AUDIOPlayer();
	 void speak(std::string &text, int & languageOption);

};

#endif