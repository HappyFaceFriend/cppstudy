#pragma once

#include <string>
#include <thread>
#include <mutex>

class Logger
{
	public:
		Logger(const std::string& filePath);
		Logger(const Logger& src) = delete;
		Logger& operator=(const Logger& rhs) = delete;
		
		void Log(const std::string& message);
	private:
		void process();
		
		std::mutex mMutex;
		std::condition_variable mCond;
		std::queue<std::string> mQueue;
		std::string mFilePath;
		
		std::thread mThread;
};
