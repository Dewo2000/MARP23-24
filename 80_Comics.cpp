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
#include <list>
#include <queue>
#include <climits>
#include <cmath>
using namespace std;


/*@ <answer>

 
 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)

 //@ <answer>



struct Comic
{
    int id, pila;
};


bool operator < (Comic a, Comic b) {
    return b.id < a.id;
}

bool resuelveCaso() {
    int N, k, cont = 0, menorAbsoluto = INT_MAX, id;
    // leer los datos de la entrada
    cin >> N;
    if (!std::cin)  // fin de la entrada
        return false;

    vector<list<Comic>> comics(N);
    priority_queue<Comic> cima;
    for (int i = 0; i < N; i++)
    {
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            cin >> id;
            if (id < menorAbsoluto) menorAbsoluto = id;
            comics[i].push_front({ id, i });
        }
    }

    int menor = INT_MAX;

    //Meto todos los tops
    for (int i = 0; i < N; i++)
        cima.push(comics[i].front());

    while (menor != menorAbsoluto)
    {
        auto aux = cima.top();
        cima.pop();
        menor = aux.id;
        comics[aux.pila].pop_front();
        if (!comics[aux.pila].empty()) cima.push(comics[aux.pila].front());
        cont++;
    }
    cout << cont << "\n";

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
