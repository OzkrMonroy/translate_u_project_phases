#include "DictionaryMenu.h"
using namespace std;

DictionaryMenu::DictionaryMenu()
{
	manager.loadWordsFromJSONFile();
}

void DictionaryMenu::run()
{
	while (true)
	{
		displayMenu();
		handleUserChoise();
	}
}

void DictionaryMenu::displayMenu() const
{
	cout << "\n--- Menú del Diccionario ---\n";
	cout << "1. Mostrar palabras\n";
	cout << "2. Agregar nueva palabra\n";
	cout << "3. Eliminar una palabra\n";
	cout << "4. Salir\n";
	cout << "Seleccione una opción: ";
}

void DictionaryMenu::handleUserChoise()
{
	int choise;
	cin >> choise;
	cin.ignore();

	switch (choise)
	{
	case 1:
		displayWords();
		break;
	case 2:
		addWord();
		break;
	case 3:
		deleteWord();
		break;
	case 4:
		cout << "Saliendo del programa...\n";
		exit(0);
	default:
		cout << "Opción no válida. Intente de nuevo.\n";
	}
}

void DictionaryMenu::displayWords()
{
	manager.displayWordsInDictionary();
}

void DictionaryMenu::addWord()
{
	WordTranslations word;

	cout << "Ingrese la palabra en español: ";
	getline(cin, word.spanish);
	cout << "Ingrese la traducción en inglés: ";
	getline(cin, word.english);
	cout << "Ingrese la traducción en italiano: ";
	getline(cin, word.italian);
	cout << "Ingrese la traducción en francés: ";
	getline(cin, word.french);
	cout << "Ingrese la traducción en alemán: ";
	getline(cin, word.german);

	manager.addWord(word);
}

void DictionaryMenu::deleteWord()
{
	string word;
	cout << "Ingrese la palabra en español a eliminar: ";
	getline(cin, word);

	manager.removeWord(word);
	cout << "La palabra ha sido eliminada. \n";
}
