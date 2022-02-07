#include "SmartPtr.h"
#include <cassert>
namespace Engine{
	
	template <typename T>
	SmartPtr<T>::SmartPtr(T* ptr):
		mptr(ptr),
		count(new Counters(1, 0))
	{
	
	}
	template <typename T>
	SmartPtr<T>::SmartPtr(const SmartPtr& i_other) :
		mptr(i_other.mptr),
		count(i_other.count)
	{
		count->owner++;
	}
	template <typename T>
	SmartPtr<T>::SmartPtr(const WeakPtr<T>& i_other) :
		mptr(i_other.mptr),
		count(i_other.count)
	{
		count->owner++;
	}

	template <typename T>
	T& SmartPtr<T>::operator*()
	{
		assert(mptr);
		return *mptr;
	
	}
	template <typename T>
	T* SmartPtr<T>::operator->()
	{
		return mptr;

	}
	template <typename T>
	SmartPtr<T>::operator bool() 
	{
		return count->owner > 0;
	}
	template <typename T>
	bool SmartPtr<T>::operator==(SmartPtr& iother)
	{
		return mptr == iother.mptr;
	}
	template <typename T>
	bool WeakPtr<T>::operator==(WeakPtr& iother)
	{
		return mptr == iother.mptr;
	}
	template <typename T>
	bool SmartPtr<T>::operator!=(SmartPtr<T>& iother) {
	
		return mptr != iother.mptr;
	}
	template <typename T>
	SmartPtr<T>::~SmartPtr() 
	{
		if (--(count->owner) == 0)
		{
			delete mptr;

			if ((count->observer) == 0)
			{
				delete count;
			}
		}
	
	}
	template <typename T>
	WeakPtr<T>::WeakPtr(const SmartPtr<T>& other):
		mptr(other.mptr),
		count(other.count)
	{
		count->observer++;
	}
	template <typename T>
	WeakPtr<T>::WeakPtr(const WeakPtr& other) :
		mptr(other.mptr),
		count(other.count)
	{
		count->observer++;
	}

	template <typename T>
	WeakPtr<T>::~WeakPtr()
	{
		count->observer--;
	}


}