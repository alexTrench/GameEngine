#include "Bullet.h"

Bullet::Bullet()
{
	ErrorLogger::Writeln(L"Calling Constructor for Bullet");
	bool active = true;
}


Bullet::~Bullet()
{

}

void Bullet::Initialise(Vector2D startPosition, float startVelocity)
{

}

void Bullet::Update(float FrameRate)
{


}

void Bullet::Render()
{
	if (active)
	{
		MyDrawEngine *pDE = MyDrawEngine::GetInstance();
		image = pDE->LoadPicture(L"bullet.bmp");
		pDE->DrawAt(position, image, 1.0f, direction);
	}

}