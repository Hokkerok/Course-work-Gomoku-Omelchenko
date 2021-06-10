#pragma once
#include "pch.h"
#include "TicTacBoard.h"
#include "TicTacPlayer.h"
#include "TicTacCompyterPlayer.h"


class TicTacHumanPlayer:public TicTacPlayer//унаслодован от класса игрока
{
public:
	int col = 15, row = 15;
	TicTacHumanPlayer();//конструктор
	virtual~TicTacHumanPlayer();//деструктор
	int MakeMove();//игроку умеет двигаться
	virtual void SetHumanColsRows(bool& closed);
};


