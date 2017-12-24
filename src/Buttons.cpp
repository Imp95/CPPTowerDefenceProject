#include "Buttons.h"

float Buttons::height()
{
	return y2 - y1;
}

float Buttons::width()
{
	return x2 - x1;
}

Buttons::~Buttons()
{
}

void Buttons::draw()
{
}

bool Buttons::isInside(float x, float y)
{
	return (x>x1 && x<x2) && (y>y1 && y<y2);
}

Buttons::Buttons()
{
}

void BuysShipButton::draw()
{
	GraphicPrimitives::drawOutlinedRect2D(x1, y1, width(), height(), 1.0f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawFillTriangle2D(x1, y1, x1, y1 + .2f, x1 + .125f, y1 + .1f, red, green, blue);
	
	GraphicPrimitives::drawText2D(str, x1, y2 + .025f, 1.0f, 1.0f, 1.0f);
	GraphicPrimitives::drawText2D(info, x1, y1 - .075f, 1.0f, 1.0f, 1.0f);
}
bool BuysShipButton::isInside(float x, float y)
{
	return (x>x1 && x<x2) && (y>y1 && y<y2);
}

Vaisseau * BuysShipButton::spawn()
{
	return new Vaisseau(fireRate, lifePoint, damage, x1, y1, red, green, blue);
}

void StartRound::draw()
{
	GraphicPrimitives::drawText2D(str, x1+0.01f, y1+.025f, 1.0f, 1.0f, 1.0f);
	
}

bool StartRound::isInside(float x, float y)
{
	return (x>x1 && x<x2) && (y>y1 && y<y2);
}

void RestartButton::draw()
{
	GraphicPrimitives::drawText2D(str, x1 + 0.01f, y1 + .025f, 1.0f, 1.0f, 1.0f);
}

bool RestartButton::isInside(float x, float y)
{
	return (x>x1 && x<x2) && (y>y1 && y<y2);
}
