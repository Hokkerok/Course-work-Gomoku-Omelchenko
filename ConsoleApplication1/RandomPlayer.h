#pragma once
#include "TicTacPlayer.h"
class RandomPlayer :public TicTacPlayer
{
public:
	RandomPlayer();
	virtual~RandomPlayer();
	virtual bool MakeMove();
};

