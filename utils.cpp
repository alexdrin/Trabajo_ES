#include <iostream>
using namespace std;

int multiply(int a, int b) {
    return a * b;
}

// Función duplicada (bad smell)
int multiply_v2(int a, int b) {
    return a * b;
}

// Función que retorna puntero a variable local (error grave)
int* getPointer() {
    int x = 42;
    return &x; // Retorna dirección inválida
}

// Función que genera fuga de memoria
int* allocateArray(int size) {
    int* arr = new int[size];
    for (int i = 0; i < size; i++)
        arr[i] = i;
    return arr; // Sin delete → responsabilidad confusa
}
