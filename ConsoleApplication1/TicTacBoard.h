#pragma once
#include"CellType.h" 
#include <SFML/Graphics.hpp>
using namespace sf;

class TicTacBoard
{ 
private:
	unsigned int boardsize;// размер доски
	CellType** cells;//количество ячеек
	bool bVictory = false;//победка
	bool IsRowMade(unsigned int row);
	bool IsColumnMade(unsigned int col);
	bool IsDiagMade();
	bool IsBoardFull();
	CellType Type;
public:
	TicTacBoard(unsigned int size); //конструктор которому мы даем его размеры
	TicTacBoard(TicTacBoard* board);// перегрузка которой мы даем ссылку на доску
	virtual~TicTacBoard();//деструктор
	void Show(RenderWindow& window);//показать доску
	void SetCell(unsigned int xpos, unsigned int ypos, CellType ct);//установить положение х или о
	bool CheckLegal(unsigned int xpos, unsigned int ypos);//проверка на правила игры
	bool CheckEndCondition();//проверка на завершение игры
	bool IsVictory(CellType& Type);//победка
	bool CheckX(unsigned int xpos, unsigned int ypos);


};

