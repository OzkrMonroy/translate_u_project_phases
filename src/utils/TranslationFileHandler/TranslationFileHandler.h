#if !defined(TRANSLATIONFILEHANDLER_H)
#define TRANSLATIONFILEHANDLER_H

#include <iostream>
#include <filesystem>
#include <fstream>
#include "../../structs/WordTranslations.h"
#include "../../structs/AVLNode.h"

class TranslationFileHandler
{
private:
	std::filesystem::path path_to_main;

private:
	std::string src_path;

public:
	TranslationFileHandler();
	std::string getValueFromFile(std::string &line);
	std::ifstream getFile(std::filesystem::path path);
	void addTranslationEntry(const WordTranslations &translation, const std::filesystem::path &file_path);
	void ensureFileExistsWithBaseStructure(const std::filesystem::path &file_path);
	void writeAllFromTree(AVLNode *root, const std::filesystem::path &file_path);
};

#endif