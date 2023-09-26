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
struct user {
    int id;
    int periodo;
    int momento;
};
bool operator<(user const& a, user const& b) {
    return b.momento < a.momento ||
        (a.momento == b.momento && b.id < a.id);
}
bool operator>(user const& a, user const& b) {
    return b < a;
}
vector<int> resuelve(PriorityQueue<user, greater<user>>  cola, int envios) {
    vector<int> salida;
    for (int i = 0; i < envios; i++) {
        user k = cola.top(); cola.pop();
        salida.push_back(k.id);
        k.momento += k.periodo;
        cola.push(k);
    }
    return salida;
}

// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>



bool resuelveCaso() {

    // leer los datos de la entrada
    int N;
    cin >> N;
    if (N==0)
        return false;
    PriorityQueue<user,greater<user>> cola;
    for (int i = 0; i < N; i++) {
        int uid, uperiod;
        cin >> uid >> uperiod;
        cola.push({uid,uperiod,uperiod });
    }
    int envios;
    cin >> envios;
    vector<int> ids = resuelve(cola, envios);
    for (int id : ids) {
        cout << id << "\n";
    }
    cout << "---\n";

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
