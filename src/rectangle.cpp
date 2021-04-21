#include "rectangle.hh"
using namespace std;
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

Prostokat Prostokat::operator+(Vector wektor)
{
    Prostokat wynik;
    for (int i = 0; i < 4; i++)
    {
        wynik[i] = pkt1[i] + wektor;
    }
    return wynik;
}

