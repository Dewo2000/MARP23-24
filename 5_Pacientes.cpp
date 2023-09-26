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

struct Paciente {
    string nombre;
    int gravedad;
    int llegada;
};
bool operator<(Paciente const& a, Paciente const& b) {
    return a.gravedad < b.gravedad || (a.gravedad == b.gravedad && a.llegada > b.llegada);
}

// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>




bool resuelveCaso() {

    // leer los datos de la entrada
    int n = 0;
    cin >> n;
    if (n == 0) //caso especial
        return false;
    priority_queue<Paciente> cola;
    for (int i = 0; i < n; i++) {
        char accion;
        cin >> accion;

        if (accion == 'I') {
            string nombre = "";
            int gravedad = 0;
            cin >> nombre >> gravedad;
            cola.push({ nombre,gravedad,i });

        }
        else if (accion == 'A') {
            cout << cola.top().nombre << "\n";
            cola.pop();
        }
    }
    cout << "---\n";
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
