#include "vector2D.h"
#include "mydrawengine.h"

#pragma once
class SpaceShip
{
private:
	Vector2D velocity;
	Vector2D position;
	float direction;
	bool active;
protected:
	PictureIndex image;
public:
	SpaceShip();


	void Initialise(Vector2D pos);
	void Render();
	void Update();

	//space for functions to add things like health
	//void health();
	//ammunition
	//void ammunition();

};

