#include"SShape.h"
#include <string.h>

SShape::SShape()
{
	this->index = 0;

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			for(int m=0; m<4; m++)
				array[i][j][m] = false;   //����i������ת���Σ�j�����У�m������ false����û�з��� true�������

	// ####    ����#�Ŵ���ո�
	// #@##
	// #@@#
	// ##@#
    //0�����һ����ת��ʽ
	for(int i=1; i<3; i++)
		array[0][i][1]=true; 
	for(int i=2; i<4; i++)
		array[0][i][2]=true;

	// ####    ����#�Ŵ���ո�
	// ##@@
	// #@@#
	// ####    
    //1����ڶ�����ת��ʽ
	for(int i=2; i<4; i++)
		array[1][1][i]=true; 
	for(int i=1; i<3; i++)
		array[1][2][i]=true;
	 
    // ####    ����#�Ŵ���ո�
	// #@##
	// #@@#
	// ##@#    
    //2�����������ת��ʽ
	for(int i=1; i<3; i++)
		array[2][i][1]=true; 
	for(int i=2; i<4; i++)
		array[2][i][2]=true;

	// ####    ����#�Ŵ���ո�
	// ##@@
	// #@@#
	// ####    
    //3�����������ת��ʽ
 	for(int i=2; i<4; i++)
		array[3][1][i]=true; 
	for(int i=1; i<3; i++)
		array[3][2][i]=true;


}

void SShape::rotate()
{
	this->index++;

	if(this->index>3)
		this->index = 0;
}

void SShape::moveLeft()
{
	this->position.y--;
}

void SShape::moveRight()
{
	this->position.y++;
}

void SShape::moveDown()
{
	this->position.x++;
}

void SShape::moveUp()
{
	this->position.x--;
}

Point SShape::getPosition()
{
	return this->position;
}

bool SShape::getArray(int row, int col)
{
	return this->array[index][row][col];
}
