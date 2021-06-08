#pragma once
#include "TicTacBoard.h"
#include "TicTacPlayer.h"


class TicTacManager
{
private:
	TicTacBoard* board;
	TicTacPlayer* player1;
	TicTacPlayer* player2;
	TicTacPlayer* currentPlayer;
	bool bGameFinished=false;
public:
	TicTacManager();//конструктор
	virtual~TicTacManager();//деструктор
	bool Init();//распределение игроков и выбор какими игроки будут комп или чел а так же сказать первым ходит игрок 1
	void ShowBoard();//отрисовка доски
	void MakeMove();//вызов отрисвоки доски и проверка на ебланский ход проверка на завершение игры + смена игрока 1 на 2 или 2 на 1
	bool IsGameFinished();//конец игры

};

