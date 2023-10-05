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
#include "IndexPQ.h"
using namespace std;


/*@ <answer>

 
 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)

 //@ <answer>






bool resuelveCaso() {
   
   // leer los datos de la entrada
   int d,a,b;
   cin >> d;
   if (!std::cin)  // fin de la entrada
      return false;
   cin >> a >> b;
   IndexPQ<int, greater<int>>pila9V(a);
   IndexPQ<int, greater<int>>pila15V(b);
   int horas;
   for (int i = 0; i < a; i++) {
       int h;
       cin >> h;
       pila9V.push(i, h);
   }
   for (int i = 0; i < b; i++) {
       int h;
       cin >> h;
       pila15V.push(i, h);
   }
   for (int i = 0; i < d; i++) {
       if (pila9V.top().prioridad > pila15V.top().prioridad) {

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

    // Resolvemos
    //while (resuelveCaso());
    resuelveCaso();
    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    return 0;
}
