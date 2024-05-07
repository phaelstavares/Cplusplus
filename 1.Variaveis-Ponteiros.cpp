#include <iostream>

using namespace std;

void trocarValores(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int main() {
  int x = 5;
  int y = 10;

  cout << "Valores originais: x = " << x << ", y = " << y << endl;

  // Troca os valores de x e y usando ponteiros
  trocarValores(&x, &y);

  cout << "Valores após a troca: x = " << x << ", y = " << y << endl;

  return 0;
}