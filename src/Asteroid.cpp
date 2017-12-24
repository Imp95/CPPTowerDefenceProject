#include "Asteroid.h"
#define _USE_MATH_DEFINES
#include "math.h"



void Asteroid::draw()
{
	std::vector<float> x0;
	std::vector<float> y0;
	for (float i = 0; i < 2 * M_PI; i += M_PI_4) {
		x0.push_back(x + cos(i)*(size / 2));
		y0.push_back(y + sin(i)*(size / 2));
	}
	GraphicPrimitives::drawFillPolygone2D(x0, y0, .55f, .27f, .07f);
	
}

void Asteroid::act()
{
	x -= speed;
}

void Asteroid::takeDamage(int dmg)
{
	lifePoint -= dmg;
}
