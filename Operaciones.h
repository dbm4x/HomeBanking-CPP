#ifndef OPERACIONES_H
#define OPERACIONES_H

#include <string>
#include <vector>

using namespace std;

class Operaciones {
public:
    enum tiposdemovimiento {
        TipoRetiro,
        TipoDeposito,
        TipoPrestamo
    };

    struct movimientos {
        tiposdemovimiento tipo;
        int saldoAnterior;
        int saldoActual;
        string fecha;

        movimientos(tiposdemovimiento tipo, int saldoAnterior, int saldoActual, string fecha)
            : tipo(tipo), saldoAnterior(saldoAnterior), saldoActual(saldoActual), fecha(fecha) {}
    };

    static int saldo;
    static vector<movimientos> movimiento;

    static int SaldoActual();
    static bool RetirarSaldo(int cuanto);
    static bool RealizarDeposito(int cuanto);
    static void RealizarPrestamo(int cuanto);
    static vector<movimientos> ListaMovimientos();
};

#endif
