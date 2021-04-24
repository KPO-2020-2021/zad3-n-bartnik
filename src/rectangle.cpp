#include "rectangle.hh"
using namespace std;

/*Fuckja buduje prostokąt. Przyjmuje wektor zawierający współrzędne jednego z punktów.
A następnie wysokość i długość prostokąta (wpisywane standardowym wejściem).
Na podstawie tych danych oblicza współrzędne pozostałych wierzchołków*/
Prostokat::Prostokat(Vector pkt, double h, double w)
{

    for (int i = 0; i < 4; i++)
    {
        pkt1[i] = pkt;
    }
    pkt1[1][0] += w;

    pkt1[2][0] += w;
    pkt1[2][1] += h;

    pkt1[3][1] += h;
}

/*FUnkcja wypisuje kolejne wierzchołki prostokąta*/
std::ostream &operator<<(std::ostream &Strm,
                         const Prostokat &Pr)
{
    for (int i = 0; i < 4; i++)
    {
        Strm << Pr[i] << endl;
    }
    Strm << Pr[0] << endl;
    return Strm;
}

/*Funkcja dodaje do prostokąta wektor. Używana w translacji*/
Prostokat Prostokat::operator+(Vector wektor)
{
    Prostokat wynik;
    for (int i = 0; i < 4; i++)
    {
        wynik[i] = pkt1[i] + wektor;
    }
    return wynik;
}

/*Funkcja sprawdzająca odległosci boków*/
double Prostokat::odleglosci()
{

    /*deklaracja zmiennych przechowujących długości boków*/
    double ab, bc, cd, da, wynik;
    /*wyliczenie długości boków*/
    ab = pkt1[0].odleglosc(pkt1[1]);
    bc = pkt1[1].odleglosc(pkt1[2]);
    cd = pkt1[2].odleglosc(pkt1[3]);
    da = pkt1[3].odleglosc(pkt1[0]);
    wynik = ab+bc+cd+da;
    if (ab != cd || da != bc)
    {
        std::cout << "Podane boki są różne. Długości boków to:" << endl;
        std::cout << "AB = " << ab << endl;
        std::cout << "BC = " << bc << endl;
        std::cout << "CD = " << cd << endl;
        std::cout << "DA = " << da << endl;
    }
    else
    {
        wynik = ab+bc+cd+da;
        std::cout << "Podane boki są równe" << endl;
    }
   return wynik;
}