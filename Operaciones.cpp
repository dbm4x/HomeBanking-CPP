#include "Operaciones.h"
#include <ctime>

int Operaciones::saldo = 5000; // USD argentinos
vector<Operaciones::movimientos> Operaciones::movimiento;

int Operaciones::SaldoActual() {
    return saldo;
}

bool Operaciones::RetirarSaldo(int cuanto) {
    if (cuanto <= saldo) {
        int viejoSaldo = saldo;
        saldo -= cuanto;
        time_t now = time(0);
        string fecha = ctime(&now);
        movimiento.push_back(movimientos(TipoRetiro, viejoSaldo, saldo, fecha));
        return true;
    }
    return false;
}

bool Operaciones::RealizarDeposito(int cuanto) {
    if (cuanto > 0 && cuanto <= 9999999) {
        int viejoSaldo = saldo;
        saldo += cuanto;
        time_t now = time(0);
        string fecha = ctime(&now);
        movimiento.push_back(movimientos(TipoDeposito, viejoSaldo, saldo, fecha));
        return true;
    }
    return false;
}

void Operaciones::RealizarPrestamo(int cuanto) {
        int viejoSaldo = saldo;
        saldo -= cuanto;
        time_t now = time(0);
        string fecha = ctime(&now);
        movimiento.push_back(movimientos(TipoPrestamo, viejoSaldo, saldo, fecha));
}

vector<Operaciones::movimientos> Operaciones::ListaMovimientos() {
    return movimiento;
}
