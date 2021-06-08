#include "pch.h"
#include "TicTacManager.h"
#include "TicTacHumanPlayer.h"
#include "TicTacCompyterPlayer.h"

TicTacManager::TicTacManager()//конструктор
{

};

TicTacManager::~TicTacManager()//деструктор
{
	delete this->player2;
	delete this->player1;
	delete this->board;
};

bool TicTacManager::Init()//распределение игроков и выбор какими игроки будут комп или чел а так же сказать первым ходит игрок 1
{
	unsigned int boardsize=15;
	string playerName;
	int playertype;
	this->board = new TicTacBoard(boardsize);

	cout << "Введите тип игрока #1 (1-Человек, любое другое число - Компьютер): ";
	cin >> playertype;
	if (playertype==1)
	  this->player1= new TicTacHumanPlayer();
	else
		this->player1 = new TicTacCompyterPlayer();
	cout << "Введите тип игрока #2 (1-Человек, любое другое число - Компьютер): ";
	cin >> playertype;
	if (playertype == 1)
		this->player2 = new TicTacHumanPlayer();
	else
		this->player2 = new TicTacCompyterPlayer();

	cin.ignore();
	cout << "Введите имя игрока играющего X: ";
	getline(cin, playerName);
	player1->SetupPlayer(playerName, CellType_X);

	cout << "Введите имя игрока играющего O: ";
	getline(cin, playerName);
	player2->SetupPlayer(playerName, CellType_O);

	player1->SetBoard(this->board);
	player2->SetBoard(this->board);
	currentPlayer = player1;
	return true;
}

void TicTacManager :: ShowBoard()//отрисовка доски
{
	this->board->Show();
}

bool TicTacManager::IsGameFinished()//конец игры
{
	return bGameFinished;
}


void TicTacManager::MakeMove()//вызов отрисвоки доски и проверка на ебланский ход проверка на завершение игры + смена игрока 1 на 2 или 2 на 1
{
	ShowBoard();
	while (!currentPlayer->MakeMove()) {
		cout << "Недопустимый ход, попробуйте еще раз" << endl;
		ShowBoard();
	}
	if (this->board->CheckEndCondition())
	{
		if (this->board->IsVictory())
			cout << "Игрок" << currentPlayer->GetName() << " победил!" << endl;
		else
			cout << "Ничья!" << endl;
		this->bGameFinished = true;
		ShowBoard();
		return;
	}
	currentPlayer = (currentPlayer == player1) ? player2 : player1;
}

