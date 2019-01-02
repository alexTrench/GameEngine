#pragma once
#include "GameObject.h"

class Bullet: public GameObject
{
private:
protected:

public:
	Bullet();
	~Bullet();

	void Initialise(Vector2D startPosition, Vector2D startVelocity);
	void Update(float FrameRate);
	void Render();

};

