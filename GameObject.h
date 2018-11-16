#include "mydrawengine.h"
#include "vector2D.h"
#include "mysoundengine.h"
#include "gametimer.h"
#include <string>

#pragma once
class GameObject
{
private:
	PictureIndex image;
	SoundIndex shootSound;
protected:
	Vector2D position;
	float direction;
	bool active;

	
	std::string LoadImage(std::string FileName);
public:
	
	void Render();
	virtual void Update(float FrameRate) = 0;
	
};

