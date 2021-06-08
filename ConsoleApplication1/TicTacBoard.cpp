#include "pch.h"
#include "TicTacBoard.h"



using namespace std;


TicTacBoard::TicTacBoard(unsigned int size)//����������� �������� �� ���� ��� �������
{
	this->boardsize = size;//������� ��� ������ ����� ����� ���� ��� �� ���� ������������
	cells = new CellType * [size];//�������� ����� ��� ���������� �������� �����
	for (unsigned int i = 0; i < size; i++)//������� ��������� ��
		cells[i] = new CellType[size];
	for (unsigned int i = 0; i < size; i++)
		for (unsigned int j = 0; j < size; j++)
			cells[i][j] = CellType_Empty;
}

TicTacBoard::TicTacBoard(TicTacBoard* board)// ���������� ������� �� ���� ������ �� ����� ��� �� � ��� ��� ���� ����� �� ����� ������� ����� �� ������ ������
{
	this->boardsize = board->boardsize;//������� ��� ������ ����� ����� ��� ������ ������
	cells = new CellType * [boardsize];//�������� ������ ����������  ������ 
	for (unsigned int i = 0; i < boardsize; i++)//������������ �������
		cells[i] = new CellType[boardsize];
	for (unsigned int i = 0; i < boardsize; i++)
		for (unsigned int j = 0; j < boardsize; j++)
			cells[i][j] = board->cells[i][j];


}
;

TicTacBoard::~TicTacBoard() //���������� 
{
	for (unsigned int i = 0; i < boardsize; i++)
		delete[]cells[i];
	delete[]cells;
};

void  TicTacBoard::Show()//�� ��� �� �����
{
	cout << " ";
	for (int j = 0; j < boardsize; j++)
		cout << j << " ";
	cout << endl;
	for (unsigned int i = 0; i < boardsize; i++)
	{
		cout << i << " ";
		for (unsigned int j = 0; j < boardsize; j++)
		{
			switch (cells[i][j])
			{
			case CellType_X:
				cout << "X";
				break;
			case CellType_O:
				cout << "O";
				break;
			case CellType_Empty:
				cout << "-";
				break;
			}
			cout << " ";
		}
		cout << endl;
	}
};

void TicTacBoard::SetCell(unsigned int xpos, unsigned int ypos, CellType ct)//��������� � ���������� ������ � ��� �
{
	cells[ypos][xpos] = ct;
};

bool TicTacBoard::CheckLegal(unsigned int xpos, unsigned int ypos)// �������� �� ����������� ����
{
	if ((xpos < 0) || (xpos > boardsize - 1) || (ypos < 0) || (ypos > boardsize - 1))
		return false;
	return ((cells[ypos][xpos] == CellType_Empty));//���� ��� �� �������� �� ������������� � ��� �
}

bool TicTacBoard::IsRowMade(unsigned int row)
{
	int numX = 0, numO = 0;
	for (unsigned int i = 0; i < 11; i++)
	{
		if (cells[row][i] == CellType_O)
		{

			for (unsigned j = 0; j < 5; j++)
			{
					if (cells[row][i + j] == CellType_O)
						numO++;
					else
					{
						numO = 0;
						break;
					}
				
			}
			if ((numO == 5))
				break;
		}


		if (cells[row][i] == CellType_X)
		{//����  ���� ������������

			for (unsigned j = 0; j < 5; j++)
			{

					if (cells[row][i + j] == CellType_X)
						numX++;
					else
					{
						numX = 0;
						break;
					}
				

			}
			if ((numX == 5))
				break;
		}		

	}

	if ((numX == 5) || (numO == 5))
	{
		bVictory = true;
		return true;
	}
	return false;
}

bool TicTacBoard::IsColumnMade(unsigned int col)
{
	int numX = 0, numO = 0;
	for (unsigned int i = 0; i < 11; i++)
	{
		if (cells[i][col] == CellType_O)
		{
			for (unsigned j = 0; j < 5; j++)
			{

					if (cells[i + j][col] == CellType_O)
						numO++;

					else
					{
						numO = 0;
						break;
					}
			
			}
			if ((numO == 5))
				break;
		}


		if (cells[i][col] == CellType_X)
		{//����  ���� ������������

			for (unsigned j = 0; j < 5; j++)
			{

					if (cells[i + j][col] == CellType_X)
						numX++;
					else
					{
						numX = 0;
						break;
					}
				

			}
			if ((numX == 5))
				break;
		}

	}

	if ((numX == 5) || (numO == 5))
	{
		bVictory = true;
		return true;
	}
	return false;
}

bool TicTacBoard::IsDiagMade()
{
	int numX = 0, numO = 0;//����������� � ���� �� �����
	for (unsigned int i = 0; i < 11; i++)
	{
		if (cells[i][i] == CellType_O)
		{
			for (unsigned j = 0; j < 5; j++)
			{

					if (cells[i + j][i + j] == CellType_O)
						numO++;
					else
					{
						numO = 0;
						break;
					}

			}
			if ((numO == 5))
				break;
		}
		if (cells[i][i] == CellType_X)
		{
			for (unsigned j = 0; j < 5; j++)
			{

					if (cells[i + j][i + j] == CellType_X)
						numX++;
					else
					{
						numX = 0;
						break;
					}

			}
			if ((numX == 5))
				break;
		}
	}


		numX = numO = 0;
		for (unsigned int i = 0; i < 11; i++)//����������� � ����� �� ����
		{
			if (cells[i][boardsize - i - 1] == CellType_O)
			{//����  ���� ������������
				for (unsigned j = 0; j < 5; j++)
				{

						if (cells[i + j][(11 - i - 1) + j] == CellType_O)
							numX++;
						else
						{
							numX = 0;
							break;
						}
					}

				
				if ((numX == 5))
					break;
			}
			if (cells[i][11 - i - 1] == CellType_X)
			{//����  ���� ������������
				for (unsigned j = 0; j < 5; j++)
				{

						if (cells[i + j][(11 - i - 1) + j] == CellType_X)
							numX++;
						else
						{
							numX = 0;
							break;
						}
					}

				
				if ((numX == 5))
					break;
			}

		}
	
	
	if ((numX == 5) || (numO == 5))
	{
		bVictory = true;
		return true;
	}
	return false;
}


bool TicTacBoard::CheckEndCondition()
{

	for (unsigned int i = 0; i < 15; i++)
	{
		if (IsRowMade(i) || IsColumnMade(i))
			return true;
	}
	if (IsDiagMade())
		  return true;

	return false;
}

	bool TicTacBoard::IsVictory()
	{
		return bVictory;
	}

	bool TicTacBoard::CheckX(unsigned int xpos, unsigned int ypos)
	{
		if (cells[ypos][xpos]== CellType_X)
		{
			return true;
		}
		return false;
	}





