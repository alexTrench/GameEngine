#include "Bullet.h"

Bullet::Bullet()
{
	ErrorLogger::Writeln(L"Creating Bullet");

}


Bullet::~Bullet()
{

}


void Bullet::Initialise(Vector2D startPosition, Vector2D startVelocity)
{
	elapsedTime = 0;
	bool active = true;
	//ErrorLogger::Writeln(L"Initialise bullet");
	MyDrawEngine *pDE = MyDrawEngine::GetInstance();
	image = pDE->LoadPicture(L"bullet.bmp");


	position = startPosition;
	direction = startVelocity.angle();
	velocity = startVelocity;
	

}

void Bullet::Update(float FrameRate)
{
	if (this->active)
	{
		elapsedTime += FrameRate;
		position = position + velocity;
		BulletCollision.PlaceAt(position, 10.f);
		ErrorLogger::Writeln(L"Updating bullet");
		if (elapsedTime > 13000000)
		{
			this->active = false;
		}
	}

}

void Bullet::Render()
{
	if (this->active)
	{
		MyDrawEngine *pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(position, image, 3.0f, direction);
		ErrorLogger::Writeln(L"Rendering bullet");
	}

}

Circle2D* Bullet::GetShape()
{
	return &BulletCollision;
}

void Bullet::HandleCollision(GameObject *pOther)
{
	int id = pOther->GetObjectID();
	if(id == 2)
	{
		ErrorLogger::Writeln(L"Bullet hit Rock");
		this->active = false;
	}
}

int Bullet::GetObjectID()
{
	return 1;
}