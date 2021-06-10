#include "pch.h"
#include <iostream>
#include "TicTacManager.h"
#include "SFML/Graphics.hpp"
using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(644, 695), "Homoku_15x15");
	sf::Event event;

    setlocale(LC_ALL, "Russian");
    TicTacManager manager;
	manager.SetWindow(&window);

	if (!manager.Init())
	{
		return 0;
	}
	window.clear();

	bool closed = false;

	do
	{
		manager.MakeMove(closed);
		if (closed == true)
			break;
	} while (!manager.IsGameFinished());

	if (!closed)
		while (window.isOpen())
		{
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}
		}

	window.close();
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
