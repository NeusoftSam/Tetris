#ifndef LLSHAPE_H
#define LLSHAPE_H
#include "Shape.h"

class LLShape : public Shape
{
private:
	int index; //当前状态坐标
public:
	virtual void rotate();      //重写rotate函数
	virtual void moveLeft();    //左移函数
	virtual void moveRight();   //右移函数
	virtual void moveDown();    //下落函数
	virtual void moveUp() ;     //向上回退
	virtual Point getPosition();
	virtual bool getArray(int row, int col);

	LLShape();//构造函数
};

#endif