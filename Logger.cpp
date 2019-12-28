#include "Logger.h"

#include <fstream>
#include <iostream>

Logger::Logger(const std::string& filePath) 
: mFilePath(filePath)
{
	mThread = std::thread{ &Logger::process, this };
}
void Logger::Log(const std::string& message)
{
	std::unique_lock lock(mMutex);
	
	mQueue.push(message);
	mCond.notify_all();
}	

void Logger::process()
{
	std::ofstream logFile(mFilePath);
	if(logFile.fail())
	{
		std::cerr << "Failed to open logfile" << std::endl;
		return;
	}
	
	unique_lock lock(mMutex);
	while(true)
	{
		mCond.wait(lock);
		
		lock.unlock();
		while(true)
		{
			lock.lock();
			if(mQueue.empty())
				break;
			logFile << mQueue.front() << std::endl;
			mQueue.pop();
			lock.unlock();
		}
	}
}
