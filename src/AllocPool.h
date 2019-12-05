#pragma once
#include <memory>

template <typename T>
union AllocPoolChunk
{
	T Chunk;
	AllocPoolChunk<T>* NextChunk;

	AllocPoolChunk() {} // to keep (de)constructors of T
	~AllocPoolChunk(){}
};

template <typename T>
class AllocPool
{
public:
	explicit AllocPool(size_t pSize = 1024) //explicit um casten zu verhindern
		: mSize(pSize)
	{
		mData = new AllocPoolChunk<T>[mSize];
		mHead = mData;

		for (size_t i = 0; i < mSize - 1; ++i)
			mData[i].NextChunk = std::addressof(mData[i + 1]);

		mData[mSize - 1].NextChunk = nullptr;
	}
	// Rule of 5
	AllocPool(const AllocPool& other) = delete; // no copy constructor needed
	AllocPool(const AllocPool&& other) = delete; // no move constructor needed
	AllocPool& operator = (const AllocPool& other) = delete; //  no copy assignment needed
	AllocPool& operator = (const AllocPool&& other) = delete; // no move assignment needed
	~AllocPool()
	{
		if (mAllocationCount > 0)
		{
			__debugbreak();
			//TODO: kill all remaining allocations or error?
		}
		delete[] mData;
		mData = nullptr; // set to nullptr to crash if there are still pointers using this
		mHead = nullptr;
	}
	
	template <typename... arguments>
	T* Allocate(arguments&&... args)
	{
		if (mHead == nullptr)
		{
			__debugbreak();
			return nullptr;
		}

		AllocPoolChunk<T>* mChunk = mHead;
		mHead = mHead.NextChunk;
		T* retVal = new (std::addressof(mChunk->Chunk)) T(std::forward<arguments>(args)...);
		++mAllocationCount;
		return retVal;
	}

	void DeAllocate(T* pChunk)
	{
		//TODO: check pChunk against chunksize and address against pool range
		pChunk->~T();
		AllocPoolChunk<T>* mChunk = reinterpret_cast<AllocPoolChunk<T>*>(pChunk);
		mChunk->NextChunk = mHead;
		mHead = mChunk;
		--mAllocationCount;
	}

private:
	size_t mSize = 0;
	AllocPoolChunk<T>* mHead = nullptr; 
	AllocPoolChunk<T>* mData = nullptr;
	size_t mAllocationCount = 0;
};