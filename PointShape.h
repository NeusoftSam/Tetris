#ifndef POINTSHAPE_H
#define POINTSHAPE_H
#include "Shape.h"

class PointShape : public Shape
{
private:
	int index; //��ǰ״̬����
public:
	virtual void rotate();        //��дrotate����
	virtual void moveLeft();      //���ƺ���
	virtual void moveRight();     //���ƺ���
	virtual void moveDown();      //���亯��
	virtual void moveUp();        //���ϻ���
	virtual Point getPosition();
	virtual bool getArray(int row, int col);

	PointShape();//���캯��
};

#endif