#pragma once
#include "Square.h"

class Projectile :
	public Interactive
{
public:
	int damage;
	float x1, y1;
	void act();
	void click();
	void draw();

	Projectile(int d,float x, float y):
		damage(d),x1(x),y1(y){}
};

class Vaisseau :
	public Interactive
{
public:
	int fireRate;
	int lifePoint;
	int damage;


	Vaisseau(int fR, int lP, int d,float x1,float y1, float r, float g, float b)
		:fireRate(fR), lifePoint(lP), damage(d),
		red(r), green(g), blue(b),x(x1),y(y1) {}

	float red, green, blue;
	float x, y;

	void draw();
	void click();
	void act();
	bool isShip();
	Projectile* fire();
	void takeDamage(int damage);
	int count = 0;
	bool roundStart = false;
};

class Heart :
	public Interactive
{
public:
	Heart(float x1,float y1):
		x(x1),y(y1){}
	void draw();
	void click();
	bool isShip();
	bool gameOver = false;
	float x, y;
};

