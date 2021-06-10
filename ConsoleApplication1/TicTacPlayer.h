#pragma once
#include "pch.h"
#include "TicTacBoard.h"

class TicTacPlayer
{
protected:
	TicTacBoard* board;//� ������ ���� ����� � ������� �� ���������������
	CellType cellType;// ��� � ��� � �� ������� �� ������
	string name;//� �� ��� ��� �����
	RenderWindow* window;
public:
	TicTacPlayer();//����������� 
	virtual~TicTacPlayer();//�����������
	void SetupPlayer(string name, CellType cellType);//���������� ������ ��� ����������
	void SetBoard(TicTacBoard* board);//��������� ��� �� �����
	virtual int MakeMove() = 0;
	string GetName();
	void SetWindow(RenderWindow* window);
};

