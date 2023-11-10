#include <algorithm> // sort
#include <iostream>
#include <queue> // filas
#include <stack> // pilas
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// ============================================================
//                         VECTORES
struct empleado {
  int nomina, edad;
  string nombre;
};

bool compare(const empleado &e1, const empleado &e2) {
  if (e1.edad == e2.edad) {
    return (e1.nomina < e2.nomina);
  }
  return e1.edad > e2.edad;
}

// ============================================================

int main() {

  // ============================================================
  //                         VECTORES
  cout << "================== VECTORES ===================== \n";
  // Contructor
  // vector<int> dato1;
  // vector<int> datos2(100); ==> vector con 100 casillas
  // vector<int> datos3(100, -5); ==> vector con 100 casillas con valor -5

  vector<int> vec;
  for (int i = 0; i <= 10; i++) {
    vec.push_back(i * 10);
  }

  for (auto it = vec.begin(); it != vec.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  // Sort
  vector<int> vec1{12, -5, 1, 21, 15, -3, 33};

  sort(vec1.begin(), vec1.end());
  for (auto it = vec1.begin(); it != vec1.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  sort(vec1.begin(), vec1.end(), greater<int>());
  for (auto it = vec1.begin(); it != vec1.end(); it++) {
    cout << *it << " ";
  }
  cout << endl;

  vector<empleado> vecEmpleado{{123, 23, "Juan"},
                               {829, 30, "Pedro"},
                               {226, 30, "Luis"},
                               {550, 25, "Angel"}};

  sort(vecEmpleado.begin(), vecEmpleado.end(), compare);
  for (auto it = vecEmpleado.begin(); it != vecEmpleado.end(); it++) {
    cout << "[" << (*it).nomina << ", " << (*it).nombre << ", " << (*it).edad
         << "]" << endl;
  }

  // ============================================================
  //                          Filas
  cout << "\n================== FILAS ===================== \n";

  // Lo primero que entra lo primero que sale
  
  // Metodos Complejidad O(1)
  // .push(T)
  // .pop()
  // .front()
  // .empty()
  // .size()

  queue<char> q;
  q.push('X');
  q.push('D');
  q.push('W');
  q.push('T');

  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }
  cout << endl;

  // ============================================================
  //                          Pilas
  cout << "\n================== PILAS ===================== \n";

  // Lo ultimo que entra lo primero que sale

  // Metodos Complejidad O(1)
  // .push(T)
  // .pop()
  // .top()
  // .empty()
  // .size()

  stack<char> p;
  p.push('X');
  p.push('D');
  p.push('W');
  p.push('T');

  while(!p.empty()){
    cout << p.top() << " ";
    p.pop();
  }
  cout << endl;


  // ============================================================
  //                     Filas priorizadas
  cout << "\n============= FILAS PRIORIZADAS ===================== \n";

  priority_queue<int> pq;
  pq.push(38);
  pq.push(15);
  pq.push(67);
  pq.push(49);
  pq.push(49);
  pq.push(20);

  while(!pq.empty()){
    cout << pq.top() << " ";
    pq.pop();
  }
  cout << endl;

  priority_queue<int, vector<int>, greater<int>> pq1;
  pq1.push(38);
  pq1.push(15);
  pq1.push(67);
  pq1.push(49);
  pq1.push(49);
  pq1.push(20);

  while(!pq1.empty()){
    cout << pq1.top() << " ";
    pq1.pop();
  }
  cout << endl;
  
  // ============================================================
  //                Conjuntos  (unordered_set)
  cout << "\n============= CONJUNTOS (unordered_set) ================= \n";

  // Metodos Complejidad O(1)
  // insert(T)
  // find(T)
  // empty()
  // size()

  unordered_set<string> miSet;
  miSet.insert("Naranjas");
  miSet.insert("Peras");
  miSet.insert("Manzanas");

  if(miSet.find("Peras") != miSet.end()){
    cout << "Si hay Peras" << endl;
  }
  for(auto it=miSet.begin(); it!=miSet.end(); it++){
    cout << "[ " << *it << " ]" << endl;
  }

  // ============================================================
  //                Mapas  (unordered_map)
  cout << "\n============= MAPAS (unordered_map) ================= \n";

  // operador []
  // empty()
  // size()

  unordered_map<string, int> miMap;
  miMap["Luis"] = 30;
  miMap["Angel"] = 23;
  miMap["Pedro"] = 25;
  miMap["Juan"] = 31;

  for(auto it = miMap.begin(); it!=miMap.end(); it++){
    cout << it->first << " tiene " << it->second << endl;
  }

  unordered_map<string, int>::iterator it;
  it = miMap.find("Paco");
  if(it != miMap.end()){
    cout << "La edad de Paco es " << it->second << endl;
  }
  else{
    cout << "Paco no esta en el mapa" << endl;
  }



  
  return 0;
}