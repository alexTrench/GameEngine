#include "ObjectManager.h"
#include <iostream>

ObjectManager::ObjectManager()
{
}


ObjectManager::~ObjectManager()
{
}

//Adds new object to the manager list 
void ObjectManager::AddToList(GameObject* pNextObject)
{
	pObjectList.emplace_back(pNextObject);
	//ErrorLogger::Writeln(L"Adding To List");
}

//Updating everything in list
//has a reference to the game timer in game code
//to keep track of the framerate
void ObjectManager::UpdateAll(GameTimer &theTimer)
{
	for (GameObject *pNextObject : pObjectList)
	{
		if (pNextObject != nullptr)
		{
			pNextObject->Update(theTimer.mdFrameTime);
		}
		else 
		{
			ErrorLogger::Writeln(L"next object pointer is null");
		}
	}
	
}

//rendering everything in list
void ObjectManager::RenderAll()
{
	for (GameObject *pNextObject : pObjectList)
	{
		pNextObject->Render();
	}
}

//Resets and deletes all the pointers to memory after the game ends
//Doesnt really help with memory leaks but cleans up after game anyway
//small game with few hundred small objects so shouldnt be a problem
void ObjectManager::EndGameCleanUp()
{
	for (GameObject *pNextObject : pObjectList)
	{
			delete pNextObject;
			pNextObject = nullptr;
	}
}

void ObjectManager::CleanUp()
{
	for (GameObject *pNextObject : pObjectList)
	{
		if (pNextObject->IsActive() == false)
		{
		delete pNextObject;
		pNextObject = nullptr;
		}
	}
}

void ObjectManager::CheckAllCollision()
{
	//for (GameObject* &nextObjectPointer : pObjectList) // The & is critical. Check.
	//{
	//if (nextObjectPointer->IsActive() == false)
	//	{
	//		delete nextObjectPointer;
	//		nextObjectPointer = nullptr; // Always do this when deleting! 
	//	}
	//}
	// This is now easier
	//auto it = std::remove(pObjectList.begin(), pObjectList.end(), nullptr);
	//pObjectList.erase(it, objectList.end());

	for (it1 = pObjectList.begin(); it1 != pObjectList.end(); it1++)
	{
		for (it2 = std::next(it1); it2 != pObjectList.end(); it2++)
		{
			if ((*it1)->GetShape()->Intersects(*((*it2)->GetShape())))
			{
				// Do something
				//ErrorLogger::Writeln(L"Collision Detected");
				(*it1)->HandleCollision((*it2));
				(*it2)->HandleCollision((*it1));
			}
		}
	}


}

