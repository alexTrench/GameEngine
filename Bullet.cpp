#include "Bullet.h"


Bullet::Bullet()
{
	//ErrorLogger::Writeln(L"Creating Bullet");

}


Bullet::~Bullet()
{

}

//starts the bullet out at the location of the ship
//at a speed dictated in the ship class
void Bullet::Initialise(Vector2D startPosition, Vector2D startVelocity)
{
	elapsedTime = 0;
	bool active = true;
	//ErrorLogger::Writeln(L"Initialise bullet");
	MyDrawEngine *pDE = MyDrawEngine::GetInstance();
	if (pDE != nullptr) 
	{
		image = pDE->LoadPicture(L"bullet.bmp");

	}

	position = startPosition;
	direction = startVelocity.angle();
	velocity = startVelocity;
}

//moves the bullet at the velocity constantly
//velocity from the ship class
//and after a certain time deletes the bullet as its probably offscreen
void Bullet::Update(float FrameRate)
{
	if (this->active)
	{
		elapsedTime += FrameRate;
		position = position + velocity;
		BulletCollision.PlaceAt(position, 10.f);
		//ErrorLogger::Writeln(L"Updating bullet");
		if (elapsedTime > 13000000)
		{
			this->active = false;
		}
	}

}

//draw the bullet at its locatio
//using a bullet sprite
//checking for null pointers
void Bullet::Render()
{
	if (this->active)
	{
		MyDrawEngine *pDE = MyDrawEngine::GetInstance();
		if (pDE != nullptr)
		{
			pDE->DrawAt(position, image, 3.0f, direction);
			//ErrorLogger::Writeln(L"Rendering bullet");
		}
	}

}


//get the collision reference
Circle2D* Bullet::GetShape()
{
	return &BulletCollision;
}

//if the bullet collides with the rocks it deletes the bullet
//rock deletes itself in its own class
void Bullet::HandleCollision(GameObject *pOther)
{
	int id = pOther->GetObjectID();
	if(id == 2)
	{
		//ErrorLogger::Writeln(L"Bullet hit Rock");
		this->active = false;
	}
}

//tells the other object what this is
//used during collisions
int Bullet::GetObjectID()
{
	return 1;
}

//MemoryManager<Bullet>Bullet::s_pool(MAXMISSILES);
