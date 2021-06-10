#pragma once
#include"CellType.h" 
#include <SFML/Graphics.hpp>
using namespace sf;

class TicTacBoard
{ 
private:
	unsigned int boardsize;// ������ �����
	CellType** cells;//���������� �����
	bool bVictory = false;//�������
	bool IsRowMade(unsigned int row);
	bool IsColumnMade(unsigned int col);
	bool IsDiagMade();
	bool IsBoardFull();
	CellType Type;
public:
	TicTacBoard(unsigned int size); //����������� �������� �� ���� ��� �������
	TicTacBoard(TicTacBoard* board);// ���������� ������� �� ���� ������ �� �����
	virtual~TicTacBoard();//����������
	void Show(RenderWindow& window);//�������� �����
	void SetCell(unsigned int xpos, unsigned int ypos, CellType ct);//���������� ��������� � ��� �
	bool CheckLegal(unsigned int xpos, unsigned int ypos);//�������� �� ������� ����
	bool CheckEndCondition();//�������� �� ���������� ����
	bool IsVictory(CellType& Type);//�������
	bool CheckX(unsigned int xpos, unsigned int ypos);


};

