// Ejercicio 6: Maximo/minimo, intercambio de filas y transpuesta de una matriz m x n.
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

// Imprime una matriz con columnas alineadas.
void imprimir(const vector<vector<int>>& M) {
    for (const auto& fila : M) {
        for (int x : fila) cout << setw(6) << x;
        cout << endl;
    }
}

int main() {
    int m, n;
    do {
        cout << "Ingrese filas (m) y columnas (n): ";
        cin >> m >> n;
    } while (m <= 0 || n <= 0);

    vector<vector<int>> A(m, vector<int>(n));
    cout << "Ingrese los elementos:" << endl;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }

    cout << "\nMatriz original:" << endl;
    imprimir(A);

    // a) Maximo y minimo con su posicion (se queda con la primera aparicion)
    int maxF = 0, maxC = 0, minF = 0, minC = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++) {
            if (A[i][j] > A[maxF][maxC]) { maxF = i; maxC = j; }
            if (A[i][j] < A[minF][minC]) { minF = i; minC = j; }
        }
    cout << "\na) Maximo: " << A[maxF][maxC] << " en fila " << maxF << ", columna " << maxC << endl;
    cout << "   Minimo: " << A[minF][minC] << " en fila " << minF << ", columna " << minC << endl;

    // b) Intercambiar la fila del maximo con la del minimo
    //    (se numeran desde 0; si son la misma fila no cambia nada)
    swap(A[maxF], A[minF]);
    cout << "\nb) Matriz con filas " << maxF << " y " << minF << " intercambiadas:" << endl;
    imprimir(A);

    // c) Transpuesta: T[j][i] = A[i][j]  (resulta de n x m)
    vector<vector<int>> T(n, vector<int>(m));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            T[j][i] = A[i][j];
    cout << "\nc) Transpuesta de la matriz intercambiada (" << n << "x" << m << "):" << endl;
    imprimir(T);
    return 0;
}
