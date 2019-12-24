#include <thread>
#include <iostream>
#include <functional>

void counter(int id, int count)
{
	for (int i=0; i<count; i++)
		std::cout << "[" << id << "] " << i << std::endl;
}

class Counter
{
	public:
		Counter() : mId(0), mCount(5){}
		Counter(int id, int count) : mId(id), mCount(count) {}
		void operator()() const
		{
			for (int i=0; i<mCount; i++)
				std::cout << "[" << mId << "] " << i << std::endl;
		}
	private:
		int mId, mCount;
};

class Request
{
	public:
		Request(int id) : mId(id)  {}
		void process()
		{
			std::cout << "Processing request " << mId << std::endl;
		}
	private:
		int mId;
};

int main()
{
	std::thread t1(counter, 1, 6);
	std::thread t2(counter, 2, 4);	//t2(counter, std::ref(~~), ..)
	
	t1.join();
	t2.join();
	
	std::thread t3{ Counter{3, 5} };
	Counter c(4,5);
	std::thread t4(std::cref(c));
	std::thread t5(Counter(5,5));
	//std::thread t6(Counter());
	
	t3.join();
	t4.join();
	t5.join();
	//t6.join();
	
	int id=1, count = 5;
	std::thread t6([id,count]	{
		for(int i=0; i<count; i++)
			std::cout << "[" << id << "] " << i << std::endl;
	});
	t6.join();
	
	Request r(100);
	std::thread t7{ &Request::process, &r};
	t7.join();
	
	return 0;
}
