#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ofstream outFile("test2.txt", ios_base::trunc);	//���� ���� ������ ����
	if(!outFile.good()) 
	{
		cerr << "Can't open test1.txt" << endl;
		return -1;
	}
	outFile << "1111111111" << endl;
	cout << "1" << endl;
	return 0;
}
