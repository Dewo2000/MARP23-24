
/*@ <authors>
 *
 * Dewei Chen (MARP07)
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include "Matriz.h"
#include <deque>
using namespace std;


/*@ <answer>

 Resolvemos el problema mediante programación dinámica ascendente basándonos en la siguiente recurrencia:
 listaComun(i,j) = número máximos de canciones en común utilizando i elementos de la lista1 (mañana) y j elementos de la lista2(tarde)
 Casos recursivos:
 Si la canción de ambas listas coinciden ,se añade
 listaComun(i,j) = listaComun(i - 1)(j - 1) + 1 si lista1(i-1)==lista2(j-1)
 En caso contrario se busca el máximo quitando una cancion en la lista1 o lista2.
 listaComun(i,j) = max(listaComun(i - 1,j),listaComun(i,j-1)) en otro caso.

 La matriz se inicializa a -1 y se va rellenando de arriba a abajo , de izquierda a derecha.
 La complejidad en tiempo está en O(m*t) siendo m el tamaño de la lista1 y t el tamaño de la lista2 ya que recorre la matriz entera para rellenar 
 cada subproblema y cada uno con un coste constante.
 La complejidad en espacio también está en O(m*t) y no es posible reducir debido a la necesidad de reconstruir la solución.
 La complejidad del reconstruir está en el O(max(m,t)).
 

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

vector<string> leerLista() {
    string linea;
    getline(cin, linea);
    if (!cin)
        return {};
    vector<string> sec;
    stringstream ss(linea);
    string pal;
    while (ss >> pal)
        sec.push_back(pal);
    return sec;
}

void reconstruir(vector<string> const& lista1, vector<string> const& lista2, Matriz<int> const& listaComun, int i, int j, deque<string> &sol) {
    if (i > 0 && j > 0) {
        if (lista1[i - 1] == lista2[j - 1]) {
            sol.push_front(lista1[i - 1]);
            reconstruir(lista1, lista2, listaComun, i - 1, j - 1, sol);
        }
        else if (listaComun[i - 1][j] > listaComun[i][j - 1]) {
            reconstruir(lista1, lista2, listaComun, i - 1, j, sol);
        }
        else
            reconstruir(lista1, lista2, listaComun, i, j-1, sol);
    }
}

bool resuelveCaso() {

    // leemos la entrada
    auto lista1 = leerLista();
    if (!cin)
        return false;
    auto lista2 = leerLista();
    int m = lista1.size();
    int t = lista2.size();
    // resolver el caso
    Matriz<int>listaComun(m + 1, t + 1, -1);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= t; j++) {
            if (lista1[i - 1] == lista2[j - 1]) {
                listaComun[i][j] = listaComun[i - 1][j - 1] + 1;
            }
            else {
                listaComun[i][j] = max(listaComun[i - 1][j], listaComun[i][j - 1]);
            }
        }
    }
    deque<string>sol;
    reconstruir(lista1, lista2, listaComun, m, t, sol);
    for (int i = 0; i < sol.size(); i++) {
        cout << sol[i] << " ";
    }
    cout << "\n";


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
