#include <iostream>
#include "Menu.h"
#include "Operaciones.h"
#include "Login.h"

void Menu::VerMenu() {
    bool salir = false;
    Operaciones operacion;
    Login login;

    do {
        cout << "*** El saldo en su cuenta es de $" << operacion.SaldoActual() << ". ***" << endl << endl;
        cout << "Elija el tipo de operación que desea realizar ..." << endl << endl;
        cout << "1) Deposito." << endl;
        cout << "2) Retiro." << endl;
        cout << "3) Prestamo." << endl;
        cout << "4) Lista de movimientos." << endl << endl;
        cout << "Otras opciones:" << endl << endl;
        cout << "5) Cambio de password." << endl;
        cout << "6) Modificar nombre y apellido." << endl;
        cout << "7) Salir." << endl;

        string opcion;
        cin >> opcion;

        if (opcion == "1") {
            deposito(operacion);
        } else if (opcion == "2") {
            retiro(operacion);
        } else if (opcion == "3") {
            prestamo(operacion);
        } else if (opcion == "4") {
            movimientos(operacion);
        } else if (opcion == "5") {
            cambiopass(login);
        } else if (opcion == "6") {
            cambionombre(login);
        } else if (opcion == "7") {
            salir = true;
        }
    } while (!salir);
}

void Menu::deposito(Operaciones& operacion) {
    cout << endl << "Ingrese el monto que desea depositar: ";
    string monto;
    cin >> monto;
    try {
        if (operacion.RealizarDeposito(stoi(monto))) {
            cout << endl << "*** Deposito realizado con éxito ***" << endl;
        } else {
            cout << endl << "*** Error. Ingrese valores válidos e intente nuevamente. ***" << endl;
        }
    } catch (exception& e) {
        cout << endl << "*** Uno o más errores ocurrieron durante el deposito, intente nuevamente. ***" << endl;
    }
}

void Menu::retiro(Operaciones& operacion) {
    cout << endl << "Ingrese el monto que desea retirar: ";
    string monto;
    cin >> monto;
    try {
        if (operacion.RetirarSaldo(stoi(monto))) {
            cout << endl << "*** Retiro realizado con éxito ***" << endl;
        } else {
            cout << endl << "*** Error. Ingrese valores válidos e intente nuevamente. ***" << endl;
        }
    } catch (exception& e) {
        cout << endl << "*** Uno o más errores ocurrieron durante el retiro, intente nuevamente. ***" << endl;
    }
}

void Menu::prestamo(Operaciones& operacion) {
    cout << endl << "Ingrese el monto del prestamo: ";
    string monto;
    cin >> monto;
    try {
        operacion.RealizarPrestamo(stoi(monto));
        cout << endl << "*** Prestamo aprobado. ***" << endl;
    } catch (exception& e) {
        cout << endl << "*** Uno o más errores ocurrieron durante el tramite de su prestamo, intente nuevamente. ***" << endl;
    }
}

string obtenerNombreMovimiento(int tipoMovimiento) {
    string nombreMovimiento;
    switch (tipoMovimiento) {
        case 0:
            nombreMovimiento = "Retiro";
            break;
        case 1:
            nombreMovimiento = "Deposito";
            break;
        case 2:
            nombreMovimiento = "Prestamo";
            break;
        default:
            nombreMovimiento = "Desconocido";
            break;
    }
    return nombreMovimiento;
}

void Menu::movimientos(Operaciones& operacion) {
    cout << endl << "Lista de movimientos:" << endl << endl;
    vector<Operaciones::movimientos> listaMovimientos = operacion.ListaMovimientos();
    for (const auto& movimiento : listaMovimientos) {
        cout << "------------------------------------" << endl;
        cout << "Tipo de movimiento: " << obtenerNombreMovimiento(movimiento.tipo) << endl;
        cout << "Fecha: " << movimiento.fecha << endl;
        cout << "Saldo anterior al movimiento: $" << movimiento.saldoAnterior << endl;
        cout << "Saldo despues del movimiento: $" << movimiento.saldoActual << endl;
    }
    if (listaMovimientos.empty()) {
        cout << "*** Sin registros recientes. ***" << endl << endl;
    } else {
        cout << "------------------------------------" << endl << endl;
    }
}

void Menu::cambiopass(Login& login) {
    cout << endl << "Cambio de contraseña ..." << endl;
    cout << "Ingrese su contraseña anterior: ";
    string vieja;
    cin >> vieja;
    cout << "Ingrese nueva contraseña: ";
    string nueva;
    cin >> nueva;

    if (login.cambioPass(vieja, nueva)) {
        cout << endl << "*** Contraseña cambiada con éxito. ***" << endl;
    } else {
        cout << endl << "*** Error al cambiar la contraseña. Chequee sus datos e intente nuevamente ... ***" << endl;
    }
}

void Menu::cambionombre(Login& login) {
    cout << endl << "Cambio de nombre ..." << endl;
    cout << "Ingrese su nuevo nombre: ";
    string nombre;
    cin >> nombre;
    login.cambioNombre(nombre);
    cout << endl << "Cambio realizado con éxito. Hola de nuevo " << login.nombreCliente() << "!" << endl;
}
