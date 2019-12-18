#include <iostream>
#include <string>

using namespace std;

int main(int argc, char** argv)
{
	string name;
	int partySize = 0;
	cin >> noskipws;
	char ch;
	while ( cin >> ch)
	{
		if (isdigit(ch))
		{
			//cin.unget();
			if(cin.fail())
				cout << "unget fail" << endl;
			break;
		}
		name += ch;
	}
	if (cin)
		cin >> partySize;
	if (!cin)
	{
		cerr << "Error getting party size" << endl;
		return 1;
	}
	cout << name << " " << partySize << endl;
	return 0;
}
