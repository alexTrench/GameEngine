#pragma once

#include "GameObject.h"
#include <vector>

class ObjectManager
{
protected:
	//cotains a list of all current game objects
	std::vector<GameObject*> pObjectList;
public:
	ObjectManager();
	~ObjectManager();

	//Adds new object to the manager list 
	void AddToList(GameObject* pNewObject);
	//Updating and rendering everything in list
	void UpdateAll(GameTimer &theTimer);
	void RenderAll();
	void CheckAllCollision();
};