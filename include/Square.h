#pragma once
#include "GraphicPrimitives.h"
class Interactive {

public:
	virtual void draw();
	virtual void click();
	virtual void act();
	virtual bool isShip();
};

class Square {

public:
	Square(float fx1 = 0.0f, float fy1 = 0.0f, float fx2 = 0.0f, float fy2 = 0.0f, float red = .5f,
		float green = .5f, float blue = .5f)
		:x1(fx1), y1(fy1), x2(fx2), y2(fy2),
		r(red), g(green), b(blue)
		{
	}
	~Square();

	float x1, y1, x2, y2;
	Interactive* inside;

	// color variation
	float r;
	float g;
	float b;

	float height();
	float width();
	void draw();
	Interactive* click();

	bool isInside(float x, float y);
};
