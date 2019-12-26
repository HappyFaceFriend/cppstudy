#include <thread>
#include <iostream>
#include <vector>
#include <mutex>

std::once_flag gOnceFlag;

int a = 0;

void InitializeSharedResources()
{
	std::cout << "Resources initialized" << std::endl;
}
void inc()
{
	a += 10;
}
void function()
{
	call_once(gOnceFlag, inc);
	std::cout << "Proc" << "cess" << "ing" << "..." << std::endl;
}

int main()
{
	std::vector<std::thread> threads;
	for (int i=0; i<3; i++)
		threads.emplace_back(function);
	InitializeSharedResources();
	for (auto& t : threads)
		t.join();
	return 0;
}
















