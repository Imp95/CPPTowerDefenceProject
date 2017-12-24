#include "Square.h"


Square::~Square()
{
	delete inside;
}

float Square::height()
{
	return y2 - y1;
}
	
float Square::width()
{
	return x2 - x1;
}

void Square::draw() {
	GraphicPrimitives::drawOutlinedRect2D(x1, y1, width(), height(), r, g, b, 1.0f);
}
Interactive* Square::click() {
	return inside;
}
	
bool Square::isInside(float x, float y)
{
	return (x>x1 && x<x2) && (y>y1 && y<y2);
}

void Interactive::draw()
{
}

void Interactive::click()
{
}

void Interactive::act()
{
}

bool Interactive::isShip()
{
	return false;
}
