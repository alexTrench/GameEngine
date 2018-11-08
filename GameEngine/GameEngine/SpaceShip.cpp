#include "vector2D.h"
#include "SpaceShip.h"
#include "mydrawengine.h"
#include "gametimer.h"
#include "myinputs.h"

//constructor
SpaceShip::SpaceShip()
{
	//once constructor is called set active to flase
	SpaceShip::active = false;

}

SpaceShip::SpaceShip(GameTimer *theTimer)
{


}

void SpaceShip::Render()
{
	if (SpaceShip::active)
	{
		MyDrawEngine *pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(position, image, 1.0f, direction, 0.3);
	}

}

void SpaceShip::Initialise(Vector2D pos, float direction)
{
	//set active 
	active = true;
	//set the spaceships angle.
	//velocity.setBearing(200, 2.0f);
	//draw the ship to the screen
	MyDrawEngine *pDE = MyDrawEngine::GetInstance();
	image = pDE->LoadPicture(L"spaceship.bmp");


}

void SpaceShip::Update(GameTimer frameRate)
{
	MyInputs *pinputs = MyInputs::GetInstance();
	pinputs->SampleKeyboard();

	if (pinputs->KeyPressed(DIK_RIGHT))
	{
		Vector2D acceleration(30, 0);
		velocity = velocity + acceleration;
	}
	if (pinputs->KeyPressed(DIK_LEFT))
	{
		Vector2D acceleration(-30, 0);
		velocity = velocity + acceleration;
	}



}

void SpaceShip::health()
{


}

void SpaceShip::ammunition()
{

}

void SpaceShip::move()
{

}
