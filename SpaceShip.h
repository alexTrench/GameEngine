#pragma once

#include "GameObject.h"

class SpaceShip: public GameObject
{
private:
	//member variables 
	Vector2D velocity;
protected:
	Vector2D acceleration;
public:

	//constructors
	SpaceShip();
	SpaceShip(GameTimer *theTimer);

	//member functions
	void Initialise(Vector2D pos);
	//void Render();
	void Update(float FrameRate);
	//void shoot();
};

