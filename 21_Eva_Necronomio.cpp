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
#include <algorithm>
#include "Digrafo.h"
using namespace std;


/*@ <answer>

 El ejercicio se resuelve utilizando grafos dirigidos en la cual los vértices son las lineas del programa y las aristas unen la siguiente instrucción a ejecutar el programa.
 Se inicializa los vértices del digrafo a tamaño L (número de instrucciones) + 1 para saber si se ha llegado a detrás de la última instrucción.
 Si la instrucción es 'A': se une el vértice actual con la siguiente.
 Si la instrucción es 'J': se une el vértice actual con el salto de línea - 1 (El digrafo empieza con vértice 0).
 Si la instrucción es 'C': se une el vértice actual con la siguiente y se une el vértice actual con el salto de línea - 1 (El digrafo empieza con vértice 0).
 Utilizando una búsqueda en profundidad dfs , vamos obteniendo si cada instrucción es visitada o no , lo que nos importa realmente es si el vértice que está detras de la última instrucción ha
 sido visitada o no , que es el vértice L , si no ha sido visitido es que el programa NUNCA acaba , si ha sido visitado , tenemos dos opciones:
    - Si no tuvo ningún ciclo , es que no se ha llegado al final pasando por una instrucción 'C' , por lo tanto acaba SIEMPRE.
    - Si tuvo un ciclo , significa que ha acabado pasando por una instrucción 'C' , y como no se sabe lo que hace el 'C' por antelación, por lo tanto A VECES acaba.


 El coste de la construcción del digrafo es de O(L) siendo L los números de instrucciones.
 El algoritmo dfs tiene un coste de O(V+A) número de vértices V=L+1 y números de aristas A = L la cual se recorre todos los vértices y todas las aristas pero solo una vez cada arista.
 
 El coste total de la resolución del problema es del O(L+1 + L) siendo L+1 números de vértices del grafo dirigido y L números de aristas . L=números de instrucciones.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>

class Necronomicon {
private:
    vector<bool>visitado;
    vector<bool>apilado;
    bool ciclo=false;
    void dfs(Digrafo const& g, int v) {
        apilado[v] = true;
        visitado[v] = true;
        for (int w : g.ady(v)) {
            if (!visitado[w]) dfs(g, w);
            else if (apilado[w])ciclo = true;

        }
        apilado[v] = false;
    }
public:
    Necronomicon(Digrafo const& g) : visitado(g.V()), apilado(g.V()) {
        dfs(g, 0);
    }
    bool visit(int v) {
        return visitado[v];
    }
    bool ciclos() {
        return ciclo;
    }
};



bool resuelveCaso() {

    int L;
    cin >> L;
    if (!cin)
        return false;
    Digrafo dg(L+1);
    for (int i = 0; i < L; i++) {
        char e;
        int l;
        cin >> e;
        if (e == 'A') {
            dg.ponArista(i, i + 1);
        }
        else if (e == 'J') {
            cin >> l;
            dg.ponArista(i, l-1);
        }
        else if (e == 'C') {
            cin >> l;
            dg.ponArista(i, i + 1);
            dg.ponArista(i, l-1);
        }
    }
    Necronomicon micon(dg);
    if (!micon.visit(L)) {
        cout << "NUNCA\n";
    }
    else if (micon.ciclos() && micon.visit(L)) {
        cout << "A VECES\n";
    }
    else {
        cout << "SIEMPRE\n";
    }
    return true;
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

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
#endif
    return 0;
}
