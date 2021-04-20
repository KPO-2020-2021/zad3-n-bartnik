#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../tests/doctest/doctest.h"
#include "vector.hh"
#include "rectangle.hh"
#include "matrix.hh"
#include "size.hh"


/****************************WEKTOR****************************/
TEST_CASE("konstruktor parametryczny"){
    double a=1, b=2;
    Vector wektor(a,b);
    
    CHECK(wektor[0]==1);
    CHECK(wektor[1]==2);
}

// TEST_CASE("konstruktor bezparametryczny"){
    
//     Vector wektor();
    
//     CHECK(wektor[0]==0);
//     CHECK(wektor[1]==0);
// }

TEST_CASE ("Dodawanie wektorów"){
Vector wektor1(1,2);
Vector wektor2(2,1);
Vector wynik;

wynik=wektor1+wektor2;
CHECK(wynik[0]==3);
CHECK(wynik[1]==3);

}

TEST_CASE ("Odejmowanie wektorów"){
Vector wektor1(1,2);
Vector wektor2(2,1);
Vector wynik;

wynik=wektor1-wektor2;
CHECK(wynik[0]==-1);
CHECK(wynik[1]==1);

}

TEST_CASE ("wektor * stała"){
Vector wektor1(1,2);
double a=2;
Vector wynik;

wynik=wektor1*a;
CHECK(wynik[0]==2);
CHECK(wynik[1]==4);

}

TEST_CASE ("wektor - wyświetlanie"){
Vector wektor1(1,2);
// double a[2]={1,2};
std::ostringstream StrmWyj;
StrmWyj << wektor1;
std::cout << StrmWyj.str();
CHECK("[ 1 ]\n[ 2 ]\n"==StrmWyj.str());


}