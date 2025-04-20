#include "TranslationFileHandler.h"

using namespace std;
namespace fs = filesystem;

TranslationFileHandler::TranslationFileHandler()
{
	path_to_main = std::filesystem::current_path();
	src_path = "src";
}

ifstream TranslationFileHandler::getFile(fs::path path)
{
	string jsonFile = (path_to_main / src_path / path).string();
	ifstream filePath(jsonFile);

	return filePath;
}

string TranslationFileHandler::getValueFromFile(string &line)
{
	size_t lineStart = line.find(":");
	if (lineStart == string::npos)
		return "";

	lineStart++;
	while (lineStart < line.size() && isspace(line[lineStart]))
	{
		lineStart++;
	}

	if (line[lineStart] == '\"')
	{
		size_t lineEnd = line.find("\"", lineStart + 1);
		if (lineEnd == string::npos)
			return "";
		return line.substr(lineStart + 1, lineEnd - lineStart - 1);
	}
	else
	{
		size_t lineEnd = line.find_first_of(",}", lineStart);
		if (lineEnd == string::npos)
			lineEnd = line.size();
		return line.substr(lineStart, lineEnd - lineStart);
	}
}

void TranslationFileHandler::addTranslationEntry(const WordTranslations &translation, const fs::path &file_path)
{
	string fullPath = (path_to_main / src_path / file_path).string();

	// Leer archivo completo (si existe)
	ifstream inFile(fullPath);
	string content;
	if (inFile.is_open())
	{
		content.assign((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
		inFile.close();
	}

	// Si no tiene contenido, crear estructura base
	if (content.empty())
	{
		content = "{\n\t\"translates\": [\n\t]\n}";
	}

	// Buscar cierre del array
	size_t pos = content.rfind("]");
	if (pos == string::npos)
	{
		cerr << "Archivo con formato incorrecto.\n";
		return;
	}

	// Buscar si ya hay al menos un objeto dentro del array
	size_t arrayStart = content.find("[");
	bool hasEntries = false;

	if (arrayStart != string::npos && arrayStart < pos)
	{
		string arrayContent = content.substr(arrayStart + 1, pos - arrayStart - 1);
		hasEntries = arrayContent.find("{") != string::npos;
	}

	// Crear nuevo bloque de traducción
	string newEntry = hasEntries ? ",\n\t\t{" : "\n\t\t{";
	newEntry += "\n\t\t\t\"es\": \"" + translation.spanish + "\",";
	newEntry += "\n\t\t\t\"it\": \"" + translation.italian + "\",";
	newEntry += "\n\t\t\t\"fr\": \"" + translation.french + "\",";
	newEntry += "\n\t\t\t\"de\": \"" + translation.german + "\",";
	newEntry += "\n\t\t\t\"en\": \"" + translation.english + "\"";
	newEntry += "\n\t\t}";

	// Insertar en el contenido antes del cierre del array
	content.insert(pos, newEntry);

	// Escribir de nuevo el archivo
	ofstream outFile(fullPath);
	if (!outFile.is_open())
	{
		cerr << "No se pudo abrir el archivo para escritura.\n";
		return;
	}
	outFile << content;
	outFile.close();
}

void TranslationFileHandler::ensureFileExistsWithBaseStructure(const fs::path &file_path)
{
	string fullPath = (path_to_main / src_path / file_path).string();
	fs::create_directories(fs::path(fullPath).parent_path());

	if (!fs::exists(fullPath))
	{
		ofstream outFile(fullPath);
		if (!outFile.is_open())
		{
			cerr << "No se pudo crear el archivo.\n";
			return;
		}

		outFile << "{\n\t\"translates\": [\n\t]\n}";
		outFile.close();
	}
}