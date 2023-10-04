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





bool resuelveCaso() {

    // leer los datos de la entrada
    int n,p;
    cin >> n;
    if (n==0) //caso especial
        return false;
    cin >> p;
    priority_queue<int> menor;
    priority_queue<int , vector<int>, greater<int>> mayor;
    vector<int> resultado;
    menor.push(n);
    for (int i = 0; i < p; i++) {
        int e , e2;
        cin >> e >> e2;
        if (e < menor.top()) {
            menor.push(e);
        }
        else {
            mayor.push(e);
        }
        if (e2 < menor.top()) {
            menor.push(e2);
        }
        else {
            mayor.push(e2);
        }
        if (menor.size() < mayor.size()) {
            menor.push(mayor.top());
            mayor.pop();
        }
        else if (menor.size() > mayor.size() + 1) {
            mayor.push(menor.top());
            menor.pop();
        }
        resultado.push_back(menor.top());
    }
    // resolver el caso posiblemente llamando a otras funciones
    for (int i : resultado) {
        cout << i << " ";
    }
    cout << "\n";
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

    // Resolvemos
    while (resuelveCaso());

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
