//#pragma once
#ifndef PIECE_H
#define PIECE_H
#include<iostream>
#include<cstring>
#include<conio.h>
using namespace std;
class piece
{
private:
public:
	virtual int** draw(int x=0)=0; //as every piece now how to draw itself
	virtual int type() = 0;   //for distinguishing piece
	virtual int** rotate(int)=0;//every piece has a rotation
	
};
#endif
