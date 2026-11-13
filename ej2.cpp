// Ejercicio 2: Elementos de un vector aleatorio mayores que el promedio.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    int n;
    do {
        cout << "Ingrese n (entero positivo): ";
        cin >> n;
    } while (n <= 0);

    // Llenar el vector con valores aleatorios en [0,10] y acumular la suma
    vector<int> v(n);
    double suma = 0;
    cout << "Vector: ";
    for (int i = 0; i < n; i++) {
        v[i] = rand() % 11;
        suma += v[i];
        cout << v[i] << " ";
    }
    cout << endl;

    double promedio = suma / n;

    // Segundo vector: solo los elementos mayores que el promedio
    vector<int> mayores;
    for (int x : v)
        if (x > promedio) mayores.push_back(x);

    cout << "Promedio: " << promedio << endl;
    cout << "Elementos mayores que el promedio: ";
    if (mayores.empty()) cout << "(ninguno)";
    for (int x : mayores) cout << x << " ";
    cout << endl;
    return 0;
}
