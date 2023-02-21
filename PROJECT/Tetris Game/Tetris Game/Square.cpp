//#pragma once
#include"square.h"
#include"piece.h"
using namespace std;
square::square()
{
	//simple constructor
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

int** square::draw(int x)
{
	this->rotate(x);
	//this->Ifill1();
	return arr;
}

square::~square()
{
	for (int i = 0; i < 4; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}
void square::drawer()
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
int square::type()
{
	return 6;
}
int** square::rotate(int x)
{
	//simply allowing piece movements changing coordinates
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->arr[i][j] = 0;
		}
	}
		arr[0][0] = 6;
		arr[0][1] = 6;
		arr[1][0] = 6;
		arr[1][1] = 6;

	return arr;

}
