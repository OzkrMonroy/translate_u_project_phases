#include "JSONReader.h"

using namespace std;
namespace fs = filesystem;

JSONReader::JSONReader()
{
	path_to_main = std::filesystem::current_path();
	src_path = "src";
}

ifstream JSONReader::getJsonFile(string fileName)
{
	string jsonFile = (path_to_main / src_path / fileName).string();
	ifstream filePath(jsonFile);

	return filePath;
}

string JSONReader::getValueFromJSON(string &line)
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