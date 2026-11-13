// Ejercicio 5: Clasificar una matriz cuadrada (triangular superior, inferior o diagonal).
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    do {
        cout << "Ingrese n (orden de la matriz): ";
        cin >> n;
    } while (n <= 0);

    vector<vector<int>> A(n, vector<int>(n));
    cout << "Ingrese los elementos de la matriz (fila por fila):" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> A[i][j];
        }

    cout << "\nMatriz ingresada:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << A[i][j] << "\t";
        cout << endl;
    }

    // Superior: todo elemento bajo la diagonal (i > j) es 0.
    // Inferior: todo elemento sobre la diagonal (i < j) es 0.
    bool superior = true, inferior = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            if (i > j && A[i][j] != 0) superior = false;
            if (i < j && A[i][j] != 0) inferior = false;
        }
    // Diagonal = triangular superior e inferior a la vez.
    bool diagonal = superior && inferior;

    cout << endl;
    if (diagonal)
        cout << "La matriz es DIAGONAL (por tanto es triangular superior y triangular inferior a la vez)." << endl;
    else if (superior)
        cout << "La matriz es TRIANGULAR SUPERIOR." << endl;
    else if (inferior)
        cout << "La matriz es TRIANGULAR INFERIOR." << endl;
    else
        cout << "La matriz no es triangular ni diagonal." << endl;
    return 0;
}
