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

    String(const String &other)
    {
        cout << "copied\n";
        m_Size = other.m_Size;
        m_Data = new char[m_Size];
        memcpy(m_Data, other.m_Data, m_Size);
    }

    String(String &&other)
    {
        cout << "moved\n";
        m_Size = other.m_Size;
        m_Data = other.m_Data;

        other.m_Size = 0;
        other.m_Data = nullptr;
    }

    ~String()
    {
        cout << "destroyed\n";
        delete[] m_Data;
    }

    void print()
    {
        cout << "printing\n";
        for (size_t i = 0; i < m_Size; i++)
            cout << m_Data[i];

        cout << endl;
    }

private:
    char *m_Data;
    int m_Size;
};

class Entity
{
public:
    Entity(const String &data) : name(data)
    {
        cout << "entity copy constructor\n";
    }

    Entity(String &&data) : name(std::move(data))
    {
        cout << "entity move constructor\n";
    }

    void print_data()
    {
        name.print();
    }

private:
    String name;
};

int main()
{
    Entity entity("hello world");
    entity.print_data();

    cin.get();
    return 0;
}