#pragma once

#include "size.hh"
#include "vector.hh"
#include"rectangle.hh"
#include <iostream>
#include <cstdlib>

class Matrix
{

private:
    double value[SIZE][SIZE]; // Wartosci macierzy
    double radian;

public:
   Matrix(double[SIZE][SIZE]); // Konstruktor klasy
    Matrix(); // Konstruktor klasy
    Vector operator*(Vector tmp); // Operator mnożenia przez wektor
    Matrix operator+(Matrix tmp);
    double &operator()(unsigned int row, unsigned int column);
    const double &operator()(unsigned int row, unsigned int column) const;
    //Matrix() { radian = 0; };
    Matrix(double kat);
    void Obroc();
 
  Prostokat operator*(Prostokat wektor);
};

std::istream &operator>>(std::istream &in, Matrix &mat);

std::ostream &operator<<(std::ostream &out, Matrix const &mat);
