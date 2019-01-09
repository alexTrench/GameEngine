#pragma once

#include "GameObject.h"
#include <list>

class ObjectManager
{
private:
protected:
	//cotains a list of all current game objects
	std::list<GameObject*> pObjectList;
	//two iterators used to handle collisons 
	//in object manager.handle collisions
	std::list<GameObject*>::iterator it1;
	std::list<GameObject*>::iterator it2;
	std::list<GameObject*>::iterator it;
public:
	ObjectManager();
	~ObjectManager();

	//Adds new object to the manager list 
	void AddToList(GameObject* pNewObject);
	//Updating and rendering everything in list
	void UpdateAll(GameTimer &theTimer);
	void RenderAll();
	void EndGameCleanUp();
	void CleanUp();
	void CheckAllCollision();
	void Debug();
};