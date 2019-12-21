#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <stdexcept>

#include "FileException.h"
using namespace std;

vector<int> readIntegerFile(const std::string& fileName)
{
	ifstream inputStream(fileName.data());
	if(inputStream.fail())
		//throw exception();
		throw FileError(fileName);
	vector<int> nums;
	int temp;
	while(inputStream >> temp)
		nums.push_back(temp);
	if(!inputStream.eof())
		throw FileOpenError(fileName);
	return nums;
}

float SafeDivide(float num, float d)
{
	if (d == 0)
		throw invalid_argument("Divide by zero");
	return num/d;
}
 
int main()
{
	vector<int> nums;
	try	{
		nums = readIntegerFile("test3.txt");
	} catch (const FileError& e)	{
		cout << "runtime error: " << e.what() << endl;
	}
	for (const auto& element : nums)	
		cout << element << " ";
	cout << endl;
	return 0;
}



