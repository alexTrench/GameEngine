#pragma once

#include "GameObject.h"
#include "myinputs.h"
#include "ObjectManager.h"


class SpaceShip: public GameObject
{
private:
	Circle2D SpaceShipCollision;
	ObjectManager &GameManager;
	const float BULLETSPEED = 100;

protected:
	//member variables
	Vector2D BulletPos;
	Vector2D frontOfShip;
	Vector2D velocity;
	Vector2D acceleration;
	const int RATEOFFIRE = 1;
	float shootDelayTimer = 1.f;
	const int SHOOTDELAY = 100;
	float turnDirection = 0.1f;

public:

	//constructor
	SpaceShip(ObjectManager &manager) : GameManager(manager) { ErrorLogger::Writeln(L"Calling Oject Manager Constructor"); };
	

	//member functions
	void Initialise(Vector2D pos);
	void Render();
	void Update(float FrameRate);
	Circle2D* GetShape();
	void HandleCollision(GameObject *pOther)override;
	int GetObjectID();
};

