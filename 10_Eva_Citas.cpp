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
#include <unordered_map>
#include "IndexPQ.h"
using namespace std;

/*@ <answer>

 La solución se ha planteado usando una cola de prioridad variable y de forma auxiliar dos unordered_map que guarda la relación entre el índice del IndexPQ con el Tema.
 Para ello se crea el Struct Tema , para ordenarlos de mayor cita a menor , en caso de empate , el más reciente.
 El coste en el evento C : O(1) + O(Log N) = O(Log N)
    Coste medio en las operaciones de unordered_map -> O(1)
    Coste del update de IndexPQ -> O(Log N) siendo N = numEventos
 El coste en el evento E : O(1) + O(Log N) = O(Log N)
    Coste medio en las operaciones de unordered_map -> O(1)
    Coste del update de IndexPQ -> O(Log N) siendo N = numEventos
 El coste en el evento TC : O(1) + O(Log N) + O(Log N) = O(Log N)
    Coste medio en las operaciones de unordered_map -> O(1)
    Coste medio en las operaciones de vector -> O(1)
    Coste del update de IndexPQ -> O(Log N) siendo N = numEventos
    Coste del pop de IndexPQ -> O(Log N) siendo N = numEventos
    Coste del top de IndexPQ -> O(1)
En conclusión todos los eventos tienen un coste de O(Log N) por lo tanto el algoritmo se hace numEventos veces.
El coste total de resuelveCaso es de O(N log N) siendo N = numEventos

 @ </answer> */


 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>
struct Tema
{
    int citas;
    int reciente;
};
bool operator<(Tema const& a, Tema const& b) {

    return a.citas > b.citas || (a.citas == b.citas && a.reciente > b.reciente);
}


bool resuelveCaso() {

    int numEventos;
    cin >> numEventos;

    if (!cin)
        return false;
    unordered_map<string, pair<int,int>> indiceTema;
    unordered_map<int, string> temaIndice;
    IndexPQ<Tema> cola (numEventos);
    int indices=0;
    for (int i = 0; i < numEventos; i++) {
        string evento , tema;
        cin >> evento;
        if (evento == "C") {
            int citas;
            cin >> tema >> citas;
            if (indiceTema.find(tema) == indiceTema.end()) {
                indiceTema[tema] = { indices,citas };
                cola.update(indices, { citas,i });
                temaIndice[indices] = tema;
                indices++;
            }
            else {
                cola.update(indiceTema[tema].first, { indiceTema[tema].second + citas,i });
                indiceTema[tema] = { indiceTema[tema].first,indiceTema[tema].second + citas };
            }
        }
        else if (evento == "E") {
            int citas;
            cin >> tema >> citas;
            cola.update(indiceTema[tema].first, { indiceTema[tema].second - citas,i });
            indiceTema[tema] = { indiceTema[tema].first,indiceTema[tema].second - citas };

        }
        else if (evento == "TC"){
            vector<string> res;
            vector < pair<int, Tema>> usados;
            int tcola = cola.size();
            for (int i = 0; i < tcola && i<3; i++) {
                res.push_back(temaIndice[cola.top().elem]);
                usados.push_back({ cola.top().elem,cola.top().prioridad });
                cola.pop();
            }
            for (int i = 0; i < usados.size(); i++) {
                cola.update(usados[i].first, { usados[i].second.citas , usados[i].second.reciente });
            }
            for (int i = 0; i < res.size(); i++) {
                cout << i + 1 << " " << res[i] << "\n";
            }
        }
    }

    // leer el resto del caso y resolverlo



    cout << "---\n";
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
