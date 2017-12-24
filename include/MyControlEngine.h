#pragma once
#include "Engine.h"
#include "Square.h"
#include "Vaisseau.h"
#include "Asteroid.h"
#include "Buttons.h"

class MyControlEngine : public ControlEngineBase {
	std::vector<Square*>* square;
	std::vector<Vaisseau*>* ships;
	std::vector<Projectile*>* bullet;
	std::vector<Heart*>* protect;
	std::vector<Asteroid*>* asteroid;
	std::vector<RestartButton*>* restarter;
	Interactive ** cursor;
	bool* gameOver;
	bool* roundRunning;
	BuysShipButton* savedBS;
	std::vector<BuysShipButton*>* buysShipButtons;
	std::vector<StartRound*>* startRound;
	int* gold;
	int* niveau;
	int currentCost;
public:
    MyControlEngine(std::vector<Square*>* square_, std::vector<Vaisseau*>* ships_, std::vector<Projectile*>* bullet_
	, std::vector<Heart*>* protect_, std::vector<Asteroid*>* asteroid_, Interactive ** cursor_, bool* gameOver_, bool* roundRunning_, int* gold_,
		std::vector<BuysShipButton*>* buysShipButtons_, std::vector<StartRound*>* startRound_, int* niveau_, std::vector<RestartButton*>* restarter_):
		square(square_), ships(ships_), bullet(bullet_), protect(protect_), asteroid(asteroid_), cursor(cursor_), gameOver(gameOver_), roundRunning(roundRunning_),
		buysShipButtons(buysShipButtons_), startRound(startRound_), gold(gold_), niveau(niveau_), restarter(restarter_) {}
    
    virtual void MouseCallback(int button, int state, int x, int y) ;
	void generateNiveau(int lvl, std::vector<Asteroid*>* asteroid_);
	void addShip(Vaisseau* ship, std::vector<Vaisseau*>* ships_);
	void restart();
};
