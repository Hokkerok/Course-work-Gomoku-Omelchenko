#pragma once
#include "pch.h"
#include "TicTacBoard.h"
#include "TicTacPlayer.h"
#include "TicTacCompyterPlayer.h"


class TicTacHumanPlayer:public TicTacPlayer//����������� �� ������ ������
{
public:
	TicTacHumanPlayer();//�����������
	virtual~TicTacHumanPlayer();//����������
	bool MakeMove();//������ ����� ���������
};


