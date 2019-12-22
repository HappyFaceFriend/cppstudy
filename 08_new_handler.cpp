#include <iostream>
#include <stdexcept>
#include <new>
#include <limits>

class please_terminate_me : public std::bad_alloc {};

void newHandler()
{
	std::cerr << "Unable to allocate memory" << std::endl;
	throw please_terminate_me();
}

int main()
{
	try {
		std::new_handler oldHandler = std::set_new_handler(newHandler);
		
		
		int **p = new int*[10000000];
		for(int i=0; i<10000000; i++)
			p[i] = new int[10000000];
		//std::set_new_handler(oldHandler);
		
	}	catch (const please_terminate_me&)	{
		std::cerr << __FILE__ << "(" << __LINE__ << "): terminate program" << std::endl;
		return 1;
	}
	return 0;
}
