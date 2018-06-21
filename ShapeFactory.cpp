#include "ShapeFactory.h"
#include "Common.h"
#include "LineShape.h" //添加|库函数
#include "LShape.h"    //添加L库函数
#include "FShape.h"    //添加方型库函数
#include "TShape.h"    //添加T型库函数
#include "LLShape.h"   //添加_|型库函数
#include "PointShape.h"//添加点型库函数
#include "SShape.h"    //添加S型库函数
#include "ZShape.h"    //添加2型库函数
#include <iostream>
#include <time.h>

Shape * ShapeFactory::getShape()
{
	switch(getRand())
	{
	case 0:
		return new LineShape(); //添加|型
	case 1:
		return new LShape();    //添加L型
	case 2:
 		return new FShape();    //添加方型
	case 3:
		return new TShape();    //添加T型
	case 4:
		return new LLShape();   //添加_|型
	case 5:
		return new PointShape();//添加点型
	case 6:
		return new SShape();//添加S型
	case 7:
		return new ZShape();//添加2型
	default:
		return NULL;
	}
}

int ShapeFactory::getRand()
{
	srand((unsigned)time(0));

	return (rand() % 8) ;     //修改
}
