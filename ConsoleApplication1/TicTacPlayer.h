#pragma once
#include "pch.h"
#include "TicTacBoard.h"

class TicTacPlayer
{
protected:
	TicTacBoard* board;//у игрока есть доска с которой он взаимодействует
	CellType cellType;// тип х или о за который он играет
	string name;//и то как его зовут
	RenderWindow* window;
public:
	TicTacPlayer();//конструктор 
	virtual~TicTacPlayer();//деструкторр
	void SetupPlayer(string name, CellType cellType);//присвоение игроку его параметров
	void SetBoard(TicTacBoard* board);//установке его на доске
	virtual int MakeMove() = 0;
	string GetName();
	void SetWindow(RenderWindow* window);
};

