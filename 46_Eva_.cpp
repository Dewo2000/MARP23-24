
/*@ <authors>
 *
 * Dewei Chen(MARP07)
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "Matriz.h"
using namespace std;


/*@ <answer>

 Resolvemos el problema mediante programación dinámica descendente basándonos en la siguiente recurrencia:
 numCaminos(i,j) = números de caminos desde la posición (i, j) para llegar a la posición (n, m) siendo n números de filas de la matriz y m número de columnas de la matriz.
 Distinguimos de dos casos bases:
    Uno es que se llegue al destino de la posición n,m (tamaño de la matriz)
    numCaminos(n,m)=1
    Otro es que alguna de las posiciones se sobresalga del tamaño de la matriz , por lo tanto no hay camino desde allí.
    numCaminos(i>n,j)=0
    numCaminos(i,j>m)=0
    numCaminos(i>n,j>m)=0
 En los casos recursivos se consulta si el subproblema haya sido resuelto anteriormente(dinámica descendente) con:
    resultado[i][j]!=-1 
 en el caso afirmativo se devolverá el valor de resultado[i][j]
 en el caso contrario se calcula:
    el numCaminos si va a la derecha : numCaminos(i+celdas[i][j],j)
    el numCaminos si va hacia abajo  : numCaminos(i,j+celdas[i][j])
 la suma de ambas se almacena en resultado[i][j] y es devuelto.
 La llamada inicial sería numCaminos(0,0).
 En este caso es numCaminos(celda,0,0,N,M,res) pero celda,N,M son constantes y res es la matriz para guardar la solución por lo tanto para la explicación se simplifica como numCaminos(i,j)
 La complejidad está en el O(n*m) tanto en tiempo como espacio ya que se utiliza una matriz de tamaño n*m en la que se recorre en el peor de los casos todas las posiciones
 y cada celda se calcula con un coste constante.


 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

int numCaminos(Matriz<int> const& celdas, int i, int j, int const n, int const m, Matriz<int>& resultado) {
    //Si llega al destino
    if (i == n - 1 && j == m - 1) {
        return 1;
    }
    //Si se sale fuera de la matriz
    else if (i > n - 1 || j > m - 1) {
        return 0;
    }
    //Si se ha resuelto el subproblema anteriormente
    if (resultado[i][j] != -1)return resultado[i][j];
    //Si esta en camino de buscar solución
    int derecha = numCaminos(celdas, i + celdas[i][j], j, n, m, resultado);
    int abajo = numCaminos(celdas, i, j + celdas[i][j], n, m, resultado);
    resultado[i][j] = derecha + abajo;
    return resultado[i][j];
}

bool resuelveCaso() {

    // leemos la entrada
    int N, M;
    cin >> N >> M;

    if (!cin)
        return false;

    Matriz<int> celda(N, M);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> celda[i][j];
        }
    }
    Matriz<int>res(N, M, -1);
    cout << numCaminos(celda, 0, 0, N, M, res) << "\n";

    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
