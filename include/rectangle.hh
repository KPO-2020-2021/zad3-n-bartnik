
#pragma once

#include <iostream>
#include <cmath>
#include "vector.hh"
#include "size.hh"

class Prostokat
{
  Vector pkt1[4];

public:
  Prostokat(){};
  Prostokat(Vector pkt, double h, double w);
  Vector operator[](int Ind) const { return pkt1[Ind]; }
  Vector &operator[](int Ind) { return pkt1[Ind]; }
  Prostokat operator+(Vector wektor);
  double odleglosci();
  /*Translacja prostokąta o zadany wektor*/
  void trans(Vector wektor)
  {
    *this = *this + wektor;
  }
};

/*
 Operator wypisywania, przyjmuje prostokąt
 */
std::ostream &operator<<(std::ostream &Strm,
                         const Prostokat &Pr);