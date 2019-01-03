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

public:
	virtual void Render() = 0;
	virtual void Update(float FrameRate) = 0;
	virtual ~GameObject() {};
	bool IsActive() { if (GameObject::active = true) return true; else return false; };

};

