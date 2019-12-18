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
	cout << "setw: " << setw(6) << i <<" again: " << i <<endl;
	cout << "setfill: " << setw(6) << setfill('!') << i << endl;	
	cout << setfill(' ');
	
	double d = 1.452;
	double d2 = 1;
	cout << "noshowpoint: " << setw(2) << noshowpoint << d << endl;
	cout << "noshowpoint: " << setw(2) << noshowpoint << d2 << endl;
	
	//지역에 맞게 숫자포맷 설정 
	cout.imbue(locale()); 
	cout << 1234567 << endl;
	//cout << put_money("12000") << endl;	
	
	return 0;
}
