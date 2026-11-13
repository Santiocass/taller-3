// Ejercicio 7: Multiplicacion de matrices C = A x B y suma de cada fila de C.
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// d) Recibe una fila (arreglo 1D) y devuelve la suma de sus elementos.
int sumaFila(const vector<int>& fila) {
    int s = 0;
    for (int x : fila) s += x;
    return s;
}

void imprimir(const vector<vector<int>>& M) {
    for (const auto& fila : M) {
        for (int x : fila) cout << setw(6) << x;
        cout << endl;
    }
}

void leer(vector<vector<int>>& M, const string& nombre) {
    for (size_t i = 0; i < M.size(); i++)
        for (size_t j = 0; j < M[i].size(); j++) {
            cout << nombre << "[" << i << "][" << j << "] = ";
            cin >> M[i][j];
        }
}

int main() {
    int m, p, filasB, q;

    // a) Pedir dimensiones hasta que columnas de A == filas de B
    while (true) {
        cout << "Dimensiones de A (filas columnas): ";
        cin >> m >> p;
        cout << "Dimensiones de B (filas columnas): ";
        cin >> filasB >> q;
        if (!cin) return 1;  // fin de la entrada: evita un ciclo infinito
        if (m > 0 && p > 0 && q > 0 && p == filasB) break;
        cout << "Error: las columnas de A deben ser iguales a las filas de B (y positivas). Intente de nuevo.\n" << endl;
    }

    // b) Llenar las matrices
    vector<vector<int>> A(m, vector<int>(p)), B(p, vector<int>(q));
    cout << "\nElementos de A:" << endl;
    leer(A, "A");
    cout << "\nElementos de B:" << endl;
    leer(B, "B");

    // c) C[i][j] = suma sobre k de A[i][k] * B[k][j]
    vector<vector<int>> C(m, vector<int>(q, 0));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < q; j++)
            for (int k = 0; k < p; k++)
                C[i][j] += A[i][k] * B[k][j];

    cout << "\nMatriz A (" << m << "x" << p << "):" << endl;
    imprimir(A);
    cout << "\nMatriz B (" << p << "x" << q << "):" << endl;
    imprimir(B);
    cout << "\nMatriz C = A x B (" << m << "x" << q << "):" << endl;
    imprimir(C);

    // d) Suma de cada fila de C
    cout << "\nSuma de cada fila de C:" << endl;
    for (int i = 0; i < m; i++)
        cout << "Fila " << i << ": " << sumaFila(C[i]) << endl;
    return 0;
}
