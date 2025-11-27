#include <iostream>
using namespace std;

class Calculator {
public:
    int lastResult; // estado mutable inesperado

    Calculator() {
        lastResult = 0;
    }

    // Función que hace demasiado y no valida nada
    int compute(int a, int b, char op) {
        if (op == '+') lastResult = a + b;
        else if (op == '-') lastResult = a - b;
        else if (op == '*') lastResult = a * b;
        else if (op == '/') lastResult = a / b; // División entre cero no controlada
        else lastResult = 9999; // Valor mágico

        // Dead code
        if (false)
            cout << "Esto nunca se ejecuta" << endl;

        return lastResult;
    }
};

// Uso innecesario
void doStuff() {
    Calculator c;
    c.compute(10, 0, '/'); // Error en tiempo de ejecución
}
