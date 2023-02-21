//#pragma once
#ifndef SQUARE_H
#define SQUARE_H
#include<iostream>
#include<cstring>
#include<conio.h>
#include"piece.h"
using namespace std;
class square :public piece
{
private:
	int** arr;
	//int* arr;
	int rows;
	int cols;
public:
	square();
	void drawer();
	virtual int** draw(int x = 0);
	virtual int type();
	virtual int** rotate(int);
	~square();
};
#endif
