#include "GameObject.h"


//Draws the spaceship on the screen
//and sets up the ability to play sounds
void GameObject::Render()
{
	if (active)
	{
		MyDrawEngine *pDE = MyDrawEngine::GetInstance();
		image = pDE->LoadPicture(L"spaceship.bmp");
		pDE->DrawAt(position, image, 1.0f, direction);

		//Sound Play System
		MySoundEngine *pSE = MySoundEngine::GetInstance();
		shootSound = pSE->LoadWav(L"Laser.wav");
	}
}

//decides what image to load in render
//NOT DONE
std::string GameObject::LoadImage(std::string FileName)
{
	return FileName;
}