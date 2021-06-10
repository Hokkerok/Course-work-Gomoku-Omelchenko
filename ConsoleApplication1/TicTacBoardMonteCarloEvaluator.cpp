
#include "CellType.h"
#include "TicTacBoardMonteCarloEvaluator.h"
#include "RandomPlayer.h"

TicTacBoardMonteCarloEvaluator::TicTacBoardMonteCarloEvaluator(TicTacBoard* board, int numIterations, CellType startCellType, unsigned int xpos, unsigned int ypos)
{
	this->board = board;
	this->numGames = numIterations;
	this->numDraw = 0;
	this->numVictories = 0;
	this->numLosses = 0;
	this->xpos = xpos;
	this->ypos = ypos;
	this->startCellType = startCellType;

}

TicTacBoardMonteCarloEvaluator::~TicTacBoardMonteCarloEvaluator()
{
}

void TicTacBoardMonteCarloEvaluator::EvaluateBoard()
{
	TicTacBoard* b = new TicTacBoard(this->board);
	RandomPlayer* player1 = new RandomPlayer();
	RandomPlayer* player2 = new RandomPlayer();
	RandomPlayer* currentPlayer;
	bool bGameFinished = false;

	player1->SetupPlayer("RandomX", CellType_X);
	player2->SetupPlayer("RandomO", CellType_O);
	player1->SetBoard(b);
	player2->SetBoard(b);
	currentPlayer = (this->startCellType == CellType_X) ? player1 : player2;
	CellType Type;

	if (b->CheckEndCondition())
	{
		if (b->IsVictory(Type))
			if (currentPlayer == player1)
				numLosses++;
			else
				numVictories++;
		else
			numDraw++;
		bGameFinished = true;
		return;
	}

	while (!bGameFinished)
	{
		while (currentPlayer->MakeMove() != 1);

		if (b->CheckEndCondition())
		{
			if (b->IsVictory(Type))
				if (currentPlayer == player1)
					numVictories++;
				else
					numLosses++;
			else
				numDraw++;
			bGameFinished = true;
		}
		currentPlayer = (currentPlayer == player1) ? player2 : player1;
	}
}

void TicTacBoardMonteCarloEvaluator::Evaluate()
{
	for (int i = 0; i < numGames; i++)
	{
		EvaluateBoard();
	}
}