#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv)
{
	bool myBool = true;
	cout << "this is default: " << myBool <<endl;
	//boolalpha : true/false 로 출력 
	cout << "using boolalpha: " << boolalpha << myBool << " " << myBool << endl;
	cout << myBool << endl;
	cout << "not using boolalpha: " <<noboolalpha << myBool <<endl;
	cout << endl; 
	
	int i = 123;
	//setw는 바로 다음 출력에만 적용됨 
	cout<< "setw: " << setw(6) << i <<" again: " << i <<endl;
	cout<< "setfill: " << setw(6) << setfill('!') << i << endl;	
	return 0;
}
