#ifndef LOGIN_H
#define LOGIN_H

#include <string>

class Login {
private:
    static std::string usuario;
    static std::string contra;
    static std::string nombre;

public:
    bool inicioDeSesion(const std::string& usuario, const std::string& contra);
    void cambioNombre(const std::string& nombre);
    bool cambioPass(const std::string& viejaPass, const std::string& pass);
    std::string nombreCliente();

private:
    bool chequeoLogin(const std::string& usuario, const std::string& contra);
};

#endif
