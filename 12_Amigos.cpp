/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

 /*@ <answer>
  *
  * MARP07 Dewei Chen
  *
  *
  *@ </answer> */

#include <iostream>
#include <fstream>
#include <vector>
#include "Grafo.h"

using namespace std;


/*@ <answer>


 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)

 //@ <answer>


class AmigoDeAmigo {
    vector<bool>visit;
    int maxGrupo;
    int dfs(Grafo const& g, int v) {
        visit[v] = true;
        int tam = 1;
        for (int w : g.ady(v)) {
            if (!visit[w]) {
                tam+=dfs(g, w);
            }
        }
        return tam; 
    }
public:
    AmigoDeAmigo(Grafo const& g) :maxGrupo(0), visit(g.V(), false) {
        for (int i = 0; i < g.V(); i++) {
            if(!visit[i]){
                int tam = dfs(g, i);
                maxGrupo = max(maxGrupo, tam);
            }
            
        }
    }
    int getMax() { return maxGrupo; }
};



void resuelveCaso() {
    cout << AmigoDeAmigo(Grafo(cin, 1)).getMax() << "\n";
}

//@ </answer>
//  Lo que se escriba dejado de esta línea ya no forma parte de la solución.

int main() {
    // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
    std::ifstream in("casos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

    // Resolvemos
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();
    //resuelveCaso();
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
