#pragma once
#include "TicTacPlayer.h"
#include "TicTacBoardMonteCarloEvaluator.h"
class TicTacCompyterPlayer:public TicTacPlayer
{private:
	
public:
	TicTacCompyterPlayer();
	virtual~TicTacCompyterPlayer();
	virtual int MakeMove();//движение компудахтера
		//функции для анализа игровой ситуации благополчно спизжено из боарда
//	bool IsRowMadeThire(unsigned int row);
	//bool IsColumnMadeThire(unsigned int col);
//	bool IsDiagMadeThire();
//int CheckUslovia();

};

