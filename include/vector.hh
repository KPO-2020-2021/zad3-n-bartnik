
#pragma once

#include "size.hh"
#include <iostream>

class Vector {

private:

    double size[SIZE];     //Tablica wektora

public:

    Vector();

    Vector(double a, double b);

    Vector operator + (const Vector &v);

    Vector operator - (const Vector &v);

    Vector operator * (const double &tmp);

    Vector operator / (const double &tmp);

    const double &operator [] (int index) const;

    double &operator [] (int index);
    bool operator==(Vector wek) const;

};

std::ostream &operator << (std::ostream &out, Vector const &tmp);

std::istream &operator >> (std::istream &in, Vector &tmp);


