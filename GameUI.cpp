#include "GameUI.h"
#include <iostream>
#include <stdlib.h>

void GameUI::showMain()
{
	system("cls");   //清屏

	std::cout << "		Tetris Game		" << std::endl;
	std::cout << "1. start Game			" << std::endl;
	std::cout << "2. Help				" << std::endl;
	std::cout << "3. Exit Game			" << std::endl;
}

void GameUI::showTetris(bool ** UIArray, int s)
{
	system("cls");   //清屏
	std::cout << "Your scores:" << s << std::endl;
	for(int i=0; i<UI_HEIGHT; i++)
	{
		for(int j=0; j<UI_WIDTH; j++)
		{
			//找边界
			if(0==i || UI_HEIGHT-1 ==i
				|| 0==j || UI_WIDTH-1==j)
				std::cout << UI_BORDER;
			else if(!UIArray[i][j])
				std::cout << UI_EMPTY;
			else
				std::cout << UI_SHAPE;
		}
		std::cout << std::endl;//换行
	}
}

void GameUI::updateUI()
{
}