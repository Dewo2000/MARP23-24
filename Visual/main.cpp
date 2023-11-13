
/*@ <authors>
 *
 * Dewei Chen (MARP07)
 *
 *@ </authors> */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include "DigrafoValorado.h"
#include "IndexPQ.h"
using namespace std;


/*@ <answer>

 La solución se plantea de la forma de que se intenta buscar el camino que no supere la distancia máxima del zulo desde el origen
 del pueblo de tiene un Borriquín, los pueblos que pertenezcan a ese camino son los posibles pueblos que puede estar Petunia ,ya que
 la distancia al zulo es menor que la máxima que puede tener. Este es un problema que busca el camino mínimo en un grafo dirigido valorado
 siendo los vértices los pueblos y las aristas, las carreteras que los unen. Por lo tanto se utiliza aqui el algoritmo de Dijkstra con 
 algunas modificaciones para la resolución del problema. El algoritmo empieza , en vez de con un solo origen , con varios origenes de tamaño
 B(números de pueblos con Borriquín), estas se añaden a la cola de prioridad con la prioridad máxima (0), esto hace que el algoritmo vaya
 relajando aristas en el orden de , primero los origenes y luego los pueblos más cercanos a estos origenes , si al acabar el bucle , la distancia
 del pueblo es menor al máximo , entonces esta es añadida al contador de pueblos.

 El coste de inicialización del vector dist y la cola de prioridad es de O(V) siendo V el número de pueblos.Estas se inicializa una única vez.
 El coste de la operación pop es de O(log V) siendo V el número de pueblos , el bucle while se ejecuta como mucho V veces.
 El coste de la operación update es de O(log V) siendo V el número de pueblos , el método relajar se ejecuta A veces siendo esto el número de 
 carreteras, en este caso como son transitables en ambos sentidos , el número de carretera es 2*A.

 El coste total del algoritmo de Dijkstra es de O(2A log V) siendo V el número de pueblos y 2A el número de carretera en ambos sentidos.


 @ </answer> */

// ================================================================
// Escribe el código completo de tu solución aquí debajo (después de la marca)
//@ <answer>

class Dijkstra {
private:
    const int INF = std::numeric_limits<int>::max();
    std::vector<int> dist;
    IndexPQ<int> pq;
    int count = 0;

    void relajar(AristaDirigida<int> a) {
        int v = a.desde(), w = a.hasta();
        if (dist[w] > dist[v] + a.valor()) {
            dist[w] = dist[v] + a.valor(); 
            pq.update(w, dist[w]);
        }
    }
public:
    Dijkstra(DigrafoValorado<int> const& g, 
    int D,vector<int>origenes) :
        dist(g.V(), INF), pq(g.V()) {
        for (int i = 0; i < origenes.size(); i++) {
            dist[origenes[i]] = 0;
            pq.push(origenes[i], 0);
        }
        while (!pq.empty()) {
            int v = pq.top().elem; pq.pop();
            for (auto a : g.ady(v))
                relajar(a); 
            if (dist[v] <= D) {
                count++;
            }
        }
    }
    int getCount() { return count; }
};


bool resuelveCaso() {
  
  // leemos la entrada
  int D, P, C;
  cin >> D >> P >> C;
  
  if (!cin)
    return false;
  DigrafoValorado<int> g(P);
  for (int i = 0; i < C; i++) {
      int po, pd, d;
      cin >> po >> pd >> d;
      g.ponArista({ po - 1,pd - 1,d });
      g.ponArista({ pd - 1,po - 1,d });
  }
  int B;
  cin >> B;
  vector<int>origenes;
  for (int i = 0; i < B; i++) {
      int b;
      cin >> b;
      origenes.push_back(b-1);
  }

  Dijkstra dj(g, D,origenes);
  cout << dj.getCount() << endl;
  // leer el resto del caso y resolverlo
  
  
  
  
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
