// Ejercicio 8: Gestor de notas (estudiantes x materias).
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n, m;
    do {
        cout << "Numero de estudiantes y de materias: ";
        cin >> n >> m;
    } while (n <= 0 || m <= 0);

    // a) Matriz de notas: filas = estudiantes, columnas = materias
    vector<vector<double>> notas(n, vector<double>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            do {
                cout << "Nota del estudiante " << i << " en la materia " << j << " (0.0 - 5.0): ";
                cin >> notas[i][j];
                if (notas[i][j] < 0.0 || notas[i][j] > 5.0)
                    cout << "Nota invalida, debe estar entre 0.0 y 5.0." << endl;
            } while (notas[i][j] < 0.0 || notas[i][j] > 5.0);
        }

    cout << fixed << setprecision(2);

    // Mostrar la matriz
    cout << "\nNotas:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Estudiante " << i << ":";
        for (int j = 0; j < m; j++) cout << setw(7) << notas[i][j];
        cout << endl;
    }

    // b) Promedio de cada estudiante (por fila)
    vector<double> promEst(n, 0.0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) promEst[i] += notas[i][j];
        promEst[i] /= m;
    }

    // c) Promedio de cada materia (por columna)
    vector<double> promMat(m, 0.0);
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) promMat[j] += notas[i][j];
        promMat[j] /= n;
    }

    cout << "\nPromedio por estudiante:" << endl;
    for (int i = 0; i < n; i++) cout << "  Estudiante " << i << ": " << promEst[i] << endl;
    cout << "\nPromedio por materia:" << endl;
    for (int j = 0; j < m; j++) cout << "  Materia " << j << ": " << promMat[j] << endl;

    // d) Estudiante con mayor promedio y materia con menor promedio
    int mejor = 0, peor = 0;
    for (int i = 1; i < n; i++)
        if (promEst[i] > promEst[mejor]) mejor = i;
    for (int j = 1; j < m; j++)
        if (promMat[j] < promMat[peor]) peor = j;

    cout << "\nEstudiante con mayor promedio: indice " << mejor << " (" << promEst[mejor] << ")" << endl;
    cout << "Materia con menor promedio: indice " << peor << " (" << promMat[peor] << ")" << endl;
    return 0;
}
