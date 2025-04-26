#include "WelcomeUI.h"
using namespace std;

WelcomeUI::WelcomeUI()
{
}

void WelcomeUI::run()
{
}

void WelcomeUI::displayWelcomeOptions() const
{
    cout << "\n--- Bienvenido ---\n";
	cout << "1. Iniciar sesión\n";
	cout << "2. Registrarse\n";
	cout << "3. Traducir\n";
	cout << "4. Salir\n";
	cout << "Seleccione una opción: ";
}

void WelcomeUI::handleUserChoise()
{
    
	int choise;
	cin >> choise;
	cin.ignore();

	switch (choise)
	{
	case 1:
		login();
		break;
	case 2:
		registerUser();
		break;
	case 3:
		translator();
		break;
	case 4:
		cout << "Saliendo del programa...\n";
		exit(0);
	default:
		cout << "Opción no válida. Intente de nuevo.\n";
	}
}

void WelcomeUI::login()
{
    string userName;
    string userPasword;

    cout << "Ingrese su nombre de usuario\n";
    getline(cin,userName);

    cout << "Ingrese su contraseña\n";
    getline(cin,userPasword);

}

void WelcomeUI::registerUser()
{
}

void WelcomeUI::translator()
{
}


