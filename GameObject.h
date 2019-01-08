#pragma once

#include "mydrawengine.h"
#include "vector2D.h"
#include "mysoundengine.h"
#include "gametimer.h"

class GameObject
{
private:
	SoundIndex shootSound;
protected:
	
	PictureIndex image;
	Vector2D position;
	float direction;
	bool active;
	Vector2D velocity;

public:

	virtual void Render() = 0;
	virtual void Update(float FrameRate) = 0;

	//destructor to avoid memeory leaks in deletion of pointers
	virtual ~GameObject() {};

	bool IsActive() { return this->active; }
	virtual IShape2D* GetShape() = 0;
	virtual void HandleCollision(GameObject *pOther) = 0;
	virtual int GetObjectID() = 0;
};

