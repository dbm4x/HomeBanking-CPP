#include <iostream>
#include <string>
#include "Login.h"
#include "Menu.h"

using namespace std;

int main() {
    int intentos = 0;

    string usuario, password;
    Login login;
    Menu menu;

    cout << "Bienvenido al sistema de Homebanking ..." << endl;
    cout << "Inicia sesión para continuar ..." << endl << endl;

    while (true) {
        if (intentos >= 3) {
            cout << "Ha alcanzado el límite de intentos permitidos." << endl;
            cout << "Gracias por utilizar el sistema Homebanking." << endl;
            break;
        }
        cout << "Indique su usuario: ";
        cin >> usuario;
        cout << "Indique su contraseña: ";
        cin >> password;
        cout << endl << "*** Chequeando información ... ***" << endl << endl;
        if (login.inicioDeSesion(usuario, password)) {
            cout << "*** Bienvenido " << login.nombreCliente() << "! ***" << endl << endl;
            menu.VerMenu();
            cout << endl << "Bienvenido al sistema de Homebanking ..." << endl;
            cout << "Inicia sesión para continuar ..." << endl << endl;
        } else {
            cout << "Lamentablemente no pudimos validar su información. ";
            cout << "Intente nuevamente ... O ingrese 1 para salir." << endl << endl;

            string opcion;
            cin >> opcion;

            if (opcion == "1") {
                break;
            } else {
                intentos++;
            }
        }
    }

    cout << endl << "Gracias por utilizar el servicio de Homebanking. Vuelva pronto!" << endl;

    return 0;
}
