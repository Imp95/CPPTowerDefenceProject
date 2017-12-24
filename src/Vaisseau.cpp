#include "Vaisseau.h"

void Projectile::act()
{
	x1 += .05;
}

void Projectile::click()
{
}

void Projectile::draw()
{
	GraphicPrimitives::drawFillRect2D(x1, y1, .01f, .01f, 1, 1, 1);
}

void Vaisseau::draw()
{
	GraphicPrimitives::drawFillTriangle2D(x, y, x, y + .2f, x + .125f, y + .1f, red, green, blue);
}

void Vaisseau::click()
{
}

void Vaisseau::act()
{
	count++;
}

bool Vaisseau::isShip()
{
	return true;
}

Projectile* Vaisseau::fire()
{
	return new Projectile(damage,x,y+.1f);
}

void Vaisseau::takeDamage(int damage)
{
	lifePoint -= damage;
}

void Heart::draw()
{
	GraphicPrimitives::drawFillRect2D(x, y, .125f, .2f, 1, 0, 0);
}

void Heart::click()
{
	gameOver = true;
}

bool Heart::isShip()
{
	return false;
}
