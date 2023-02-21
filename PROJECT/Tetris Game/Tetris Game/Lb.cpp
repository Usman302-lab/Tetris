//#pragma once
#include"Lb.h"
#include"piece.h"
using namespace std;
Lb::Lb()
{

	this->rows = 4;
	this->cols = 4;
	this->arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		this->arr[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->arr[i][j] = 0;
		}
	}

}
int** Lb::draw(int x)
{
	this->rotate(x);
	//this->Ifill1();
	return arr;
}

Lb::~Lb()
{
	for (int i = 0; i < 4; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}
void Lb::drawer()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << this->arr[i][j] << "  ";
		}
		cout << endl;
	}
}
int Lb::type()
{
	return 3;
}
int** Lb::rotate(int x)
{
	//simply allowing piece movements changing coordinates
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->arr[i][j] = 0;
		}
	}
	if (x == 0)
	{
		arr[0][2] = 3;
		arr[1][0] = 3;
		arr[1][1] = 3;
		arr[1][2] = 3;
	}
	if (x == 1)
	{
		arr[0][0] = 3;
		arr[0][1] = 3;
		arr[0][2] = 3;
		arr[1][0] = 3;
	}
	if (x == 2)
	{
		arr[0][0] = 3;
		arr[0][1] = 3;
		arr[1][1] = 3;
		arr[2][1] = 3;
	}
	if (x == 3)
	{
		arr[0][0] = 3;
		arr[1][0] = 3;
		arr[2][0] = 3;
		arr[2][1] = 3;
	}
	return arr;

}
