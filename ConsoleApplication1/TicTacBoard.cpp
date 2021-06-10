#include "pch.h"
#include "TicTacBoard.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;


TicTacBoard::TicTacBoard(unsigned int size)//конструктор которому мы даем его размеры
{
	this->boardsize = size;//говорим что размер доски равен тому что мы даои конструктору
	cells = new CellType * [size];//выделяем место под количество заданных ячеек
	for (unsigned int i = 0; i < size; i++)//циклами заполняем их
		cells[i] = new CellType[size];
	for (unsigned int i = 0; i < size; i++)
		for (unsigned int j = 0; j < size; j++)
			cells[i][j] = CellType_Empty;
}

TicTacBoard::TicTacBoard(TicTacBoard* board)// перегрузка которой мы даем ссылку на доску как бы у нас уже есть доска мы должы создать новую по основе старой
{
	this->boardsize = board->boardsize;//говорим что размер новой доски это размер старой
	cells = new CellType * [boardsize];//выделяем нужное количество  ячееек 
	for (unsigned int i = 0; i < boardsize; i++)//отрисовываем циклами
		cells[i] = new CellType[boardsize];
	for (unsigned int i = 0; i < boardsize; i++)
		for (unsigned int j = 0; j < boardsize; j++)
			cells[i][j] = board->cells[i][j];


}
;

TicTacBoard::~TicTacBoard() //деструктор 
{
	for (unsigned int i = 0; i < boardsize; i++)
		delete[]cells[i];
	delete[]cells;
};

void TicTacBoard::Show(RenderWindow& window)//то как мы ходим
{
	Texture TextureBoard1, TextureKamen1, TextureKamen2;
	Sprite Board1, KamenW, KamenB;

	TextureBoard1.loadFromFile("images/Board.jpg");
	TextureKamen1.loadFromFile("images/kamen_W.png");
	TextureKamen2.loadFromFile("images/kamen_B.png");
	Board1.setTexture(TextureBoard1);
	Board1.setPosition(0, 51);

	KamenW.setTexture(TextureKamen1);
	KamenB.setTexture(TextureKamen2);

	window.draw(Board1);

	for (int i = 0; i < boardsize; i++)
	{
		for (int j = 0; j < boardsize; j++)
		{
			switch (cells[i][j])
			{
			case CellType_X:
				KamenW.setPosition(13 + j * 42, 64 + i * 42);
				window.draw(KamenW);
				break;
			case CellType_O:
				KamenB.setPosition(13 + j * 42, 64 + i * 42);
				window.draw(KamenB);
				break;
			}
		}
	}

	window.display();
};

void TicTacBoard::SetCell(unsigned int xpos, unsigned int ypos, CellType ct)//установка в конкретную ячейку х или о
{
	this->Type = ct;
	cells[ypos][xpos] = ct;
};

bool TicTacBoard::CheckLegal(unsigned int xpos, unsigned int ypos)// проверка на првильность игры
{
	if ((xpos < 0) || (xpos > boardsize - 1) || (ypos < 0) || (ypos > boardsize - 1))
		return false;
	return ((cells[ypos][xpos] == CellType_Empty));//если все по правилам то устанваливаем х или о
}

bool TicTacBoard::IsRowMade(unsigned int row)
{
	int numX = 0, numO = 0;
	for (unsigned int i = 0; i < 11; i++)
	{
		if (cells[row][i] == CellType_O)
		{

			for (unsigned j = 0; j < 5; j++)
			{
					if (cells[row][i + j] == CellType_O)
						numO++;
					else
					{
						numO = 0;
						break;
					}
				
			}
			if ((numO == 5))
				break;
		}


		if (cells[row][i] == CellType_X)
		{//сюда  надо ограничитель

			for (unsigned j = 0; j < 5; j++)
			{

					if (cells[row][i + j] == CellType_X)
						numX++;
					else
					{
						numX = 0;
						break;
					}
				

			}
			if ((numX == 5))
				break;
		}		

	}

	if ((numX == 5) || (numO == 5))
	{
		bVictory = true;
		return true;
	}
	return false;
}

bool TicTacBoard::IsColumnMade(unsigned int col)
{
	int numX = 0, numO = 0;
	for (unsigned int i = 0; i < 11; i++)
	{
		if (cells[i][col] == CellType_O)
		{
			for (unsigned j = 0; j < 5; j++)
			{

					if (cells[i + j][col] == CellType_O)
						numO++;

					else
					{
						numO = 0;
						break;
					}
			
			}
			if ((numO == 5))
				break;
		}


		if (cells[i][col] == CellType_X)
		{//сюда  надо ограничитель

			for (unsigned j = 0; j < 5; j++)
			{

					if (cells[i + j][col] == CellType_X)
						numX++;
					else
					{
						numX = 0;
						break;
					}
				

			}
			if ((numX == 5))
				break;
		}

	}

	if ((numX == 5) || (numO == 5))
	{
		bVictory = true;
		return true;
	}
	return false;
}

bool TicTacBoard::IsDiagMade()////////////////////////////////сюда смотри ебло тупое
{
	int numX = 0, numO = 0;
	for ( int i = 0; i < 10; i++)
		for ( int j = 0; j < 10; j++)
		{
			if (cells[i][j] == CellType_O)
			for (int z = 0; z < 5; z++)
			{ 
				if (cells[i + z][j + z] == CellType_O)
					numO++;
				else 
				{
					numO = 0;
					break;
				}
			}
			if (cells[i][j] == CellType_X)
			for (int z = 0; z < 5; z++)
			{
				if (cells[i + z][j + z] == CellType_X)
					numX++;
				else
				{
					numX = 0;
					break;
				}
			}

		}


if ((numX == boardsize) || (numO == boardsize))
	{
		bVictory = true;
		return true;
	}



	numX = numO = 0;
	for (unsigned int i=4 ; i<15; i++)
		for (unsigned int j = 0; j < 10; j++)
		{
			if (cells[i][j] == CellType_O)
			for (unsigned int z = 0; z < 5; z++)
			{
				if (cells[i-z][j+z] == CellType_O)
					numO++;
				else
				{
					numO = 0;
					break;
				}
			}
			if (cells[i][j] == CellType_X)
			for (unsigned int z = 0; z < 5; z++)
			{
				if (cells[i - z][ j + z] == CellType_X)
					numX++;
				else
				{
					numX = 0;
					break;
				}
			}
		}

	
	
	
	
	
	
	
	
if ((numX == 5) || (numO == 5))
	{
		bVictory = true;
		return true;
	}
	return false;
}


bool TicTacBoard::CheckEndCondition()
{

	for (unsigned int i = 0; i < 15; i++)
	{
		if (IsRowMade(i) || IsColumnMade(i))
			return true;
	}
	if (IsDiagMade())
		  return true;

	return false;
}

	bool TicTacBoard::IsVictory(CellType& Type)
	{
		Type = this->Type;
		return bVictory;
	}

	bool TicTacBoard::CheckX(unsigned int xpos, unsigned int ypos)
	{
		if (cells[ypos][xpos]== CellType_X)
		{
			return true;
		}
		return false;
	}





