#include "Lab.hpp"
#include<cstdio>
#include<cstdlib>
#include <iostream>
#include <fstream>
using namespace std;


void Matrix::utworzMacierz()
{
	macierz = new int*[n];
	for (int i = 0; i < n; i++)
	{
		macierz[i] = (int*)calloc(m, sizeof(int));
	}
	
}

Matrix::Matrix(int nn, int mm)
{
	n = nn;
	m = mm;
	utworzMacierz();
}



Matrix::Matrix(int nn)
{
	n = nn;
	m = nn;
	utworzMacierz();
}

void Matrix::set(int i, int j, int val)
{
	if (i >= 0 && i < n && j >= 0 && j < m)
	{
		macierz[i][j] = val;
	}
}

int Matrix::get(int i, int j)
{

	if (i >= 0 && i < n && j >= 0 && j < m)
	{
		return macierz[i][j];
	}
}

Matrix Matrix::add(Matrix m2)
{
	if (m != m2.cols() && n != m2.rows())
	{
		cout << "Nie ma mozliwosci dodawania. Macierze nie pasuja do siebie" << endl;
		return 1;
	}

	Matrix wynik(n, m);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			wynik.macierz[i][j] = macierz[i][j] + m2.macierz[i][j];
		}
	}
	return wynik;
}

Matrix Matrix::subtract(Matrix m2)
{
	if (m != m2.cols() && n != m2.rows())
	{
		cout << "Nie ma mozliwosci odejmowania. Macierze nie pasuja do siebie" << endl;
		return 1;
	}

	Matrix wynik(n, m);
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			wynik.macierz[i][j] = macierz[i][j] - m2.macierz[i][j];
		}
	}
	return wynik;
}

Matrix Matrix::multiply(Matrix m2)
{
	if (n != m2.rows())
	{
		cout << "Nie ma mozliwosci mno¿enia. Macierze nie pasuja do siebie" << endl;
		return 1;
	}

	Matrix wynik(n, m2.rows());
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m2.rows(); j++)
		{
			double mnozenie = 1;
			for (int k = 0; k < m; k++)
			{
				mnozenie += macierz[i][k] * m2.get(k,j);
			}
			wynik.set(i, j, mnozenie);
		}
	}
	return wynik;
}

int Matrix::cols()
{
	return m;
}

int Matrix::rows()
{
	return n;
}

void Matrix::print()
{
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < m; j++)
		{
			cout << macierz[i][j] << " ";
		}
		cout << endl;
	}
}

void Matrix::store(std::string filename, std::string path)
{
	ofstream  plik;
	path += "\\" + filename;
	plik.open(path, ios_base::out);
	if (!plik.good())
	{
		cout << "Nie udalo sie otworzyc pliku." << endl;
		exit(0);
	}

	plik << n << "\t" << m << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			plik << macierz[i][j] << "\t";
		plik << endl;
	}

	plik.close();
}

Matrix Matrix::matrix(std::string path)
{
	ifstream plik;
	plik.open(path);
	if (plik.good() != 0)
	{
		cout << "Nie udalo sie otorzyc pliku" << endl;
		exit(1);
	}

	plik >> n;
	plik >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			plik >> macierz[i][j];
		}
	}
	plik.close();
}
