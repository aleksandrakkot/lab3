#include <cstdio>
#include<cstdlib>
#include <iostream>
#include <fstream>
#include "Lab.hpp"

using namespace std;

int main()
{
	Matrix m(5, 6);
	Matrix m2(5, 6);
	Matrix kwadratowa(5);

	m.set(0, 0, 20);
	m2.set(0, 0, 11);
	kwadratowa.set(0, 0, 4);

	cout << "Pierwszy element macierzy m to: " << m.get(0, 0) << endl;
	cout << "Pierwszy element macierzy m2 to: " << m2.get(0, 0) << endl;
	cout << "Pierwszy element macierzy kwadratowej to: " << kwadratowa.get(0, 0) << endl;

	Matrix wynik = m.add(m2);
	cout << "Macierz m+m2: " <<endl;
	wynik.print();
	Matrix wynik1 = m.subtract(m2);
	cout << "Macierz m-m2: " << endl;
	wynik1.print();

	Matrix wynik2 = m.multiply(m2);
	cout << "Macierz m*m2: " << endl;
	wynik2.print();

	cout << "Liczba kolumn macierzy m to: " << m.cols() << endl;
	cout << "Liczba wierszy macierzy m to: " << m.rows() << endl;

	m.matrix("C:/Users/aleks/Desktop/Laboratorium3/Lab3/Lab3");
	m.store("plik.txt", "C:/Users/aleks/Desktop/Laboratorium3/Lab3/Lab3");


}