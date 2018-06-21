#include "ShapeFactory.h"
#include "Common.h"
#include "LineShape.h" //���|�⺯��
#include "LShape.h"    //���L�⺯��
#include "FShape.h"    //��ӷ��Ϳ⺯��
#include "TShape.h"    //���T�Ϳ⺯��
#include "LLShape.h"   //���_|�Ϳ⺯��
#include "PointShape.h"//��ӵ��Ϳ⺯��
#include "SShape.h"    //���S�Ϳ⺯��
#include "ZShape.h"    //���2�Ϳ⺯��
#include <iostream>
#include <time.h>

Shape * ShapeFactory::getShape()
{
	switch(getRand())
	{
	case 0:
		return new LineShape(); //���|��
	case 1:
		return new LShape();    //���L��
	case 2:
 		return new FShape();    //��ӷ���
	case 3:
		return new TShape();    //���T��
	case 4:
		return new LLShape();   //���_|��
	case 5:
		return new PointShape();//��ӵ���
	case 6:
		return new SShape();//���S��
	case 7:
		return new ZShape();//���2��
	default:
		return NULL;
	}
}

int ShapeFactory::getRand()
{
	srand((unsigned)time(0));

	return (rand() % 8) ;     //�޸�
}
