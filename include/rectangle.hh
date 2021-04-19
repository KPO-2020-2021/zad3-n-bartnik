
#pragma once

#include <iostream>
#include <cmath>
#include "vector.hh"
#include "size.hh"

/*
 *  Tutaj trzeba opisac klase. Jakie pojecie modeluje ta klasa
 *  i jakie ma glowne cechy.
 */
class Prostokat
{
  Vector pkt1[4];

public:
Prostokat(){};
  Prostokat(Vector pkt, double h, double w);
  Vector operator[](int Ind) const { return pkt1[Ind]; } //wypisywanie
  Vector &operator[](int Ind) { return pkt1[Ind]; } //wpisywanie
Prostokat operator+ (Vector wektor);
};



/*
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 * Szczegoly dotyczace zalecen realizacji opisow mozna
 * znalezc w pliku:
 *    ~bk/edu/kpo/zalecenia.txt 
 */
std::ostream &operator<<(std::ostream &Strm,
                         const Prostokat &Pr);