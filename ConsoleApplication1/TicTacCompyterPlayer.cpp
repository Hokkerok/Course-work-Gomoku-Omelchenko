#include "pch.h"
#include "TicTacCompyterPlayer.h"
#include <vector>
#include "TicTacBoard.h"
#include "CellType.h"








TicTacCompyterPlayer::TicTacCompyterPlayer()
{
}

TicTacCompyterPlayer::~TicTacCompyterPlayer()
{
}


bool TicTacCompyterPlayer::MakeMove()
{
	vector <TicTacBoardMonteCarloEvaluator*>evaluators;
	for (unsigned int i = 0; i < 15; i++)
		for (unsigned int j = 0; j < 15; j++)
			if (this->board->CheckLegal(j, i))
			{
				this->board->SetCell(j, i, this->cellType);
				evaluators.push_back(new TicTacBoardMonteCarloEvaluator(this->board, 1000, (this->cellType == CellType_X) ? CellType_O : CellType_X, j, i));
				this->board->SetCell(j, i, CellType_Empty);
			}
	for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++)
		(*evaluator)->Evaluate();

	int biggestVictories = -1;

	for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++)
		if (this->cellType == CellType_X)
		{
			if ((*evaluator)->GetVictories() > biggestVictories)
				biggestVictories = (*evaluator)->GetVictories();
		}
		else
		{
			if ((*evaluator)->GetLosses() > biggestVictories)
				biggestVictories = (*evaluator)->GetLosses();
		}

	vector <TicTacBoardMonteCarloEvaluator*>biggestWinEvaluators;
	for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++)
	{
		int numVictories;
		if (this->cellType == CellType_X)
			numVictories = (*evaluator)->GetVictories();
		else
			numVictories = (*evaluator)->GetLosses();
		if (numVictories == biggestVictories)
			biggestWinEvaluators.push_back((*evaluator));

	}
	//и еще ниже строкой до меня уже даже не компилятор а комп добеался
	this->board->SetCell(biggestWinEvaluators[0]->GetXPos(), biggestWinEvaluators[0]->GetYPos(), this->cellType);
	for (auto evaluator = evaluators.begin(); evaluator != evaluators.end(); evaluator++)
		delete (*evaluator);
	evaluators.clear();
	biggestWinEvaluators.clear();
	return true;
}









/*bool TicTacCompyterPlayer::IsRowMadeThire(unsigned int row)
{
	int numX = 0;
	for (unsigned int i = 0; i < 15; i++)
	{
		if (this->board->CheckX(row, i))

		{
			for (unsigned j = 0; j < 3; j++)
			{
				if (this->board->CheckX(row, (i + j)))
					numX++;
				else
				{
					numX = 0;
					break;
				}
			}
			if ((numX == 3))
				break;
		}

		if ((numX == 3))
		{

			return true;
		}
		return false;
	}
}

	bool TicTacCompyterPlayer::IsColumnMadeThire(unsigned int col)
	{
		int numX = 0;
		for (unsigned int i = 0; i < 15; i++)
		{

			if (this->board->CheckX(i, col))
				
			{//сюда  надо ограничитель
				for (unsigned j = 0; j < 3; j++)
				{
					if (this->board->CheckX((i + j), col))
						
						numX++;
					else
					{
						numX = 0;
						break;
					}

				}
				if ((numX == 3))
					break;
			}
		}

		if ((numX == 3))
		{

			return true;
		}
		return false;
	}


bool TicTacCompyterPlayer::IsDiagMadeThire()
{
	int numX = 0;//горизонталь с лево на право
	for (unsigned int i = 0; i < 15; i++)
	{

		if (this->board->CheckX(i, i))
		{
			for (unsigned j = 0; j < 3; j++)
			{
				if (this->board->CheckX((i + j), (i + j)))
					
					numX++;
				else
				{
					numX = 0;
					break;
				}
			}
			if ((numX == 3))
				break;
		}
	}


	numX = 0;
	for (unsigned int i = 0; i < 15; i++)//горизонталь с права на лево
	{
	
		if (this->board->CheckX((i), (15 - i - 1)))
			
		{//сюда  надо ограничитель
			for (unsigned j = 0; j < 3; j++)
			{
				if (this->board->CheckX((i - j), ((15 - i - 1) - j)))
					
					numX++;
				else
				{
					numX = 0;
					break;
				}

			}
			if ((numX == 3))
				break;
		}
	}


	if ((numX == 3))
	{
		return true;
	}
	return false;
}


int TicTacCompyterPlayer::CheckUslovia()
{
	for (unsigned int i = 0; i < 15; i++)
	{
		if (IsRowMadeThire(i) )
	
			return 1;
		if (IsColumnMadeThire(i))
			return 2;
	}
	if (IsDiagMadeThire())
		return 3;

	return 4;
}

bool TicTacCompyterPlayer::MakeMove()
{ 
	for (unsigned int i = 0; i < 15; i++)//проебегаю весь массив
		for (unsigned int j = 0; j < 15; j++)
		{
			if (this->board->CheckX(i, j))
			{
				if (CheckUslovia() == 1)
				{
					if (this->board->CheckLegal(i, j+4))
					{
						this->board->SetCell(i, j+4, this->cellType);
						return true;
					}
				}
				if (CheckUslovia() == 2)
				{
					if (this->board->CheckLegal(i+4, j))
					{
						this->board->SetCell(i+4, j , this->cellType);
						return true;
					}
				}

				if (CheckUslovia() == 3)
				{
					if (this->board->CheckLegal(i + 4, i + 4))
					{
						this->board->SetCell(i + 4, j + 4, this->cellType);
						return true;
					}
					if (this->board->CheckLegal(i + 4, i + 4)==false)
						if (this->board->CheckLegal(i - 4, i - 4))
						{
							this->board->SetCell(i - 4, j - 4, this->cellType);
							return true;
						}
				}
				else {
					int row, col;
					row = (int)rand() % (15 - i);
					col = (int)rand() % (15 - j);
					if (this->board->CheckLegal(i + row, j + col))
					{
						this->board->SetCell(i + row, j + col, this->cellType);
						return true;
					}
					return false;
				}

			}
		}
}*/
	