//#pragma once
#ifndef I_H
#define I_H
#include<iostream>
#include<cstring>
#include<conio.h>
#include"piece.h"
using namespace std;
class I :public piece
{
private:
	int** arr;
	//int* arr;
	int rows;
	int cols;
public:
	I();
	void drawer();
	virtual int** draw(int x = 0);
	virtual int type();
	virtual int** rotate(int);
	~I();
};
#endif
