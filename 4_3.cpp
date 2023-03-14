#include <iostream>
#include <string>
using namespace std;

class String
{
private:
	char* value;
	int length; 
public:
	String() 
	{
		value = new char[1];
		length = 0;
		value[0] = '\0';
	}

	String(string str)
	{
		length = str.length();
		value = new char[length + 1];
		for (int i = 0; i <= length; i++) {
			value[i] = str[i];
		}
	}

	String(const String& s) 
	{
	length = s.length;
	value = new char[length + 1];
	for (int i = 0; i <= length; i++) {
	value[i] = s.value[i];
	}
	}
	friend ostream& operator<<(ostream& outputStream, const String& s); 
		~String() 
	{
		delete[] value;
	}
};
ostream& operator<<(ostream& outputStream, const String& s) 
{
 return outputStream << s.value;
}


int main(int argc, char** argv) 
{
	setlocale(LC_ALL, "Russian");
	cout << "Введите строку:" << endl;
	string example1;
	cin >> example1;
	String a(example1);
	cout << "Вывод строки, инициализированный конструктором:" << endl;
	cout << a << endl;
	return 0;
}
