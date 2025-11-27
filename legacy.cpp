#include <iostream>
using namespace std;

void legacyFunction(int x){
    int i,j,k,l; // Variables sin usar ni nombre significativo

    if (x > 10)
        if (x > 20)
            cout << "Muy grande" << endl;
        else
            cout << "Grande" << endl;
    else
        cout << "Pequeño" << endl;

    // Condición redundante
    if (x == x)
        cout << "Siempre verdad" << endl;
}
