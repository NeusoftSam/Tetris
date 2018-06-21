#ifndef SHAPE_H
#define SHAPE_H
#include "Point.h"

class Shape
{
protected:
	bool array[4][4][4];//4*4*4数组存储
	                    //每个图形有4种角度
	Point position;     //图形所在位置

public:
	virtual void rotate()=0;      //变形函数
	virtual void moveLeft()=0;    //左移函数
	virtual void moveRight()=0;   //右移函数
	virtual void moveDown()=0;    //下落函数
	virtual void moveUp()=0;      //向上回退
	virtual Point getPosition()=0;
	virtual bool getArray(int row, int col)=0;
};

#endif