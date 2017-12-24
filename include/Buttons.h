#pragma once
#include "GraphicPrimitives.h"
#include "Vaisseau.h"
class Buttons
{
public:
	Buttons(float x1_, float y1_, float x2_, float y2_) :
		x1(x1_), y1(y1_), x2(x2_), y2(y2_) {}
	
	~Buttons();

	float x1, y1,x2,y2;


	virtual void draw();
	float height();
	float width();
	bool isInside(float x, float y);
protected:
	Buttons();
};

class BuysShipButton:
	public Buttons
{
public:
	BuysShipButton(float x1_, float y1_, int fR, int lP, int d, float r, float g, float b, int cost_, char* str_,char* info_) :
		x1(x1_), y1(y1_), x2(x1_+.125f), y2(y1_+.2f), fireRate(fR), lifePoint(lP), damage(d),
		red(r), green(g), blue(b), cost(cost_), str(str_),info(info_){}

	float x1, y1, x2, y2;
	void draw();

	bool isInside(float x, float y);

	int fireRate;
	int lifePoint;
	int damage;
	int cost;
	char* str;
	char* info;
	float red, green, blue;

	Vaisseau* spawn();

};

class StartRound :
	public Buttons
{
public:
	StartRound(float x1_, float y1_, float x2_, float y2_) :
		x1(x1_), y1(y1_), x2(x2_), y2(y2_) {}

	float x1, y1, x2, y2;
	void draw();
	bool isInside(float x, float y);
	char* str = "Start wave";

};

class RestartButton :
	public Buttons
{
public:
	RestartButton(float x1_, float y1_, float x2_, float y2_) :
		x1(x1_), y1(y1_), x2(x2_), y2(y2_) {}

	float x1, y1, x2, y2;
	void draw();
	bool isInside(float x, float y);
	char* str = "Restart Game";

};