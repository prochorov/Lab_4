#include <cstring>
#include <iostream>
#include <string>

using namespace std;

class String {
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

    void setValue(char* newValue)
    {
        delete[] value;
        length = strlen(newValue);
        value = new char[length + 1];
        strcpy(value, newValue);
    }

    friend ostream& operator<<(ostream& outputStream, const String& s);
    friend istream& operator>>(istream& inputStream, String& s);

    ~String()
    {
        delete[] value;
    }
};

ostream& operator<<(ostream& outputStream, const String& s)
{
    return outputStream << s.value;
}

istream& operator>>(istream& inputStream, String& s)
{
    char buffer[1024];
    inputStream >> buffer;
    s.setValue(buffer);
    return inputStream;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Введите строку: " << endl;
    String str;
    cin >> str;
    cout << "Введенная строка: " << endl;
    cout << str << endl;
    return 0;
}
