#include <iostream>

#include <stdexcept>
#include <string>

class MyException : public std::exception
{
private:
	std::string m_Message;
public:
	MyException(const std::string& s) : m_Message(s) {}
	virtual const char* what() const noexcept override {
		return m_Message.c_str();
	}
};
using namespace std;

void doSomething()
{
	try	{
		throw runtime_error("Throw runtimeError");
	} catch (const runtime_error& e) {
		cout << __func__ << " caught runtime_error" << endl;
		throw_with_nested(MyException("MyException nested with runtime_error"));
	}
}

int main()
{
	try	{
		doSomething();
	} catch (const MyException& e)	{
		cout << __func__ << " caught MyException : " << e.what() << endl;
		try{
			rethrow_if_nested(e);
		} catch (const runtime_error& e) {
			cout << "Nested exception " << e.what() << endl;
		}
	}
	return 0;
}













