#ifndef GAME_H
#define GAME_H
#include "Common.h"
#include "GameUI.h"
//#include "Shape.h"
#include "ShapeFactory.h"

class Game
{
private:
	int game_status;
	GameUI gameUI;
	bool ** gameArray;
	Shape *shape;
	int score;

public:
	//void GameStart();
	void GameRun();
	//void GamePause();
	//void GameEnd();

	Game();
	void downSpeed(int time);
	int keyCheck();
	bool CollisionDection();
	bool ** merge();
	void cancelBlock();
	void finalBlock();
	void getScores();
	void moveLine(int row);
};

#endif