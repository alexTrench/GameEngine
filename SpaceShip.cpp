#include "SpaceShip.h"

//constructor
//constructer that sets a reference to the game
//so that the space ship can seed the game bullets when created
//should be moved to the gameoject manager later 
//USE THIS ONE LATER
//SpaceShip::SpaceShip(Game &game, GameTimer *theTimer) :theGame(game)
//{
//
//
//}

SpaceShip::SpaceShip()
{


}

SpaceShip::SpaceShip(GameTimer *theTimer)
{


}

void SpaceShip::Initialise(Vector2D pos)
{
	//set active 
	active = true;
	GameObject::position = pos;
	
}

void SpaceShip::Render()
{
	if (active)
	{
		MyDrawEngine *pDE = MyDrawEngine::GetInstance();
		image = pDE->LoadPicture(L"spaceship.bmp");
		pDE->DrawAt(position, image, 1.0f, direction);
	}


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
		acceleration.setBearing(direction, 0.08f);
		velocity = velocity + acceleration * FrameRate/ 300;

	}
	if (pinputs->KeyPressed(DIK_S))
	{
		Vector2D acceleration;
		acceleration.setBearing(direction, 0.03f);
		velocity = velocity - acceleration * FrameRate / 300;
	}
	if (pinputs->KeyPressed(DIK_D))
	{
		this->direction = direction + 0.1;
	}
	if (pinputs->KeyPressed(DIK_A))
	{
		this->direction = direction - 0.1;
	}
	if (pinputs->KeyPressed(DIK_SPACE))
	{
		//Bullet *pBullet = new Bullet();
		//pBullet->Initialise();
	}
	//these should also all be timsed by FrameRate
	//but again breaks when used
	Vector2D friction = -0.02 * velocity;
	velocity = velocity + friction;
	position = position + velocity;

	//firing bullets section
	//CAUSES MEMORY LEAKS ATM FIX 
	/*
	shootDelayTimer = shootDelayTimer - FrameRate;
	if (pinputs->NewKeyPressed(DIK_SPACE) && shootDelayTimer <= 0)
	{
		Bullet *pBullet = new Bullet();
		pBullet->Initialise(position, direction);
		shootDelayTimer - SHOOTDELAY;
	}
	*/
}

//void SpaceShip::shoot()
//{
//	MySoundEngine* pSE = MySoundEngine::GetInstance();
//	pSE->Play(shootSound);
//}