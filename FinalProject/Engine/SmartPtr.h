#pragma once
#include "GameObject.h"
#include <cassert>
namespace Engine {
	struct Counters {
		unsigned long owner;
		unsigned long observer;
		Counters(unsigned long initialOwner, unsigned long initialObserver) :
			owner(initialOwner),
			observer(initialObserver) {}
	};

	template <class T>
	class WeakPtr;
	template <typename T>
	class SmartPtr

	{

	public:
		 SmartPtr():mptr(nullptr),
			count(nullptr){
			

		}
		
		explicit SmartPtr(T* ptr) :mptr(ptr),
			count(new Counters(4, 0))
		{

		}


		SmartPtr(const SmartPtr& i_other) :
			mptr(i_other.mptr),
			count(i_other.count)
		{
			(*count).owner++;
		}

		SmartPtr(const WeakPtr<T>& i_other) :
			mptr(i_other.mptr),
			count(i_other.count)
		{
			(*count).owner++;
		}


		T* operator->()
		{
			return mptr;

		}

		T& operator*() {
			assert(mptr);
			return *mptr;

		}

		~SmartPtr()
		{
			if (count != nullptr) {
				if (--(count->owner) == 0)
				{
					delete mptr;

				if ((count->observer) == 0)
					{
						delete count;
					}
				}
			}

		}
		operator bool()
		{
			return count->owner > 0;
		}

		bool operator==(SmartPtr<T>& iother)
		{
			return mptr == iother.mptr;
		}


		bool operator!=(SmartPtr<T>& iother)
		{

			return mptr != iother.mptr;
		}

		T* mptr;
		Counters* count;
	private:
		//template <typename T>
		
		
	};

	template <class T>
	class WeakPtr {
	public:
		friend class SmartPtr<T>;
		WeakPtr(const SmartPtr<T>& other) :
			mptr(other.mptr),
			count(other.count)
		{
			(*count).observer++;
		}

		WeakPtr(const WeakPtr& other) :
			mptr(other.mptr),
			count(other.count)
		{
			(*count).observer++;
		}

		bool operator==(WeakPtr<T>& iother)
		{
			return mptr == iother.mptr;
		}

		~WeakPtr()
		{
			(*count).observer++;
		}

	private:
		T* mptr;
		Counters* count;

	};

}

