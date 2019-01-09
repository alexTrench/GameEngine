#pragma once
#include "GameObject.h"
#include "ObjectManager.h"

//Class to create more rock objects during the game
class RockSpawner: public GameObject
{
private:
	Circle2D RockSpawnerCollision;
	ObjectManager & GameManager;
	const float TIMER = 28000000;
	float spawnTimer;
public:
	RockSpawner(ObjectManager &manager) : GameManager(manager) { ErrorLogger::Writeln(L"Calling Oject Manager Constructor"); };
	~RockSpawner();


	void Initialise(Vector2D startPos);
	void Update(float FrameRate);
	void Render();

	//Doesnt have any collision so this doesnt do anything but here 
	//because it need to overide the game object functions
	Circle2D* GetShape() override;
	void HandleCollision(GameObject *pOther) override;
	int GetObjectID();
};

