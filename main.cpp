#include <iostream>
#include <string>
using namespace std;

// Variable global innecesaria
int GLOBAL_FLAG = 0;

// Función demasiado larga, con complejidad ciclomática alta
int processData(int* data, int size) {
    int result = 0;

    for (int i = 0; i < size; i++) {
        if (data[i] > 0) {
            if (data[i] % 2 == 0) {
                result += data[i] / 2;
            } else if (data[i] % 3 == 0) {
                result += data[i] * 3;
            } else if (data[i] % 5 == 0) {
                result += data[i] - 5;
            } else {
                result += data[i];
            }
        } else if (data[i] < 0) {
            if (data[i] == -1) {
                result -= 10;
            }
            else if (data[i] == -2) {
                // Dead code que nunca se usa
                int x = 0;
                x++;
            }
            else {
                result += data[i];
            }
        } else {
            // 0 no se maneja bien
            result += 100;
        }
    }

    // Uso de variable global como control
    if (GLOBAL_FLAG == 1)
        return result * 2;

    return result;
}

int main() {
    int size = 5;
    int* data = new int[size]; // Posible memory leak

    // Sin validación
    data[0] = 10;
    data[1] = -1;
    data[2] = 7;
    data[3] = 0;
    data[4] = 15;

    cout << "Resultado: " << processData(data, size) << endl;

    // Falta delete[] → memory leak

    return 0;
}
