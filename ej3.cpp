// Ejercicio 3: Igual al ejercicio 2, pero ordenando ascendentemente los mayores al promedio.
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

    vector<int> mayores;
    for (int x : v)
        if (x > promedio) mayores.push_back(x);

    // Ordenamiento burbuja ascendente del segundo vector
    int m = mayores.size();
    for (int i = 0; i < m - 1; i++)
        for (int j = 0; j < m - 1 - i; j++)
            if (mayores[j] > mayores[j + 1]) {
                int aux = mayores[j];
                mayores[j] = mayores[j + 1];
                mayores[j + 1] = aux;
            }

    cout << "Promedio: " << promedio << endl;
    cout << "Mayores al promedio (ordenados ascendentemente): ";
    if (mayores.empty()) cout << "(ninguno)";
    for (int x : mayores) cout << x << " ";
    cout << endl;
    return 0;
}
