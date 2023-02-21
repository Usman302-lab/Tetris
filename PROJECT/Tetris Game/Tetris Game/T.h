//#pragma once
#ifndef T_H
#define T_H
#include<iostream>
#include<cstring>
#include<conio.h>
#include"piece.h"
using namespace std;
class T :public piece
{
private:
	int** arr;
	//int* arr;
	int rows;
	int cols;
public:
	T();
	void drawer();
	virtual int** draw(int x = 0);
	virtual int type();
	virtual int** rotate(int);
	~T();
};
#endif
