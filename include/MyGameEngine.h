#pragma once

#include "Engine.h"
#include "GameEngineBase.h"
#include "Square.h"
#include "Vaisseau.h"
#include "Asteroid.h"

class MyGameEngine : public GameEngineBase {
private:
	std::vector<Square*>* square;
	std::vector<Vaisseau*>* ships;
	std::vector<Projectile*>* bullet;
	std::vector<Heart*>* protect;
	std::vector<Asteroid*>* asteroid;
	bool* gameOver;
	bool* roundRunning;
	int* gold;
	int* niveau;
public:
    MyGameEngine(std::vector<Square*>* square_, std::vector<Vaisseau*>* ships_, std::vector<Projectile*>* bullet_
		, std::vector<Heart*>* protect_, std::vector<Asteroid*>* asteroid_,bool* gameOver_,bool* roundRunning_,int* gold_,int* niveau_) :
		square(square_), ships(ships_), bullet(bullet_), protect(protect_), asteroid(asteroid_), gameOver(gameOver_), roundRunning(roundRunning_),gold(gold_),niveau(niveau_){}
    virtual void idle();
};

