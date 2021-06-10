#include "TicTacHumanPlayer.h"
#include "SFML/Graphics.hpp"

TicTacHumanPlayer::TicTacHumanPlayer()
{

}

TicTacHumanPlayer::~TicTacHumanPlayer()
{

}


void TicTacHumanPlayer::SetHumanColsRows(bool& closed)
{
    Zanavo: // <-----
	bool doing = true;
	bool rowscolsselected = false;
	int xpos, ypos;
	sf::Event event;

	while (doing)
	{

		Vector2i MousePos = Mouse::getPosition(*window);//�������� ����� �������

		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				closed = true;
				return;
			}

			if (event.type == Event::MouseButtonPressed) //���� ������ ������� ����
				if (event.key.code == Mouse::Left) //� ������ �����
				{
					xpos = MousePos.x; //�������� ���������� ������� ������� �
					ypos = MousePos.y; //� Y
					rowscolsselected = true;
				}
		}
		if (rowscolsselected)
		{
			doing = false;
			break;
		}
	}

	if (rowscolsselected)
	{
		for (int i = 0; i < 15; i++)
			if (((8 + i * 42) <= xpos) && (xpos <= (47 + i * 42)))
				col = i;

		for (int j = 0; j < 15; j++)
			if (((59 + j * 42) <= ypos) && (ypos <= (106 + j * 42)))
				row = j;
	}
	if (row == 15 || col == 15)
		goto Zanavo; // ----->
}

int TicTacHumanPlayer::MakeMove()
{
	bool closed = false;
	SetHumanColsRows(closed);
	if (closed)
		return 2;

	if (this->board->CheckLegal(col,row))//�������� �� ������
	{
		this->board->SetCell(col, row, this->cellType);//��������� � ��� � �� �����
		return 1;
	}

	return 0;
}



