#include "TicTacPlayer.h"

TicTacPlayer::TicTacPlayer()
{
}

TicTacPlayer::~TicTacPlayer()
{
}

void TicTacPlayer::SetupPlayer(string name, CellType cellType)//присвоение игроку его свойств
{
	this->name = name;
	this->cellType = cellType;
}

void TicTacPlayer::SetBoard(TicTacBoard* board)//понимание игрока что он на доске
{
	this->board = board;
}

string TicTacPlayer::GetName()//имя
{
	return this->name;
}
