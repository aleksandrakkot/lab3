// ConsoleApplication3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include<cstdio>
#include<cstdlib>
#include <iostream>
#include <fstream>


using namespace std;

class Matrix
{
private:
	int** macierz; //pole klasy
	int n;
	int m;
	void utworzMacierz()
	{
		macierz = new int*[n];
		for (int i = 0; i < n; i++)
		{
			macierz[i] = (int*)calloc(m, sizeof(int));
		}
	}

public:
	Matrix(int nn, int mm) //konstruktor
	{
		n = nn;
		m = mm;
		utworzMacierz();
	}

	Matrix(int nn)
	{
		n = nn;
		m = nn;
		utworzMacierz();
	}

	void set(int i, int j, int val)
	{
		if (i >= 0 && i < n && j >= 0 && j < m)
		{
			macierz[i][j] = val;
		}
	}

	int get(int i, int j)
	{
		if (i >= 0 && i < n && j >= 0 && j < m)
		{
			return macierz[i][j];
		}
	}

	Matrix add(Matrix m2)
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

	Matrix subtract(Matrix m2)
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
	Matrix multiply(Matrix m2)
	{
		if (n != m2.rows())
		{
			cout << "Nie ma mozliwosci mnożenia. Macierze nie pasuja do siebie" << endl;
			return 1;
		}

		Matrix wynik(n, m);
		for (size_t i = 0; i < n; i++)
		{
			for (size_t j = 0; j < m; j++)
			{
				wynik.macierz[i][j] = 0;
				for (int k = 0; k < m; k++)
				{
					wynik.macierz[i][j] += macierz[i][k] * m2.macierz[k][j];
				}
				return wynik;
			}
		}
		
	}

	int cols()
	{

		return m;

	}

	int rows()
	{
		
		return n;
	}

	void print()
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

	Matrix store(string filename, string path)
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

	Matrix matrix(string path)
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
};

int main()
{
	Matrix m(4, 5);
	Matrix kwadratowa(4);
	Matrix m2(4, 5);

	cout << "Macierz 4x5 zainicjowana zerami: " << endl;
	m.print();
	cout << "Macierz kwadratowa zainicjowana zerami: " << endl;
	kwadratowa.print();

	m.set(0, 0, 20);
	m2.set(0, 0, 8);
	kwadratowa.set(0, 0, 3);

	cout<< "Pierwszy element tabilcy m to: "<< m.get(0, 0)<<endl;
	cout<<"Liczba kolumn macierzy m to: "<< m.cols()<<endl;
	cout << "Liczba wierszy macierzy m to: " << m.rows() << endl;


}