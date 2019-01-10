#include "SpaceShip.h"
#include "Bullet.h"



//sets up the position of the ship
//aswell as setting it to active
void SpaceShip::Initialise(Vector2D pos)
{
	//set active 
	active = true;
	GameObject::position = pos;

	MyDrawEngine *pDE = MyDrawEngine::GetInstance();
	image = pDE->LoadPicture(L"spaceship.bmp");
	
}

//draws the ship on the screen at a certain location
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
	//gets a instance to the keyboard for keypresses
	MyInputs *pinputs = MyInputs::GetInstance();
	pinputs->SampleKeyboard();

	//movement
	//up down left right
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
	//adds a delay for how fast the ship can shoot
	shootDelayTimer -= FrameRate;
	if (pinputs->KeyPressed(DIK_SPACE) && shootDelayTimer <= 0)
	{
		Vector2D BulletVelocity;
		BulletVelocity.setBearing(SpaceShip::direction, BULLETSPEED);
		//ErrorLogger::Writeln(L"Pressing Bullet");
		Bullet *pBullet = new Bullet();
		//pBullet = s_pool.Allocate();
		//new(pBullet) Bullet();
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

//gets a reference to the collision 
Circle2D* SpaceShip::GetShape()
{
	return &SpaceShipCollision;
}

//find out the other game objects ID
//and does something based of that
void SpaceShip::HandleCollision(GameObject *pOther)
{
    int id = pOther->GetObjectID();
	if (id == 2)
	{
		//ErrorLogger::Writeln(L"Spaceship Collised with Rock");
		this->active = false;
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

MemoryManager<SpaceShip>SpaceShip::s_pool(MAXSHIPS);