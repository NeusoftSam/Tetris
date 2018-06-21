#ifndef SHAPEFACTORY
#define SHAPEFACTORY
#include "Shape.h"

class ShapeFactory
{
private:
	Shape *pShape;

protected:
	static int getRand();

public:
	static Shape * getShape();
};

#endif