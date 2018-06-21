#include "LineShape.h"
#include <string.h>

LineShape::LineShape()
{
	this->position.x=0;
	this->position.y=0;
	this->index = 0; //直线初始状态
	//TODO:
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			for(int m=0; m<4; m++)
				array[i][j][m] = false;
	// |形
	for(int i=0; i<4; i++)
		array[0][i][1] = true;
	// — 形
	for(int j=0; j<4; j++)
		array[1][2][j] = true;

}

void LineShape::rotate()
{
	if(this->index == 0)
		this->index++;
	else
		this->index = 0;

	//this->index = this->index ^ 1;
}

void LineShape::moveLeft()
{
	this->position.y--;
}

void LineShape::moveRight()
{
	this->position.y++;
}

void LineShape::moveDown()
{
	this->position.x++;
}

void LineShape::moveUp()
{
	this->position.x--;
}

Point LineShape::getPosition()
{
	return this->position;
}

bool LineShape::getArray(int row, int col)
{
	return this->array[index][row][col];
}
