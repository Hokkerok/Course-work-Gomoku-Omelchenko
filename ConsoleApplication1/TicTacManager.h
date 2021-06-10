#pragma once
#include "TicTacBoard.h"
#include "TicTacPlayer.h"
#include "SFML/Graphics.hpp"
using namespace sf;

class TicTacManager
{
private:
	TicTacBoard* board;
	TicTacPlayer* player1;
	TicTacPlayer* player2;
	TicTacPlayer* currentPlayer;
	RenderWindow* window;
	bool bGameFinished=false;
public:
	TicTacManager();//�����������
	virtual~TicTacManager();//����������
	bool Init();//������������� ������� � ����� ������ ������ ����� ���� ��� ��� � ��� �� ������� ������ ����� ����� 1
	void ShowBoard();//��������� �����
	void MakeMove(bool& closed);//����� ��������� ����� � �������� �� ��������� ��� �������� �� ���������� ���� + ����� ������ 1 �� 2 ��� 2 �� 1
	bool IsGameFinished();//����� ����
	void SetWindow(RenderWindow* window);
};

