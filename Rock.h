#pragma once
#include "GameObject.h"



class Rock: public GameObject
{
private:
	int number = 1;
	Circle2D RockCollision;
protected:
	//uses glide and direction to tell the rocks to move a certain way
	Vector2D drift;
	//used to give the rock a slow constant movement during gameplay
	int glide,direction;
public:
	Rock();
	~Rock();

	//member functions
	void Render();
	void Initialise(Vector2D pos);
	//void Render();
	void Update(float FrameRate);
	//void shoot();
	Circle2D* GetShape() override;

	void HandleCollision(GameObject *pOther) override;
	int GetObjectID();
};

