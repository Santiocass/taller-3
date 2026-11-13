// Ejercicio 4: Factorial de cada elemento de un vector aleatorio.
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Calcula el factorial de x de forma iterativa (0! = 1). Con x <= 10 cabe en un int.
int factorial(int x) {
    int f = 1;
    for (int i = 2; i <= x; i++) f *= i;
    return f;
}

int main() {
    srand(time(0));
    int n;
    do {
        cout << "Ingrese n (entero positivo): ";
        cin >> n;
    } while (n <= 0);

    vector<int> v(n);
    for (int i = 0; i < n; i++) v[i] = rand() % 11;  // valores en [0,10]

    for (int i = 0; i < n; i++)
        cout << "v[" << i << "] = " << v[i] << "  ->  " << v[i] << "! = " << factorial(v[i]) << endl;
    return 0;
}
