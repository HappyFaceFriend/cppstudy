#include <string>
#include <iostream>

/*void PrintMessage(std::string& message)
{
	std::cout << "l-value ver : " << message << std::endl;
}*/
void PrintMessage(std::string&& message)
{
	std::cout << "r-value ver : " << message << std::endl;
}

int main()
{
	std::string a = "Hello ";
	std::string b = "World";
	
	PrintMessage(std::move(a));
	PrintMessage(a+b);
	PrintMessage("hi");
	return 0;
}
