#include "RandomPlayer.h"


RandomPlayer::RandomPlayer()
{
}

RandomPlayer::~RandomPlayer()
{
}


bool RandomPlayer::MakeMove()
{
	unsigned int row, col;

	row = (unsigned int)(rand() % 15);
	col = (unsigned int)(rand() % 15);

	if (this->board->CheckLegal(col, row))
	{
		this->board->SetCell(col, row, this->cellType);
		return true;
	}

	return false;
}
