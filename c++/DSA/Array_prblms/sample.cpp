#include <iostream>

using namespace std;

class Base1
{
    char v;
    int a;
    int d;
};

class Base2
{
    virtual void func()
    {
    }
};

class Base3
{
    int a;
    int b;
    int c;
    virtual void func()
    {
    }
};

class Base4
{
    int a;
    void func()
    {
    }
};

struct a
{
    int a;
    char b;
};

int main()
{
    cout << sizeof(Base1) << endl;
    cout << sizeof(Base2) << endl;
    cout << sizeof(Base3) << endl;
    cout << sizeof(Base4) << endl;
    cout << sizeof(a) << endl;
    return 0;
}