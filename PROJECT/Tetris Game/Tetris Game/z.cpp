
#include"z.h"
#include"piece.h"
using namespace std;
z::z()
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

int** z::draw(int x)
{
	this->rotate(x);
	//this->Ifill1();
	return arr;
}

z::~z()
{
	for (int i = 0; i < 4; i++)
	{
		delete arr[i];
	}
	delete[] arr;
}
void z::drawer()
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
int z::type()
{
	return 4;
}
int** z::rotate(int x)
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
		arr[0][0] = 4;
		arr[0][1] = 4;
		arr[1][1] = 4;
		arr[1][2] = 4;
	}
	if (x == 1)
	{
		arr[0][1] = 4;
		arr[1][0] = 4;
		arr[1][1] = 4;
		arr[2][0] = 4;
	}
	return arr;

}
