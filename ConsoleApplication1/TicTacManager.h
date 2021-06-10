#pragma once
#include "TicTacBoard.h"
#include "TicTacPlayer.h"
#include "SFML/Graphics.hpp"
using namespace sf;

class TicTacManager
{
private:
	TicTacBoard* board;
	TicTacPlayer* player1;
	TicTacPlayer* player2;
	TicTacPlayer* currentPlayer;
	RenderWindow* window;
	bool bGameFinished=false;
public:
	TicTacManager();//конструктор
	virtual~TicTacManager();//деструктор
	bool Init();//распределение игроков и выбор какими игроки будут комп или чел а так же сказать первым ходит игрок 1
	void ShowBoard();//отрисовка доски
	void MakeMove(bool& closed);//вызов отрисвоки доски и проверка на ебланский ход проверка на завершение игры + смена игрока 1 на 2 или 2 на 1
	bool IsGameFinished();//конец игры
	void SetWindow(RenderWindow* window);
};

