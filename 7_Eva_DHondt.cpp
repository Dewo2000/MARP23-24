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
#include <limits>
#include <queue>
using namespace std;


/*@ <answer>

 Escribe aquí un comentario general sobre la solución, explicando cómo
 se resuelve el problema y cuál es el coste de la solución, en función
 del tamaño del problema.

 El problema se resuelve utilizando una cola de prioridad en la cual se va ordenando las candidaturas según su coeficiente , votos y su índice , como se muestra en el 
 operator<. La idea es que se vaya guardando las escañas en un vector de enteros en el índice que le corresponde a cada candidatura y se actualiza los datos para que
 vuelva a la cola.
 En cuanto al coste de la solución del método resuelve , se hace 'e' (número de escañas a repartir) veces las operaciones top , pop y push por lo que es:
 e1 + e log N + e log N , tiene un coste total de (e log N) siendo 'e' (número de escañas a repartir) y 'N' (número de canditaturas que está en la cola de prioridad).
 
 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
struct Canditaturas
{
    double coe;
    int votos;
    int esc;
    int indice;
};
bool operator<(Canditaturas const& a, Canditaturas const& b) {

    return a.coe < b.coe || (a.coe == b.coe && a.votos < b.votos) || (a.coe == b.coe && a.votos == b.votos && a.indice > b.indice);
}
vector<int> resuelve(priority_queue<Canditaturas> cola, int e) {
    vector<int> resultado(cola.size());
    for (int i = 0; i < e; i++) {
        Canditaturas top = cola.top(); cola.pop();
        top.esc += 1;
        resultado[top.indice] = top.esc;
        top.coe = top.votos / (1.00 + top.esc);
        cola.push(top);
    }
    return resultado;
}
 //@ <answer>



bool resuelveCaso() {

    // leemos la entrada
    int C, N;
    cin >> C >> N;

    if (C == 0)
        return false;
    priority_queue<Canditaturas> cola;
    for (int i = 0; i < C; i++) {
        int votos;
        cin >> votos;
        double coe = votos / (1 + 0);
        cola.push({ coe,votos,0,i });
    }
    // leer el resto del caso y resolverlo
    vector<int>res = resuelve(cola, N);
    for (int i : res) {
        cout << i << " ";
    }
    cout << "\n";

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
    system("PAUSE");
#endif
    return 0;
}
