#include "SpaceShip.h"
#include "Bullet.h"

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

void SpaceShip::Initialise(Vector2D pos)
{
	//set active 
	active = true;
	GameObject::position = pos;

	MyDrawEngine *pDE = MyDrawEngine::GetInstance();
	image = pDE->LoadPicture(L"spaceship.bmp");
	
}

void SpaceShip::Render()
{
	if (active)
	{
		MyDrawEngine *pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(position, image, 1.0f, direction);
	}


}

void SpaceShip::Update(float FrameRate)
{
	MyInputs *pinputs = MyInputs::GetInstance();
	pinputs->SampleKeyboard();


	if (pinputs->KeyPressed(DIK_W))
	{
		Vector2D acceleration;
		acceleration.setBearing(direction, 0.1f);
		velocity = velocity + acceleration * FrameRate/ 5000;
	}
	if (pinputs->KeyPressed(DIK_S))
	{
		Vector2D acceleration;
		acceleration.setBearing(direction, 0.02f);
		velocity = velocity - acceleration * FrameRate / 5000;
	}
	if (pinputs->KeyPressed(DIK_D))
	{
		//ErrorLogger::Writeln(L"D Pressed");
		this->direction = direction + (turnDirection /** (FrameRate / 5.f)*/);
	}
	if (pinputs->KeyPressed(DIK_A))
	{
		//ErrorLogger::Writeln(L"A Pressed");
		this->direction = direction - (turnDirection/* * (FrameRate / 5.f)*/);
	}
	Vector2D friction = -0.02f * velocity;
	velocity = velocity + friction;
	position = position + velocity;


	//shootDelayTimer = shootDelayTimer - FrameRate;
	if (pinputs->NewKeyPressed(DIK_SPACE)/* && shootDelayTimer <= 0*/)
	{
		ErrorLogger::Writeln(L"Pressing Bullet");
		Bullet *pBullet = new Bullet();
		pBullet->Initialise(position, velocity);
		GameManager.AddToList(pBullet);
		shootDelayTimer = SHOOTDELAY;
	
	}
	
}
