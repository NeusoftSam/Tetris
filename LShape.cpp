#include"LShape.h"
#include <string.h>

LShape::LShape()
{
	this->index = 0;

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			for(int m=0; m<4; m++)
				array[i][j][m] = false;
	//1-L
	for(int i=1; i<4; i++)
		array[0][i][1]=true;
	array[0][3][2]=true;

	//2-©½
	for(int i=1; i<4; i++)
		array[1][2][i]=true;
	array[1][3][1]=true;

	//3-
	for(int i=1; i<4; i++)
		array[2][i][2]=true;
	array[2][1][1]=true;

	//4-
	for(int i=1; i<4; i++)
		array[3][1][i]=true;
	array[3][2][1]=true;
}

void LShape::rotate()
{
	this->index++;

	if(this->index>3)
		this->index = 0;
}

void LShape::moveLeft()
{
	this->position.y--;
}

void LShape::moveRight()
{
	this->position.y++;
}

void LShape::moveDown()
{
	this->position.x++;
}

void LShape::moveUp()
{
	this->position.x--;
}

Point LShape::getPosition()
{
	return this->position;
}

bool LShape::getArray(int row, int col)
{
	return this->array[index][row][col];
}