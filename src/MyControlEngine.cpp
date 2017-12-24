#include "MyControlEngine.h"
#include "MyGameEngine.h"

void MyControlEngine::MouseCallback(int button, int state, int x, int y){

    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		Square* current;
		Vaisseau* currentV;
		for (int i = 0; i < square->size(); i++) {
			current = (*square)[i];
			if (current->isInside(((x - 400) / 400.f), ((y - 300) / -300.f))) {
				if (*gameOver) {
					return;
				}
				if (*cursor != NULL && current->inside == NULL && *gold >= currentCost) {
					currentV = (Vaisseau*)*cursor;
					currentV->x = current->x1;
					currentV->y = current->y1;
					current->inside = currentV;
					addShip(currentV, ships);
					*gold -= currentCost;
					currentCost = 0;
					*cursor = savedBS->spawn();
					currentCost = savedBS->cost;

				}
			}
		}
		BuysShipButton* currentBS;
		for (int i = 0; i < buysShipButtons->size(); i++) {
			currentBS = (*buysShipButtons)[i];
			if (currentBS->isInside(((x - 400) / 400.f), ((y - 300) / -300.f))) {
				if (*gameOver) {
					return;
				}
				savedBS = currentBS;
				*cursor = currentBS->spawn();
				currentCost = currentBS->cost;
			}
		}
		RestartButton* currentRS;
		for (int i = 0; i < restarter->size(); i++) {
			currentRS = (*restarter)[i];
			if (currentRS->isInside(((x - 400) / 400.f), ((y - 300) / -300.f))) {
				if (*gameOver) {
					restart();
					return;
				}
			}
		}
		StartRound* currentSR;
		for (int i = 0; i < startRound->size(); i++) {
			currentSR = (*startRound)[i];
			if (currentSR->isInside(((x - 400) / 400.f), ((y - 300) / -300.f))) {
				if (!(*roundRunning)) {
					if (*gameOver) {
						return;
					}
					generateNiveau(*niveau, asteroid);
					*roundRunning = true;
				}
			}
		}
    }
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		if (*cursor != NULL) {
			delete *cursor;
			*cursor = NULL;
			currentCost = 0;
		}
	}
}

void MyControlEngine::generateNiveau(int lvl, std::vector<Asteroid*>* asteroid_) {
	float x, y;
	for (int i = 0; i < lvl * 10; i++) {
		if (lvl > 4) {
			y = -.4f + (.2f * (i % 5));
		}
		else if (lvl > 2) {
			y = -.2f + (.2f * (i % 3));
		}
		else {
			y = .0f;
		}
		x = .7f + .05f * i;
		if (i % 9 == 0) {
			asteroid_->push_back(new Asteroid(40*(lvl/5 + 1), 0.005f, .1f, x, y, 6));
		}
		else if (i % 4 == 0) {
			asteroid_->push_back(new Asteroid(20 * (lvl / 5 + 1), 0.007f, .05f, x, y, 3));
		}
		else {
			asteroid_->push_back(new Asteroid(10 * (lvl / 5 + 1), 0.01f, .025f, x, y, 1));
		}
	}
}

void MyControlEngine::addShip(Vaisseau * ship, std::vector<Vaisseau*>* ships_)
{
	ships_->push_back(ship);
}

void MyControlEngine::restart()
{
	for (int i = 0; i < bullet->size(); i++) {
		delete (*bullet)[i];
	}
	bullet->clear();
	for (int i = 0; i < asteroid->size(); i++) {
		delete (*asteroid)[i];
	}
	asteroid->clear();
	for (int i = 0; i < square->size(); i++) {
		(*square)[i]->inside = NULL;
	}
	for (int i = 0; i < ships->size(); i++) {
		delete (*ships)[i];
	}
	ships->clear();
	for (int i = 0; i < protect->size(); i++) {
		delete (*protect)[i];
	}
	protect->clear();
	Heart* temp;
	for (int i = 0; i < square->size(); i++) {
		if ((*square)[i]->x1 == -1.0f) {
			temp = new Heart((*square)[i]->x1, (*square)[i]->y1);
			(*square)[i]->inside = temp;
			protect->push_back(temp);
		}
	}
	*niveau = 1;
	*gold = 60;
	*roundRunning = false;
	*gameOver = false;
}
