//#include "Allocator.h"
//
//
//
//Allocator::Allocator(int iNumItems)
//{
//	m_ItemStore = (Allocator*) 
//		operator new(sizeof(Allocator)*iNumItems);
//
//	for (int i = 0; i<iNumItems; i++)
//	{
//		m_FreeItems.push(m_ItemStore + i);
//	}
//
//}
//
//Allocator::~Allocator()
//{
//	operator delete(m_ItemStore);
//}
//
//Allocator* Allocator::Allocate()
//{
//	Allocator* pItem = m_FreeItems.top();	// NULL if
//	m_FreeItems.pop();			//    empty
//	return pItem;
//}
//
//void Allocator::Free(Allocator* pItem)
//{
//	m_FreeItems.push(pItem);
//}
//
//
