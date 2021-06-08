#pragma once
#include "pch.h"
#include "TicTacBoard.h"
#include "TicTacPlayer.h"
#include "TicTacCompyterPlayer.h"


class TicTacHumanPlayer:public TicTacPlayer//унаслодован от класса игрока
{
public:
	TicTacHumanPlayer();//конструктор
	virtual~TicTacHumanPlayer();//деструктор
	bool MakeMove();//игроку умеет двигаться
};


