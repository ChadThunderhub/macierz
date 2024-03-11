#include <iostream>
#include "macierz.h"


int main() 
{
    system("chcp 1250");
    system("cls");


    const int zero = 0;
    const int one = 1;


    Macierz matrix;
    std::cout << "Macierz wype³niona zerami:" << std::endl << matrix << std::endl;


    matrix.set(zero, zero, 10.1);
    matrix.set(zero, one, 5.8);
    matrix.set(one, zero, 2.5);
    matrix.set(one, one, 3.0);


    Macierz matrix2;
    matrix2.set(zero, zero, 2.1);
    matrix2.set(zero, one, 1.3);
    matrix2.set(one, zero, 3.1);
    matrix2.set(one, one, 7.2);


    std::cout << "Macierz po wype³nieniu danymi:" << std::endl << matrix << std::endl;


    Macierz multiplicationMtrx = matrix * matrix2;
    std::cout << "1. Mno¿enie macierzy:" << std::endl << multiplicationMtrx << std::endl;


    Macierz addition = matrix + matrix2;
    std::cout << "2. Dodawanie macierzy:" << std::endl << addition << std::endl;

    
    double x = 1.1;
    Macierz multiplicationNmbr = matrix * x;
    std::cout << "3. Mno¿enie macierzy przez liczbê:" << std::endl << multiplicationNmbr << std::endl;


    Macierz substitution = matrix;
    std::cout << "4. Podmiana macierzy:" << std::endl << "Przed podmian¹: " << std::endl << substitution << std::endl;
    substitution = matrix2;
    std::cout << "Po podmianie: " << std::endl << substitution << std::endl;


    std::cout << "5. Porównanie macierzy:" << std::endl;
    if (matrix == matrix2) {
        std::cout << "Macierze s¹ równe." << std::endl << std::endl;
    }
    else {
        std::cout << "Macierze nie s¹ równe." << std::endl << std::endl;
    }


    Macierz addition2 = matrix;
    std::cout << "6. Dodawanie macierzy: " << std::endl;
    addition2 += matrix2;
    std::cout << addition2 << std::endl;


    Macierz multiplicationMtrx2 = matrix;
    std::cout << "7. Mno¿enie macierzy:" << std::endl;
    multiplicationMtrx2 *= matrix2;
    std::cout << multiplicationMtrx2 << std::endl;


    Macierz multiplicationNmbr2 = matrix;
    std::cout << "8. Mno¿enie macierzy przez liczbê:" << std::endl;
    multiplicationNmbr2 *= x;
    std::cout << multiplicationNmbr2 << std::endl;


    Macierz transpose = matrix;
    std::cout << "9. Transponowanie macierzy:" << std::endl << "Przed transponowaniem:" << std::endl << transpose << std::endl;
    transpose.transpozycja();
    std::cout << "Po transponowaniu:" << std::endl << transpose;


    return 0;
}
