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
	Macierz(); //konstruktor macierzy wype³nionej zerami
	Macierz(const Macierz &copy); //konstruktor macierzy kopiuj¹cej wartoœci innej macierzy
	~Macierz(); //destruktor klasy Macierz()

	Macierz operator*(const Macierz& copy) const; //operator mno¿enia macierzy przez macierz
	Macierz operator+(const Macierz& copy) const; //operator dodawania macierzy
	Macierz operator*(const double x) const; //operator mno¿enia macierzy przez liczbê
	Macierz& operator=(const Macierz& copy); //operator przypisania wartoœci macierzy
	bool operator==(const Macierz& copy) const; //operator porównania wartoœci macierzy
	Macierz& operator+=(const Macierz& copy); //operator dodawania macierzy
	Macierz& operator*=(const Macierz& copy); //operator mno¿enia macierzy przez macierz
	Macierz& operator*=(const double x); //operator mno¿enia macierzy przez liczbê 
	friend std::ostream& operator<<(std::ostream& s, const Macierz& m); //przeci¹¿ony operator wyœwietlaj¹cy macierz

	void set(int i, int j, double x); //metoda ustawiaj¹ca wartoœci macierzy z pozycji (i, j)
	double get(int i, int j) const; //metoda zwracaj¹ca wartoœci macierzy z pozycji (i, j)

	void transpozycja(); //metoda transponuj¹ca macierz
};

#endif // MACIERZ_H