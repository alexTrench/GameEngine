#pragma once
#include "GameObject.h"

class Bullet: public GameObject
{
private:
protected:

public:
	Bullet();
	~Bullet();

	void Initialise(Vector2D startPosition, float startVelocity);
	void Update(float FrameRate);
	void Render();

};

