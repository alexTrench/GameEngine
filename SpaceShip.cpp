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
//void SpaceShip::Render()
//{
//	if (SpaceShip::active)
//	{
//		MyDrawEngine *pDE = MyDrawEngine::GetInstance();
//		image = pDE->LoadPicture(L"spaceship.bmp");
//		pDE->DrawAt(position, image, 1.0f, direction);
//	
//		//Sound Play System
//		MySoundEngine *pSE = MySoundEngine::GetInstance();
//		shootSound = pSE->LoadWav(L"Laser.wav");
//	}
//
//}

void SpaceShip::Initialise(Vector2D pos)
{
	//set active 
	active = true;

	Vector2D position(pos);

}

void SpaceShip::Update(float FrameRate)
{
	MyInputs *pinputs = MyInputs::GetInstance();
	pinputs->SampleKeyboard();

	//THIS NEED TO BE FIXED THE FRAME RATE IN THE FUTURE
	//NOT SURE WHY IT BREAKS IT
	if (pinputs->KeyPressed(DIK_W))
	{
		Vector2D acceleration;
		acceleration.setBearing(direction, 1.0f);
		velocity = velocity + acceleration;

	}
	if (pinputs->KeyPressed(DIK_S))
	{
		Vector2D acceleration;
		acceleration.setBearing(direction, 0.5f);
		velocity = velocity - acceleration;
	}
	if (pinputs->KeyPressed(DIK_D))
	{
		this->direction = direction - 0.1;
	}
	if (pinputs->KeyPressed(DIK_A))
	{
		this->direction = direction + 0.1;
	}
	//these should also all be timsed by FrameRate
	//but again breaks when used
	Vector2D friction = -0.03 * velocity;
	velocity = velocity + friction;
	position = position + velocity;



}

//void SpaceShip::shoot()
//{
//	MySoundEngine* pSE = MySoundEngine::GetInstance();
//	pSE->Play(shootSound);
//}