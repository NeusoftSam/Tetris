#include"ZShape.h"
#include <string.h>

ZShape::ZShape()
{
	this->index = 0;

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			for(int m=0; m<4; m++)
				array[i][j][m] = false;   //其中i代表旋转方形，j代表行，m代表列 false代表没有符号 true代表填充

	// ####    其中#号代表空格
	// ##@#
	// #@@#
	// #@##
    //0代表第一种旋转方式
	for(int i=2; i<4; i++)
		array[0][i][1]=true; 
	for(int i=1; i<3; i++)
		array[0][i][2]=true;

	// ####    其中#号代表空格
	// #@@#
	// ##@@
	// ####    
    //1代表第二种旋转方式
	for(int i=1; i<3; i++)
		array[1][1][i]=true; 
	for(int i=2; i<4; i++)
		array[1][2][i]=true;
	 
    // ####    其中#号代表空格
	// ##@#
	// #@@#
	// #@##  
    //2代表第三种旋转方式
	for(int i=2; i<4; i++)
		array[2][i][1]=true; 
	for(int i=1; i<3; i++)
		array[2][i][2]=true;

	// ####    其中#号代表空格
	// #@@#
	// ##@@
	// ####    
    //1代表第二种旋转方式
	for(int i=1; i<3; i++)
		array[3][1][i]=true; 
	for(int i=2; i<4; i++)
		array[3][2][i]=true;


}

void ZShape::rotate()
{
	this->index++;

	if(this->index>3)
		this->index = 0;
}

void ZShape::moveLeft()
{
	this->position.y--;
}

void ZShape::moveRight()
{
	this->position.y++;
}

void ZShape::moveDown()
{
	this->position.x++;
}

void ZShape::moveUp()
{
	this->position.x--;
}

Point ZShape::getPosition()
{
	return this->position;
}

bool ZShape::getArray(int row, int col)
{
	return this->array[index][row][col];
}
