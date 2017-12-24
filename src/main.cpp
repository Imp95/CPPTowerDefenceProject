#include <iostream>
#include "Engine.h"
#include "ControlEngineBase.h"
#include "GameEngineBase.h"
#include "GraphicEngineBase.h"
#include "MyControlEngine.h"
#include "MyGameEngine.h"
#include "MyGraphicEngine.h"
#include "Square.h"
#include "Vaisseau.h"
#include "Asteroid.h"
#include "Buttons.h"

int main(int argc, char* argv[]){
    Engine e(argc,argv);
    
    //std::vector<Papillon*> paps;
	//std::vector<Fourmi*> fours;

	//(x - 400) / 400.f), (y - 300) / -300.f)
	std::vector<Square*> square;
	std::vector<Vaisseau*> ships;
	std::vector<Projectile*> bullet;
	std::vector<Heart*> protect;
	std::vector<Asteroid*> asteroid;
	std::vector<BuysShipButton*> buysShipButtons;
	std::vector<StartRound*> startRound;
	std::vector<RestartButton*> restarter;
	Interactive * cursor=NULL;
	int gold = 60;
	int niveau = 1;
	bool gameOver = false;
	bool roundRunning = false;

	for (float j = -.5f; j < .5f; j +=.2f) {
		for (float i = -1.0f; i < .5f; i+=.125f) {
			square.push_back(new Square(i,j,i+.125f,j+.2f));
		}
	}
	Heart* temp;

	for (int i = 0; i < square.size(); i++) {
		if (square[i]->x1 == -1.0f) {
			temp= new Heart(square[i]->x1, square[i]->y1);
			square[i]->inside = temp;
			protect.push_back(temp);
		}
	}

	buysShipButtons.push_back(new BuysShipButton(-.3f, .7f, 30, 40, 10, .0f, .0f, 1.0f, 15, "Medium blue 15G","HP : 40, RoF : 1/30, Dmg : 10"));
	buysShipButtons.push_back(new BuysShipButton(-1.0f, .7f, 58, 80, 20, .0f, 1.0f, .0f, 20, "Big green 20G", "HP : 80, RoF : 1/58, Dmg : 20"));
	buysShipButtons.push_back(new BuysShipButton(.4f, .7f, 14, 20, 5, 1.0f, 1.0f, .5f, 10, "Small yellow 10G", "HP : 20, RoF : 1/14, Dmg : 5"));

	restarter.push_back(new RestartButton(.4f, .7f, .8f, 1.0f));
	startRound.push_back(new StartRound(.4f, -.7f, .8f, -.4f));

    
    GraphicEngineBase* ge = new MyGraphicEngine(&square, &ships, &bullet, &protect, &asteroid, &cursor, &gameOver, &roundRunning, &gold, &buysShipButtons, &startRound, &niveau,&restarter);
	GameEngineBase* gme = new MyGameEngine(&square, &ships, &bullet, &protect, &asteroid, &gameOver, &roundRunning,&gold,&niveau);
    ControlEngineBase* ce = new MyControlEngine(&square, &ships, &bullet, &protect, &asteroid,&cursor,&gameOver,&roundRunning, &gold,&buysShipButtons,&startRound, &niveau,&restarter);
    
    e.setGraphicEngine(ge);
    e.setGameEngine(gme);
    e.setControlEngine(ce);
    
    e.start();
    return 0;
}


