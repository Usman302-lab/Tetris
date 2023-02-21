//#pragma once
#ifndef Z_H
#define Z_H
#include<iostream>
#include<cstring>
#include<conio.h>
#include"piece.h"
using namespace std;
class z :public piece
{
private:
	int** arr;
	//int* arr;
	int rows;
	int cols;
public:
	z();
	void drawer();
	virtual int** draw(int x = 0);
	virtual int type();
	virtual int** rotate(int);
	~z();
};
#endif
