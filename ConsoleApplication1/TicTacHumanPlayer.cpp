#include "TicTacHumanPlayer.h"

TicTacHumanPlayer::TicTacHumanPlayer()
{

}

TicTacHumanPlayer::~TicTacHumanPlayer()
{

}


bool TicTacHumanPlayer::MakeMove()
{
	unsigned int row, col;//прнимаемаемые значения положения на доске
	cout << "Игрок: " << name << ", ваш ход..." << endl;
	cout << "Введите строку: ";
	cin >> row;
	cout << "Введите столбец: ";
	cin >> col;

	if (this->board->CheckLegal(col,row))//проверка на дебила
	{
		this->board->SetCell(col, row, this->cellType);//устаноука х или о на доску
		return true;
	}

	return false;
}


