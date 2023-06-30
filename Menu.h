#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include "Operaciones.h"
#include "Login.h"

class Menu {
public:
    void VerMenu();
    void deposito(Operaciones& operacion);
    void retiro(Operaciones& operacion);
    void prestamo(Operaciones& operacion);
    void movimientos(Operaciones& operacion);
    void cambiopass(Login& login);
    void cambionombre(Login& login);
};

#endif
