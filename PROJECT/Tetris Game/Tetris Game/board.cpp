#include<iostream>
#include"board.h"
using namespace std;
Board::Board()
{
	this->rows = 20;
	this->cols = 10;
	this->baser_row = 3;
	this->shape = 0;
	this->row_bottom = 0;
	this->right_column = 0;
	this->baser_column = 3;                //baser_row and column are just pickup as a refrence and in start to put values
	this->typer = 0;
	this->temp_bottom=0;
	this->board = new int* [rows];
	this->temp = new int* [4];            //an array helpful in rotating matrices
	this->arr = new int* [4];             //as each piece is actually a 4X4 array
	for (int i = 0; i < 4; i++)
	{
		this->arr[i] = new int[4];
		this->temp[i] = new int[4];
	}
	for (int i = 0; i < rows; i++)
	{
		this->board[i] = new int[cols];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			this->board[i][j] = 0;
		}
	}
	this->score = 0;
}
void Board::draw_board()
{
	/*for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << endl;
	}*/
	showConsoleCursor(false);
	int x1 = 50, y1 = 50, x2 = 80, y2 = 80;
	
	for (int i = 0; i < rows; i++)
	{
		//x1 = 100, x2 = 130;         
		x1 = 50, x2 = 80;
		for (int j = 0; j < cols; j++)                   //simple drawing blocks on basis of number they actually contain;
		{                             
			if (board[i][j] == 0)
			{
				drawRectangle(x1, y1, x2, y2, 0, 0, 0, 65, 75, 86);
			}
			if (board[i][j] == 1)
			{
				drawRectangle(x1, y1, x2, y2, 0, 0, 0, 255, 0, 255);
			}
			if (board[i][j] == 2)
			{
				drawRectangle(x1, y1, x2, y2, 0, 0, 0, 255, 0, 0);
			}
			if (board[i][j] == 3)
			{
				drawRectangle(x1, y1, x2, y2, 0, 0, 0, 0, 0, 255);
			}
			if (board[i][j] == 4)
			{
				drawRectangle(x1, y1, x2, y2, 0, 0, 0, 0, 255, 0);
			}
			if (board[i][j] == 5)
			{
				drawRectangle(x1, y1, x2, y2, 0, 0, 0, 0, 255, 255);
			}
			if (board[i][j] == 6)
			{
				drawRectangle(x1, y1, x2, y2, 0, 0, 0, 255, 215, 0);
			}
			if (board[i][j] == 7)
			{
				drawRectangle(x1, y1, x2, y2, 0, 0, 0, 139, 69, 19);
			}
			x1 = x1 + 20,
				x2 = x2 + 20;
		}
		cout << endl;
		y1 = y1 + 20;
		y2 = y2 + 20;
	}
}
int Board::RemoveLines()
{
		// This removes the full rows
		int removed = 0;
		for (int i = rows - 1; i >= 0; i--)
		{
			bool entireLine = true;
			for (int j = 0; j < cols; j++)  //in order to simply check that is whole row empty or not
			{
				if (board[i][j] == 0)
				{
					entireLine = false;
				}
			}
			if (entireLine)
			{
				removed++;
				for (int k = i; k-1 >= 0; k--)  //if row is empty copy its previous row content
				{
					for (int j = 0; j < cols; j++)
					{
						board[k][j] = board[k - 1][j];
					}
				}
				for (int u = 0; u < cols; u++)  //if a line is empty full then when removing one row space become empty so it must be 0 in our board
				{
					board[0][u] = 0;
				}
				gotoxy(0, 0);
				showConsoleCursor(false);
				this->draw_board();
				Sleep(150);
				i++;
			}
		}
		return removed;
	
}
void Board::Board_play()
{
	int filled = 0;
	int q = 0;
	srand(time(0));
	int game = 0;
	while (filled != 1)
	{
		shape = 0;
		q = rand() % 7;       //since 7 are total pieces
		//q = 2;
		if (q == 0)
		{
			p = new I;
		}
		if (q == 1)
		{
			p = new L;
		}
		if (q == 2)
		{
			p = new Lb;
		}
		if (q == 3)
		{
			p = new z;
		}
		if (q == 4)
		{
			p = new za;
		}
		if (q == 5)
		{
			p = new square;
		}
		if (q == 6)
		{
			p = new T;
		}
		typer = p->type();
		arr = p->draw();           //taking piece array
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (arr[i][j] != 0 && board[0 + i][baser_column + j]==0)
				{
					board[0 + i][baser_column + j] = arr[i][j];
				}
			}
		}
		gotoxy(0, 0);
		this->draw_board();
		Sleep(300);
		row_bottom = 3;                    //in order to calculate the belowest element of an array
		if (arr[3][0] == 0 && arr[3][1] == 0 && arr[3][2] == 0 && arr[3][3] == 0)
		{
			baser_row = baser_row - 1;
			row_bottom = row_bottom - 1;
		}
		if (arr[2][0] == 0 && arr[2][1] == 0 && arr[2][2] == 0 && arr[2][3] == 0)
		{
			baser_row = baser_row - 1;
			row_bottom = row_bottom - 1;
		}
		if (arr[1][0] == 0 && arr[1][1] == 0 && arr[1][2] == 0 && arr[1][3] == 0)
		{
			baser_row = baser_row - 1;
			row_bottom = row_bottom - 1;
		}
		while (game != 1)
		{
			char key = getKey();
			//move down with speed
			if (key == 'd')
			{
					int advance = 1;           //to check that going down is allowed or not
					int arrayfirst = 3;       //to check the piece column 0  least bottom element
					int arraysecond = 3;     //to check the piece column 1  least bottom element
					int arraythird = 3;      //to check the piece column 2  least bottom element
					int arrayforth = 3;     //to check the piece column 3  least bottom element
					if (arr[3][0] == 0)
					{
						arrayfirst = arrayfirst - 1;
						if (arr[2][0] == 0)
						{
							arrayfirst = arrayfirst - 1;
							if (arr[1][0] == 0)
							{
								arrayfirst = arrayfirst - 1;
								if (arr[0][0] == 0)
								{
									arrayfirst = arrayfirst - 1;
								}
							}
						}
					}
					if (arr[3][1] == 0)
					{
						arraysecond = arraysecond - 1;
						if (arr[2][1] == 0)
						{
							arraysecond = arraysecond - 1;
							if (arr[1][1] == 0)
							{
								arraysecond = arraysecond - 1;
								if (arr[0][1] == 0)
								{
									arraysecond = arraysecond - 1;
								}
							}
						}
					}
					if (arr[3][2] == 0)
					{
						arraythird = arraythird - 1;
						if (arr[2][2] == 0)
						{
							arraythird = arraythird - 1;
							if (arr[1][2] == 0)
							{
								arraythird = arraythird - 1;
								if (arr[0][2] == 0)
								{
									arraythird = arraythird - 1;
								}
							}
						}
					}
					if (arr[3][3] == 0)
					{
						arrayforth = arrayforth - 1;
						if (arr[2][3] == 0)
						{
							arrayforth = arrayforth - 1;
							if (arr[1][3] == 0)
							{
								arrayforth = arrayforth - 1;
								if (arr[0][3] == 0)
								{
									arrayforth = arrayforth - 1;
								}
							}
						}
					}
					int g = baser_row - row_bottom;
					if (arrayfirst >= 0)
					{
						if (arr[arrayfirst][0] != 0)
						{
							if ((g + arrayfirst + 1) < rows)
								if (board[g + arrayfirst][baser_column] != 0)
								{
									if ((g + arrayfirst + 1) < rows)
										if (board[g + arrayfirst + 1][baser_column] != 0)
										{
											game = 1;
											advance = 0;
											break;
										}
								}
						}
					}
					g = baser_row - row_bottom;
					if (arraysecond >= 0)
					{
						if (arr[arraysecond][1] != 0)
						{
							if ((g + arraysecond + 1) < rows)
								if (board[g + arraysecond][baser_column + 1] != 0)
								{
									if (board[g + arraysecond + 1][baser_column + 1] != 0)
									{
										game = 1;
										advance = 0;
										break;
									}
								}
						}
					}
					g = baser_row - row_bottom;
					if (arraythird >= 0)
					{
						if (arr[arraythird][2] != 0)
						{
							if ((g + arraythird + 1) < rows)
								if (board[g + arraythird][baser_column + 2] != 0)
								{
									if (board[g + arraythird + 1][baser_column + 2] != 0)
									{
										game = 1;
										advance = 0;
										break;
									}
								}
						}
					}
					g = baser_row - row_bottom;
					if (arrayforth >= 0)
					{
						if (arr[arrayforth][3] != 0)
						{
							if ((g + arrayforth + 1) < rows)
								if (board[g + arrayforth][baser_column + 3] != 0)
								{
									if (board[g + arrayforth + 1][baser_column + 3] != 0)
									{
										game = 1;
										advance = 0;
										break;
									}
								}
						}
					}
					if (baser_row + 1 >= rows)
					{
						advance = 0;
						game = 1;
						break;
					}
					if (advance == 1 && baser_row + 1 < rows)
					{
						for (int i = baser_row - row_bottom, h = 0; i < baser_row + 1; i++, h++)
						{
							for (int j = baser_column, k = 0; j < baser_column + 4; j++, k++)
							{
								if (arr[h][k] != 0)
								{
									board[i][j] = 0;
								}
							}
						}
						baser_row = baser_row + 1;          //if advance allow then add1 in baser_row
						for (int i = baser_row - row_bottom, h = 0; i < baser_row + 1; i++, h++)
						{
							for (int j = baser_column, k = 0; j < baser_column + 4; j++, k++)
							{
								if (arr[h][k] != 0)
								{
									board[i][j] = arr[h][k];
								}
							}
						}

					}
					gotoxy(0, 0);
					this->draw_board();
			}
           //rotate
           if (key == 'r')
           {
			   for (int i = 0; i < 4; i++)
			   {
				   for (int j = 0; j < 4; j++)
				   {
					   temp[i][j] = 0;
				   }
			   }
			   for (int i = baser_row - row_bottom, h = 0; i <= baser_row; i++, h++)  //simply removing piece in order to check that if space is avaliable for rotated piece
			   {
				   for (int j = baser_column, k = 0; j <= baser_column + 3; j++, k++)
				   {
					   if (i >= 0 && i < rows)
					   {
						   if (arr[h][k] != 0)
						   {

							   board[i][j] = 0;
						   }
					   }
				   }
			   }
			   for (int i = 0; i < 4; i++)  //in order to first save first piece positionss
			   {
				   for (int j = 0; j < 4; j++)
				   {
					   temp[i][j] = arr[i][j];
				   }
			   }
			    temp_bottom = row_bottom;
			   if (typer == 1)  //in order to take different shapes
			   {
				   shape = shape + 1;
				   if (shape == 2)
				   {
					   shape = 0;
				   }
				   arr = p->draw(shape);

			   }
			   if (typer == 2)
			   {
				   shape = shape + 1;
				   if (shape == 4)
				   {
					   shape = 0;
				   }
				   arr = p->draw(shape);

			   }
			   if (typer == 3)
			   {
				   shape = shape + 1;
				   if (shape == 4)
				   {
					   shape = 0;
				   }
				   arr = p->draw(shape);

			   }
			   if (typer == 4)
			   {
				   shape = shape + 1;
				   if (shape == 2)
				   {
					   shape = 0;
				   }
				   arr = p->draw(shape);

			   }
			   if (typer == 5)
			   {
				   shape = shape + 1;
				   if (shape == 2)
				   {
					   shape = 0;
				   }
				   arr = p->draw(shape);

			   }
			   if (typer == 6)
			   {
				   arr = p->draw(shape);

			   }
			   if (typer == 7)
			   {
				   shape = shape + 1;
				   if (shape == 4)
				   {
					   shape = 0;
				   }
				   arr = p->draw(shape);

			   }
			   int allow_rotation = 1;

			   baser_row = baser_row - temp_bottom;
			   row_bottom = 3;
			   if (arr[3][0] == 0 && arr[3][1] == 0 && arr[3][2] == 0 && arr[3][3] == 0)
			   {
				   row_bottom = row_bottom - 1;
			   }
			   if (arr[2][0] == 0 && arr[2][1] == 0 && arr[2][2] == 0 && arr[2][3] == 0)
			   {
				   row_bottom = row_bottom - 1;
			   }
			   if (arr[1][0] == 0 && arr[1][1] == 0 && arr[1][2] == 0 && arr[1][3] == 0)
			   {
				   row_bottom = row_bottom - 1;
			   }
			   if (baser_row + row_bottom >= rows)
			   {
				   allow_rotation = 0;
			   }
			   if (baser_row + row_bottom < rows)
			   {
				   for (int i = baser_row, h = 0; i <= baser_row + row_bottom; i++, h++)
				   {
					   for (int j = baser_column, k = 0; j <= baser_column + 3; j++, k++)
					   {
						   if (i >= 0 && i < rows)
						   {
							   if (arr[h][k] != 0)
							   {
								   if (board[i][j] != 0)
								   {
									   allow_rotation = 0;
								   }
							   }
						   }
					   }
				   }
			   }
			   if (allow_rotation == 1)  //if rotation is valid rotating piece
			   {
				   for (int i = baser_row, h = 0; i <= baser_row + row_bottom; i++, h++)
				   {
					   for (int j = baser_column, k = 0; j <= baser_column + 3; j++, k++)
					   {
						   
							   if (arr[h][k] != 0)
							   {
								   board[i][j] = arr[h][k];
							   }
						   
					   }
				   }
				   baser_row = baser_row + row_bottom;


			   }
			   if (allow_rotation == 0) //if rotation is not valid simply placing piece again
			   {
				   for (int i = baser_row, h = 0; i <= baser_row + temp_bottom; i++, h++)
				   {
					   for (int j = baser_column, k = 0; j <= baser_column + 3; j++, k++)
					   {
							   if (temp[h][k] != 0)
							   {
								   board[i][j] = temp[h][k];
							   }
					   }
				   }
				   baser_row = baser_row + temp_bottom;
				   row_bottom = temp_bottom;
				   for (int i = 0; i < 4; i++)
				   {
					   for (int j = 0; j < 4; j++)
					   {
						   arr[i][j] = 0;
					   }

				   }
				   for (int i = 0; i < 4; i++)
				   {
					   for (int j = 0; j < 4; j++)
					   {
						   arr[i][j] = temp[i][j];
					   }
				   }
			   }
			   gotoxy(0, 0);
			   this->draw_board();
			   //Sleep(30);
			   delay(30);
		   }
			//right
			if (key == 'a')
			{
				int right_allow = 1;   //to check right allow movement is valid
				right_column = 3;     //determing the right most column of piece
				if (arr[0][3] == 0 && arr[1][3] == 0 && arr[2][3] == 0 && arr[3][3] == 0)
				{
					right_column = right_column - 1;
				}
				if (arr[0][2] == 0 && arr[1][2] == 0 && arr[2][2] == 0 && arr[3][2] == 0)
				{
					right_column = right_column - 1;
				}
				if (arr[0][1] == 0 && arr[1][1] == 0 && arr[2][1] == 0 && arr[3][1] == 0)
				{
					right_column = right_column - 1;
				}
				if (baser_column + right_column+1 < cols)
				{
					for (int i = 0; i < row_bottom; i++)
					{
						if (arr[i][right_column != 0])
						{
							if (board[baser_row - row_bottom + i][baser_column + right_column + 1] != 0)
							{
								right_allow = 0;
							}
						}
					}
				}
				if (baser_column + right_column + 1 < cols && right_allow==1)  //if allow is valid move right piece
				{
					for (int i = baser_row - row_bottom, h = 0; i < baser_row + 1; i++, h++)
					{
						for (int j = baser_column, k = 0; j < baser_column + 4; j++, k++)
						{
							if (arr[h][k] != 0)
							{
								board[i][j] = 0;
							}
						}
					}
					baser_column = baser_column + 1;
					for (int i = baser_row - row_bottom, h = 0; i < baser_row + 1; i++, h++)
					{
						for (int j = baser_column, k = 0; j < baser_column + 4; j++, k++)
						{
							if (arr[h][k] != 0)
							{
								board[i][j] = arr[h][k];
							}
						}
					}
				}
				gotoxy(0, 0);
				this->draw_board();
				Sleep(300);


			}
			//left
			if (key == 'l')
			{
				int left__allow = 1;            //check if left allow is valid
				if (baser_column - 1 >= 0)
				{
					for (int i = baser_row - row_bottom,h=0; i < baser_row + 1; i++,h++)
					{
						if (arr[h][0] != 0)
						{
							if (board[i][baser_column - 1] != 0)
							{
								left__allow = 0;
							}
						}
					}
				}
				if (baser_column - 1 >= 0 && left__allow == 1)  //if allow is valid move piece to left
				{
					for (int i = baser_row - row_bottom, h = 0; i < baser_row + 1; i++, h++)
					{
						for (int j = baser_column, k = 0; j < baser_column + 4; j++, k++)
						{
							if (arr[h][k] != 0)
							{
								board[i][j] = 0;
							}
						}
					}
					baser_column = baser_column - 1;
					for (int i = baser_row - row_bottom, h = 0; i < baser_row + 1; i++, h++)
					{
						for (int j = baser_column, k = 0; j < baser_column + 4; j++, k++)
						{
							if (arr[h][k] != 0)
							{
								board[i][j] = arr[h][k];
							}
						}
					}
				}
				gotoxy(0, 0);
				this->draw_board();
				Sleep(400);
			}//
			//notgetkey
			if (!getKey())
			{
				int advance = 1;
				int arrayfirst = 3;        //to check the piece column 0  least bottom element
				int arraysecond = 3;      //to check the piece column 1  least bottom element
				int arraythird = 3;       //to check the piece column 2  least bottom element
				int arrayforth = 3;      //to check the piece column 3  least bottom element
				if (arr[3][0] == 0)
				{
					arrayfirst = arrayfirst - 1;
					if (arr[2][0] == 0)
					{
						arrayfirst = arrayfirst - 1;
						if (arr[1][0] == 0)
						{
							arrayfirst = arrayfirst - 1;
							if (arr[0][0] == 0)
							{
								arrayfirst = arrayfirst - 1;
							}
						}
					}
				}
				if (arr[3][1] == 0)
				{
					arraysecond = arraysecond - 1;
					if (arr[2][1] == 0)
					{
						arraysecond = arraysecond - 1;
						if (arr[1][1] == 0)
						{
							arraysecond = arraysecond - 1;
							if (arr[0][1] == 0)
							{
								arraysecond = arraysecond - 1;
							}
						}
					}
				}
				if (arr[3][2] == 0)
				{
					arraythird = arraythird - 1;
					if (arr[2][2] == 0)
					{
						arraythird = arraythird - 1;
						if (arr[1][2] == 0)
						{
							arraythird = arraythird - 1;
							if (arr[0][2] == 0)
							{
								arraythird = arraythird - 1;
							}
						}
					}
				}
				if (arr[3][3] == 0)
				{
					arrayforth = arrayforth - 1;
					if (arr[2][3] == 0)
					{
						arrayforth = arrayforth - 1;
						if (arr[1][3] == 0)
						{
							arrayforth = arrayforth - 1;
							if (arr[0][3] == 0)
							{
								arrayforth = arrayforth - 1;
							}
						}
					}
				}			
				int g = baser_row - row_bottom;
				if (arrayfirst >= 0)
				{
					if (arr[arrayfirst][0] != 0)
					{
						if ((g + arrayfirst + 1) < rows)
							if (board[g + arrayfirst][baser_column] != 0)
							{
								if ((g + arrayfirst + 1) < rows)
									if (board[g + arrayfirst + 1][baser_column] != 0)
									{
										game = 1;
										advance = 0;
										break;
									}
							}
					}
				}
				g = baser_row - row_bottom;
				if (arraysecond >= 0)
				{
					if (arr[arraysecond][1] != 0)
					{
						if ((g + arraysecond + 1) < rows)
							if (board[g + arraysecond][baser_column + 1] != 0)
							{
								if (board[g + arraysecond + 1][baser_column + 1] != 0)
								{
									game = 1;
									advance = 0;
									break;
								}
							}
					}
				}
				g = baser_row - row_bottom;
				if (arraythird >= 0)
				{
					if (arr[arraythird][2] != 0)
					{
						if ((g + arraythird + 1) < rows)
							if (board[g + arraythird][baser_column + 2] != 0)
							{
								if (board[g + arraythird + 1][baser_column + 2] != 0)
								{
									game = 1;
									advance = 0;
									break;
								}
							}
					}
				}
				g = baser_row - row_bottom;
				if (arrayforth >= 0)
				{
					if (arr[arrayforth][3] != 0)
					{
						if ((g + arrayforth + 1) < rows)
							if (board[g + arrayforth][baser_column + 3] != 0)
							{
								if (board[g + arrayforth + 1][baser_column + 3] != 0)
								{
									game = 1;
									advance = 0;
									break;
								}
							}
					}
				}
				if (baser_row + 1 >= rows)
				{
					advance = 0;
					game = 1;
					break;
				}
				if (advance == 1 && baser_row + 1 < rows)
				{
					for (int i =baser_row-row_bottom,h=0; i < baser_row+1; i++,h++)
					{
						for (int j = baser_column,k=0; j < baser_column+4; j++,k++)
						{
							if (arr[h][k] != 0)
							{
								board[i][j] = 0;
							}
						}
					}
					baser_row = baser_row + 1;
					for (int i = baser_row - row_bottom, h = 0; i < baser_row + 1; i++, h++)
					{
						for (int j = baser_column, k = 0; j < baser_column + 4; j++, k++)
						{
							if (arr[h][k] != 0)
							{
								board[i][j] = arr[h][k];
							}
						}
					}

				}
				gotoxy(0, 0);
				this->draw_board();
				Sleep(300);
			}//
		}
		score = score + (RemoveLines())*10;
		game = 0;
		delete p;		
		baser_row = 3;
		baser_column = 3;
		if (board[0][baser_column] != 0 && board[0][baser_column + 1]!=0)
		{
			filled = 1;
			break;
		}
		if (typer == 3)
		{
			if (board[0][baser_column] != 0 && board[0][baser_column + 1] != 0 && board[0][baser_column+2]!=0)
			{
				filled = 1;
				break;
			}
		}

	}
	cls();
	Sleep(300);
	gotoxy(0, 0);
	cout << "no space left for new piece game ends" << endl;
	cout << "Your score is " << score; //showing score
	
}
Board::~Board()
{
	//simply deallocating memeory used
	for (int i = 0; i < rows; i++)
	{
		delete board[i];
	}
	delete[] board;
	for (int i = 0; i < 4; i++)
	{
		delete temp[i];
		delete arr[i];
	}
	delete [] temp;
	delete[] arr;
	this->baser_column = 0;
	this->baser_row = 0;
	this->cols = 0;
	this->cols = 0;
	this->right_column = 0;
	this->rows = 0;
	this->row_bottom = 0;
	this->score = 0;
	this->shape = 0;
	this->temp_bottom = 0;
	this->typer = 0;
}
