#ifndef TSHAPE_H
#define TSHAPE_H
#include "Shape.h"

class TShape : public Shape
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

	TShape();//���캯��
};

#endif