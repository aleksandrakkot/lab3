#pragma once
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstring>
#include<cstdio>


class Matrix
{
private:
	int** macierz; //pole klasy
	int n;
	int m;
	

public:
	void utworzMacierz();
	Matrix(int nn, int mm); //konstruktor
	Matrix(int nn);
	void set(int i, int j, int val);
	int get(int i, int j);
	Matrix add(Matrix m2);
	Matrix subtract(Matrix m2);
	Matrix multiply(Matrix m2);
	int cols();
	int rows();
	void print();
	Matrix store(std::string filename, std::string path);
	Matrix matrix(std::string path);
};
