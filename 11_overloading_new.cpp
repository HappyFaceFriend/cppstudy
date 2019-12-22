#include <cstddef>
#include <new>
#include <iostream>

class MemoryDemo
{
	public:
		MemoryDemo() : i(0) {
			throw std::exception();
		}
		virtual ~MemoryDemo() = default;
	
		void* operator new(size_t size)
		{
			std::cout << "operator new(size_t)" << std::endl;
			return ::operator new(size);
		}
		void operator delete(void* ptr) noexcept
		{
			std::cout << "operator delete(void*)" << std::endl;
			return ::operator delete(ptr);
		}
		
		void* operator new[](size_t size)
		{
			std::cout << "operator new[](size_t)" << std::endl;
			return ::operator new[](size);
		}
		void operator delete[](void* ptr) noexcept
		{
			std::cout << "operator delete[](size_t)" << std::endl;
			return ::operator delete[](ptr);
		}
		
		void* operator new(size_t size, const std::nothrow_t&) noexcept
		{
			std::cout << "operator new(size_t, nothrow_t)" << std::endl;
			return ::operator new(size,std::nothrow);
		}
		void operator delete(void* ptr, const std::nothrow_t&) noexcept
		{
			std::cout << "operator delete(void*, nothrow_t)" << std::endl;
			return ::operator delete(ptr,std::nothrow);
		}
		
		void* operator new[](size_t size, const std::nothrow_t&) noexcept
		{
			std::cout << "operator new[](size_t, nothrow_t)" << std::endl;
			return ::operator new(size,std::nothrow);
		}
		void operator delete[](void* ptr, const std::nothrow_t&) noexcept
		{
			std::cout << "operator delete[](void*, nothrow_t)" << std::endl;
			return ::operator delete(ptr,std::nothrow);
		}
		
		void* operator new(size_t size, int extra)
		{
			std::cout << "operator new(size_t) + " << extra << std::endl;
			return ::operator new(size);
		}
		void operator delete(void* ptr, int extra) noexcept
		{
			std::cout << "operator delete(void*) + " << extra << std::endl;
			return ::operator delete(ptr);
		}
	private:
		int i;
};

int main()
{
	MemoryDemo* pm;
	try{
		pm = new MemoryDemo();
		delete pm;
	} catch(...)	{
		std::cout << "ERROR!" << std::endl;
	}
	
	pm = new MemoryDemo[4];
	delete [] pm;
	
	pm = new (std::nothrow) MemoryDemo();
	delete pm;
	
	pm = new (std::nothrow) MemoryDemo[6];
	delete[] pm;
	
	pm = new(5) MemoryDemo();
	delete pm;
	
	return 0;
}



















