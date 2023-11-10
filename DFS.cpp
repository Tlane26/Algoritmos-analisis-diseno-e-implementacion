// Busqueda e Profundidad (DFS) con una representacion
// de lista de Adyacencia


#include <iostream>
#include <stack>
#include <vector>

using namespace std;


void leeListAdj(vector<vector<int>> &listAdj, int m){
  int a, b;

  for(int i = 0; i < m; i++){
    cin >> a >> b;
    listAdj[a-1].push_back(b-1);
    listAdj[b-1].push_back(a-1);

  }
}

void printListAdj(vector<vector<int>> &listAdj){
  for(int i = 0; i < listAdj.size(); i++){
    cout << i+1 << " ";
    for(int j =0; j < listAdj[i].size(); j++){
      cout << " ==> " << listAdj[i][j]+1; 
    }
    cout << endl;
  }
}

// Complejidad: O(|V| + |E|). || = Tamaño
void DFS(vector<vector<int>> &listAdj){
  stack<int> pila;
  int dato;
  vector<bool> status(listAdj.size(), false);
  int cantVisitados = 0;

  for(int i = 0; i < listAdj.size() && cantVisitados != listAdj.size(); i++){
    if(!status[i]){ // Si no ha sido visitado el nodo i, lo empieza a procesar.
      pila.push(i);
      while(!pila.empty() && cantVisitados != listAdj.size()){
        dato = pila.top();
        pila.pop(); // Saco al nodo del tope de la pila
        if(!status[dato]){
          // Visito el nodo que acabo de sacar de la pila
          // lo pongo como visitado, lo despliego y 
          // la cantVisitados le sumo 1
          status[dato] = true;
          cantVisitados++;
          cout << (dato+1) << " "; // Base del usuario es base 1
          // Por cada nodo Adyacente al nodo que acabo de visitar,
          // Buscarlos en forma inversa, 
          // para que el tope de la pila quede el 
          // nodo adyacente como nombre mas pequeños
          // Pero lo meto a la pila si no ha sido visitado
          for(int j = listAdj[dato].size()-1; j>=0; j--){
            if(!status[listAdj[dato][j]]){
              pila.push(listAdj[dato][j]);
            }
          }
        }

      }
    }
  } 
  cout << endl; 
}


int main(){
  // n = cantidad de nodos o vertices
  // m = cantidad de arcos
  int n, m;
  cin >> n >> m;
  // Simularemos la listAdj coon un vector de vectores de int
  // Donde la dim 1 son los nodos
  // Donde la dim 2 son los adjacentes al nodo de la dim 1

  vector<vector<int>> listAdj(n);
  leeListAdj(listAdj, m);
  printListAdj(listAdj);
  DFS(listAdj);
}

/*
Datos del Grafo1 solo falta agregar el nodo de arranque
7 11
1 2
1 3
1 4
2 3  
2 5
3 4
3 5
4 5
4 6
5 7
6 7
Resultado: 1 2 3 4 5 7 6 

0 -> 1 -> 2 -> 3
1 -> 0 -> 2 -> 4
2 -> 0 -> 1 -> 3 -> 4
3 -> 0 -> 2 -> 4 -> 5
4 -> 1 -> 2 -> 3 -> 6
5 -> 3 -> 6
6 -> 4 -> 5

---------------------------------
Datos del Grafo2 solo falta agregar el nodo de arranque
7 6
1 2
2 3  
2 5
3 4
4 6
5 7
Resultado: 1 2 3 4 6 5 7 

*/