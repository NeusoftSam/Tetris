#include"FShape.h"
#include <string.h>

FShape::FShape()
{
	this->index = 0;

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			for(int m=0; m<4; m++)
				array[i][j][m] = false;   //����i������ת���Σ�j�����У�m������ false����û�з��� true�������

	// ####    ����#�Ŵ���ո�
	// #@@#
	// #@@#
	// ####    
    //0�����һ����ת��ʽ
	for(int i=1; i<3; i++)
		array[0][i][1]=true;    
	for(int i=1; i<3; i++)
		array[0][i][2]=true;

	// ####    ����#�Ŵ���ո�
	// #@@#
	// #@@#
	// ####    
    //1����ڶ�����ת��ʽ
	 for(int i=1; i<3; i++)
		array[1][i][1]=true;
	 for(int i=1; i<3; i++)
		array[1][i][2]=true;
	 
    // ####    ����#�Ŵ���ո�
	// #@@#
	// #@@#
	// ####    
    //2�����������ת��ʽ
	for(int i=1; i<3; i++)
		array[2][i][1]=true;
	for(int i=1; i<3; i++)
		array[2][i][2]=true;

	// ####    ����#�Ŵ���ո�
	// #@@#
	// #@@#
	// ####    
    //3�����������ת��ʽ
 	for(int i=1; i<3; i++)
		array[3][i][1]=true;
	for(int i=1; i<3; i++)
		array[3][i][2]=true;


}

void FShape::rotate()
{
	this->index++;

	if(this->index>3)
		this->index = 0;
}

void FShape::moveLeft()
{
	this->position.y--;
}

void FShape::moveRight()
{
	this->position.y++;
}

void FShape::moveDown()
{
	this->position.x++;
}

void FShape::moveUp()
{
	this->position.x--;
}

Point FShape::getPosition()
{
	return this->position;
}

bool FShape::getArray(int row, int col)
{
	return this->array[index][row][col];
}
