#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<int> readIntegerFile(const std::string& fileName)
{
	ifstream inputStream(fileName.data());
	vector<int> nums;
	int temp;
	while(inputStream >> temp)
		nums.push_back(temp);
	return nums;
}


int main()
{
	vector<int> nums = readIntegerFile("test1.txt");
	for (const auto& element : nums)	
		cout << element << " ";
	cout << endl;
	return 0;
}
