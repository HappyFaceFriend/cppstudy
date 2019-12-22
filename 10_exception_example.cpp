#include <iostream>
#include "GameBoard.h"

#include <stdexcept>
#include <new>

void newHandler()
{
	throw std::bad_alloc();
}

int main()
{

	std::set_new_handler(newHandler);
	GameBoard g1(30000000,30000000);
	GameBoard g2(2,2);
	
	g1.at(1,1);
	swap(g1,g2);
	
	GameBoard g3 = g1;
	g3 = g2;
	
	return 0;
}
