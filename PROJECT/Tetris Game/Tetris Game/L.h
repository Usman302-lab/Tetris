//#pragma once
#ifndef L_H
#define L_H
#include<iostream>
#include<cstring>
#include<conio.h>
#include"piece.h"
using namespace std;
class L :public piece
{
private:
	int** arr;
	//int* arr;
	int rows;
	int cols;
public:
	L();
	void Ifill1();
	void drawer();
	virtual int** draw(int x=0);
	virtual int type();
	virtual int** rotate(int);
	~L();
};
#endif
