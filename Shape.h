#ifndef SHAPE_H
#define SHAPE_H
#include "Point.h"

class Shape
{
protected:
	bool array[4][4][4];//4*4*4����洢
	                    //ÿ��ͼ����4�ֽǶ�
	Point position;     //ͼ������λ��

public:
	virtual void rotate()=0;      //���κ���
	virtual void moveLeft()=0;    //���ƺ���
	virtual void moveRight()=0;   //���ƺ���
	virtual void moveDown()=0;    //���亯��
	virtual void moveUp()=0;      //���ϻ���
	virtual Point getPosition()=0;
	virtual bool getArray(int row, int col)=0;
};

#endif