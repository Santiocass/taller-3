// Ejercicio 1: Matriz n x n aleatoria y operaciones sobre ella.
#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// Devuelve true si x es primo (los menores que 2 no lo son).
bool esPrimo(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

// Imprime un vector en una sola linea.
void imprimirVector(const vector<double>& v) {
    for (double x : v) cout << fixed << setprecision(2) << x << " ";
    cout << endl;
}

int main() {
    srand(time(0));
    int n;
    cout << "Ingrese n: ";
    cin >> n;
    if (n <= 0) { cout << "n debe ser positivo." << endl; return 1; }

    // Generar la matriz con valores aleatorios en [0,50]
    vector<vector<int>> M(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = rand() % 51;

    // a) Imprimir la matriz
    cout << "\na) Matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << setw(4) << M[i][j];
        cout << endl;
    }

    // b) Diagonales principal (i==j) y secundaria (j==n-1-i)
    vector<int> dp(n), ds(n);
    int sumaP = 0, sumaS = 0;
    for (int i = 0; i < n; i++) {
        dp[i] = M[i][i];
        ds[i] = M[i][n - 1 - i];
        sumaP += dp[i];
        sumaS += ds[i];
    }
    cout << "\nb) Diagonal principal: ";
    for (int x : dp) cout << x << " ";
    cout << "| suma = " << sumaP << endl;
    cout << "   Diagonal secundaria: ";
    for (int x : ds) cout << x << " ";
    cout << "| suma = " << sumaS << endl;

    // c) Primera fila y ultima columna; elevar al cuadrado y sumar posicion a posicion
    vector<int> fila(n), col(n), resultado(n);
    for (int i = 0; i < n; i++) {
        fila[i] = M[0][i];
        col[i] = M[i][n - 1];
    }
    for (int i = 0; i < n; i++) {
        fila[i] *= fila[i];
        col[i] *= col[i];
        resultado[i] = fila[i] + col[i];
    }
    cout << "\nc) Suma de cuadrados (primera fila + ultima columna): ";
    for (int x : resultado) cout << x << " ";
    cout << endl;

    // d) Contar primos
    int primos = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (esPrimo(M[i][j])) primos++;
    cout << "\nd) Cantidad de elementos primos: " << primos << endl;

    // e) Pares, impares y multiplos de 3
    int pares = 0, impares = 0, mult3 = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (M[i][j] % 2 == 0) pares++; else impares++;
            if (M[i][j] % 3 == 0) mult3++;
        }
    cout << "\ne) Pares: " << pares << ", Impares: " << impares
         << ", Divisibles por 3: " << mult3 << endl;

    // f) Suma por columnas; tabla X (suma) vs Y (seno del valor convertido a radianes)
    vector<int> sumaCol(n, 0);
    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            sumaCol[j] += M[i][j];
    cout << "\nf) Tabla de sumas por columna:" << endl;
    cout << setw(8) << "X" << setw(12) << "Y=sin(rad)" << endl;
    for (int j = 0; j < n; j++) {
        double rad = sumaCol[j] * M_PI / 180.0;  // grados -> radianes
        cout << setw(8) << sumaCol[j] << setw(12) << fixed << setprecision(4) << sin(rad) << endl;
    }

    // g) Aplanar a vector 1D, calcular promedio y dividir cada elemento por el promedio
    vector<double> plano;
    double total = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            plano.push_back(M[i][j]);
            total += M[i][j];
        }
    double promedio = total / (n * n);
    cout << "\ng) Promedio = " << fixed << setprecision(2) << promedio << endl;
    if (promedio == 0) {
        cout << "   El promedio es 0, no se puede dividir." << endl;
    } else {
        for (double& x : plano) x /= promedio;
        cout << "   Vector dividido por el promedio: ";
        imprimirVector(plano);
    }
    return 0;
}
