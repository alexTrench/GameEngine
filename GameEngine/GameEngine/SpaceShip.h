#include "vector2D.h"
#include "mydrawengine.h"
#include "gametimer.h"
#include "myinputs.h"

#pragma once
class SpaceShip
{
private:
	//member variables 
	Vector2D velocity;
	Vector2D position;
	float direction;
	bool active;
protected:
	Vector2D acceleration;
	PictureIndex image;
public:

	//constructors
	SpaceShip();
	SpaceShip(GameTimer *theTimer);

	//member functions
	void Initialise(Vector2D pos);
	void Render();
	void Update(GameTimer frameRate);
	void health();
	void ammunition();
	void move();


};

