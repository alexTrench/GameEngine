#pragma once
#include <stack>

class Bullet;

template <typename T>
class BulletPool{
private:
	std::stack<T*> m_FreeItems;
	T* m_ItemStore;
public:
	BulletPool(int iNumItems);
	~BulletPool();

	T* Allocate();
	void Free(T* pItem);
	//void FreeAll();
};



