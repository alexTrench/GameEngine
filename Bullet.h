#pragma once
#include "GameObject.h"

class Bullet: public GameObject
{
private:
	Circle2D BulletCollision;
	float elapsedTime;
	static const int MAXMISSILES = 300;
protected:

public:
	Bullet();
	~Bullet();

	void Initialise(Vector2D startPosition, Vector2D startAngle);
	void Update(float FrameRate);
	void Render();
	Circle2D* GetShape() override;
	void HandleCollision(GameObject *pOther)override;
	int GetObjectID();
};

