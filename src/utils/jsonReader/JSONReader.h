#ifndef JSONREADER_H
#define JSONREADER_H

#include <iostream>
#include <filesystem>
#include <fstream>

class JSONReader
{
private:
	std::filesystem::path path_to_main;

private:
	std::string src_path;

public:
	JSONReader();
	std::string getValueFromJSON(std::string &line);
	std::ifstream getJsonFile(std::string fileName);
};

#endif