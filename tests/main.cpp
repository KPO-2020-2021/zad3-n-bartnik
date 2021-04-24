#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "rectangle.hh"
#include "matrix.hh"
#include "size.hh"

/****************************WEKTOR****************************/
TEST_CASE("konstruktor parametryczny")
{
    double a = 1, b = 2;
    Vector wektor(a, b);

    CHECK(wektor[0] == 1);
    CHECK(wektor[1] == 2);
}

TEST_CASE("konstruktor bezparametryczny")
{

    Vector wektor;

    CHECK(wektor[0] == 0);
    CHECK(wektor[1] == 0);
}

TEST_CASE("Dodawanie wektorów")
{
    Vector wektor1(1, 2);
    Vector wektor2(2, 1);
    Vector wynik;

    wynik = wektor1 + wektor2;
    CHECK(wynik[0] == 3);
    CHECK(wynik[1] == 3);
}

TEST_CASE("Odejmowanie wektorów")
{
    Vector wektor1(1, 2);
    Vector wektor2(2, 1);
    Vector wynik;

    wynik = wektor1 - wektor2;
    CHECK(wynik[0] == -1);
    CHECK(wynik[1] == 1);
}

TEST_CASE("wektor * stała")
{
    Vector wektor1(1, 2);
    double a = 2;
    Vector wynik;

    wynik = wektor1 * a;
    CHECK(wynik[0] == 2);
    CHECK(wynik[1] == 4);
}

TEST_CASE("wektor - wyświetlanie")
{
    Vector wektor1(1, 2);
    // double a[2]={1,2};
    std::ostringstream StrmWyj;
    StrmWyj << wektor1;
    std::cout << StrmWyj.str();
    CHECK("1 2 " == StrmWyj.str());
}

TEST_CASE("wektor - wpisywanie")
{
    Vector a;

    std::istringstream in("1 1 ");
    in >> a;
    std::ostringstream out;
    out << a;

    CHECK("1 1 " == out.str());
}

TEST_CASE("operator porownania")
{
    Vector wektor1(1, 2);
    Vector wektor2(1, 2);

    CHECK(wektor1 == wektor2);
}
TEST_CASE("T=blad")
{
    Vector wektor1(1, 2);
    WARN_THROWS(wektor1[2]);
}

TEST_CASE("operator porownania")
{
    Vector wektor1(1, 2);
    Vector wektor2(1, 2);

    CHECK(wektor1 == wektor2);
}

TEST_CASE("mierzenie odległosci")
{
    double wynik;
    Vector wektor1(1, 2);
    Vector wektor2(1, 2);

    wynik = wektor1.odleglosc(wektor2);

    CHECK(wynik == 0);
}
/****************************MACIERZ****************************/

TEST_CASE("konstruktor parametryczny")
{

    double tab[2][2] = {{2, 2}, {2, 2}};
    Matrix macierz(tab);

    CHECK(macierz(0, 0) == 2);
    CHECK(macierz(0, 1) == 2);
    CHECK(macierz(1, 0) == 2);
    CHECK(macierz(1, 1) == 2);
}

TEST_CASE("konstruktor bezparametryczny")
{

    Matrix macierz;

    CHECK(macierz(0, 0) == 0);
    CHECK(macierz(0, 1) == 0);
    CHECK(macierz(1, 0) == 0);
    CHECK(macierz(1, 1) == 0);
}

TEST_CASE("macierz mnożenie * wektor")
{
    Vector wektor1(1, 2);
    Vector wektor2(0, 0);
    Matrix macierz;

    wektor1 = macierz * wektor1;
    CHECK(wektor1 == wektor2);
}

TEST_CASE("macierz obrót")
{
    Vector wektor1(1, 2);
    Vector wektor2(1, 2);
    Matrix macierz;
    macierz.Obroc();
    wektor1 = macierz * wektor2;

    CHECK(wektor1 == wektor2);
}

TEST_CASE("T=blad")
{
    Matrix macierz;
    WARN_THROWS(macierz(100, 100));
}

TEST_CASE("metoda gaussa")
{
    double tab[2][2] = {{1, 1}, {0, 1}};
    Matrix macierz(tab);
    macierz.Gaus(macierz);

    CHECK(macierz(0, 0) == 1);
    CHECK(macierz(0, 1) == 1);
    CHECK(macierz(1, 0) == 0);
    CHECK(macierz(1, 1) == 1);
}

/****************************PROSTOKAT****************************/

TEST_CASE("konstruktor parametryczny")
{

    Vector wektor(1, 1), wektor1(21, 1), wektor2(21, 11), wektor3(1, 11);
    double h = 10, w = 20;
    Prostokat Pr(wektor, h, w);

    CHECK(Pr[0] == wektor);
    CHECK(Pr[1] == wektor1);
    CHECK(Pr[2] == wektor2);
    CHECK(Pr[3] == wektor3);
}

TEST_CASE("konstruktor bezparametryczny")
{

    Prostokat Pr;
    Vector wektor;
    CHECK(Pr[0] == wektor);
    CHECK(Pr[1] == wektor);
    CHECK(Pr[2] == wektor);
    CHECK(Pr[3] == wektor);
}

TEST_CASE("przesuniecie o wektor")
{

    Prostokat Pr;
    Vector wektor(20, 20);
    Pr.trans(wektor);
    CHECK(Pr[0] == wektor);
    CHECK(Pr[1] == wektor);
    CHECK(Pr[2] == wektor);
    CHECK(Pr[3] == wektor);
}

TEST_CASE("obrot wokol srodka ukladu wspolrzednych")
{

    Prostokat Pr;

    Matrix macierz(90);
    macierz.Obroc();
    macierz.Rot(Pr);
    Vector wektor;
    CHECK(Pr[0] == wektor);
    CHECK(Pr[1] == wektor);
    CHECK(Pr[2] == wektor);
    CHECK(Pr[3] == wektor);
}

TEST_CASE("prostokar - wyświetlanie")
{
    Prostokat Pr;

    std::ostringstream StrmWyj;
    StrmWyj << Pr;
    std::cout << StrmWyj.str();
    CHECK("0 0 \n0 0 \n0 0 \n0 0 \n0 0 \n" == StrmWyj.str());
}

TEST_CASE("prostokar - sprawdzanie odleglosci")
{
    Vector wektor(1, 1);
    double wynik, h = 10, w = 20;
    Prostokat Pr(wektor, h, w);
    wynik = Pr.odleglosci();
    CHECK(wynik == 60);
}
