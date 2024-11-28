#include <iostream>
#include <cstring>

using namespace std;

class String
{
public:
    String() = default;
    String(const char *string)
    {
        cout << "created\n";
        m_Size = strlen(string);
        m_Data = new char[m_Size];
        memcpy(m_Data, string, m_Size);
    }

    String(String &&other)
    {
        cout << "moved through constructor\n";

        m_Data = other.m_Data;
        m_Size = other.m_Size;

        other.m_Data = nullptr;
        other.m_Size = 0;
    }

    String &operator=(String &&other)
    {
        if (this != &other)
        {
            cout << "moved through operator\n";

            delete[] m_Data;

            m_Data = other.m_Data;
            m_Size = other.m_Size;

            other.m_Data = nullptr;
            other.m_Size = 0;
        }
        return *this;
    }

    ~String()
    {
        cout << "destroyed\n";
        delete[] m_Data;
    }

    void print()
    {
        cout << "value :";
        for (size_t i = 0; i < m_Size; i++)
            cout << m_Data[i];

        cout << endl;
    }

private:
    char *m_Data;
    int m_Size;
};

int main()
{
    String str1 = "hello";

    String str2(std::move(str1));

    str1.print();
    str2.print();

    String str3 = "world";
    String str4 = "c++";

    str3.print();
    str4.print();

    str3 = std::move(str4);

    str3.print();
    str4.print();

    cin.get();

    return 0;
}