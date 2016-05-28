#pragma once

#ifdef _MSC_VER
#define MS_ALIGN(N) __declspec(align(N))
#endif

#define DEFINE_ALIGNED_NEW_DELETE \
	void* operator new[](size_t Size) \
	{ \
		void* Mem = _aligned_malloc(Size, 16); \
		if (!Mem) \
			throw std::bad_alloc(); \
			\
		return Mem; \
	} \
	void* operator new(size_t Size) \
	{ \
		void* Mem = _aligned_malloc(Size, 16); \
		if (!Mem) \
			throw std::bad_alloc(); \
			\
		return Mem; \
	} \
	void operator delete[] (void* Ptr) \
	{ \
		_aligned_free(Ptr); \
	} \
	void operator delete(void* Mem) \
	{ \
		_aligned_free(Mem); \
	} \
	void* operator new (size_t Size, void* Ptr) throw() \
	{ \
		return Ptr; \
	}


#define SAFE_DELETE(p) if(p != nullptr){ delete p; p = nullptr; }

template<typename _Ty,
typename _Ty2 = std::remove_pointer<_Ty>::type>
	inline static void TypeSafeDelete(_Ty2** Target)
{
	if (Target != nullptr)
	{
		delete (*Target);
		*Target = nullptr;
	}
}