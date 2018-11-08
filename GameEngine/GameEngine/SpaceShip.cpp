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
		image = pDE->LoadPicture(L"spaceship.bmp");
		pDE->DrawAt(position, image);
	}

}

void SpaceShip::Initialise(Vector2D pos)
{
	//set active 
	active = true;
	//set the spaceships angle.
	//velocity.setBearing(200, 2.0f);
	//draw the ship to the screen
	

}

void SpaceShip::Update(GameTimer frameRate)
{
	MyInputs *pinputs = MyInputs::GetInstance();
	pinputs->SampleKeyboard();

	if (pinputs->KeyPressed(DIK_RIGHT))
	{
		Vector2D acceleration(30, 0);
		position = position + acceleration;
	}
	if (pinputs->KeyPressed(DIK_LEFT))
	{
		Vector2D acceleration(-30, 0);
		position = position + acceleration;
	}



}

void SpaceShip::health()
{


}

void SpaceShip::ammunition()
{

}
