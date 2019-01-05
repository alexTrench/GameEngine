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

	bool active = true;
	ErrorLogger::Writeln(L"Initialise bullet");
	MyDrawEngine *pDE = MyDrawEngine::GetInstance();
	image = pDE->LoadPicture(L"bullet.bmp");
	position = startPosition + startVelocity;
	velocity = startVelocity;
}

void Bullet::Update(float FrameRate)
{
	ErrorLogger::Writeln(L"Updating bullet");

	//PLACEHOLD ROCK FUNCTION
	//updates the rocks position each frame
	//variables used to make the rocks fly through space
	Vector2D drift;
	drift.setBearing(direction, 0.2f);

	//updates the position of the game object
	position = position + velocity;
	BulletCollision.PlaceAt(position, 10);
}

void Bullet::Render()
{
	//if (active)
	//{
		MyDrawEngine *pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(position, image, 3.0f, direction);
		ErrorLogger::Writeln(L"Rendering bullet");
	//}

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
	}
}

int Bullet::GetObjectID()
{
	return 1;
}