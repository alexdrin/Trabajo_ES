#include <iostream>
#include <vector>
#include <cstring>

/**
 * Seminario 1: Laboratorio de Análisis Estático
 * Archivo: buggy_benchmark.cpp
 * Objetivo: Banco de pruebas con 10 defectos semánticos para evaluar herramientas de V&V.
 */

// 1. Conversión de tipo peligrosa (Narrowing conversion)
// Defecto: El retorno de double a int causará pérdida de precisión.
int calculateArea(double radius) {
    return 3.14159 * radius * radius; 
}

void processData() {
    // 2. Uso de variables no inicializadas
    int factor;
    int total = 100 * factor; 
    std::cout << "Total inicial: " << total << std::endl;

    // 3. Fuga de memoria (Memory Leak)
    // Defecto: Se reserva memoria en el heap y nunca se libera.
    int* dataBuffer = new int[50];
    dataBuffer[0] = 10;
    
    // 4. Código inalcanzable (Unreachable code)
    return; 
    std::cout << "Este mensaje nunca se imprimira." << std::endl; 
}

void securityFlaws() {
    // 5. Desbordamiento de buffer (Buffer Overflow)
    char source[] = "Este es un texto demasiado largo para el destino";
    char destination[10];
    // Defecto: strcpy no comprueba límites.
    strcpy(destination, source); 

    // 6. Desbordamiento de array (Off-by-one error)
    int scores[5] = {10, 20, 30, 40, 50};
    // Defecto: El índice 5 está fuera de rango (0 a 4).
    for (int i = 0; i <= 5; i++) {
        std::cout << scores[i] << " ";
    }
}

// 7. El Señuelo (False Positive Bait)
// Este código es complejo pero CORRECTO. 
// Las herramientas podrían marcarlo como posible división por cero, 
// pero el 'if' garantiza que nunca ocurra.
void falsePositiveBait(int val) {
    int x = 0;
    if (val > 100) {
        x = val - 100;
        if (x > 0) {
            int result = 500 / x; 
            std::cout << "Resultado: " << result << std::endl;
        }
    }
}

// 8. Comparación de flotantes (Precision Fault)
// Defecto: Comparar floats con == es peligroso debido a la precisión.
void compareFloats() {
    float f1 = 0.1f + 0.2f;
    if (f1 == 0.3f) {
        std::cout << "Son iguales" << std::endl;
    }
}

// 9. Retorno de referencia local (Dangling Reference)
// Defecto: Se devuelve una referencia a una variable que muere al salir de la función.
int& getLocalReference() {
    int tempValue = 42;
    return tempValue; 
}

// 10. Memory leak por reasignación
void reassignLeak() {
    char* msg = new char[20];
    // Defecto: Se pierde el puntero original antes de liberar la memoria.
    msg = (char*)"Nuevo Mensaje"; 
}

int main() {
    std::cout << "Iniciando Buggy Benchmark..." << std::endl;
    
    processData();
    securityFlaws();
    falsePositiveBait(150);
    compareFloats();
    
    // El código compila, pero su ejecución es errática o fallida.
    return 0;
}
