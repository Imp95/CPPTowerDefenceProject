#pragma once
#include "Engine.h"
#include "GraphicPrimitives.h"
#include "Square.h"
#include "Vaisseau.h"
#include "Asteroid.h"
#include "Buttons.h"

class MyGraphicEngine : public GraphicEngineBase {
private:
	std::vector<Square*>* square;
	std::vector<Vaisseau*>* ships;
	std::vector<Projectile*>* bullet;
	std::vector<Heart*>* protect;
	std::vector<Asteroid*>* asteroid;
	std::vector<RestartButton*>* restarter;
    char* str;
	Interactive ** cursor;
	bool* gameOver;
	bool* roundRunning;
	std::vector<BuysShipButton*>* buysShipButtons;
	std::vector<StartRound*>* startRound;
	int* gold;
	int* niveau;

public:
    
    MyGraphicEngine(std::vector<Square*>* square_, std::vector<Vaisseau*>* ships_, std::vector<Projectile*>* bullet_
		, std::vector<Heart*>* protect_, std::vector<Asteroid*>* asteroid_, Interactive ** cursor_, bool* gameOver_, bool* roundRunning_, int* gold_,
		std::vector<BuysShipButton*>* buysShipButtons_, std::vector<StartRound*>* startRound_, int* niveau_, std::vector<RestartButton*>* restarter_) :
		square(square_), ships(ships_), bullet(bullet_), protect(protect_), asteroid(asteroid_), cursor(cursor_), gameOver(gameOver_), roundRunning(roundRunning_),
		buysShipButtons(buysShipButtons_), startRound(startRound_), gold(gold_), niveau(niveau_), restarter(restarter_),
    str(new char[13]{'C','l','i','c',' ','&',' ','E','n','j','o','y','\0'}),
        x1(0.5f),
        x2(-0.5f),
        dx1(0.01),
        dx2(-0.02)
        {}
    
    float x1,x2, dx1, dx2;
    
    virtual void Draw();
    
};
