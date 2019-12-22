#include <iostream>
#include <stdexcept>

class Entity
{
public:
	Entity(int i) 
	{
		throw std::runtime_error("Exception by Entity ctor");
	}
};

class MyClass
{
	public:
		MyClass();
	private:
		int* mData = nullptr;
		Entity mEntity;
};

MyClass::MyClass()
try
	: mData(new int[42]{1,2,3}), mEntity(42)
{
	std::cout<<"MyClass ctor"<<std::endl;
}
catch ( const std::runtime_error& e )
{
	delete[] mData;
	mData = nullptr;
	std::cout<<"try block caught : " << e.what() << std::endl;
	throw;
}


int main()
{
	try{
		MyClass m;
	} catch (const std::runtime_error& e)	{
		std::cout << "main caught " <<e.what() <<std::endl; 
	}
	
}











