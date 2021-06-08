#pragma once
#include "TicTacBoard.h"
#include "TicTacPlayer.h"


class TicTacManager
{
private:
	TicTacBoard* board;
	TicTacPlayer* player1;
	TicTacPlayer* player2;
	TicTacPlayer* currentPlayer;
	bool bGameFinished=false;
public:
	TicTacManager();//�����������
	virtual~TicTacManager();//����������
	bool Init();//������������� ������� � ����� ������ ������ ����� ���� ��� ��� � ��� �� ������� ������ ����� ����� 1
	void ShowBoard();//��������� �����
	void MakeMove();//����� ��������� ����� � �������� �� ��������� ��� �������� �� ���������� ���� + ����� ������ 1 �� 2 ��� 2 �� 1
	bool IsGameFinished();//����� ����

};

