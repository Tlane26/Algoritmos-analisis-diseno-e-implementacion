// BFS - Matriz de Adjacencias
// Busqueda en Anchura con una representacion de Matriz de Adyacencia
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 10 // macro

// Inicializa la matAdj con false
void iniMatAdj(bool matAdj[MAX][MAX]){
  for(int i = 0; i < MAX; i++){
    for(int j = 0; j < MAX; j++){
      matAdj[i][j] = false;
    }
  }
}

// Lee los m arcos y los pone en la matAdj
void leeMatAdj(bool matAdj[MAX][MAX], int m){
  int a,b;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    // Recordar que el usuario tiene como 1 nodo al nodo 1
    // Y que la matriz el primer nodo tiene el nodo 0
    // Por eso tenemos qe rebajarle 1 a a y b
    // Recordar que el grafo es NO-DIRIGIDO y NO-ponderado
    matAdj[a-1][b-1] = matAdj[b-1][a-1] = true; 
  }
}

void printMatAdj(bool matAdj[MAX][MAX], int n){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      cout << (matAdj[i][j]) << " ";
    }
    cout << endl;
  }
}

// Complejidad: O(|V|^2)
void BFS(bool matAdj[MAX][MAX], int n){
  queue<int> fila;
  vector<int> status(n, false); // false: NO PROCESADO, true = PROCESADO
  int dato;
  for(int i = 0; i < n; i++){
    if(!status[i]){ // Si el nodo no se ha procesado
      fila.push(i); // Se incerta a la fila
      status[i] = true; // Se proceso el nodo i
      while(!fila.empty()){
        dato = fila.front();
        fila.pop();
        cout << (dato + 1) << " "; // Le sumo 1 para mostrarlo como lo desea el usuario
        for(int j = 0; j < n; j++){
          if(matAdj[dato][j] && !status[j]){
            fila.push(j);
            status[j] = true;
          }
        }
      }
    }
  }
  cout << endl;
}


int main(){
  bool matAdj[MAX][MAX];
  int n, m;
   // n = cantidad de nodos
   // m = cantidad de arcos
   cin >> n >> m;
   iniMatAdj(matAdj);
   leeMatAdj(matAdj, m);
   //printMatAdj(matAdj, n);
   BFS(matAdj, n);
  return 0;
}



/*
Grafo no dirigido y no ponderado
n = cantidad de nodos (base 1)
m = cantidad de arcos porteriormente m arcos

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
Resultado: 1 2 3 4 5 6 7 
------------------------
7 6
1 2
2 3  
2 5
3 4
4 6
5 7
Resultado: 1 2 3 5 4 7 6 
*/