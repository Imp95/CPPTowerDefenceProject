#pragma once
#include "GraphicPrimitives.h"
class Asteroid
{
public:
	Asteroid(int lp, float sp, float s, float x1,float y1,int v) :
		lifePoint(lp), speed(sp),size(s), x(x1), y(y1),value(v) {}

	int lifePoint;
	float size;
	float speed;
	float x, y;
	int value;

	void draw();
	void act();
	void takeDamage(int dmg);
};

