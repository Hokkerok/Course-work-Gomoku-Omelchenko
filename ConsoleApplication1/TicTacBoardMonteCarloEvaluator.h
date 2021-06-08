#pragma once
#include "TicTacBoard.h"
#include "pch.h"

class TicTacBoardMonteCarloEvaluator
{
private:
	TicTacBoard* board;
	int numGames;
	int numVictories;
	int numLosses;
	int numDraw;
	unsigned int xpos, ypos;
	CellType startCellType;
public:
	TicTacBoardMonteCarloEvaluator(TicTacBoard* board, int numIterations, CellType startCellType, unsigned int xpos, unsigned int ypos);
	//TicTacBoardMonteCarloEvaluator(TicTacBoard* board);
	~TicTacBoardMonteCarloEvaluator();
	void EvaluateBoard();
	void Evaluate();
	int GetVictories() { return numVictories; }
	int GetLosses() { return numLosses; }
	int GetDraw() { return numDraw; }
	int GetXPos() { return xpos; }
	int GetYPos() { return ypos; }
};
