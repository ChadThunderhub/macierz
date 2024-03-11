#pragma once
#ifndef MACIERZ_H
#define MACIERZ_H

#include <iostream>
#include <cstdlib>
#include <ctime>

class Macierz
{
private:
	double matrix[2][2]; //macierz 2x2

public:
	Macierz(); //konstruktor macierzy wype�nionej zerami
	Macierz(const Macierz &copy); //konstruktor macierzy kopiuj�cej warto�ci innej macierzy
	~Macierz(); //destruktor klasy Macierz()

	Macierz operator*(const Macierz& copy) const; //operator mno�enia macierzy przez macierz
	Macierz operator+(const Macierz& copy) const; //operator dodawania macierzy
	Macierz operator*(const double x) const; //operator mno�enia macierzy przez liczb�
	Macierz& operator=(const Macierz& copy); //operator przypisania warto�ci macierzy
	bool operator==(const Macierz& copy) const; //operator por�wnania warto�ci macierzy
	Macierz& operator+=(const Macierz& copy); //operator dodawania macierzy
	Macierz& operator*=(const Macierz& copy); //operator mno�enia macierzy przez macierz
	Macierz& operator*=(const double x); //operator mno�enia macierzy przez liczb� 
	friend std::ostream& operator<<(std::ostream& s, const Macierz& m); //przeci��ony operator wy�wietlaj�cy macierz

	void set(int i, int j, double x); //metoda ustawiaj�ca warto�ci macierzy z pozycji (i, j)
	double get(int i, int j) const; //metoda zwracaj�ca warto�ci macierzy z pozycji (i, j)

	void transpozycja(); //metoda transponuj�ca macierz
};

#endif // MACIERZ_H