#pragma once
#include<iostream>
#include<cstring>
#include<conio.h>
#include"piece.h"
using namespace std;
class za :public piece
{
private:
	int** arr;
	//int* arr;
	int rows;
	int cols;
public:
	za();
	void drawer();
	virtual int** draw(int x = 0);
	virtual int type();
	virtual int** rotate(int);
	~za();
};