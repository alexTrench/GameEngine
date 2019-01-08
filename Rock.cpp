#include "Rock.h"

Rock::Rock()
{
	//once constructor is called set active to flase
	Rock::active = false;
	
}

Rock::~Rock()
{
}

//Sets active as true, so that it only renders if initialised
//creates a random number to select one of four differnt rock bitmaps
//done that in here because it doesnt get updated, unlike render
void Rock::Initialise(Vector2D pos) 
{
	//set active 
	active = true;

	//sets all the variables needed to make the rocks move 
	this->glide = rand() % 2;
	this->direction = rand() % 360;
	//this number is used to select a random sprite for a rock, to add variation in the game
	this->number = rand() % 4;

	GameObject::position = pos;

	//the random sprites it could be 
	MyDrawEngine *pDE = MyDrawEngine::GetInstance();
	if (number == 0)
	{
		image = pDE->LoadPicture(L"rock1.bmp");
	}
	if (number == 1)
	{
		image = pDE->LoadPicture(L"rock2.bmp");
	}
	if (number == 2)
	{
		image = pDE->LoadPicture(L"rock3.bmp");
	}
	if (number == 3)
	{
		image = pDE->LoadPicture(L"rock4.bmp");
	}

}
//void Render();
void Rock::Update(float FrameRate) 
{
	if (this->active == true)
	{
		//updates the rocks position each frame
		//variables used to make the rocks fly through space
		Vector2D drift;
		drift.setBearing(direction, glide);

		//updates the position of the game object
		position = position + drift;
		RockCollision.PlaceAt(position, 30);
	}
}

//shows the rocks on screen
void Rock::Render()
{
	if (this->active == true)
	{
		MyDrawEngine *pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(position, image, 1.0f, direction);

	}
}

Circle2D* Rock::GetShape()
{
	return &RockCollision;
}

void Rock::HandleCollision(GameObject *pOther)
{
	int id = pOther->GetObjectID();
	if (id == 1)
	{
		ErrorLogger::Writeln(L"Rock hit by Bullet");
		this->active = false;

	}
}

int Rock::GetObjectID()
{
	return 2;
}
