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

#include "bintree.h"

/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema.
 
 @ </answer> */

template <typename T>
struct sol {
    bool avl;
    int alt;
    T min, max;
};

template <typename T>
sol<T> es_avl_rec(BinTree<T> const& arbol) {
    if (arbol.empty())
        return { true,0,T(),T() };
    else {
        auto [avl_iz, alt_iz, min_iz, max_iz] = es_avl_rec(arbol.left());
        auto [avl_dr, alt_dr, min_dr, max_dr] = es_avl_rec(arbol.right());

        int alt = std::max(alt_iz, alt_dr) + 1;
        T max = arbol.right().empty() ? arbol.root() : max_dr;
        T min = arbol.left().empty() ? arbol.root() : min_iz;

        bool avl = avl_iz && avl_dr && abs(alt_iz - alt_dr) <= 1 &&
            (arbol.left().empty() || arbol.root() > max_iz) &&
            (arbol.right().empty() || arbol.root() < min_dr);

        return { avl,alt,min,max };
    }
}

template <typename T>
bool es_avl(BinTree<T> const& arbol) {
    return es_avl_rec(arbol).avl;
}

// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>




bool resuelveCaso() {

    // leer los datos de la entrada
    char type;
    cin >> type;
    if (!std::cin)  // fin de la entrada
        return false;
    if (type == 'N') {
        BinTree<int> arbol = read_tree<int>(cin);
        if (es_avl(arbol)) {
            cout << "SI\n";
        }
        else {
            cout << "NO\n";
        }

    }
    else if(type == 'P')
    {
        BinTree<string> arbol = read_tree<string>(cin);
        if (es_avl(arbol)) {
            cout << "SI\n";
        }
        else {
            cout << "NO\n";
        }

    }
    // resolver el caso posiblemente llamando a otras funciones

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
