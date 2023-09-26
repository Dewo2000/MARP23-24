/*
 * MUY IMPORTANTE: Solo se corregirán los comentarios y el código
 * contenidos entre las etiquetas <answer> y </answer>.
 * Toda modificación fuera de esas etiquetas no será corregida.
 */

/*@ <answer>
 *
 * Indicad el nombre completo y usuario del juez de quienes habéis hecho esta solución:
 * Estudiante 1: Dewei Chen
 * Estudiante 2:
 *
 *@ </answer> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

#include "PriorityQueue.h"

/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema.
 
 @ </answer> */

int64_t resuelveSuma(PriorityQueue<int64_t> cola) {
    int64_t esfuerzo=0;
    while (cola.size() > 1) {
        int64_t a = cola.top(); cola.pop();
        int64_t b = cola.top(); cola.pop();
        int64_t coste = a + b;
        esfuerzo += coste;
        cola.push(a + b);
    }
    return esfuerzo;
}

// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>



bool resuelveCaso() {

    // leer los datos de la entrada
    int64_t N;
    cin >> N;
    if (N==0)
        return false;
    PriorityQueue<int64_t> cola;
    for (int64_t i = 0; i < N; i++) {
        int64_t n;
        cin >> n;
        cola.push(n);
    }
    // resolver el caso posiblemente llamando a otras funciones
    cout << resuelveSuma(cola) << "\n";
    // escribir la solución

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
  
  while (resuelveCaso());

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
#endif
  return 0;
}
