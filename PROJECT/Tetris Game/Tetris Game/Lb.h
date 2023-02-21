//#pragma once
#ifndef LB_H
#define LB_H
#include<iostream>
#include<cstring>
#include<conio.h>
#include"piece.h"
using namespace std;
class Lb :public piece
{
private:
	int** arr;
	//int* arr;
	int rows;
	int cols;
public:
	Lb();
	void drawer();
	virtual int** draw(int x = 0);
	virtual int type();
	virtual int** rotate(int);
	~Lb();
};
#endif
