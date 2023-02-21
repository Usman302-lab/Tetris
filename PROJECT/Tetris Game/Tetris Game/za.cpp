//#pragma once
#include"za.h"
#include"piece.h"
using namespace std;
za::za()
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

int** za::draw(int x)
{
	this->rotate(x);
	//this->Ifill1();
	return arr;
}

za::~za()
{
	for (int i = 0; i < 4; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}
void za::drawer()
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
int za::type()
{
	return 5;
}
int** za::rotate(int x)
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
		arr[0][1] = 5;
		arr[0][2] = 5;
		arr[1][0] = 5;
		arr[1][1] = 5;
	}
	if (x == 1)
	{
		arr[0][0] = 5;
		arr[1][0] = 5;
		arr[1][1] = 5;
		arr[2][1] = 5;
	}
	return arr;

}
