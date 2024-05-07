#include <iostream>
using namespace std;

int contarCaracteresPonteiro(char* str) {
  int contador = 0;
  while (*str != '\0') {
    contador++;
    str++;
  }
  return contador;
}

int main() {
  char str[] = "Hello, World!";
  int numeroCaracteres = contarCaracteresPonteiro(str);

  cout << "A string \"" << str << "\" possui " << numeroCaracteres << " caracteres." << endl;

  return 0;
}