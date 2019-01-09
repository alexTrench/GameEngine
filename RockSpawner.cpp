#include "RockSpawner.h"
#include "Rock.h"

RockSpawner::~RockSpawner()
{
}

void RockSpawner::Initialise(Vector2D startPos)
{
	this->active = true;
	this->position = startPos;
}


void RockSpawner::Update(float FrameRate)
{
	spawnTimer -= FrameRate;
	if(active && spawnTimer <= 0)
	{
		Rock *pRock = new Rock();
		pRock->Initialise(this->position);
		pRock->SetDirection(rand() % 3 + 68);
		GameManager.AddToList(pRock);
		spawnTimer = TIMER;
	}
}

//doesnt do anything as its a invisible object
void RockSpawner::Render()
{
	if (active)
	{

	}
}

Circle2D* RockSpawner::GetShape()
{
	return &RockSpawnerCollision;
}

void RockSpawner::HandleCollision(GameObject *pOther)
{

}

//returns a int to all whatever handles collisions what type of object it is
//1 is for bullets
//2 is for rocks
//3 is for spaceship
//4 for rockSpawner
//returning int is quicker than strings
int RockSpawner::GetObjectID()
{
	return 4;
}