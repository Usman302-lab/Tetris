//#pragma once
#include"za.h"
#include"T.h"
using namespace std;
T::T()
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

int** T::draw(int x)
{
	this->rotate(x);
	//this->Ifill1();
	return arr;
}

T::~T()
{
	for (int i = 0; i < 4; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}
void T::drawer()
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
int T::type()
{
	return 7;
}
int** T::rotate(int x)
{
	////simply allowing piece movements changing coordinates
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->arr[i][j] = 0;
		}
	}
	if (x == 0)
	{
		arr[0][1] = 7;
		arr[1][0] = 7;
		arr[1][1] = 7;
		arr[1][2] = 7;
	}
	if (x == 1)
	{
		arr[0][0] = 7;
		arr[0][1] = 7;
		arr[0][2] = 7;
		arr[1][1] = 7;
	}
	if (x == 2)
	{
		arr[0][1] = 7;
		arr[1][0] = 7;
		arr[1][1] = 7;
		arr[2][1] = 7;
	}
	if (x == 3)
	{
		arr[0][0] = 7;
		arr[1][0] = 7;
		arr[1][1] = 7;
		arr[2][0] = 7;
	}
	return arr;

}
