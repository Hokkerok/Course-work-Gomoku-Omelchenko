#include "TicTacHumanPlayer.h"

TicTacHumanPlayer::TicTacHumanPlayer()
{

}

TicTacHumanPlayer::~TicTacHumanPlayer()
{

}


bool TicTacHumanPlayer::MakeMove()
{
	unsigned int row, col;//������������� �������� ��������� �� �����
	cout << "�����: " << name << ", ��� ���..." << endl;
	cout << "������� ������: ";
	cin >> row;
	cout << "������� �������: ";
	cin >> col;

	if (this->board->CheckLegal(col,row))//�������� �� ������
	{
		this->board->SetCell(col, row, this->cellType);//��������� � ��� � �� �����
		return true;
	}

	return false;
}


