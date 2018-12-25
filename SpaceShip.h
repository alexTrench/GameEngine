#pragma once

#include "GameObject.h"
#include "myinputs.h"


class SpaceShip: public GameObject
{
private:
	
	//used to give created objects to the game
	//Game &theGame;
protected:
	//member variables 
	Vector2D velocity;
	Vector2D acceleration;
	float shootDelayTimer = 1.f;
	const int SHOOTDELAY = 1;
	float turnDirection = 1.0f;
public:

	//constructors
	// USE THIS ONE LATER
	//SpaceShip(Game &game, GameTimer *theTimer);
	SpaceShip(GameTimer *theTimer);
	SpaceShip();
	

	//member functions
	void Initialise(Vector2D pos);
	void Render();
	void Update(float FrameRate);
	//void shoot();
};

