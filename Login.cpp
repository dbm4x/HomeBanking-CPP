#include "Login.h"

std::string Login::usuario = "juan";
std::string Login::contra = "123";
std::string Login::nombre = "Juan diaz";

bool Login::inicioDeSesion(const std::string& usuario, const std::string& contra) {
    return chequeoLogin(usuario, contra); // Simular conectando con db ...
}

bool Login::chequeoLogin(const std::string& usuario, const std::string& contra) {
    if (usuario == this->usuario && contra == this->contra) {
        return true;
    }
    return false;
}

void Login::cambioNombre(const std::string& nombre) {
    this->nombre = nombre;
}

bool Login::cambioPass(const std::string& viejaPass, const std::string& pass) {
    if (viejaPass == this->contra) {
        this->contra = pass;
        return true;
    }
    return false;
}

std::string Login::nombreCliente() {
    return nombre;
}
