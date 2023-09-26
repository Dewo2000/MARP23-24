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
#include <queue>
using namespace std;



/*@ <answer>
 
 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema.
 
 @ </answer> */

struct Tarea {
    int comienzo;
    int fin;
    int periodo;
};
bool operator<(Tarea const& a, Tarea const& b) {
    return a.comienzo > b.comienzo || (a.comienzo == b.comienzo && a.fin < b.fin);
}

bool resuelve(priority_queue<Tarea> cola, int tiempo) {
    int tiempoactual = 0;
    while (!cola.empty()) {
        Tarea a = cola.top(); cola.pop();
        if (a.comienzo >= tiempo) {
            return false;
        }
        if (a.comienzo < tiempoactual) {
            return true;   
        }
        tiempoactual = a.fin;
        if (a.periodo > 0) {
            cola.push({ a.comienzo + a.periodo,a.fin + a.periodo,a.periodo });
        }

    }
    return false;
}
// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>




bool resuelveCaso() {

    // leer los datos de la entrada
    int u,p,t;
    cin >> u;
    if (!std::cin)  // fin de la entrada
        return false;
    cin >> p >> t;
    priority_queue<Tarea> cola;
    for (int i = 0; i < u; i++) {
        int c, f;
        cin >> c >> f;
        cola.push({ c,f,0 });
    }
    for (int i = 0; i < p; i++) {
        int c, f,periodo;
        cin >> c >> f>> periodo;
        cola.push({ c,f,periodo });
    }

    // resolver el caso posiblemente llamando a otras funciones
    if (resuelve(cola, t)) {
        cout << "SI\n";
    }
    else cout << "NO\n";
  
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
