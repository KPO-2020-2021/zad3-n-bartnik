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
    Matrix(); // Konstruktor bezparametryczny klasy
    Vector operator*(Vector tmp); // Operator mnożenia przez wektor
    Matrix operator+(Matrix tmp);
    double &operator()(unsigned int row, unsigned int column);
    const double &operator()(unsigned int row, unsigned int column) const;
    Matrix(double kat);
    void Obroc();

/*Funkcja rotacji. Mnoży prostokąt razy macierz. 
Konieczne wcześniejsze obrócenie macierzy*/
    void Rot(Prostokat &Pr) {Pr=*this*Pr;} 
 
  Prostokat operator*(Prostokat wektor);
  void Gaus(Matrix macierz);
};

std::istream &operator>>(std::istream &in, Matrix &mat);

std::ostream &operator<<(std::ostream &out, Matrix const &mat);
