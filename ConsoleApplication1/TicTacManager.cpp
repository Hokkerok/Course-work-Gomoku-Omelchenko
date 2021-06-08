#include "pch.h"
#include "TicTacManager.h"
#include "TicTacHumanPlayer.h"
#include "TicTacCompyterPlayer.h"

TicTacManager::TicTacManager()//�����������
{

};

TicTacManager::~TicTacManager()//����������
{
	delete this->player2;
	delete this->player1;
	delete this->board;
};

bool TicTacManager::Init()//������������� ������� � ����� ������ ������ ����� ���� ��� ��� � ��� �� ������� ������ ����� ����� 1
{
	unsigned int boardsize=15;
	string playerName;
	int playertype;
	this->board = new TicTacBoard(boardsize);

	cout << "������� ��� ������ #1 (1-�������, ����� ������ ����� - ���������): ";
	cin >> playertype;
	if (playertype==1)
	  this->player1= new TicTacHumanPlayer();
	else
		this->player1 = new TicTacCompyterPlayer();
	cout << "������� ��� ������ #2 (1-�������, ����� ������ ����� - ���������): ";
	cin >> playertype;
	if (playertype == 1)
		this->player2 = new TicTacHumanPlayer();
	else
		this->player2 = new TicTacCompyterPlayer();

	cin.ignore();
	cout << "������� ��� ������ ��������� X: ";
	getline(cin, playerName);
	player1->SetupPlayer(playerName, CellType_X);

	cout << "������� ��� ������ ��������� O: ";
	getline(cin, playerName);
	player2->SetupPlayer(playerName, CellType_O);

	player1->SetBoard(this->board);
	player2->SetBoard(this->board);
	currentPlayer = player1;
	return true;
}

void TicTacManager :: ShowBoard()//��������� �����
{
	this->board->Show();
}

bool TicTacManager::IsGameFinished()//����� ����
{
	return bGameFinished;
}


void TicTacManager::MakeMove()//����� ��������� ����� � �������� �� ��������� ��� �������� �� ���������� ���� + ����� ������ 1 �� 2 ��� 2 �� 1
{
	ShowBoard();
	while (!currentPlayer->MakeMove()) {
		cout << "������������ ���, ���������� ��� ���" << endl;
		ShowBoard();
	}
	if (this->board->CheckEndCondition())
	{
		if (this->board->IsVictory())
			cout << "�����" << currentPlayer->GetName() << " �������!" << endl;
		else
			cout << "�����!" << endl;
		this->bGameFinished = true;
		ShowBoard();
		return;
	}
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

