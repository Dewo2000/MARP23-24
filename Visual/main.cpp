
/*@ <authors>
 *
 * Dewei Chen (MARP07)
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "ConjuntosDisjuntos.h"
#include "GrafoValorado.h"
#include "PriorityQueue.h"
using namespace std;


/*@ <answer>

 La resolución del problema se plantea de la siguiente forma. Las condiciones son que necesitamos que el coche pueda circular libremente por la red,
 esto significa que desde cualquier vértice tenga un camino que le haga llega a otra cualquiera, con la autonomía mínima significa que el coste o valor
 de las aristas que va a recorrer sean lo menor posible.Estas condiciones coinciden con la definición de ARM , árboles de recubrimiento mínimo la cual es un
 árbol que une todos los vértices medientate aristas de menor valor posible por lo tanto vamos a utilizar un tipo algoritmo de ARM ,Kruskal.

 Se ordenan las aristas en una cola de prioridad de menor a mayor, se crea el conjunto disjunto.
 Se saca el primer elemento de la cola y se obtiene sus dos vértices , si estaban unidos ya , significa que al unirlos crearía un ciclo y no es lo que 
 queremos en un ARM , por lo tanto se salta a la siguiente iteración , si no estaban unidos , significa que es una arista con menor coste que une el nuevo
 vértice , se unen y se comprueba números de aristas.El valor mínimo de la autonomía en este caso es el valor del último arista que se añade al ARM, como
 no sabemos exactamente en que iteración la vamos sobreescribiendo en cada una de las iteraciones hasta llegar al final.


 El coste de la construcción de la cola de prioridad es de O(A) siendo A las carreteras de la red.
 El coste de la construcción del conjunto disjunto es de O(V) siendo V las ciudades.
 
 El bucle while itera como mucho A veces siendo A el número de aristas (las carreteras).
 La operación pop tiene un coste de O(Log A) siendo A las carreteras
 La operaciones unir y unidos tiene un coste de O(Ln* V) siendo V las ciudades , que es prácticamente constante.
 Tener en cuenta que aunque las operaciones pop y unidos que puedan llamar A veces , la operación unir solo se llamará V-1 veces (lo necesario para 
 construir un ARM).

 El coste total del algoritmo de Kruskal es de O(A Log A) siendo A las aristas (o carreteras en este caso) teniendo en cuenta de que las construcciones
 de la cola y el conjunto siempre se va a hacer una vez en el algoritmo.

 @ </answer> */

 // ================================================================
 // Escribe el código completo de tu solución aquí debajo (después de la marca)
 //@ <answer>
class Kruskal {
    int coste;
    int aristas;
public:
    Kruskal(GrafoValorado<int> const& g) {
        coste = 0;
        aristas = 0;
        PriorityQueue<Arista<int>>cola(g.aristas());
        ConjuntosDisjuntos conjunto(g.V());
        while (!cola.empty())
        {
            Arista<int> a = cola.top(); cola.pop();
            int v = a.uno();
            int w = a.otro(v);

            if (!conjunto.unidos(v, w)) {
                conjunto.unir(v, w);
                coste = a.valor();
                aristas++;
                if (aristas == g.V() - 1)break;
            }

        }
    }
    bool isArm(GrafoValorado<int> const& g) {
        return aristas == g.V() - 1;
    }
    int cost() {
        return coste;
    }
};



bool resuelveCaso() {

    // leemos la entrada
    int N, M;
    cin >> N >> M;

    if (!cin)
        return false;
    GrafoValorado<int> red(N);
    for (int i = 0; i < M; i++) {
        int a, b, v;
        cin >> a >> b >> v;
        red.ponArista({ a-1,b-1,v });
    }
    Kruskal sol(red);
    if (!sol.isArm(red))cout << "IMPOSIBLE\n";
    else
        cout << sol.cost() << "\n";
    return true;
}

//@ </answer>
//  Lo que se escriba debajo de esta línea ya no forma parte de la solución.

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
