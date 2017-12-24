#include <string>
#include "MyGraphicEngine.h"
#include "MyGameEngine.h"

void MyGraphicEngine::Draw(){

	glutReshapeWindow(800, 600);

   //GraphicPrimitives::drawLine2D(x1, 0.5f, x2, -0.5f, 1.0f, 0.0f, 1.0f);
   //GraphicPrimitives::drawText2D(str, -1.0f, 0.9f, 0.0f, 0.0f, 1.0f);
   std::string s = std::to_string(*gold);
   char const *pchar = s.c_str();
   char * b= new char[20];
   strcpy(b, pchar);
   //GraphicPrimitives::drawText2D(b, -1.0f, 0.7f, 1.0f, 1.0f, 1.0f);

   for (int i = 0; i < ships->size(); i++) {
	   (*ships)[i]->draw();
   }
   for (int i = 0; i < protect->size(); i++) {
	   (*protect)[i]->draw();
   }
   for (int i = 0; i < square->size(); i++){
	(*square)[i]->draw();
   }
   for (int i = 0; i < bullet->size(); i++) {
	   (*bullet)[i]->draw();
   }
   for (int i = 0; i < asteroid->size(); i++) {
	   (*asteroid)[i]->draw();
   }
   GraphicPrimitives::drawOutlinedRect2D(.5f, -.5f, 1.0f, 1.0f, .5, .5, .5, 1.0f);

   GraphicPrimitives::drawText2D("Gold : ", -1.0f, -.9f, 1.0f, 1.0f, 1.0f);
   GraphicPrimitives::drawText2D(b, -.8f, -.9f, 1.0f, 1.0f, 1.0f);

   GraphicPrimitives::drawText2D("Cursor : ", -.4f, -.9f, 1.0f, 1.0f, 1.0f);
   if (*cursor != NULL) {
	   float r, g, b;
	   Vaisseau* cV =(Vaisseau*) *cursor;
	   r = cV->red;
	   g = cV->green;
	   b = cV->blue;
	   GraphicPrimitives::drawFillRect2D(-.2f, -.9f, .1f, .1f, r, g, b);
   }
   else {
	   GraphicPrimitives::drawOutlinedRect2D(-.2f, -.9f, .1f, .1f, 1.0f, 1.0f, 1.0f);
   }
   if (*niveau < 5) {
	   GraphicPrimitives::drawFillRect2D(.5f, -.5f, .1f, .2f, 1, 1, 1);
	   GraphicPrimitives::drawFillRect2D(.5f, .3f, .1f, .2f, 1, 1, 1);
   }
   if (*niveau < 3) {
	   GraphicPrimitives::drawFillRect2D(.5f, -.3f, .1f, .2f, 1, 1, 1);
	   GraphicPrimitives::drawFillRect2D(.5f, .1f, .1f, .2f, 1, 1, 1);
   }
   std::string s2 = std::to_string(*niveau);
   char const *pchar2 = s2.c_str();
   char * b2 = new char[20];
   strcpy(b2, pchar2);

   GraphicPrimitives::drawText2D("Level : ", -1.0f, -.7f, 1.0f, 1.0f, 1.0f);
   GraphicPrimitives::drawText2D(b2, -.8f, -.7f, 1.0f, 1.0f, 1.0f);

   if (!(*gameOver)) {
	   for (int i = 0; i < buysShipButtons->size(); i++) {
		   (*buysShipButtons)[i]->draw();
	   }
	   if (!(*roundRunning)) {
		   for (int i = 0; i < startRound->size(); i++) {
			   (*startRound)[i]->draw();
		   }
	   }
   }
   else {
	   GraphicPrimitives::drawText2D("Game Over ", -.9f, .7f, 1.0f, 1.0f, 1.0f);
	   for (int i = 0; i < restarter->size(); i++) {
		   (*restarter)[i]->draw();
	   }
   }

   
   x1 += dx1;
   if (x1 > 0.9f || x1 < -0.9f) {
	dx1 = -dx1;
	x1 += dx1;
   }
   
   x2 += dx2;
   if (x2 > 0.9f || x2 < -0.9f) {
	dx2 = -dx2;
	x2 += dx2;
   }
   
}
   
   