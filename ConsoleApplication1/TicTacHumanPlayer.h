#pragma once
#include "pch.h"
#include "TicTacBoard.h"
#include "TicTacPlayer.h"
#include "TicTacCompyterPlayer.h"


class TicTacHumanPlayer:public TicTacPlayer//����������� �� ������ ������
{
public:
	int col = 15, row = 15;
	TicTacHumanPlayer();//�����������
	virtual~TicTacHumanPlayer();//����������
	int MakeMove();//������ ����� ���������
	virtual void SetHumanColsRows(bool& closed);
};


