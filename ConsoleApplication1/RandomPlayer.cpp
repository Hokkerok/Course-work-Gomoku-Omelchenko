#include "RandomPlayer.h"


RandomPlayer::RandomPlayer()
{
}

RandomPlayer::~RandomPlayer()
{
}


int RandomPlayer::MakeMove()
{
	unsigned int row, col;

	row = (unsigned int)(rand() % 15);
	col = (unsigned int)(rand() % 15);

	if (this->board->CheckLegal(col, row))
	{
		this->board->SetCell(col, row, this->cellType);
		return 1;
	}

	return 0;
}
