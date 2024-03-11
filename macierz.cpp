#include "macierz.h"


Macierz::Macierz()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matrix[i][j] = 0.0;
        }
    }
}


Macierz::Macierz(const Macierz& copy)
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            matrix[i][j] = copy.matrix[i][j];
        }
    }
}


Macierz::~Macierz(){}


Macierz Macierz::operator*(const Macierz& copy) const 
{
    Macierz result;

    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            double sum = 0.0;
            for (int k = 0; k < 2; ++k) 
            {
                sum += matrix[i][k] * copy.get(k, j);
            }
            result.set(i, j, sum);
        }
    }

    return result;
}


Macierz Macierz::operator+(const Macierz& copy) const 
{
    Macierz result;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            result.set(i, j, matrix[i][j] + copy.get(i, j));
        }
    }

    return result;
}


Macierz Macierz::operator*(const double x) const 
{
    Macierz result;
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            result.set(i, j, matrix[i][j] * x);
        }
    }
    return result;
}


Macierz& Macierz::operator=(const Macierz& copy) 
{
    if (this != &copy) 
    {
        for (int i = 0; i < 2; i++) 
        {
            for (int j = 0; j < 2; j++) 
            {
                matrix[i][j] = copy.get(i, j);
            }
        }
    }
    return *this;
}


bool Macierz::operator==(const Macierz& copy) const 
{
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            if (matrix[i][j] != copy.get(i, j)) 
            {
                return false;
            }
        }
    }
    return true;
}


Macierz& Macierz::operator+=(const Macierz& copy) 
{
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            matrix[i][j] += copy.get(i, j);
        }
    }
    return *this;
}


Macierz& Macierz::operator*=(const Macierz& copy) 
{
    *this = *this * copy;
    return *this; 
}


Macierz& Macierz::operator*=(const double x) 
{
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            matrix[i][j] *= x;
        }
    }
    return *this;
}


std::ostream& operator<<(std::ostream& s, const Macierz& m) 
{
    for (int i = 0; i < 2; i++) 
    {
        for (int j = 0; j < 2; j++) 
        {
            s << m.get(i, j) << " ";
        }
        s << std::endl;
    }
    return s;
}


void Macierz::set(int i, int j, double x) 
{
    if (i >= 0 && i < 2 && j >= 0 && j < 2) 
    {
        matrix[i][j] = x;
    }
    else
    {
        std::cout << "dupa";
        exit;
    }
}


double Macierz::get(int i, int j) const 
{
    if (i >= 0 && i < 2 && j >= 0 && j < 2) 
    {
        return matrix[i][j];
    }
    return 0.0;
}


void Macierz::transpozycja() 
{
    for (int i = 0; i < 2; i++) 
    {
        for (int j = i + 1; j < 2; j++) 
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }
}