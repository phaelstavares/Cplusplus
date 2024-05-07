#include <iostream>

int main() {
    int valor1 = 10;
    int valor2 = 20;

    int *ptr1 = &valor1;
    int *ptr2 = &valor2;

    std::cout << "Valor 1: " << valor1 << std::endl;
    std::cout << "Valor 2: " << valor2 << std::endl;

    if (*ptr1 > *ptr2) {
        std::cout << "O ponteiro ptr1 aponta para o valor mais alto: " << *ptr1 << std::endl;
    } else if (*ptr2 > *ptr1) {
        std::cout << "O ponteiro ptr2 aponta para o valor mais alto: " << *ptr2 << std::endl;
    } else {
        std::cout << "Os valores apontados pelos ponteiros são iguais: " << *ptr1 << std::endl;
    }

    return 0;
}