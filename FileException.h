#include <stdexcept>
#include <string>

class FileError : public std::exception
{
public:
	FileError(const std::string& fileName)
	 : m_FileName(fileName)
	{
		setMessage(std::string("error!! : ") + getFileName());
	}
	 
	virtual const char* what() const noexcept override
	{
		return m_Message.c_str();
	}
	
	const std::string& getFileName() const noexcept { return m_FileName; }
protected:
	void setMessage(const std::string& message)
	{
		m_Message = message;
	}
	
private:
	std::string m_FileName;
	std::string m_Message; 	
};

class FileOpenError : public FileError
{
public:
	FileOpenError(const std::string& fileName) : FileError(fileName)
	{
		setMessage(std::string("Can\'t open ") + getFileName());
	}
};
