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

	if (pinputs->KeyPressed(DIK_D))
	{
		//ErrorLogger::Writeln(L"D Pressed");
		this->direction = direction + (turnDirection + 16.f);
	}
	if (pinputs->KeyPressed(DIK_A))
	{
		//ErrorLogger::Writeln(L"A Pressed");
		this->direction = direction - (turnDirection + 16.f);
	}
	if (pinputs->KeyPressed(DIK_W))
	{
		Vector2D acceleration;
		acceleration.setBearing(direction, 0.09f);
		velocity = velocity + acceleration * FrameRate/ 5000;
	}
	if (pinputs->KeyPressed(DIK_S))
	{
		Vector2D acceleration;
		acceleration.setBearing(direction, 0.07f);
		velocity = velocity - acceleration * FrameRate / 5000;
	}
	

	//Shooting bullets 
	shootDelayTimer -= FrameRate;
	if (pinputs->KeyPressed(DIK_SPACE) && shootDelayTimer <= 0)
	{
		Vector2D BulletVelocity;
		BulletVelocity.setBearing(SpaceShip::direction, BULLETSPEED);
		//ErrorLogger::Writeln(L"Pressing Bullet");
		Bullet *pBullet = new Bullet();
		pBullet->Initialise(position, BulletVelocity);
		GameManager.AddToList(pBullet);
		//sets the delay back to a constnt delay
		shootDelayTimer = SHOOTDELAY;

	}

	//Updating the position of space ship
	Vector2D friction = -0.02f * velocity;
	velocity = velocity + friction;
	position = position + velocity;

	//Attach the collision for the ship on its location
	//and to a approiate size
	SpaceShipCollision.PlaceAt(position, 30);
	

}

Circle2D* SpaceShip::GetShape()
{
	return &SpaceShipCollision;
}

void SpaceShip::HandleCollision(GameObject *pOther)
{
    int id = pOther->GetObjectID();
	if (id == 2)
	{
		ErrorLogger::Writeln(L"Spaceship Collised with Rock");

	}
}

//returns a int to all whatever handles collisions what type of object it is
//1 is for bullets
//2 is for rocks
//3 is for spaceship
//returning int is quicker than strings
int SpaceShip::GetObjectID()
{
	return 3;
}