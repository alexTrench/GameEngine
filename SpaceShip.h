#pragma once

#include "GameObject.h"
#include "myinputs.h"
#include "ObjectManager.h"


class SpaceShip: public GameObject
{
private:
	ObjectManager theGameManager;
protected:
	//member variables 
	Vector2D velocity;
	Vector2D acceleration;
	float shootDelayTimer = 1.f;
	const int SHOOTDELAY = 1;
	float turnDirection = 3.f;

public:

	//constructors
	// USE THIS ONE LATER
	//SpaceShip(Game &game, GameTimer *theTimer);
	SpaceShip();
	SpaceShip(ObjectManager &manager) : theGameManager(manager) { ErrorLogger::Writeln(L"Calling Oject Manager Constructor"); };
	

	//member functions
	void Initialise(Vector2D pos);
	void Render();
	void Update(float FrameRate);
};

