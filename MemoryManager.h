#pragma once
#include <stack>

template <class T>
class MemoryManager
{
private:
	std::stack<T*>m_FreeItems;
	T* m_ItemStore;
public:
	MemoryManager::MemoryManager(int iNumItems)
	{
		m_ItemStore = (T*) operator new(sizeof(T) *iNumItems);

		for (int i = 0; i < iNumItems; i++)
		{
			m_FreeItems.push(m_ItemStore + i);
		}
	}
	MemoryManager::~MemoryManager()
	{
		operator delete(m_ItemStore);
	}

	T* MemoryManager::Allocate()
	{
		T* pItem = m_FreeItems.top();
		m_FreeItems.pop();
		return pItem;
	}
	
	void Free(T* pItem)
	{
		m_FreeItems.push(pItem);
	}

};


