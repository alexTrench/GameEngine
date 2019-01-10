#pragma once
#include "GameObject.h"
#include "MemoryManager.h"

class Bullet: public GameObject
{
private:
	Circle2D BulletCollision;
	float elapsedTime;
	static const int MAXMISSILES = 300;
	//memory managment template
	static MemoryManager<Bullet> s_pool;
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

	//MemoryManager<Bullet>Bullet::s_pool(MAXMISSILES) { s_pool = MAXMISSILES; }
	//void* operator new(size_t size) { return(s_pool.Allocate()); }
	//void  operator delete(void* pItem) { s_pool.Free((Bullet*)pItem); }
};

