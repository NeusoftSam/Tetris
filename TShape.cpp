#include"TShape.h"
#include <string.h>

TShape::TShape()
{
	this->index = 0;

	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			for(int m=0; m<4; m++)
				array[i][j][m] = false;   //����i������ת���Σ�j�����У�m������ false����û�з��� true�������

	// ####    ����#�Ŵ���ո�
	// ##@#
	// #@@@
	// ####    
    //0�����һ����ת��ʽ
	for(int i=1; i<4; i++)
		array[0][2][i]=true; 
		array[0][1][2]=true;

	// ####    ����#�Ŵ���ո�
	// #@##
	// #@@#
	// #@##    
    //1����ڶ�����ת��ʽ
	 for(int i=1; i<4; i++)
		array[1][i][1]=true;
		array[1][2][2]=true;
	 
    // ####    ����#�Ŵ���ո�
	// #@@@
	// ##@#
	// ####    
    //2�����������ת��ʽ
	for(int i=1; i<4; i++)
		array[2][1][i]=true;
		array[2][2][2]=true;

	// ####    ����#�Ŵ���ո�
	// ##@#
	// #@@#
	// ##@#    
    //3�����������ת��ʽ
 	for(int i=1; i<4; i++)
		array[3][i][2]=true;
		array[3][2][1]=true;


}

void TShape::rotate()
{
	this->index++;

	if(this->index>3)
		this->index = 0;
}

void TShape::moveLeft()
{
	this->position.y--;
}

void TShape::moveRight()
{
	this->position.y++;
}

void TShape::moveDown()
{
	this->position.x++;
}

void TShape::moveUp()
{
	this->position.x--;
}

Point TShape::getPosition()
{
	return this->position;
}

bool TShape::getArray(int row, int col)
{
	return this->array[index][row][col];
}
