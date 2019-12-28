#include <iostream>
#include <thread>
#include <future>
#include <functional>

int main()
{
	std::promise<void> thread1Started, thread2Started;
	std::promise<int> signalPromise;
	auto signalFuture = signalPromise.get_future().share();	//shared_future
	
	auto function1 = [&thread1Started, signalFuture]	{
		thread1Started.set_value();
		int parameter = signalFuture.get();
		std::cout << "function1:" << parameter << std::endl;
	};
	auto function2 = [&thread2Started, signalFuture]	{
		thread2Started.set_value();
		int parameter = signalFuture.get();
		std::cout << "function2:" << parameter << std::endl;
	};
	
	auto result1 = std::async(std::launch::async, function1);
	auto result2 = std::async(std::launch::async, function2);
	
	thread1Started.get_future().wait();
	thread2Started.get_future().wait();
	
	std::cin.get();
	signalPromise.set_value(42);
	return 0;
}

