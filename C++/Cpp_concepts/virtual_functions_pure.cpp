#include <iostream>

using namespace std;

// Base class
class Base
{
public:
    // pure virtual function
    virtual void func() = 0;
};

// Derived class from Base class
class Derived : public Base
{
public:
    //overriding the base class pure virtual function
    void func() override
    {
        cout << "Derived class function" << endl;
    }
};

int main()
{
    // calling function using Derived class object
    Base *ptr = new Derived();
    ptr->func();

    return 0;
}