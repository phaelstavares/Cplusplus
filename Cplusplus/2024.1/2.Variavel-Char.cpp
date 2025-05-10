#include <iostream>

using namespace std;

int main() {
  char letra;
  char* ponteiroLetra = &letra;

  cout << "Digite um caractere: ";
  cin >> letra;

  cout << "Valor do caractere digitado: " << *ponteiroLetra << endl;

  *ponteiroLetra = 'A';

  cout << "Valor do caractere após a modificação: " << *ponteiroLetra << endl;

  return 0;
}