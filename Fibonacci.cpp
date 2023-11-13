#include <iostream>
#include <vector>

using namespace std;


// Implementacion directa de la definicion de factorial
// Buena implementacion hasta el numero 41
// O (2^n)
int fibonacciDirecto(int n){
  if(n <= 1)
    return n;
  else
    return fibonacciDirecto(n-1) + fibonacciDirecto(n-2);
}

// Se inicializa el vector con los valores de 0 y 1
vector<int> memo = {0,1};

int fibonacciPD(int n){
  if(n < memo.size()) // Si n esta en memo se obtiene su valor
    return memo[n];
  else{ // Si no esta se calcula y se agrega el resultado a memo
    int f = fibonacciPD(n-1) + fibonacciPD(n-2);
    memo.push_back(f);
    return f;
  }
}

int fibonacciIterativoPD(int n){
  int F[n];
  F[0] = 0;
  F[1] = 1;
  for(int i = 2; i <= n; i++){
    F[i] = F[i-1] + F[i-2];
  }
  return F[n];
}

// Complejidad O(n)
int fibonacciIterativo(int n){
  if(n <= 1){
    return n;
  }
  else{
    int n1 = 0, n2= 1, f;
    for(int i = 2; i <= n; i++){
      f = n1+n2;
      n1 = n2;
      n2 = f;
    }
    return f;
  }
}

int main() {
  int n;

  cout << "Metodo Fibonnaci" << endl;
  cin >> n;
  cout << fibonacciIterativo(n);
}