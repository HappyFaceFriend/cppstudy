#include <iostream>
#include <string>

using namespace std;

string readName(istream& stream)
{
	string name;
	while (!stream.fail())	// while(stream)
	{
		int next = stream.get(); //char 말고 eof 등 특수한 문자 갖기 가능
		if(!stream || next == std::char_traits<char>::eof())
			break;
		name += static_cast<char>(next); 
	}
	return name;
}
string readName2(istream& stream)
{
	string name;
	char next;
	while(stream.get(next))
		name += next;
	return name;
	
}

int main(int argc, char** argv)
{
	string input;
	cin >> input;
	cout << "input : " << input << endl;
	/*
	int sum = 0;
	if(!cin.good())
	{
		cerr << "cin not good" << endl;
		return 1;
	}
	
	int num;
	
	while(!cin.bad())
	{
		cin >> num;
		if (cin.good())
			sum += num;
		else if (cin.eof())
			break;
		else if (cin.fail())
		{
			cin.clear();
			string badToken;
			cin >> badToken;
			cerr << "Bad input: " << badToken << endl;
		}
	}
	cout << "sum: " << sum << endl;
	*/
	string name = readName(cin);
	cout << name << endl;
	
	return 0;
}
