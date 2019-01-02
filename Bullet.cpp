#include "Bullet.h"

Bullet::Bullet()
{
	ErrorLogger::Writeln(L"Creating Bullet");
	bool active = true;
}


Bullet::~Bullet()
{

}

void Bullet::Initialise(Vector2D startPosition, Vector2D startVelocity)
{
	ErrorLogger::Writeln(L"Initialise bullet");
	MyDrawEngine *pDE = MyDrawEngine::GetInstance();
	image = pDE->LoadPicture(L"bullet.bmp");
}

void Bullet::Update(float FrameRate)
{
	ErrorLogger::Writeln(L"Updating bullet");

}

void Bullet::Render()
{
	if (active)
	{
		MyDrawEngine *pDE = MyDrawEngine::GetInstance();
		pDE->DrawAt(position, image, 1.0f, direction);
		ErrorLogger::Writeln(L"Rendering bullet");
	}

}