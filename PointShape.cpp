#include "PointShape.h"
#include <string.h>

PointShape::PointShape()
{
	this->position.x=0;
	this->position.y=0;
	this->index = 0; 
	//TODO:
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			for(int m=0; m<4; m++)
				array[i][j][m] = false;
	
	for(int i=0; i<1; i++)
		array[0][1][1] = true;
	

}

void PointShape::rotate()
{
	if(this->index == 0)
		this->index++;
	else
		this->index = 0;

	//this->index = this->index ^ 1;
}

void PointShape::moveLeft()
{
	this->position.y--;
}

void PointShape::moveRight()
{
	this->position.y++;
}

void PointShape::moveDown()
{
	this->position.x++;
}

void PointShape::moveUp()
{
	this->position.x--;
}

Point PointShape::getPosition()
{
	return this->position;
}

bool PointShape::getArray(int row, int col)
{
	return this->array[index][row][col];
}
