#pragma once

#include "GameObject.h"
#include "myinputs.h"
#include "ObjectManager.h"


class SpaceShip: public GameObject
{
private:
	Circle2D SpaceShipCollision;
	ObjectManager &GameManager;
	const float BULLETSPEED = 50;

protected:
	//member variables
	Vector2D BulletPos;
	Vector2D frontOfShip;
	Vector2D velocity;
	Vector2D acceleration;
	float shootDelayTimer;
	const float SHOOTDELAY = 1200000;
	float turnDirection = 0.1f;

public:

	//constructor
	SpaceShip(ObjectManager &manager) : GameManager(manager) {};
	

	//member functions
	void Initialise(Vector2D pos);
	void Render();
	void Update(float FrameRate);
	Circle2D* GetShape();
	void HandleCollision(GameObject *pOther)override;
	int GetObjectID();
};

