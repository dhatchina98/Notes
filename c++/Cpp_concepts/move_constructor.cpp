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

    String(String &&other) noexcept
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
        delete m_Data;
    }

    void print()
    {
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
    Entity(const String &name) : m_Name(name)
    {
    }

    Entity(String &&name) : m_Name(move(name))
    {
    }

    void print_name()
    {
        m_Name.print();
    }

private:
    String m_Name;
};

int main()
{

    Entity entity(String("cherno"));
    // Entity entity(String("cherno"));
    entity.print_name();

    cin.get();
}