#pragma once
#include "TicTacPlayer.h"
#include "TicTacBoardMonteCarloEvaluator.h"
class TicTacCompyterPlayer:public TicTacPlayer
{private:
	
public:
	TicTacCompyterPlayer();
	virtual~TicTacCompyterPlayer();
	virtual bool MakeMove();//�������� ������������
		//������� ��� ������� ������� �������� ����������� �������� �� ������
//	bool IsRowMadeThire(unsigned int row);
	//bool IsColumnMadeThire(unsigned int col);
//	bool IsDiagMadeThire();
//int CheckUslovia();

};

