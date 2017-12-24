#include "MyGameEngine.h"
#include <algorithm>

void MyGameEngine::idle(){
	Sleep(1000 / 60);
	if (*gameOver || !(*roundRunning)) {
		return;
	}
	std::vector<int> shipRemove;
	std::vector<int> bulletRemove;
	std::vector<int> asteroidRemove;
	for (int i = 0; i < ships->size(); i++) {
		(*ships)[i]->act();
		if ((*ships)[i]->count >= (*ships)[i]->fireRate) {
			(*ships)[i]->count = 0;
			bullet->push_back((*ships)[i]->fire());
		}
	}
	Projectile* currentP;
	Asteroid* currentA;
	Square* currentS;
	Vaisseau* currentV;
	//On deplace tout les missiles et supprime ce qui sont sorti de l'écran
	for (int i = 0; i < bullet->size(); i++) {
		(*bullet)[i]->act();
		if ((*bullet)[i]->x1 > 1.0) {
			bulletRemove.push_back(i);
		}
	}
	for (int i = bulletRemove.size()-1; i >= 0; i--) {
		delete (*bullet)[bulletRemove[i]];
		bullet->erase(bullet->begin() + bulletRemove[i]);
	}
	bulletRemove.clear();
	//On verifie si un missile touche un asteroid
	for (int i = 0; i < asteroid->size(); i++) {
		currentA = (*asteroid)[i];
		for (int y = 0; y < bullet->size(); y++) {
			currentP=(*bullet)[y];
			if (currentP->x1 <= currentA->x + currentA->size / 2 && currentP->x1 >= currentA->x - currentA->size / 2) {
				if (currentP->y1 <= currentA->y + .1f && currentP->y1 >= currentA->y - .1f) {
					currentA->takeDamage(currentP->damage);
					bulletRemove.push_back(y);
					if (currentA->lifePoint <= 0) {
						asteroidRemove.push_back(i);
						*gold += currentA->value;
					}
				}
			}
		}
	}
	//On supprime tout les asteroids detruit et les missiles qui les ont toucher
	std::sort(bulletRemove.begin(), bulletRemove.end());
	bulletRemove.erase(std::unique(bulletRemove.begin(), bulletRemove.end()), bulletRemove.end());
	for (int i = bulletRemove.size() - 1; i >= 0; i--) {
		delete (*bullet)[bulletRemove[i]];
		bullet->erase(bullet->begin() + bulletRemove[i]);
	}
	bulletRemove.clear();
	std::sort(asteroidRemove.begin(), asteroidRemove.end());
	asteroidRemove.erase(std::unique(asteroidRemove.begin(), asteroidRemove.end()), asteroidRemove.end());
	for (int i = asteroidRemove.size() - 1; i >= 0; i--) {
		delete (*asteroid)[asteroidRemove[i]];
		asteroid->erase(asteroid->begin() + asteroidRemove[i]);
	}
	asteroidRemove.clear();
	//On deplace les asteroides
	for (int i = 0; i < asteroid->size(); i++) {
		currentA = (*asteroid)[i];
		currentA->act();
		for (int y = 0; y < bullet->size(); y++) {
			currentP = (*bullet)[y];
			if (currentP->x1 <= currentA->x + currentA->size / 2 && currentP->x1 >= currentA->x - currentA->size / 2) {
				if (currentP->y1 <= currentA->y + .1f && currentP->y1 >= currentA->y - .1f) {
					currentA->takeDamage(currentP->damage);
					bulletRemove.push_back(y);
					if (currentA->lifePoint <= 0) {
						asteroidRemove.push_back(i);
						*gold += currentA->value;
					}
				}
			}
		}
		if (currentA->x < -1.0f) {
			*gameOver = true;
		}
	}
	//On supprime tout les asteroids detruit et les missiles qui les ont toucher
	std::sort(bulletRemove.begin(), bulletRemove.end());
	bulletRemove.erase(std::unique(bulletRemove.begin(), bulletRemove.end()), bulletRemove.end());
	for (int i = bulletRemove.size() - 1; i >= 0; i--) {
		delete (*bullet)[bulletRemove[i]];
		bullet->erase(bullet->begin() + bulletRemove[i]);
	}
	bulletRemove.clear();
	std::sort(asteroidRemove.begin(), asteroidRemove.end());
	asteroidRemove.erase(std::unique(asteroidRemove.begin(), asteroidRemove.end()), asteroidRemove.end());
	for (int i = asteroidRemove.size() - 1; i >= 0; i--) {
		delete (*asteroid)[asteroidRemove[i]];
		asteroid->erase(asteroid->begin() + asteroidRemove[i]);
	}
	asteroidRemove.clear();
	//On vérifie si un asteroid a rencontrer un vaisseau/le coeur
	for (int i = 0; i < asteroid->size(); i++) {
		currentA = (*asteroid)[i];
		currentA->act();
		for (int y = 0; y < square->size(); y++) {
			currentS = (*square)[y];
			if (currentS->isInside(currentA->x, currentA->y)) {
				if (currentS->inside != NULL) {
					currentS->inside->click();
					if (currentS->inside->isShip()) {
						currentV = (Vaisseau*)currentS->inside;
						currentV->takeDamage(currentA->lifePoint);
						currentA->lifePoint = -currentV->lifePoint;
						if (currentA->lifePoint <= 0) {
							asteroidRemove.push_back(i);
							*gold += currentA->value;
						}

						if (currentV->lifePoint <= 0) {
							for (int z = 0; z < ships->size(); z++) {
								if ((*ships)[z] == currentV) {
									shipRemove.push_back(z);
								}
							}
							currentS->inside = NULL;
						}
					}
				}
			}
		}
	}
	//On suprime les vaisseaux et asteroid detruit par colision
	std::sort(shipRemove.begin(), shipRemove.end());
	shipRemove.erase(std::unique(shipRemove.begin(), shipRemove.end()), shipRemove.end());
	for (int i = shipRemove.size() - 1; i >= 0; i--) {
		delete (*ships)[shipRemove[i]];
		ships->erase(ships->begin() + shipRemove[i]);
	}
	shipRemove.clear();
	std::sort(asteroidRemove.begin(), asteroidRemove.end());
	asteroidRemove.erase(std::unique(asteroidRemove.begin(), asteroidRemove.end()), asteroidRemove.end());
	for (int i = asteroidRemove.size() - 1; i >= 0; i--) {
		delete (*asteroid)[asteroidRemove[i]];
		asteroid->erase(asteroid->begin() + asteroidRemove[i]);
	}
	asteroidRemove.clear();
	for (int i = 0; i < protect->size(); i++) {
		if ((*protect)[i]->gameOver) {
			printf("game over \n");
			*gameOver = true;
		}
	}
	//Recherche si le round est fini et supprime tout missle restant si c'est le cas
	if (asteroid->size() == 0) {
		*roundRunning = false;
		for (int i = 0; i < bullet->size(); i++) {
			delete (*bullet)[i];
		}
		bullet->clear();
		*niveau += 1;
	}
}

