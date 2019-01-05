#pragma once
#include "GameObject.h"

class Bullet: public GameObject
{
private:
	Circle2D BulletCollision;
	Vector2D velocity;
protected:

public:
	Bullet();
	~Bullet();

	void Initialise(Vector2D startPosition, Vector2D startVelocity);
	void Update(float FrameRate);
	void Render();
	Circle2D* GetShape() override;
	void HandleCollision(GameObject *pOther)override;
	int GetObjectID();
};

