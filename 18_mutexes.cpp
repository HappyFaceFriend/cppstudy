#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

class Counter1
{
	public:
		Counter1(int id, int count) : mId(id), mCount(count) {}
		void operator()() const
		{
			for(int i=0; i<mCount; i++)
			{
				std::lock_guard<std::mutex> lock(sMutex);
				std::cout << "Counter " << mId << " has value " << i << std::endl;
			}
		}
	private:
		int mId;
		int mCount;
		static std::mutex sMutex;
};
std::mutex Counter1::sMutex;

class Counter2
{
	public:
		Counter2(int id, int count) : mId(id), mCount(count) {}
		void operator()() const
		{
			for(int i=0; i<mCount; i++)
			{
				std::unique_lock<std::timed_mutex> lock(sMutex, std::chrono::milliseconds(200));
				if(lock)
				{
					std::cout << "Counter " << mId << " has value " << i << std::endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(100));
				}
				else
					std::cout << "Failed to get lock : " << i << std::endl;
			}
		}
	private:
		int mId;
		int mCount;
		static std::timed_mutex sMutex;
};
std::timed_mutex Counter2::sMutex;

int main()
{
	Counter2 c1(1,5);
	std::thread t1(std::ref(c1));
	std::thread t2(std::ref(c1));
	std::thread t3(std::ref(c1));
	
	t1.join();
	t2.join();
	t3.join();
	
	return 0;
}
