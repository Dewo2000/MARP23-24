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


class ArbolLibre {
public:
    ArbolLibre(Grafo const& g, int s) : visit(g.V(), false), ciclico(false),nVisit(0) ,ant(g.V(),-1) {
        dfs(g, 0);
    };
    bool esCiclico(Grafo const& g) { return !ciclico && esConexo(g); }
private:
    std::vector<bool> visit;
    std::vector<int> ant;
    bool ciclico;
    int nVisit;
    void dfs(Grafo const& G, int v) {
        visit[v] = true;
        nVisit++;
        for (int w : G.ady(v)) {
            if (ciclico)return;

            if (ant[v] == w) continue;

            if (!visit[w]) {
                ant[w] = v;
                dfs(G, w);
            }
            else {
                ciclico = true;
            }
           
        }
    };
    bool esConexo(Grafo const& g) const {
        return nVisit == g.V();
    };
};



bool resuelveCaso() {
    int V, A;
    cin >> V;
    if (!std::cin)  // fin de la entrada
        return false;
    Grafo grafo(V);
    cin >> A;
    for (int i = 0; i < A; i++) {
        int a, b;
        cin >> a >> b;
        grafo.ponArista(a, b);
    }
    // resolver el caso posiblemente llamando a otras funciones
    ArbolLibre a(grafo, 0);
    // escribir la soluci�n
    a.esCiclico(grafo) ? cout << "SI" : cout << "NO";
    cout << "\n";
    return true;
    // resolver el caso posiblemente llamando a otras funciones
    // escribir la solución
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
    while (resuelveCaso());
    //resuelveCaso();
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
