#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include <stdexcept>

using namespace std;

vector<int> readIntegerFile(const std::string& fileName)
{
	ifstream inputStream(fileName.data());
	if(inputStream.fail())
		//throw exception();
		throw runtime_error("Unable to open the file");
	vector<int> nums;
	int temp;
	while(inputStream >> temp)
		nums.push_back(temp);
	if(!inputStream.eof())
		throw runtime_error("Error reading file");
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
	try {
		cout << SafeDivide(5,2) << endl;
		cout << SafeDivide(10,0) << endl;
		cout << SafeDivide(3,3) << endl;
	} catch (const invalid_argument& e)	{
		cout << "Exception: " << e.what() << endl;
	}
	vector<int> nums;
	try	{
		nums = readIntegerFile("test3.txt");
	} catch (const runtime_error& e)	{
		cout << "runtime error: " << e.what() << endl;
	}
	for (const auto& element : nums)	
		cout << element << " ";
	cout << endl;
	return 0;
}



