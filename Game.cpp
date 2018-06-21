#include "Game.h"
#include "GameUI.h"
#include "Point.h"
#include <iostream>
#include <time.h>
#include <conio.h>

Game::Game()
{
	this->game_status = GAME_READY;
	this->score = 0;
	
	this->gameArray = new bool*[UI_HEIGHT];
	for(int i=0; i<UI_HEIGHT; i++)
	{
		this->gameArray[i] = new bool[UI_WIDTH];
		for(int j=0; j<UI_WIDTH; j++)
		{
			this->gameArray[i][j] = false;
			if(0==i || UI_HEIGHT-1==i 
				|| 0==j || UI_WIDTH-1 ==j)
				this->gameArray[i][j] = true;
		}
	}
}

void Game::GameRun()
{
	this->gameUI.showMain();

	int key = -1;
	while (key == -1)
	{
		key = keyCheck();

		switch(key)
		{
		case START:
			this->game_status = GAME_START;
			break;
		case HELP:
			break;
		case EXIT:
			exit(0);
		default:
			break;
		}
	}

	while(this->game_status)
	{
		if(this->game_status == GAME_START)
		{
			this->shape = ShapeFactory::getShape();
			if(CollisionDection())
				return ;
			while(true)
			{
				this->gameUI.showTetris(merge(), score);
				this->downSpeed(1);
				this->cancelBlock();
				this->shape->moveDown();
				if(CollisionDection())
				{
					this->shape->moveUp();
					break;
				}
				switch(this->keyCheck())
				{
				case TOP:
					this->shape->rotate();
					if(CollisionDection())
					{
						this->shape->rotate();
						this->shape->rotate();
						this->shape->rotate();
					}
					break;
				case BUTTOM:
					this->shape->moveDown();
					if(CollisionDection())
					{
						this->shape->moveUp();
					}
					break;
				case LEFT:
					this->shape->moveLeft();
					if(CollisionDection())
					{
						this->shape->moveRight();
					}
					break;
				case RIGHT:
					this->shape->moveRight();
					if(CollisionDection())
					{
						this->shape->moveLeft();
					}
					break;
				default:
					break;
				}
			}
			this->merge();
			this->getScores();
		}
	}
}

void Game::downSpeed(int time)
{
	clock_t begin, end;
	begin = clock();
	while(1)
	{
		end = clock();
		if((end - begin) >= (time * CLOCK_PER_SECOND))
			return ;
	}
	return ;
}

int Game::keyCheck()
{
	char key;
	if(!_kbhit()) return -1;
	key = _getch();
	switch(key)
	{
	case 'w':
		return TOP;
	case 's':
		return BUTTOM;
	case 'a':
		return LEFT;
	case 'd':
		return RIGHT;
	case '1':
		return START;
	case '2':
		return HELP;
	case '3':
		return EXIT;
	default:
		return NULL;
	}

	return NULL;
}

bool Game::CollisionDection()
{
	Point p = shape->getPosition();

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
		{
			if((p.x+i)!=0 && shape->getArray(i, j)
				&& p.x+i < UI_HEIGHT && p.y+j < UI_WIDTH)
			{
				if(this->gameArray[p.x+i][p.y+j])
					return true;
			}
		}
	
	return false;
}

bool ** Game::merge()
{
	Point p = this->shape->getPosition();

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			if(shape->getArray(i, j))
				gameArray[p.x+i][p.y+j]= shape->getArray(i, j);

	return this->gameArray;
}

void Game::cancelBlock()
{
	Point p = this->shape->getPosition();

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
		{
			if(this->shape->getArray(i, j))
				this->gameArray[p.x+i][p.y+j]=false;
		}
}

void Game::getScores()
{
	int m = 0;
	bool result;

	for(int i=UI_HEIGHT-2; i>m; i--)
	{
		result = true;
		for(int j=1; j<UI_WIDTH-1; j++)
		{
			if(!this->gameArray[i][j])
			{
				result = false;
				break;
			}
		}
		
		if(result) 
		{
			this->score++;
			moveLine(i);
		}
	}
}

void Game::moveLine(int row)
{
	for(int i=row; i>1; i--)
		for(int j=1; j<UI_WIDTH-2; j++)
			this->gameArray[i][j] = this->gameArray[i-1][j];

	for(int i=1; i<UI_WIDTH-2; i++)
		this->gameArray[1][i] = false;
}
