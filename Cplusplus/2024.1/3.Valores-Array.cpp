#include <iostream>
using namespace std;

int main() {
  int array[] = {10, 20, 30, 40, 50};
  int tamanhoArray = sizeof(array) / sizeof(array[0]);

  for (int* i = array; i < array + tamanhoArray; ++i) {
    cout << *i << " ";
  }

  cout << endl;

  return 0;
}