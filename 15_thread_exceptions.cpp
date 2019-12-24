#include <iostream>
#include <stdexcept>
#include <thread>
#include <functional>

void function(int i)
{
	for(int j=0; j<5; j++)
		std::cout << j << std::endl;
	std::cout << "Thread throwing a runtime_error" << std::endl;
	throw std::runtime_error("Exception from thread");
}

void functionError(std::exception_ptr& err)
{
	try{
		function(1);
	} catch(...)	{
		std::cout << "Caught exception" << std::endl;
		err = std::current_exception();
	}
}

int main()
{
	std::exception_ptr error;
	std::thread t(functionError, std::ref(error));
	
	t.join();
	
	if(error)
	{
		std::cout << "Received exception" << std::endl;
		std::rethrow_exception(error);
	}
	else
		std::cout << "Didn\'t receive exception" << std::endl;
	
	return 0;
}






