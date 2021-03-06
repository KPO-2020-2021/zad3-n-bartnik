#include "size.hh"
#include "vector.hh"
#include "matrix.hh"
#include <iostream>
#include <cstdlib>
#include<cmath>


using namespace std; 
/******************************************************************************
 |  Konstruktor klasy Matrix.                                                 |
 |  Argumenty:                                                                |
 |      Brak argumentow.                                                      |
 |  Zwraca:                                                                   |
 |      Macierz wypelnione wartoscia 0.                                       |
 */
Matrix::Matrix() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = 0;
        }
    }
    radian=0;
}


/******************************************************************************
 |  Konstruktor parametryczny klasy Matrix.                                              |
 |  Argumenty:                                                                |
 |      tmp - dwuwymiarowa tablica z elementami typu double.                               |
 |  Zwraca:                                                                   |
 |      Macierz wypelniona wartosciami podanymi w argumencie.                 |
 */
Matrix::Matrix(double tmp[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            value[i][j] = tmp[i][j];
        }
    }
}


/******************************************************************************
 |  Realizuje mnozenie macierzy przez wektor.                                 |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik mnozenia,                     |
 |      v - wektor, czyli drugi skladnik mnozenia.                            |
 |  Zwraca:                                                                   |
 |      Iloczyn dwoch skladnikow przekazanych jako wektor.                    |
 */

Vector Matrix::operator * (Vector tmp) {
    Vector result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result[i] += value[i][j] * tmp[j];
        }
    }
    return result;

}


/******************************************************************************
 |  Funktor macierzy                                                          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy.                             |
 */
double &Matrix::operator()(unsigned int row, unsigned int column) {

    if (row >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem"; 
        exit(0); // lepiej by??oby rzuci?? wyj??tkiem stdexcept
    }

    if (column >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej by??oby rzuci?? wyj??tkiem stdexcept
    }

    return value[row][column];
}


/******************************************************************************
 |  Funktor macierzy                                                ctor::odleglosc(Vector wek)
{      8          |
 |  Argumenty:                                                                |
 |      row - numer wiersza.                                                  |
 |      column - numer kolumny.                                               |
 |  Zwraca:                                                                   |
 |      Wartosc macierzy w danym miejscu tablicy jako stala.                  |
 */
const double &Matrix::operator () (unsigned int row, unsigned int column) const {

    if (row >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej by??oby rzuci?? wyj??tkiem stdexcept
    }

    if (column >= SIZE) {
        throw "Error: Macierz jest poza zasiegiem";
        exit(0); // lepiej by??oby rzuci?? wyj??tkiem stdexcept
    }

    return value[row][column];
}

/******************************************************************************
 |  Przeci????enie dodawania macierzy                                                          |
 |  Argumenty:                                                                |
 |      this - macierz, czyli pierwszy skladnik dodawania,                     |
 |      v - wektor, czyli drugi skladnik dodawania.                                               |
 |  Zwraca:                                                                   |
 |      Macierz - iloczyn dw??ch podanych macierzy.                  |
 */
Matrix Matrix::operator + (Matrix tmp) {
    Matrix result;
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            result(i, j) = this->value[i][j] + tmp(i, j);
        }
    }
    return result;
}

/******************************************************************************
 |  Przeciazenie operatora >>                                                 |
 |  Argumenty:                                                                |
 |      in - strumien wyjsciowy,                                              |
 |      mat - macierz.                                                         |
 */
std::istream &operator>>(std::istream &in, Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            in >> mat(i, j);
        }
    }
    return in;
}


/******************************************************************************
 |  Przeciazenie operatora <<                                                 |
 |  Argumenty:                                                                |
 |      out - strumien wejsciowy,                                             |
 |      mat - macierz.                                                        |
 */
std::ostream &operator<<(std::ostream &out, const Matrix &mat) {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            out << "| " << mat(i, j) << " | "; //warto ustalic szerokosc wyswietlania dokladnosci liczb
        }
        std::cout << std::endl;
    }
    return out;
}

/*FUnkcja oblicza dla macierzy zadany k??t (ze stopni na radiany)*/
Matrix::Matrix(double kat)
{
    radian = kat * M_PI / 180;
}

/*Funkcja tworzy macierz obrotu wed??ug wzoru podanego w instrukcji zadania*/
void Matrix::Obroc()
{
    value[0][0] = cos(radian);
    value[0][1] = -sin(radian);
    value[1][0] = sin(radian);
    value[1][1] = cos(radian);
}

/*Funkcja mno??y prostok??t i macierz. U??ywana w rotacji prostok??ta*/
Prostokat Matrix::operator*(Prostokat prost)
{
    Prostokat wynik;
    for (int i = 0; i < 4; i++)
    {
        wynik[i] = (*this) * prost[i];
    }
    return wynik;
} 
/*Metoda eliminacji Gaussa
i, j, k- liczniki petel,
ograniczony do liczby 2 ze wzgledu na rozmiary macierzy w programie
ratio - dzielnik wierszy
*/

void Matrix::Gaus(Matrix macierz){
    float ratio;
for(int i=0;i<2;i++)
	 {
		  if(macierz(i,i) == 0.0)
		  {
			   std::cout<<"Mathematical Error!";
			   exit(0);
		  }
		  for(int j=0;j<2;j++)
		  {
			   ratio = macierz(j,i)/ macierz(i,i) ;

			   for(int k=0;k<2;k++)
			   {
			  		macierz(j,k) = macierz(j,k) - ratio* macierz(i,k);
			   }
		  }
	 }
}