#include "vector2D.h"
#include "SpaceShip.h"
#include "mydrawengine.h"

//constructor
SpaceShip::SpaceShip()
{
	//once constructor is called set active to flase
	SpaceShip::active = false;

}


void SpaceShip::Render()
{
	if (SpaceShip::active)
	{
		MyDrawEngine *pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(position, image, 1.0f, direction, 0.3);
	}

}

void SpaceShip::Initialise(Vector2D pos)
{
	//set active 
	active = true;
	//set the spaceships angle.
	velocity.setBearing(100, 4.0f);
	//draw the ship to the screen
	MyDrawEngine *pDE = MyDrawEngine::GetInstance();
	image = pDE->LoadPicture(L"spaceship.bmp");
	float angle = 0.0f;

}

void SpaceShip::Update()
{

}
