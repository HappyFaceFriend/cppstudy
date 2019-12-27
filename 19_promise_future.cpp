#include <iostream>
#include <thread>
#include <future>
#include <functional>

void dowork(std::promise<int>& myPromise)
{
	myPromise.set_value(42);
}

int sum(int a, int b)
{
	return a+b;
}

int main()
{
	std::promise<int> myPromise;
	auto myFuture = myPromise.get_future();
	std::thread myThread{ dowork, std::ref(myPromise)};
	int result = myFuture.get();
	std::cout << result << std::endl;
	
	myThread.join();
	
	std::packaged_task<int(int,int)> task(sum);
	auto taskFuture = task.get_future();
	std	::thread taskThread { std::move(task), 39, 3};
	result = taskFuture.get();
	std::cout << result << std::endl;
	
	taskThread.join();
	
	return 0;
}
