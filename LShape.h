#ifndef LSHAPE_H
#define LSHAPE_H
#include "Shape.h"

class LShape : public Shape
{
private:
	int index; //��ǰ״̬����
public:
	virtual void rotate();      //��дrotate����
	virtual void moveLeft();    //���ƺ���
	virtual void moveRight();   //���ƺ���
	virtual void moveDown();    //���亯��
	virtual void moveUp() ;     //���ϻ���
	virtual Point getPosition();
	virtual bool getArray(int row, int col);

	LShape();//���캯��
};

#endif