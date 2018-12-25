//#include "ObjectManager.h"
//
//ObjectManager::ObjectManager()
//{
//}
//
//
//ObjectManager::~ObjectManager()
//{
//}
//
////Adds new object to the manager list 
//void ObjectManager::AddToList(GameObject* pNextObject)
//{
//	pObjectList.push_back(pNextObject);
//}
//
////Updating everything in list
////has a reference to the game timer in game code
////to keep track of the framerate
//void ObjectManager::UpdateAll(GameTimer &theTimer)
//{
//	for (GameObject *pNextObject : pObjectList)
//	{
//		pNextObject->Update(theTimer.mdFrameTime);
//	}
//	
//}
//
////rendering everything in list
//void ObjectManager::RenderAll()
//{
//	for (GameObject *pNextObject : pObjectList)
//	{
//		pNextObject->Render();
//	}
//}